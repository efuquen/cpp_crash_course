---
title: Ch6 - Compile-time Polymorphism
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

# Declaring Templates

Use carets with `typename`  or `class` (legacy reasons) with a letter, i.e.
`template<typename X, typename Y>`.

Can be used in front of class definitions or functions.

# Named Conversion Functions

Convert to different types using template functions.

`const_cast` removes the `const` from the type.

`static_cast` makes standard conversions that would be allowed implicitly, and
the reverse of those conversions.

`reintepret_cast` gives you full control on casting, i.e. allowing casting a
number to a specific pointer in memory.

`narrow_cast` like a `static_cast` but will throw an exception if the value
will be narrowed.

# mean: A Template Function Example

Illustrative example with a `mean` function how templates can reduce code
through generic programming.

## Template Type Deduction

The type in the template parameter can be deduce by C++, similar to using
`auto`. However sometimes its not possible for the compiler to deduce
the type on return types.

# Type Checking in Templates

Template type checks happen late in compilation, leading to cryptic error
messages. Comparison to duck-typing doing checks at runtime vs compilation.

# Concepts

Template parameter checking at point of instation as opposed to point
of first use.

concepts are a function that return True if they pass some set of
static validations through type traits and/or requirements.

The sole stated benefit is to get better compiler errors, with a lot
more code and compilation complexity. But, many concepts will be
defined by the standard library and should avoid you having to write
your own.