---
title: Ch5 - Runtime Polymorphism
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

# Polymorphism

Polymorphism is shared code among types. Compile time and runtime polymorphism
are linked.

# A Motiviating Exmaple

Logger requirements:

- Log to multiple different destinations (remote, local, printer).
- Change the logging at runtime.

Proposes an approach that uses enum to switch for different logger types in the
bank transfer function.

## Adding New Loggers

The downside of switching on enums is it takes many updates to different places
in code to add new logger types.

## Interfaces

A generic interface gets ride of much of these downsides.

## Object Composition and Implementation Inheritance

Author states a clear preference for object composition, despite what is stated
this is not any sort of clear consensus that inheritance is 'antiquated'.

There is certianly a valid/widely held view that inheritance can be over-used &
mis-used, that does not mean it should never be used. One common saying is to
"prefer composition over inheritance". That is not the same as "never use
inheritence".

Listing Go & Rust to justify the strong statement on inheritence is a bit
misguided when I can make a long long list of languages (including new ones)
that include it:

C#, C++, JavaScript, Java, Swift, Kotlin, Dart, Scala, Python, and Ruby

However, the communities in both Go & Rust certainly agree it's not worth
having anything other then interface inheritance.

Go FAQ on why there is no inheritence:

https://go.dev/doc/faq#inheritance

Reddit thread on inheritence in Rust:

https://www.reddit.com/r/rust/comments/14q7i0m/languages_on_the_rise_like_rust_and_go_are_being/

Clarifying description on the difference between *interface* vs *implemenation*
inheritence:

> Implementation inheritance is a relationship where a child class inherits
> behaviour implementation from a base class. Interface inheritance is when a
> child class only inherits the description of behaviour from the base class
> and provides the implementation itself.

https://www.linkedin.com/pulse/why-prefer-interface-inheritance-implementation-adrain-pinto/

# Defining Interfaces

Using C++ implementation inheritance mechanisms to define interfaces.

## Base class inheritence

Describes previous discuession on error classes with inheritence.

## Member Inheritence

non-private members inherited by classes as well, but author recommends not
doing this, as the primary reason to use it is for base class implementations.

## Virtual methods

`virtual` methods can be override in child classes, to *require* child classes
override a `virtual` method make it equal to `=0`.

## Pure-Virtual Classes and Virtual Destructors

Pure virtual classes are only composed of pure virtual methods, acting as
interfaces in C++.

If you do not specify the destructure as a virtual method in these cases the
child class destructor will not be called. The text doesn't explain why this
is necessary.

This article describes the reason more directly, that the Base class has a
destructor if it's not marked as virtual and code will not look for a child
classes destructor if it's not marked as overriden.

https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks

## Using Interfaces

A basic description of how to use Dependency Injection with interfaces, property
vs constructor injection.

Also, if the type could be determined at compilation time prefer to use
templates.

# Updating the Bank Logger

Implements Bank's logger with constructor and property injection and compares
the two pros/cons.