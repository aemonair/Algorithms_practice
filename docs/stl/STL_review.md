[TOC]
# 1. STL
- C++ Standard Library C++标准库
- Standard Template Library STL标准模板库
《C++标准程序库》
## 1.1 六大部件
### 1.1.0 六大部件
- 容器（container）、
- 分配器（Allocators）、
- 算法（algorithm）、
- 迭代器（iterator）、
- 适配器（ adaptor）、
- 函数对象函数对象（functor）

> 分配器给容器分配存储空间，
> 算法通过迭代器获取容器中的内容，
> 仿函数可以协助算法完成各种操作，
> 配接器用来套接适配仿函数

## 1.2 容器Container
### 1.2.1 顺序容器
- Array
- vector
- Deque
- List
- Forward-List

|                 名称                  |                                                                                                          特性                                                                                                          |
| ------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| vector                                | 模拟的数据结构式动态数组，在内存中是连续储存的，支持随机存取，支持在尾部快速插入和删除元素，搜索速度较慢                                                                                                                          |
| deque                                 | 称为双端队列，在内存中的储存方式是小片连续，每片之间用链表连接起来，支持随机存取，支持在头部和尾部快速插入和删除元素，搜索速度较慢                                                                                                   |
| list                                  | 称为双向链表，在内存中的储存是不连续的，每个元素的内存之间用指针相连，不支持随机存取（因为要从首或尾遍历至指定位置），但是支持在任意位置快速插入和删除元素，搜索速度最慢，扩展内存时无需复制和拷贝原元素                                     |
| <font color='red'>array</font>        | 称为静态数组，在内存中是连续储存的，支持随机存取，不支持插入或删除元素                                                                                                                                                        |
| <font color='red'>forward_list</font> | 称为前向链表，在内存中的储存是不连续的，同list一样支持在任意位置快速插入和删除元素，不支持随机存取，搜索速度也较慢，与list最大的区别在于其只能从头部遍历至尾部，不能反向遍历，因此没有保存后向指针，比list更省内存，插入和删除元素比list稍慢。 |
### 1.2.2 关联式容器
- Set/Multiset Containers
- Map/Multimap Containers

|   名称   |                                                                          特性                                                                           |
| -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| set      | 以红黑树实现，内存中是不连续储存的，保存的是元素是唯一的键值且不可变，排列的方式根据指定的严格弱序排列，不支持随机存取，搜索速度较快                                  |
| multiset | 与set基本一致，差别就在于允许保存重复键值                                                                                                                   |
| map      | 同样以红黑树实现，保存的元素是一个pair类型{key, value}，每个键值对应一个值，且键值唯一不可变，键值的排列方式根据指定的严格弱序排列，支持用key进行随机存取，搜索速度较快 |
| multimap | 与map基本一致，差别在于键值可以重复                                                                                                                        |
### 1.2.3 无序容器Unordered Containers
- Unordered Set/Multiset Containers
- Unordered  Map/Multimap Containers
(HashTable )

|   名称   | 特性|
| -- | -- |
|unordered_set|以哈希表实现，内存中是不连续储存的，保存的是元素是唯一的键值且不可变，无序的排列方式，不支持随机存取，搜索速度比红黑树实现的set要快|
|unordered_multiset|与unordered_set基本一致，差别就在于允许保存重复键值|
|unordered_map|同样以哈希表实现，保存的元素是一个pair类型{key, value}，每个键值对应一个值，且键值唯一不可变，key值无序排列，支持用key进行随机存取，搜索速度比红黑树实现的map要快|
|unordered_multimap|与unordered_map基本一致，差别在于键值可以重复|

### 1.2.4 容器适配器：均可以用vector, list和deque来实现，没有提供迭代器

|      名称      |                                   特性                                   |
| -------------- | ------------------------------------------------------------------------ |
| stack          | 默认用deque来实现数据结构的栈的功能                                         |
| queue          | 默认用deque来实现数据结构的队列的功能                                       |
| priority_queue | 默认用vector来实现，其中保存的元素按照某种严格弱序进行排列，队首元素总是值最大的（默认最大堆，修改为greater为最小堆 |

## 1.3 空间适配器allocator
### 1.3.0 空间适配器allocator
allocator模板类定义在头文件memory.h中，它帮助我们将内存分配和对象构造分开来。它提供一种类型感知的内存分配方法，它分配的内存是原始的、未构造的。利用allocate方法分配一段内存，当利用allocator对象分配了内存以后，要再用construct方法来再这块内存中构造指定类型的对象。当使用完这块内存中的对象后，可以利用destroy方法来销毁这个对象，这块内存又变为原始的未构造的内存，可以再次在这块内存中构造指定类型的对象。当使用完这块内存后，要先销毁其中保存的对象，再利用deallocate方法销毁这块内存。

### 1.3.1 allocator作用
- STL的分配器用于封装STL容器在内存管理上的底层细节。
- 在C++中，其内存配置和释放如下：
- new运算分两个阶段：
  - (1) 调用::operator new配置内存;
  - (2) 调用对象构造函数构造对象内容
- delete运算分两个阶段：
  - (1) 调用对象析构函数；
  - (2) 调用::operator delete释放内存

- 为了精密分工，STL allocator将两个阶段操作区分开来：
  - 内存配置有alloc::allocate()负责，内存释放由alloc::deallocate()负责；
  - 对象构造由::construct()负责，对象析构由::destroy()负责。

- 同时为了提升内存管理的效率，减少申请小内存造成的内存碎片问题，SGI STL采用了两级配置器，当分配的空间大小超过128B时，会使用第一级空间配置器；
当分配的空间大小小于128B时，将使用第二级空间配置器。
- 第一级空间配置器直接使用malloc()、realloc()、free()函数进行内存空间的分配和释放，而第二级空间配置器采用了内存池技术，通过空闲链表来管理内存。

### 1.3.2 分配器
一级分配器和二级分配器
一级分配器就是采用malloc分配内存，二级分配器采用内存池。
二级分配器设计的非常巧妙，分别给8k，16k,…, 128k等比较小的内存片都维持一个空闲链表，每个链表的头节点由一个数组来维护。需要分配内存时从合适大小的链表中取一块下来。假设需要分配一块10K的内存，那么就找到最小的大于等于10k的块，也就是16K，从16K的空闲链表里取出一个用于分配。释放该块内存时，将内存节点归还给链表。
如果要分配的内存大于128K则直接调用一级分配器
为了节省维持链表的开销，采用了一个union结构体，分配器使用union里的next指针来指向下一个节点，而用户则使用union的空指针来表示该节点的地址。

### 1.3.3 malloc/brk
`malloc` 是 C 语言标准库中的一个函数，用于动态分配内存。它的实现因操作系统和库的不同而有所差异，但通常遵循一些共同的原则和步骤。下面是一个简化的 `malloc` 实现的概述，以及一些常见的优化技术。

#### 1.3.3.1 基本原理

1. **请求内核分配内存**：当 `malloc` 被调用时，它首先检查是否有足够的空闲内存块可用。如果没有，它会请求操作系统分配更多的内存。
2. **内存管理**：`malloc` 需要管理已分配和未分配的内存块，以便有效地重用内存。
3. **返回指针**：如果成功分配了内存，`malloc` 返回一个指向分配内存的指针；如果失败，则返回 `NULL`。

#### 1.3.3.2 内存块管理

`malloc` 通常使用一种称为“内存池”或“堆”的数据结构来管理内存块。常见的内存管理策略包括：

1. **链表**：使用链表来记录空闲内存块。
2. **位图**：使用位图来标记哪些内存块是空闲的。
3. **分桶**：将不同大小的内存块分类存储，以便快速查找。

#### 1.3.3.3 常见优化技术

1. **合并空闲块**：当释放内存时，`free` 会尝试将相邻的空闲块合并成一个更大的空闲块，以减少内存碎片。
2. **快速路径**：对于小内存块，使用特殊的快速路径来加速分配和释放。
3. **多线程支持**：现代 `malloc` 实现通常支持多线程环境，使用锁或其他同步机制来保证线程安全。
4. **预分配大块内存**：预先从操作系统分配一大块内存，然后在该大块内存中进行细粒度的分配和释放，以减少系统调用的开销。

#### 1.3.3.4 简化版 `malloc` 实现

以下是一个简化的 `malloc` 实现，仅用于说明基本原理。实际的 `malloc` 实现会更加复杂，包含更多的优化和错误处理。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHUNK_SIZE (1024 * 1024)  // 初始分配的大块内存大小

typedef struct FreeBlock {
    size_t size;
    struct FreeBlock *next;
} FreeBlock;

static FreeBlock *free_list = NULL;

void *malloc(size_t size) {
    if (size == 0) return NULL;

    // 尝试从自由列表中找到合适的块
    FreeBlock *prev = NULL;
    FreeBlock *curr = free_list;
    while (curr != NULL && curr->size < size) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        // 找到了合适的块
        if (prev == NULL) {
            free_list = curr->next;
        } else {
            prev->next = curr->next;
        }
        return (void *)((char *)curr + sizeof(FreeBlock));
    }

    // 没有找到合适的块，请求新的内存
    if (free_list == NULL || free_list->size < size + sizeof(FreeBlock)) {
        size_t chunk_size = (size + sizeof(FreeBlock) > CHUNK_SIZE) ? size + sizeof(FreeBlock) : CHUNK_SIZE;
        char *new_chunk = (char *)sbrk(chunk_size);
        if (new_chunk == (char *)-1) {
            return NULL;  // 内存分配失败
        }

        FreeBlock *new_block = (FreeBlock *)new_chunk;
        new_block->size = chunk_size - sizeof(FreeBlock);
        new_block->next = free_list;
        free_list = new_block;
    }

    // 从新的块中分配内存
    FreeBlock *block = free_list;
    free_list = block->next;
    return (void *)((char *)block + sizeof(FreeBlock));
}

