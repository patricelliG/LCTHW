// add standard input and output functions
#include <stdio.h>
// include the ability to assert
#include <assert.h>
// include stdlib for sizeof
#include <stdlib.h>
// adds strdup
#include <string.h>

// make a person struct with a string and serveral ints
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// make a new person and return a pointer "who" that points to that space in memory
struct Person Person_create(char *name, int age, int height, int weight)
{
    struct Person who;

    // assign the various fields
    who.name = name;
    who.age = age;
    who.height = height;
    who.weight = weight;

    // return the new person
    return who;
}

// now that Person is created on the stack, this function is not needed
//void Person_destroy(struct Person *who)
//{
//    // make sure the pointer is pointing to something
//    assert(who != NULL);
//
//    // free the strdupe memory
//    free(who->name);
//    // free the rest of the person structure
//    free(who);
//}

// simply print the various fields of person
void Person_print(struct Person who)
{
    printf("Name: %s\n",who.name);
    printf("\tAge: %d\n",who.age);
    printf("\tHeight: %d\n",who.height);
    printf("\tWeight: %d\n",who.weight);
}

// demonstrate person functionality
int main(int argc, char *argv[])
{
    // make two people structures
    struct Person joe = Person_create(
            "Joe Alex", 32, 64, 140);

    struct Person frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out
    Person_print(joe);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40;
    Person_print(joe); 

    frank.age += 20;
    frank.weight += 20;
    Person_print(frank);

    // The structs are now on the stack, not heap! 
    //Person_destroy(joe);
    //Person_destroy(frank);

    return 0;
}
