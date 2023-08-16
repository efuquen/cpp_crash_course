---
title: Ch11 - Smart Pointers
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

# Smart Pointers

Managing memory manually is hard, i.e. on errors or exceptions. RAII makes
this manageable and modern C++ provides prebuilt utilities to do it, smart
pointers.

# Smart Pointer Ownership

The ownership model of smart pointers gurantees if you have a reference to it
the object is allocated and it won't leak. Onwership requirements drive the
choice of which smart pointer to use.

# Scoped Pointers

**NOTE**: *Interesting choice to start with Boost specific pointer type.*

Dynamic object of scoped pointer cannot be moved (non-transferable) and it can
only be owned by one smart pointer (exclusive ownerhsip).

## Constructing

All smart pointers are either `empty` (when first constructed) or `full` (after
they are assigned). Usually use directly pass a `new` dynamic object into smart
pointer constructor.

## Bring in the Oath Breakers

Introduces new class as example to use scoped ptr with

## Implicit bool Conversion Based on Ownership

`scoped_ptr` is a `true` value if it has an object, `false` if not.

## RAII Wrapper

Example of how `scoped_ptr` calls a destructor when it goes out of scope.

## Pointer Semantics

Example of common pointer operations with the smart pointer.

## Comparison with nullptr

Can use standard comparison (`==` & `!=`) with `nullptr` for `empty` **only**.

## Swapping

You can use `swap` to in place exchange scoped pointers.

## Resetting and Replacing a scoped_ptr

`reset()` will destruct the current pointer and leave it empty if not passed
in anything. If passed in a new dynamic object it will destruct the current
one and replace it with the new dynamic object.

## Non-transferrability

Any attempt to copy or move a `scoped_ptr` results in a compilation error.

## boost::scoped_array

Allows the use of `[]` index operator with a dynamic array.

# Unique Pointers

# Shared Pointers

# Weak Pointers

# Intrusive Pointers

# Summary of Smart Pointer Options

# Allocators