void free(void *ptr) {
    if (ptr == NULL) return;

    FreeBlock *block = (FreeBlock *)((char *)ptr - sizeof(FreeBlock));
    block->next = free_list;
    free_list = block;
}
```

#### 1.3.3.5 解释

1. **初始化**：`free_list` 是一个链表，用于记录空闲内存块。
2. **`malloc` 函数**：
   - 首先检查自由列表中是否有合适大小的空闲块。
   - 如果没有，使用 `sbrk` 系统调用从操作系统请求新的内存块。
   - 返回分配的内存块的指针。
3. **`free` 函数**：
   - 将释放的内存块重新插入到自由列表中，供后续的 `malloc` 调用使用。

#### 1.3.3.6 实际实现

实际的 `malloc` 实现（如 glibc 中的 `malloc`）会包含更多的优化和错误处理机制，例如：

- **多线程支持**：使用锁或其他同步机制。
- **内存对齐**：确保返回的指针对齐。
- **内存碎片管理**：通过合并相邻的空闲块来减少内存碎片。
- **快速路径**：为小内存块提供专门的管理策略。

这些优化使得 `malloc` 在实际应用中更加高效和可靠。
### 1.3.4 brk

`sbrk` 是一个 Unix 系统调用，用于动态调整进程的程序-break（program break），即数据段的结束地址。它通过内核来管理内存，而不是通过用户空间的内存管理机制。通过 `sbrk`，进程可以请求更多的内存或释放之前分配的内存。`sbrk` 主要用于实现动态内存分配器，如 `malloc` 和 `free`。
#### 1.3.4.1 基本概念

- **程序-break**：程序-break 是数据段的结束地址，也就是进程可以使用的最大虚拟地址。程序-break 之后的地址是不可访问的。
- **数据段**：数据段包括全局变量和静态变量的存储区域。动态分配的内存也通常位于数据段中。
#### 1.3.4.2 `sbrk` 的原型

```c
#include <unistd.h>

