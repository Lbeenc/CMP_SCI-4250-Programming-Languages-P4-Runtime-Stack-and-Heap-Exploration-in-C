#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 500  // Default size of the array
#define RECURSION_LIMIT 10  // Limit for f1() and f3()

// Global static variable for tracking stack size
static int activation_record_count = 0;

void f1() {
    static int n = 0;
    static long addr = 0;

    int array[ARRAY_SIZE];
    long current_addr = (long)&array;

    n++;
    activation_record_count = n;

    if (n > 1) {
        printf("Call #%d at 0x%lx\n", n, current_addr);
        printf("AR Size #%d is %ld\n", n, addr - current_addr);
    } else {
        printf("Call #%d at 0x%lx\n", n, current_addr);
        printf("AR Size #%d is 0 (First Call)\n", n);
    }

    addr = current_addr;

    if (n < RECURSION_LIMIT) {
        f1();
    }
}

void f2() {
    static int n = 0;
    static long addr = 0;

    int array[ARRAY_SIZE];
    long current_addr = (long)&array;

    n++;
    activation_record_count = n;

    long ar_size = (n > 1) ? (addr - current_addr) : 0;
    long total_stack_size = n * ar_size;

    printf("Call #%d at 0x%lx\n", n, current_addr);
    printf("AR Size #%d is %ld\n", n, ar_size);
    printf("Stack Size #%d is %ld\n", n, total_stack_size);

    addr = current_addr;

    f2();
}

void f3() {
    static int n = 0;  // Tracks  activation records

    char c;
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    n++;
    activation_record_count = n;

    long ar_size = (long)&c - (long)array;

    printf("Call #%d at 0x%lx\n", n, (long)array);
    printf("AR Size #%d is %ld\n", n, ar_size);

    free(array);

    if (n < RECURSION_LIMIT) {
        f3();
    }
}

int main() {
//uncomment the functions to test the outputs one by one
    //f1();
    // f2();
    // f3();

    return 0;
}
