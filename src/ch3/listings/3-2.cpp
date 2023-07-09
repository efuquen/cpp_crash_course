/**
Run: bazel run //ch3/listings:3-2

Creates an integer variable and uses address-of operator to create
a pointer variable that points to the integer.

The initial value is printed using the dereference pointer operator on the rhs 
followed by the raw pointer address. Then the value is changed with the
dereference operator on the lhs and the value & address are printed again.
**/

#include <cstdio>

int main() {
    int gettysburg{};
    int* gettysburg_address = &gettysburg;
    printf("Value at gettysburg_address: %d\n", *gettysburg_address);
    printf("Gettysburg Address: %p\n", gettysburg_address);
    *gettysburg_address = 17325;
    printf("Value at gettysburg_address: %d\n", *gettysburg_address);
    printf("Gettysburg Address: %p\n", gettysburg_address);
}