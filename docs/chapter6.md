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