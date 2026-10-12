//Normally, variables are stored in RAM, not on the hard disk.
//There are different types of memory, with different speeds :
//1 - Hard Disk → Slowest
//2 - RAM → Faster
//3 - Cache Memory → Faster than RAM
//4 - Register → Fastest(closest to the CPU
//	In old versions of C++, if you wanted a variable to be stored in a register,
// you could write register before it.
//	→ This was used for variables that needed very fast access.
//
//	But registers are very limited and valuable resources in the CPU.
//
//	From C++11 and above, the register keyword was removed because 
// modern compilers are smart enough to optimize this automatically.