void *sbrk(intptr_t increment);
```

- **参数**：
  - `increment`：表示要调整的字节数。如果 `increment` 为正数，表示增加内存；如果为负数，表示减少内存。
- **返回值**：
  - 成功时，返回调整后的程序-break 地址。
  - 失败时，返回 `(void *)-1`。

#### 1.3.4.3 `sbrk` 的实现

1. **系统调用**：
   - 当用户程序调用 `sbrk` 时，它会触发一个系统调用。系统调用是一种从用户空间进入内核空间的机制，允许用户程序请求内核执行某些操作。
   - 在 x86 架构上，通常使用 `int 0x80` 指令（在 Linux 系统上）或 `syscall` 指令（在现代 x86-64 系统上）来触发系统调用。

2. **内核处理**：
   - 内核接收到系统调用后，会检查请求的合法性，包括权限检查和参数验证。
   - 内核会根据请求的增量 `increment` 调整程序-break。
     - 如果 `increment` 为正数，内核会尝试扩展数据段，分配更多的内存。
     - 如果 `increment` 为负数，内核会尝试缩减数据段，释放部分内存。

3. **内存管理**：
   - 内核会使用虚拟内存管理机制来处理内存分配和释放。虚拟内存管理包括页表管理和物理内存分配。
   - 如果需要更多内存，内核会从空闲的物理内存中分配页面，并将这些页面映射到进程的虚拟地址空间。
   - 如果需要释放内存，内核会解除这些页面的映射，并将它们标记为空闲，以便其他进程或系统使用。

#### 1.3.4.4 内存中断

- **内存中断**：内存中断通常是指硬件中断，例如页故障（page fault）。当进程访问一个未映射的虚拟地址时，会触发页故障中断。内核会处理这个中断，将相应的物理页面映射到虚拟地址空间。
- **`sbrk` 与内存中断**：`sbrk` 本身不会直接触发内存中断，但它会影响内存映射。当 `sbrk` 调整程序-break 时，内核可能会创建新的页表条目，将新的虚拟地址映射到物理内存。如果进程随后访问这些新映射的地址，可能会触发页故障中断，内核会处理这些中断并完成内存映射。

#### 1.3.4.5 sbrk具体实现步骤

1. **用户空间调用 `sbrk`**：
   ```c
   void *ptr = sbrk(increment);
   ```

2. **触发系统调用**：
   - 用户空间代码通过系统调用接口（如 `int 0x80` 或 `syscall`）进入内核空间。

3. **内核处理系统调用**：
   - 内核检查 `increment` 参数是否合法。
   - 内核根据 `increment` 调整程序-break：
     - 如果 `increment` 为正数，内核会分配新的物理页面，并将这些页面映射到进程的虚拟地址空间。
     - 如果 `increment` 为负数，内核会解除部分页面的映射，并将这些页面标记为空闲。

4. **返回结果**：
   - 内核将调整后的程序-break 地址返回给用户空间。
   - 如果操作成功，返回新的程序-break 地址。
   - 如果操作失败，返回 `(void *)-1` 并设置 `errno`。

#### 1.3.4.6 sbrk示例代码

以下是一个简化的示例，展示了 `sbrk` 的使用：

```c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    // 请求 1024 字节的内存
    void *ptr = sbrk(1024);
    if (ptr == (void *)-1) {
        perror("sbrk");
        return 1;
    }

    // 使用分配的内存
    char *data = (char *)ptr;
    strcpy(data, "Hello, World!");
    printf("%s\n", data);

    // 释放 1024 字节的内存
    void *new_ptr = sbrk(-1024);
    if (new_ptr == (void *)-1) {
        perror("sbrk");
        return 1;
    }

    return 0;
}
```


#### 1.3.4.7 sbrk注意事项

1. **内存对齐**：`sbrk` 返回的地址通常是按页对齐的，因此分配的内存可能会比请求的多。
2. **线程安全**：`sbrk` 不是线程安全的。在多线程环境中，应避免直接使用 `sbrk`，而是使用线程安全的内存分配函数，如 `malloc` 和 `free`。
3. **内存碎片**：频繁调用 `sbrk` 可能会导致内存碎片，影响内存管理的效率。
4. **限制**：`sbrk` 只能在数据段的末尾增加或减少内存，不能在任意位置分配内存。这使得它不适合复杂的内存管理需求。

#### 1.3.4.8 sbrk实际应用

在实际的内存分配器（如 glibc 中的 `malloc`）中，`sbrk` 通常与其他内存管理技术结合使用，以提供更高效的内存分配和释放。例如：

- **多级空闲列表**：使用多个空闲列表来管理不同大小的内存块。
- **内存池**：预先分配一大块内存，然后在该大块内存中进行细粒度的分配和释放。
- **内存对齐**：确保返回的指针对齐，以满足不同数据类型的要求。
- **内存碎片管理**：通过合并相邻的空闲块来减少内存碎片。

#### 1.3.4.9 sbrk总结

- **`sbrk` 是一个系统调用**，用于调整进程的程序-break。
- **内核处理**：内核负责管理内存分配和释放，包括虚拟内存管理和物理内存分配。
- **内存中断**：`sbrk` 本身不会直接触发内存中断，但它会影响内存映射，可能导致后续的页故障中断。

通过这些机制，`sbrk` 提供了一种简单但强大的方式来动态管理进程的内存。
通过这些技术，`malloc` 和 `free` 可以在大多数情况下提供高效和可靠的内存管理。
## 1.4 迭代器iterator
### 1.4.0 迭代器iterator
Iterator(迭代器)用于提供一种方法顺序访问一个聚合对象中各个元素, 而又不需暴露该对象的内部表示，相当于智能指针。
### 1.4.1 五种iterator category
```cpp
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag:public input_iterator_tag{};
struct bidirectional_iterator_tag:public forward_iterator_tag{};
struct random_access_iterator_tag:public bidirectional_iterator_tag{};
```
直接使用 高复用性 高性能 高移植性 数据和算法分离，利用迭代器进行沟通
### 1.4.2 iterator使用
1. STL容器中只有顺序容器和关联容器支持迭代器遍历，行为类似于指针，用于指向容器内的元素，并通过解引用*符号来获取元素。
2. 所有容器的迭代器都支持 == 和!=运算符；一般都支持++和--运算符（forward_list不支持--运算符）；除了无序关联容器以外，其它容器的迭代器均支持<, <=, >, >=运算符。
3. 一个迭代器范围由一对迭代器表示，第一个迭代器指向范围内第一个元素，第二个迭代器指向范围内最后一个元素的下一个位置，是一个左闭右开区间`[ begin, end)`。如果begin和end相等，则范围为空；如果begin和end不等，则范围至少包含一个元素，且begin指向第一个元素；begin递增若干次可以 == end。
4. 每种容器都有指向首元素的begin()和指向尾后位置的end()迭代器，类型类似于`vector<int>::iterator`；另外还有对应的const版本的迭代器cbegin()和cend()，类型类似于`vector<int>::const_iterator`。
5. 反向迭代器，仅能反向迭代的容器支持。rbegin()指向末尾的第一个元素，rend()指向首元素的前一个位置，crbegin()和crend()分别为对应的const版本。类型为reverse_iterator以及其const版本const_reverse_iterator。

### 1.4.3 容器支持的迭代器

|                容器名称                | 支持的迭代器类型 |
| ------------------------------------- | -------------- |
| vector                                | 随机访问迭代器   |
| deque                                 | 随机访问迭代器   |
| list                                  | 双向迭代器      |
| <font color="red">array</font>        | 随机访问迭代器   |
| <font color='red'>forword_list</font> | 前向迭代器      |
| stack                                 | 不支持          |
| queue                                 | 不支持          |
| priority_queue                        | 不支持          |
| set                                   | 双向迭代器      |
| multiset                              | 双向迭代器      |
| map                                   | 双向迭代器      |
| multimap                              | 双向迭代器      |

### 1.4.4 容器和适配器对应的插入删除方法

#### 1.4.4.1 序列容器

| 容器            | 插入方法                         | 删除方法                   |
| ------------- | ---------------------------- | ---------------------- |
| `std::vector` |                              |                        |
|               | - `push_back(val)`           | - `pop_back()`         |
|               | - `insert(pos, val)`         | - `erase(pos)`         |
|               | - `insert(pos, n, val)`      | - `erase(first, last)` |
|               | - `insert(pos, first, last)` | - `clear()`            |
| `std::deque`  |                              |                        |
|               | - `push_front(val)`          | - `pop_front()`        |
|               | - `push_back(val)`           | - `pop_back()`         |
|               | - `insert(pos, val)`         | - `erase(pos)`         |
|               | - `insert(pos, n, val)`      | - `erase(first, last)` |
|               | - `insert(pos, first, last)` | - `clear()`            |
| `std::list`   |                              |                        |
|               | - `push_front(val)`          | - `pop_front()`        |
|               | - `push_back(val)`           | - `pop_back()`         |
|               | - `insert(pos, val)`         | - `erase(pos)`         |
|               | - `insert(pos, n, val)`      | - `erase(first, last)` |
|               | - `insert(pos, first, last)` | - `clear()`            |

#### 1.4.4.2 关联容器

| 容器              | 插入方法                    | 删除方法           |
| --------------- | ----------------------- | -------------- |
| `std::set`      |                         |                |
|                 | - `insert(val)`         | - `erase(pos)` |
|                 | - `insert(first, last)` | - `erase(key)` |
|                 | -                       | - `clear()`    |
| `std::map`      |                         |                |
|                 | - `insert(val)`         | - `erase(pos)` |
|                 | - `insert(first, last)` | - `erase(key)` |
|                 | -                       | - `clear()`    |
| `std::multiset` |                         |                |
|                 | - `insert(val)`         | - `erase(pos)` |
|                 | - `insert(first, last)` | - `erase(key)` |
|                 | -                       | - `clear()`    |
| `std::multimap` |                         |                |
|                 | - `insert(val)`         | - `erase(pos)` |
|                 | - `insert(first, last)` | - `erase(key)` |
|                 | -                       | - `clear()`    |

#### 1.4.4.3 适配器

| 适配器                   | 插入方法          | 删除方法      | 访问方法                          |
| --------------------- | ------------- | --------- | ----------------------------- |
| `std::stack`          | - `push(val)` | - `pop()` | - **front()**<br>- **back()** |
| `std::queue`          | - `push(val)` | - `pop()` | `- top()`                     |
| `std::priority_queue` | - `push(val)` | - `pop()` | `- top()`                     |

- **序列容器**：包括`std::vector`、`std::deque`和`std::list`。这些容器提供了多种插入和删除方法，可以根据需要选择适当的方法。
  - `push_back(val)`：向容器尾部添加元素。
  - `insert(pos, val)`：在指定位置插入元素。
  - `insert(pos, n, val)`：在指定位置插入`n`个值为`val`的元素。
  - `insert(pos, first, last)`：在指定位置插入一个范围内的元素。
  - `erase(pos)`：删除指定位置的元素。
  - `erase(first, last)`：删除一个范围内的元素。
  - `clear()`：清空整个容器。

- **关联容器**：包括`std::set`、`std::map`、`std::multiset`和`std::multimap`。这些容器主要用于键值对的存储和检索。
  - `insert(val)`：插入元素（对于`std::map`和`std::multimap`，插入键值对）。
  - `insert(first, last)`：插入一个范围内的元素。
  - `erase(pos)`：删除指定位置的元素。
  - `erase(key)`：删除具有指定键的元素。
  - `clear()`：清空整个容器。

- **适配器**：包括`std::stack`、`std::queue`和`std::priority_queue`。这些适配器基于其他容器（如`std::deque`或`std::vector`）实现特定的数据结构。
  - `push(val)`：添加元素。
  - `pop()`：删除元素。

## 1.5 vector
### 1.5.0 vector
单端开口 Array静态空间 vector动态 动态空间大小是重新开辟空间并将原先数据拷贝至新内存，所以原有迭代器失效
### 1.5.1 vector接口
```cpp
v.capacity()//容器容量 扩展不是成倍扩展
vector<T> v
vector<int> v(10,100)//10个100有参构造
vector<int> v(v1.begin(),v1.end());//end指向最后的下一位 左开右闭
v1.swap(v)//元素交换
v.resize(n)//重新指定容器长度 长增长默认0填充 短删除超出元素
v.resize(n,10)//第二个参数默认填充值
at []同string
v.front() v.back()//第一个和最后一个元素
v.insert(itreator,x)//插入 第一个迭代器 x为值
v.insert(itreator,n,x)//插入 第一个迭代器 n个数
v.pop_back()//尾删
v.erase(v.begin())   v.erase(v.begin(),v.end()) //删除
v.clear();v.erase(v.begin(),v.end())//清空
vector<int>(v).swap(v);//利用swap收缩空间 利用拷贝构造初始匿名对象并交换 匿名对象自动释放 v指向新的收缩后内存
v.reserve(10000)//预留空间 减少因空间不足动态增加产生的操作消耗
vector<int>::reverse_iterator it = v.rbegin();//逆序迭代器
vector<int>::iterator it = v.begin(); it = it + i;//支持随机访问
```
### 1.5.2 vector底层存储
vector就是一个动态数组，里面有一个指针指向一片连续的内存空间，当空间不够装下数据时，会自动申请另一片更大的空间（一般是增加当前容量的50%或100%），然后把原来的数据拷贝过去，接着释放原来的那片空间；当释放或者删除里面的数据时，其存储空间不释放，仅仅是清空了里面的数据。

当 std::vector 需要扩容但未能成功申请到足够的内存时，它会抛出一个 std::bad_alloc 异常。这是因为 std::vector 使用连续的内存块来存储其元素，以保证随机访问的性能。当向 std::vector 添加元素，而现有的内存空间不足以容纳新元素时，std::vector 将尝试重新分配一块更大的内存区域。

std::vector 的扩容策略通常是在当前容量的基础上增加一个固定的比例（如两倍），以减少频繁的内存重新分配。但是，如果在尝试重新分配内存时，操作系统或运行环境无法提供所需的内存资源，std::vector 的构造函数、插入函数（如 push_back 或 resize）或任何可能触发内部重新分配的操作都会失败，并抛出 std::bad_alloc 异常。
### 1.5.3 自增长机制
当已经分配的空间不够装下数据时，分配双倍于当前容量的存储区，把当前的值拷贝到新分配的内存中，并释放原来的内存。
### 1.5.4 begin和end指向最后一个的后面位置
begin返回的是第一个元素的迭代器，end返回的是最后一个元素后面位置的迭代器。
### 1.5.5 插入时迭代器失效？
vector动态增加大小时，并不是在原空间后增加新的空间，而是以原大小的两倍在另外配置一片较大的新空间，然后将内容拷贝过来，并释放原来的空间。由于操作改变了空间，所以迭代器失效。

- vector每次insert或erase之后，以前保存的iterator会不会失效？
- 理论上会失效，理论上每次insert或者erase之后，所有的迭代器就重新计算的，所以都可以看作会失效，原则上是不能使用过期的内存
- 但是vector一般底层是用数组实现的，我们仔细考虑数组的特性，不难得出另一个结论，
- insert时，假设insert位置在p，分两种情况：
  * a) 容器还有空余空间，不重新分配内存，那么p之前的迭代器都有效，p之后的迭代器都失效
  * b) 容器重新分配了内存，那么p之后的迭代器都无效
- erase时，假设erase位置在p，则p之前的迭代器都有效并且p指向下一个元素位置（如果之前p在尾巴上，则p指向无效尾end），p之后的迭代器都无效

### 1.5.6 vector中erase方法与algorithm中的remove方法区别
- vector中erase方法真正删除了元素，迭代器不能访问了
- remove只是简单地将元素移到了容器的最后面，迭代器还是可以访问到。因为algorithm通过迭代器进行操作，不知道容器的内部结构，所以无法进行真正的删除。
删除 vector 中所有值等于 a 的元素可以通过组合使用 std::remove 和 std::vector::erase 来实现。std::remove 不实际删除元素，而是将不需要删除的元素移到 vector 的前部，并返回一个迭代器，指向新的“结束”位置。然后，你可以使用 std::vector::erase 来删除这之后的所有元素。
```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
    int a = 2;

    v.erase(std::remove(v.begin(), v.end(), a), v.end());

    return 0;
}
```
### 1.5.7 vector的push_back时间复杂度
 - vector中两个迭代器start/finish指向已使用的范围，
- 迭代器end_of_storage指向整块连续空间((含备用空间)的尾端
- 检查是否还有备用空间，（判断  finish是否与 end_of_storage 相等.）如果有就直接在备用空间上构造元素，并调整迭代器 finish，使 vector变大。如果没有备用空间了，就扩充空间，重新配置、移动数据，释放原空间。​
- 当执行 push_back 操作，该 vector 需要分配更多空间时，它的容量(capacity)会增大到原来的 m 倍
- n个元素，m倍增因子
  * 假定有 n 个元素,倍增因子为 m。那么完成这 n 个元素往一个 vector 中的push_back​操作，需要重新分配内存的次数大约为 logm(n)，第 i 次重新分配将会导致复制 m^i (也就是当前的vector.size() 大小)个旧空间中元素，因此 n 次 push_back操作所花费的总时间约为 n*m/(m - 1):
  * n个元素，n次操作 n*m/(m - 1)/n 变成 m/(m-1)一个常量
  * vector ,m== 2,n个元素总时间 2*n/(2-1);
- 算法导论方法
  * 假设现在 capacity() == size() == N ，那么
  * 后 1/2 N 个元素拷贝了1次，是 push_back() 直接拷贝的。
  * 前 1/2 N 个元素在上次扩容的时候多拷贝了 1 次，
  * 前 1/4 N 个元素在上上次扩容的时候又多拷贝了 1 次，以此类推。
  * 所以平均每个元素拷贝了 1 + 1/2 + 1/4 + ... = 2 次，这是下限。
   * 如果这时再 push_back()，又会扩容 size = N+1 = capacity/2 + 1，这次扩容会拷贝 N 个元素，那么平均每个元素拷贝了 2+1 = 3 次，这是上限。
它被复制的次数可以被表示为一个等比数列 1 + 1/2 + 1/4 + ... ，这个等比数列的和为 2，所以平均每个元素被复制了 2 次。
然后，如果我们再执行一次 push_back 操作，这将导致 std::vector 扩容，所有的 N 个元素都需要被复制到新的内存位置。这就相当于每个元素又被复制了一次，所以平均每个元素被复制的次数变为 3 次。

这个分析是基于 std::vector 的内存扩容策略，即每次扩容都将容量增大一倍。在这种策略下，元素的复制次数是有上下限的，下限是 2 次，上限是 3 次，这就是我们说 push_back 的摊销时间复杂度为 O(1) 的原因。

 在一系列连续的 push_back 操作中，只有在每次容量不足，需要扩展时，才会进行内存的重新分配。如果采用的是倍增的策略，即每次扩展到原来容量的 m 倍，那么对于插入 n 个元素，需要进行的内存重新分配次数是 logm(n)。
每次重新分配时，都需要将旧的元素复制到新的内存位置，如果当前 vector 的大小为 m^i，那么这一步操作需要复制 m^i 个元素，时间复杂度为 O(m^i)。
如果将所有重新分配的操作加总，可以得到总的时间复杂度约为 m/(m-1)*n，因此每次 push_back 的平均时间复杂度是 m/(m-1)，这是一个和 m 有关的常数，所以我们通常说 push_back 的摊销时间复杂度为 O(1)。
对于 std::vector，在很多实现中，m 的值为 2，所以插入 n 个元素的总时间复杂度约为 2n/(2-1) = 2n，即每次 push_back 的平均时间复杂度为 2，这仍然被看作是 O(1) 的摊销时间复杂度。
以上是对摊销时间复杂度的一个理论性分析，但具体的行为可能会因编译器和标准库的实现而有所不同。在实际编程中，我们通常会根据预期的元素数量来预先设置 std::vector 的容量（通过 reserve 方法），以避免频繁的内存重新分配  。


### 1.5.8 删除vector中某元素
在 C++ 中，使用 for 循环和 std::vector::erase 删除元素时需要小心，因为 erase 会改变容器的大小并可能使迭代器失效。
如果你在循环中删除元素，需要确保不会访问已删除的元素，同时还要更新迭代器以避免出现未定义的行为。以下是一个示例：

```cpp
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
    int a = 2;

    for (auto it = v.begin(); it != v.end(); ) {
        if (*it == a) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }

    return 0;
}
```
在这个例子中，我们在删除元素后立即更新迭代器 it。这是因为 std::vector::erase 返回的是下一个有效元素的迭代器，所以我们可以安全地进行这样的操作。在不满足 if 条件（即元素不等于 a）的情况下，我们需要手动递增迭代器。
请注意，这种方法比使用 std::remove 和 std::vector::erase 效率更低，因为每次删除元素时都可能需要移动后面的所有元素。如果可能，应尽量避免在循环中删除元素。

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
    int a = 2;

    v.erase(std::remove(v.begin(), v.end(), a), v.end());

    return 0;
}
```
### 1.5.9 push_back 和 emplace_back
`push_back` 和 `emplace_back` 是C++标准库中用于向容器中添加元素的函数，它们的区别主要体现在两个方面：语义和效率。

