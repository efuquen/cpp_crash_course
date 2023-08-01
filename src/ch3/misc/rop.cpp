/**
bazel run --copt="-fno-stack-protector" //ch3/misc:rop <arg1>

**/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char name[32];

void vulnerable(char* string) 
{
    char buffer[5];
    strcpy(buffer, string);
    puts(buffer);
}

int main(int argc, char** argv) {
    vulnerable(argv[1]);
    return 0;
}