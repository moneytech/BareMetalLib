# BareMetalLib
[![Build Status](
    https://travis-ci.org/kuanweeloong/BareMetalLib.svg?branch=master)](
    https://travis-ci.org/kuanweeloong/BareMetalLib)

## Introduction
BareMetalLib (BML) is an experimental, modern C++, header-only support library for bare-metal
programming. It aims to provide functionality similar to that of the C++ standard library, but in
a form more suited to bare-metal code; its main use case is for environments where using the normal
C++ standard library is not possible. To this end, BML eschews the use of:

- Headers from the C and C++ standard libraries, except for C11 freestanding headers
- Exceptions (By design, BML is `noexcept` throughout and provides no exception guarantees.)
- RTTI
- Thread-local storage
- Static objects
- Dynamic allocation via global `operator new` or `operator new[]`
- Floating point operations

BML does not assume that user code is subject to the same limitations; user code is free to use any
of the features listed above (although using exceptions will be problematic due to BML's
`noexcept`-ness and lack of exception guarantees). However, due to these constraints, BML is **not**
a drop-in replacement for the C++ standard library.

BML is based on [libc++](https://libcxx.llvm.org/). This is a learning project, so please be
patient!

## Requirements
BML requires a C++17 conforming compiler. It is tested on the following platforms:

| OS                 | Architecture | Compiler    | Remarks       |
| ------------------ | ------------ | ----------- | ------------- |
| Ubuntu 18.04.1 LTS | x64          | GCC 8.2.0   |               |
| Ubuntu 18.04.1 LTS | x64          | Clang 6.0.0 |               |
| Ubuntu 16.04.5 LTS | x64          | GCC 8.1.0   | Via Travis CI |
| Ubuntu 16.04.5 LTS | x64          | Clang 6.0.1 | Via Travis CI |

## License
BML is licensed under the MIT license. For more details, see [LICENSE.md](LICENSE.md).
