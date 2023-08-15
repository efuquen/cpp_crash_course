#include <cstdio>

struct College {
    char name[256];
};

struct ShorterCollege {
    char name[10];
};

void print_name(College* college_ptr) {
    printf("%s College\n", college_ptr->name);

    // Extra to original Listing.
    printf("%s College[0]\n", college_ptr[0].name);
    printf("%s College[1]\n", college_ptr[1].name);
    printf("%s College[2]\n", college_ptr[2].name);
    // Past end of array.
    printf("%s College[3]\n", college_ptr[3].name);
    // NULL string byte.
    printf("name[8]: '%c'\n", college_ptr->name[8]);
    // Past NULL string byte in char array.
    printf("name[9]: '%c'\n", college_ptr->name[9]);
    // Past end of char array.
    printf("name[256]: '%c'\n", college_ptr->name[256]);
    printf("name[257]: '%c'\n", college_ptr->name[257]);
    printf("name[258]: '%c'\n", college_ptr->name[258]);
    printf("name[259]: '%c'\n", college_ptr->name[259]);

    // Fun totally not safe thing to do.
    printf("%s college_ptr->name[256]\n", &(college_ptr->name[256]));
    printf("%s college_ptr->name[256*2]\n", &(college_ptr->name[256*2]));
}

void print_shorter_names(ShorterCollege* shorter_college_ptr) {
    printf("%s shorter_college_ptr->name\n", shorter_college_ptr->name);
    printf("%s shorter_college_ptr.name[10]\n", &(shorter_college_ptr->name[10]));
}

int main() {
    College best_colleges[] = { "Magdalen", "Nuffield", "Kellog" };
    print_name(best_colleges);
    ShorterCollege shorter_colleges[] = { "Magdalen", "Nuffield", "Kellog" };
    print_shorter_names(shorter_colleges);
}