//
// Created by efuquen on 10/15/22.
//

#include <cstdio>

bool write_to(char* str, char ch, int i, int len) {
    if(i < 0 || i >= len) {
        return false;
    }
    str[i] = ch;
    return true;
}

bool read_from(const char* str, char* ch, int i, int len) {
    if(i < 0 || i >= len) {
        return false;
    }
    *ch = str[i];
    return true;
}

int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";

    char *upper_ptr = upper;

    lower[3] = 'd';
    upper_ptr[3] = 'D';

    printf("lower: %s\nupper: %s\n", lower, upper);

    char letter_d = lower[3];
    char letter_D = upper_ptr[3];

    printf("lower[3]: %c\nupper_ptr[3]: %c\n", letter_d, letter_D);

    lower[7] = 'g';

    printf("lower: %s\nupper: %s\n", lower, upper);

    printf("=========Safe read/write=========\n");

    bool status;
    status = write_to(lower, 'z', 0, sizeof(lower) / sizeof(char));
    if(!status) {
        printf("Failed to write z to index 0.");
        return -1;
    }
    char letter;
    status = read_from(lower, &letter, 0, sizeof(lower) / sizeof(char));
    if(!status) {
        printf("Failed to read z from index 0.");
        return -1;
    }
    printf("Read lower[0]: %c\n", letter);

    return 0;
}