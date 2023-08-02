/**
 * Listings 10.8 through 10.29
*/

#include <exception>
#include <stdexcept>

struct SpeedUpdate {
    double velocity_mps;
};

struct CarDetected {
    double distance_m;
    double velocity_mps;
};

struct BrakeCommand {
    double time_to_collisions_s;
};

struct Tracer {
  Tracer(const char* name) : name{ name } {
    printf("%s constructed.\n", name);
  }
  ~Tracer() {
    printf("%s destructed.\n", name);
  }
private:
  const char* const name;
};

template <typename T>
struct AutoBrake {
  AutoBrake(const T& publish)
    : collision_threshold_s{ 5 }, speed_mps{}, publish{ publish } { }
  void observe(const SpeedUpdate& su) {
    speed_mps = su.velocity_mps;
  }
  void observe(const CarDetected& cd) {
    auto relative_velocity_mps = speed_mps - cd.velocity_mps;
    auto collision_time_s = cd.distance_m / relative_velocity_mps;
    if (collision_time_s > 0 && collision_time_s <= collision_threshold_s) {
      printf("BrakeCommand collision_time_s: %f\n", collision_time_s);
      //publish(BrakeCommand{ collision_time_s });
    }
  }
  void set_collision_threshold_s(double x) {
    // Bug in Listing 10.14, `std::exception` is not valid here.
    if (x < 1) throw std::runtime_error{ "Collision less than 1." };
    collision_threshold_s = x;
  }
  double get_collision_threshold_s() const {
    return collision_threshold_s;
  }
  double get_speed_mps() const {
    return speed_mps;
  }
private:
  double collision_threshold_s;
  double speed_mps;
  const T& publish;
};

constexpr void assert_that(bool statement, const char* message) {
  if (!statement) throw std::runtime_error{ message };
}

void initial_speed_is_zero() {
  AutoBrake auto_brake{ [](const BrakeCommand&) {} };
  assert_that(
    auto_brake.get_speed_mps() == 0L,
    // Attempted to use std::format(), but need C++20, which required gcc13.
    // Major pain to try to install this. https://stackoverflow.com/a/26221725
    (std::to_string(
        auto_brake.get_speed_mps()) + " speed not equal 0").c_str());
}

void initial_sensitivity_is_five() {
  AutoBrake auto_brake{ [](const BrakeCommand&) {} };
  assert_that(
    auto_brake.get_collision_threshold_s() == 5L,
    (std::to_string(
      auto_brake.get_collision_threshold_s()) + " sensitivity is not 5"
      ).c_str());
}

void sensitivity_greater_than_1() {
  AutoBrake auto_brake{ [](const BrakeCommand&) {} };
  try {
    auto_brake.set_collision_threshold_s(0.5L); 
  } catch (const std::exception&) {
    return;
  }
  assert_that(false, "no exception thrown");
}

void speed_is_saved() {
  AutoBrake auto_brake{ [](const BrakeCommand&) {} };
  auto_brake.observe(SpeedUpdate{ 100L });
  assert_that(100L == auto_brake.get_speed_mps(), "speed not saved to 100");
  auto_brake.observe(SpeedUpdate{ 50L });
  assert_that(50L == auto_brake.get_speed_mps(), "speed not saved to 50");
  auto_brake.observe(SpeedUpdate{ 0L });
  assert_that(0L == auto_brake.get_speed_mps(), "speed not saved to 0");
}

void run_test(void(*unit_test)(), const char* name) {
  try {
    unit_test();
    printf("[+] Test %s successful.\n", name);
  } catch (const std::exception& e) {
    printf("[-] Test failure in %s. %s.\n", name, e.what());
  }
}

void alert_when_imminent_segfault() {
  // Tracer has local scope and passed into AutoBrake as const-ref, so it will
  // **not** get ownership. The compiler could/should destruct this immediately
  // after construction, and in GCC it does. The issue above you can see clearly
  // author ran this in a web-based tool where the passed object did not get
  // destructed immediately and works.

  AutoBrake auto_brake{ Tracer { "Publish" } };

  auto_brake.set_collision_threshold_s(10L);
  auto_brake.observe(SpeedUpdate{ 100L });
  auto_brake.observe(CarDetected{ 100L, 0L });

  printf("Return segfault test\n");
}

AutoBrake<Tracer> alert_when_imminent_out_of_scope() {
  auto tracer = Tracer { "Publish" };
  AutoBrake auto_brake{ tracer };

  auto_brake.set_collision_threshold_s(10L);
  auto_brake.observe(SpeedUpdate{ 100L });

  printf("Return auto_brake\n");
  return auto_brake;
}

void alert_when_imminent() {
  int brake_commands_published{};

  // The better fix for this would be for AutoBrake to take ownership of this
  // object. If we exit this function and AutoBrake stays around as a object
  // beyond it we would have problems. 
  auto publish_fn = [&brake_commands_published](const BrakeCommand &) {
    brake_commands_published++;
  };
  AutoBrake auto_brake { publish_fn };

  auto_brake.set_collision_threshold_s(10L);
  auto_brake.observe(SpeedUpdate{ 100L });
  auto_brake.observe(CarDetected{ 100L, 0L });
  assert_that(
    brake_commands_published == 1,
    "brake commands published not one");
}

int main() {
  run_test(initial_speed_is_zero, "initial speed is 0");
  run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
  run_test(sensitivity_greater_than_1, "sensitivity greater than 1");
  run_test(speed_is_saved, "speed is saved");
  run_test(alert_when_imminent, "alert when imminent successful");

  // The original code had a lifetime bug when this final requirement was
  // implemented in Listing 10-19.
  // https://github.com/JLospinoso/ccc/issues/98
  // 
  // See Chapter 4 of book for more detailed life cycle/lifetime discusions,
  // particularlly Automatic Storage Duration.
  //
  // The following two lines will illustrate the input argument being
  // destructed in two different cases before use.
  //
  // You must comment out the publish function calls in AutoBrake to have these
  // test compile.
  
  //run_test(
  //  alert_when_imminent_segfault, "alert when imminent successful segfault");
  //alert_when_imminent_out_of_scope().observe(CarDetected{ 100L, 0L });
}