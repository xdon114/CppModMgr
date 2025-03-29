# xdon's c++ module manager
建议搭配源代码阅读。

## 1.04

### `ModG_MBegin(ModuleName, NamesapceName)`

表示此宏函数之后直到`ModG_MEnd()`之前,
都是在模块`ModuleName`中的命名空间`NamespaceName`中的定义.

在此区间内的代码应注意其是在命名空间中定义的,
特别是不能在此区间内进行 `#include` 操作.

### `ModG_MEnd()`

见上。

### `ModG_ModNS(ModuleName)`

表示这个模块的命名空间.

### `ModG_Import(ModuleName)`

表示使模块中的所有标识符在此作用域下都可用.

注意其实际是 `using namespace`,
可能造成标识符泄露.

### `ModG_Ver()`

模块管理器的版本

### 其他注意事项

由于源代码较短,
程序员可以直接阅读代码以得到更好的理解
~~因为我根本不会写README~~.

任何作为某一个或多个模块实现的文件应当包含 `#pragma once`.

如果标识符有冲突, 可以如下操作:
```c++
#pragma once
#include<iostream>
#include"module2.h"

#include"libs/modmgr_def.h"
ModG_MBegin(M1,M1);
#include"libs/modmgr_undef.h"

void add_and_print(int a, int b) {
    #include"libs/modmgr_def.h"
    ModG_Import(M2);
    #include"libs/modmgr_undef.h"

    std::cout << M2::add_int(a + b) << endl;
    return;
}

#include"libs/modmgr_def.h"
ModG_MEnd(); // M1::M1
#include"libs/modmgr_undef.h"
```
即在每次使用时包含定义文件, 
使用, 并包含去定义文件.

如果需要将其替换为其他名称, 
也可以包装,如

```c++
#error This paragrah is to be developed.
// libs/modg.h
// libs/demodg.h
```

或直接修改源代码, 
注意统一定义文件和去定义文件中的标识符.
