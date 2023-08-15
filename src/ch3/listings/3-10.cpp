#include <cstdio>

struct Element {
  Element* next{};
  void insert_after(Element* new_element) {
    new_element->next = next;
    next = new_element;
  }
  char prefix[2];
  short operating_number;
};

struct CharPtrElement {
  CharPtrElement* next{};
  char* prefix;
  short operating_number;
};

struct DataPtrElement {
  DataPtrElement* next{};
  void* data;
};

int main() {
  Element trooper1, trooper2, trooper3;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 421;
  trooper1.insert_after(&trooper2);
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper2.insert_after(&trooper3);
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;

  for (Element *cursor = &trooper1; cursor; cursor = cursor->next) {
    printf("stormtrooper %c%c-%d\n",
           cursor->prefix[0],
           cursor->prefix[1],
           cursor->operating_number);
  }

  CharPtrElement trooper4;
  trooper4.prefix = "ABCDEFGHIJKLMNOPQRSTUVWXZY";
  trooper4.operating_number = 001;
  DataPtrElement trooper5;
  printf(
    "element size: %d char_ptr_element size: %d void_element size: %d\n",
    sizeof(trooper3), sizeof(trooper4), sizeof(trooper5));
}

