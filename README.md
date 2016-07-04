# vmath
[![Build Status](https://travis-ci.org/kernan/vmath.svg?branch=develop)](https://travis-ci.org/kernan/vmath)

## Introduction

*vmath* is a linear algebra header-only library for C++.

## Documentation

Full API documentation can be found [here](http://kernan.github.io/vmath/)

## Usage

### Functions

_vmath/functions.hpp_ provides basic linear algebra functions (sine, cosine, etc.)
and conversions operations (degrees, radians) as well as more generic rounding,
exponent, and interpolation functions. The full list may be found
[here](http://kernan.github.io/vmath/functions_8hpp.html).

### Structures

Also provided are vector and matrix structures. The core of *vmath* contains
generic length and container types, but commonly used types are pre-defined in
_vmath/types.hpp_. The pre-defined types may be found
[here](http://kernan.github.io/vmath/types_8hpp.html).

If you require functionality beyond the pre-defined types you can go directly to
the core implementation (`vmath::core`) and create your own. Documentation for
the core may be found
[here](http://kernan.github.io/vmath/namespacevmath_1_1core.html).

## License

MIT License. Copyright (c) 2013-2016 Robert Kernan.
