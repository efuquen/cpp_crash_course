/**
Run: bazel run //ch3/listings:3-1

Creates an integer with default values. Prints the integer
and then prints the address of the pointer with &.
**/

#include <cstdio>

int main() {
    int gettysburg {};
    printf("gettysburg: %d\n", gettysburg);
    int *gettysburg_address = &gettysburg;
    printf("&gettysburg: %p\n", gettysburg_address);
}