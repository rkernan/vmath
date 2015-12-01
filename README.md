# Math
[![Build Status](https://travis-ci.org/kernan/vmath.svg?branch=master)](https://travis-ci.org/kernan/math)

## Introduction

*Math* is a linear algebra header-only library for C++.

## Documentation

Full API documentation can be found [here](http://kernan.github.io/math/)

## Usage

### Functions

_math/functions.hpp_ provides basic linear algebra functions (sine, cosine, etc.)
and conversions operations (degrees, radians) as well as more generic rounding,
exponent, and interpolation functions. The full list may be found
[here](http://kernan.github.io/math/functions_8hpp.html).

### Structures

Also provided are vector and matrix structures. The core of *Math* contains
generic length and container types, but commonly used types are pre-defined in
_math/types.hpp_. The pre-defined types may be found
[here](http://kernan.github.io/math/types_8hpp.html).

If you require functionality beyond the pre-defined types you can go directly to
the core implementation (`math::core`) and create your own. Documentation for
the core may be found
[here](http://kernan.github.io/math/namespacemath_1_1core.html).

## License

MIT License. Copyright (c) 2013-2015 Robert Kernan.
