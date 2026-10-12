/*
  In programming, "Memory" typically refers to RAM.
  A program's memory in RAM is generally divided into four main sections:

  1. Code (or Text) Segment:
     - This is where the executable instructions (your compiled code) are stored.
     - It usually has a fixed size.

  2. Global / Static Data Segment:
     - This section holds global and static variables.
     - The lifetime of these variables lasts for the entire duration of the program.
     - It also has a fixed size.

  3. The Stack:
     - This memory is managed automatically by the operating system for the program.
     - It is used to store local variables, function parameters, and function call information.
     - Pointers themselves (the variables that hold addresses) are typically stored here.
     - Its size changes as functions are called and return.

  4. The Heap:
     - This is a region of free memory that the developer can access for dynamic allocation using pointers.
     - The actual dynamically allocated data is stored on the Heap.
     - For example, in the statement `int* ptrX = new int;`:
       - The pointer variable `ptrX` is created on the Stack.
       - The integer it points to is allocated on the Heap.
     - The Heap is used for any dynamic variables, objects, arrays, etc., whose size might not be known at compile time.
*/

#include <iostream>

int main() {
    // You can place the comment here or anywhere else in your code.
    std::cout << "This is an example of C++ code." << std::endl;
    return 0;
}