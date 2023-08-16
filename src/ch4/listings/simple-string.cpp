#include <cstdio>
#include <cstring>
#include <exception>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size)
    : max_size{ max_size },
      length{} {
    if (max_size == 0) {
      throw std::runtime_error{ "Max size must be at least 1." };
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }

  SimpleString(const SimpleString& other)
  : max_size{ other.max_size },
    buffer{ new char[other.max_size] },
    length{ other.length } {
    std::strncpy(buffer, other.buffer, max_size);
  }

  SimpleString& operator=(const SimpleString& other) {
    if (this == &other) return *this;
    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    std::strncpy(buffer, other.buffer, max_size);
    return *this;
  }

  ~SimpleString() {
    delete[] buffer;
  }

  void print(const char* tag) const {
    printf("%s: %s", tag, buffer);
  }

  bool append_line(const char* x) {
    const auto x_len = strlen(x);
    if (x_len + length + 2 > max_size) return false;
    //WARNING: `strncpy` can lead to memory errors.
    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

private:
  size_t max_size;
  char* buffer;
  size_t length;
};

void foo(SimpleString x) {
  x.append_line("This change is lost.");
}

int main() {
  SimpleString string{ 115 };
  string.append_line("Starbuck, whaddya hear?");
  string.append_line("Nothin' but the rain.");
  string.print("A");
  string.append_line("Grab your gun and bring the cat in.");
  string.append_line("Aye-aye sir, coming home.");
  string.print("B");
  if (!string.append_line("Galactica!")) {
    printf("String was not big enough to append another message.\n");
  }
  printf("\n\n");

  // Size does not mean "true size" characters to append_line.
  SimpleString test_string { 5 };
  printf("%s\n", test_string.append_line("a") ? "true" : "false");
  printf("%s\n", test_string.append_line("b") ? "true" : "false");
  printf("%s\n", test_string.append_line("c") ? "true" : "false");
  test_string.print("test_string");
  printf("\n\n");

  SimpleString a{ 50 };
  a.append_line("We apologize for the");
  SimpleString a_copy{ a };
  a.append_line("inconvenience.");
  a_copy.append_line("incontinence.");
  a.print("a");
  a_copy.print("a_copy");
  printf("\n\n");

  SimpleString a_value { 20 };
  foo(a_value); // Invokes copy constructor
  a_value.print("Still empty"); 
  printf("\n\n");

  SimpleString x{ 50 };
  x.append_line("We apologize for the");
  SimpleString y{ 50 };
  y.append_line("Last message");
  x.print("x");
  y.print("y");
  y = x;
  x.print("x");
  y.print("y"); 
}