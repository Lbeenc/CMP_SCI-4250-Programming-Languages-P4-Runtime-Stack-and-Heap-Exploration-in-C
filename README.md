# CMP_SCI-4250-Programming-Languages-P4-Runtime-Stack-and-Heap-Exploration-in-C

Project Specification: Runtime Stack and Heap Exploration in C

Overview:
This project requires you to explore activation records in both the runtime stack and heap by implementing three different functions: `f1()`, `f2()`, and `f3()`. Each function will explore activation records in different ways, examining the stack or heap and calculating the sizes of activation records and stack space.

The `main()` function should look like this:

int main() {
    f1();
    //f2();
    //f3();
    return 0;
}

_________________________________________________________________________________________________________________________________________________________________________

Function f1() Specification:

The f1() function should:

1. Define a local array of integers (int array[]), with the size adjustable via a define macro. The default size should be 500.
2. Define a static integer variable n that increments with each function call to track the number of activation records.
3. Define a static long integer addr that stores the starting address of the local array.
4. Print the following details for each function call:
   - The current activation record number.
   - The memory address of the current local array.
   - The difference in memory addresses between the current activation record and the previous one (representing the size of the current activation record).
5. Recursively call f1() up to a maximum of 10 calls.

Sample Output for f1():

Call #1     at 0x7ffdd1a2b530
AR Size     #1     is 45000

Call #2     at 0x7ffdd1a2b3f0
AR Size     #2     is 64

Call #3     at 0x7ffdd1a2b2b0
AR Size     #3     is 64

Call #4     at 0x7ffdd1a2b170
AR Size     #4     is 64

...

___________________________________________________________________________________________________________________________________________________________

Function f2() Specification:

The f2() function should:

1. Perform all the same tasks as f1().
2. The recursion should continue indefinitely, eventually resulting in a segmentation fault due to stack overflow.
3. Each function call should also print the estimated total stack size, calculated as the product of the activation record size and the number of activation records so far.

Sample Output for f2():


Call #1     at 0x7fffd1e2b3d0
AR Size     #1     is 500
Stack Size  #1     is 500

Call #2     at 0x7fffd1e2b3b0
AR Size     #2     is 500
Stack Size  #2     is 1000

Call #3     at 0x7fffd1e2b390
AR Size     #3     is 500
Stack Size  #3     is 1500

...
________________________________________________________________________________________________________________________________________________________________________________

Function f3() Specification:

The f3() function should:

1. Define a dynamically allocated array using malloc() instead of using the stack.
2. Introduce another local variable (e.g., a char c) in the function to track the size of the current activation record.
3. Calculate the size of the activation record by measuring the difference between the memory address of the dynamically allocated array and the address of the local variable c.
4. Ensure to free the dynamically allocated array before each recursive call to avoid memory leaks.
5. Recursively call f3() up to a maximum of 10 calls.

Sample Output for f3():

Call #1     at 0x1f72fe10
AR Size     #1     is 40

Call #2     at 0x1f72fdd0
AR Size     #2     is 40

Call #3     at 0x1f72fd90
AR Size     #3     is 40

Call #4     at 0x1f72fd50
AR Size     #4     is 40

...

______________________________________________________________________________________________________________________________________________________________

Additional Guidelines:

- Function Parameters and Recursion Limit:
  - Each function (f1(), f2(), f3()) should contain logic to track and print the current activation record count and sizes.
  - For f1() and f3(), limit the recursion to 10 calls to avoid infinite recursion.
  - For f2(), allow the recursion to continue indefinitely, until the stack overflows and causes a segmentation fault.
  
- Dynamic Allocation (in f3()):
  - When using malloc() in f3(), ensure to properly free the memory at the end of each recursive call to avoid memory leaks.
  
- Testing:
  - Test each function separately by commenting/uncommenting the respective function calls in main(). 

---

Submission.

Submit the following:

A single C file containing the implementations for f1(), f2(), f3(), and main();
The complete output of your program when you execute f1();
The part of the output of your program when you execute f2() with 10 last calls before segmentation fault;
The complete output of your program when you execute f3();
 

You are NOT supposed to get the same numerical values in your output as in sample runs.

The output may be shown in screenshots or snippets.
