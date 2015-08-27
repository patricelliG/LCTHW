#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);
typedef int *(*sorter)(int *numbers, int count, compare_cb cmp);

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }
    return target;
}

int *pivot_sort(int *numbers, int count, compare_cb cmp)
{
    int p = 0;
    int i = 0;
    int temp = 0;
    int biggest = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    // Walk the pivot 'p' down from the top of array
    for(p = count - 1; p > 0; p--) {
        biggest = 0;
        // Walk up to the pivot point 'p'
        for(i = 0; i <= p; i++) {
              if(cmp(target[biggest], target[i]) < 0) {
                biggest = i;
            }
        }
        // Swap the pivot with the largest number
        temp = target[p];
        target[p] = target[biggest];
        target[biggest] = temp;
    }
    return target;
    
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{ 
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp, sorter sort)
{
    int i = 0;
    int *sorted = sort(numbers, count, cmp);

    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");

    free(sorted);
}

int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    // Test bubble sort
    test_sorting(numbers, count, sorted_order, bubble_sort);
    test_sorting(numbers, count, reverse_order, bubble_sort);
    test_sorting(numbers, count, strange_order, bubble_sort);

    // Test pivot sort
    test_sorting(numbers, count, sorted_order, pivot_sort);
    test_sorting(numbers, count, reverse_order, pivot_sort);
    test_sorting(numbers, count, strange_order, pivot_sort);


    free(numbers);

    return 0;
}
