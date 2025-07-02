### Related to `sort_students.cpp`
It is a C++ program to manage and sort student data using **custom comparators** and **std::sort**.

> In C++, before calling a method on a pointer, you must ensure that the pointer points to a valid object.  

`->` is syntactic sugar for dereferencing a pointer to an object. When you have a pointer to an object (like Student* s), you use:  
```cpp
s->InputData();
```
So:
- `->` dereferences the pointer (*s)  
- Then accesses a member of the object (InputData())

There are two essential custom comparators in this program:
```cpp
// Sorts by firstname, then lastname (lexicographical order)
bool sort_by_name(const Student* a, const Student* b) {
    if (a->firstname != b->firstname) 
        return a->firstname < b->firstname;
    return a->lastname < b->lastname; // Tie-breaker
}

// Sorts by marks (descending) with name tie-breaker
bool sort_by_marks(const Student* a, const Student* b) {
    if (a->marks != b->marks)
        return a->marks > b->marks; // Descending order
    return sort_by_name(a, b); // Fallback to name sort
```

The array `Student* s[user]` is sorted using pointer arithmetic (which decays to iterators):
```cpp
sort(s, s + user, sort_by_name); 
// s       = pointer to first element
// s+user  = pointer to one past last element
```
---
