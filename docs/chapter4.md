---
title: Ch4 - The Object Life Cycle 
layout: page
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

# An Object's Storage Duration

## Allocation, Deallocation, and Lifetime

Object stages:

1. Storage allocated, duration begins.
2. Constructor called
3. Lifetime begins.
4. Do stuff
5. Lifetime ends.
6. Destructor called.
7. STorage deallocated, duration ends.

## Memory Manaement

Describes memory managed languages and how C++ does not do this for the
programmer for greater runtime performance.

**Question 4.1**: *The author glosses over the pros and cons, but memory
management of vital importance when choosing a language. Can you think of more
pros and cons of memory management and/or specific examples from lanugages? Why
would you (or **must**) you use a non-memory managed language like C/C++.*

## Automatic Storage Duration

Allocation at beginning and end of a code block, with function parameters
counting as within the function code block. Automatic variables also called
local variables.

## Static Storage Duration

`static` or `extern` variables at global scope, allocated on program start
and deallocated on program stop. `static` variables have 'internal linkage',
meaning they are not accessible from external translation units (essentially
a C++ source file). To access from external translation units use `extern`.

### Local Static Variables

`static` variables in a local scope storage duration begins when first defined
in that local scope but last until the end of the program. The static variable
is not accessible outside that local scope.

### Static Members

Members of a class declared static have separate lifetimes from the class,
having same duration as a global static variable, just namespaced by the
`Class` name.

## Thread-Local Storage Duration

A variable can have a `thread_local` modifier that keeps a separate copy for
each thread. Lot more to say about concurrency later.

## Dynamic Storage Duration

Dynamic objects allocated with `new` keyword and programmer has direct control
on their storage duration. The pointer returned by `new` can be deallocated
with a call to `delete`.

What happens to deallocated memory in dynamic storage is undefined, but the
compiler pratically won't overwrite it unless it needs it for performance
reasons. This is a major source of program errors and possible security
vulnerabilities, as this means the memory could accidentally continued to be
used (use-after-free).

A short description of a possible security vulnerability with Use-After-Free
<https://6point6.co.uk/insights/common-software-vulnerabilities-part-ii-explaining-the-use-after-free/>

**NOTE**: *You should really avoid using `new` and `delete` directly as much
as possible and use more advanced pointers introduced later.*

See a more complete warning and suggestion on this in this other books Memory
Management chapter:

<https://learning.oreilly.com/library/view/professional-c-5th/9781119695400/c07.xhtml#head-2-90>

### Dynamic Arrays

Examples using `new` to dynamic storage arrays. Array length can be specified
at runtime and hence can be a variable.

### Memory Leaks

Basic warning about memory leaks, could be more in-depth.

# Tracing the Object Life Cycle

A walk through of implementing a `Tracer` class that illustrates a number of the
lifecycle scenarios listed above.

See [`src/ch4/listings/4-6.cpp`](
    https://github.com/efuquen/cpp_crash_course/blob/main/src/ch4/listings/4-6.cpp).

# Exceptions

General description of an exception and the alternative of returning an error
code.

## The throw Keyword

Describes simple throw syntax for exceptions, similar to other lanugages.

## Using try-catch Blocks

Same as with throw, straight-forward catch symantics. Aside on inheritance
in C++.

## stdlib Exception Classes

Use stdlib types as much as possible.

### Standard Exception Classes

Three major classes of errors outlined below.

### Logic Errors

`logic_error`, unexpected failures in logic of program, i.e. class invariants.

Distinction between `domain_error` (mathy emphasis) vs `invalid_argument`
(generally bad inputs).

### Runtime Errors

"error conditions outside the program's scope". I don't find this a good
explanation between difference with Logic Errors.

### Launguage Support Errors

Core language errors.

## Handling Exceptions

Describes the chain of exceptions in catches.

**Question 4.2**: *What order are catches evaluated in? The author doesn't
really clarify.*

## User-Defined Exceptions

user defined excedptions usually inherit from `std::exception`.

## The noexcept Keyword

`noexcept` marks a function to not throw an exception, but the compiler doesn't
check, your program will just terminate (oooppphhhffff).

The 'benefit' is compiler optimizations, unclear how big a deal that is.
Interesting reference to Item 16 at `Effective Modern C++`.

## Call Stacks and Exceptions

### Stacks

General description of a function call stack and how it works.

### Call Stacks and Exception Handling

Exceptions move up the call stack.

### Throwing in Destructors

Very bad, make sure exceptions are handled in destructor, otherwise the program
will terminate.

# A SimpleString Class

Introduction to RAII, where class constructor allocates and the destructor
deallocates, ensuring storage is never leaked.

A note about how there is a copy constructor and storage could be double free'd.
This has security implications:

<https://owasp.org/www-community/vulnerabilities/Doubly_freeing_memory>

**Question 4.3**: *How would you fix the double free problem?*

## Appending and Printing

## Using SimpleString

See [`src/ch4/listings/simple-string.cpp`](
    https://github.com/efuquen/cpp_crash_course/blob/main/src/ch4/listings/simple-string.cpp).

## Composing a SimpleString

Example of another class owning SimpleString object and order of constructor
& destructor.

## Call Stack Unwinding

Example of multiple function calls with SimpleStringOwner, eventually resulting
in an exception that unwinds the stack to main and is handled.

## Exceptions and Performance

No overhead for exception handling code if it's not thrown, unlike checking
error codes. But you pay a price if exceptions are thrown as they are more
expensive.

Might not be able to use exceptions in embedded or legacy code. If you use
RAII objects should clean themselves despite exceptions, but much legacy code
has manual (less safe) handling of memory.

## Alternatives to Exceptions

Recommends invariant flags & structured bindings to deal with errors if not
using exceptions.

**NOTE**: *Could have mentioned templated return classes, also a future
chapter like structured bindings.*

# Copy Semantics

To copy x to y means:

1. equivalences (`x == y`).
2. independence, modifying `x` does not modify `y`.

When passing by value to functions fundamental types and Plain Old Data (POD)
types are always copied by value, with PODs copied member by member.

Classes with dynamic members are very dangerous using member by member copy.
i.e. if `SimpleString` was copied in this way copies would point to the same
buffer. Aside from clobbering each others memory then destructed the copies
will delete the same buffers.

## Copy Constructors

## Copy Assignment

## Default Copy

## Copy Guidelines

# Move Semantics

## Copying Can Be Wasteful

## Value Categories

## lvalue and rvalue References

## The std::move Function

## Move Construction

## Move Assignment

## The Final Product

## Compiler Generated Methods