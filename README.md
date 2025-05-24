# C++ Module Manager
## Intro
This is a C++ project supporting *module* in C++ 98 or higher.

## Tutorial
You can put `modmgr.hpp` and `modmgr_undef.hpp` anywhere, as it does not include other file.

When you suppose to use it, 

```cpp
#include /*modmgr.hpp*/
// things you want to do
#include /*modmgr_undef.hpp*/
```

### module file
To define entities in the module `MOD`'s namespace, define then between `MOD_BEG(MOD);` and `MOD_END(MOD)`. The module name argument in `MOD_END` is advised but not required.

For example:
```cpp
// mod.hpp
#include<iostream> /*DO NOT INCLUDE FILE INSIDE MODULE*/

#include /*modmgr.hpp*/
MOD_BEG(mod);
// -------- module namespace --------
// You can see it as in a namespace(It is actually).
void f(int x){
  std::cout << x;
}
MOD_END(mod);
// -------- globals ------
#include /*modmgr_undef.hpp*/
```

**WARNING: ALL codes between `MOD_BEG` and `MOD_END` are defined inside module but NOT globals. Especially, do NOT include files inside modules.**

Not advised to define both globals and modules in one file, 
as it is confusing. 
Neither advised to define multiply modules in one file.

### module details

Define module detail between `DET_BEG(MOD)` and `DET_END(MOD)`. It is defined inside `/*Module namespace*/::_det`.

```cpp
DET_BEG(mod);
// -------- module details --------
void g(int);
DET_END(mod);
// -------- globals --------
```

When using module details in module namespace, 
```cpp
// -------- module namespace --------
void f(int x) {
  _det::g(x);
  // or,
  DET_USE(); // using namespace /*details*/;
  g(x);
}
```

### module including
To import a *scoped* module, use `MOD_USE`.
```cpp
int main() {
#include /*modmgr.hpp*/
  MOD_USE(mod);
#include /*modmgr_undef.hpp*/
}
```
### full example
```cpp
// mod_det.hpp
#ifndef MOD_DET_HPP
#define MOD_DET_HPP
#include "iostream"

#include /*modmgr.hpp*/
DET_BEG(mod);
// -------- detail ns mod --------

using namespace std;
void g(int x) {
  cout << x << endl;
}

DET_END(mod);
// -------- globals --------
#include /*modmgr_undef.hpp*/
#endif
```
```cpp
// mod.hpp
#ifndef MOD_HPP
#define MOD_HPP
#include "iostream"
#include "mod_det.hpp" // include details and sub-module in module file

#include /*modmgr.hpp*/
MOD_BEG(mod);
// -------- module ns mod --------

// using namespace std; // This pollutes the module namespace
void f(int x) {
  DET_USE();
  g(x);
  std::cout << x << endl;
}

MOD_END(mod);
// -------- globals --------
#include /*modmgr_undef.hpp*/
#endif
```
```cpp
// main.cpp
#include"mod.hpp"

int main() {
#include /*modmgr.hpp*/
  MOD_USE(mod);
#include /*modmgr_undef.hpp*/ // undef immediately
  mod::f(100);
#include /*modmgr.hpp*/
  MOD_USE_ALL(mod);
#include /*modmgr_undef.hpp*/ // undef immediately
  f(100);
}
```
Expected output:
```text
100
100
100
100
```

### Reference
**TBD**