1.语义：
push_back：接受一个已存在的对象作为参数，并将其拷贝（或移动）到容器中。这意味着元素是通过复制或移动构造函数创建的。
emplace_back：接受构造函数的参数，直接在容器内部构造新的对象。也就是说，元素是在容器内直接构造而不需要拷贝或移动构造。
2.效率：
push_back：由于需要进行对象的拷贝（或移动），可能会涉及到额外的内存分配和复制操作，相对而言效率稍低。
emplace_back：由于直接在容器内部构造对象，避免了拷贝（或移动）的开销，通常比 push_back 更高效。

选择使用哪个函数取决于具体的需求：
如果你已经有了一个已存在的对象，想将其添加到容器中，那么可以使用 push_back。
如果你想在容器中直接构造一个新的对象，并且不需要额外的拷贝或移动操作，那么应该使用 emplace_back。
总之，如果你有已存在的对象，使用 push_back；如果你只有构造函数的参数，直接在容器内构造新对象，使用 emplace_back。这样可以更好地利用语义和效率来达到更优的性能。
### 1.5.10 为什么不都直接用emplace_back, 它不能解决什么问题么？
虽然 `emplace_back` 在某些情况下能够提供更高效的性能，但并不是所有情况下都适合使用它。以下是一些情况下不适合使用 `emplace_back` 的原因：
1.不支持直接构造：
容器中存储的元素类型没有对应的构造函数，或者构造函数不可用。
元素类型是抽象类，无法直接创建对象。
2.无法省略参数：
构造函数需要传递多个参数，而这些参数是必需的，没有默认值可用。
参数类型较为复杂，不方便手动指定每个参数的值。
3.复用已有对象：
需要使用已存在的对象，并在容器中创建该对象的副本。
已有对象需要在容器中保留一份独立的拷贝。
4.容器内存管理：
需要在元素添加到容器时进行特定的内存管理操作，如自定义内存分配器。

在以上情况下，push_back 更适合使用，它可以灵活地接受已存在的对象，并将其添加到容器中。此外，如果代码已经大量使用了 push_back，改用 emplace_back 可能带来的性能收益可能不那么显著，因为 emplace_back 并不会对现有代码产生影响。

因此，选择使用 emplace_back 还是 push_back 取决于具体的需求和设计考虑。在大多数情况下，首先考虑使用 emplace_back，只有在上述情况下才需要考虑使用 push_back。
当元素类型为普通指针或没有默认构造函数的类时，`emplace_back` 将无法使用，只能使用 `push_back`。以下是这两种情况的示例：

1.元素类型为普通指针：
```cpp
#include <vector>

int main() {
    std::vector<int*> myVector;

    int* ptr = new int(10);

    // 无法使用 emplace_back 添加指针对象
    // myVector.emplace_back(ptr);  // 编译错误

    // 只能使用 push_back 添加指针对象
    myVector.push_back(ptr);

    return 0;
}
```
2.元素类型没有默认构造函数：
```cpp
#include <vector>
#include <string>

class MyClass {
public:
    MyClass(int value) : data(value) {}
private:
    int data;
};

int main() {
    std::vector<MyClass> myVector;

    // 无法使用 emplace_back 直接构造对象
    // myVector.emplace_back(10);  // 编译错误

    // 只能使用 push_back 拷贝构造对象
    myVector.push_back(MyClass(10));

    return 0;
}
```
在上述示例中，如果尝试使用 emplace_back 添加元素，编译器会报错。因为指针类型无法直接构造，而类 MyClass 没有默认构造函数，只能通过拷贝构造函数添加到容器中。
### 1.5.11 vector的resize和reverse的区别？

`std::vector` 的 `resize` 和 `reserve` 是两个常用的成员函数，但它们的功能和行为有显著区别。以下是它们的详细对比：

---

### **1.5.11 `vector::resize`**

#### **1.5.11.1 resize功能**

- 改变 `vector` 的 **大小（size）**，即实际存储的元素数量。
- 如果新的大小大于当前大小，会添加新元素（默认初始化或指定值初始化）。
- 如果新的大小小于当前大小，会删除多余的元素。


```cpp
void resize(size_type n);
void resize(size_type n, const value_type& val);
```

#### **1.5.11.2 resize示例**


```cpp
std::vector<int> vec = {1, 2, 3};
vec.resize(5);       // 大小变为 5，新增元素默认初始化为 0
vec.resize(2);       // 大小变为 2，删除多余的元素
```

#### **1.5.11.3 resize特点**

- 影响 `size()` 的返回值。
- 可能触发内存重新分配（如果新大小超过 `capacity()`）。

---

### **1.5.12 `vector::reserve`**

#### **1.5.12.1 reverse功能**

- 改变 `vector` 的 **容量（capacity）**，即预分配的内存空间。
- 不会改变 `vector` 的大小，也不会添加或删除元素。
- 主要用于避免频繁的内存重新分配。

#### **1.5.12.2 reverse语法**

```cpp
void reserve(size_type n);
```

#### **1.5.12.3 reverse示例**

```cpp
std::vector<int> vec;
vec.reserve(100);     // 预分配 100 个元素的内存空间
vec.push_back(1);     // 添加元素，不会触发内存重新分配
```

#### **1.5.12.4 reverse特点**

- 不影响 `size()` 的返回值。
- 如果 `n` 大于当前 `capacity()`，会触发内存重新分配。

---

### **1.5.13 reverse/resize 对比总结 使用建议**

| 特性         |  `resize`    |  `reserve`              |     |
| ---------- | ------------ | ----------------------- | --- |
|  **功能**    | 改变 `size()`  | 改变 `capacity()`         |     |
|  **影响元素**  | 可能添加或删除元素    | 不添加或删除元素                |     |
|  **内存分配**  | 可能触发内存重新分配   | 仅在 `n > capacity()` 时触发 |     |
|  **适用场景**  | 需要改变元素数量时    | 预分配内存以避免频繁重新分配          |     |
- 使用 `resize` 当需要改变 `vector` 的实际元素数量时。
- 使用 `reserve` 当需要预分配内存以避免频繁重新分配时（例如，已知 `vector` 最终大小的情况下）。

通过合理使用 `resize` 和 `reserve`，可以优化 `std::vector` 的性能和内存使用。

## 1.6 list
### 1.6.0 list
list对于vector对空间运用更精准 动态存储分配一次开辟一个 不会造成浪费和溢出
插入删除方便只需要修改指针 是一个循环的双向链表
链表灵活 但时间空间浪费较大（指针）
插入删除不会造成迭代器失效（vector内存重新分配会失效）
不支持随机访问
### 1.6.1 list使用接口
```cpp
    list<T> l;
    l.push_back(i);
    l.push_front(i);
    reverse_iterator it = l.begin();
    l.insert(l.begin(),i);
    l.remove(elem);//删除所有与elem匹配的元素
    l.reverse();//反转 逆序遍历是非质变的 反转质变
    l.sort();// 所有系统提供的标准算法 使用的容器提供的迭代器必须支持随机访问 (这个是list容器自带的sort)
    l.sort(myfunc());//myfunc()提供一个回调函数 对于自定义的类型 必须指定排序规则
```
### 1.6.2 list存储
以结点为单位存放数据，结点的地址在内存中不一定连续，每次插入或删除一个元素，就配置或释放一个元素空间

节点 ，刻意在环状list尾端加一空白节点，用以符合STL前闭后开区间；

### 1.6.3 list自带排序
将前两个元素合并，再将后两个元素合并，然后合并这两个子序列成4个元素的子序列，重复这一过程，得到8个，16个，...，子序列，最后得到的就是排序后的序列。

```cpp
void List::sort()
{
    List carry;
    List counter[64]; //数组元素为链表
    int fill = 0;
    while (head->next != tail)
    {
        carry.transfer(carry.getHead()->next, head->next, head->next->next);
        //head是哨兵，不存放有效值
        //head->next元素被移走，所以while循环不需要head=head->next;
        int i = 0;
        while (i < fill &&
        counter[i].getHead()->next != counter[i].getHead())
        //counter[i]不是空
        {
            counter[i].merge(carry);
            carry.swap(counter[i++]);
        }
        carry.swap(counter[i]);
        if (i == fill)
            ++fill;
    }
    for (int i = 1; i < fill; i++)
        counter[i].merge(counter[i - 1]);
        //通过这个实现排序（将有序的链表合成一个新的有序链表）
    swap(counter[fill - 1]);
}
```
### 1.6.4 vector和list的区别
vector和数组类似，拥有连续的内存空间，支持随机的存取，在中间进行元素的插入和删除的操作时间复杂度是O(n)
list是由双向链表实现的，只能通过数组指针来进行数据访问，遍历中间的元素，时间的复杂度是O(n).
### 1.6.5 vector插入删除和list有什么区别？
vector插入和删除数据，需要对现有数据进行复制移动，如果vector存储的对象很大或者构造函数很复杂，则开销较大，如果是简单的小数据，效率优于list。
list插入和删除数据，需要对现有数据进行遍历，但在首部插入数据，效率很高。

## 1.7 STL的vector和list的区别，应用
### 1.7.1 Vector
- 连续存储的容器，动态数组，在堆上分配空间
- 底层实现：数组
- 两倍容量增长：
  * vector 增加（插入）新元素时，如果未超过当时的容量，则还有剩余空间，那么直接添加到最后（插入指定位置），然后调整迭代器。
  * 如果没有剩余空间了，则会重新配置原有元素个数的两倍空间，然后将原空间元素通过复制的方式初始化新空间，再向新空间增加元素，最后析构并释放原空间，之前的迭代器会失效。
- 性能：
  * 访问：O(1)
  * 插入：
    - 在最后插入（空间够）：很快
    - 在最后插入（空间不够）：需要内存申请和释放，以及对之前数据进行拷贝。
    - 在中间插入（空间够）：内存拷贝
    - 在中间插入（空间不够）：需要内存申请和释放，以及对之前数据进行拷贝。
  * 删除：在最后删除：很快
    * 在中间删除：内存拷贝
  * 适用场景：经常随机访问，且不经常对非尾节点进行插入删除。
