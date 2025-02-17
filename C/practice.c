#include <stdio.h>

typedef struct {
    char *name;
    int number;
}
person;

int main(void) {
    person p1;
    p1.name = "Adnan";
    p1.number = 22;
    person p2;
    p2.name = "Abtahi";
    p2.number = 6;
    printf("name: %s. age: %i\n", p1.name, p1.number);
    printf("name: %s. age: %i\n", p2.name, p2.number);
}
