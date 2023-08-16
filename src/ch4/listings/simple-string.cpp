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

  // Size does not mean "true size" characters to append_line.
  SimpleString test_string { 5 };
  printf("%s\n", test_string.append_line("a") ? "true" : "false");
  printf("%s\n", test_string.append_line("b") ? "true" : "false");
  printf("%s\n", test_string.append_line("c") ? "true" : "false");
  test_string.print("test_string");
}