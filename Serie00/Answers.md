## 2.3
`off_t` represents at least the size of an `int`, but on an 64-bit machine, 
it will transparently scale up to `off64_t`, allowing the use of all 64 bits. 

`size_t` represents an unsigned number, typically used to represent sizes of any object in bytes. 

## 2.6
`f()` returns the address of a local variable, getting freed after the function call.
The address therefore points to a memory location, which is not part of the program anymore. 
A segmentation fault occurs. 