### 1.7.2 List
- 动态链表，在堆上分配空间，每插入一个元素都会分配空间，每删除一个元素都会释放空间。
- 底层：双向链表
- 性能：
    - 访问：随机访问性能很差，只能快速访问头尾节点。
    - 插入：很快，一般是常数开销
    - 删除：很快，一般是常数开销
- 适用场景：经常插入删除大量数据
### 1.7.3 vector/list区别
1）vector底层实现是数组；list是双向 链表。
2）vector支持随机访问，list不支持。
3）vector是顺序内存，list不是。
4）vector在中间节点进行插入删除会导致内存拷贝，list不会。
5）vector一次性分配好内存，不够时才进行2倍扩容；list每次插入新节点都会进行内存申请。
6）vector随机访问性能好，插入删除性能差；list随机访问性能差，插入删除性能好。
### 1.7.4 vector/list应用
- vector拥有一段连续的内存空间，因此支持随机访问，如果需要高效的随即访问，而不在乎插入和删除的效率，使用vector。
- list拥有一段不连续的内存空间，如果需要高效的插入和删除，而不关心随机访问，则应使用list。

|           vector           |         list          |
| -------------------------- | --------------------- |
| 动态数组                    | 动态链表               |
| 两倍容量增长                | 每次插入删除分配释放空间 |
| 访问快O(1)                  | 随机访问慢，只能头尾节点 |
| 插入 不足时空间申请和释放     | 插入高效很快            |
| 删除 最后快，中间需要内存拷贝 | 删除高效很快            |
| 适合随机访问不经常插入删除   | 适合经常插入删除        |

## 1.8 deque 分段连续空间
### 1.8.1 deque双端队列
双端开口 可以头尾两端进行插入删除操作
没有容量概念 动态的以连续分段空间组合而成 中控器Key 缓冲区Val
```cpp
deque<T> d;
d.push_back(i)//尾插
d.push_front(i)//头插
d.pop_back()//删除最后一个数据
d.pop_front()//删除第一个数据
```
deque动态地以分段连续空间组合而成，随时可以增加一段新的连续空间并链接起来。不提供空间保留功能。
注意：除非必要，我们尽可能选择使用vector而非deque，因为deque的迭代器比vector迭代器复杂很多。对deque排序，为了提高效率，可先将deque复制到一个vector上排序，然后再复制回deque。
deque采用一块map（不是STL的map容器）作为主控，其为一小块连续空间，其中每个元素都是指针，指向另一段较大的连续空间（缓冲区）。

### 1.8.2 deque的迭代器包含4个内容
1）cur：迭代器当前所指元素
2）first：此迭代器所指的缓冲区的头。
3）last：缓冲区尾。
4）node：指向管控中心。


## 1.10 set容器和multiset容器
### 1.10.0 .红黑树有什么性质？时间复杂度？
1）每个结点是红色或者黑色。
2）根结点为黑色。
3）叶结点为黑色的NULL结点。
4）如果结点为红，其子节点必须为黑。
5）任一结点到NULL的任何路径，所含黑结点数必须相同。

红黑树是一种平衡二叉查找树，
红黑树的高度近似 log2n，所以它是近似平衡，插入、删除、查找操作的时间复杂度都是 O(logn)。
二分法的时间复杂度
N/2 N/4 ... 设置x次找到，N*(1/2)^x = 1，x=log2N
log2n
### 1.10.1 set接口
关联式容器 会根据元素的键值自动排序
set的元素既是键值又是实值 所以不能通过set的迭代器（const_iterator）随意修改set元素值 因为有默认排序规则
 set不允许有两个元素有相同键值
set和list某些相同 插入删除后 之前的迭代器依然有效
multiset容器 和set用法相同 底层都是红黑树 但允许键值重复
```cpp
set<T> s;
s.insert(i);//插入数据 内部自动排好序 唯一插入方式
pair<iterator, bool> insert(int val); insert的返回值；迭代器+插入成功
s.erase(elem);//删除elem的元素，返回0或者1；
set.erase(std::prev(set.end())) // 删除最大元素
b.erase(b.find(2), b.find(4)) // 删除[2,4)之间的元素,如果不存在2则会出错，end()~find(4)
b.erase(b.lower_bound(2), b.upper_bound(4)); // 删除[2,4]之间的元素
s.find(elem);//存在返回对应元素的迭代器（*pos可以取找到的值） 不存在返回end()迭代器
s.count(elem);//找elem个数 对于set要么1 要么0
set<int>::iterator res = s.lower_bound(elem);//返回第一个key>=elem元素的迭代器
set<int>::iterator res = s.upper_bound(elem);//返回第一个key>elem元素的迭代器
pair<set<int>::iterator,set<int>::iterator> res = s.equal_range(elem);//返回容器中key与elem相等的上下限的两个迭代器(对组)
res.first//lower_bound迭代器
res.second//upper_bound迭代器
pair<set<int>::iterator,bool> res = s.insert(i);//res.second为bool体现是否插入成功
b_it = std::next(a_it,3) 修改迭代器后返回，返回向后的三个迭代器，a_it不变,不会改变原迭代器
`d::next(it, -3)` 相当于 `it - 3`。还可以用另一个专门的函数 `std::prev(it, 3)`
std::advance(a_it,3) a_it向后移动三个迭代器，没有返回值
`std::distance(it1, it2)` 相当于 `it2 - it1`，注意顺序和 `-`相反
```
利用仿函数(普通回调函数只是指针 不能作为类型套入模板函数)指定排序规则//对自定义数据类型使用set时同样在插入之前指定排序规则
```cpp
set<int,MyCompare> s;
实现MyCompare类
class MyComapre
{
public:
    bool operator()(const int a,const int b)
    {
    	return a>b;
    }
}
```
迭代器修改为 `set<int,MyCompare>::iterator it = begin();`
### 1.10.2 upper_bound/lower_bound
在C++中，`lower_bound` 和 `upper_bound` 是 `<algorithm>` 头文件中定义的函数模板，通常用于有序范围内的二分查找。它们在标准库容器（如 `vector`、`list` 或 `array`）以及关联容器（如 `set` 和 `map`）上非常有用。这两个函数主要用于处理已排序的数据。

#### 1.10.2.1 `lower_bound`不小于(大于等于)

- **功能**：`lower_bound` 函数返回一个迭代器，指向第一个不小于给定值的元素位置。
- **原型**：
  ```cpp
  forward_iterator lower_bound (forward_iterator first, forward_iterator last, const val& value);
  ```
  对于关联容器，如 `set` 或 `map`，可以使用带比较器的版本：
  ```cpp
  forward_iterator lower_bound (forward_iterator first, forward_iterator last, const val& value, Compare comp);
  ```
- **用法示例**：
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>

  int main() {
      std::vector<int> vec = {1, 2, 3, 4, 4, 4, 5, 6};
      auto it = std::lower_bound(vec.begin(), vec.end(), 4);
      if (it != vec.end()) {
          std::cout << "First element not less than 4 is: " << *it << std::endl;
      } else {
          std::cout << "No element found" << std::endl;
      }
      return 0;
  }
  ```

#### 1.10.2.2 `upper_bound`大于

- **功能**：`upper_bound` 函数返回一个迭代器，指向第一个大于给定值的元素位置。
- **原型**：
  ```cpp
  forward_iterator upper_bound (forward_iterator first, forward_iterator last, const val& value);
  ```
  同样，对于关联容器，可以使用带比较器的版本：
  ```cpp
  forward_iterator upper_bound (forward_iterator first, forward_iterator last, const val& value, Compare comp);
  ```
- **用法示例**：
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>

  int main() {
      std::vector<int> vec = {1, 2, 3, 4, 4, 4, 5, 6};
      auto it = std::upper_bound(vec.begin(), vec.end(), 4);
      if (it != vec.end()) {
          std::cout << "First element greater than 4 is: " << *it << std::endl;
      } else {
          std::cout << "No element found" << std::endl;
      }
      return 0;
  }
  ```

#### 1.10.2.3 区别

- `lower_bound` 返回的是第一个不小于目标值的位置。
- `upper_bound` 返回的是第一个大于目标值的位置。
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 6, 7};// 查找第一个不小于3的元素的位置
    auto lb = std::lower_bound(vec.begin(), vec.end(), 3);
    if (lb != vec.end()) {
        std::cout << "First element not less than 3 is: " << *lb << std::endl;
    } else {
        std::cout << "All elements are less than 3." << std::endl;
    }
    
    // 查找第一个大于4的元素的位置
    auto ub = std::upper_bound(vec.begin(), vec.end(), 4);
    if (ub != vec.end()) {
        std::cout << "First element greater than 4 is: " << *ub << std::endl;
    } else {
        std::cout << "All elements are less than or equal to 4." << std::endl;
    }

    return 0;
}
```
- `lower_bound` 找到了第一个不小于 3 的元素，即 4。
- `upper_bound` 找到了第一个大于 4 的元素，即 6。
#### 1.10.2.4 使用场景

这些函数特别适用于需要快速定位元素或范围的情况，尤其是在数据量较大且已经排序的情况下。例如，在实现区间查询、数据统计或者需要高效插入新元素到正确位置的算法中，`lower_bound` 和 `upper_bound` 都是非常有用的工具。

#### 1.10.2.5 查找小于某个值的最大元素
在 C++ 标准库中，`lower_bound` 和 `upper_bound` 主要用于查找不小于和大于某个值的元素。如果你需要查找小于某个值的最大元素，可以结合使用这些函数来实现。

具体来说，你可以使用 `std::upper_bound` 来找到第一个大于目标值的元素位置，然后减去一个迭代器步长，得到小于目标值的最大元素的位置。

下面是一个示例代码，展示了如何查找小于某个值的最大元素：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 6, 7};

    // 要查找小于的目标值
    int target = 5;

    // 使用 upper_bound 找到第一个大于目标值的元素的位置
    auto ub = std::upper_bound(vec.begin(), vec.end(), target);

    if (ub != vec.begin()) {
        // 减去一个迭代器步长，得到小于目标值的最大元素的位置
        --ub;
        std::cout << "The largest element less than " << target << " is: " << *ub << std::endl;
    } else {
        std::cout << "There are no elements less than " << target << "." << std::endl;
    }

    return 0;
}
```
在这个例子中：
- 我们使用 `std::upper_bound` 找到第一个大于 5 的元素的位置。
- 然后通过 `--ub` 得到小于 5 的最大元素的位置，即 4。

这样就可以实现查找小于某个值的最大元素的功能。

