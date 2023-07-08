---
title: Chapter 3
layout: page
---

# Pointers

Pointers encode an object's **address** and it's **type** to interact with it. Low-level construct used often in C, but higher-level constructs in C++ reduce use, but are still a foundational concept.

Section summary:
- Find address of an object and assigne to a pointer variable.
- *Dereferencing* a pointer to get the underlying object.
- Managing *arrays* and what can go wrong with array & pointer-based programs.
- Two special pointers, `void` and `std::byte` pointers.
- Encode empty pointers with `nullptr`.
- Pointers in Boolean expressions.

## Addressing Variables

Use the *address-of operator (&)* to obtain the address of a pointer, see `src/ch3/listings/3-1.cpp`. Multiple runs will return different addresses dueo to *address space layout randomization*.

### Address Space Layout Randomization
