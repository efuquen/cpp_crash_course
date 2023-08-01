/**
 * Listings 10.8 through 10.29
*/

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

template <typename T>
struct AutoBrake {
  AutoBrake(const T& publish) : speed_mps{}, publish{ publish } { }
  void observe(const SpeedUpdate& cd) { }
  void observe(const CarDetected& cd) { }
  void set_collision_threshold_s(double x) {
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

void run_test(void(*unit_test)(), const char* name) {
  try {
    unit_test();
    printf("[+] Test %s successful.\n", name);
  } catch (const std::exception& e) {
    printf("[-] Test failure in %s. %s.\n", name, e.what());
  }
}

int main() {
  run_test(initial_speed_is_zero, "initial speed is 0");
  run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
}