## 1.11 map/multimap容器
### 1.11.0 map/multimap容器
同时拥有键值和实值 可以有两个相同实值不可以相同的键值 multimap可以重复
其他同set 底层红黑树、

1.元素的唯一性：std::map 中的键是唯一的，每个键只能对应一个值。而 std::multimap 中的键可以对应多个值，允许重复的键。
2.插入顺序：std::map 会根据键的比较自动进行排序，以保证键的有序性。而 std::multimap 不会自动排序，插入的顺序就是元素的顺序。
3.检索和删除：在 std::map 中，通过键可以快速进行查找和删除操作，因为键是唯一的。而在 std::multimap 中，由于键可以重复，查找和删除操作需要额外处理重复键的情况。
```cpp
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    std::map<int, std::string> myMap;

    // 插入键值对到 map
    myMap.insert({2, "apple"});
    myMap.insert({1, "banana"});
    myMap.insert({3, "orange"});
    myMap.insert({2, "grape"});  // 重复的键

    std::cout << "std::map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::multimap<int, std::string> myMultiMap;

    // 插入键值对到 multimap
    myMultiMap.insert({2, "apple"});
    myMultiMap.insert({1, "banana"});
    myMultiMap.insert({3, "orange"});
    myMultiMap.insert({2, "grape"});  // 重复的键

    std::cout << "\nstd::multimap:" << std::endl;
    for (const auto& pair : myMultiMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

```
### 1.11.1 map接口
```cpp
map<int ,int> m;
//插入
m.insert(pair<int,int>(1,10));
m.insert(make_pair(2,20));
m.insert(map<int,int>::value_type(3,30));
m[4] = 40;
//读取
map<int ,int>::iterator it = m.begin();
it->first 或者(*it).first

m.erase(key)//按照key删除
map<int ,int>::iterator pos = m.find(key)//返回迭代器 pos != end() 则查到

map<int，int>::iterator res = m.lower_bound(key);//返回第一个容器中key>=key元素的迭代器
map<int，int>::iterator res = m.upper_bound(key);//返回第一个容器中key>key元素的迭代器
pair<map<int，int>::iterator,map<int，int>::iterator> res = m.equal_range(key);//返回容器中key与key相等的上下限的两个迭代器(对组)
res.first//lower_bound迭代器 值为res.first->first
res.second//upper_bound迭代器 ......

// 指定排序规则
map<int,int,MyCompare> m;//同set
```
### 1.11.1.2 multimap接口
```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultiMap;

    myMultiMap.insert({2, "apple"});
    myMultiMap.insert({1, "banana"});
    myMultiMap.insert({3, "orange"});
    myMultiMap.insert({2, "grape"});

    // 使用 equal_range 查找给定键所有的元素
    auto range = myMultiMap.equal_range(2);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // 使用 find 查找第一个匹配的元素
    auto it = myMultiMap.find(3);
    if (it != myMultiMap.end()) {
        std::cout << "Found: " << it->first << ": " << it->second << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
2: apple
2: grape
Found: 3: orange

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultiMap;

    myMultiMap.insert({2, "apple"});
    myMultiMap.insert({1, "banana"});
    myMultiMap.insert({3, "orange"});
    myMultiMap.insert({2, "grape"});

    // 删除键为2的所有元素
    int keyToDelete = 2;
    auto range = myMultiMap.equal_range(keyToDelete);
    myMultiMap.erase(range.first, range.second);

    // 打印删除后的 multimap
    for (const auto& pair : myMultiMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
1: banana
3: orange
```
### 1.11.2 map底层存储实现
map以RB-TREE为底层机制。RB-TREE是一种平衡二叉搜索树，自动排序效果不错。map的内部结构是R-B-tree来实现的，所以保证了一个稳定的动态操作时间，查询、插入、删除都是O（logN），最坏和平均都是。

## 1.12 map和set的3个问题
### 1.12.1 为何map和set的插入删除效率比其他序列容器高。
因为不需要内存拷贝和内存移动
### 1.12.2 为何map和set每次Insert之后，以前保存的iterator不会失效？
因为插入操作只是结点指针换来换去，结点内存没有改变。而iterator就像指向结点的指针，内存没变，指向内存的指针也不会变。
### 1.12.3 数据元素增多时（从10000到20000），map的set的查找速度会怎样变化？
RB-TREE用二分查找法，时间复杂度为logn，所以从10000增到20000时，查找次数从log10000=14次到log20000=15次，多了1次而已。
```
(2^0 = 1)
(2^1 = 2)
(2^2 = 4)
(2^3 = 8)
(2^4 = 16)
(2^5 = 32)
(2^6 = 64)
(2^7 = 128)
(2^8 = 256)
(2^9 = 512)
(2^{10} = 1024) (1 kilobyte in binary)
(2^{11} = 2048)
(2^{12} = 4096)
(2^{13} = 8192)
(2^{14} = 16384)
(2^{15} = 32768)
(2^{16} = 65536)
(2^{17} = 131072)
(2^{18} = 262144)
(2^{19} = 524288)
(2^{20} = 1048576) (1 megabyte in binary)
```
"1 megabyte in binary" 是指 1 兆字节，这通常是指 (2^{20}) 字节，而不是 (10^6) 字节。
### 1.12.4 set map hash 时间复杂度
#### set、map的时间复杂度 multimap,multiset
红黑树实现
插入O(logN)
查看O(logN)
删除O(logN)
#### hash_map,hash_set,hash_multimap,hash_multiset
哈希表实现
插入:O(1)，最坏情况O(N)。
查看:O(1)，最坏情况O(N)。
删除:O(1)，最坏情况O(N)
### 1.12.5 二叉树存储
二叉树既可以用链式存储，也可以用数组顺序存储。数组顺序存储的方式比较适合完全二叉树，其他类型的二叉树用数组存储会比较浪费存储空间。堆其实就是一种完全二叉树，最常用的存储方式就是数组。
### 1.12.6 散列表VS二叉查找(排序)树
散列表无序存储，二叉查找树，中序遍历O(n)输出有序
散列表扩容耗时多，不稳定。平衡二叉查找树稳定O(logn)
散列表复杂，散列函数。平衡二叉查找树成熟稳定
散列查找常量级，哈希冲突不一定比logn小，不一定比平衡二叉查找树高
### 1.12.7 红黑树
红黑树是一种平衡二叉查找树，
红黑树的高度近似 log2n，所以它是近似平衡，插入、删除、查找操作的时间复杂度都是 O(logn)。
二分法的时间复杂度
N/2 N/4 ... 设置x次找到，N*(1/2)^x = 1，x=log2N
log2n
### 1.12.8 multimap 支持`[]`吗？
multimap 支持 `[]` 下标操作，但与 map 不同，它返回一个迭代器而不是一个值。当使用 [] 下标操作时，它会返回指向第一个匹配键的迭代器。由于 multimap 可能包含多个具有相同键的元素，这个操作允许你访问这些元素中的第一个。

如果你希望获取所有具有相同键的元素，你可以使用迭代器来遍历它们，或者使用范围循环来处理它们。这允许你处理所有与特定键相关的值。

以下是一个示例，演示如何使用 multimap 进行 `[]` 下标操作：

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultiMap;
    myMultiMap.insert({1, "apple"});
    myMultiMap.insert({1, "banana"});
    myMultiMap.insert({2, "cherry"});

    // 使用 [] 下标操作获取第一个匹配键的元素
    auto it = myMultiMap[1];
    std::cout << "First element with key 1: " << it->second << std::endl;

    // 遍历所有匹配键的元素
    for (auto range = myMultiMap.equal_range(1); range.first != range.second; ++range.first) {
        std::cout << "Element with key 1: " << range.first->second << std::endl;
    }

    return 0;
}
```
上述示例中，`myMultiMap[1] `返回的是指向第一个匹配键 1 的元素的迭代器，而遍历匹配键的元素允许你获取所有相关值。

`std::map`和`std::multimap`容器了`at()`成员函数，它可以用来访问与给定键关联的值。与`[]`操作符不同，`at()`在键不存在时会抛出一个`std::out_of_range`异常，而不是默默地插入一个新元素。
使用`at()`可以让你在访问键时进行更安全的边界检查。下面是一个示例：
```cpp
#include <map>
#include <iostream>
#include <stdexcept>

