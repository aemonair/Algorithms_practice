[TOC]
# 1. STL
- C++ Standard Library C++标准库
- Standard Template Library STL标准模板库

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
2. 所有容器的迭代器都支持==和!=运算符；一般都支持++和--运算符（forward_list不支持--运算符）；除了无序关联容器以外，其它容器的迭代器均支持<, <=, >, >=运算符。
3. 一个迭代器范围由一对迭代器表示，第一个迭代器指向范围内第一个元素，第二个迭代器指向范围内最后一个元素的下一个位置，是一个左闭右开区间[begin, end)。如果begin和end相等，则范围为空；如果begin和end不等，则范围至少包含一个元素，且begin指向第一个元素；begin递增若干次可以==end。
4. 每种容器都有指向首元素的begin()和指向尾后位置的end()迭代器，类型类似于vector<int>::iterator；另外还有对应的const版本的迭代器cbegin()和cend()，类型类似于vector<int>::const_iterator。
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
  * vector ,m==2,n个元素总时间 2*n/(2-1);
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
- 动态链表，在堆上分配空间，每插入一个元数都会分配空间，每删除一个元素都会释放空间。
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
s.erase(elem);//删除elem的元素
s.find(elem);//存在返回对应元素的迭代器（*pos可以取找到的值） 不存在返回end()迭代器
s.count(elem);//找elem个数 对于set要么1 要么0
set<int>::iterator res = s.lower_bound(elem);//返回第一个key>=elem元素的迭代器
set<int>::iterator res = s.upper_bound(elem);//返回第一个key>elem元素的迭代器
pair<set<int>::iterator,set<int>::iterator> res = s.equal_range(elem);//返回容器中key与elem相等的上下限的两个迭代器(对组)
res.first//lower_bound迭代器
res.second//upper_bound迭代器
pair<set<int>::iterator,bool> res = s.insert(i);//res.second为bool体现是否插入成功
```
利用仿函数(普通回调函数只是指针 不能作为类型套入模板函数)指定排序规则//对自定义数据类型使用set时同样在插入之前指定排序规则
```
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
在这个例子中，我们创建了一个 std::variant，它可以持有 std::vector<int> 或 std::vector<double>。我们使用 std::visit 和一个 lambda 表达式来计算和打印出 std::variant 中存储的 std::vector 的元素之和。
> error 示例:
> ```cpp
> return std::visit([&](std::variant<T1,T2> const &t1, std::variant<T1,T2>const & t2){
>            // return t1+t2;
>            std::variant<T1,T2> ret ;
> ```
> 无限递归问题: 在 lambda 函数内部，ret = t1 + t2; 实际上又调用了你正在定义的 operator+。因为 t1 和 t2 本身是 std::variant 类型，这就导致了无限递归。
代码试图对 `std::variant<T1, T2>` 对象进行加法操作，这在 `std::visit` 的 lambda 函数中完成。然而，在你的 lambda 函数内部，你又执行了 t1 + t2。而在这个上下文中，t1 和 t2 是 `std::variant<T1, T2>` 类型。因此，t1 + t2 事实上又在调用你正在定义的 `operator+`，这导致了无限递归。
为了避免这个问题，你需要确保 std::visit 的 lambda 函数对 std::variant 存储的实际值（即 T1 或 T2 类型）进行操作，而不是对 `std::variant` 本身进行操作。这就是为什么在修改后的代码中，我们使用 auto 关键字让编译器推断 t1 和 t2 的实际类型，而不是显式地声明它们为 `std::variant<T1, T2>` 类型。