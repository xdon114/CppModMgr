
# C++ Mod Manager

# Intro

A library supporting *modules* since c++98.

# Simple

`undef_modmgr.hpp`: undef macros in `modmgr.hpp`.
Slient when `modmgr.hpp` not included.

`CPPMODMGR_VER`: Version number as format `0xXXYYZZ`.\
`MOD_BEGIN(Mod)`: Start module definition in Mod.
All decls and defs are in module Mod.\
`MOD_END(Mod)`: Exit module Mod and return to global.\
`USE_MOD(Mod)`: let `Mod` alias to module namespace Mod.\
`FROM_MOD(Mod) Member`: From Mod import Member.
`ALL_FROM_MOD(Mod)`: From Mod import all entities.

# Example

```cpp
/////// lib1.h
#include <iostream>
#include /*modmgr.h*/
MOD_BEGIN(lib1);
int x;
void f() {
    std::cout << x << std::endl;
}
MOD_END(lib1);
```

```cpp
/////// main.cpp
#include "lib1.h"

int main() {
{
#include /*modmgr.h*/
    USE_MOD(lib1);
    FROM_MOD(lib1) x;
#include /*undef_modmgr.h*/
    x = 3;
    lib1::f();
}
#include /*modmgr.h*/
    ALL_FROM_MOD(lib1);
#include /*undef_modmgr.h*/  
    x = 5;
    f();
}
```