int main() {
    std::map<std::string, int> myMap;
    myMap["apple"] = 1;
    myMap["banana"] = 2;

    try {
        int value = myMap.at("banana");
        std::cout << "The value for 'banana' is: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Key not found in map." << std::endl;
    }

    try {
        int value = myMap.at("cherry"); // 这个键不存在
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Key not found in map." << std::endl;
    }

    return 0;
}
```

在这个例子中，当尝试访问一个不存在的键（"cherry"）时，`at()`会抛出一个异常，从而可以被异常处理机制捕获并做出适当的响应。

因此，如果你需要在访问`std::map`或`std::multimap`中的元素时进行安全性检查，`at()`是一个更好的选择，因为它可以防止程序因错误的键访问而导致的意外行为。
### 1.12.9 判断一个键是否存在于容器中：

1. 使用`find()`成员函数：
    ```cpp
    std::map<KeyType, ValueType> myMap;
    KeyType keyToFind;
    if (myMap.find(keyToFind) != myMap.end()) {
        // 键存在
    }
    ```

2. 使用`count()`成员函数（仅在`std::map`中返回0或1，在`std::multimap`中可能返回大于1的值）：
    ```cpp
    if (myMap.count(keyToFind) > 0) {
        // 键存在
    }
    ```

3. 使用`contains()`成员函数（C++20 引入）：
    ```cpp
    if (myMap.contains(keyToFind)) {
        // 键存在
    }
    ```

4. 使用`try_emplace()`或`emplace()`成员函数尝试插入一个元素，如果键已存在则不执行插入：
    ```cpp
    auto [it, inserted] = myMap.try_emplace(keyToFind, valueToInsert);
    if (!inserted) {
        // 键已存在
    }
    ```

## 1.13 map和set的区别
### 1.13.0 map和set的区别
 - 相同：
map和set都是C++的关联容器，其底层实现都是红黑树（RB-Tree）。由于 map 和set所开放的各种操作接口，RB-tree 也都提供了，所以几乎所有的 map 和set的操作行为，都只是转调 RB-tree 的操作行为。
- 区别：
（1）map中的元素是key-value（关键字—值）对：关键字起到索引的作用，值则表示与索引相关联的数据；Set与之相对就是关键字的简单集合，set中每个元素只包含一个关键字。

（2）set的迭代器是const的，不允许修改元素的值；map允许修改value，但不允许修改key。其原因是因为map和set是根据关键字排序来保证其有序性的，如果允许修改key的话，那么首先需要删除该键，然后调节平衡，再插入修改后的键值，调节平衡，如此一来，严重破坏了map和set的结构，导致iterator失效，不知道应该指向改变前的位置，还是指向改变后的位置。所以STL中将set的迭代器设置成const，不允许修改迭代器的值；而map的迭代器则不允许修改key值，允许修改value值。

（3）map支持下标操作，set不支持下标操作。map可以用key做下标，map的下标运算符[ ]将关键码作为下标去执行查找，如果关键码不存在，则插入一个具有该关键码和mapped_type类型默认值的元素至map中，因此下标运算符[ ]在map应用中需要慎用，const_map不能用，只希望确定某一个关键值是否存在而不希望插入元素时也不应该使用，mapped_type类型没有默认值也不应该使用。如果find能解决需要，尽可能用find。

## 1.14 迭代器作用（STL中迭代器的作用，有指针为何还要迭代器）
### 1.14.1 迭代器作用
- Iterator（迭代器）模式又称Cursor（游标）模式，用于提供一种方法顺序访问一个聚合对象中各个元素, 而又不需暴露该对象的内部表示。
  - 或者这样说可能更容易理解：Iterator模式是运用于聚合对象的一种模式，通过运用该模式，使得我们<span style="color:red">可以在不知道对象内部表示的情况下，按照一定顺序（由iterator提供的方法）访问聚合对象中的各个元素</span>。
- 由于Iterator模式的以上特性：与聚合对象耦合，在一定程度上限制了它的广泛运用，一般仅用于底层聚合支持类，如STL的list、vector、stack等容器类及ostream_iterator等扩展iterator
### 1.14.2 迭代器和指针的区别
- 迭代器不是指针，是类模板，表现的像指针。他只是模拟了指针的一些功能，通过重载了指针的一些操作符，->、*、++、--等。迭代器封装了指针，是一个“可遍历STL（ Standard Template Library）容器内全部或部分元素”的对象， 本质是封装了原生指针，是指针概念的一种提升（lift），提供了比指针更高级的行为，相当于一种智能指针，他可以根据不同类型的数据结构来实现不同的++，--等操作。
- 迭代器返回的是对象引用而不是对象的值，所以cout只能输出迭代器使用*取值后的值而不能直接输出其自身
### 1.14.3 迭代器产生原因
- Iterator类的访问方式就是把不同集合类的访问逻辑抽象出来，使得不用暴露集合内部的结构而达到循环遍历集合的效果。
## 1.15 STL迭代器删除元素
### 1.15.0 STL迭代器删除元素
- 这个主要考察的是迭代器失效的问题。
- 1.对于序列容器vector,deque来说，使用erase(itertor)后，后边的每个元素的迭代器都会失效，但是后边每个元素都会往前移动一个位置，但是erase会返回下一个有效的迭代器；
- 2.对于关联容器map set来说，使用了erase(iterator)后，当前元素的迭代器失效，但是其结构是红黑树，删除当前元素的，不会影响到下一个元素的迭代器，所以在调用erase之前，记录下一个元素的迭代器即可。
- 3.对于list来说，它使用了不连续分配的内存，并且它的erase方法也会返回下一个有效的iterator，因此上面两种正确的方法都可以使用。

```cpp
for(auto it = vec.begin(); it != vec.end(); /* 不在这里更新迭代器 */)
{
    if(需要删除的条件)
    {
        it = vec.erase(it);  // erase 返回指向被删除元素之后元素的迭代器
    }
    else
    {
        ++it;  // 只有在不删除元素时才更新迭代器
    }
}
for(auto it = mySet.begin(); it != mySet.end(); /* 不在这里更新迭代器 */)
{
    if(需要删除的条件)
    {
        it = mySet.erase(it);  // erase 返回指向被删除元素之后元素的迭代器
    }
    else
    {
        ++it;  // 只有在不删除元素时才更新迭代器
    }
}
std::set<int> mySet = {1, 2, 3, 4, 5};

for (auto it = mySet.begin(); it != mySet.end(); /* 不在这里更新迭代器 */)
{
    if (需要删除的条件)
    {
        mySet.erase(it++);  // 先使用 it，然后递增 it
    }
    else
    {
        ++it;  // 如果没有删除元素，则递增 it
    }
}

std::set<int> mySet = {1, 2, 3, 4, 5};

// 复制不需要删除的元素到一个临时 set
std::set<int> temp;
std::copy_if(mySet.begin(), mySet.end(), std::inserter(temp, temp.end()),
             [](int value) { return value % 2 == 0; });  // 保留所有偶数

// 使用临时 set 替换原来的 set
mySet = std::move(temp);

```
## 1.16 函数对象（仿函数）
### 1.16.0 函数对象（仿函数）
重载()运算符 使得类对象可以像函数一样使用 因此可以拥有自己的状态
函数对象可以作为函数的参数传递
函数对象可以内联编译（空间换时间）普通函数不行
可以配合模板使用set<int,MyCompare()> s;

### 1.16.1 内建函数对象
```cppf
//#include<functional>   sort(v.begin(),v.end(),greater<int>());大于
//negate<T> n;n(1);取反仿函数
//plus<int> p;p(1,1);加法仿函数
```
## 1.17 算法（algorithm）
### 1.17.1 std::for_each

std::for_each 算法会遍历给定范围内的每个元素，并对每个元素执行给定的函数或者 lambda 表达式。

这是一个 std::for_each 的例子：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::for_each(numbers.begin(), numbers.end(), [](int number) {
        std::cout << number << " ";
    });

    // 使用 lambda 表达式
    std::for_each(numbers.begin(), numbers.end(), [](int& number) {
        number *= 2;
    });
    return 0;
}
```
这段代码会打印出 1 2 3 4 5 和 2 4 6 8 10。std::for_each 接收了三个参数：一个迭代器指向 numbers 的开始，一个迭代器指向 numbers 的结束，以及一个 lambda 表达式，该表达式对每个元素进行操作（在这个例子中，操作是打印元素）。

### 1.17.2 std::transform

std::transform 算法接收输入范围，然后应用给定的函数或者 lambda 表达式到每个元素，并将结果存储到输出范围。

这是一个 std::transform 的例子：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> results(numbers.size());

    std::transform(numbers.begin(), numbers.end(), results.begin(), [](int number) {
        return number * 2;
    });

    // Print the results
    for (int number : results) {
        std::cout << number << " ";
    }

    return 0;
}
```
这段代码会打印出 2 4 6 8 10 。std::transform 接收了四个参数：一个迭代器指向 numbers 的开始，一个迭代器指向 numbers 的结束，一个迭代器指向 results 的开始，以及一个 lambda 表达式，该表达式对每个元素进行操作（在这个例子中，操作是乘以 2）并返回结果。结果被存储到 results 中。
### 1.17.3 visit/variant
使用 `std::visit` 处理 `std::variant`，其可能类型是 `std::vector<int>` 和 `std::vector<double>`：

```cpp
#include <iostream>
#include <vector>
#include <variant>
#include <numeric>

