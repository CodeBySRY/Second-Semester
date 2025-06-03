## Related To `lab_final_prac.cpp`
### Pointer vs. Object Passing: Debugging the `Test` Class
Initially, I was making the mistake in the following line of code:
```cpp
void change(Test t) { this->x = t->x; } // Error: t is not a pointer
```
This was a silly mistake at my end, but nonetheless, I wanted to document it, just so that someone else, or even me, runs into the same error again. 
The reason it failed:

1. **Type Mismatch**:
    
    - `t` was declared as an **object** (`Test t`), but I tried to access it as a **pointer** (`t->x`).

    - `->` is strictly for pointers; objects use `.` (dot) notation.
2. **Memory Inefficiency**:

    - Passing by value (`Test t`) creates a _copy_ of the object, wasting resources for no reason.

The **solution** was that the parameter type was to be changed to a pointer:
```cpp
void change(Test *t) { this->x = t->x; }  // t is now a pointer
```
> Use `->` only for pointers (`Test*`). Additionally, always `delete` dynamically allocated objects (to prevent memory leaks).