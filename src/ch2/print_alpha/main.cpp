//
// Created by efuquen on 10/8/22.
//

#include <cstddef>
#include <cstdio>


int main() {

    char alpha[26];
    for (size_t i = 0; i < 26; i++) {
        char cur_alpha = i + 97;
        printf("%c ", cur_alpha);
        alpha[i] = cur_alpha;
    }

    printf("\n");

    for (size_t i = 0; i < 26; i++) {
        char upper_alpha = alpha[i] - 32;
        printf("%c ", upper_alpha);
    }

    return 0;
}