int main() {
    std::variant<int, double> a = 10, b = 20;
    int ret = 0;

    std::visit([&ret](auto const& t1, auto const& t2) {
        ret = t1 + t2;
    }, a, b);

    std::cout << "The sum is: " << ret << std::endl;
    // visit vector
    using VarVec = std::variant<std::vector<int>, std::vector<double>>;
    VarVec var = std::vector<int>{1, 2, 3, 4, 5};

    std::visit([](auto&& vec) {
        auto sum = std::accumulate(vec.begin(), vec.end(), 0.0);
        std::cout << "The sum of the vector is: " << sum << std::endl;
    }, var);

    return 0;
}
```
std::visit 将 10 和 20 的和赋给 ret，然后程序打印出 The sum is: 30。
在这个例子中，我们创建了一个 std::variant，它可以持有 `std::vector<int>` 或 `std::vector<double>`。我们使用 std::visit 和一个 lambda 表达式来计算和打印出 std::variant 中存储的 std::vector 的元素之和。

> error 示例:
```cpp
return std::visit([&](std::variant<T1,T2> const &t1,
					  std::variant<T1,T2>const & t2){
           // return t1+t2;
           std::variant<T1,T2> ret ;
```
> 无限递归问题: 在 lambda 函数内部，ret = t1 + t2; 实际上又调用了你正在定义的 operator+。因为 t1 和 t2 本身是 std::variant 类型，这就导致了无限递归。
代码试图对 `std::variant<T1, T2>` 对象进行加法操作，这在 `std::visit` 的 lambda 函数中完成。然而，在你的 lambda 函数内部，你又执行了 t1 + t2。而在这个上下文中，t1 和 t2 是 `std::variant<T1, T2>` 类型。因此，t1 + t2 事实上又在调用你正在定义的 `operator+`，这导致了无限递归。
为了避免这个问题，你需要确保 std::visit 的 lambda 函数对 std::variant 存储的实际值（即 T1 或 T2 类型）进行操作，而不是对 `std::variant` 本身进行操作。这就是为什么在修改后的代码中，我们使用 auto 关键字让编译器推断 t1 和 t2 的实际类型，而不是显式地声明它们为 `std::variant<T1, T2>` 类型。

## 1.18 C++ 中的 **SFINAE**

C++ 中的 **SFINAE**（Substitution Failure Is Not An Error，替换失败并非错误）是模板元编程中的核心原则之一，它允许编译器在模板重载解析过程中“优雅地”忽略某些不符合条件的模板特化，而不是直接报错。SFINAE 是实现编译时条件判断、类型检查和模板特化的关键技术。

---

### 1.18.1 **SFINAE 的核心机制**
1. **模板替换过程**：  
   在模板实例化时，编译器会尝试将所有可能的模板参数替换到模板中，生成具体的函数或类。
2. **替换失败的处理**：  
   - 如果在替换过程中**语法或语义错误**（如无效的类型操作），编译器不会直接报错，而是**静默忽略该模板候选**，继续尝试其他重载版本。
   - 若所有候选均失败，才会最终报错。

---

### 1.18.2 **SFINAE 的典型应用场景**
#### 1.18.2.1 **条件启用模板函数**
通过 SFINAE 控制特定模板的可见性，仅在满足条件时启用。常用 `std::enable_if` 或返回类型推导实现。

```cpp
#include <type_traits>

// 仅对整数类型生效
template <typename T>
auto func(T x) -> typename std::enable_if<std::is_integral<T>::value, void>::type {
    // 处理整数
}

// 仅对浮点类型生效
template <typename T>
auto func(T x) -> typename std::enable_if<std::is_floating_point<T>::value, void>::type {
    // 处理浮点数
}

int main() {
    func(42);      // 调用整数版本
    func(3.14);    // 调用浮点数版本
    // func("hello"); // 编译错误：无匹配版本
}
```

#### 1.18.2.2 **检查类型是否具有某成员**
利用 SFINAE 检测类型是否包含特定成员函数或属性。

```cpp
#include <iostream>

// 检查类型 T 是否有成员函数 `void foo()`
template <typename T>
class HasFoo {
    template <typename U>
    static auto test(int) -> decltype(std::declval<U>().foo(), std::true_type{});

    template <typename U>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

struct A { void foo() {} };
struct B {};

int main() {
    std::cout << HasFoo<A>::value; // 输出 1（true）
    std::cout << HasFoo<B>::value; // 输出 0（false）
}
```

#### 1.18.2.3 **选择不同实现策略**
根据类型特性选择不同的算法实现。

```cpp
template <typename T>
void process(T data) {
    if constexpr (std::is_pointer_v<T>) {
        // 指针类型的处理
    } else {
        // 非指针类型的处理
    }
}
```

---

### 1.18.3 **SFINAE 的实现原理**
#### 1.18.3.1 实现关键点：
- **替换失败**发生在模板参数推导阶段，而非实例化阶段。
- 替换失败的原因需是**直接依赖模板参数的无效表达式**（如访问不存在的成员、无效的类型转换）。

#### 1.18.3.2 SFINAE示例解析：
```cpp
template <typename T>
void foo(T x, typename T::type* = nullptr) {  // 若 T 没有 `type` 成员，替换失败
    // 实现 A
}

template <typename T>
void foo(T x) {  // 通用实现 B
    // 实现 B
}

int main() {
    struct X { using type = int; };
    foo(X{});   // 调用实现 A（T::type 存在）
    foo(42);    // 调用实现 B（T::type 不存在，SFINAE 忽略实现 A）
}
```

---

### 1.18.4 **SFINAE 的演进与替代**
- **C++11**：引入 `std::enable_if` 和类型特征库（`<type_traits>`），简化 SFINAE 的使用。
- **C++17**：`if constexpr` 允许在编译时分支中直接禁用代码块，减少对 SFINAE 的依赖。
- **C++20**：**概念（Concepts）** 通过 `requires` 子句直接约束模板参数，取代复杂的 SFINAE 技巧。

#### 1.18.4.1使用 Concepts（C++20）替代 SFINAE：
```cpp
template <typename T>
requires std::integral<T>  // 直接约束 T 为整数类型
void func(T x) { /* 处理整数 */ }

template <typename T>
requires std::floating_point<T>  // 约束 T 为浮点类型
void func(T x) { /* 处理浮点数 */ }
```

---

### 1.18.5 **总结**
- **SFINAE** 是 C++ 模板元编程的基石，用于在编译时根据类型特性选择代码分支。
- 核心价值：通过模板替换失败机制实现条件编译和类型检查。
- 现代替代：优先使用 `if constexpr` 和 Concepts 简化代码，但理解 SFINAE 仍是掌握模板机制的关键。

## 1.19 concepts
**Concepts（概念）** 是 C++20 引入的核心特性之一，用于对模板参数施加明确的约束，取代传统基于 **SFINAE** 或 **`std::enable_if`** 的复杂类型检查逻辑。它的目标是让模板代码更简洁、可读性更强，同时提供更友好的编译错误信息。

---

### 1.19.1 **Concepts 的核心作用**
1. **约束模板参数**：定义模板参数必须满足的条件（例如“必须是整数类型”或“必须支持某种操作”）。
2. **简化代码**：用直观的语法替代冗长的 SFINAE 技巧。
3. **提升错误信息**：编译器能明确提示“约束不满足”，而非复杂的模板实例化错误。

---

### 1.19.2 Concept**基本语法**
#### 1.19.2.1 **定义 Concept**
通过 `concept` 关键字定义约束条件：
```cpp
template <typename T>
concept Integral = std::is_integral_v<T>;  // 约束 T 必须是整数类型

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;  // 约束 T 必须支持 + 操作，且结果类型为 T
};
```

#### 1.19.2.2 **使用 Concept 约束模板**
在模板参数列表中通过 `requires` 或直接附加约束：
```cpp
// 方法 1：直接约束模板参数
template <Integral T>
void func(T x) { /* 仅接受整数类型 */ }

// 方法 2：使用 requires 子句
template <typename T>
requires Addable<T>
T add(T a, T b) { return a + b; }

// 方法 3：结合 auto 简化函数签名
auto add(Addable auto a, Addable auto b) { return a + b; }
```

#### 1.19.2.3 **组合约束**
通过逻辑运算符组合多个 Concept：
```cpp
template <typename T>
concept Numeric = Integral<T> || std::is_floating_point_v<T>;  // 整数或浮点数

template <Numeric T>
void process(T x) { /* ... */ }
```

---

### 1.19.3 **Concepts 的典型场景**
#### 1.19.3.1 **约束容器元素类型**
```cpp
#include <vector>
#include <concepts>

template <std::integral T>  // 使用标准库预定义的 integral concept
void sum(const std::vector<T>& vec) { /* 求和 */ }

sum(std::vector<int>{1, 2, 3});     // 合法
sum(std::vector<double>{1.0, 2.0}); // 编译错误：不满足约束
```

#### 1.19.3.2 **要求类型支持特定操作**
```cpp
template <typename T>
concept Printable = requires(const T& t) {
    { std::cout << t } -> std::same_as<std::ostream&>;  // 必须支持流输出
};

template <Printable T>
void log(const T& msg) { std::cout << msg << std::endl; }

log(42);       // 合法
log(std::vector<int>{}); // 编译错误：vector 不支持直接输出
```

#### 1.19.3.3 **替代 SFINAE 实现重载**
传统 SFINAE 代码：
```cpp
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void oldFunc(T x) { /* ... */ }
```
使用 Concepts：
```cpp
template <std::integral T>
void newFunc(T x) { /* 更简洁 */ }
```

---

### 1.19.4 **Concepts 的核心优势**
| 特性                | 传统 SFINAE                           | Concepts                          |
|---------------------|---------------------------------------|-----------------------------------|
| **可读性**          | 复杂、依赖晦涩的模板元编程            | 直观的约束表达式                  |
| **编译错误信息**    | 冗长的模板实例化失败信息              | 明确提示“约束不满足”              |
| **代码维护**        | 难以修改和扩展                        | 逻辑集中，易于组合和复用          |
| **语法简洁性**      | 需要 `enable_if` 或特化技巧           | 直接通过 `requires` 或 `concept`  |

---

### 1.19.5 **预定义的标准库 Concepts**
C++20 标准库已内置常用 Concepts，位于 `<concepts>` 头文件：
- **类型约束**：`std::integral`, `std::floating_point`, `std::same_as`, `std::derived_from`
- **操作约束**：`std::movable`, `std::copyable`, `std::invocable`
- **容器约束**：`std::ranges::range`, `std::contiguous_iterator`

示例：
```cpp
#include <concepts>

template <std::movable T>  // 要求 T 可移动
void moveExample(T&& obj) { /* ... */ }
```

---

### 1.19.6 **如何逐步应用 Concepts？**
1. **替换简单 SFINAE**：  
   将 `std::enable_if` 替换为 `requires` 或直接约束。
2. **定义领域特定约束**：  
   针对项目需求自定义 Concepts（如 `DatabaseConnectable`）。
3. **与 `auto` 结合**：  
   简化泛型 lambda 或函数签名：
   ```cpp
   auto printIfPrintable(const auto& obj) requires Printable<decltype(obj)> {
       std::cout << obj << std::endl;
   }
   ```
4. **约束类模板**：  
   对类模板的成员函数或整个类施加约束：
   ```cpp
   template <std::regular T>  // 要求 T 是“正则类型”（可默认构造、可拷贝等）
   class Container { /* ... */ };
   ```

---

### 1.19.7 **Concepts总结**
- **Concepts 是模板编程的革命性改进**：通过声明式约束替代过程式类型检查。
- **核心价值**：提升代码可读性、简化错误调试、增强模板设计意图的表达。
- **适用场景**：所有需要模板参数约束的场合，尤其是替代传统 SFINAE 的复杂逻辑。

建议在支持 C++20 的环境中优先使用 Concepts，它能让模板代码更接近“自然语言”，同时大幅降低维护成本。

## 1.20 std::sort的底层原理？是快速排序么？

`std::sort` 是 C++ 标准库中的一个排序算法，它的底层实现并不是简单的快速排序，而是一种混合排序算法，结合了多种排序算法的优点。以下是 `std::sort` 的底层原理和实现细节：

---

### **1.20.1 std::sort底层原理**

`std::sort` 的底层实现通常基于 **Introsort**（内省排序），这是一种混合排序算法，结合了以下三种排序算法的优点：

1. **快速排序（Quick Sort）**：
    - 在大多数情况下，`std::sort` 使用快速排序作为主要排序算法。
    - 快速排序的平均时间复杂度为 (O(n \log n))，但在最坏情况下会退化为 (O(n^2))。
2. **堆排序（Heap Sort）**：
    - 当递归深度超过一定阈值时，`std::sort` 会切换到堆排序。
    - 堆排序的时间复杂度为 (O(n \log n))，且不会出现最坏情况。
3. **插入排序（Insertion Sort）**：
    - 当待排序的元素数量较少时（通常小于某个阈值），`std::sort` 会使用插入排序。
    - 插入排序在小数据量下性能优异，时间复杂度为 (O(n^2))，但常数因子较小。

---

### **1.20.2 Introsort 的工作流程**

1. **快速排序阶段**：
    - 使用快速排序对数组进行分区和递归排序。
    - 如果递归深度超过 (2 \log n)（(n) 为元素数量），则切换到堆排序。
2. **堆排序阶段**：
    - 对当前分区进行堆排序，确保在最坏情况下时间复杂度仍为 (O(n \log n))。
3. **插入排序阶段**：
    - 当分区中的元素数量较少时，使用插入排序进行最终排序。

---

### **1.20.3 为什么使用 Introsort？**

- **避免快速排序的最坏情况**：通过切换到堆排序，避免快速排序在特定情况下退化为 (O(n^2))。
- **优化小数据量性能**：在小数据量下，插入排序的性能优于快速排序和堆排序。
- **平衡性能和稳定性**：Introsort 在大多数情况下保持了快速排序的高性能，同时通过堆排序和插入排序避免了最坏情况。

---

### **1.20.4 示例代码**

以下是一个使用 `std::sort` 的简单示例：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    std::sort(vec.begin(), vec.end());

    for (int num : vec) {
        std::cout << num << " ";
    }
    return 0;
}
```

---

### **1.20.5 std::sort总结**

`std::sort` 的底层实现基于 **Introsort**，结合了快速排序、堆排序和插入排序的优点。它通过以下方式确保高效和稳定的排序：

1. 在大多数情况下使用快速排序。
2. 在递归深度过大时切换到堆排序，避免最坏情况。
3. 在小数据量下使用插入排序，优化性能。

这种混合排序算法使得 `std::sort` 在大多数场景下都能提供高效的排序性能。
