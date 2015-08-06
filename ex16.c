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
struct Person *Person_create(char *name, int age, int height, int weight)
{
    // allocate memory equal to Person size and have who point to it
    struct Person *who = malloc(sizeof(struct Person));
    // make sure the memory was allocated correctly
    assert(who != NULL);

    // assign the various fields
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    // return the pointer to the new person
    return who;
}

// remove the person who points to correctly
void Person_destroy(struct Person *who)
{
    // make sure the pointer is pointing to something
    assert(who != NULL);

    // free the strdupe memory
    free(who->name);
    // free the rest of the person structure
    free(who);
}

// simply print the various fields of person
void Person_print(struct Person *who)
{
    printf("Name: %s\n",who->name);
    printf("\tAge: %d\n",who->age);
    printf("\tHeight: %d\n",who->height);
    printf("\tWeight: %d\n",who->weight);
}

// demonstrate person functionality
int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
            "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe); 

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}





