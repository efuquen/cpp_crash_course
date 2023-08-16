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

A `unique_ptr` is *transferable* (can be moved) but still have exclusive
ownership (can't be copied). Part of standard library in `<memory>` header.

**Question 11.1**: *Why would we not just use the standard library `unique_ptr`*
*over boost dependency `scoped_ptr`?*

## Constructing

Can be constructed in the same way as a `scoped_ptr`, but has one other way,
using `make_unique<T>()`. Latest C++ it doesn't matter which version you use.

## Supported Operations

All the same ones as `scoped_ptr`.

## Transferable, Exclusive Ownership

Shows how `move` works with a `unique_ptr`.

## Unique Arrays

`unique_ptr` supports arrays directly, but be careful not to accidently set
an dynamic array `[]T` to a pointer that has `T`. The compiler can't catch it
and it will not properly clean up the dynamic array.

## Deleters

A second template paramter to `unique_ptr` specifies a `Deleter`, which a
default implementation just calls `delete` or `delete[]` on the object or array.

You can specify a custom deleter which is just a function that takes in a `*T`
type. More on `decltype`: <https://en.wikipedia.org/wiki/Decltype>

## Custom Deleters and System Programming

Example of need for custom Deleter with system programming. A `*FILE` handle
shoudl have `fclose()` called to release the file resource, not `delete`.

**Question 11.2**: *Any built in RAII types for file handling?*

# Shared Pointers

`shared_ptr` has *transferable* and *non-exclusive* ownership. On destruction
the `shared_ptr` will check if there are other owners.

**Question 11.3**: *Why not use the more power `shared_ptr` over `unique_ptr` ?*

## Constructing

Same as `unique_ptr`, except you *should* prever `make_shared<T>` over regular
construction. You will be duplicating allocations if you don't.

**Question 11.4**: *What exactly is the 'control block' referenced in the text?*

Much more details on the internals of `shared_ptr` and the 'control block':
<https://www.nextptr.com/tutorial/ta1358374985/shared_ptr-basics-and-internals-with-examples>

## Specifying an Allocator

You can specify a custom allocator with `shared_ptr`. A few complicated
semantics about how to do this, but this section doesn't explain why you
would want to.

**Question 11.5**: *Why would specify a custom allocator?*

# Weak Pointers

# Intrusive Pointers

# Summary of Smart Pointer Options

# Allocators
