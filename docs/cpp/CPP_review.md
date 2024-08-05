[TOC]

# 1. C/C++基础关键字

## 1.1 static关键字作用

### 1.1.1 c里的static

#### 1.1.1.1 静态局部变量
> 普通局部变量在栈上(或堆上动态)分配，局部变量所在函数被多次调用时，局部变量每次的位置不一定相同。

```cpp
int func()
{
    int        local1  = 2;
    int        local2  ;
    static int slocal1 ;
    static int slocal2 = 3;

    local1++;
    local2++;
    slocal1++;
    slocal2++;
    printf("local1  :%d(& %p),\t  local2 :%d(& %p),\n",  local1, &local1 ,  local2, & local2);
    printf("slocal1 :%d(& %p),\t slocal2 :%d(& %p),\n", slocal1, &slocal1, slocal2, &slocal2);
    return 0;
}

{
    func();
    func();
}

// local1  :3(& 0x7ffc8373a450),     local2 :32631(& 0x7ffc8373a454),
// slocal1 :1(& 0x55bca240e018),    slocal2 :4(& 0x55bca240e010),

// local1  :3(& 0x7ffc8373a450),     local2 :32765(& 0x7ffc8373a454),
// slocal1 :2(& 0x55bca240e018),    slocal2 :5(& 0x55bca240e010),
```

#####  1.1.1.1.1. 存储位置
- 存储在静态区，生命周期与程序相同，main函数之前初始化，在程序退出时销毁（在全局存储区.data不在.bss)
##### 1.1.1.1.2. 作用域
- 作用域仍为**局部作用域**，当定义它的函数或者语句块结束的时候，作用域结束。但是当局部静态变量离开作用域后，**并没有销毁**，而是仍然驻留在内存当中，只不过我们不能再对它进行访问，直到该函数再次被调用，并且值不变
##### 1.1.1.1.3. 访问权限
- 静态局部变量只能被其作用域内的变量或函数访问。也就是说虽然它会在程序的整个生命周期中存在，由于它是static的，它不能被其他的函数和源文件访问。
##### 1.1.1.1.4. 值
- 静态局部变量如果没有被用户初始化，者编译器自动赋值为0；以后每次调用仍是从全局存储区读出的就是上次修改后的值。

#### 1.1.1.2 静态全局变量
#####  1.1.1.2.1. 存储位置
- 存储在静态区，被static修饰的全局变量只能被该包含该定义的文件访问。静态全局变量可以分别定义；在全局数据区分配存储空间，且编译器会自动对其初始化.
##### 1.1.1.2.2. 作用域


```cpp test_static_extern.cpp
// 被包含的文件中，定义全局静态变量
#include "test_static_extern.h"

int global_1    ; //普通全局变量，可extern
int global_2 = 2;

static int global_s2 =6;
static int global_s3   ;
```

```cpp
// main函数定义同名静态全局变量，使用另一个文件中的静态全局变量（出错）
#include <iostream>
#include "test_static_extern.h" // head file

extern int global_1     ; // 普通全局变量，可使用
extern int global_2     ;

static int global_s1    ; //静态全局变量
static int global_s2 = 2;

int main()
{
    // 打印
    std::cout << "global_s1:" << global_s1 << std::endl;
    std::cout << "global_s2:" << global_s2 << std::endl;

    std::cout << "global_1:" << global_1 << std::endl;
    std::cout << "global_2:" << global_2 << std::endl;

    std::cout << global_s3 << std::endl;
    // error: ‘global_s3’ was not declared in this scope
    return 0;
}

```
- 静态全局变量**仅对当前文件可见**，其他文件不可访问，其他文件可以定义与其同名的变量，两者互不影响. 加上static关键字能够有效地降低程序模块之间的耦合，避免不同文件同名变量的冲突，且不会误使用
- （普通全局变量对整个工程可见，其他文件可以使用extern外部声明后直接使用。也就是说其他文件不能再定义一个与其相同名字的变量了（否则编译器会认为它们是同一个变量）。

>**把局部变量改变为静态变量后是改变了它的存储方式即改变了它的生存期。
>把全局变量改变为静态变量后是改变了它的作用域， 限制了它的使用范围。**


#### 1.1.1.3 静态函数
```cpp test.static_extern.h
#ifndef _TEST_STATIC_EXTERN_
#define _TEST_STATIC_EXTERN_

#include <iostream>

int printstatic1();//普通函数
static int printstatic2(); // 静态函数

#endif //_TEST_STATIC_EXTERN_
```
```cpp test_static_extern.cpp
#include "test_static_extern.h"

int printstatic1()
{
    std::cout << "this is a static func1." << std::endl;
    return 0;
}
static int printstatic2()
{
    std::cout << "this is a static func2." << std::endl;
    return 0;
}
```
```cpp
#include <iostream>

#include "test_static_extern.h"

static int printstatic()
{
    std::cout << "this is a static func." << std::endl;
    return 0;
}

int main()
{
    printstatic();
    printstatic1(); // 可调用其他文件的普通函数
    printstatic2(); // Error 不可调用
    return 0;
}
```
```cpp
Compiling ...test_static_func.cpp test_static_extern.cpp
In file included from test_static_func.cpp:3:0:
test_static_extern.h:9:12: warning: ‘int printstatic2()’ used but never defined
 static int printstatic2();
            ^~~~~~~~~~~~
/tmp/ccHhYITF.o: In function `main':
/home/air/test/cpp/01.01.static_test/test_static_func.cpp:15: undefined reference to `printstatic2()'
collect2: error: ld returned 1 exit status
```
 1. 静态函数只能在声明它的文件中可见，其他文件不能引用该函数
 2. 不同的文件可以使用相同名字的静态函数，互不影响
 3. static函数与普通函数有什么区别：static函数在内存中只有一份，普通函数在每个被调用中维持一份拷贝

### 1.1.2 cpp里的static
#### 1.1.2.1 类里静态数据成员
> 被 static 修饰的变量属于类变量，可以通过`类变量名.变量名`直接引用，而不需要 new 出一个类来
##### 1.1.2.1.1分配空间
- 静态数据成员是在程序开始运行时被分配空间，到程序结束之后才释放，只要类中指定了静态数据成员，即使不定义对象，也会为静态数据成员分配空间。

```cpp
// sizeof(A) = 4
class A
{
    int a;
};
// sizeof(B) = 1
class B
{
    static int b;
};
// sizeof(C) = 4
class C
{
    int a;
    static int b;
};
```
##### 1.1.2.1.2声明/初始化
  - 静态数据成员存储在全局数据区，静态数据成员在定义时分配存储空间，所以不能在类声明中定义
  - static 成员不能在类体内进行初始化，只能在类体外进行初始化。 若未对静态数据成员赋初值，则编译器会自动为其初始化为 0。

```cpp
// 普通非静态变量不能这样初始化
// int A::a = 10;
//  error: ‘int A::a’ is not a static data member of ‘class A’
// 静态变量在类内声明，在类外定义、初始化
int B::b = 20;
int C::b = 30;

int main()
{
    std::cout << "B::b :" << B::b << std::endl; // 20
    std::cout << "C::b :" << C::b << std::endl; // 30

    B instance_b;
    std::cout << "instance_b.b  :" << instance_b.b  << std::endl; // 20
    return 0;
}
```
```cpp
// 未在类外定义的情况会报 未定义错误
class D
{
public:
    static int b;
};

int main()
{
    // 未定义，类内声明未定义，需要在类外定义
    D instance_d;
    std::cout << "instance_d.b  :" << instance_d.b  << std::endl;
    // undefined reference to `D::b'
}
```
```cpp
// 定义无初值
class E
{
public:
    static int e;
};

int E::e; // 定义未給初值，默认为0；

int main()
{
    // 未定义，类内声明未定义，需要在类外定义
    E instance_e;
    std::cout << "instance_e.e  :" << instance_e.e  << std::endl;    // 0
}
```
##### 1.1.2.1.3 类共享的静态资源
  - 静态数据成员是类的成员，无论定义了多少个类的对象，静态数据成员的拷贝只有一个，且对该类的所有对象可见。static 成员不占用类对象的空间
  - 可以实现多个对象之间的数据共享，是类的所有对象中共享的成员
##### 1.1.2.1.4 作用域(类名::静态成员名)
```cpp
    std::cout << "B::b          :" << B::b          << std::endl;
    B instance_b;
    std::cout << "instance_b.b  :" << instance_b.b  << std::endl;
```
  - 静态数据成员既可以通过对象名引用，也可以通过类名引用
  - 静态数据成员不属于任何对象，在没有类的实例时其作用域就可见，在没有任何对象时，就可以进行操作

##### 1.1.2.1.5 静态数据成员两个优势：
 同全局变量相比，
- 静态成员没有进入程序的全局名字空间，因此不存在与程序中其它全局名字冲突的可能性
- 可以实现信息隐藏。静态数据成员可以是private成员，而全局变量不能

#### 1.1.2.2 静态成员函数
  * 全局静态函数
    - Static函数只作用于当前文件，不能被其他文件所用；
  * 类里，静态成员函数；
##### 1.1.2.2.1 静态成员函数属于类、没有this指针
- 类的静态成员(变量和方法)属于类本身；
- 静态成员函数没有this指针，它无法访问属于类对象的非静态数据成员，也无法访问非静态成员函数，它只能调用其余的静态成员函数；
- 非静态成员函数有this指针
- 如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。静态成员函数即使在类对象不存在的情况下也能被调用

##### 1.1.2.2.2 类名调用静态成员函数，不可以调用非静态成员函数
```cpp
#include <iostream>

class A
{
public:
    int normalfunc() // 普通函数
    {
        return 0;
    }
    static int staticfunc()
    {
        return 0;
    }
};

int main()
{
    A::normalfunc();
    // error: cannot call member function ‘int A::normalfunc()’ without object
    A::staticfunc();
    return 0;
}
```
##### 1.1.2.2.3 类实例对象可以调用静态和非静态成员函数
- 通过类的对象调用静态成员函数和非静态成员函数。
```cpp
    A instance_a;
    instance_a.normalfunc();
    instance_a.staticfunc();
```

##### 1.1.2.2.4 静态成员函数中不能调用非静态成员函数
```cpp
class A
{
public:
    int normalfunc()
    {
        std::cout << "This is a normal member function." << std::endl;
        return 0;
    }

    static int callnormal()
    {
        normalfunc();
        // error: cannot call member function ‘int A::normalfunc()’ without object
    }
};

```
##### 1.1.2.2.5 非静态成员函数中能调用静态成员函数
```cpp
class A
{
public:
    static int staticfunc()
    {
        std::cout << "This is a static member function." << std::endl;
        return 0;
    }

    int callstatic()
    {
        staticfunc();
    }
};
int main()
{
    A instance_a;
    instance_a.callstatic();
    return 0;
}
```
##### 1.1.2.2.6 静态成员函数访问静态数据成员不能访问非静态成员
- 非静态成员函数可以任意地访问静态成员函数和静态数据成员
- 调用这个函数不会访问或者修改任何对象（非static）数据成员，因为非静态成员（变量和方法）属于类的对象
> 因为静态成员函数属于整个类，在类实例化对象之前就已经分配空间了，而类的非静态成员必须在类实例化对象后才有内存空间，所以这个调用就出错了，就好比没有声明一个变量却提前使用它一样。

#### 1.1.2.3 静态类对象
就像变量一样，对象也在声明为static时具有范围，直到程序的生命周期。
在main结束后调用析构函数。这是因为静态对象的范围是贯穿程序的生命周期。
```cpp
#include <iostream>

class A
{
public:
    A(int i):a(i)
    {
        std::cout << "Constructor A." << a << std::endl;
    }
    ~A()
    {
        std::cout << "Destructor A." << a << std::endl;
    }
private:
    int a;
};


int main()
{
    // 局部变量
    {
        A c(3);
        static A d(4);
    }
    std::cout << "End main" << std::endl;
    return 0;
}

```
```cpp
// 运行结果
// 先析构了局部普通变量c，main结束后析构静态变量d
Constructor A.3
Constructor A.4
Destructor A.3
End main
Destructor A.4
静态对象的构造时机是当程序运行到定义它的位置之时。在这个程序里，静态对象 d 是在 main 函数之前定义的，所以它会最先被构造。
局部对象的构造时机是当程序运行到定义它的位置之时。在这个程序里，对象 c 是在语句块里定义的，当程序运行到这个语句块时，它才被构造。
因此，A(3) 的构造先于 A(4) 的构造，A(3) 的析构也先于 A(4) 的析构。
```

### 1.1.3 静态成员函数和普通成员函数的区别

- 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）
- 普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针

### 1.1.4 类的静态成员变量初始化问题
 - 静态数据成员存储在全局数据区，静态数据成员在定义时分配存储空间，所以不能在类声明中定义,
 - 类的静态成员变量最好在源文件中初始化，而不能在头文件初始化，否则，编译的时候就会报错"symbol multiply defined",
 - 头文件被多次include, 如果在头文件中初始化则可能会导致变量被多次声明， 因此不可行


   * 静态成员变量初始化, 即定义:

```cpp
return_type class_type::value_name = 0;

class A {
    static int b;
}

int A::b = 0;
```

## 1.2 const关键字
----

### 1.2.1 const修饰变量
#### 1.2.1.1 变量定义
* const用于定义变量，需先初始化，以后就没有机会改变他了
* const是constant的简写，是不变的意思。但并不是说它修饰常量，而是说它限定一个变量为只读。

```cpp

    const int i;
    //  error: uninitialized const ‘i’ [-fpermissive]

    const int a = 1;
    a = 2;
    // error: assignment of read-only variable ‘a’

    const std::string s = "helloworld";

```
1. 必须初始化
2. 不能修改

#### 1.2.1.2 作用域(默认为文件局部变量)
const对象默认为文件局部变量（详见#1.2.5.3 const对象默认为文件局部变量）

### 1.2.2 const修饰指针，指定指针或指针所指的数据

* const位于*左侧：
  * 指向常量的指针，不能修改值，数据
  * const就是用来修饰指针所指向的变量，即指针指向为常量
  - 指针常量：不能通过指针修改变量
* const位于*右侧 ：
  * 指针本身，常指针，数据可以改变；
  * const就是修饰指针本身，即指针本身是常量。
  - 常量指针：一直指向该变量，不能赋予新地址

  ``` c++

    const int * a;      // a 的指向内容不能修改
    int const * b;      // b 指向const对象的指针或者说指向常量的指针
    int * const c;      // c 不能修改，指向类型对象的const指针。或者说常指针、const指针
    const int* const d; //指向const对象的const指针。

  ```

  ```cpp

    int a = 10;
    int b = 20;
    int c = 30;
    const int d = 40;
    const int f = 50;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //指向常量的指针
    const int * const_p0      ; // const_p0 的指向内容不能修改,可以不初始化(指向int类型常量对象的指针，对象不可变，指针可变)
    const int * const_p1 = & a; // const_p1 的指向内容不能修改,不能通过 *const_p1 = 赋值给常量对象
    int const * const_p2 = & b; // const_p2 的指向内容不能修改,可以改变指针指向

    std::cout << "const_p0->" << *const_p0 << std::endl;
    std::cout << "const_p1->" << *const_p1 << std::endl;
    std::cout << "const_p2->" << *const_p2 << std::endl;

    const_p0 = &c; // 赋初始值，
    const_p1 = &b; // 可以改变指针指向
    const_p2 = &a;
    std::cout << "const_p0->" << *const_p0 << std::endl;
    std::cout << "const_p1->" << *const_p1 << std::endl;
    std::cout << "const_p2->" << *const_p2 << std::endl;

    *const_p0 = 50; // 不能通过指针修改常量
    // error: assignment of read-only location ‘* const_p0’
    *const_p1 = 50; // 不能通过 *const_p1 赋值给常量对象
    // error: assignment of read-only location ‘* const_p1’

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 常指针
    int * const p3_const = & c; // p3_const 指针本身不能修改，可以通过解引用修改指向对象的值

    int * const p4_const      ; // p4_const 不能修改，const是指针本身，const对象必须初始化
    // error: uninitialized const ‘p4_const’ [-fpermissive]

    int * const p5_const = & f;
    // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]

    std::cout << "p3_const->" << *p3_const << std::endl;
    *p3_const = 100;
    std::cout << "p3_const->" << *p3_const << std::endl;

    p3_const = &b;
    //  error: assignment of read-only variable ‘p3_const’

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // void * 指针
    const void* const_vp6 = & d; // 指向常量的void指针必须也为const

    std::cout << "const_vp6->" << *p3_const << std::endl;
    void      *       vp7 = & d; // 不能使用void * 指向const对象的地址
    // error: invalid conversion from ‘const void*’ to ‘void*’ [-fpermissive]

  ```
####  1.2.2.1 指向常量的指针

**const_p0** | const在`*`左边，未初始化
```cpp
    const int * const_p0      ; // const_p0指向常量的指针，
    int c                 = 30;
    const_p0              = &c; // 赋初始值，

    *const_p0             = 50; // 不能通过指针修改常量
    // error: assignment of read-only location ‘* const_p0’
```
    是一个指向int类型const对象的指针，const定义的是int类型，也就是ptr所指向的对象类型，而不是ptr本身，所以ptr可以不用赋初始值。但是不能通过ptr去修改所指对象的值。

**const_vp** | const在`*`左边， `void *`指针
```c++
    const int          d  = 40 ; // 常量
    const void* const_vp6 = & d; // 指向常量的void指针必须也为const

    void      *       vp7 = & d; // 不能使用void * 指向const对象的地址
    // error: invalid conversion from ‘const void*’ to ‘void*’ [-fpermissive]
```
    除此之外，也不能使用void*指针保存const对象的地址，必须使用const void*类型的指针保存const对象的地址。

**const_p1** | const在`*`左边，可以修改指针指向，不能通过解引用赋值

```c++
    int a = 10;
    int b = 20;
    const int * const_p1 = & a; // const_p1 的指向常量内容不能修改
    std::cout << "const_p1->" << *const_p1 << std::endl; // 10
    const_p1 = &b;
    std::cout << "const_p1->" << *const_p1 << std::endl; // 20

    *const_p1 = 50; // 不能通过 *const_p1 赋值给常量对象
    // error: assignment of read-only location ‘* const_p0’
```
    将非const对象的地址赋给const对象的指针:**允许把非const对象的地址赋给指向const对象的指针。**
    我们不能通过const_p1指针来修改val的值，即使它指向的是非const对象!
    不能使用指向const对象的指针修改基础对象，然而如果该指针指向了非const对象，可用其他方式修改其所指的对象。可以修改const指针所指向的值的，但是不能通过const对象指针来进行而已！

####  1.2.2.2 常指针
**p3_const | p4_const **
```cpp

    int b                 = 20;
    int c                 = 30;
    int * const p3_const  = & c; // p3_const 指针本身不能修改，可以通过解引用修改指向对象的值
    std::cout << "p3_const->" << *p3_const << std::endl;
    *p3_const = 100;
    std::cout << "p3_const->" << *p3_const << std::endl;

    p3_const = &b;
    //  error: assignment of read-only variable ‘p3_const’

    int * const p4_const      ; // p4_const 不能修改，const是指针本身，const对象必须初始化
    // error: uninitialized const ‘p4_const’ [-fpermissive]

```
const指针必须进行初始化，且const指针的值不能修改。
**p5_const**
```cpp
    const int f = 50;
    int * const p5_const = & f;
    // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
```
当把一个const常量的地址赋值给p5_const时候，由于p5_const指向的是一个变量，而不是const常量，所以会报错，出现：const int* -> int *错误！

####  1.2.2.3 指向常量的常指针
```cpp
const int p = 3;
const int * const ptr = &p;
```
ptr是一个const指针，然后指向了一个int 类型的const对象。

### 1.2.3 函数使用|const参数传递和函数返回值

#### 1.2.3.1 参数传递|形参 值传递
```cpp
void func(const int var); // 传递过来的参数不可变
void func(int *const var); // 指针本身不可变
char *strncpy(char *dest,const char *src,size_t n);//字符串拷贝函数
int  *strncmp(const char *s1,const char *s2,size_t n);//字符串比较函数
```
* 在一个函数声明中，const可以修饰形参表明他是一个输入参数，在函数内部不可以改变其值；
* 但是，作为形参，不会被更改，无需保护；
* 值传递的 const 修饰传递，一般这种情况不需要 const 修饰，因为函数会自动产生临时变量复制实参值

#### 1.2.3.2 参数传递|指针传递
```cpp
void StringCopy(char *dst, const char *src);`
```
* 当 const 参数为指针时，可以防止指针被意外篡改

#### 1.2.3.3 参数传递|引用传递
```cpp
void func(const A &a)
```
* const引用增加效率，减少复制:自定义类型的参数传递，需要临时对象复制参数，对于临时对象的构造，需要调用构造函数，比较浪费时间，因此我们采取 const 外加引用传递的方法;


> 也是用const来修饰返回的指针或引用，保护指针指向的内容或引用的内容不被修改，也常用于运算符重载。归根究底就是使得函数调用表达式不能作为左值。
#### 1.2.3.4 函数返回值|修饰内置类型
```cpp
const int func1();
```
* const 修饰内置类型的返回值，修饰与不修饰返回值作用一样(因为参数返回本身就是赋值给其他的变量)
#### 1.2.3.5 函数返回值|修饰指针返回值
##### const int*
```cpp
const int * func2();
const int *p2 = func2();
```
指针指向的内容不变。必须赋值给`const int*`类型；

##### int *const
```cpp
int *const func3();

void *pf30 = func3();
int  *pf31 = func3();
     *pf31 =  40    ;
```
指针本身不可变。没有影响。可以赋值给其他。

#### 1.2.3.6 函数返回值|自定义类型
* const 修饰自定义类型的作为返回值，此时返回的值不能作为左值使用，既不能被赋值，也不能被修改
*  const 修饰返回的指针或者引用，是否返回一个指向 const 的指针，取决于我们想让用户干什么
*  修饰函数返回值，不能被直接修改，只能被赋值给加const修饰的同类型

### 1.2.4 cosnt类的成员，常数据成员(初始化)

```cpp
class A
{
private:
    int a;
public:
    const int b;
    A(int i):b(i){}
    A():b(0){};
};
```
- **非静态`const`数据成员**必须在构造函数的初始化列表中初始化。
- **静态`const`数据成员**可以在类内初始化（如果值是常量表达式），也可以在类外初始化。
- **`constexpr`数据成员**必须在声明时初始化，并且只能初始化为常量表达式。
#### 1.2.4.1. 初始化列表/声明位置
- const声明为常对象，构造函数就只能通过初始化列表对该数据成员进行初始化,新版本也可以在声明位置直接初始化
#### 1.2.4.2 static结合const
- 可以通过结合static和const，在外面初始化;
```cpp
class A{
    static const int c;
};
const int A::c = 10;
```
- （static静态成员变量不能在类的内部初始化。在类的内部只是声明，定义必须在类定义体的外部，通常在类的实现文件中初始化。）
#### 1.2.4.3 const非静态成员变量初始化

在C++11及更高版本中，确实可以直接在类内初始化`const`非静态成员变量，只要这些成员变量是`integral`类型、`enum`类型、`std::nullptr_t`类型、`union`类型、类类型（如果该类型具有默认的`constexpr`构造函数），或者数组类型（其元素类型满足上述条件）。

这种直接在类内初始化`const`非静态成员变量的能力极大地简化了代码，使得不需要在构造函数的初始化列表中进行显式初始化。例如：

```cpp
#include <iostream>
#include <string>

class MyClass {
public:
    int const myConstInt = 42; // C++11 及更高版本允许这样做
    std::string const myConstString = "Hello, World!";

    MyClass() {
        std::cout << "myConstInt: " << myConstInt << std::endl;
        std::cout << "myConstString: " << myConstString << std::endl;
    }
};

int main() {
    MyClass obj;
    return 0;
}
```

在上面的代码中，`myConstInt`和`myConstString`都在类内被直接初始化，而无需构造函数的初始化列表。这是C++11引入的一个特性，旨在简化代码并提高可读性。

然而，需要注意的是，这种初始化方式并不适用于所有类型的`const`成员变量。例如，如果`const`成员变量是指向非`static`成员的指针，或者类型不满足上述条件，那么你仍然需要在构造函数的初始化列表中进行初始化。

此外，对于一些复杂的类型，如自定义类型的`const`成员变量，如果它们的初始化需要特定的构造函数或者需要在构造函数初始化列表中执行其他操作（如资源分配），那么在类内初始化可能就不适用了。在这种情况下，你仍然需要在构造函数的初始化列表中显式初始化这些`const`成员变量。

总之，C++11及其后续版本提供了在类内初始化`const`非静态成员变量的能力，这在许多情况下可以简化代码，但在处理复杂类型或需要特殊构造逻辑的场景中，你可能仍然需要使用构造函数的初始化列表。

### 1.2.5  const修饰类对象

> const 修饰函数，是从函数的层面,不修改数据
> const 修饰对象，是从对象的层面,不修改数据,只能调用const成员函数
- 只有常成员函数才有资格操作常量或常对象，没有使用const关键字指明的成员函数不能用来操作常对象

#### 1.2.5.1 const常对象只能调常函数，不能调普通成员函数
- const声明为常对象，只能调用它的常成员函数，而不能调用普通的成员函数。常对象的任何成员都不能被修改。

```cpp
    int A::printnormal()
    {
        std::cout << "normal a:" << a  << std::endl;
    }

    const A ctest1;
    ctest1.printnormal();
    // error: passing ‘const A’ as ‘this’ argument discards qualifiers [-fpermissive]

```
- const修饰的成员函数表明函数调用不会对对象做出任何更改，事实上，如果确认不会对对象做更改，就应该为函数加上const限定，这样无论const对象还是普通对象都可以调用该函数。

#### 1.2.5.2 非const常对象可以访问任意成员函数
```cpp
    int A::printconst() const
    {
        std::cout << "const b:" << b  << std::endl;
    }

    A test2(2);
    test2.printconst();
```

#### 1.2.5.3 const对象默认为文件局部变量
> 普通变量默认为extern。不需要添加extern。
> cosnt变量必须显式指定为extern。

```cpp
// 定义extern变量的文件
int ext ;
// extern int ext;
// undefined reference to `ext'
// collect2: error: ld returned 1 exit status

//const int ext_c = 12;
//undefined reference to `ext_c'
//collect2: error: ld returned 1 exit status


extern const int ext_c = 12;

```
> 其中，若普通变量extern则会出错，即未被const修饰的变量不需要extern显式声明！
> const常量需要显式声明extern，并且需要做初始化！因为常量在定义后就不能被修改，所以定义时必须初始化。

```cpp
// 调用extern的main函数
#include <iostream>

extern int ext;
extern const int ext_c;

int main()
{
    std::cout << (ext+10) << std::endl;
    // 10

    std::cout << (ext_c+10) << std::endl;
    // 22
    return 0;
}

```
- 非const变量
  * 不需要extern声明
- const变量
  * 显式声明extern，并初始化

### 1.2.6 const类的成员函数，表明其是一个常函数
const位置在函数声明之后 实现体之前
#### 1.2.6.1 常函数能访问任意数据成员
const函数承诺，不会修改数据成员，能访问const和非const数据成员，但不能修改；
```cpp
    int A::printa() const
    {
        std::cout << "const a:" << a  << std::endl;
        a = 20;
        // error: assignment of member ‘A::a’ in read-only object
    }

```
#### 1.2.6.2 常函数不能调用非const函数

- const类的成员函数，不能修改类的成员变量，不能调用非const成员函数

```cpp
    int A::printnormal()
    {
        std::cout << "normal a:" << a  << std::endl;
    }
    int A::printconst() const
    {
        printnormal();
        //// error: passing  cconst A’ as ‘this’ argumentcdiscards qualifiers [-fpermissive]
        std::cout << "const b:" << b  << std::endl;
    }

```
- const 修饰类成员函数，其目的是防止成员函数修改被调用对象的值，如果我们不想修改一个调用对象的值，所有的成员函数都应当声明为 const 成员函数

常成员函数（const member function）的主要限制是它不应该修改任何非静态数据成员，并且不应调用可能修改非静态数据成员的非const函数。然而，常成员函数可以访问和修改静态数据成员，因为静态数据成员不属于任何特定的对象实例，而是属于整个类。这意味着它们不受const限定符的影响。

静态数据成员是类的所有对象共享的，无论常成员函数是在一个常量对象还是非常量对象上调用的，它都可以修改静态数据成员，因为这些成员并不与任何一个特定对象实例的生命周期绑定。

例如：

```cpp
class MyClass {
public:
    static int count; // 静态数据成员

    MyClass() {
        ++count; // 在构造函数中增加计数
    }

    void incrementCount() { // 非const成员函数
        ++count;
    }

    void incrementCount() const { // const成员函数
        ++count;
    }
};

// 初始化静态数据成员
int MyClass::count = 0;

int main() {
    const MyClass obj1; // 常量对象
    obj1.incrementCount(); // 调用const成员函数，可以修改静态数据成员

    MyClass obj2;
    obj2.incrementCount(); // 调用非const成员函数，同样可以修改静态数据成员

    return 0;
}
```

在这个例子中，`incrementCount`无论是声明为const还是非const成员函数，都能够修改静态数据成员`count`。这是因为静态数据成员不属于任何单个对象，而是属于整个类，因此它们的修改不受const限定符的约束。

### 1.2.7 const关键字不能与static关键字同时使用修饰函数
```cpp
     static int printsc() const{}
    //error: static member function ‘static int A::printsc()’ cannot have cv-qualifier
```

- 静态函数不能为const
- static静态成员是属于类的，而不属于某个具体的对象，所有的对象共用static成员。
- this指针是某个具体对象的地址，因此**static成员函数没有this指针**。
- 而函数中的const其实就是用来**修饰this指针**的，意味this指向的内容不可变，所以const不能用来修饰static成员函数
- 静态成员函数不含有 this 指针，即不能实例化，const 成员函数必须具体到某一实例。

### 1.2.8 构造析构函数不能是const
```cpp
    A() const:b(0){};
    // error: constructors may not be cv-qualified

    ~A() const;
    //error: destructors may not be cv-qualified

```
- 构造函数不能为const，构造函数也属于类的成员函数，但是构造函数是要**修改类的成员变量**，所以类的构造函数不能申明成const类型的。

### 1.2.9 mutable可变数据成员
- 在const成员函数里，使用mutable关键字修饰的可变成员，可以被修改。

```cpp
class A
{
    mutable int m;
    const mutable int cm;
    // error: const ‘cm’ cannot be declared ‘mutable’
}
...
    int A::printconst() const
    {
        std::cout << "const b:" << b  << std::endl;
        m = 4;
        std::cout << "const m:" << m  << std::endl;
    }

```


## 1.3 extern关键字

### 1.3.1 条件编译
 - `#ifdef _cplusplus/#endif _cplusplus` 避免重复包含头文件

### 1.3.2 extern关键字作用
* extern置于变量或者函数前，提示编译器遇到此变量和函数时在其他模块中寻找其定义
* extern声明不是定义，即不分配存储空间

### 1.3.3 extern "C"
* extern C以C的规则去翻译相应的函数名而不是C++的，C++编译器会进行重载翻译；
* 一个C++程序包含其它语言编写的部分代码, 为了使它们遵守统一规则，可以使用extern指定一个编译和连接规约.
* extern "c": 指定一段代码应该根据C的编译和连接规约来链接, c++就会按照 c 的规则生成对应函数的符号, 可以进行连接
* extern "C"指令非常有用，因为C和C++的近亲关系。
  * **注意：extern "C"指令中的C，表示的一种编译和连接规约，而不是一种语言。C表示符合C语言的编译和连接规约的任何语言，如Fortran、assembler等。**
* extern "C"指令仅指定编译和连接规约，但不影响语义。例如在函数声明中，指定了extern "C"，仍然要遵守C++的类型检测、参数转换规则
* extern "C"的真实目的是实现**类C和C++的混合编程**

### 1.3.4 C/C++互相调用
#### 1.3.4.1 C++调用C函数
- 引用C的头文件时，需要加extern "C"

```cpp
//filec.h
#ifndef _FILEC_H_
#define _FILEC_H_

extern int add();
#endif//_FILEC_H_
```
----
```cpp
//filec.c
#include "filec.h"

int add()
{
    return 10;
}
```
----
```cpp
//maincppcallc.cpp
#include <iostream>

// 直接使用不加extern找不到
//#include "filec.h"
// maincppcallc.cpp:(.text+0x5): undefined reference to `add()'
//

extern "C"
{
    #include "filec.h"
}

int main()
{
    std::cout << add() << std::endl;
    return 0;
}

//gcc -c filec.c
//g++ maincppcallc.cpp filec.o -o main
//
//./main
```
#### 1.3.4.2 C调用C++函数
- 在C语言的头文件中，对其外部函数只能指定为extern类型，C语言中不支持extern "C"声明，在.c文件中包含了extern "C"时会出现编译语法错误。
- 所以使用extern "C"全部都放在于cpp程序相关文件或其头文件中。

```cpp
// filecpp.h
#ifndef _FILEC_H_
#define _FILEC_H_

extern "C"{
    int add();
}
#endif//_FILEC_H_
```
----
```cpp
// filecpp.cpp
#include "filecpp.h"

int add()
{
    return 11;
}
```
----
```cpp
// mainccallcpp.c
#include <stdio.h>

//#include "filecpp.h"

extern int add();

int main()
{
    printf("result:%d\n",add());
    return 0;
}

```
[C++项目中的extern "C" {}](https://www.cnblogs.com/skynet/archive/2010/07/10/1774964.html)

## 1.4 Volatile关键字

### 1.4.1 volatile

不会直接使用上一条语句对应的volatile变量的寄存器内容，而是重新从内存中读取
volatile告诉编译器，不要对我这个变量进行各种激进的优化，
Volatile变量，与非Volatile变量之间的操作，是可能被编译器交换顺序的。



#### 1.4.1.1 例子1(编译器优化同一个指针的值）
``` cpp
volatile int *p = /* ... */;
int a, b;
a = *p;
b = *p;
```

- `p` 就只是一个「指向 `int` 类型的指针」。
- `a = *p;` 和 `b = *p;` 两句，就只需要从内存中读取一次就够了。因为从内存中读取一次之后，CPU 的寄存器中就已经有了这个值；把这个值直接复用就可以了。
- 这样一来，编译器就会做优化，把两次访存的操作优化成一次。这样做是基于一个假设：我们在代码里没有改变 `p` 指向内存地址的值，那么这个值就一定不会发生改变
> 此处说的「读取内存」，包括了读取 CPU 缓存和读取计算机主存。

- 然而，由于 MMIP（Memory mapped I/O）的存在，这个假设不一定是真的。例如说，假设 `p` 指向的内存是一个硬件设备。这样一来，从 `p` 指向的内存读取数据可能伴随着**可观测的副作用**：硬件状态的修改。
- 此时，代码的原意可能是将硬件设备返回的连续两个 `int` 分别保存在 `a` 和 `b` 当中。这种情况下，编译器的优化就会导致程序行为不符合预期了。

#### 1.4.1.2 例子2(中断服务子程序访问变量)

``` cpp
static int i=0;

int main()
{
    while(1)
    {
    if(i) dosomething();
    }
}

/* Interrupt service routine */
void IRS()
{
    i=1;
}
```
- 上面示例程序的本意是产生中断时，由中断服务子程序IRS响应中断，变更程序变量i，使在main函数中调用dosomething函数，但是，由于编译器判断在main函数里面没有修改过i，因此可能只执行一次对从i到某寄存器的读操作，然后每次if判断都只使用这个寄存器里面的“i副本”，导致dosomething永远不会被调用。
- 如果将变量i加上volatile修饰，则编译器保证对变量i的读写操作都不会被优化，从而保证了变量i被外部程序更改后能及时在原程序中得到感知。

#### 1.4.1.3 例子3(比如并行设备的硬件寄存器）
```cpp
int  *output = (unsigned  int *)0xff800000; //定义一个IO端口
int   init(void)
{
    int i;
    for(i=0;i< 10;i++)
    {
        *output = i;
    }
}
```
- 经过编译器优化后，编译器认为前面循环半天都是废话，对最后的结果毫无影响，因为最终只是将output这个指针赋值为 9，所以编译器最后给你编译编译的代码结果相当于：
```cpp
int  init(void)
{
    *output = 9;
}
```
- 对此端口反复写操作，被优化后可能只做了一次读写操作；

#### 1.4.1.4 例子4(多线程）
```cpp
volatile  bool bStop=false;  //bStop 为共享全局变量
//第一个线程
void threadFunc1()
{
    ...
    while(!bStop){...}
}
//第二个线程终止上面的线程循环
void threadFunc2()
{
    ...
    bStop = true;
}
```
- 要想通过第二个线程终止第一个线程循环，如果bStop不使用volatile定义，那么这个循环将是一个死循环，因为bStop已经读取到了寄存器中，寄存器中bStop的值永远不会变成FALSE，加上volatile，程序在执行时，每次均从内存中读出bStop的值，就不会死循环了。

#### 1.4.1.5 总结：一般说来，volatile用在如下几个地方：
1) 中断服务程序中修改的供其它程序检测的变量需要加 volatile；(例子2）
2) 多任务环境下各任务间共享的标志应该加 volatile；(例子4，具体看1.4.3)
3) 存储器映射的硬件寄存器通常也要加 volatile 说明，因为每次对它的读写都可能由不同意义；（例子3）

- 总结来说，被 `volatile` 修饰的变量，在对其进行读写操作时，会引发一些**可观测的副作用**。而这些可观测的副作用，是由**程序之外的因素决定的**

### 1.4.2 volatile编译器负优化
- 在 C/C++ 中，对 volatile 对象的访问，有编译器优化上的副作用：
  - 不允许被优化消失（optimized out）；
  - 于序列上在另一个对 volatile 对象的访问之前。
> 这里提及的「不允许被优化」表示对 volatile 变量的访问，编译器不能做任何假设和推理，都必须按部就班地与「内存」进行交互。因此，上述例中「复用寄存器中的值」就是不允许的。

- 需要注意的是，无论是 C 还是 C++ 的标准，对于 volatile 访问的序列性，都有**单线程执行的前提**。其中 C++ 标准特别提及，这个顺序性在多线程环境里不一定成立。


### 1.4.3 多线程下volatile
- volatile 不能解决多线程中的问题。
- 按照 Hans Boehm & Nick Maclaren 的总结，volatile 只在三种场合下是合适的。
  - 和信号处理（signal handler）相关的场合；
  - 和内存映射硬件（memory mapped hardware）相关的场合；
  - 和非本地跳转（setjmp 和 longjmp）相关的场合。

#### 1.4.3.1 多线程判断变量 happens-before
```cpp
// global shared data
bool flag = false;

thread1()
{
    flag = false;
    Type* value = new Type(/* parameters */);
    thread2(value);
    while (true) {
        if (flag == true) {
            apply(value);
            break;
        }
    }
    thread2.join();
    if (nullptr != value) { delete value; }
    return;
}

thread2(Type* value)
{
    // do some evaluations
    value->update(/* parameters */);
    flag = true;
    return;
}
```
 > 这段代码将 thread1 作为主线程，等待 thread2 准备好 value。
 因此，thread2 在更新 value 之后将 flag 置为真，而 thread1 死循环地检测 flag。
 简单来说，这段代码的意图希望实现 thread2 在 thread1 使用 value 之前执行完毕这样的语义。

 - 问题主要出在两个方面。
 - 其一，在 thread1 中，flag = false 赋值之后，在 while 死循环里，没有任何机会修改 flag 的值，因此在运行之前，编译器优化可能会将 if (flag == true) 的内容全部优化掉。
 - 其二，在 thread2 中，尽管逻辑上 update 需要发生在 flag = true 之前，但编译器和 CPU 并不知道；
   - 因此编译器优化和 CPU 乱序执行可能会使 flag = true 发生在 update 完成之前，因此 thread1 执行 apply(value) 时可能 value 还未准备好。

#### 1.4.3.2 多线程加入volatile
```cpp
// global shared data
volatile bool flag = false;  // 1.

thread1() {
    flag = false;
    Type* value = new Type(/* parameters */);
    thread2(value);
    while (true) {
        if (flag == true) {  // 2.
            apply(value);
            break;
        }
    }
    thread2.join();
    if (nullptr != value) { delete value; }
    return;
}

thread2(Type* value) {
    // do some evaluations
    value->update(/* parameters */);
    flag = true;
    return;
}
```
- 在 (1) 处，我们将 flag 声明为 volatile-qualified。
- 因此，在 (2) 处，由于 flag == true 是对 volatile 变量的访问，故而 if-block 不会被优化消失。
- 然而，尽管 flag 是 volatile-qualified，但 value 并不是。因此，编译器仍有可能在优化时将 thread2 中的 update 和对 flag 的赋值交换顺序。
- 此外，由于 volatile 禁止了编译器对 flag 的优化，这样使用 volatile 不仅无法达成目的，反而会导致性能下降

#### 1.4.3.3 多线程加入两个volatile
```cpp
// global shared data
volatile bool flag = false;

thread1() {
    flag = false;
    volatile Type* value = new Type(/* parameters */);   // 1.
    thread2(value);
    while (true) {
        if (flag == true) {
            apply(value);
            break;
        }
    }
    thread2.join();
    if (nullptr != value) { delete value; }
    return;
}

thread2(volatile Type* value) {
    // do some evaluations
    value->update(/* parameters */);                    // 2.
    flag = true;
    return;
}
```
- 在上一节代码的基础上，(1) 将 value 声明为 volatile-qualified。
- 因此 (2) 处对两个 volatile-qualified 变量进行访问时，编译器不会交换他们的顺序。看起来就万事大吉了。
- 然而，volatile 只作用在编译器上，但我们的代码最终是要运行在 CPU 上的。尽管编译器不会将 (2) 处换序，但 CPU 的乱序执行（out-of-order execution）已是几十年的老技术了；
  - 在 CPU 执行时，value 和 flag 的赋值仍有可能是被换序了的（store-store）。

#### 1.4.3.4 分析多线程
- 一是 flag 相关的代码块不能被轻易优化消失，二是要保证线程同步的 happens-before 语义。
- 但本质上，设计使用 flag 本身也就是为了构建 happens-before 语义。
- 这也就是说，两个问题，后者才是核心；如有其他不用 flag 的办法解决问题，那么 flag 就不重要。
- 最简单的办法是使用原子操作。

```cpp
// global shared data
std::atomic<bool> flag = false;  // #include <atomic>

thread1() {
    flag = false;
    Type* value = new Type(/* parameters */);
    thread2(value);
    while (true) {
        if (flag == true) {
            apply(value);
            break;
        }
    }
    thread2.join();
    if (nullptr != value) { delete value; }
    return;
}

thread2(Type* value) {
    // do some evaluations
    value->update(/* parameters */);
    flag = true;
    return;
}
```
- 由于对 std::atomic\<bool\> 的操作是原子的，同时构建了良好的内存屏障，因此整个代码的行为在标准下是良定义的。
- 除此之外，还可以结合使用互斥量和条件变量。

```cpp
// global shared data
std::mutex m;                   // #include <mutex>
std::condition_variable cv;     // #include <condition_variable>
bool flag = false;

thread1() {
    flag = false;
    Type* value = new Type(/* parameters */);
    thread2(value);
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [](){ return flag; });
    apply(value);
    lk.unlock();
    thread2.join();
    if (nullptr != value)
        { delete value; }
    return;
}

thread2(Type* value) {
    std::lock_guard<std::mutex> lk(m);
    // do some evaluations
    value->update(/* parameters */);
    flag = true;
    cv.notify_one();
    return;
}
```

- 这样一来，由线程之间的同步由互斥量和条件变量来保证，同时也避免了 while (true) 死循环空耗 CPU 的情况;

- `std::atomic<bool>` 和原生的 bool 不同之处不仅在于对 `std::atomic<bool>` 的读写操作是有原子性保证的，还在于 `std::atomic<bool>` 提供了内存屏障。
- 其中 `std::atomic<bool>` 的 `operator=` 运算符，相当于
- `std::atomic<bool>::store(bool flag, std::memory_order_seq_cst)`。这里保证了不会乱序

### 1.4.4 volatile问题( 一个参数既是const还可以是volatile吗?一个指针可以是volatile吗?square(volatile int *ptr))
#### 1.4.4.1 一个参数既是const还可以是volatile吗？为什么？
- 可以。一个例子是只读的状态寄存器。它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。
#### 1.4.4.2 一个指针可以是volatile吗？为什么？
- 可以。尽管这并不常见。一个例子是当一个中断服务子程序修该一个指向一个buffer的指针时。
#### 1.4.4.3 下面的函数 参数为volatile，平方
```cpp
int square(volatile int *ptr)
{
    return *ptr * *ptr;
}
```
由于`*ptr`的值可能被意想不到地改变，因此a和b可能是不同的。结果，这段代码可能返回的不是你所期望的平方值！正确的代码如下：
```cpp
long square(volatile int *ptr)
{
    int a=*ptr;
    return a * a;
}
```
`volatile`关键字在C和C++中用于告诉编译器某个变量可能会被意外地改变。这通常用于硬件访问、多线程环境或实时系统中，其中变量可能由中断服务程序、其他处理器核心或外部设备修改，而这些修改是编译器无法预测的。

### 1.4.5 `volatile`与编译器优化
#### 1.4.5.1 `volatile`与编译器优化

当一个变量被声明为`volatile`时，编译器必须遵守以下规则：

1. **禁止重新排序**：编译器不会重新排序对`volatile`变量的读写操作，以保持它们的顺序，防止可能导致数据不一致的副作用。

2. **禁止优化掉读写操作**：即使编译器观察到对`volatile`变量的读写之间没有依赖关系，它也不会优化掉这些操作。每次访问`volatile`变量时，编译器都会生成读取或写入的实际代码，即使在连续的指令中变量的值没有被使用。

3. **读写同步**：访问`volatile`变量通常被认为具有某种形式的内存屏障效果，这意味着对`volatile`变量的读写操作与其他内存操作之间存在一定程度的同步。

#### 1.4.5.2 编译器负优化

然而，过度使用`volatile`关键字可能导致所谓的“负优化”。这是因为编译器为了遵循`volatile`变量的规则，可能生成更慢、更冗余的代码，从而影响性能。例如：

- **增加代码量**：每次访问`volatile`变量时，编译器都可能生成额外的指令，这增加了代码量，可能导致缓存未命中率增加。

- **减少寄存器使用效率**：编译器可能避免将`volatile`变量的值存储在寄存器中，导致更多的内存访问，从而降低了性能。

- **禁用编译器优化**：`volatile`变量的使用可能阻止编译器执行某些类型的优化，如循环展开、指令调度和常量传播，这些优化在没有`volatile`变量时通常可以提高代码效率。

#### 1.4.5.3 如何使用`volatile`

正确使用`volatile`的关键在于理解它所解决的问题类型。在硬件接口或低级编程中，`volatile`是必要的，但在多线程环境中，`volatile`可能不足以保证线程安全，因为虽然它防止了编译器的某些优化，但它并不提供原子性或锁机制。在多线程环境下，更推荐使用`std::atomic`类型和原子操作，这些类型和操作不仅防止了编译器优化，还提供了内存模型和原子性保证。

总之，`volatile`是一个强大但需要谨慎使用的工具。它有助于确保代码的正确性，尤其是在硬件交互或低级编程中，但在性能敏感的应用中，过度使用`volatile`可能导致不必要的性能损失。在多线程环境中，应优先考虑使用`std::atomic`和相关的原子操作来确保线程安全和性能。
## 1.5 this指针
### 1.5.0 this指针 打印

```cpp
class A
{
public:
    A(int i):a(i){}
    A * get_address()
    {
        return this;
    }

    int get_a()
    {
        return a;
    }
    int printvalue(const A & that)
    {
        std::cout << "this->a:" << this->a << std::endl;
        std::cout << "that.a" << that.a << std::endl;
    }
private:
    int a = 1;
};

int main()
{
    A instancea(5);
    std::cout << "&instancea           :" << &instancea << std::endl;
    std::cout << "instancea.get_address:" << instancea.get_address() << std::endl;

    std::cout << instancea.get_a() << std::endl;
    A instanceb(6);
    instanceb.printvalue(instancea);
    instancea.printvalue(instanceb);
    return 0;
    // &instancea 和 instancea.get_address() 的值应该是一样的
}
this->a:6
that.a:5
this->a:5
that.a:6
```
### 1.5.1 this 概念？
#### 1.5.1.0 概念
this 是一个指向当前对象的指针，它可以在类的成员函数内部使用。this 指针指向调用该成员函数的对象的地址，通过它可以访问当前对象的成员变量和成员函数。
#### 1.5.1.1 this不影响sizeof
1. this指针不是对象的一部分，不影响sizeof(对象)的结果。
#### 1.5.1.2 非静态成员函数隐式传递this
2. this作用域在类内部，当在类的**非静态成员函数**中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数传递给函数。
  - 即使你没有写上this指针，编译器在编译的时候也是加上this的，它作为非静态成员函数的隐含形参，对各成员的访问均通过this进行。
#### 1.5.1.3 友元函数没有this
3. 友元函数没有 this 指针，因为友元不是类的成员。只有非静态成员函数才有 this 指针。
```cpp
    static A * get_this()
    {
        return this;
        // error: ‘this’ is unavailable for static member functions
    }
    friend int get_a()
    {
        return this->a;
        //error: invalid use of ‘this’ in non-member function
    }
```
#### 1.5.1.4 this常量指针，不可修改
4. 因为 this 的目的总是指向“这个”对象，所以 this 是一个常量指针（参见2.4.2节，第56页），我们不允许改变 this 中保存的地址。
```cpp
class A{
    int move_this()
    {
        //this = nullptr;
        // 4. error: lvalue required as left operand of assignment
    }
};
```
#### 1.5.1.5 是个右值，不能取this地址
5. this 并不是一个常规变量，而是个右值，所以不能取得 this 的地址（不能 &this）

### 1.5.2 this的使用
#### 1.5.2.1 返回类本身返回 return *this
1. 在类的非静态成员函数中返回类对象本身的时候，直接使用 `return *this`。
#### 1.5.2.2 使用成员变量
2. 当参数与成员变量名相同时，如this->n = n （不能写成n = n)。
#### 1.5.2.3 为实现对象的链式引用；
#### 1.5.2.4 为避免对同一对象进行赋值操作；
#### 1.5.2.5 在实现一些数据结构时，如 list。

### 1.5.3 this的解释
当我们调用成员函数时，实际上是替某个对象调用它。

成员函数通过一个名为 this 的额外隐式参数来访问调用它的那个对象，当我们调用一个成员函数时，用请求该函数的对象地址初始化 this。
例如，如果调用 total.isbn()则编译器负责把 total 的地址传递给 isbn 的隐式形参 this，可以等价地认为编译器将该调用重写成了以下形式：
```cpp
//伪代码，用于说明调用成员函数的实际执行过程
Sales_data::isbn(&total)
```
其中，调用 Sales_data 的 isbn 成员时传入了 total 的地址。

### 1.5.4 关于this 返回 `const A*const `还是`A *const`

get_age函数会被解析成get_age(const A * const this),
add_age函数会被解析成add_age(A* const this,int a) 常指针，指针不能修改
### 1.5.5 this 主要有以下几个作用：

区分同名的成员变量和局部变量：当成员变量和局部变量同名时，使用 this 可以明确指出要访问的是成员变量。例如：

```cpp
class MyClass {
private:
    int num;
public:
    void setNum(int num) {
        this->num = num; // 使用 this 指针区分成员变量和局部变量
    }
};
```
在类的成员函数中返回对象本身：通过在成员函数中返回 *this（解引用 this 指针），可以实现链式调用。这种技术称为方法链（Method Chaining）。例如：

```cpp
class MyClass {
private:
    int value;
public:
    MyClass& setValue(int value) {
        this->value = value;
        return *this; // 返回对象本身，实现链式调用
    }
};
```
可以使用链式调用方式设置对象的多个属性，提高代码的可读性和简洁性。

在类的成员函数中传递当前对象：有时候，在类的成员函数中需要将当前对象作为参数传递给其他函数，可以使用 this 来传递当前对象的地址。

```cpp
class MyClass {
public:
    void doSomething() {
        // 将当前对象的地址传递给其他函数
        otherFunction(this);
    }

    void otherFunction(MyClass* obj) {
        // 使用传递的对象指针访问成员变量或调用成员函数
        int num = obj->getNum();
        // ...
    }
};
```
需要注意的是，this 指针只能在非静态成员函数中使用，因为静态成员函数没有隐式的当前对象。此外，对于常量成员函数（被 const 修饰的成员函数），this 指针的类型是指向常量的指针，即 const ClassName* 类型。这样做是为了确保常量成员函数不会修改对象的状态。
## 1.6 inline内联
[原文链接](https://www.cnblogs.com/fnlingnzb-learner/p/6423917.html)
### 1.6.1 内联inline
#### 1.6.1.1内联 加inline原因
- 解决大量消耗栈空间，引入inline
- 可以替换代码，例如循环中使用内连函数被替换成代码，避免频繁调用函数；
#### 1.6.1.2 inline使用限制
- 简单函数，不能包含复杂控制语句，不能是递归
#### 1.6.1.3 inline仅是一个对编译器的建议
inline 函数仅仅是一个对编译器的**建议**，所以最后能否真正内联，看编译器的意思，它如果认为函数不复杂，能在调用点展开，就会真正内联，并不是说声明了内联就会内联，声明内联只是一个建议而已。
### 1.6.1.4 建议 inline 函数的定义放在头文件中
- 因为内联函数要在调用点展开，所以编译器必须随处可见内联函数的定义，要不然就成了非内联函数的调用了。所以，这要求每个调用了内联函数的文件都出现了该内联函数的定义。
- 因此，将内联函数的定义放在头文件里实现是合适的，省却你为每个文件实现一次的麻烦。
- 声明跟定义要一致：如果在每个文件里都实现一次该内联函数的话，那么，最好保证每个定义都是一样的，否则，将会引起未定义的行为。如果不是每个文件里的定义都一样，那么，编译器展开的是哪一个，那要看具体的编译器而定。所以，最好将内联函数定义放在头文件中。
### 1.6.2 类中的成员函数默认inline
定义在类中的成员函数默认都是内联的，如果在类定义时就在类内给出函数定义，那当然最好。如果在类中未给出成员函数定义，而又想内联该函数的话，那在类外要加上 inline，否则就认为不是内联的。

### 1.6.3 inline 是一种"用于实现的关键字"
- 关键字 inline 必须与函数定义体放在一起才能使函数成为内联，仅将 inline 放在函数声明前面不起任何作用。

```cpp
//  如下风格的函数 Foo 不能成为内联函数：
inline void Foo(int x, int y); // inline 仅与函数声明放在一起
void Foo(int x, int y){}

// 而如下风格的函数 Foo 则成为内联函数：
void Foo(int x, int y);
inline void Foo(int x, int y) {} // inline 与函数定义体放在一起
```
- 所以说，inline 是一种"用于实现的关键字"，而不是一种"用于声明的关键字"。一般地，用户可以阅读函数的声明，但是看不到函数的定义。
- 尽管在大多数教科书中内联函数的声明、定义体前面都加了inline 关键字，但我认为inline不应该出现在函数的声明中。这个细节虽然不会影响函数的功能，但是体现了高质量C++/C 程序设计风格的一个基本原则：声明与定义不可混为一谈，用户没有必要、也不应该知道函数是否需要内联。
### 1.6.4 慎用 inline
- 内联能提高函数的执行效率，为什么不把所有的函数都定义成内联函数？如果所有的函数都是内联函数，还用得着"内联"这个关键字吗？
- 内联是以代码膨胀（复制）为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。
- 如果执行函数体内代码的时间，相比于函数调用的开销较大，那么效率的收获会很少。另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。
- 以下情况不宜使用内联：
  -（1）如果函数体内的代码比较长，使用内联将导致内存消耗代价较高。
  -（2）如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。类的构造函数和析构函数容易让人误解成使用内联更有效。要当心构造函数和析构函数可能会隐藏一些行为，如"偷偷地"执行了基类或成员对象的构造函数和析构函数。所以不要随便地将构造函数和析构函数的定义体放在类声明中。一个好的编译器将会根据函数的定义体，自动地取消不值得的内联（这进一步说明了 inline 不应该出现在函数的声明中）。
### 1.6.5 virtual虚函数可以是内联函数inline么
#### 1.6.5.1 虚函数可以是内联函数，
- 内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
- 内联是在编译器**建议**编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
#### 1.6.5.2 虚函数表现为多态时不能inline
- inline virtual 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 Base::who()），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生

### 1.6.6 内联函数和宏定义
- 宏定义在**预编译**的时候会进行宏替换；内联函数在**编译**阶段，在调用内联函数的地方进行替换，
- 内联函数相比宏定义更安全，内联函数可以**检查参数**，而宏定义只是简单的文本替换。因此推荐使用内联函数，而不是宏定义。
- 内联函数可以作为某个类的成员函数，这样可以使用类的保护成员和私有成员。而当一个表达式涉及到类保护成员或私有成员时，宏就不能实现了(无法将this指针放在合适位置)。

#### 1.6.6.1 预编译时进行宏替换
#### 1.6.6.2 内联函数编译时替换

### 1.6.7 预编译指令
  * `#`: 将变量名转化为字符串
  * `##`: 组合两个变量名连接起来形成一个新的变量
  * `@#`: 将变量名转化为字符
  * `#pragma pack(1)`: 指定 `1` 字节对齐
  * `__LINE__`: 这会在程序编译时包含当前行号
  * `__FILE__`: 这会在程序编译时包含当前文件名
  * `__DATE__`: 这会包含一个形式为 month/day/year 的字符串, 它表示把源文件转换为目标代码的日期
  * `__TIME__`: 这会包含一个形式为 hour:minute:second 的字符串, 它表示程序被编译的时间
### 1.6.8 宏
#### 1.6.8.1 '#'字符串化操作符
- `#` 表示转化为字符串

```CPP

using namespace std;
#define exp(s) printf("test s is:%s\n",s)
#define exp1(s) printf("test s is:%s\n",#s)
#define exp2(s) #s
int main()
{
    exp("hello");
    exp1(hello);

    string str = exp2(   bac );
    cout<<str<<" "<<str.size()<<endl;
    /**
     * 忽略传入参数名前面和后面的空格。
     */
    string str1 = exp2( asda  bac );
    /**
     * 当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
     * 用每个子字符串之间以一个空格连接，忽略剩余空格。
     */
    cout<<str1<<" "<<str1.size()<<endl;
    return 0;
    //test s is:hello
    //test s is:hello
    //bac 3
    //asda bac 8
}
```
#### 1.6.8.2 符号连接操作符##
-“##”是一种分隔连接方式，它的作用是先分隔，然后进行强制连接。将宏定义的多个形参转换成一个实际参数名。
- 注意事项：
  * 1.当用##连接形参时，##前后的空格可有可无。
  * 2.连接后的实际参数名，必须为实际存在的参数名或是编译器已知的宏定义。
  * 3.如果##后的参数本身也是一个宏的话，##会阻止这个宏的展开。
```cpp
#include <iostream>

using namespace std;

#define expA(s) printf("前缀加上后的字符串为:%s\n",gc_##s)  //gc_s必须存在
// 注意事项2
#define expB(s) printf("前缀加上后的字符串为:%s\n",gc_  ##  s)  //gc_s必须存在
// 注意事项1
#define gc_hello1 "I am gc_hello1"
int main() {
    // 注意事项1
    const char * gc_hello = "I am gc_hello";
    expA(hello);
    expB(hello1);
//前缀加上后的字符串为:I am gc_hello
//前缀加上后的字符串为:I am gc_hello1
}
```
#### 1.6.8.3 续行操作符\
- 当定义的宏不能用一行表达完整时，可以用”\”表示下一行继续此宏的定义。
### 1.6.9 inline总结
`inline`关键字在C++中用于指示编译器尝试将函数调用点处的函数体替换为函数的实际代码，这一过程称为内联（Inlining）。内联的主要目标是减少函数调用的开销，包括保存和恢复寄存器状态、压栈和弹栈参数等，从而提高程序的执行效率。然而，`inline`关键字本质上是一个建议而非命令，编译器可以根据优化规则和函数的大小等因素自行决定是否真正内联函数。

#### 1.6.9.1 `inline`的使用场景：

1. **小函数内联**：
   `inline`通常用于小型函数，尤其是那些频繁调用的函数，如访问器（Getters）、修改器（Setters）、转换函数和运算符重载。对于这些函数，内联可以显著减少调用开销。

2. **内联变量和命名空间**：
   自C++17起，`inline`可以用于变量和命名空间，允许在多个翻译单元中声明相同的变量或命名空间，只要它们的初始化是相同的，这有助于避免链接错误。

3. **模板函数**：
   模板函数默认是内联的，即使没有显式使用`inline`关键字。这是因为模板实例化发生在编译期，每个实例化都相当于一个独立的函数定义。

4. **控制链接性**：
   `inline`可以用于控制函数或变量的链接属性，使其在当前翻译单元内可见，从而避免在多个翻译单元中定义相同名字实体时的链接错误。

#### 1.6.9.2 `inline`的注意事项：

1. **编译器自由裁量权**：
   即使使用了`inline`关键字，编译器也有权决定是否内联函数。如果函数体过大，或者内联会导致代码膨胀，编译器可能选择不内联。

2. **代码膨胀**：
   大量使用内联可能导致二进制文件的大小显著增加，因为每次函数调用都被替换成实际的代码，而不是一个简单的跳转指令。

3. **性能权衡**：
   内联可以减少函数调用开销，但过多的内联可能会降低程序的缓存效率，因为函数代码的重复可能会导致缓存未命中率增加。

4. **调试困难**：
   大量内联可能导致调试困难，因为函数调用堆栈中的信息可能消失，使跟踪程序执行流变得更加复杂。

#### 1.6.9.3 inline结论：

`inline`关键字是C++中一个重要的优化工具，它可以帮助减少函数调用的开销，但其使用需要谨慎，以避免不必要的代码膨胀和性能下降。正确使用`inline`可以显著提升程序的性能，但过度使用则可能带来相反的效果。因此，在使用`inline`时，开发者应根据具体情况权衡其利弊。

## 1.7  sizeof(class)大小
### 1.7.1 sizeof空类的大小为?字节
```cpp
class A
{};
struct B
{};

int main()
{
    std::cout << "sizeof(empty class): " << sizeof(A) << std::endl;  // 1
    std::cout << "sizeof(empty struct): " << sizeof(B) << std::endl; // 1
    return 0;
}
// 在 C++ 中，空类或空结构的大小至少为 1 字节
```
### 1.7.2 一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都是不占用类对象的存储空间。
```cpp
#include <iostream>

class A
{
    int a;
};
// sizeof 4

class B
{
    int a;
    static int b;
    int get_normal()
    {
        return 1;
    }
};
// sizeof 4

class C
{
    int a;
    static int b;
    static int c;
    static int d;
    virtual int get_a()
    {
        return a;
    }
    int get_normal()
    {
        return 1;
    }
};
int B::b =2;
// sizeof(C) 在 64 位系统上通常是 16 字节（4 字节用于 a 和 8 字节用于虚表指针）
// 8 + 4 （ +4）
// sizeof 16
// 虚函数表指针的位置取决于具体的编译器实现
```
- 多个static变量不影响类的大小；

### 1.7.3 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
```cpp
class C
{
    int a;
    static int b;
    virtual int get_a()
    {
        return a;
    }
    int get_normal()
    {
        return 1;
    }
};
// 4 + 8
// sizeof 16

class D
{
    int a;
    virtual int get_a()
    {
        return a;
    }
    virtual int get_normal()
    {
        return 1;
    }
};
// 4 + 8
// sizeof 16
```
- 多个虚函数不影响类的大小；
### 1.7.4 普通继承，派生类继承了所有基类的函数与成员，要按照字节对齐来计算大小

```cpp

class A
{
    int  a; // 4  4   0
    char b; // 1  8   4 （+3
    int  c; // 4  12  8
    char e; // 1  16  12
};

// 16
// 4 + 1 (+3) + 4 + 1 (+3) = 16
Offset of 'a': 0
Offset of 'b': 4
Offset of 'c': 8
Offset of 'e': 12

class A1
{
    int  a; // 4  0
    char b; // 1  4
    int  c; // 4  8
    long d; // 8  16
    char e; // 1  24
};
// 32
// int char     int     long char
// 4 + 1 (+3) + 4 +(+4) + 8 + 1 (+7)
Offset of 'a': 0
Offset of 'b': 4
Offset of 'c': 8
Offset of 'd': 16
Offset of 'e': 24
32
0-3   : int a  (4 bytes)
4     : char b (1 byte)
5-7   : padding (3 bytes for alignment of next int)
8-11  : int c  (4 bytes)
12-15 : padding (4 bytes for alignment of next long)
16-23 : long d (8 bytes)
24    : char e (1 byte)
25-31 : padding (7 bytes for alignment of next possible long)
你可以看到，虽然 A1 实际上只有18个字节的数据，但由于对齐的需求，它的大小实际上是32字节。在这个例子中，对齐是以 long 类型的大小（8字节）为基准的，因此整个对象的大小必须是8的倍数。这就是为什么大小是32而不是28。
///////////////////////////////////////////
// 继承 is-a
class B: A
{
    // 4 1 4 1 = 16
    int  d1; // 4
    char e1; // 1
};
// 24
// 16 + 4 + 4
Offset of 'B.a': 0
Offset of 'B.b': 4
Offset of 'B.c': 8
Offset of 'B.e': 12
Offset of 'B.d1': 16
Offset of 'B.e1': 20
sizeof(B): 24

class B1: A1
{
    // 4 1 4 8 1
    char a; // 1
    int  b; // 4
};
// 32/40
//       int char     int      long    char + char    int
//index       4        8         16    24     32      36
//  4       + 1 (+3) + 4 +(+4) + 8    + 1 +7 + 1 (+3) +4

Offset of 'B1.a': 0
Offset of 'B1.b': 4
Offset of 'B1.c': 8
Offset of 'B1.d': 16
Offset of 'B1.e': 24
Offset of 'B1.a1': 32
Offset of 'B1.b1': 36
sizeof(B1): 40

/* if #pragma pack(1) ,
Offset of 'B1.a': 0
Offset of 'B1.b': 4
Offset of 'B1.c': 8
Offset of 'B1.d': 12
Offset of 'B1.e': 20
Offset of 'B1.a1': 24
Offset of 'B1.b1': 28
sizeof(B1): 32

*/
//////////////////////////////////////////////////
// 内含has-a A
class C
{
    A    a; // 16
    char b; // 1  20
};
// 20
// 16 + 1 (+3)
Offset of 'C.a': 0
Offset of 'C.b': 16
sizeof(C): 20

class C1
{
    char a; // 1
    A    b; // 16 20
};
// 20
// 1 (+3) + 16
Offset of 'C1.b': 4
sizeof(C1): 20

sizeof(A): 16
sizeof(B): 24
sizeof(A1): 32
sizeof(B1): 32
sizeof(C): 20
sizeof(C1): 20
```
### 1.7.5 虚函数继承，sizeof
```cpp
class A
{
public:
    int a;
    virtual int get_a()
    {
        return 2;
    }
    virtual int get_normal()
    {
        return 1;
    }
};
// 8 + 4 (+4)
// sizeof 16
sizeof(A): 8
Offset of 'B.a': 8
sizeof(B): 16
Offset of 'B1.c': 8
sizeof(B1): 16

class B: public A
{
public:
    long b;
};
// 24
// 8 + 4 (+4) + 8

class B1: public A
{
public:
    char c;
};
// 16
// 8 + 4 + 1 (+3)

int main()
{
    std::cout << "Offset of 'A.a': " << offsetof(A, a) << '\n';
    std::cout << "sizeof(A): " << sizeof(A) << std::endl;  // 8
    std::cout << "Offset of 'B.a': " << offsetof(B, a) << '\n';
    std::cout << "Offset of 'B.b': " << offsetof(B, b) << '\n';
    std::cout << "sizeof(B): " << sizeof(B) << std::endl; // 16
    std::cout << "Offset of 'B1.a': " << offsetof(B1, a) << '\n';
    std::cout << "Offset of 'B1.c': " << offsetof(B1, c) << '\n';
    std::cout << "sizeof(B1): " << sizeof(B1) << std::endl; // 16
    A instancea;
    std::cout << (char *)&instancea.a - (char *)&instancea;
    return 0;
}
Offset of 'A.a': 8
sizeof(A): 16
Offset of 'B.a': 8
Offset of 'B.b': 16
sizeof(B): 24
Offset of 'B1.a': 8
Offset of 'B1.c': 12
sizeof(B1): 16
```
- 不管是单继承还是多继承，都是继承了基类的vptr。(32位操作系统4字节，64位操作系统 8字节)！
### 1.7.6 多继承，基类的vptr都+8。

```cpp
class A
{
    int a;
    virtual int get_a()
    {
        return a;
    }
    virtual int get_normal()
    {
        return 1;
    }
};
// 8 + 4
// sizeof 16
// (gdb) p a
// $2 = {_vptr.A = 0x555555755ca8 <vtable for A+16>, a = 1431654310}
// struct A {
//        int ()(void) * *           _vptr.A;              /*     0     8 */
//        int                        a;                    /*     8     4 */
/*
Vtable for A
A::_ZTV1A: 4 entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI1A)
16    (int (*)(...))A::get_a
24    (int (*)(...))A::get_normal

Class A
   size=16 align=8
   base size=12 base align=8
A (0x0x7f6c336008a0) 0
    vptr=((& A::_ZTV1A) + 16)
*/
class B
{
public:
    virtual int get_b()
    {
        return 2;
    }
};
// 8 vptr
// struct B {
//        int ()(void) * *           _vptr.B;              /*     0     8 */
/*
(gdb) p b
$3 = {_vptr.B = 0x555555755c90 <vtable for B+16>}

Vtable for B
B::_ZTV1B: 3 entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI1B)
16    (int (*)(...))B::get_b

Class B
   size=8 align=8
   base size=8 base align=8
B (0x0x7f6c336009c0) 0 nearly-empty
    vptr=((& B::_ZTV1B) + 16)
*/
class C : A, B
{
public:
    int get_c()
    {
        return 4;
    }
};
// 24
// 16 + 8
// struct C : A, B {
        /* struct A                   <ancestor>; */     /*     0    16 */
        /* XXX last struct has 4 bytes of padding */
        /* struct B                   <ancestor>; */     /*    16     8 */
/*
(gdb) p c
$4 = {<A> = {_vptr.A = 0x555555755c58 <vtable for C+16>, a = 65535}, <B> = {_vptr.B = 0x555555755c78 <vtable for C+48>}, <No data fields>}
Vtable for C
C::_ZTV1C: 7 entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI1C)
16    (int (*)(...))A::get_a
24    (int (*)(...))A::get_normal
32    (int (*)(...))-16
40    (int (*)(...))(& _ZTI1C)
48    (int (*)(...))B::get_b

Class C
   size=24 align=8
   base size=24 base align=8
C (0x0x7f6c33628230) 0
    vptr=((& C::_ZTV1C) + 16)
  A (0x0x7f6c33600a80) 0
      primary-for C (0x0x7f6c33628230)
  B (0x0x7f6c33600ae0) 16 nearly-empty
      vptr=((& C::_ZTV1C) + 48)
*/
class D : A, B
{
public:
    virtual int get_d()
    {
        return 5;
    }
};
// 24
// 16 + 8
// struct D : A, B {
        /* struct A                   <ancestor>; */     /*     0    16 */
        /* XXX last struct has 4 bytes of padding */
        /* struct B                   <ancestor>; */     /*    16     8 */
/*
(gdb) p d
$6 = {<A> = {_vptr.A = 0x555555755c18 <vtable for D+16>, a = 1431654781}, <B> = {_vptr.B = 0x555555755c40 <vtable for D+56>}, <No data fields>}
(gdb) info vtbl d
vtable for 'D' @ 0x555555755c18 (subobject @ 0x7fffffffe390):
[0]: 0x555555554fbe <A::get_a()>
[1]: 0x555555554fd0 <A::get_normal()>
[2]: 0x555555554ff0 <D::get_d()>

vtable for 'B' @ 0x555555755c40 (subobject @ 0x7fffffffe3a0):
[0]: 0x555555554fe0 <B::get_b()>

Vtable for D
D::_ZTV1D: 8 entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI1D)
16    (int (*)(...))A::get_a
24    (int (*)(...))A::get_normal
32    (int (*)(...))D::get_d
40    (int (*)(...))-16
48    (int (*)(...))(& _ZTI1D)
56    (int (*)(...))B::get_b

Class D
   size=24 align=8
   base size=24 base align=8
D (0x0x7f6c33628310) 0
    vptr=((& D::_ZTV1D) + 16)
  A (0x0x7f6c33600ba0) 0
      primary-for D (0x0x7f6c33628310)
  B (0x0x7f6c33600c00) 16 nearly-empty
      vptr=((& D::_ZTV1D) + 56)
*/
class E : virtual A, virtual B
{
public:
    virtual int get_e()
    {
        return 5;
    }
};
// 24
/*
(gdb) p e
$7 = {<A> = {_vptr.A = 0x555555755be0 <vtable for E+88>, a = -6992}, <B> = {_vptr.B = 0x555555755bb0 <vtable for E+40>}, <No data fields>}
(gdb) info vtbl e
vtable for 'E' @ 0x555555755bb0 (subobject @ 0x7fffffffe3b0):
[0]: 0x555555554fe0 <B::get_b()>
[1]: 0x555555555000 <E::get_e()>

vtable for 'A' @ 0x555555755be0 (subobject @ 0x7fffffffe3b8):
[0]: 0x555555554fbe <A::get_a()>
[1]: 0x555555554fd0 <A::get_normal()>
*/
//  struct E : virtual A, virtual B {
        /* --- cacheline 67108863 boundary (4294967232 bytes) was 63 bytes ago --- */
        /* struct A                   <ancestor>; */     /* 4294967295    16 */
        /* XXX last struct has 4 bytes of padding */
        /* struct B                   <ancestor>; */     /* 4294967295     8 */
(gdb) info vtbl e
vtable for 'E' @ 0x555555755bb0 (subobject @ 0x7fffffffe3b0):
[0]: 0x555555554fe0 <B::get_b()>
[1]: 0x555555555000 <E::get_e()>

vtable for 'A' @ 0x555555755be0 (subobject @ 0x7fffffffe3b8):
[0]: 0x555555554fbe <A::get_a()>
[1]: 0x555555554fd0 <A::get_normal()>
(gdb) p e
$10 = {<A> = {_vptr.A = 0x555555755be0 <vtable for E+88>, a = -6992}, <B> = {_vptr.B = 0x555555755bb0 <vtable for E+40>}, <No data fields>}
(gdb)
```
### 1.7.8 内存对齐指定字节
* `#pragma pack(1)`: 指定 `1` 字节对齐

## 1.8 assert
### 1.8.0 assert

断言，宏，而非函数
```cpp
#define NDEBUG          // 加上这行，则 assert 不可用
```
assert 是一种在 C 和 C++ 中常用的宏，它被用来进行条件测试，并在条件不满足（即为 false）时终止程序。

assert 宏的作用是帮助程序员找出程序中的逻辑错误。当 assert 的条件不满足时，程序会立即停止，并输出一条包含文件名和行号信息的错误消息，这对于快速定位和修复问题很有帮助。

以下是使用 assert 的一个例子：

```c++
#include <cassert>

void foo(int x) {
    assert(x > 0);  // 如果 x 不大于 0，程序将在此处停止并输出错误消息
    // ... 其他代码 ...
}

int main() {
    foo(-1);  // 这会触发 assert，并终止程序
    return 0;
}
```
在这个例子中，如果 foo 函数的参数不大于 0，assert 将触发，并导致程序停止运行。这是一种保证函数预期行为的有效方式。

然而，需要注意的是，在发布的最终产品中，一般会禁用 assert。这是通过在包含 cassert 或 assert.h 之前定义 NDEBUG 宏来实现的。因此，你不应该依赖 assert 来进行程序的流程控制，而应该只在调试和开发阶段使用它来捕获和修复错误。
## 1.9 位域
### 1.9.0 位域

Bit field
“ 位域 “ 或 “ 位段 “(Bit field)为一种数据结构，
- 可以把数据以位的形式紧凑的储存，并允许程序员对此结构的位进行操作
- 位域的类型必须是整型或枚举类型，带符号类型中的位域的行为将因具体实现而定
- 取地址运算符（&）不能作用于位域，任何指针都无法指向类的位域

### 1.9.1 位域优点
#### 1.9.1.1 节省空间
这种数据结构的一个好处是它可以使数据单元节省储存空间，当程序需要成千上万个数据单元时，这种方法就显得尤为重要。
#### 1.9.1.2 方便访问
第二个好处是位段可以很方便的访问一个整数值的部分内容从而可以简化程序源代码。
### 1.9.2 位域缺点
#### 1.9.2.1 依赖平台，不可移植
而这种数据结构的缺点在于，位段实现依赖于具体的机器和系统，在不同的平台可能有不同的结果，这导致了位段在本质上是不可移植的。

## 1.10 struct结构体
### 1.10.1 C中struct
#### 1.10.1.1 数据复合，不能加函数
- 在C中struct只单纯的用作数据的复合类型，也就是说，在结构体声明中只能将数据成员放在里面，而不能将函数放在里面。

```cpp
struct C
{
    //int printa();
    //struct_inc.c:14:9: error: field ‘printa’ declared as a function

    //int printa()
    //{
    //    return 0;
    //}
    //struct_inc.c:17:5: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘{’ token
};
```
#### 1.10.1.2 不能使用C++ public修饰符
- 在C结构体声明中不能使用C++访问修饰符，如：public、protected、private 而在C++中可以使用。
```cpp
struct D
{
//public:
    //struct_inc.c:26:1: error: expected specifier-qualifier-list before ‘public’
    int a;
};
```
#### 1.10.1.3 struct变量如果使用需要加struct
- 在C中定义结构体变量，如果使用了下面定义必须加struct。
```cpp
int main()
{
    printf("sizeof(A):%ld\n", sizeof(struct A)); // 0
    printf("sizeof(B):%ld\n", sizeof(struct B)); // 4

    A();
    //printf("sizeof(D):%ld\n", sizeof( D)); // 4
    //struct_inc.c:35:39: error: ‘D’ undeclared (first use in this function)
    return 0;
}
```
#### 1.10.1.4 不能继承
- C的结构体不能继承（没有这一概念）。
```cpp
//struct C: struct B
        // struct_inc.c:12:9: error: expected identifier or ‘(’ before ‘:’ token
```
#### 1.10.1.5 结构体同名的函数不冲突
- 若结构体的名字与函数名相同，可以正常运行且正常的调用！例如：可以定义与 struct Base 不冲突的 void Base() {}。

```cpp
struct A
{
};

int A()
{
    printf("A() 10");
}

int main()
{
    printf("sizeof(A):%ld\n", sizeof(struct A)); // 0
    A();
}
```

### 1.10.2 C++中的struct
#### 1.10.2.1 C++结构体中不仅可以定义数据，还可以定义函数。（可以有构造函数）
```cpp
struct C
{
    int printa();

    int printb()
    {
        return 0;
    }
};

printf("sizeof(C):%ld\n", sizeof( C)); // 1

```
#### 1.10.2.2 C++结构体中可以使用访问修饰符，如：public、protected、private 。
```cpp
struct D
{
public:
    int a;
private:
    char b;
};

    printf("sizeof(D):%ld\n", sizeof( D)); // 8
```
#### 1.10.2.3 C++结构体使用可以直接使用不带struct。
```cpp
    printf("sizeof(A):%ld\n", sizeof(struct A)); // 0
    printf("sizeof(B):%ld\n", sizeof(struct B)); // 4

    printf("sizeof(C):%ld\n", sizeof( C)); // 1
    printf("sizeof(D):%ld\n", sizeof( D)); // 8
```
#### 1.10.2.4 C++继承
```cpp
struct E: public D
{
};

struct F: private D
{
};

    printf("sizeof(E):%ld\n", sizeof( E)); // 8
    printf("sizeof(F):%ld\n", sizeof( F)); // 8
```
#### 1.10.2.5 结构体同名的函数不冲突
若结构体的名字与函数名相同，可以正常运行且正常的调用！但是定义结构体变量时候只能用带struct的！
##### 1.10.2.5.1  有同名函数后，定义结构体变量需添加struct关键字
```cpp
    A();
    //A a;
    //struct_incpp.cpp:55:7: error: expected ‘;’ before ‘a’
    struct A a;
```
##### 1.10.2.5.2 typedef后，不能再创建同名函数
```cpp
typedef struct B
{
    int b;
}B1;

int B1()
{
    printf("func A() 10\n");
}
//error: ‘int B1()’ redeclared as different kind of symbol
```
- error! 符号 "B1" 已经被定义为一个 "struct B" 的别名

### 1.10.3 c/c++ struct 区别
|                        C                         |                           C++                            |
| ------------------------------------------------ | -------------------------------------------------------- |
| 不能将函数放在结构体声明                            | 	能将函数放在结构体声明                                   |
| 在C结构体声明不能使用C++访问修饰符。                | 	public、protected、private 在C++中可以使用。           |
| 在C中定义结构体变量，如果使用了下面定义必须加struct。 | 	可以不加struct                                         |
| 结构体不能继承（没有这一概念）。                    | 	可以继承                                              |
| 若结构体的名字与函数名相同，可以正常运行且正常的调用！ | 若结构体的名字与函数名相同，使用结构体，只能使用带struct定义！ |

## 1.11 struct 和class
### 1.11.1 struct 和class继承访问权限
- 可以用struct和class定义类，都可以继承。
- structural的默认继承权限和默认访问权限是public，而class的默认继承权限和默认访问权限是private。
### 1.11.2 struct 和class 数据成员访问权限
struct默认public，class默认private；
### 1.11.3 struct 和class: class还可以定义模板类形参，比如template
在 C++ 中，模板参数可以是类、函数、基本类型或者模板。当你创建模板时，如果要使用某种类型（无论是类、结构、基本类型等）作为模板参数，你只需要写 typename T 或者 class T，并不需要显式写出 struct。
在这里，T 可以是任何类型，包括 int、std::string 或者其他你定义的结构或类。所以你并不需要在模板声明中写出 struct T，只需要写 typename T 或者 class T 即可。
```cpp
template<class T>
struct A
{
    T a;
};

template<typename T>
struct B
{
    T a;
};

template<class T>
class C
{
    T a;
};

template<typename T>
class D
{
    T a;
};

template<struct T>
//template.cpp:27:17: error: ‘struct T’ is not a valid type for a template non-type parameter
class E
{
    T a;
};

template<struct T>
//template.cpp:34:17: error: ‘struct T’ is not a valid type for a template non-type parameter
struct F
{
    T a;
};
```
## 1.12 union 联合体
### 1.12.1 union 联合体 定义
联合（union）是一种节省空间的特殊的类，一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。
使用 union 语句，方式与定义结构类似。union 语句定义了一个新的数据类型，带有多个成员。union 语句的格式如下：
```cpp
union [union tag]
{
   member definition;
   member definition;
   ...
   member definition;
} [one or more union variables];
```
- 可以根据需要在一个共用体内使用任何内置的或者用户自定义的数据类型。
- 共用体占用的内存应足够存储共用体中最大的成员。
### 1.12.2 union 联合体 访问
- 使用成员访问运算符（.）
### 1.12.3 union 联合体 特点
#### 1.12.3.1 默认访问控制符为 public
```cpp
union A
{
    int a;
public:
    char b[20];
protected:
    char c[4];
private:
    double d=0.0;
};
```
#### 1.12.3.2 可以含有构造函数、析构函数
```cpp
union A
{
    A(){std::cout << "Construct union" << std::endl;}
    ~A(){std::cout <<"Destrator union" << std::endl;}
}
```
#### 1.12.3.2 不能含有引用类型的成员

```cpp
int global_a =10;
int &reference = global_a;

union A
{
    int a;
    //int &reference2 = global_a;
    //union.test.cpp:10:23: error: non-static data member ‘A::reference2’ in a union may not have reference type ‘int&’
}
```

#### 1.12.3.3 不能继承自其他类，不能作为基类
```cpp
class F{};

union G: F{};
// error: derived union ‘G’ invalid
```
#### 1.12.3.4 不能含有虚函数
```cpp
union A
{
    //virtual int printa(){std::cout << "a:" <<  a;}
    //union.test.cpp:11:24: error: function ‘printa’ declared ‘virtual’ inside a union
}
```
#### 1.12.3.5 匿名 union 在定义所在作用域可直接访问 union 成员
```cpp
struct E
{
    int a;
    //int e;
    union
    {
        int e;
        // 不能和已有成员同名
        // error: redeclaration of ‘int E::<unnamed union>::e’
        char f[10];
    };
}E;

    struct E u3;
    strcpy( u3.f ,"789");
    std::cout << "u3.e: " << u3.e << std::endl;
    std::cout << "u3.f: " << u3.f << std::endl;

```
#### 1.12.3.6 匿名 union 不能包含 protected 成员或 private 成员
```cpp
struct E
{
    int a;
    //int e;
    union
    {
        protected:
        // error: protected member ‘int E::<unnamed union>::e’ in anonymous union [-fpermissive]
        int e;

        private:
        // error: private member ‘char E::<unnamed union>::f [10]’ in anonymous union [-fpermissive]
        char f[10];
    };
}E;
```
#### 1.12.3.7 全局匿名联合必须是静态（static）的
```cpp
static union
{
    int a;
};
int main()
{
    std::cout << "static unnamed union :: a:" << a << std::endl;
}
```
```cpp
static union
{
    int a = 20;
};
int main()
{
    std::cout << "static unnamed union :: a:" << a << std::endl;
}
```
```cpp
union
{
    int b = 30;
    // error: namespace-scope anonymous aggregates must be static
};
```

## 1.13 explicit 显式
### 1.13.1 explicit 修饰构造函数时，可以防止隐式转换和复制初始化

```cpp
#include <iostream>

class A
{
public:
    A(int){std::cout<<"Constructor A"<<std::endl;};
    operator bool() const { std::cout <<"bool A to true"<< std::endl;return true; }
};

class B
{
public:
    explicit B(int){std::cout<<"Constructor B"<<std::endl;};
    explicit operator bool() const { std::cout << "bool B to true" <<std::endl;return true; }
};

void funcA(A a ){}
void funcB(B b ){}

int main()
{
    //A a0;
    // error: no matching function for call to ‘A::A()’
    A a1(1);
    A a2 = 1;
    A a3{1};
    A a4 = {1};
    A a5 = (A)1;
    funcA(1);
    if(a1);
    bool bool6 (a1);
    bool bool7 = a1;
    bool bool8 = static_cast<bool>(a1);

    //B b0;
    // error: no matching function for call to ‘B::B()’
    B b1(1);
    //B b2 = 2;
    // error: conversion from ‘int’ to non-scalar type ‘B’ requested
    B b3{1};
    //B b4 = {1};
    // error: converting to ‘B’ from initializer list would use explicit constructor ‘B::B(int)’
    B b5 = (B)1;
    //funcB(1);
    // error: could not convert ‘1’ from ‘int’ to ‘B’
    if (b1);
    bool bool9 (b1);
    //bool bool10 = b1;
    //  error: cannot convert ‘B’ to ‘bool’ in initialization
    bool bool11 = static_cast<bool>(b1);

    return 0;
}
```
### 1.13.2 explicit 修饰转换函数时，可以防止隐式转换，但按语境转换除外

## 1.14 friend友元
### 1.14.0 friend友元
友元提供了一种 普通函数或者类成员函数 访问另一个类中的私有或保护成员 的机制。也就是说有两种形式的友元：
（1）友元函数：普通函数对一个访问某个类中的私有或保护成员。
（2）友元类：类A中的成员函数访问类B中的私有或保护成员
优点：提高了程序的运行效率。
缺点：破坏了类的封装性和数据的透明性
### 1.14.1 友元函数
在类声明的任何区域中声明，而定义则在类的外部。
```cpp
#include <iostream>

class A
{
public:
    A(int i):a(i){};
    friend int friendgeta(A &a); // 友元函数声明
private:
    int a;
};

int friendgeta(A &instance) // 友元函数定义
{
    return instance.a;
}

int geta(A &instance)
{
    return 0;
    //return instance.a;
    // error: ‘int A::a’ is private within this context
}

int main()
{
    A a1(3);
    // std::cout << a1.a << std::endl;
    // error: ‘int A::a’ is private within this context
    std::cout << friendgeta(a1) << std::endl;
    return 0;
}
```
- 因为友元函数没有this指针，则参数要有三种情况：
  * 要访问非static成员时，需要对象做参数；
  * 要访问static成员或全局变量时，则不需要对象做参数；
  * 如果做参数的对象是全局对象，则不需要对象做参数.
- 可以直接调用友元函数，不需要通过对象或指针

### 1.14.2 友元类
友元类的声明在该类的声明中，而实现在该类外
```cpp
#include <iostream>

class A
{
public:
    A(int i):a(i){};
    friend class B; // 友元类
private:
    int a;
};

class B
{
public:
    int friendclassgeta(A &instance) // 友元类可以访问私有成员
    {
        return instance.a;
    }
};

class C
{
    int classgeta(A &instance)
    {
        return 0;
        //return instance.a;
        // error: ‘int A::a’ is private within this context
    }
};

int main()
{
    A a1(5);
    // std::cout << a1.a << std::endl;
    // error: ‘int A::a’ is private within this context
    B b;
    C c;
    std::cout << b.friendclassgeta(a1) << std::endl;
    // std::cout << c.classgeta(a1) << std::endl;
    // error: ‘int C::classgeta(A&)’ is private within this context
    return 0;
}
```
## 1.15 using使用
### 1.15.1 using 局部和全局使用
```cpp
using namespace::std;
// global
void func()
{
    std::cout<<"::func"<<std::endl;
}

namespace ns1
{
    void func()
    {
        std::cout<<"ns1::func"<<std::endl;
    }
}

namespace ns2
{
    using ns1::func;
}

namespace ns3
{
    using ::func;
}

int main()
{
    ns2::func();
    ns3::func();
    return 0;
}
```
- 使用using指定不同命名空间；

### 1.15.2 using 改变访问性
- 使用using可改变不同访问权限

```cpp
using namespace std;

class Base1
{
public:
    Base1():value(10),value2(25) {}
    virtual ~Base1() {}
    void test1() { cout << "Base test1..." << endl; }
protected: // 保护
    int value;
private:
    int value2;
};
// 默认为私有继承
class Derived1 : Base1
{
public:
    void test2() { cout << "protected value is " << value << endl; }
    //void test3() { cout << "private   value2 is " << value2 << endl;}
    //derived_base_using.cpp:21:54: error: ‘int Base1::value2’ is private within this context
};

class Base
{
public:
    Base():value(20),value2(25) {}
    virtual ~Base() {}
    void test1() { cout << "Base test1..." << endl; }
protected:  //私有
    int value;
    int value2;
};

/**
 * 子类对父类成员的访问权限跟如何继承没有任何关系，
 * “子类可以访问父类的public和protected成员，不可以访问父类的private成员”——这句话对任何一种继承都是成立的。
 *
 */
class Derived : Base
{
public:
    //using Base::value;
    using Base::value2;
    void test2() { cout << "protected value is " << value << endl; }
    void test3() { cout << "private   value2 is " << value2 << endl;}
private:
    using Base::value;
};


int main()
{
    Derived1 d1;
    d1.test2();

    Derived d;
    d.test2();
    d.test3();
    std::cout << "using public value2 "<< d.value2 << std::endl;
    std::cout << "using public value "<< d.value << std::endl;
    //derived_base_using.cpp:62:44: error: ‘int Base::value’ is protected within this context
    return 0;
}
```
### 1.15.3 using 函数重载
```cpp
class Base
{
public:
    void f(){ cout<<"f()"<<endl;}
    void f(int n)
    {
        cout<<"Base::f(int)"<<endl;
    }
};

class Derived : private Base
{
public:
    using Base::f;
    void f(int n)
    {
        cout<<"Derived::f(int)"<<endl;
    }
};

int main()
{
    Base b;
    Derived d;
    d.f();
    // 没有using Base::f的情况下，
    //overload_using.cpp:28:9: error: no matching function for call to ‘Derived::f()’
    // 一旦定义了一个重载版本，那么其他的重载版本都会变为不可见
    d.f(1);
    return 0;
}
```
- 在派生类中使用using声明语句指定一个名字而不指定形参列表，所以一条基类成员函数的using声明语句就可以把该函数的所有重载实例添加到派生类的作用域中。此时，派生类只需要定义其特有的函数就行了，而无需为继承而来的其他函数重新定义。

### 1.15.4 using取代typedef
- 可以使用using取代typedef进行别名定义

```cpp
typedef vector<int> V1;
using V2 = vector<int>;


int main()
{
    int nums1[] = {1,2,3,4,5,6};
    V1 vec1(nums1,nums1+sizeof(nums1)/sizeof(int));
    int nums2[] = {5,7,6};
    V2 vec2(nums2,nums2+sizeof(nums2)/sizeof(int));

    for(auto i:vec1)
        cout<<i<<" ";
    cout<<endl;

    for(auto i:vec2)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
```
## 1.16 作用域符::
### 1.16.0 作用域符::
```cpp
#include <iostream>
using namespace std;

int count=0;    // 全局(::)的count

class A
{
public:
    static int count;  // 类A的count (A::count)
};
// 静态变量必须在此处定义
int A::count;

namespace ns1
{
    int count = 6;
}
int main()
{
    int count=3; // 局部count
    cout<<"count " << count<<endl;
    count=4;     // 设置局部的count为4
    cout<<"count " << count<<endl;

    ::count=1; // 设置全局的count为1
    A::count=5; // 设置类A的count为2
    cout<<"::count " << ::count<<endl;
    cout<< "A::count " << A::count<<endl;

    cout<< "ns1::count " << ns1::count<<endl;
    ns1::count = 7;
    cout<< "ns1::count " << ns1::count<<endl;
    return 0;
}
```
#### 1.16.1 作用域符::全局
- count = 0 使用::count 操作
#### 1.16.2 作用域符::类作用
- A::count 类作用域内的count
#### 1.16.3 作用域符::命名空间
- ns1::count 进行控制

## 1.17 enum枚举
### 1.17.1 enum枚举：传统行为,不能命名冲突
```
enum Color {RED,BLUE};
enum Feeling {EXCITED,BLUE};
// error: redeclaration of ‘BLUE’
```
- 会隐式转换为int
- 用来表征枚举变量的实际类型不能明确指定，从而无法支持枚举类型的前向声明。
### 1.17.2 enum枚举 经典做法
#### 1.17.2.1 修改变量名加前缀

```cpp
// 1. Add prefix
enum Color_
{
    Color_RED,
    Color_Blue
};

enum Feeling_
{
    Feeling_EXCITED,
    Feeling_BLUE
};

// 1.prefix
    std::cout << "Color_Blue : " << Color_Blue << std::endl;
```
#### 1.17.2.2 增加命名空间
```cpp
// 2.namespace
namespace Color
{
    enum Type
    {
        RED=15,
        YELLOW,
        BLUE
    };
};
// using namespce Color 可以减少前缀

// 2.namespace
    std::cout << "Color::BLUE : " << Color::BLUE << std::endl;
    //  定义新的枚举变量
    Color::Type nstype = Color::RED;
    std::cout << "namespace:: nstype :" << nstype<< std::endl;
```
#### 1.17.2.3 封装到结构体或类中
```cpp
//3.struct /class
struct Color1
{
    enum Type
    {
        RED=102,
        YELLOW,
        BLUE
    };
};

class Color2
{
public:
    enum Type
    {
        RED=202,
        YELLOW,
        BLUE
    };
};

// 3.struct/class
    std::cout << "Color1::BLUE : " << Color1::BLUE << std::endl;
    std::cout << "Color1::Type::BLUE : " << Color1::Type::BLUE << std::endl;

    std::cout << "Color2::BLUE : " << Color2::BLUE << std::endl;
    std::cout << "Color2::Type::BLUE : " << Color2::Type::BLUE << std::endl;

    Color1 s1;
    std::cout << "s1.BLUE : " << s1.BLUE << std::endl;
    std::cout << "s1.YELLOW: " << s1.YELLOW <<  std::endl;
    std::cout << "s1.Type::BLUE : " << s1.Type::BLUE << std::endl;

    Color1::Type s2 = Color1::RED;
    std::cout << "s2: " << s2 <<  std::endl;


    Color2 c2;
    std::cout << "c2.BLUE : " << c2.BLUE << std::endl;
    std::cout << "c2.Type::BLUE : " << c2.Type::BLUE << std::endl;
```
### 1.17.3 C++11枚举类
- C++11 标准中引入了“枚举类”(enum class)
  * 新的enum的作用域不在是全局的
  * 不能隐式转换成其他类型
  * 可以指定用特定的类型来存储enum

```cpp
// * 下面等价于enum class Color2:int
enum class Color2
{
    RED=2,
    YELLOW,
    BLUE
};

enum class Color3:char;  // 前向声明

// 定义
enum class Color3:char
{
    RED='r',
    BLUE
};

int main()
{
    Color2 c2 = Color2::RED;
    //std::cout<<c2<<std::endl;
    // 不能直接输出
    std::cout << static_cast<int>(c2) << std::endl;

    char c3 = static_cast<char>(Color3::RED);
    std::cout<<c3<<std::endl;
    return 0;
}
```
### 1.17.4 类中枚举类型
```cpp
class A
{
public:
    enum
    {
        BOY=0,
        GILR
    }SexType;
};


class B
{
public:
    enum: char
    {
        BOY='0',
        GILR
    }SexType;
};
int main()
{
    std::cout << sizeof(A) << std::endl; // 4
    std::cout << sizeof(B) << std::endl; // 1
    return 0;
}
```
枚举常量不会占用对象的存储空间，它们在编译时被全部求值。
枚举常量的缺点是：它的隐含数据类型是整数，其最大值有限，且不能表示浮点

## 1.18 decltype
### 1.18.0 decltype 是什么？
`decltype (expression)`
- decltype，在C++中，作为操作符，用于查询表达式的数据类型。
- decltype在C++11标准制定时引入，主要是为泛型编程而设计，以解决泛型编程中，由于有些类型由模板参数决定，而难以（甚至不可能）表示之的问题。
- decltype 仅仅“查询”表达式的类型，并不会对表达式进行“求值”。

### 1.18.1 decltype使用
#### 1.18.1.1 推导出表达式类型
```cpp
int getsize();

    // 1. expression
    int i =2;
    // i为int，a为int
    decltype(i) a;
    std::cout << typeid(a).name() << std::endl;
    //b 为int，getsize()没有定义，但是正常。因为decltype只做分析，并不调用getSize().
    decltype(getsize()) b;
    std::cout << typeid(b).name() << std::endl;
```
#### 1.18.1.2 与using/typedef合用，用于定义类型
```cpp
    // 2.using/typedef
    using size_t = decltype(sizeof(0));//sizeof(a)的返回值为size_t类型
    using ptrdiff_t = decltype((int*)0 - (int*)0);
    using nullptr_t = decltype(nullptr);

    nullptr_t  nu;
    int * p =NULL;
    if(p==nu)
    {
        std::cout<<"NULL"<<std::endl;
    }

    int nums[] = {1,2,3,4};
    std::vector<int >vec(nums, nums+4);

    // iterator
    std::vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    //decltype
    typedef decltype(vec.begin()) vectype;
    for (vectype i = vec.begin(); i != vec.end(); i++)
    {
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
```
#### 1.18.1.3 重用匿名类型
```cpp
    // 3.anonymous
    struct
    {
        int d;
        double b;
    }anony_st;

    //anony_st as1;
    // usage_decltype.cpp:54:14: error: expected ‘;’ before ‘as1’
    decltype(anony_st) as;
```
#### 1.18.1.4 结合auto，用于追踪函数的返回值类型
```cpp
template <typename T>
auto multiply(T x, T y)->decltype(x*y)
{
    return x*y;
}
//  泛型编程中结合auto，用于追踪函数的返回值类型

    // 4.
    std::cout<<multiply(11,2)<<std::endl;
```

### 1.18.2 decltype 与其他类型结合(const/reference/pointer)
- auto推断时会实际执行，decltype不会执行，只做分析。总之在使用中过程中和const、引用和指针结合时需要特别小心。

[decltype关键字-龙心纹](https://www.cnblogs.com/ghbjimmy/p/10636030.html)
#### 1.18.2.1 与const结合
- auto忽略顶层const，decltype保留顶层const；
```cpp
    double tempA = 3.0;
    const double ctempA = 5.0;
    const double ctempB = 6.0;
    const double *const cptrTempA = &ctempA;

    // 1.dclTempA推断为const double（保留顶层const，此处与auto不同）
    decltype(ctempA) dclTempA = 4.1;

    // 2.dclTempA为const double，不能对其赋值，编译不过
    //dclTempA = 5;
    // error: assignment of read-only variable ‘dclTempA’

    // 3.dclTempB推断为const double * const
    decltype(cptrTempA) dclTempB = &ctempA;

    //4.输出为4(32位),8(64位)和5
    std::cout<<sizeof(dclTempB)<<"    "<<*dclTempB<<std::endl;
    // 8 5

    // 5.保留顶层const，不能修改指针指向的对象，编译不过
    //dclTempB = &ctempB;
    // error: assignment of read-only variable ‘dclTempB’

    // 6.保留底层const，不能修改指针指向的对象的值，编译不过
    //*dclTempB = 7.0;
    // error: assignment of read-only location ‘*(const double*)dclTempB’
```
#### 1.18.2.2 与reference结合
- 对引用操作，auto推断出原有类型，decltype推断出引用；
- 对解引用操作，auto推断出原有类型，decltype推断出引用；

```cpp
int tempA = 0, &refTempA = tempA;

    // 1.dclTempA为引用，绑定到tempA
    decltype(refTempA) dclTempA = tempA;

    // 2.dclTempB为引用，必须绑定到变量，编译不过
    //decltype(refTempA) dclTempB = 0;
    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

    // 3.dclTempC为引用，必须初始化，编译不过
    //decltype(refTempA) dclTempC;
    // error: ‘dclTempC’ declared as reference but not initialized

    // 4.双层括号表示引用，dclTempD为引用，绑定到tempA
    decltype((tempA)) dclTempD = tempA;

    const int ctempA = 1, &crefTempA = ctempA;

    // 5.dclTempE为常量引用，可以绑定到普通变量tempA
    decltype(crefTempA) dclTempE = tempA;

    // 6.dclTempF为常量引用，可以绑定到常量ctempA
    decltype(crefTempA) dclTempF = ctempA;

    // 7.dclTempG为常量引用，绑定到一个临时变量
    decltype(crefTempA) dclTempG = 0;

    // 8.dclTempH为常量引用，必须初始化，编译不过
    //decltype(crefTempA) dclTempH;
    // error: ‘dclTempH’ declared as reference but not initialized

    // 9.双层括号表示引用,dclTempI为常量引用，可以绑定到普通变量tempA
    decltype((ctempA))  dclTempI = ctempA;
```
#### 1.18.2.3 与指针结合
```cpp
    int tempA = 2;
    int *ptrTempA = &tempA;
    /*1.常规使用dclTempA为一个int *的指针*/
    decltype(ptrTempA) dclTempA;
    /*2.需要特别注意，表达式内容为解引用操作，dclTempB为一个引用，引用必须初始化，故编译不过*/
    decltype(*ptrTempA) dclTempB;
    // error: ‘dclTempB’ declared as reference but not initialized
```
[C++11特性：decltype关键字-melonstreet](https://www.cnblogs.com/QG-whz/p/4952980.html)

## 1.19 C++智能指针及其简单实现
### 1.19.0 C++智能指针 是什么？

- 智能指针的作用是管理一个指针，因为存在以下这种情况：
- 申请的空间在函数结束时忘记释放，造成内存泄漏。使用智能指针可以很大程度上的避免这个问题，因为智能指针就是一个类，当超出了类的作用域是，类会自动调用析构函数，析构函数会自动释放资源。所以智能指针的作用原理就是在函数结束时自动释放内存空间，不需要手动释放内存空间。

### 1.19.1. auto_ptr（c++98的方案，cpp11已经抛弃）

```cpp
#include <memory>
// 有一个类A
class A
{
public:
    A(int x = 0) :a(x)
    {
        std::cout << "A Ctor:" << a << std::endl;
    }
    ~A()
    {
        std::cout << "A Dtor:" << a << std::endl;
    }
    void print() const
    {
        std::cout << a << std::endl;
    }
private:
    int a;
};
```
#### 1.19.1.1 auto_ptr类模板，自动调用析构函数
- 是C++标准库提供的类模板，auto_ptr对象通过初始化指向由new创建的动态内存，它是这块内存的拥有者，一块内存不能同时被分给两个拥有者。当auto_ptr对象生命周期结束时，其析构函数会将auto_ptr对象拥有的动态内存自动释放
```CPP
int func1_ctor()
{
    std::cout << "int func1_ctor()" << std::endl;
    A * pa = new A(10);
    pa->print();

    std::auto_ptr<A> autpa (new A(20));
    autpa->print();
    return 0;
    //int func1_ctor()
    //A Ctor:10
    //A::print:10
    //
    //A Ctor:20
    //A::print:20
    //A Dtor:20
    //
    // auto_ptr can Dtor
}
// 自动释放autpa调用Dtor，pa则未析构
```
#### 1.19.1.2 auto_ptr赋值，所有权模式(潜在内存崩溃)
 - 初始化可以赋空值
 - 采用所有权模式。
   - autpb剥夺了autpa的所有权，但是当程序运行时访问autpa将会报错。所以auto_ptr的缺点是：存在潜在的内存崩溃问题！

```cpp
int func2_assign()
{
    std::cout << "int func2_assign()" << std::endl;
    std::auto_ptr<A> autpa (new A(20));
    std::cout << "autpb: " << std::endl;
    std::auto_ptr<A> autpb;
    // 赋值
    autpb = autpa;
    autpb->print();
    return 0;
    // int func2_assign()
    // A Ctor:20
    // autpb:
    // autpa.get() :0
    // autpb.get() :0x56044fee92a0
    // A::print:20
    // A Dtor:20
    //
    // Only one 20 Dtor
}
// 通过 赋值 =， 转移autpa所有权到autpb，autpa get为0，只析构一次；
```

#### 1.19.1.3 auto_ptr拷贝赋值，所有权模式(潜在内存崩溃)
```cpp
int func3_copy()
{
    std::cout << "int func3_copy()" << std::endl;
    // 拷贝, 转移所有权
    std::auto_ptr<A> autpc (new A(25));
    std::auto_ptr<A> autpd(autpc);     // move to autpd
    autpd->print();
    std::cout << autpc.get()<< std::endl;
    std::cout << autpd.get()<< std::endl;
    // Re use autpa
    //autpa->print();
    // [1]    7771 segmentation fault  ./autoptr

    return 0;
    // int func3_copy()
    // A Ctor:25
    // A::print:25
    // 0
    // 0x561fd01a92a0
    // A Dtor:25
}
    // 使用autoptr构造另一个autoptr，也会发生所有权转移，再次使用时可能会发生崩溃
```

#### 1.19.1.4 auto_ptr指向同一个对象，析构混乱
```cpp
int func4_same()
{
    std::cout << "int func4_same()" << std::endl;
    std::cout << "same:" << std::endl;
    A * pc = new A(30);
    std::auto_ptr<A> ap1(pc);
    std::auto_ptr<A> ap2(pc);
    // 1.get
    std::cout << "the adress of pc: "<< pc << std::endl;
    std::cout << "the adress of ap1: " << &ap1 << std::endl;
    std::cout << "the adress of the object which ap1 point to: " << ap1.get() << std::endl;
    std::cout << "the adress of the object which ap2 point to: " << ap2.get() << std::endl;
    ap1->print();
    ap2->print();
    return 0;
    // int func4_same()
    // same:
    // A Ctor:30
    // the adress of pc: 0x5617e89e62a0
    // the adress of ap1: 0x7ffd6f1f62d0
    // the adress of ap2: 0x7ffd6f1f62d8
    // the adress of the object which ap1 point to: 0x5617e89e62a0
    // the adress of the object which ap2 point to: 0x5617e89e62a0
    // A::print:30
    // A::print:30
    // A Dtor:30
    // A Dtor:0
    //
    // 会进行两次析构
}

```
#### 1.19.1.5 auto_ptr不能作为函数传值参数
- 按值传递时，产生局部变量，会失去所有权，局部变量会再删除
- 引用或指针，不存在拷贝过程，如果失去所有权则运行时错误；
    - const reference

```cpp
template <typename T>
int func(std::auto_ptr<T> ap)
{
    std::cout << "func: " << *ap << std::endl;
    return 0;
}
int func(std::auto_ptr<A> ap)
{
    ap->print();
    return 0;
}
int func5_call_func()
{
    std::cout << "int func5_call_func()" << std::endl;
    std::cout << "func call :" << std::endl;
    std::auto_ptr<int> ap0(new int(0));
    std::auto_ptr<A> autpb(new A(20));
    std::cout << "func call before: " << *ap0 << std::endl;
    std::cout << "func call before: " << *autpb; // << std::endl;
    autpb->print();
    func(ap0);
    std::cout << "the adress of the object which ap0 point to: " << ap0.get() << std::endl; // 0
    func(autpb); // Dtor
    std::cout << "the adress of the object which autpb point to: " << autpb.get() << std::endl; // 0
    std::cout << "func call end: "  << std::endl;

    // 再使用之前的变量会出错
    //autpb->print();
    // std::cout << *ap0 << std::endl;
    // [1]    8323 segmentation fault  ./autoptr
    return 0;
    // int func5_call_func()
    // func call :
    // A Ctor:20
    // func call before: 20
    // func call before: Print A's a is:20
    // A::print:20
    //
    // (int)
    // func: 20
    // the adress of the object which ap0 point to: 0
    //
    // (A)
    // A::print:0
    // A Dtor:0
    //
    // the adress of the object which autpb point to: 0
    //
    // func call end:
    // [1]    8323 segmentation fault  ./autoptr
    //
    // 传值参数时，失去所有权，get为0，
}
```
#### 1.19.1.6 不能初始化为指向非动态分配内存
```cpp
int func6_normalpointer()
{
    std::cout << "int func6_normalpointer()" << std::endl;
    int number = 0;
    int *pnumber = & number;
    //std::auto_ptr<int> normalp (pnumber);
    return 0;
    // int func6_normalpointer()
    // free(): invalid pointer
    // munmap_chunk(): invalid pointer

}
```
#### 1.19.1.7 成员函数 get/ reset/ release
- get 获取
```cpp
// 返回auto_ptr指向的那个对象的内存地址。
```
- reset 销毁设置新值
```cpp
// reset 销毁设置新值
// 重新设置auto_ptr指向的对象。类似于赋值操作，但赋值操作不允许将一个普通指针指直接赋给auto_ptr，而reset()允许。
int func7_reset()
{
    std::cout << "int func7_reset()" << std::endl;
    // 2.reset
    // Deallocate object pointed and set new value

    std::auto_ptr< std::string> p1 (new std::string ("I reigned lonely as a cloud."));
    std::cout << "before reset p1.get(): " << p1.get() << std::endl;
    std::cout << "*p1:" << *p1 << std::endl;
    p1.reset(new std::string( " New string"));
    std::cout << "after  reset p1.get(): " << p1.get() << std::endl;
    std::cout << "*p1:" << *p1 << std::endl;

    std::auto_ptr<A> poldA ( new A(40));
    // std::auto_ptr<A> poldB ( new A(50));
    std::cout << "before reset poldA.get(): " << poldA.get() << std::endl;
    poldA.reset(new A(50));
    std::cout << "after  reset poldA.get(): " << poldA.get() << std::endl;

    return 0;
    // int func7_reset()
    //
    // before reset p1.get(): 0x55a5d54182c0
    // *p1:I reigned lonely as a cloud.
    // after  reset p1.get(): 0x55a5d5418320
    // *p1: New string
    //
    // A Ctor:40
    // before reset poldA.get(): 0x55a5d54182a0
    // A Ctor:50
    // after  reset poldA.get(): 0x55a5d54182a0
    // A Dtor:50
}
```
- release
```cpp
int func8_release()
{
    // 返回auto_ptr指向的那个对象的内存地址,并释放对这个对象的所有权。
    // 用此函数初始化auto_ptr时可以避免两个auto_ptr对象拥有同一个对象的情况（与get函数相比）。
    std::cout << "int func8_release()" << std::endl;
    //3. release
    //std::auto_ptr<A> p60( new A(60));
    //p60->print();
    //std::auto_ptr<A> pget(p60.get());
    //pget->print();

    std::auto_ptr<A> p70( new A(70));
    //p70.release();
    std::cout << "p70.get():" << p70.get() << std::endl;
    std::auto_ptr<A> prelease(p70.release());
    std::cout << "p70.get():" << p70.get() << std::endl;
    std::cout << "prelease.get():" << prelease.get() << std::endl;
    //p70->print();// segmentation fault
    prelease->print();
    return 0;
    // int func8_release()
    // A Ctor:60
    // A::print:60
    // A::print:60
    // A Dtor:60
    // A Dtor:40
}
```
### 1.19.2. unique_ptr（替换auto_ptr）

```cpp
class A
{
public:
    A(int x = 0) :a(x)
    {
        std::cout << "A Ctor:" << a << std::endl;
    }
    ~A()
    {
        std::cout << "A Dtor:" << a << std::endl;
    }
    void print() const
    {
        std::cout << "A::print:" <<  a << std::endl;
    }
private:
    int a;
};

template <typename T>
int func(std::unique_ptr<T> ap)
{
    std::cout << "func: " << *ap << std::endl;
    return 0;
}

int func(std::unique_ptr<A> ap)
{
    ap->print();
    return 0;
}
```

#### 1.19.2.1 使用原始指针构造，自动调用析构函数
```cpp
int func1_unique_ptr()
{
    std::cout << "func1_unique_ptr():" << std::endl;
    A * pa = new A(10);
    pa->print();

    std::unique_ptr<A> unipa (new A(20));
    unipa->print();
    // func1_unique_ptr():
    // A Ctor:10
    // A::print:10
    // A Ctor:20
    // A::print:20
    // A Dtor:20

    return 0;
}
```

#### 1.19.2.2 独占式拥有,不能拷贝与赋值
> unique_ptr拥有它所指向的对象，在某一时刻，只能有一个unique_ptr指向特定的对象。当unique_ptr被销毁时，它所指向的对象也会被销毁。因此不允许多个unique_ptr指向同一个对象，所以不允许拷贝与赋值。

```cpp
int func2_assign()
{
    std::cout << "func2_assign():" << std::endl;
    std::unique_ptr<A> unipa (new A(20));
    unipa->print();
    std::cout << "uniquepb: " << std::endl;
    std::unique_ptr<A> unipb;

    // 不能赋值
    unipb = unipa;
    //  error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std:unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]’
    //  unique_ptr& operator=(const unique_ptr&) = delete;

    // 不能复制 拷贝构造
    std::unique_ptr<A> unipc(unipa);
    // error: use of deleted function  std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]’
    // unique_ptr(const unique_ptr&) = delete;

    //func2_assign():
    // A Ctor:20
    // A::print:20
    // uniquepb:
    // A Dtor:20

    return 0;
}
```
#### 1.19.2.3 C++14可使用make_unique构造
```cpp
int func3_make_unique()
{
    std::cout << "func3_make_unique():" << std::endl;
    // C++14 make_unique
    std::unique_ptr<A> unipd = std::make_unique<A>(40);

    //func3_make_unique():
    // A Ctor:40
    // A Dtor:40
    return 0;
}
```
#### 1.19.2.4 get获取指针，move操作转移所有权
```cpp
int func4_unique_move()
{
    std::cout << "func4_unique_move():" << std::endl;
    // C++14 make_unique
    std::unique_ptr<A> unipa (new A(20));
    std::unique_ptr<A> unipb;

    unipa->print();
    if (unipb != nullptr)
    {
        unipb->print();
    }
    else
    {
        std::cout << "unipb is null." << std::endl;
    }
    std::cout << "Before move,the adress of the object which unipa point to: " << unipa.get() << std::endl; // 0x564cfdde52a0
    std::cout << "Before move,the adress of the object which unipb point to: " << unipb.get() << std::endl; // 0
    unipb = std::move(unipa);
    if (unipb != nullptr)
    {
        unipb->print();
    }
    std::cout << "Afer   move,the adress of the object which unipa point to: " << unipa.get() << std::endl; // 0
    std::cout << "Afer   move,the adress of the object which unipb point to: " << unipb.get() << std::endl; // 0x564cfdde52a0

    // func4_unique_move():
    // A Ctor:20
    // A::print:20
    // unipb is null.
    // Before move,the adress of the object which unipa point to: 0x564cfdde52a0
    // Before move,the adress of the object which unipb point to: 0
    // A::print:20
    // Afer   move,the adress of the object which unipa point to: 0
    // Afer   move,the adress of the object which unipb point to: 0x564cfdde52a0
    // A Dtor:20
    return 0;
}
```
   - Class unique_ptr实现独占式拥有（exclusive ownership）或严格拥有（strict ownership）概念，保证同一时间内只有一个智能指针可以指向该对象。它对于避免资源泄露（resourece leak）——例如“以new创建对象后因为发生异常而忘记调用delete”——特别有用。不能拷贝或赋值。如果确实
   - 想执行类似的操作，要安全的重用这种指针，可给它赋新值。C++有一个标准库函数std::move()，让你能够将一个unique_ptr赋给另一个。

#### 1.19.2.5 reset操作
- 参数可以为 空、内置指针，先将up所指对象释放，然后重置up的值.
```cpp
int func5_unique_reset()
{
    std::cout << "func5_unique_reset():" << std::endl;
    std::unique_ptr<A> unipd = std::make_unique<A>(40);
    std::cout << "unipd.get(): " << unipd.get() << std::endl;
    unipd.reset();
    std::cout << "unipd.get(): " << unipd.get() << std::endl;

    // func5_unique_reset:
    // A Ctor:40
    // unipd.get(): 0x5644b0fe22a0
    // A Dtor:40
    // unipd.get(): 0
    return 0;
}
```
#### 1.19.2.6 release操作
- 在 unique_ptr 对象上调用 release()将释放其关联的原始指针的所有权，并返回原始指针。这里是释放所有权，并没有delete原始指针，reset才会。

```cpp
int func6_unique_release()
{
    std::cout << "func6_unique_release():"<< std::endl;
    std::unique_ptr<A> unipb = std::make_unique<A>(20);
    std::cout << "Before release,the adress of the object which unipb point to: " << unipb.get() << std::endl;
    A * ptr_b = unipb.release();
    std::cout << "Afer   release,the adress of the object which unipb point to: " << unipb.get() << std::endl;
    std::cout << "Afer   release,the adress of the object which ptr_b point to: " << ptr_b << std::endl;

    // func6_unique_release
    // A Ctor:20
    // Before release,the adress of the object which unipb point to: 0x56294be9c2a0
    // Afer   release,the adress of the object which unipb point to: 0
    // Afer   release,the adress of the object which ptr_b point to: 0x56294be9c2a0

    return 0;
}
```

#### 1.19.2.7 拷贝或赋值一个将要被销毁的unique_ptr
> unique_ptr不可拷贝和赋值，那要怎样传递unique_ptr参数和返回unique_ptr呢？
> 事实上不能拷贝unique_ptr的规则有一个例外：我们可以拷贝或赋值一个将要被销毁的unique_ptr （C++ Primer 5th p418）

```cpp
int func7_callfunc()
{
    std::cout << "func7_callfunc():" << std::endl;
    std::unique_ptr<A> unipe = std::make_unique<A>(50);
    unipe->print();
    func1(unipe); // reference
    unipe->print();

    // release 之后 才可以使用，同时，如果不使用unipe接收返回值会内存泄漏
    unipe = func2(std::unique_ptr<A>(unipe.release()));
    unipe->print();

    // func7_callfunc():
    // A Ctor:50
    // A::print:50
    //
    // func reference unique_ptr
    // A::print:50
    //
    // A::print:50  // can print
    //
    // func2 reference unique_ptr
    // A::print:50
    //
    // A::print:50
    // A Dtor:50
    return 0;
}
```
#### 1.19.2.8 传参数时可以传引用

```cpp
int func1(std::unique_ptr<A> &ap)
{
    std::cout << "func reference unique_ptr" << std::endl;
    ap->print();
    return 0;
}
std::unique_ptr<A> func2(std::unique_ptr<A> ap)
{
    std::cout << "func2 reference unique_ptr" << std::endl;
    ap->print();
    return ap;
}

int func7_callfunc()
{
    std::cout << "func7_callfunc():" << std::endl;
    std::unique_ptr<A> unipe = std::make_unique<A>(50);
    unipe->print();
    func1(unipe); // reference
    unipe->print();

    // release 之后 才可以使用，同时，如果不使用unipe接收返回值会内存泄漏
    unipe = func2(std::unique_ptr<A>(unipe.release()));
    unipe->print();

    // func7_callfunc():
    // A Ctor:50
    // A::print:50
    //
    // func reference unique_ptr
    // A::print:50
    //
    // A::print:50  // can print
    //
    // func2 reference unique_ptr
    // A::print:50
    //
    // A::print:50
    // A Dtor:50
    return 0;
}
```

#### 1.19.2.9 delete删除器
```cpp
// non-specialized
template <class T, class D = default_delete<T>> class unique_ptr;
// array specialization
template <class T, class D> class unique_ptr<T[],D>;
```
- 会有默认deleter类型，
```cpp
void math_add(int* a)
{
    int b = ++(*a);
    delete a;
    fprintf(stdout, "add operation: %d\n", b);
}
int func8_deleter()
{
    std::cout << "func8_deleter():" << std::endl;
    std::unique_ptr<int, decltype(&math_add)> Ad(new int, &math_add);
    if(!Ad)
    {
        fprintf(stderr, "Ad is nullptr\n");
        return -1;
    }
    *Ad = 10;
    std::cout << "Ad.get(): " << Ad.get() << std::endl;
    // func8_deleter():
    // func8_deleter():
    // Ad.get(): 0x55df087b72c0
    // add operation: 11
    return 0;
   // 局部变量会调用指定删除器
}
```
### 1.19.3. shared_ptr
```cpp
class A
{
public:
    A(int x = 0) :a(x)
    {
        std::cout << "A Ctor:" << a << std::endl;
    }
    ~A()
    {
        std::cout << "A Dtor:" << a << std::endl;
    }
    A(const A &i)
    {
        this->a = i.a;
        std::cout << "A(const A&) Ctor:" << a << std::endl;
    }
    A operator =(const A &i)
    {
        this->a = i.a;
        std::cout << "A= (const A&) Ctor:" << a << std::endl;
    }
    void print() const
    {
        std::cout << "A::print:" <<  a << std::endl;
    }
private:
    int a;
};
```
#### 1.19.3.1 构造

```cpp
int func1_sharedptr()
{
    std::cout << "func1_sharedptr():" << std::endl;
    // 原始指针
    A * pa = new A(10);
    pa->print();   // 10

    A pb = (*pa);  // A(const A&) Ctor
    A pc;          // A Ctor 0
    pc =(*pa);     // A= (const A& ) Ctor
    std::shared_ptr<A> sharpa (new A(20));
    sharpa->print();
    //
    // func1_sharedptr():
    // A Ctor:10
    // A::print:10
    // A(const A&) Ctor:10
    // A Ctor:0
    // A= (const A&) Ctor:10
    // A Dtor:32767
    // A Ctor:20
    // A::print:20
    // A Dtor:20
    // A Dtor:10
    // A Dtor:10
    return 0;
}

```
#### 1.19.3.2 复制、赋值(引用计数+1)
```cpp
int func2_assign()
{
    std::cout << "func2_assign():" << std::endl;
    std::shared_ptr<A> sharpa (new A(20));                                            // A Ctor:20
    std::cout << std::boolalpha;// << std::endl;
    std::cout << "the unique  of object sharpa is :" << sharpa.unique() << std::endl; // 1 true
    std::cout << std::noboolalpha ;//<< std::endl;
    std::cout << "uniquepb: " << std::endl;
    std::shared_ptr<A> sharpb;
    sharpb = sharpa;                                                                  // assign
    std::cout << "sharpa.use_count() : "<< sharpa.use_count() << std::endl;           // 2
    std::cout << "sharpb.use_count() : "<< sharpb.use_count() << std::endl;           // 2

    // 复制 拷贝构造
    std::shared_ptr<A> sharpc1(sharpa);
    std::cout << "sharpc1.use_count() : "<< sharpc1.use_count() << std::endl;         // 3
    auto sharpc2(sharpa);
    std::cout << "sharpc1.use_count() : "<< sharpc1.use_count() << std::endl;         // 4
    std::cout << "sharpc2.use_count() : "<< sharpc2.use_count() << std::endl;         // 4
    std::cout << std::boolalpha ;//<< std::endl;
    std::cout << "the unique  of object sharpd is :" << sharpb.unique() << std::endl; // 0 false
    std::cout << std::noboolalpha ;//<< std::endl;

    return 0;
    // func2_assign():
    // A Ctor:20
    // the unique  of object sharpa is :true
    // uniquepb:
    // sharpa.use_count() : 2
    // sharpb.use_count() : 2
    // sharpc1.use_count() : 3
    // sharpc1.use_count() : 4
    // sharpc2.use_count() : 4
    // the unique  of object sharpd is :false
    // A Dtor:20
}
```

#### 1.19.3.3 make_shared
```cpp
int func3_make_shared()
{
    std::cout << "func3_make_shared():" << std::endl;
    std::cout << "sharpd make_shared " << std::endl;
    // C++14 make_shared
    std::shared_ptr<A> sharpd = std::make_shared<A>(40);

    if (sharpd != nullptr)
    {
        sharpd->print();
    }
    return 0;
    // func3_make_shared():
    // sharpd make_shared
    // A Ctor:40
    // A::print:40
    // A Dtor:40
}
```

#### 1.19.3.4 reset操作

```cpp
int func4_shared_reset()
{
    std::cout << "func4_shared_reset():" << std::endl;
    std::shared_ptr<A> sharpa (new A(20));
    std::shared_ptr<A> sharpc1(sharpa);
    std::cout << "sharpc1.use_count() : "<< sharpc1.use_count() << std::endl;          // 2
    auto sharpc2(sharpa);
    std::cout << "sharpc1.use_count() : "<< sharpc1.use_count() << std::endl;          // 3
    std::cout << "sharpc2.use_count() : "<< sharpc2.use_count() << std::endl;          // 3
    std::cout << "sharpc2.reset() " << std::endl;
    std::cout << "sharpc2.use_count() : "<< sharpc2.use_count() << std::endl;          // 3
    // 减少引用计数-1
    sharpc2.reset();                                                                   // reset
    // (gdb) p sharpa
    // $7 = std::shared_ptr<A> (use count 2, weak count 0) = {get() = 0x55555576f2a0}
    // (gdb) p sharpc1
    // $8 = std::shared_ptr<A> (use count 2, weak count 0) = {get() = 0x55555576f2a0}
    // (gdb) p sharpc2
    // $9 = std::shared_ptr<A> (empty) = {get() = 0x0}

    std::cout << "sharpc1.use_count() : "<< sharpc1.use_count() << std::endl;          // 2
    std::cout << "sharpc2.use_count() : "<< sharpc2.use_count() << std::endl;          // 0 why not 2?
    std::cout << std::boolalpha ;//<< std::endl;
    std::cout << "the unique  of object sharpc2 is :" << sharpc2.unique() << std::endl;// 0 false
    std::cout << std::noboolalpha ;//<< std::endl;

    std::cout << "sharpc1.reset() " << std::endl;
    sharpc1.reset(new A(30));                                                          // reset + Ctor
    // reset()包含两个操作。
    // 1.当智能指针中有值的时候，调用reset()会使引用计数减1.
    // 2.当调用reset（new xxx())重新赋值时，智能指针首先是生成新对象，
    //   然后将就对象的引用计数减1（当然，如果发现引用计数为0时，则析构旧对象），
    //   然后将新对象的指针交给智能指针保管。
    std::cout << "sharpc1.use_count() : "<< sharpc1.use_count() << std::endl;          // 1
    std::cout << "sharpa.use_count() : "<< sharpa.use_count() << std::endl;            // 1
    std::cout << std::boolalpha ;//<< std::endl;
    std::cout << "the unique  of object sharpc1 is :" << sharpc1.unique() << std::endl;// 1 true
    std::cout << std::noboolalpha ;//<< std::endl;

    //std::cout << "sharpb.release() " << std::endl;
    //std::cout << "sharpb.use_count() : "<< sharpb.use_count() << std::endl;

    // 引用计数为0时析构
    std::shared_ptr<A> sharpd = std::make_shared<A>(40);
    std::cout << "the address of object sharpd is :" << sharpd.get() << std::endl;     // 0x XXX
    std::cout << std::boolalpha ;//<< std::endl;
    std::cout << "the unique  of object sharpd is :" << sharpd.unique() << std::endl;  // 1 true
    std::cout << std::noboolalpha ;//<< std::endl;
    sharpd.reset(new A(45));                                                           // Ctor 45, Dtor 40
    if (sharpd != nullptr)
    {
        sharpd->print();                                                               // 45
    }
    std::cout << "the address of object sharpd is :" << sharpd.get() << std::endl;     // 0
    sharpd.reset();                                                                    // Dtor 45
    std::cout << "the address of object sharpd is :" << sharpd.get() << std::endl;     // 0

    return 0;
    // func4_shared_reset():
    // A Ctor:20
    // sharpc1.use_count() : 2
    // sharpc1.use_count() : 3
    // sharpc2.use_count() : 3
    // sharpc2.reset()
    // sharpc2.use_count() : 3
    // sharpc1.use_count() : 2
    // sharpc2.use_count() : 0
    // the unique  of object sharpc2 is :0 false
    // sharpc1.reset()
    // A Ctor:30
    // sharpc1.use_count() : 1
    // sharpa.use_count() : 1
    // the unique  of object sharpc1 is :1 true
    // A Ctor:40
    // the address of object sharpd is :0x55f82bc6b330
    // the unique  of object sharpd is :1 true
    // A Ctor:45
    // A Dtor:40
    // A::print:45
    // the address of object sharpd is :0x55f82bc6b340
    // A Dtor:45
    // the address of object sharpd is :0
    // A Dtor:30
    // A Dtor:20
}

```
#### 1.19.3.5 不使用get初始化另一个智能指针
```cpp
int func5_getassign()
{
    std::cout << "func5_getassign():" << std::endl;
    std::shared_ptr<A> sharpe = std::make_unique<A>(50);                          // Ctor
    sharpe->print();
    func1(sharpe);                                                                // reference
    sharpe->print();

    std::shared_ptr<A> sharpf (sharpe.get());
    std::cout << "the address of object sharpe is :" << sharpe.get() << std::endl;// 0xXXX
    std::cout << "the address of object sharpf is :" << sharpf.get() << std::endl;// 0xXXX
    std::cout << "sharpe.use_count() : "<< sharpe.use_count() << std::endl;       // 1
    std::cout << "sharpf.use_count() : "<< sharpf.use_count() << std::endl;       // 1
    sharpe.reset();                                                               // Dtor
    std::cout << "sharpe.use_count() : "<< sharpe.use_count() << std::endl;       // 0
    std::cout << "sharpf.use_count() : "<< sharpf.use_count() << std::endl;       // 1
    std::cout << "the address of object sharpe is :" << sharpe.get() << std::endl;// 0
    std::cout << "the address of object sharpf is :" << sharpf.get() << std::endl;// 0xXXX
    if (sharpe == nullptr)
    {
        std::cout << " starpe is nullptr." << std::endl;                          // nullptr
    }
    if (sharpf == nullptr)
    {
        std::cout << " starpf is nullptr." << std::endl;
    }
    else
    {
        sharpf->print();                                                          // error number
    }

    return 0;
    // func5_getassign():
    // A Ctor:50
    // A::print:50
    // func reference shared_ptr
    // A::print:50
    // A::print:50
    // the address of object sharpe is :0x55f82bc6b2c0
    // the address of object sharpf is :0x55f82bc6b2c0
    // sharpe.use_count() : 1
    // sharpf.use_count() : 1
    // A Dtor:50
    // sharpe.use_count() : 0
    // sharpf.use_count() : 1
    // the address of object sharpe is :0
    // the address of object sharpf is :0x55f82bc6b2c0
    //  starpe is nullptr.
    // A::print:734442208
    // A Dtor:734442208
}

```
> get用来将指针的访问权限传递给代码，只有在确定代码不会delete指针的情况下，才能使用get。特别是，永远不要用get初始化另一个智能指针或者为另一个智能指针赋值！

   - 实现共享式拥有（shared ownership）概念。多个智能指针可以指向相同对象，该对象和其相关资源会在“最后一个引用（reference）被销毁”时候释放。
   - 从名字share就可以看出了资源可以被多个指针共享，它使用计数机制来表明资源被几个指针共享。可以通过成员函数use_count()来查看资源的所有者个数。
   - 除了可以通过new来构造，还可以通过传入auto_ptr, unique_ptr,weak_ptr来构造。
   - shared_ptr没有release()。

### 1.19.4. weak_ptr
#### 1.19.4.1 循环引用的问题
```cpp
class ClassB;

class ClassA
{
public:
    ClassA() { std::cout << "ClassA Constructor..." << std::endl; }
    ~ClassA() { std::cout << "ClassA Destructor..." << std::endl; }
    std::shared_ptr<ClassB> pb;  // 在A中引用B
};

class ClassB
{
public:
    ClassB() { std::cout << "ClassB Constructor..." << std::endl; }
    ~ClassB() { std::cout << "ClassB Destructor..." << std::endl; }
    std::shared_ptr<ClassA> pa;  // 在B中引用A
};
int func2_ab()
{
    std::cout << "func2_ab():"<< std::endl;
    std::shared_ptr<ClassA> spa = std::make_shared<ClassA>();
    std::shared_ptr<ClassB> spb = std::make_shared<ClassB>();
    spa->pb = spb;
    spb->pa = spa;
    std::cout << "spa use_cout:" << spa.use_count() << ", spb use_cout:" << spb.use_count() << std::endl; //spa: 2 spb:2
    return 0;
}

// ClassA Constructor...
// ClassB Constructor...
// spa use_cout:2 spb use_cout:2
// 引用计数不会为0，不析构释放
```
#### 1.19.4.2 使用weak_ptr引用计数不加1解决循环引用
- weak_ptr不会改变shared_ptr，但是会和shared_ptr的引用保持一致

```cpp
class ClassD;

class ClassC
{
public:
    ClassC() { std::cout << "ClassC Constructor..." << std::endl; }
    ~ClassC() { std::cout << "ClassC Destructor..." << std::endl; }
    std::weak_ptr<ClassD> pd;  // 在C中引用D
};

class ClassD
{
public:
    ClassD() { std::cout << "ClassD Constructor..." << std::endl; }
    ~ClassD() { std::cout << "ClassD Destructor..." << std::endl; }
    std::weak_ptr<ClassC> pc;  // 在D中引用C
};

int func3_cd()
{
    std::shared_ptr<ClassC> spc = std::make_shared<ClassC>();
    std::shared_ptr<ClassD> spd = std::make_shared<ClassD>();
    spc->pd = spd;
    spd->pc = spc;
    std::cout << "spc use_cout:" << spc.use_count() << ", spd use_cout:" << spd.use_count() << std::endl; //spa: 2 spb:2
}

// ClassC Constructor...
// ClassD Constructor...
// spc use_cout:1, spd use_cout:1
// ClassD Destructor...
// ClassC Destructor...
```

#### 1.19.4.3 weak_ptr没有`*`和`->`,编译错误
- 编译报错，weak_ptr没有重载*，->操作符，因此不可直接通过weak_ptr使用对象,只能通过lock()使用shared_ptr来操作

```cpp
    std::cout << *weak_ptr  number is " << *wptf2 << std::endl;
    // error: no match for ‘operator*’ (operand type is ‘std::weak_ptr<int>’)
    std::cout << "*shared_ptr number is " << *spte2 << std::endl; // 40

    spte1->print(); // 30
    //wptf1->print();
    // error: base operand of ‘->’ has non-pointer type ‘std::weak_ptr<A>’
```
#### 1.19.4.4 使用lock获取shared_ptr并加引用计数
- 如果对象存在，lock()函数返回一个指向共享对象的shared_ptr，否则返回一个空shared_ptr。

```cpp
    std::cout << "func4_lock():"<< std::endl;

    //fwPtr.lock()后会该变shared_ptr的引用计数(+1)
    std::shared_ptr<int> spte2 = std::make_shared<int>(40);
    std::weak_ptr<int> wptf2 = spte2;
    std::cout << "spte use_count:" << spte2.use_count() << " , wptf2 use_count:" << wptf2.use_count() << std::endl;
    // use count 1 , use count 1
    std::cout << "wptf2.lock() " << std::endl;
    std::shared_ptr<int> sptf2 = wptf2.lock();
    std::cout << "spte use_count:" << spte2.use_count() << " , wptf2 use_count:" << wptf2.use_count() << std::endl;
    // use count 2 , use count 2

//spte use_count:1 , wptf2 use_count:1
//wptf2.lock()
//spte use_count:2 , wptf2 use_count:2
```

```cpp
    // lock *2
    std::shared_ptr<A> spte1 = std::make_shared<A>(30);
    std::weak_ptr<A>   wptf1 = spte1;
    std::cout << "spte1 use_count:" << spte1.use_count() << " , wptf1 use_count:" << wptf1.use_count() << std::endl; // use_count 1,use_count 1
    std::cout << "wptf1.lock() *2" << std::endl;
    auto spte3 = wptf1.lock();
    std::cout << "spte1 lock1 use_count:" << spte1.use_count() << " , wptf1 lock1 use_count:" << wptf1.use_count() << std::endl; // use count:2 ,use count :2
    std::shared_ptr<A> spte4 = wptf1.lock();
    //weak_ptr不会改变shared_ptr，但是会和shared_ptr的引用保持一致
    std::cout << "spte1 use_count:" << spte1.use_count() << " , wptf1 use_count:" << wptf1.use_count() << std::endl; // use count:3 ,use count :3
// A Ctor:30
// spte1 use_count:1 , wptf1 use_count:1
// wptf1.lock() *2
// spte1 lock1 use_count:2 , wptf1 lock1 use_count:2
// spte1 use_count:3 , wptf1 use_count:3

    std::cout << "*shared_ptr number is " << *spte2 << std::endl;
    spte1->print();

// *shared_ptr number is 40
// A::print:30
// A Dtor:30
```
#### 1.19.4.5 expired判断引用计数是否为0
- 引用计数为0返回true

```cpp
int func5_expired()
{
    std::cout << "func5_expired():"<< std::endl;
    std::shared_ptr<int> spte5 = std::make_shared<int>(50);
    std::weak_ptr<int> wptf5 = spte5;
    std::cout << "spte use_count:" << spte5.use_count() << " , wptf5 use_count:" << wptf5.use_count() << std::endl;
    std::cout << std::boolalpha << wptf5.expired() << std::endl; // false
    spte5.reset();
    std::cout << std::boolalpha << wptf5.expired() << std::endl; // true
    std::cout << "spte use_count:" << spte5.use_count() << " , wptf5 use_count:" << wptf5.use_count() << std::endl;
    if (wptf5.expired())
    {
        std::cout << "shared_ptr object has been destory" << std::endl;
    }

    std::shared_ptr<int> spte6  = wptf5.lock();//wptf5 为NULL
    // std::cout << "empty shared_ptr  *number is " << *spte6  << std::endl; //运行时中断
    return 0;
    // func5_expired():
    // spte use_count:1 , wptf5 use_count:1
    // false
    // true
    // spte use_count:0 , wptf5 use_count:0
    // shared_ptr object has been destory
}

```
   - 一种不控制对象生命周期的智能指针, 它指向一个 shared_ptr 管理的对象. 进行该对象的内存管理的是那个强引用的 shared_ptr. weak_ptr只是提供了对管理对象的一个访问手段。
   - weak_ptr 设计的目的是为配合 shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 它只可以从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会引起引用记数的增加或减少。
   - share_ptr可能出现循环引用，从而导致内存泄露；weak_ptr是用来解决shared_ptr相互引用时的死锁问题,如果说两个shared_ptr相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。它是对对象的一种弱引用，不会增加对象的引用计数，从而解决循环引用的问题；
   - 和shared_ptr之间可以相互转化，shared_ptr可以直接赋值给它，它可以通过调用lock函数来获得shared_ptr

## 1.19.5 什么时候改变引用计数？

- 构造函数中计数初始化为1；
- 拷贝构造函数中计数值加1；
- 赋值运算符中，左边的对象引用计数减一，右边的对象引用计数加一；
- 析构函数中引用计数减一；
- 在赋值运算符和析构函数中，如果减一后为0，则调用delete释放对象。

# 2.C/C++常见概念
## 2.1 指针和引用
### 2.1.1 指针和引用的区别
| 引用     | 指针     |
| ------ | ------ |
| 必须初始化  | 可以不初始化 |
| 不能为空   | 可以为空   |
| 不能更换目标 | 可以更换目标 |

1.指针有自己的一块空间，而引用只是一个别名；定义一个引用的时候，必须初始化。
2.使用sizeof看一个指针的大小是4or8，而引用则是被引用对象的大小；“sizeof 引用” == 变量(对象)的大小
3.指针可以被初始化为NULL，而引用必须被初始化且必须是一个已有对象的引用；指针可以为空，引用是别名，不能为空。
4.作为参数传递时，指针需要被解引用才可以对对象进行操作，而直接对引用的修改都会改变引用所指向的对象；
~~5.可以有const指针，但是没有const引用；~~
- 引用常量不存在，没有int& const p，常量引用是存在的cosnt int &p
6.指针在使用中可以指向其它对象，但是引用只能是一个对象的引用，不能被改变；对一个对象"至死不渝"；
7.指针可以有多级指针（**p），而引用止于一级；
8.指针和引用使用++运算符的意义不一样；
9.如果返回动态内存分配的对象或者内存，必须使用指针，引用可能引起内存泄露。
### 2.1.2 引用
当一个对象被用作右值的时候，用的是对象的值（内容）；当对象被用作左值的时候，用的是对象的身份（在内存中的位置）。左值有持久的状态，而右值要么是字面常量，要么是在表达式求值过程中创建的对象，即左值持久，右值短暂。
#### 2.1.2.1 左值引用
- 左值引用要求右边的值必须能够取地址，如果无法取地址，可以用常引用；
- 但使用常引用后，我们只能通过引用来读取数据，无法去修改数据，因为其被const修饰成常量引用了。
##### 2.1.2.1.1 non-const左值引用
- 对于non-const引用，其只能用non-const左值来初始化：

```cpp
    int x = 20;
    int& rx1 = x;   // non-const引用可以被non-const左值初始化

    const int y = 10;
    int& rx2 = y;  // 非法：non-const引用不能被const左值初始化
    // error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
    int& rx3 = 10;      // 非法：non-const引用不能被右值初始化
    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

```
##### 2.1.2.1.2 const左值引用

```cpp
    int x = 10;
    const int cx = 20;
    const int& crx1 = x;   // const引用可以被non-const左值初始化
    const int& crx2 = cx;  // const引用可以被const左值初始化
    const int& crx3 = 9;   // const引用可以被右值初始化
```
- const左值引用可以接收右值

### 2.1.3 右值引用
> C++11以前，右值被认为是无用的资源，所以在C++11中引入了右值引用，就是为了重用右值。定义右值引用需要使用&&：
#### 2.1.3.1 定义右值引用
- 定义右值引用的格式如下：
```cpp
类型 && 引用名 = 右值表达式;
```
右值引用一定不能被左值所初始化，只能用右值初始化：
右值引用用来绑定到右值，绑定到右值以后本来会被销毁的右值的生存期会延长至与绑定到它的右值引用的生存期。
```cpp
int      x = 20;    // 左值
int&& rrx1 = x ;    // 非法：右值引用无法被左值初始化
const int&& rrx2 = x;  // 非法：右值引用无法被左值初始化
```

```cpp
    int            x = 20    ;   // 左值
/////////////////////////////////////////////
    int      && rrx1 = x     ;   // 非法：右值引用无法被左值初始化
    //  error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’

    const int&& rrx2 = x     ;   // 非法：右值引用无法被左值初始化
    //  error: cannot bind rvalue reference of type ‘const int&&’ to lvalue of type ‘int’
/////////////////////////////////////////////
    int      &&   rx = x  * 2;   // x*2的结果是一个右值，rx延长其生命周期
    int            y = rx + 2;   // 因此你可以重用它：42
    rx               = 100   ;   // 一旦你初始化一个右值引用变量，该变量就成为了一个左值，可以被赋值
```

#### 2.1.3.2 右值引用用于函数

```cpp
// 接收左值
void fun(int& lref)
{
    std::cout << "l-value reference\n";
}

// 接收右值
void fun(int&& rref)
{
    std::cout << "r-value reference\n";
}

// 不仅可以接收左值，而且可以接收右值（如果你没有提供接收右值引用的重载版本）
void fun2(const int& clref)
{
    std::cout << "l-value const reference\n";
}

    fun(x);  // l-value reference
    fun(10); // l-value reference
    fun2(x); // l-value const reference
    fun2(10);// l-value const reference
```
#### 2.1.3.3 右值作用
>  C++98/03中遇到的两个问题
> 第一个问题就是临时对象非必要的昂贵的拷贝操作，
> 第二个问题是在模板函数中如何按照参数的实际类型进行转发。
> 通过引入右值引用，很好的解决了这两个问题，改进了程序性能，后面将会详细介绍右值引用是如何解决这两个问题的。

```cpp
class RValue {
};

RValue get() {
    return RValue();
}

void put(RValue){}
```
- 在汇编层面右值引用做的事情和常引用是相同的，即产生临时量来存储常量。但是，唯一一点的区别是，右值引用可以进行读写操作，而常引用只能进行读操作。
- 右值引用的存在并不是为了取代左值引用，而是充分利用右值(特别是临时对象)的构造来减少对象构造和析构操作以达到提高效率的目的。

* 右值引用可实现转移语义（Move Sementics）和精确传递（Perfect Forwarding），它的主要目的有两个方面：
  - 消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。
  - 能够更简洁明确地定义泛型函数

##### 2.1.3.4 引用折叠
```cpp
using Lref = Data&;
using Rref = Data&&;
Data data;

Lref&  r1 = data;    // r1 is Data&
Lref&& r2 = data;    // r2 is Data&
Rref&  r3 = data;    // r3 is Data&
Rref&& r4 = Data{};  // r4 is Data&&
```
- X& &、X& &&、X&& & 可折叠成 X&
- X&& && 可折叠成 X&&
 C++的引用在减少了程序员自由度的同时提升了内存操作的安全性和语义的优美性。

#### 2.1.3.5 移动语义
> 对象的资源所有权转移
> 一个对象的移动语义的实现是通过移动构造函数与移动赋值运算符来实现的。
> 由于右值对象一般是临时对象，在移动时，对象包含的资源 不需要先拷贝再删除，只需要直接 从旧对象移动到新对象。
#### 2.1.3.6 std::move强制转化为右值
> 通过move定义可以看出，move并没有”移动“什么内容，只是将传入的值转换为右值，此外没有其他动作。std::move+移动构造函数或者移动赋值运算符，才能充分起到减少不必要拷贝的意义。
#### 2.1.3.7 完美转发
- 什么是 完美转发 (perfect forwarding)：
  - 如果参数是 左值引用，直接以 左值引用 的形式，转发给下一个函数
  - 如果参数是 右值引用，要先 “还原” 为 右值引用 的形式，再转发给下一个函数
### 2.1.4 指针和引用参数传递
指针和引用传参 有什么不同？
2.1.4.1.语法：指针传参使用指针类型作为函数参数，而引用传参使用引用类型作为函数参数。
指针传参示例：
```cpp
void foo(int* ptr) {
    // 使用指针操作ptr
}
```
引用传参示例：
```cpp
void bar(int& ref) {
    // 使用引用操作ref
}
```
2.1.4.2.空值（null）的处理：指针可以被赋予空值（nullptr），以表示它不指向任何有效的内存地址。引用必须始终引用到一个有效的对象，不能是空值。
2.1.4.3.对象的别名：通过引用传参，函数可以直接操作原始对象，因为引用本身就是对象的别名。通过指针传参，需要通过解引用操作符（*）来访问指针所指向的对象。

2.1.4.4.空指针检查：在函数中，可以对指针进行空指针检查，以确保指针的有效性。对于引用，不需要进行空指针检查，因为引用必须在创建时引用一个有效的对象。

2.1.4.5.参数传递的副作用：通过指针传参，函数可以修改指针所指向的对象的值。这是因为指针传递的是对象的地址，函数可以间接地修改对象。通过引用传参，同样也可以修改原始对象的值，因为引用本身就是对象的别名。

选择使用指针传参还是引用传参取决于具体的需求和情况。一般来说，如果函数需要改变传入参数的值或者可能为空，指针传参是一个更好的选择。而引用传参通常用于不需要改变传入参数的值，并且保证了参数不能为空的情况。同时，引用传参可以使代码更易读，并防止了空指针引起的潜在错误。
### 2.1.5 指针 引用 参数传递
在C++中，无论是指针传递还是引用传递，实际上都是通过传递参数的内存地址来访问原始对象。但是底层的实现机制是不同的。
指针和引用本身存储的是地址信息，而不是对象的值。它们只是提供了访问和操作原始对象的方式，而不是存储对象本身的值。

**指针传递**：当使用指针传递参数时，函数接收到的是一个指向原始对象的内存地址的副本。函数内部可以通过解引用操作符（*）来访问指针所指向的原始对象，并可以修改它的值。指针传递需要手动获取和解引用指针才能访问和操作原始对象。
**引用传递**：当使用引用传递参数时，函数接收到的是原始对象的一个别名，而不是副本。因此，在函数内部可以直接使用引用来访问和操作原始对象，就像在函数外部一样。对引用的修改会直接影响到原始对象。引用传递不需要显式地获取和解引用指针，对原始对象的访问更直观和简洁。

指针参数传递本质上是值传递，它所传递的是一个地址值。值传递过程中，被调函数的形式参数作为被调函数的局部变量处理，会在栈中开辟内存空间以存放由主调函数传递进来的实参值，从而形成了实参的一个副本（替身）。值传递的特点是，被调函数对形式参数的任何操作都是作为局部变量进行的，不会影响主调函数的实参变量的值（形参指针变了，实参指针不会变）。
引用参数传递过程中，被调函数的形式参数也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址。被调函数对形参（本体）的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量（根据别名找到主调函数中的本体）。因此，被调函数对形参的任何操作都会影响主调函数中的实参变量。
引用传递和指针传递是不同的，虽然他们都是在被调函数栈空间上的一个局部变量，但是任何对于引用参数的处理都会通过一个间接寻址的方式操作到主调函数中的相关变量。而对于指针传递的参数，如果改变被调函数中的指针地址，它将应用不到主调函数的相关变量。如果想通过指针参数传递来改变主调函数中的相关变量（地址），那就得使用指向指针的指针或者指针引用。
从编译的角度来讲，程序在编译时分别将指针和引用添加到符号表上，符号表中记录的是变量名及变量所对应地址。指针变量在符号表上应的地址值为指针变量的地址值，而引用在符号表上对应的地址值为引用对象的地址值（与实参名字不同，地址相同）。符号表生成之后就不会再改，因此指针可以改变其指向的对象（指针变量中的值可以改），而引用对象则不能修改。

## 2.2 数组和指针
### 2.2.1 数组和指针
|                              指针                               |               数组               |
| -------------------------------------------------------------- | -------------------------------- |
| 保存数据的地址                                                   | 保存数据                          |
| 间接访问数据，首先获得指针的内容，然后将其作为地址，从该地址中提取数据 | 直接访问数据，                     |
| 通常用于动态的数据结构                                            | 通常用于固定数目且数据类型相同的元素 |
| 通过Malloc分配内存，free释放内存                                  | 隐式的分配和删除                   |
| 通常指向匿名数据，操作匿名函数                                     | 自身即为数据名                     |

当一个指针变量被初始化成数组名时，就说该指针变量指向了数组
数组名就是该数组的首地址，也是数组第一个元素的地址。
把数组作为参数传递的时候，会退化为指针

## 2.3 野指针
### 2.3.1 野指针

- 野指针就是指向一个已删除的对象或者未申请访问受限内存区域的指针,是指向不可用内存区域的指针。
- 野指针不是NULL指针，是指向“垃圾”内存的指针.

- 野指针的成因主要有3种:
  * 指针变量没有被初始化, 任何指针变量在刚被创建的时候不会自动成为NULL指针，它的缺省值是随机的。所以指针变量在创建的时候，要么设置为NULL，要么指向合法的内存
  * 指针p被free/delete之后，没有置为NULL(最好加一句p = NULL;)
  * 指针操作超越了变量的作用范围。不要返回指向栈内存的指针或引用，因为栈内存在函数结束时会被释放

## 2.4 C++内存管理详解
### 2.4.1 C++内存管理 分配简介
  - 5个区，堆、栈、自由存储区、全局/静态存储区和常量存储区。
  - 堆。就是那些由new分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个new就要对应一个delete。
  - 栈。局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放
  - 自由存储区，
  - 全局/静态。
  - 常量。不允许修改。
  - 栈。编译器管理。堆。程序员决定。

### 2.4.2 C语言是怎么进行函数调用的
  - call函数调用，ret返回
  - 记录 被调用函数下一地址压入栈；
  - 参数由右向左依次入栈；
  - 64位前六个参数可以通过寄存器；

### 2.4.3 C++函数返回值
  - 生成一个临时变量，把它的引用作为函数参数传入函数内。
  - 1.保存当前执行函数的状态（执行到了哪里，各个参数的值等）；
  - 2.把参数放到特定的位置，供被调用的函数使用；
  - 3.跳转到要调用的函数开始处，开始执行（这一步叫控制转移）；
  - 4.函数执行完毕，将返回值放到特定位置；
  - 5.清理函数使用的资源（返回值不会被清理）；
  - 6.读取保存的函数状态，跳转到原来的位置继续执行（控制转移）；
  - 7.从特定位置取出返回值并使用。
  - 返回的是 eax 寄存器里的内容。
  - eax 寄存器有两个作用：
    - 计算时的临时存储变量
    - 在函数返回时，作为传递返回值的寄存器

## 2.5 C++强制类型转换
### 2.5.0 C++强制类型转换
static_cast ／ const_cast / dynamic_cast / reinterpret_cast
### 2.5.1 为什么需要类型转换:
  * 没有从形式上体现转换功能和风险的不同
  * 将多态基类指针转换成派生类指针时不检查安全性，即无法判断转换后的指针是否确实指向一个派生类对象
  * 难以在程序中寻找到底什么地方进行了强制类型转换

### 2.5.2 隐式类型转换
  - 首先，对于内置类型，低精度的变量给高精度变量赋值会发生隐式类型转换，
  - 其次，对于只存在单个参数的构造函数的对象构造来说，函数调用可以直接使用该参数传入，编译器会自动调用其构造函数生成临时对象。

  在C++中，隐式类型转换（Implicit Type Conversion）是指在表达式中自动发生的类型转换，通常发生在不同数据类型的操作数之间。这种转换可以使代码更加灵活，但也可能导致难以发现的错误，特别是在类型不兼容或精度损失的情况下。

#### 常见的隐式类型转换情形：

1. **数值类型之间的转换**：
   - 当一个较小范围的整数类型转换为较大范围的整数类型时，例如`char`转`int`。
   - 当整数类型与浮点数类型混合运算时，整数将被提升为浮点数类型，以避免精度损失。

2. **窄字符到宽字符的转换**：
   - 当`char`类型与`wchar_t`类型混合使用时，`char`类型会被转换为`wchar_t`。

3. **枚举类型到整数的转换**：
   - 枚举类型的值可以被隐式转换为整数类型。

4. **指针类型转换**：
   - 空指针`nullptr`可以隐式转换为任何类型的指针。
   - 指向派生类的指针可以隐式转换为指向基类的指针（向下转型需要显式转换）。

5. **用户自定义类型的转换**：
   - 当用户自定义类型提供了合适的转换构造函数时，可以进行从简单类型到复杂类型的隐式转换。

#### 隐式类型转换的潜在问题：

- **精度损失**：当高精度类型转换为低精度类型时，例如`double`转`float`，可能会丢失精度。
- **溢出和截断**：当大数值转换为小范围类型时，例如`int`转`char`，可能会导致溢出或截断。
- **语义错误**：例如，将`bool`类型转换为`int`，虽然在某些情况下是合法的，但可能导致逻辑错误。
- **对象生命周期问题**：当一个智能指针或对象转换为原始指针或基本类型时，可能会影响对象的生命周期管理。

#### 如何避免潜在问题：

- **显式转换**：使用`static_cast`、`dynamic_cast`、`const_cast`或`reinterpret_cast`进行显式类型转换，以增加代码的清晰度和安全性。
- **避免不必要的转换**：尽量使用相同类型的数据进行运算，减少类型转换的需求。
- **使用静态类型检查工具**：使用诸如Clang-Tidy、Cppcheck等工具进行静态代码分析，以检测潜在的类型转换问题。
- **设计良好的接口**：在设计类和函数时，考虑类型安全，避免需要频繁的类型转换。

隐式类型转换在C++中是常见的现象，理解其行为对于编写健壮、高性能的代码至关重要。在可能引起问题的场景中，显式控制类型转换通常是一种更好的实践。

### 2.5.3 **static_cast\<type\>(expr):**
- 用于各种隐式转换，比如非const转const，void*转指针等, static_cast能用于多态向上转化，如果向下转能成功但是不安全，结果未知；
- 进行强制数据类型转换时，将想要转换成的数据类型放到尖括号中，将待转换的变量或表达式放在元括号中：static_cast <类型说明符> （变量或表达式）：可以实现C++中内置基本数据类型之间的相互转换,
- 用于进行比较“自然”和低风险的转换，如整型和浮点型、字符型之间的互相转换
任何编写程序时能够明确的类型转换都可以使用static_cast（static_cast不能转换掉底层const，volatile和__unaligned属性）。
由于不提供运行时的检查，所以叫static_cast，因此，需要在编写程序时确认转换的安全性。
用于进行比较**“自然”和低风险的转换**; 如整型和浮点型、字符型之间的互相转换; 可以实现C++中内置基本数据类型之间的相互转换,
进行强制数据类型转换时，将想要转换成的数据类型放到尖括号中，将待转换的变量或表达式放在元括号中：static_cast <类型说明符> （变量或表达式）：

1.使用场景：
　　a、用于类层次结构中基类和派生类之间指针或引用的转换；static_cast能用于多态向上转化，如果向下转能成功但是不安全，结果未知；
　　 - 上行转换（派生类---->基类）是安全的。
　　 - 下行转换（基类---->派生类）由于没有动态类型检查，所以是不安全的。
　　b、用于基本数据类型之间的转换，如把int转换为char，int转enum，安全性问题由开发者来保证；
　　c、把空指针转换成目标类型的指针，`void*`转指针（不安全） 例如`void *`转`int *`、`char *`转`void *`
　　d、把任何类型的表达式转为void类型；
2.使用特点
　　a、主要执行非多态的转换操作，用于代替C中通常的转换操作；
　　b、隐式转换都建议使用static_cast进行标明和替换；
注意：static_cast不能转换掉expression的const、volatile、或者__unaligned属性。
```cpp
#include <iostream>
using namespace std;

class A
{
public:
    operator int() { return 1; }
    operator char*() { return NULL; }
};

int main()
{
    A a;
    int n;
    char* p = "New Dragon Inn";

    n = static_cast <int> (3.14);  // n 的值变为 3
    n = static_cast <int> (a);     // 调用 a.operator int，n 的值变为 1
    p = static_cast <char*> (a);   // 调用 a.operator char*，p 的值变为 NULL
    n = static_cast <int> (p);     // 编译错误，static_cast不能将指针转换成整型
    p = static_cast <char*> (n);   // 编译错误，static_cast 不能将整型转换成指针

    return 0;
}
```
### 2.5.4 **const_cast\<type\>(expr):**
- 运算符仅用于进行去除 const 属性的转换,不是用于去除变量的常量性，而是去除指向常数对象的指针或引用的常量性，其去除常量性的对象必须为指针或引用：const_cast<type_id> (expression)：
- 将 const 引用转换为同类型的非 const 引用，将 const 指针转换为同类型的非 const 指针时可以使用 const_cast 运算符

const_cast用于移除类型的const、volatile和__unaligned属性。
    1.使用场景：
    　　a、常量指针转换为非常量指针，并且仍然指向原来的对象
    　　b、常量引用被转换为非常量引用，并且仍然指向原来的对象
    2.使用特点：
    　　a、cosnt_cast是四种类型转换符中唯一可以对常量进行操作的转换符
    　　b、去除常量性是一个危险的动作，尽量避免使用。
```cpp
    const string s = "Inception";
    string& p = const_cast <string&> (s);
    string* ps = const_cast <string*> (&s);  // &s 的类型是 const string*
```

const_cast `const *`，`*const`
### 2.5.5 **reinterpret_cast\<type\>(expr):**
- 主要有三种强制转换用途：改变指针或引用的类型、将指针或引用转换为一个足够长度的整形、将整型转换为指针或引用类型
- 用于进行各种不同类型的指针之间、不同类型的引用之间以及指针和能容纳指针的整数类型之间的转换。转换时，执行的是逐个比特复制的操作
reinterpret 是“重新解释”的意思，
主要有三种强制转换用途：改变指针或引用的类型、将指针或引用转换为一个足够长度的整形、将整型转换为指针或引用类型
( 用于进行各种不同类型的指针之间、不同类型的引用之间以及指针和能容纳指针的整数类型之间的转换。转换时，执行的是逐个比特复制的操作)
reinterpret_cast意图执行低级转型，从底层对数据进行重新解释; 实际动作（及结果）可能取决于编辑器，依赖具体的平台，这也就表示它不可移植。
```cpp
#include <iostream>
using namespace std;

class A
{
public:
    int i;
    int j;
    A(int n):i(n),j(n) { }
};

int main()
{
    A a(100);
    int &r = reinterpret_cast<int&>(a); // 强行让 r 引用 a

    r = 200;                            // 把 a.i 变成了 200
    cout << a.i << "," << a.j << endl;  // 输出 200,100

    int n = 300;
    A *pa = reinterpret_cast<A*> (&n);  // 强行让 pa 指向 n
    pa->i = 400;                        // n 变成 400
    pa->j = 500;                        // 此条语句不安全，很可能导致程序崩溃
    cout << n << endl;                  // 输出 400

    long long la = 0x12345678abcdLL;
    pa = reinterpret_cast<A*>(la);     // la太长，只取低32位0x5678abcd拷贝给pa
    unsigned int u = reinterpret_cast<unsigned int>(pa);   // pa逐个比特拷贝到u
    cout << hex << u << endl;          // 输出 5678abcd

    typedef void (* PF1) (int);
    typedef int (* PF2) (int,char *);
    PF1 pf1;
    PF2 pf2;
    pf2 = reinterpret_cast<PF2>(pf1);  // 两个不同类型的函数指针之间可以互相转换
}
class A {
    public:
    int m_a;
};

class B {
    public:
    int m_b;
};

class C : public A, public B {};

C c;
printf("%p, %p, %p", &c, reinterpret_cast<B*>(&c), static_cast <B*>(&c));
```
前两个的输出值是相同的，最后一个则会在原基础上偏移4个字节，这是因为static_cast计算了父子类指针转换的偏移量，并将之转换到正确的地址（c里面有m_a,m_b，转换为`B*`指针后指到m_b处），而reinterpret_cast却不会做这一层转换。

### 2.5.6 **dynamic_cast\<type\>(expr):**
#### 2.5.6.0 动态类型转换，向上向下转换多态类型

- 用于**动态类型转换**。只能用于含有虚函数的类，用于类层次间的向上和向下转化。只能转指针或引用。向下转化时，如果是非法的对于指针返回NULL，对于引用抛异常。要深入了解内部转换的原理
- 它要求所转换的操作数必须包含多态类类型（即至少包含一个虚函数的类）。检查是否会转换成功,能成功则转,不成功就会返回0;
- reinterpret_cast可以将多态基类（包含虚函数的基类）的指针强制转换为派生类的指针，但是这种转换不检查安全性，即不检查转换后的指针是否确实指向一个派生类对象。
- dynamic_cast专门用于将多态基类的指针或引用强制转换为派生类的指针或引用，而且能够检查转换的安全性。对于不安全的指针转换，转换结果返回 NULL 指针
  用于动态类型转换。只能用于含有虚函数的类，用于类层次间的向上（Upcasting）和向下转化（Downcasting）。只能转指针或引用。
向上转型是无条件的，不会进行任何检测，所以都能成功；
向下转化时，向下转型的前提必须是安全的，要借助 RTTI 进行检测，所有只有一部分能成功。如果是非法的对于指针返回NULL，对于引用抛std::bad_cast异常。要深入了解内部转换的原理
它 RTTI 要求所转换的操作数必须包含多态类类型（即至少包含一个虚函数的类）。检查是否会转换成功,能成功则转,不成功就会返回0;
#### 2.5.6.1 转换类型 指针/引用
##### 2.5.6.1.1 指针类型
举例，Base为包含至少一个虚函数的基类，Derived是Base的共有派生类，如果有一个指向Base的指针bp，我们可以在运行时将它转换成指向Derived的指针，代码如下：
```cpp
if(Derived *dp = dynamic_cast<Derived *>(bp)){
  //使用dp指向的Derived对象
}
else{
  //使用bp指向的Base对象
}
```
值得注意的是，在上述代码中，if语句中定义了dp，这样做的好处是可以在一个操作中同时完成类型转换和条件检查两项任务。
##### 2.5.6.1.2 引用类型
因为不存在所谓空引用，所以引用类型的dynamic_cast转换与指针类型不同，在引用转换失败时，会抛出std::bad_cast异常，该异常定义在头文件typeinfo中。
```cpp
void f(const Base &b){
 try{
   const Derived &d = dynamic_cast<const Base &>(b);
   //使用b引用的Derived对象
 }
 catch(std::bad_cast){
   //处理类型转换失败的情况
 }
}
```

### 2.5.7 为什么不使用C的强制转换？
- C的强制转换表面上看起来功能强大什么都能转，但是转化不够明确，不能进行错误检查，容易出错。

### 2.5.8 RTTI
- 运行时类型检查，在C++层面主要体现在dynamic_cast和typeid,VS中虚函数表的-1位置存放了指向type_info的指针。对于存在虚函数的类型，typeid和dynamic_cast都会去查询type_info
Runtime Type IdentificationI
运行时类型检查，在C++层面主要体现在dynamic_cast和typeid,VS中虚函数表的-1位置存放了指向type_info的指针。对于存在虚函数的类型，typeid和dynamic_cast都会去查询type_info
程序在运行时能根据基类的指针或引用来获得该指针或引用所指的对象的实际类型。但是现在RTTI的类型识别已经不限于此了，它还能通过typeid操作符识别出所有的基本类型（int，指针等）的变量对应的类型。
（1）typeid运算符，该运算符返回其表达式或类型名的实际类型。
（2）dynamic_cast运算符，该运算符将基类的指针或引用安全地转换为派生类类型的指针或引用。

## 2.6 什么是右值引用，跟左值又有什么区别(#2.1.2)
### 2.6.0 什么是右值引用，跟左值又有什么区别(#2.1.2)
- 右值引用是C++11中引入的新特性 , 它实现了转移语义和精确传递。它的主要目的有两个方面：
- 消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。
- 能够更简洁明确地定义泛型函数。

- 左值和右值的概念：
  - 左值：能对表达式取地址、或具名对象/变量。一般指表达式结束后依然存在的持久对象。
  - 右值：不能对表达式取地址，或匿名对象。一般指表达式结束就不再存在的临时对象。

- 右值引用和左值引用的区别：
  - 左值可以寻址，而右值不可以。
  - 左值可以被赋值，右值不可以被赋值，可以用来给左值赋值。
  - 左值可变,右值不可变（仅对基础类型适用，用户自定义类型右值引用可以通过成员函数改变）。

### 2.7.0 C++源文件从文本到可执行文件经历的过程
#### 2.7.1 预处理阶段：
- 对源代码文件中文件包含关系（头文件）、预编译语句（宏定义）进行分析和替换，生成预编译文件。
#### 2.7.2 编译阶段：
- 将经过预处理后的预编译文件转换成特定汇编代码，生成汇编文件
#### 2.7.3  汇编阶段：
- 将编译阶段生成的汇编文件转化成机器码，生成可重定位目标文件
#### 2.7.4 链接阶段：
- 将多个目标文件及所需要的库连接成最终的可执行目标文件

# 3. C++ 面向对象

### 3.1 C/C++语言区别

#### 3.1.1 设计思想上：
  - C++是面向对象的语言，而C是面向过程的结构化编程语言
#### 3.1.2 语法上：
  - C++具有封装、继承和多态三种特性
  - C++相比C，增加多许多类型安全的功能，比如强制类型转换、
  - C++支持范式编程，比如模板类、函数模板等

### 3.2 new与malloc的区别

#### 3.2.1. `new/delete` 是 `C++` 的运算符操作符； `malloc/free` 是 `C++/C` 语言的标准库函数；

#### 3.2.2. new自己计算需要的空间大小；malloc需要指定大小;

#### 3.2.3 调用构造析构函数
- new在动态分配内存的时候可以初始化对象，调用其构造函数，delete在释放内存时调用对象的析构函数。
- `new` 内置了 `sizeof`, 类型转换和类型安全检查功能, 可以直接申请对应类型的对象。
- malloc只分配一段给定大小的内存，并返回该内存首地址指针，如果失败，返回NULL；`malloc` 返回值的类型是 `void *`, 要显式地进行类型转换, 同时它只关心内存的总字节数。

#### 3.2.4. opeartor new /operator delete可以重载，而malloc不行

#### 3.2.5. new可以调用malloc来实现，但是malloc不能调用new来实现

#### 3.2.6. new[] delete[] 分配内存和多次构造多次析构
- 对于数据C++定义new[\]专门进行动态数组分配，用delete[\]进行销毁。
-  new[\]会一次分配内存，然后多次调用构造函数；delete[]会先多次调用析构函数，然后一次性释放。

#### 3.2.7. malloc能够直观地重新分配内存
   - 在使用过程中发现内存不足，可以使用realloc函数进行内存重新分配实现内存的扩充。
   - realloc先判断当前的指针所指内存是否有足够的连续空间，
     - 如果有，原地扩大可分配的内存地址，并且返回原来的地址指针；
     - 如果空间不够，先按照新指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，而后释放原来的内存区域。

#### 3.2.8. 分配在堆上。
   - new是分配在自由存储区,而malloc分配在堆上，自由存储区可以是堆也可以不是，具体要看new内部的实现。
   - 操作系统在堆上维护一个空闲内存链表，当需要分配内存的时候，就查找这个表，找到一块内存大于所需内存的区域，分配内存并将剩余的内存空间返还到空闲链表上（如果有剩余的话）。
   - Malloc在申请内存时，一般会通过brk或者mmap系统调用进行申请。其中当申请内存小于128K时，会使用系统函数brk在堆区中分配；而当申请内存大于128K时，会使用系统函数mmap在映射区分配

### 3.3 delete与delete[]的区别
[释放对象数组:delete与delete[]](https://blog.csdn.net/kate19930802/article/details/10300793)

``` c++
string *stringptr1 = new string;
string *stringptr2 = new string[100];
...
delete stringptr1;// 删除一个对象
delete [] stringptr2;// 删除对象数组
```

如果你在stringptr1前加了"[]"会怎样呢？答案是：那将是不可预测的；
如果你没在stringptr2前没加上"[]"又会怎样呢？答案也是：不可预测

方括号的存在会使编译器获取数组大小（size）然后析构函数再被依次应用在每个元素上，一共size次。否则，只有一个元素被析构。
无论哪种情况，分配的全部空间被返还给自由存储区。

为什么无论哪种情况，分配的全部空间被返还给自由存储区?

* 空间释放(肯定有个log记录分配的大小)和调用析构函数(类型识别,不同的编译器实现不同)采用不同的机制.

* 一般在分配时分配器会自动写一个日志（一般在分配使用得内存之前又一个结构），用于记录分配的大小，分配内容的sizeof等等, 空间释放是根据这个日志进行释放, 释放空间的机制是需要绝对保证的, delete操作则不是通过类型信息来确定分配的内存大小, 这是通过编译器记住那块大小
* delete时编译器得到类型信息是类的单个的指针, 那么释放时，只调用一次析构函数; delete[] 编译器得到的类型信息是类的数组类型，则按照类的数组来处理，依次调用每个元素的析构函数

> 函数指针

> 声明普通类型指针时，需要指明指针所指向的数据类型，而声明函数指针时，也就要指明指针所指向的函数类型，即需要指明函数的返回类型和形参类型。

## 3.4 C++类的访问权限
### 3.4.0 C++类的访问权限
C++通过 public、protected、private 三个关键字来控制成员变量和成员函数的访问权限，它们分别表示公有的、受保护的、私有的，被称为成员访问限定符。
在类的内部（定义类的代码内部），无论成员被声明为 public、protected 还是 private，都是可以互相访问的，没有访问权限的限制。
在类的外部（定义类的代码之外），只能通过对象访问成员，并且通过对象只能访问 public 属性的成员，不能访问 private、protected 属性的成员

|  访问权限        |  public  |  protected  |  private  |
|  -------------- |  ------  |  ---------  |  -------  |
|  对本类          |  可见    |  可见       |  可见      |
|  对子类          |  可见    |  可见       |  不可见    |
|  对外部(调用方)  |  可见     |  不可见     |  不可见    |


## 3.5 析构函数
### 3.5.0 析构函数
析构函数与构造函数对应，当对象结束其生命周期，如对象所在的函数已调用完毕时，系统会自动执行析构函数。
析构函数名也应与类名相同，只是在函数名前面加一个位取反符`~`，例如`~stud()`，以区别于构造函数。它不能带任何参数，也没有返回值（包括void类型）。只能有一个析构函数，不能重载。
如果用户没有编写析构函数，编译系统会自动生成一个缺省的析构函数（即使自定义了析构函数，编译器也总是会为我们合成一个析构函数，并且如果自定义了析构函数，编译器在执行时会先调用自定义的析构函数再调用合成的析构函数），它也不进行任何操作。所以许多简单的类中没有用显式的析构函数。
如果一个类中有指针，且在使用的过程中动态的申请了内存，那么最好显示构造析构函数在销毁类之前，释放掉申请的内存空间，避免内存泄漏。
类析构顺序：1）派生类本身的析构函数；2）对象成员析构函数；3）基类析构函数。

## 3.6 析构函数抛异常
### 3.6.0 析构函数抛异常
- 从语法上来说，构造函数和析构函数都可以抛出异常。
- 但从逻辑上和风险控制上，构造函数可以，析构函数不推荐抛出异常
- [正常情况下调用析构函数抛出异常导致资源泄露]
   - 如果析构函数抛出异常，则异常点之后的程序不会执行，如果析构函数在异常点之后执行了某些必要的动作比如释放某些资源，则这些动作不会执行，会造成诸如资源泄漏的问题。
- [在发生异常的情况下调用析构函数抛出异常，会导致程序崩溃]
   - 通常异常发生时，c++的机制会调用已经构造对象的析构函数来释放资源，此时若析构函数本身也抛出异常，则前一个异常尚未处理，又有新的异常，会造成程序崩溃的问题。
- 解决方案：
  - 1. 如果某个操作可能会抛出异常，class应提供一个普通函数（而非析构函数），来执行该操作。目的是给客户一个处理错误的机会。
  - 2. 如果析构函数中异常非抛不可，那就用try catch来将异常吞下，必须要把这种可能发生的异常完全封装在析构函数内部，决不能让它抛出函数之外。

## 3.7 复制构造函数
### 3.7.0 复制构造函数
复制构造函数（Copy Constructor）是一种特殊的构造函数，用于创建一个对象，其内容与现有对象相同。它通常用于在创建新对象时，以已存在的对象作为初始值。

复制构造函数的语法格式如下：
```cpp
类名(const 类名& existingObject)
{
    // 构造函数的实现代码
}
```
在复制构造函数中，参数是一个对同类型的对象的引用。通过引用方式传递参数的原因是避免在复制过程中对对象进行不必要的拷贝操作，提高性能和效率。

当满足以下情况之一时，复制构造函数会被调用：

在创建一个新对象时，使用现有对象进行初始化。
将一个已经创建的对象作为参数传递给函数，并在函数内部创建新对象。
复制构造函数的目的是创建一个对象的深拷贝（Deep Copy）。深拷贝意味着将现有对象的所有成员变量的值复制到新对象中，而不仅仅是简单地复制指针或引用。

需要注意的是，如果在类中没有定义自己的复制构造函数，编译器会提供一个默认的复制构造函数，该函数会按位拷贝对象的成员变量。但是，如果类中包含指针或动态分配的资源，简单的按位拷贝可能导致问题，需要自定义复制构造函数来正确地复制对象的内容。

复制构造函数在对象的拷贝、传递和赋值过程中起重要作用，确保新对象能够正确地初始化和复制现有对象的状态。
- 在linux下，编译器有时会对复制构造函数的调用做优化，避免不必要的复制构造函数调用。
  - 可以使用命令g++ xxx.cpp -fno-elide-constructors命令关闭编译器优化
- 拷贝赋值函数值传递
  - 不能。如果是这种情况下，调用拷贝构造函数的时候，首先要将实参传递给形参，这个传递的时候又要调用拷贝构造函数。如此循环，无法完成拷贝，栈也会满。

# 4 类继承与派生

## 4.1 继承权限
### 4.1.0 基类的访问权限在不同权限继承时在子类中的权限:

|    基类权限    |  private  | protected |  public   |
| -------------- | --------- | --------- | --------- |
| public 继承    | 子类不可见 | protected | public    |
| protected 继承 | 子类不可见 | protected | protected |
| private 继承   | 子类不可见 | private   | private   |
引申出struct和class，参见 #1.11；

### 4.1.1 公有继承
#### 4.1.1.1 基类中protected的成员
- 类内部：可以访问
- 类的使用者：不能访问
- 类的派生类成员：可以访问
#### 4.1.1.2.派生类不可访问基类的private成员
#### 4.1.1.3.派生类可访问基类的protected成员
#### 4.1.1.4.派生类可访问基类的public成员
```cpp
#include <iostream>
class A{
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};
class B: public A
{
    public:
    int d;
    int printa(){std::cout << "print a:" << a << std::endl;}
    int printb(){std::cout << "print b:" << b << std::endl;}
    // int printc(){std::cout << "print c:" << c << std::endl;}
    // error: ‘int A::c’ is private within this context
};
class C : protected A
{
    public:
    int e;
    int printa(){std::cout << "print a:" << a << std::endl;}
    int printb(){std::cout << "print b:" << b << std::endl;}

    // int printc(){std::cout << "print c:" << c << std::endl;}
    // error: ‘int A::c’ is private within this context
};
class D: private A
{
    public:
    int f;
    int printa(){std::cout << "print a:" << a << std::endl;}
    // int printb(){std::cout << "print b:" << b << std::endl;}

    // int printc(){std::cout << "print c:" << c << std::endl;}
    // error: ‘int A::c’ is private within this context
};
int main()
{
    B b;
    std::cout << "print a:" << b.a << std::endl;
    b.printa();
    b.printb();
    C c;
    //std::cout << "print a:" << c.a << std::endl;
    // error: ‘int A::a’ is inaccessible within this context
    c.printa();
    c.printb();
    D d;
    // std::cout << "print a:" << d.a << std::endl;
    //  error: ‘int A::a’ is inaccessible within this context
    d.printa();

    //b.printc();

    // std::cout << "print b:" << b.b << std::endl;
    // ‘int A::b’ is protected within this context
    //
    // std::cout << "print c:" << b.c << std::endl;
    //error: ‘int A::c’ is private within this context
    return 0;
}
```
### 4.1.2 私有继承
- 派生类不可访问基类的任何成员与函数
通过私有继承并使用 using 声明，可以在派生类中使用基类的成员。私有继承意味着基类的公共和保护成员在派生类中变为私有成员，但仍然可以通过 using 声明来提供对这些成员的访问权限。

下面是一个示例代码：

```cpp
#include <iostream>

class Base {
public:
    void publicFunction() {
        std::cout << "This is a public function in the base class." << std::endl;
    }
};

class Derived : private Base {
public:
    using Base::publicFunction;   // 使用 using 声明，提供对基类的公共函数的访问权限

    void callBaseFunction() {
        publicFunction();   // 可以在派生类中调用基类的公共函数
    }
};

int main() {
    Derived derived;
    derived.callBaseFunction();    // 输出：This is a public function in the base class.

    // 使用 using 声明后，也可以直接调用基类的成员
    derived.publicFunction();     // 输出：This is a public function in the base class.

    return 0;
}
```
在上述示例中，Derived 类私有继承了 Base 类，并使用 `using` 声明来让 Base 类的 `publicFunction()` 成员在 Derived 类中可见和访问。通过 `callBaseFunction()` 函数和 `derived.publicFunction()` 的调用，我们可以看到基类的公共函数在派生类中仍然可以被访问和使用。

需要注意的是，私有继承意味着基类的公共和保护成员在派生类中变为私有成员，因此除非通过 using 声明提供访问权限，否则这些成员对派生类的外部是不可见的。
### 4.1.3 保护继承
- 派生方式为protected的继承称为保护继承，在这种继承方式下，
  * 基类的public成员在派生类中会变成protected成员，
  * 基类的protected和private成员在派生类中保持原来的访问权限;
- 注意点：
  * 当采用保护继承的时候，由于public成员变为protected成员，因此类的使用者不可访问！而派生类可访问！
在保护继承中，基类的公有成员对于外部代码来说是不可访问的，具体派生类对象也不能直接访问。只有派生类内部的成员函数可以访问派生类从基类继承而来的保护成员。

下面是一个示例来说明这个概念：

```cpp
class Base {
public:
    int publicMember;

protected:
    int protectedMember;
};

class Derived : protected Base {
public:
    void accessBaseMembers(Derived& other) {
        publicMember = 10;                  // 可以在派生类中进行访问
        protectedMember = 20;               // 可以在派生类中进行访问

        other.publicMember = 30;            // 可以在同类型的其他派生类对象中进行访问
        other.protectedMember = 40;         // 可以在同类型的其他派生类对象中进行访问

        // Base baseObj;
        // baseObj.publicMember = 50;       // 不允许在基类对象或其他非派生类对象中进行访问
        // baseObj.protectedMember = 60;    // 不允许在基类对象或其他非派生类对象中进行访问
    }
};

int main() {
    Derived derivedObj1;
    Derived derivedObj2;
    derivedObj1.accessBaseMembers(derivedObj2);   // 可以在同类型的派生类对象间进行访问
    return 0;
}
```
在上述示例中，Derived 类使用保护继承从 Base 类继承而来。在 accessBaseMembers 函数中，派生类对象和其他同类型的派生类对象可以访问基类的公有成员和保护成员。但是，在 main 函数中，无法直接在派生类对象以外的地方访问这些成员。

因此，外部代码无法直接访问保护继承所得到的基类成员。只有在派生类内部或相同类型的其他派生类对象中，才能对这些成员进行访问。
### 4.1.4 派生类对基类成员的访问形式
1.通过派生类对象直接访问基类成员
2.在派生类成员函数中直接访问基类成员
3.通过基类名字限定访问被重载的基类成员名

## 4.2 继承重载不可见
### 4.2.0 继承重载不可见
-  一旦定义了一个重载版本，那么其他的重载版本都会变为不可见
    // 没有using Base::f的情况下，
    //overload_using.cpp:28:9: error: no matching function for call to ‘Derived::f()’


## 4.3 派生类赋值相容性
### 4.3.0 派生类赋值相容性
- 基类对象与派生类对象之间存在赋值相容性。
- 包括以下几种情况：
  * 把派生类对象赋值给基类对象。
  * 把派生类对象的地址赋值给基类指针。
  * 用派生类对象初始化基类对象的引用。
- 反之则不行，
  * 即不能把基类对象赋值给派生类对象；
  * 不能把基类对象的地址赋值给派生类对象的指针；
  * 也不能把基类对象作为派生对象的引用。

## 4.4 派生类构造函数析构函数
### 4.4.1 类对象成员的构造顺序
- 先构造成员 再构造自身（调用构造函数）

```cpp
class C
{
public:
	C() { cout<<"Constructing C"<<endl;}
	~C(){ cout<<"Destructing C"<<endl;}
	B b;
	A a;
};

int main()
{
    C c;
}
Constructing B
Constructing A
Constructing C
Destructing C
Destructing A
Destructing B
```

### 4.4.2 派生类构造函数
- 派生类可能有多个基类，也可能包括多个成员对象，在创建派生类对象时，派生类的构造函数除了要负责本类成员的初始化外，还要调用基类和成员对象的构造函数，并向它们传递参数，以完成基类子对象和成员对象的建立和初始化。
- 派生类只能采用构造函数初始化列表的方式向基类或成员对象的构造函数传递参数，形式如下：
```cpp
派生类构造函数名(参数表):基类构造函数名(参数表),成员对象名1(参数表),…
{ //…… }
```

```cpp
class Point{
protected:
    int x,y;
public:
    Point(int a,int b=0)
    {
        x=a;  y=b;
        cout<<"constructing point("<<x<<","<<y<<")"<<endl;
    }
};
class Line:public Point
{
protected:
    int len;
public:
    Line(int a,int b,int l):Point(a,b)
    {
        len=l;
        cout<<"Constructing Line,len ..."<<len<<endl;
    }
};
int main()
{
    Line L1(1,2,3);
}
constructing point(1,2)
Constructing Line,len ...3
```
### 4.4.3 构造函数和析构函数调用次序

```cpp
class D : public B{
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0,a4;
    D( ) : a4(4),c2(2),c1(1),B(1) {
cout << "D-----5"<<endl;
    }
};
B-----1
C-----1
C-----2
A-----10
A-----0
A-----4
D-----5
```
- 派生类对象的构造
  * 先构造基类
  * 再构造成员
  * 最后构造自身（调用构造函数）
- 基类构造顺序由派生层次决定：
  * 最远的基类最先构造 成员构造顺序和定义顺序符合
- 析构函数的析构顺序与构造相反

## 4.5 多继承
### 4.5.0 多继承
多个基类继承
## 4.6 虚基类 虚继承
### 4.6.0 虚基类 虚继承
虚基类 class A: virtual public B{}
虚基类（Virtual Base Class）和虚继承（Virtual Inheritance）是 C++ 中用于解决多重继承中的问题的特性。

在多重继承中，如果一个派生类从多个基类继承同名的成员，可能会引发命名冲突和二义性的问题。为了解决这个问题，可以使用虚继承和虚基类。

虚继承使得共享基类成为可能，虚基类是在多重继承结构中被声明为虚基类的基类。它具有以下特点：

虚基类是通过在继承关系中声明 virtual 关键字来定义的。派生类必须使用 virtual 继承关键字来指示对虚基类的继承。

在虚继承中，无论有多少个派生类，只会有一个共享的虚基类子对象。这意味着虚基类的成员在派生类中只存在一份拷贝。

当派生类进行虚继承时，虚基类子对象由最派生类负责初始化，它通过构造函数的初始化列表进行初始化。

如果多个基类都继承自同一个虚基类，则共享该虚基类的成员只有一份拷贝。

虚基类和虚继承的主要目的是解决菱形继承（Diamond Inheritance）中的问题，也就是多条继承路径导致的二义性和冗余拷贝。通过使用虚基类和虚继承，可以确保每个虚基类在派生类中只有一份拷贝，从而消除了二义性，减少了资源的冗余。

虚继承需要谨慎使用，因为它引入了额外的复杂性。同时，在设计多重继承的类层次结构时，需要仔细考虑哪些基类应该声明为虚基类，以及如何组织继承关系，以避免二义性和不必要的复杂性。
```cpp
class Base {
public:
    int value;
};

class Derived1 : virtual public Base { /* ... */ };
class Derived2 : virtual public Base { /* ... */ };

class MostDerived : public Derived1, public Derived2 {
    // 访问虚基类成员
    void func() {
        value = 10;                // 直接访问虚基类成员
        Derived1::value = 20;      // 使用作用域解析符访问 Derived1 的虚基类成员
        Derived2::value = 30;      // 使用作用域解析符访问 Derived2 的虚基类成员
    }
};
```
对于上述示例中的派生类 MostDerived，虚基类 Base 的成员 value 在内存中只有一个拷贝。尽管 MostDerived 继承了两个虚基类 Derived1 和 Derived2，它们都派生自同一个虚基类 Base，但是 Base 类的成员 value 只存在于派生类 MostDerived 的对象中一份。
这意味着，当我们通过派生类 MostDerived 的对象访问 value 成员变量时，无论是通过 MostDerived 自身的成员函数，还是通过 Derived1 或 Derived2 的成员函数，都是访问同一个 value 成员。
因此，在示例中的分布中，只有一个 value 成员。

总结起来，虚基类和虚继承是用于解决多重继承中命名冲突和二义性的机制，它们允许在多个派生类中共享同一份基类成员，并且通过在继承关系中使用 virtual 关键字声明。
## 4.7 多重继承构造函数和析构函数的执行顺序
### 4.7.0 多重继承构造函数和析构函数的执行顺序

[**按虚继承顺序构造 -> 按非虚继承顺序构造 -> 按成员变量声明顺序构造 -> 派生类自身构造**](https://wangxiaokun.github.io/Archives/2019/01/29/C++-Constructor-destructor-Order.html)

## 4.8 重载 重写
### 4.8.1 重载
- 函数名相同的这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同，即参数列表不同。返回值类型没有要求，在同一作用域中。

### 4.8.2 重写
- 子类继承了父类，父类中的函数是虚函数，在子类中重新定义了这个虚函数，这种情况是**重写**

### 4.8.3 静态函数和虚函数区别
  - 静态函数在编译的时候就已经确定运行时机，
  - 虚函数在运行的时候动态绑定。
  - 虚函数因为用了虚函数表机制，调用的时候会增加一次内存开销

## 4.10 继承无覆盖
## 4.11 继承虚函数的实例
### 4.11.0 继承虚函数的几个实例

1. 无继承无虚函数
2. 无继承有虚函数
3. 单继承无虚函数
4. 单继承有虚函数
5. 多继承无虚继承无虚函数
6. 多继承无虚继承有虚函数
7. 多继承有虚继承无虚函数
8. 多继承有虚继承有虚函数

|         | 无继承 | 单继承 | 多继承无虚继承 | 多继承 虚继承 |
| ------- | ----- | ----- | ------------- | ------------ |
| 无虚函数 |       |       |               |              |
| 有虚函数 |       |       |               |              |

### 1. 无继承无虚函数
#### - 代码/Codes
```cpp
#include <iomanip>
#include <functional>

class Base
{
public:
    Base(int i) :baseI(i){};
    void print(void){ std::cout << "Call Base::print()" << &Base::print << std::endl; }
    void setI(){std::cout<<"Call Base::setI()"<<std::endl;}
    ~Base(){std::cout << "Call Base::~Base()" << std::endl;}
    friend std::ostream &operator<<(std::ostream &os, Base &a)
    {
        os << "Print Base 's baseI is :" << a.baseI  << std::endl;
        return os;
    }
private:
    int baseI;
};
int main()
{
    Base b(1000);
    std::cout << "&b: " << &b << std::endl;
    std::cout << std::hex <<  (long *)(&b) << std::endl;
    std::cout << std::hex <<  (intptr_t *)(&b) << std::endl;
    std::cout << "sizeof(b):" << sizeof(b) << std::endl;
    std::cout << "sizeof(Base):" << sizeof(Base) << std::endl;
    std::cout << "sizeof(int):" << sizeof(int) << std::endl;
    std::cout << "sizeof(long):" << sizeof(long)  << std::endl;
    std::cout << "sizeof(inptr_t):"<< sizeof(intptr_t) << std::endl;
    return 0;
}
```

#### - 运行结果/Run Results
```cpp
&b: 0x7fffffffe2f4
0x7fffffffe2f4
0x7fffffffe2f4
sizeof(b):4
sizeof(Base):4
sizeof(int):4
sizeof(long):8
sizeof(inptr_t):8
Call Base::~Base()
```
#### - 调试/GDB
```
    // 31          Base b(1000);
    // (gdb) p b
    // $1 = {baseI = 21845}
    // (gdb) p &b
    // $2 = (Base *) 0x7fffffffe2f4
    // (gdb) next
    // 32          std::cout << "&b: " << &b << std::endl;
    // (gdb)
    // &b: 0x7fffffffe2f4
    // 33          std::cout << std::hex <<  (long *)(&b) << std::endl;
    // (gdb)
    // 0x7fffffffe2f4
    // 34          std::cout << std::hex <<  (intptr_t *)(&b) << std::endl;
    // (gdb)
    // 0x7fffffffe2f4
    // 35          std::cout << "sizeof(b):" << sizeof(b) << std::endl;
    // (gdb) p b
    // $3 = {baseI = 1000}
    // (gdb) x /d 0x7fffffffe2f4
    // 0x7fffffffe2f4: 1000
```
### 2. 无继承有虚函数
#### - 代码/Codes
```cpp
#include <iostream>
#include <iomanip>
#include <functional>

class Base
{
public:

    Base(int i) :baseI(i){};

    virtual void print(void){ std::cout << "Call Base::print()" << &Base::print << std::endl; }

    virtual void setI(){std::cout<<"Call Base::setI()"<<std::endl;}

    virtual ~Base(){std::cout << "Call Base::~Base()" << std::endl;}

    friend std::ostream &operator<<(std::ostream &os, Base &a)
    {
	    os << "Print Base 's baseI is :" << a.baseI  << std::endl;
	    return os;
    }

private:

    int baseI;

};

int main()
{
    Base b(1000);
    std::cout << "sizeof(b)   :" << sizeof(b)    << std::endl; // 16
    std::cout << "sizeof(Base):" << sizeof(Base) << std::endl; // 16

    std::cout << "&b:" << std::hex <<  (intptr_t *)(&b) << std::endl; // 0x7fffffffe2e0
    intptr_t* b_vptr = (intptr_t *)(&b) ;
    std::cout << "b_vptr         :" << std::hex <<  b_vptr  << std::endl;//0x7fffffffe2e0
    std::cout << "(intptr_t*)(&b):" << std::hex <<  (intptr_t*)(&b)  << std::endl;//0x7fffffffe2e0
    std::cout << "(intptr_t*)*(intptr_t*)(&b):" << std::hex <<  (intptr_t*)*(intptr_t*)(&b)  << std::endl; // 0x555555756d10

    std::cout << "((intptr_t*)(* b_vptr         ))[0]:" << std::hex << ((intptr_t*)(*b_vptr))[0] << std::endl; // 5555555554ac
    std::cout << "((intptr_t*)(*(intptr_t *)(&b)))[0]:" << std::hex << ((intptr_t*)(*(intptr_t *)(&b)))[0] << std::endl; // 5555555554ac

    std::cout << "((intptr_t *)(* (intptr_t *) * (intptr_t *)(&b))    ):"
  << std::hex <<  ((intptr_t *)(* (intptr_t *) * (intptr_t *)(&b))    ) << std::endl;
    std::cout << " (intptr_t *)(*((intptr_t *)(*((intptr_t *)(&b)))+1)):"
  << std::hex <<   (intptr_t *)(*((intptr_t *)(*((intptr_t *)(&b)))+1)) << std::endl;
    std::cout << "((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +1)):"
  << std::hex <<  ((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +1)) << std::endl;
    std::cout << "((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +2)):"
  << std::hex <<  ((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +2)) << std::endl;
    std::cout << "((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +3)):"
  << std::hex <<  ((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +3)) << std::endl;
    std::cout << "((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +4)):"
  << std::hex <<  ((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +4)) << std::endl;
    std::cout << "((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +5)):"
  << std::hex <<  ((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +5)) << std::endl;
    std::cout << "((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +6)):"
  << std::hex <<  ((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +6)) << std::endl;

    using Func1 = void(*)(Base  *);
    Func1 test1 = (Func1)(*(long *)*(long *)(&b));// << std::endl;
    test1(&b); // Call Base::print()1
    using Func2 = void(*)();
    Func2 test2 = (Func2)(*(long *)*(long *)(&b));// << std::endl;
    test2(); // Call Base::print()1
    std::cout << "typeid(b):" << (typeid(b).name())<< std::endl; // 4Base
    std::cout << "sizeof(typeid(b):" <<  sizeof(typeid(b))<< std::endl; // 10
    return 0;
}
```
#### - 运行/Run Results
```
//sizeof(b)   :16
//sizeof(Base):16
//&b:0x7fffffffe2e0
//b_vptr         :0x7fffffffe2e0
//(intptr_t*)(&b):0x7fffffffe2e0
//(intptr_t*)*(intptr_t*)(&b):0x555555756d10
//((intptr_t*)(* b_vptr         ))[0]:5555555554ac
//((intptr_t*)(*(intptr_t *)(&b)))[0]:5555555554ac
//((intptr_t *)(* (intptr_t *) * (intptr_t *)(&b))    ):0x5555555554ac
// (intptr_t *)(*((intptr_t *)(*((intptr_t *)(&b)))+1)):0x555555555514
//((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +1)):0x555555555514
//((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +2)):0x55555555554c
//((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +3)):0x555555555592
//((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +4)):0x7ffff7dc67f8
//((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +5)):0x555555555914
//((intptr_t *) *((intptr_t *) * (intptr_t *)(&b)  +6)):0x1
//Call Base::print()1
//Call Base::print()1
//typeid(b):4Base
//sizeof(typeid(b):10
////////////////////////////////////////////////////////////////////////////////
```
#### - 调试/GDB
```
//(gdb) p b
//$10 = {_vptr.Base = 0x555555756d10 <vtable for Base+16>, baseI = 1000}
vptr 0x555555756d10
//(gdb) p &b
//$11 = (Base *) 0x7fffffffe2e0
//(gdb) info vtbl b
//vtable for 'Base' @ 0x555555756d10 (subobject @ 0x7fffffffe2e0):
//[0]: 0x5555555554ac <Base::print()>
//[1]: 0x555555555514 <Base::setI()>
//(gdb) p (intptr_t *)*(intptr_t*)b_vptr
//$12 = (intptr_t *) 0x555555756d10 <vtable for Base+16>

//(gdb) x /8xg 0x555555756d10
//0x555555756d10 <_ZTV4Base+16>:  0x00005555555554ac      0x0000555555555514
//0x555555756d20 <_ZTV4Base+32>:  0x000055555555554c      0x0000555555555592
//0x555555756d30 <_ZTI4Base>:     0x00007ffff7dc67f8      0x0000555555555914
//0x555555756d40: 0x0000000000000001      0x0000000000000001
0x00005555555554ac
0x    5555555554ac
<Base::print()>
//(gdb) x /8xg 0x00005555555554ac
//0x5555555554ac <Base::print()>: 0x54415541e5894855      0xe87d894810ec8348
//0x5555555554bc <Base::print()+16>:      0x4800000188358d48      0x91e800201b563d8d
//0x5555555554cc <Base::print()+32>:      0xbc41c28948fffff6      0x0000bd4100000001
//0x5555555554dc <Base::print()+48>:      0xc08548e0894c0000      0xc689c0b60fc0950f
//
0x0000555555555514
0x    555555555514
<Base::setI()>
//(gdb) x /8xg 0x0000555555555514
//0x555555555514 <Base::setI()>:  0x10ec8348e5894855      0x37358d48f87d8948
//0x555555555524 <Base::setI()+16>:       0x1af23d8d48000001      0x48fffff62de80020
//0x555555555534 <Base::setI()+32>:       0x201a93058b48c289      0xe8d78948c6894800
//0x555555555544 <Base::setI()+48>:       0x90c3c990fffff638      0x10ec8348e5894855
0x000055555555554c
0x    55555555554c
<Base::~Base()>
//(gdb) x /8xg 0x000055555555554c
//0x55555555554c <Base::~Base()>: 0x10ec8348e5894855      0xb1158d48f87d8948
//0x55555555555c <Base::~Base()+16>:      0x48f8458b48002017      0x000103358d481089
//0x55555555556c <Base::~Base()+32>:      0x00201aac3d8d4800      0xc28948fffff5e7e8
//0x55555555557c <Base::~Base()+48>:      0x4800201a4d058b48      0xf5f2e8d78948c689
0x0000555555555592
0x    555555555592
<Base::~Base()>
//(gdb) x /8xg 0x0000555555555592
//0x555555555592 <Base::~Base()>: 0x10ec8348e5894855      0xf8458b48f87d8948
//0x5555555555a2 <Base::~Base()+16>:      0xffffffa2e8c78948      0x000010bef8458b48
//0x5555555555b2 <Base::~Base()+32>:      0xfff5b5e8c7894800      0x5741001f0fc3c9ff
//0x5555555555c2 <__libc_csu_init+2>:     0x415541d789495641      0x00201716258d4c54
//
//(gdb) x /8xg 0x00007ffff7dc67f8
//0x7ffff7dc67f8: 0x00007ffff7add1c0      0x00007ffff7add1e0
//0x7ffff7dc6808: 0x00007ffff7adfb80      0x00007ffff7adfb80
//0x7ffff7dc6818: 0x00007ffff7add310      0x00007ffff7add130
//0x7ffff7dc6828: 0x00007ffff7add2c0      0x00007ffff7add200
//
//(gdb) x /8xg 0x0000555555555914
//0x555555555914 <_ZTS4Base>:     0x0000006573614234      0x000000b03b031b01
//0x555555555924: 0xfffff1f400000015      0xfffff2c4000000fc
//0x555555555934: 0xfffff2d400000124      0xfffff3de000000cc
//0x555555555944: 0xfffff9c200000304      0xfffffa0b0000032c

//(gdb) info vtbl b
//vtable for 'Base' @ 0x555555756d10 (subobject @ 0x7fffffffe2e0):
//[0]: 0x5555555554ac <Base::print()>
//[1]: 0x555555555514 <Base::setI()>
//(gdb) x /8xg 0x555555756d10
//0x555555756d10 <_ZTV4Base+16>:  0x00005555555554ac      0x0000555555555514
//0x555555756d20 <_ZTV4Base+32>:  0x000055555555554c      0x0000555555555592
//0x555555756d30 <_ZTI4Base>:     0x00007ffff7dc67f8      0x0000555555555914
//0x555555756d40: 0x0000000000000001      0x0000000000000001
//(gdb) p sizeof(typeid(b))
//$13 = 16
//(gdb) p (typeid(b))
//$14 = {_vptr.type_info = 0x7ffff7dc67f8, __name = 0x555555555914 <typeinfo name for Base> "4Base"}
//
//(gdb) p sizeof(b)
//$22 = 16
//(gdb) p b.baseI
//$23 = 1000
//(gdb) p &b.baseI
//$24 = (int *) 0x7fffffffe2e8
//(gdb) p b.print
//$25 = {void (Base * const)} 0x5555555554ac <Base::print()>
//(gdb) p b.setI
//$26 = {void (Base * const)} 0x555555555514 <Base::setI()>

```
```
Base --> +------------+
         |- baseI:int |
         +------------+
         |+  print()  |
         +------------+
         |+  setI()   |
         +------------+
		 |+ operator<<|
         +------------+


 struct B                                          Base VTable
 object                                            +--------------+
     0 - class Base  0x7fffffffe2e0                | RTTI for Base|
     0 -  _vptr.Base --------------------------->  +--------------+
     8 -   int baseI                0x555555756d10 | Base::print()|  0x5555555554ac
                                                   +--------------+
sizeof(Base): 16    align: 8        0x555555756d18 | Base::setI() |  0x555555555514
                                                   +--------------+
                                    0x555555756d20 | Base::~Base()|  0x55555555554c
                                                   +--------------+
                                                   | Base::~Base()|  0x555555555592
                                                   +--------------+


Vtable for Base
Base::_ZTV4Base: 6 entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI4Base)
16    (int (*)(...))Base::print
24    (int (*)(...))Base::setI
32    (int (*)(...))Base::~Base
40    (int (*)(...))Base::~Base

Class Base
   size=16 align=8
   base size=12 base align=8
Base (0x0x7f4c182ac660) 0
    vptr=((& Base::_ZTV4Base) + 16)

(gdb) x /8xg 0x555555756d10-16
0x555555756d00 <_ZTV4Base>:     0x0000000000000000      0x0000555555756d30
0x555555756d10 <_ZTV4Base+16>:  0x00005555555554ac      0x0000555555555514
0x555555756d20 <_ZTV4Base+32>:  0x000055555555554c      0x0000555555555592
0x555555756d30 <_ZTI4Base>:     0x00007ffff7dc67f8      0x0000555555555914
0x     555555756d30
0x0000 555555756d30
0x0000555555756d30
0x0000 7ffff7dc67f8

0x555555756d08 <vtable for Base+8>:
<_ZTV4Base+8> 指向 typeinfo <typeinfo for Base>
0x555555756d30

(gdb) x /8c 0x0000555555555914
0x555555555914 <_ZTS4Base>:     52 '4'  66 'B'  97 'a'  115 's' 101 'e' 0 '\000'        0 '\000'        0 '\000'

(gdb) x /160xb 0x555555756d00
0x555555756d00 <vtable for Base>:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x555555756d08 <vtable for Base+8>:     0x30    0x6d    0x75    0x55    0x55    0x55    0x00    0x00
0x555555756d10 <vtable for Base+16>:    0xac    0x54    0x55    0x55    0x55    0x55    0x00    0x00
0x555555756d18 <vtable for Base+24>:    0x14    0x55    0x55    0x55    0x55    0x55    0x00    0x00
0x555555756d20 <vtable for Base+32>:    0x4c    0x55    0x55    0x55    0x55    0x55    0x00    0x00
0x555555756d28 <vtable for Base+40>:    0x92    0x55    0x55    0x55    0x55    0x55    0x00    0x00
0x555555756d30 <typeinfo for Base>:     0xf8    0x67    0xdc    0xf7    0xff    0x7f    0x00    0x00
0x555555756d38 <typeinfo for Base+8>:   0x14    0x59    0x55    0x55    0x55    0x55    0x00    0x00
```
### 3. 单继承无虚函数
#### - 代码/Codes
```cpp
#include <iostream>
#include <iomanip>
#include <functional>

class Base
{
public:
    Base(int i) :baseI(i){};
    void print(void){ std::cout << "Call Base::print()" << std::endl; }
    void print(int a ){ std::cout << "Call Base::print(a)" << a << std::endl; }
    void setI(){std::cout<<"Call Base::setI()"<<std::endl;}
    void getaddI() { std::cout << "The address of baseI :" << &(this->baseI)<< ", baseI value:"<<std::dec << baseI << std::endl;}
    ~Base(){std::cout << "Call Base::~Base()" << std::endl;}
    friend std::ostream &operator<<(std::ostream &os, Base &a)
    {
	    os << "Print Base 's baseI is :" << a.baseI  << std::endl;
	    return os;
    }
private:
    int baseI;
};

// Base print()        Derived print()
//      print(int)             ->
//      setI()                 ->
//      getaddI()              getaddI()
//      baseI                  derivedI

class Derived: public Base
{
public:
    Derived(int d=1): Base(d),derivedI(2){std::cout << "Call Derived Ctor" << derivedI << std::endl;};
    void print(void){ std::cout << "Call Derived::print()" << &Derived::print << std::endl; }
    void getaddI() { std::cout << "The address of derivedI:"<< &(derivedI) << ", derivedI value:" << derivedI << std::endl;}
    ~Derived(){std::cout << "Call Derived::~Derived()" << std::endl;}
private:
    int derivedI;
};



int main()
{
    Base    b(1000);
    Derived d(200);
    std::cout << "sizeof(b)   :" << sizeof(b) << std::endl; // 4
    std::cout << "sizeof(Base):" << sizeof(Base) << std::endl; // 4
    std::cout << "sizeof(Derived):" << sizeof(Derived) << std::endl; // 8

    std::cout << "*(int *)(&b):" << std::dec <<*(int *)(&b) << std::endl; // 1000
    std::cout << "*(int *)(&d):" << std::dec <<*(int *)(&d) << std::endl; // 200

    std::cout << "&b:" << std::hex <<  (intptr_t *)(&b) << std::endl; // &b:0x7fffffffe2ec
    std::cout << "&d:" << std::hex <<  (intptr_t *)(&d) << std::endl; // &d:0x7fffffffe2f0
    std::cout << "Both function:" << std::endl;
    b.getaddI(); // The address of baseI :0x7fffffffe2ec, baseI value:1000
    d.getaddI(); // The address of derivedI:0x7fffffffe2f4, derivedI value:2
    // +4 Base占位

    std::cout << "typeid(b):" << typeid(b).name()<< std::endl; // 4Base
    std::cout << "typeid(d):" << typeid(Base).name() << std::endl; // 4Base
    std::cout << "typeid(d):" << typeid(Derived).name() << std::endl; // 7Derived

    std::cout << "Only Base function:" << std::endl;
    b.setI(); // Call Base::setI()
    d.setI(); // Call Base::setI()

    std::cout << "Only Base function print:" << std::endl;
    b.print(1); // Call Base::print(a)1
    //d.print(1);
    //error: no matching function for call to ‘Derived::print(int)’
    return 0;
}
```
#### - 运行/Run Results
```
// Call Derived Ctor2
// sizeof(b)   :4
// sizeof(Base):4
// sizeof(Derived):8
// *(int *)(&b):1000
// *(int *)(&d):200
// &b:b:0x7fffffffe2ec
// &d:d:0x7fffffffe2f0
// Both function:
// The address of baseI :0x7fffffffe2ec, baseI value:1000
// The address of derivedI:0x7fffffffe2f4, derivedI value:2
// typeid(b):4Base
// typeid(d):4Base
// typeid(d):7Derived
// Only Base function:
// Call Base::setI()
// Call Base::setI()
// Only Base function print:
// Call Base::print(a)1
// Call Derived::~Derived()
// Call Base::~Base()
// Call Base::~Base()
```
#### - 调试/GDB
```
// (gdb) p b
// $1 = {baseI = 1000}
// (gdb) p d
// $2 = {<Base> = {baseI = 200}, derivedI = 2}
// (gdb) p d.baseI
// $3 = 200
// (gdb) p &d.baseI
// $4 = (int *) 0x7fffffffe2f0
// (gdb) p &d.derivedI
// $5 = (int *) 0x7fffffffe2f4
```
### 4. 单继承有虚函数
#### - 代码/Codes
```cpp
#include <iostream>
#include <iomanip>
#include <functional>

class Base
{
public:

    Base(int i) :baseI(i){std::cout << "Call Base Ctor," << baseI << std::endl;};

    virtual void print(void){ std::cout << "Call Base::print()" << std::endl; }

    virtual void print(int a ){ std::cout << "Call Base::print(a)" << a << std::endl; }

    virtual void setI(){std::cout<<"Call Base::setI()"<<std::endl;}

    void getaddI() { std::cout << "The address of baseI :" << &(this->baseI)<< ", baseI value:"<<std::dec << baseI << std::endl;}

    virtual ~Base(){std::cout << "Call Base::~Base()" << std::endl;}

    friend std::ostream &operator<<(std::ostream &os, Base &a)
    {
	    os << "Print Base 's baseI is :" << a.baseI  << std::endl;
	    return os;
    }

private:

    int baseI;

};
// Base                          Derived
//        Base(int)                        Derived(int)
//      v print()                        v print()
//      v print(int)
//      v setI()                         v -->
//        getaddI()                        getaddI()
//      v ~Base()                        v ~Derived()
//        baseI                             -->
//                                         derivedI

class Derived: public Base
{
public:
    Derived(int d=1): Base(d),derivedI(2){std::cout << "Call Derived Ctor," << derivedI << std::endl;};

    void print(void){ std::cout << "Call Derived::print()" << &Derived::print << std::endl; }

    void getaddI() { std::cout << "The address of derivedI:"<< &(derivedI) << ", derivedI value:" << derivedI << std::endl;}

    ~Derived(){std::cout << "Call Derived::~Derived()" << std::endl;}
private:
    int derivedI;
};



int main()
{
    Base    b(1000);
    Derived d(200);
    // 8 + 4 + 4
    std::cout << "sizeof(b)   :" << sizeof(b) << ",sizeof(Base)   :" << sizeof(Base)    << std::endl; // 16
    std::cout << "sizeof(d)   :" << sizeof(d) << ",sizeof(Derived):" << sizeof(Derived) << std::endl; // 16

    std::cout << "*(int *)(&b):" << std::dec <<*(int *)(&b) << std::endl;
    std::cout << "*(int *)(&d):" << std::dec <<*(int *)(&d) << std::endl;

    std::cout << "&b:" << std::hex <<  (intptr_t *)(&b) << std::endl; // 0x7fffffffe2d0
    std::cout << "&d:" << std::hex <<  (intptr_t *)(&d) << std::endl; // 0x7fffffffe2e0
    std::cout << "Both function:" << std::endl;
    b.getaddI();// The address of baseI :0x7fffffffe2d8, baseI value:1000
    d.getaddI();// The address of derivedI:0x7fffffffe2ec, derivedI value:2

    std::cout << "typeid(b):" << typeid(b).name()<< std::endl;        // 4Base
    std::cout << "typeid(d):" << typeid(Base).name() << std::endl;    // 4Base
    std::cout << "typeid(d):" << typeid(Derived).name() << std::endl; // 7Derived

    std::cout << "Only Base function:" << std::endl;
    b.setI();// Call Base::setI()
    d.setI();// Call Base::setI()

    std::cout << "Only Base function print:" << std::endl;
    b.print(1);// Call Base::print(a)1
    //d.print(1);
    //error: no matching function for call to ‘Derived::print(int)’
    Base *pb = new Base(300);
    Derived *pd = new Derived(400);
    Base *pdb = new Derived(500);

    std::cout << "vptr (intptr_t *) * (intptr_t*)(pb):" << std::hex << (intptr_t *) (*(intptr_t*)(pb))  << std::endl; // 0x555555756cc8
    std::cout << "vptr (intptr_t *) * (intptr_t*)(pd):" << std::hex <<  (intptr_t *) *(intptr_t*)(pd)  << std::endl; // 0x555555756c90
    std::cout << "vptr (intptr_t *) * (intptr_t*)(pdb):" << std::hex <<  (intptr_t *) *(intptr_t*)(pdb)  << std::endl; // 0x555555756c90

    std::cout << "vtable for 'Base' @ " << (intptr_t *)*(intptr_t *)(pb)
              << " (subobject @ "       <<              (intptr_t *)(pb) << "):" << std::endl;
    std::cout << "[0]:" << (intptr_t *)*((intptr_t *)*(intptr_t *)(pb)+0)<< std::endl; // 0x5555555557fe
    std::cout << "[1]:" << (intptr_t *)*((intptr_t *)*(intptr_t *)(pb)+1)<< std::endl; // 0x555555555836
    std::cout << "[2]:" << (intptr_t *)*((intptr_t *)*(intptr_t *)(pb)+2)<< std::endl; // 0x555555555880

    std::cout << typeid(pdb).name() << std::endl;// P4Base

    return 0;
}
```
#### - 运行/Run Results
```
// Call Base Ctor,1000
// Call Base Ctor,200
// Call Derived Ctor,2
// sizeof(b)   :16,sizeof(Base)   :16
// sizeof(d)   :16,sizeof(Derived):16
// *(int *)(&b):1433758920
// *(int *)(&d):1433758864
// &b:0x7fffffffe2d0
// &d:0x7fffffffe2e0
// Both function:
// The address of baseI :0x7fffffffe2d8, baseI value:1000
// The address of derivedI:0x7fffffffe2ec, derivedI value:2
// typeid(b):4Base
// typeid(d):4Base
// typeid(d):7Derived
// Only Base function:
// Call Base::setI()
// Call Base::setI()
// Only Base function print:
// Call Base::print(a)1
// Call Base Ctor,300
// Call Base Ctor,400
// Call Derived Ctor,2
// Call Base Ctor,500
// Call Derived Ctor,2
// vptr (intptr_t *) * (intptr_t*)(pb):0x555555756cc8
// vptr (intptr_t *) * (intptr_t*)(pd):0x555555756c90
// vptr (intptr_t *) * (intptr_t*)(pdb):0x555555756c90
// vtable for 'Base' @ 0x555555756cc8 (subobject @ 0x55555576a280):
// [0]:0x5555555557fe
// [1]:0x555555555836
// [2]:0x555555555880
// P4Base
// Call Derived::~Derived()
// Call Base::~Base()
// Call Base::~Base()
```
#### - 调试/GDB
```
//(gdb) info vtbl pb
//vtable for 'Base' @ 0x555555756cc8 (subobject @ 0x55555576a280):
//[0]: 0x5555555557fe <Base::print()>
//[1]: 0x555555555836 <Base::print(int)>
//[2]: 0x555555555880 <Base::setI()>
//(gdb) info vtbl pd
//vtable for 'Derived' @ 0x555555756c90 (subobject @ 0x55555576a2a0):
//[0]: 0x555555555a44 <Derived::print()>
//[1]: 0x555555555836 <Base::print(int)>
//[2]: 0x555555555880 <Base::setI()>
//(gdb) info vtbl pdb
//vtable for 'Base' @ 0x555555756c90 (subobject @ 0x55555576a2c0):
//[0]: 0x555555555a44 <Derived::print()>
//[1]: 0x555555555836 <Base::print(int)>
//[2]: 0x555555555880 <Base::setI()>
//
//(gdb) p typeid(pb)
//$25 = {_vptr.type_info = 0x7ffff7dc73d8, __name = 0x555555555e84 <typeinfo name for Base*> "P4Base"}
//(gdb) p typeid(pd)
//could not find typeinfo symbol for 'Derived*'
//(gdb) p typeid(pdb)
//$26 = {_vptr.type_info = 0x7ffff7dc73d8, __name = 0x555555555e84 <typeinfo name for Base*> "P4Base"}
//
//(gdb) x /8cb 0x555555555e84
//0x555555555e84 <_ZTSP4Base>:    80 'P'  52 '4'  66 'B'  97 'a'  115 's' 101 'e' 0 '\000'        0 '\000'

//(gdb) info vtbl pdb
//vtable for 'Base' @ 0x555555756c90 (subobject @ 0x55555576a2c0):
//[0]: 0x555555555a44 <Derived::print()>
//[1]: 0x555555555836 <Base::print(int)>
//[2]: 0x555555555880 <Base::setI()>

//(gdb) p /a *(void **) 0x555555756c90@6
//$22 = {0x555555555a44 <Derived::print()>, 0x555555555836 <Base::print(int)>, 0x555555555880 <Base::setI()>,
//  0x555555555b1c <Derived::~Derived()>, 0x555555555b6e <Derived::~Derived()>, 0x0}
//(gdb) p /a *((void **) 0x555555756c90-1)
//$23 = 0x555555756d10 <_ZTI7Derived>
//(gdb) p /a *((void **) 0x555555756c90-2)
//$24 = 0x0
//
// Base
// 0x555555756cc8
//[0]: 0x5555555557fe <Base::print()>
//[1]: 0x555555555836 <Base::print(int)>
//[2]: 0x555555555880 <Base::setI()>
// Derived
// 0x555555756c90
//[0]: 0x555555555a44 <Derived::print()>
```
#### - 布局

\<pre>
(gdb) p d
$4 = {\<Base> = {_vptr.Base = <span style="background-color:#8A2BE2;">0x555555756c90</span> <vtable for Derived+16>, baseI = 200}, derivedI = 2}

(gdb) p b
$3 = {_vptr.Base = <span style="background-color: #00BFFF;">0x555555756cc8</span> <vtable for Base+16>, baseI = 1000}
```
(gdb) p typeid(b)
$1 = {\_vptr.type_info = <font color="HotPink">0x7ffff7dc67f8</font> <vtable for __cxxabiv1::__class_type_info+16>, __name = <font color="DeepPink">0x555555555e99</font> <typeinfo name for Base> "4Base"}

(gdb) p typeid(d)
$2 = {_vptr.type_info = <font color="Orange">0x7ffff7dc7438</font> <vtable for __cxxabiv1::__si_class_type_info+16>, __name = <font color= "#ff6600;">0x555555555e90</font> <typeinfo name for Derived> "7Derived"}

(gdb) p typeid(pb)
$3 = {_vptr.type_info = <font color="Lime">0x7ffff7dc73d8</font> <vtable for __cxxabiv1::__pointer_type_info+16>, __name = <font color="LimeGreen">0x555555555e84</font> <typeinfo name for Base*> "P4Base"}

(gdb) p typeid(pdb)
$4 = {_vptr.type_info = <font color="Lime">0x7ffff7dc73d8</font> <vtable for __cxxabiv1::__pointer_type_info+16>, __name = <font color="LimeGreen">0x555555555e84</font> <typeinfo name for Base*> "P4Base"}

                                                                Address                                              Value

                                                   0x555555756c80 &lt;_ZTV7Derived&gt;:     +----------------------------------------+
                                                                                      |       offset   :   0x0                 |
                                                   0x555555756c88 &lt;_ZTV7Derived+8&gt;:   +----------------------------------------+
                +----------------+                                                    |       type_info:  &lt;_ZTI7Derived&gt;       | <span style="background-color:#A9A9A9;">0x555555756d10</span>
    Derived --&gt; |  _vptr.Base    |  ------------&gt;  <span style="background-color:#8A2BE2;">0x555555756c90</span> &lt;_ZTV7Derived+16&gt;:  +----------------------------------------+
                +----------------+                                                    |+v  &lt;Derived::print()&gt;                  | 0x555555555a44
                | - baseI:int    |                 0x555555756c98 &lt;_ZTV7Derived+24&gt;:  +----------------------------------------+
                +----------------+                                                    |+v  &lt;Base::print(int)&gt;                  | 0x555555555836
                | - derivedI:int |                 0x555555756ca0 &lt;_ZTV7Derived+32&gt;:  +----------------------------------------+
                +----------------+                                                    |+v  &lt;Base::setI()&gt;                      | 0x555555555880
    		 +------------------------+		       0x555555756ca8 &lt;_ZTV7Derived+40&gt;:  +----------------------------------------+
             |+   getaddI()           |                                               |+v  &lt;Derived::~Derived()&gt; [complete]    | 0x555555555b1c
    		 +------------------------+		       0x555555756cb0 &lt;_ZTV7Derived+48&gt;:  +----------------------------------------+
             |+   operator&lt;&lt;          |                                               |+v  &lt;Derived::~Derived()&gt; [deleting]    | 0x555555555b6e
             +------------------------+                                               +----------------------------------------+


                                                                Address                                              Value

                                                   0x555555756cb8 &lt;_ZTV4Base&gt;:        +----------------------------------+
                                                                                      |       offset   :   0x0           |
                                                   0x555555756cc0  &lt;_ZTV4Base+8&gt;:     +----------------------------------+
             +-------------+                                                          |       type_info:   &lt;_ZTI4Base&gt;   | <span style="background-color:#FFD700">0x555555756d28</span>
    Base --&gt; |  _vptr.Base | ------------------&gt;   <span style="background-color: #00BFFF;">0x555555756cc8</span> &lt;_ZTV4Base+16&gt;:     +----------------------------------+
             +-------------+                                                          |+v  &lt;Base::print()&gt;               | 0x5555555557fe
             |- baseI:int  |                       0x555555756cd0 &lt;_ZTV4Base+24&gt;:     +----------------------------------+
             +-------------+                                                          |+v  &lt;Base::print(int)&gt;            | 0x555555555836
                                                   0x555555756cd8 &lt;_ZTV4Base+32&gt;:     +----------------------------------+
                                                                                      |+v  &lt;Base::setI()&gt;                | 0x555555555880
    		 +------------------------+		       0x555555756ce0 &lt;_ZTV4Base+40&gt;:     +----------------------------------+
             |+   getaddI()           |                                               |+v  &lt;Base::~Base()&gt; [complete]    | 0x555555555938
    		 +------------------------+		       0x555555756ce8 &lt;_ZTV4Base+48&gt;:     +----------------------------------+
             |+   operator&lt;&lt;          |                                               |+v  &lt;Base::~Base()&gt; [deleting]    | 0x55555555597e
             +------------------------+                                               +----------------------------------+

    										       0x555555756cf0 &lt;_ZTIP4Base&gt;:       &lt;_ZTVN10__cxxabiv119__pointer_type_infoE+16&gt;  <font color="Lime">0x7ffff7dc73d8</font>
    										       0x555555756cf8 &lt;_ZTIP4Base+8&gt;:     &lt;_ZTSP4Base&gt;                                  <font color="LimeGreen">0x555555555e84  80 'P'  52 '4'  66 'B'  97 'a'  115 's' 101 'e' 0 '\000'</font>
    										       0x555555756d00 &lt;_ZTIP4Base+16&gt;:    offset                                        0x0
    										       0x555555756d08 &lt;_ZTIP4Base+24&gt;:    &lt;_ZTI4Base&gt;                                   <span style="background-color:#FFD700">0x555555756d28</span>
    										       <span style="background-color:#A9A9A9;">0x555555756d10</span> &lt;_ZTI7Derived&gt;:     &lt;_ZTVN10__cxxabiv120__si_class_type_infoE+16&gt; <font color="Orange">0x7ffff7dc7438</font>
    										       ...
                                                   0x555555756d18 &lt;_ZTI7Derived+8&gt;:   &lt;_ZTS7Derived&gt;                                <font color= "#ff6600;">0x555555555e90 55 '7'  68 'D'  101 'e' 114 'r' 105 'i' 118 'v' 101 'e' 100 'd' 0 '\000'</font>
                                                   0x555555756d20 &lt;_ZTI7Derived+16&gt;:  &lt;_ZTI4Base&gt;                                   <span style="background-color:#FFD700">0x555555756d28</span>
                                                   <span style="background-color:#FFD700">0x555555756d28</span> &lt;_ZTI4Base&gt;:        &lt;_ZTVN10__cxxabiv117__class_type_infoE+16&gt;    <font color="HotPink">0x7ffff7dc67f8</font>
                                                   0x555555756d30 &lt;_ZTI4Base+8&gt;:      &lt;_ZTS4Base&gt;                                   <font color="DeepPink">0x555555555e99 52 '4'  66 'B'  97 'a'  115 's' 101 'e' 0 '\000'</font>
```
</pre>

### 5. 多继承无虚继承无虚函数
#### - 代码/Codes
```cpp
// Base1 Base1()     |  Derived Derived()   | Base2 Base2()
//       print()     |          print()     |       print()
//       print(int)  |             X        |       print(int)
//       setI()      |             ?        |       setI()
//       set1I()     |           >  <       |       set2I()
//       func1()                   ?        |       func1()
//       getaddI()   |          getaddI()   |       getaddI()
//       ~Base1()    |          ~Derived()  |       ~Base2()
//       base1I                  >  <               base2I
//                              derivedI
//         4                     4+4+4=12             4
#include <iostream>
#include <iomanip>
#include <functional>

class Base1
{
public:

    Base1(int i) :base1I(i){std::cout << "Call Base1 Ctor," << std::dec << base1I << std::endl;};

    void print(void){ std::cout << "Call Base1::print()" << std::endl; }

    void print(int a ){ std::cout << "Call Base1::print(a)" << a << std::endl; }

    void setI(){std::cout<<"Call Base1::setI()"<<std::endl;}

    void set1I(){std::cout<<"Call Base1::set1I()"<<std::endl;}

    void func1(){std::cout << "Call Base1::func1()" << std::endl;}

    void getaddI() { std::cout << "The address of base1I :" << &(this->base1I)<< ", base1I value:"<<std::dec << base1I << std::endl;}

    ~Base1(){std::cout << "Call Base1::~Base1()" << std::endl;}

    friend std::ostream &operator<<(std::ostream &os, Base1 &a)
    {
	    os << "Print Base1 's base1I is :" << a.base1I  << std::endl;
	    return os;
    }

private:

    int base1I;
};

class Base2
{
public:

    Base2(int i) :base2I(i){std::cout << "Call Base2 Ctor," << std::dec <<  base2I << std::endl;};

    void print(void){ std::cout << "Call Base2::print()" << std::endl; }

    void print(int a ){ std::cout << "Call Base2::print(a)" << a << std::endl; }

    void setI(){std::cout<<"Call Base2::setI()"<<std::endl;}

    void set2I(){std::cout<<"Call Base2::set2I()"<<std::endl;}

    void func1(){std::cout << "Call Base2::func1()" << std::endl;}

    void getaddI() { std::cout << "The address of base2I :" << &(this->base2I)<< ", base2I value:"<<std::dec << base2I << std::endl;}

    ~Base2(){std::cout << "Call Base2::~Base2()" << std::endl;}

    friend std::ostream &operator<<(std::ostream &os, Base2 &a)
    {
	    os << "Print Base2 's base2I is :" << a.base2I  << std::endl;
	    return os;
    }

private:

    int base2I;
};

class Derived: public Base1, public Base2
{
public:
    Derived(int d=1): Base1(1),Base2(2),derivedI(d){std::cout << "Call Derived Ctor," <<  std::dec << derivedI << std::endl;};

    void print(void){ std::cout << "Call Derived::print()" << &Derived::print << std::endl; }

    void getaddI() { std::cout << "The address of derivedI:"<< &(derivedI) << ", derivedI value:" << derivedI << std::endl;}

    ~Derived(){std::cout << "Call Derived::~Derived()" << std::endl;}
private:
    int derivedI;
};



int main()
{
    Base1   b1(10);
    Base2   b2(20);
    Derived d(200);
    std::cout << "sizeof(b1)   :" << sizeof(b1) << ",sizeof(Base1)   :" << sizeof(Base1)    << std::endl;//4
    std::cout << "sizeof(b2)   :" << sizeof(b2) << ",sizeof(Base2)   :" << sizeof(Base2)    << std::endl;//4
    std::cout << "sizeof(d)    :" << sizeof(d)  << ",sizeof(Derived) :" << sizeof(Derived) << std::endl; //12

    std::cout << "*(int *)(&b1):" << std::dec <<*(int *)(&b1) << std::endl; // 10
    std::cout << "*(int *)(&b2):" << std::dec <<*(int *)(&b2) << std::endl; // 10
    std::cout << "*(int *)(&d) :" << std::dec <<*(int *)(&d) << std::endl;  // 1

    std::cout << "&b1:" << std::hex <<  (intptr_t *)(&b1) << std::endl; // 0x7fffffffe248
    std::cout << "&b2:" << std::hex <<  (intptr_t *)(&b2) << std::endl; // 0x7fffffffe24c
    std::cout << "&d :" << std::hex <<  (intptr_t *)(&d) << std::endl;  // 0x7fffffffe26c

    std::cout << "typeid(b1):" << typeid(b1).name()<< std::endl; // 5Base1
    std::cout << "typeid(Base1):" << typeid(Base1).name() << std::endl; // 5Base1
    std::cout << "typeid(Base2):" << typeid(Base2).name() << std::endl; // 5Base2
    std::cout << "typeid(d):" << typeid(Derived).name() << std::endl; // 7Derived

    std::cout << "Both function:" << std::endl;
    // d.func1();
    // error: request for member ‘func1’ is ambiguous
    std::cout << " error: request for member ‘func1’ is ambiguous" <<std::endl;

    std::cout << "Only Base function:" << std::endl;
    d.set1I();
    d.set2I();
    std::cout << "Only Base function print:" << std::endl;
    // d.print(1);
    // error: no matching function for call to  Derived::print(int)’
    std::cout << " error: no matching function for call to  Derived::print(int)’" << std::endl;

    Base1 *pb1 = new Base1(300);
    Derived *pd = new Derived(400);
    Base1 *pdb = new Derived(500);

    std::cout << typeid(pb1).name() << std::endl; // P5Base1
    std::cout << typeid(pd).name() << std::endl; // P7Derived
    std::cout << typeid(pdb).name() << std::endl; // P5Base1

    return 0;
}
```
#### - 运行/Run Results
```cpp
//Call Base1 Ctor,10
//Call Base2 Ctor,20
//Call Base1 Ctor,1
//Call Base2 Ctor,2
//Call Derived Ctor,200
//sizeof(b1)   :4,sizeof(Base1)   :4
//sizeof(b2)   :4,sizeof(Base2)   :4
//sizeof(d)    :12,sizeof(Derived) :12
//*(int *)(&b1):10
//*(int *)(&b2):20
//*(int *)(&d) :1
//&b1:0x7fffffffe248
//&b2:0x7fffffffe24c
//&d :0x7fffffffe26c
//Both function:
//typeid(b1):5Base1
//typeid(Base1):5Base1
//typeid(Base2):5Base2
//typeid(d):7Derived
//Both function:
// error: request for member ‘func1’ is ambiguous
//Only Base function:
//Call Base1::set1I()
//Call Base2::set2I()
//Only Base function print:
// error: no matching function for call to  Derived::print(int)’
//Call Base1 Ctor,300
//Call Base1 Ctor,1
//Call Base2 Ctor,2
//Call Derived Ctor,400
//Call Base1 Ctor,1
//Call Base2 Ctor,2
//Call Derived Ctor,500
//P5Base1
//P7Derived
//P5Base1
//Call Derived::~Derived()
//Call Base2::~Base2()
//Call Base1::~Base1()
//Call Base2::~Base2()
//Call Base1::~Base1()
//
```
#### - 调试/GDB
```
//(gdb) x /4hw pb1
//0x55555576a280: 300     0       0       0
//(gdb) x /4hw pd
//0x55555576a2a0: 1       2       400     0
//(gdb) x /4hw pdb
//0x55555576a2c0: 1       2       500     0
//
//(gdb) x /4hw &b1
//0x7fffffffe248: 10      20      1433838208      21845
//(gdb) x /4hw &b2
//0x7fffffffe24c: 20      1433838208      21845   1433838240
//(gdb) x /4hw &d
//0x7fffffffe26c: 1       2       200     -1818930176

//(gdb) p b
//$11 = {i = {0, 1068498944}, d = 0.0625}
//(gdb) p d
//$12 = {<Base1> = {base1I = 1}, <Base2> = {base2I = 2}, derivedI = 200}
//(gdb) p b1
//$13 = {base1I = 10}
//(gdb) p b2
//$14 = {base2I = 20}
```

### 6. 多继承无虚继承有虚函数
#### - 代码/Codes

```cpp
               D vfunc2
            /    func3
          /      m_data5   \
A vfunc1                    \
  vfunc2                     \
  vfunc3                      \
   func1                       CD m_data_cd
   func2                      /
   m_data1                   /
   m_data2                  /
          \               /
              C vfunc1
                 func2
                 m_data1
                 m_data4

B vfunc1
   func2
   m_data3
#include <iostream>

class A
{
public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    void func1();
    void func2();
private:
    int m_data1, m_data2;
};
void A::vfunc1(){std::cout << "A::vfunc1" << std::endl;}
void A::vfunc2(){std::cout << "A::vfunc2" << std::endl;}
void A::vfunc3(){std::cout << "A::vfunc3" << std::endl;}
void A:: func1(){std::cout << "A::func1" << std::endl;}
void A:: func2(){std::cout << "A::func2" << std::endl;}

class B
{
public:
    virtual void vfunc1();
    void func2();
private:
    int m_data3;
};
void B::vfunc1(){std::cout << "B::vfunc1" << std::endl;}
void B:: func2(){std::cout << "B::func2" << std::endl;}

class C: public A
{
public:
    virtual void vfunc1();
    void func2();
private:
    int m_data1, m_data4;
};
void C::vfunc1(){std::cout << "C::vfunc1" << std::endl;}
void C:: func2(){std::cout << "C::func2" << std::endl;}

class D:public A
{
public:
    virtual void vfunc2();
    void func3();
private:
    int m_data5;
};
void D::vfunc2(){std::cout << "D::vfunc2" << std::endl;}
void D:: func3(){std::cout << "D::func3" << std::endl;}
//               D vfunc2
//             /    func3
//                  m_data5
// A vfunc1
//   vfunc2
//   vfunc3
//    func1
//    func2
//    m_data1
//    m_data2
//            \
//               C vfunc1
//                  func2
//                  m_data1
//                  m_data4
//
// B vfunc1
//    func2
//    m_data3
//
class AB: public A, public B
{
private:
    int m_data_ab;
};
class CD: public C, public D
{
private:
    int m_data_cd;
};
int main()
{
    std::cout <<
    "               D vfunc2                       \n"
    "            /    func3                        \n"
    "          /      m_data5   \\                 \n"
    "A vfunc1                    \\                \n"
    "  vfunc2                     \\               \n"
    "  vfunc3                      \\              \n"
    "   func1                       CD m_data_cd   \n"
    "   func2                      /               \n"
    "   m_data1                   /                \n"
    "   m_data2                  /                 \n"
    "          \\               /                  \n"
    "              C vfunc1                        \n"
    "                 func2                        \n"
    "                 m_data1                      \n"
    "                 m_data4                      \n"
    "                                              \n"
    "B vfunc1                                      \n"
    "   func2                                      \n"
    "   m_data3                                    \n"
    << std::endl;

    A  *  a = new A();
    B  *  b = new B();
    C  *  c = new C();
    D  *  d = new D();
    AB * ab = new AB();
    CD * cd = new CD();

    std::cout << "AB * = new AB()" << std::endl;
    //ab->vfunc1();
    //error: request for member ‘vfunc1’ is ambiguous
    std::cout <<"error: request for member ‘vfunc1’ is ambiguous" << std::endl;
    ab->vfunc2(); // A::vfunc2
    ab->vfunc3(); // A::vfunc3
    ab->func1();  // A::func1
    //ab->func2();
    // error: request for member ‘func2 is ambiguous
    std::cout <<"error: request for member ‘func2 is ambiguous" << std::endl;

    std::cout << "" << std::endl;

    //cd->vfunc2();
    //error: request for member ‘vfunc2’ is ambiguous

    std::cout << "A  * = new C ()" << std::endl;
    A * pc = new C();
    pc->vfunc1(); // C::vfunc1
    pc->vfunc2(); // A::vfunc2
    pc->vfunc3(); // A::vfunc3
    pc->func1();  // A::func1
    pc->func2();  // A::func2

    std::cout << "" << std::endl;

    std::cout << "A  * = new D ()" << std::endl;
    A * pd = new D();
    pd->vfunc1(); // A::vfunc1
    pd->vfunc2(); // D::vfunc2
    pd->vfunc3(); // A::vfunc3
    pd-> func1(); // A::func1
    pd-> func2(); // A::func2
    // pd-> func3();
    //  error: ‘class A’ has no member named ‘fun; did you mean ‘vfunc3’?
    std::cout << "error: ‘class A’ has no member naname func3; did you mean vfunc3? " << std::endl;

    // A * pcd = new CD();
    // error: ‘A’ is an ambiguous base of ‘CD’
    std::cout << "" << std::endl;
    std::cout << "error : A  * = new CD()" << std::endl;
    std::cout << "error: ‘A’ is an ambiguous base of ‘CD’"<< std::endl;

    std::cout << "" << std::endl;

    std::cout << "C  * = new C ()" << std::endl;
    C * pcc = new C();
    pcc->vfunc1(); // C::vfunc1
    pcc->vfunc2(); // A::vfunc2
    pcc->vfunc3(); // A::vfunc3
    pcc-> func1(); // A::func1
    pcc-> func2(); // C::func2

    std::cout << "" << std::endl;

    std::cout << "C  * = new CD()" << std::endl;
    C * pcd = new CD();
    pcd->vfunc1(); // C::vfunc1
    pcd->vfunc2(); // A::vfunc2
    pcd->vfunc3(); // A::vfunc3
    pcd-> func1();
    pcd-> func2(); // C::func2
    // pcd-> func3();
    // error: ‘class C’ has no member named ‘fun; did you mean ‘func2’?
    std::cout << "error: ‘class C’ has no member named func3" << std::endl;

    std::cout << "" << std::endl;

    std::cout << "D  * = new CD()" << std::endl;
    D * pdd = new CD();
    pdd->vfunc1(); // A::vfunc1
    pdd->vfunc2(); // D::vfunc2
    pdd->vfunc3(); // A::vfunc3
    pdd-> func1(); // A::func1
    pdd-> func2(); // A::func2
    pdd-> func3(); // D::func3
    return 0;
}
```

#### - 运行/Run Results

```cpp
AB * = new AB()
error: request for member ‘vfunc1’ is ambiguous
A::vfunc2
A::vfunc3
A::func1
error: request for member ‘func2 is ambiguous

A  * = new C ()
C::vfunc1
A::vfunc2
A::vfunc3
A::func1
A::func2

A  * = new D ()
A::vfunc1
D::vfunc2
A::vfunc3
A::func1
A::func2
error: ‘class A’ has no member naname func3; did you mean vfunc3?

error : A  * = new CD()
error: ‘A’ is an ambiguous base of ‘CD’

C  * = new C ()
C::vfunc1
A::vfunc2
A::vfunc3
A::func1
C::func2

C  * = new CD()
C::vfunc1
A::vfunc2
A::vfunc3
A::func1
C::func2
error: ‘class C’ has no member named func3

D  * = new CD()
A::vfunc1
D::vfunc2
A::vfunc3
A::func1
A::func2
D::func3
```
#### - 调试/GDB
```cpp
                                                                             C * pcc = new C();
                                                                             'C' @ 0x555555756c70
                                                                                 ||
                                                                             A * pc = new C();                            C * pcd = new CD();
                                                                             'A' @ 0x555555756c70                        'C' @ 0x555555756bb8
                                                                                 ||                                          ||
                                                                             C  *  c = new C();                           CD * cd = new CD();
                                                                             C @ 0x555555756c70                          'CD' @ 0x555555756bb8
                                                                             [0]: 0x555555554fc2 <C::vfunc1()>     -     [0]: 0x555555554fc2 <C::vfunc1()>
AB * ab = new AB();                    A  *  a = new A();                    [1]: 0x555555554e72 <A::vfunc2()>     -     [1]: 0x555555554e72 <A::vfunc2()>
'AB' @ 0x555555756c08             __   A @ 0x555555756cb0                  / [2]: 0x555555554eaa <A::vfunc3()>     -     [2]: 0x555555554eaa <A::vfunc3()>
[0]: 0x555555554e3a <A::vfunc1()>      [0]: 0x555555554e3a <A::vfunc1()>  / /                                            'D' @ 0x555555756be0
[1]: 0x555555554e72 <A::vfunc2()>      [1]: 0x555555554e72 <A::vfunc2()>  \/                                             [0]: 0x555555554e3a <A::vfunc1()>
[2]: 0x555555554eaa <A::vfunc3()>      [2]: 0x555555554eaa <A::vfunc3()>   \   D  *  d = new D();                   /    [1]: 0x555555555032 <D::vfunc2()>
'B' @ 0x555555756c30                                                    \    \ D @ 0x555555756c48                  / /   [2]: 0x555555554eaa <A::vfunc3()>
[0]: 0x555555554f52 <B::vfunc1()>                                         \    [0]: 0x555555554e3a <A::vfunc1()>    / /      ||
                                  \                                         \  [1]: 0x555555555032 <D::vfunc2()>     /    D * pdd = new CD();
                                   \                                           [2]: 0x555555554eaa <A::vfunc3()>         'D' @ 0x555555756be0
                                    \  B  *  b = new B();                         ||
                                       B @ 0x555555756c98                      A * pd = new D();
                                       [0]: 0x555555554f52 <B::vfunc1()>       'A' @ 0x555555756c48

    A
    A  *  a = new A();
(gdb) info vtbl a
vtable for 'A' @ 0x555555756cb0 (subobject @ 0x55555576a280):
[0]: 0x555555554e3a <A::vfunc1()>
[1]: 0x555555554e72 <A::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

    B
    B  *  b = new B();
(gdb) info vtbl b
vtable for 'B' @ 0x555555756c98 (subobject @ 0x55555576a2a0):
[0]: 0x555555554f52 <B::vfunc1()>

    C
    C  *  c = new C();
(gdb) info vtbl c
vtable for 'C' @ 0x555555756c70 (subobject @ 0x55555576a2c0):
[0]: 0x555555554fc2 <C::vfunc1()>
[1]: 0x555555554e72 <A::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

    D
    D  *  d = new D();
(gdb) info vtbl d
vtable for 'D' @ 0x555555756c48 (subobject @ 0x55555576a2e0):
[0]: 0x555555554e3a <A::vfunc1()>
[1]: 0x555555555032 <D::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

    AB
    AB * ab = new AB();
(gdb) info vtbl ab
vtable for 'AB' @ 0x555555756c08 (subobject @ 0x55555576a300):
[0]: 0x555555554e3a <A::vfunc1()>
[1]: 0x555555554e72 <A::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

vtable for 'B' @ 0x555555756c30 (subobject @ 0x55555576a310):
[0]: 0x555555554f52 <B::vfunc1()>

    CD
    CD * cd = new CD();
(gdb) info vtbl cd
vtable for 'CD' @ 0x555555756bb8 (subobject @ 0x55555576a330):
[0]: 0x555555554fc2 <C::vfunc1()>
[1]: 0x555555554e72 <A::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

vtable for 'D' @ 0x555555756be0 (subobject @ 0x55555576a348):
[0]: 0x555555554e3a <A::vfunc1()>
[1]: 0x555555555032 <D::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>


    pc
    A * pc = new C();
(gdb) info vtbl pc
vtable for 'A' @ 0x555555756c70 (subobject @ 0x55555576a370):
[0]: 0x555555554fc2 <C::vfunc1()>
[1]: 0x555555554e72 <A::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

    pd
    A * pd = new D();
(gdb) info vtbl pd
vtable for 'A' @ 0x555555756c48 (subobject @ 0x55555576a390):
[0]: 0x555555554e3a <A::vfunc1()>
[1]: 0x555555555032 <D::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>


    pcc
    C * pcc = new C();
(gdb) info vtbl pcc
vtable for 'C' @ 0x555555756c70 (subobject @ 0x55555576a3b0):
[0]: 0x555555554fc2 <C::vfunc1()>
[1]: 0x555555554e72 <A::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

    pcd
    C * pcd = new CD();
(gdb) info vtbl pcd
vtable for 'C' @ 0x555555756bb8 (subobject @ 0x55555576a3d0):
[0]: 0x555555554fc2 <C::vfunc1()>
[1]: 0x555555554e72 <A::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>

    pdd
    D * pdd = new CD();
(gdb) info vtbl pdd
vtable for 'D' @ 0x555555756be0 (subobject @ 0x55555576a428):
[0]: 0x555555554e3a <A::vfunc1()>
[1]: 0x555555555032 <D::vfunc2()>
[2]: 0x555555554eaa <A::vfunc3()>
```
#### - 布局
```cpp

a = 0x55555576a280
b = 0x55555576a2a0
c = 0x55555576a2c0
d = 0x55555576a2e0
ab = 0x55555576a300
cd = 0x55555576a330
pc = 0x55555576a370
pd = 0x55555576a390
pcc = 0x55555576a3b0
pcd = 0x55555576a3d0
pdd = 0x55555576a428

+------------------------------------------------------+
|(gdb) p cd                                            |
|$4 = (CD *) 0x55555576a330                            |
|(gdb) p (C*)cd                                        |
|$5 = (C *) 0x55555576a330                             |
|(gdb) p (D*)cd                                        |
|$6 = (D *) 0x55555576a348                             |
+------------------------------------------------------+
|cd this= 0x55555576a330                               |
|p = this + top_offset // p = this - 24                |
|p = 0x55555576a348                                    |
+--------------------------+---------------------------+
|  0x55555576a330          | -187649982291152          |
|- 0x55555576a348          |              -24(offset)  |
|-----------------         | ----------------          |
|             -24 (offset) | -187649982291128          |
+--------------------------+---------------------------+

+--------------------------+---------------------------+
|(gdb) p ab                                            |
|$7 = (AB *) 0x55555576a300                            |
|(gdb) p (A*)ab                                        |
|$8 = (A *) 0x55555576a300                             |
|(gdb) p (B*)ab                                        |
|$9 = (B *) 0x55555576a310                             |
|                                                      |
|  0x55555576a300                                      |
|- 0x55555576a310                                      |
|-----------------                                     |
|            - 16  (offset)                            |
+------------------------------------------------------+
(gdb) p typeid(*a)
$52 = {_vptr.type_info = 0x7ffff7dc67f8 <vtable for __cxxabiv1::__class_type_info+16>, __name = 0x555555555fe8 <typeinfo name for A> "1A"}
(gdb) p typeid(*b)
$53 = {_vptr.type_info = 0x7ffff7dc67f8 <vtable for __cxxabiv1::__class_type_info+16>, __name = 0x555555555fe5 <typeinfo name for B> "1B"}
(gdb) p typeid(*c)
$54 = {_vptr.type_info = 0x7ffff7dc7438 <vtable for __cxxabiv1::__si_class_type_info+16>, __name = 0x555555555fe2 <typeinfo name for C> "1C"}
(gdb) p typeid(*d)
$55 = {_vptr.type_info = 0x7ffff7dc7438 <vtable for __cxxabiv1::__si_class_type_info+16>, __name = 0x555555555fdf <typeinfo name for D> "1D"}
(gdb) p typeid(*ab)
$56 = {_vptr.type_info = 0x7ffff7dc74f8 <vtable for __cxxabiv1::__vmi_class_type_info+16>, __name = 0x555555555fdb <typeinfo name for AB> "2AB"}
(gdb) p typeid(*cd)
$57 = {_vptr.type_info = 0x7ffff7dc74f8 <vtable for __cxxabiv1::__vmi_class_type_info+16>, __name = 0x555555555fd7 <typeinfo name for CD> "2CD"}
(gdb) p typeid(*pc)
$58 = {_vptr.type_info = 0x7ffff7dc7438 <vtable for __cxxabiv1::__si_class_type_info+16>, __name = 0x555555555fe2 <typeinfo name for C> "1C"}
(gdb) p typeid(*pd)
$59 = {_vptr.type_info = 0x7ffff7dc7438 <vtable for __cxxabiv1::__si_class_type_info+16>, __name = 0x555555555fdf <typeinfo name for D> "1D"}
(gdb) p typeid(*pcc)
$60 = {_vptr.type_info = 0x7ffff7dc7438 <vtable for __cxxabiv1::__si_class_type_info+16>, __name = 0x555555555fe2 <typeinfo name for C> "1C"}
(gdb) p typeid(*pcd)
$61 = {_vptr.type_info = 0x7ffff7dc74f8 <vtable for __cxxabiv1::__vmi_class_type_info+16>, __name = 0x555555555fd7 <typeinfo name for CD> "2CD"}
(gdb) p typeid(*pdd)
$62 = {_vptr.type_info = 0x7ffff7dc74f8 <vtable for __cxxabiv1::__vmi_class_type_info+16>, __name = 0x555555555fd7 <typeinfo name for CD> "2CD"}

(gdb) p *a
$16 = {_vptr.A = 0x555555756cb0 <vtable for A+16>, m_data1 = 0, m_data2 = 0}
(gdb) p *b
$17 = {_vptr.B = 0x555555756c98 <vtable for B+16>, m_data3 = 0}
(gdb) p *c
$18 = {<A> = {_vptr.A = 0x555555756c70 <vtable for C+16>, m_data1 = 0, m_data2 = 0}, m_data1 = 0, m_data4 = 0}
(gdb) p *d
$19 = {<A> = {_vptr.A = 0x555555756c48 <vtable for D+16>, m_data1 = 0, m_data2 = 0}, m_data5 = 0}

(gdb) p *ab
$20 = {<A> = {_vptr.A = 0x555555756c08 <vtable for AB+16>, m_data1 = 0, m_data2 = 0}, <B> = {_vptr.B = 0x555555756c30 <vtable for AB+56>, m_data3 = 0}, m_data_ab = 0}
(gdb) p *cd
$21 = {<C> = {<A> = {_vptr.A = 0x555555756bb8 <vtable for CD+16>, m_data1 = 0, m_data2 = 0}, m_data1 = 0, m_data4 = 0}, <D> = {<A> = {_vptr.A = 0x555555756be0 <vtable for CD+56>, m_data1 = 0, m_data2 = 0}, m_data5 = 0}, m_data_cd = 0}
(gdb) p *pc
$22 = {_vptr.A = 0x555555756c70 <vtable for C+16>, m_data1 = 0, m_data2 = 0}
(gdb) p *pd
$23 = {_vptr.A = 0x555555756c48 <vtable for D+16>, m_data1 = 0, m_data2 = 0}
(gdb) p *pcc
$24 = {<A> = {_vptr.A = 0x555555756c70 <vtable for C+16>, m_data1 = 0, m_data2 = 0}, m_data1 = 0, m_data4 = 0}
(gdb) p *pcd
$25 = {<A> = {_vptr.A = 0x555555756bb8 <vtable for CD+16>, m_data1 = 0, m_data2 = 0}, m_data1 = 0, m_data4 = 0}
(gdb) p *pdd
$26 = {<A> = {_vptr.A = 0x555555756be0 <vtable for CD+56>, m_data1 = 0, m_data2 = 0}, m_data5 = 0}

                                                                  0x555555756ba8 <_ZTV2CD>:          +----------------------------------------+
                                                                                                     |       offset   :   0x0                 |
                                                                  0x555555756bb0 <_ZTV2CD+8>:        +----------------------------------------+
                                                                                                     |       type_info: <_ZTI2CD>             | 0x555555756cc8  ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
                      +--+--+--+----------------++          - ->  0x555555756bb8 <_ZTV2CD+16>:       +----------------------------------------+                                                                     !
  0x55555576a330   cd |CD|C |A |  _vptr.A       ||  _ _ _ /                                          |+v  <C::vfunc1()>                       | 0x555555554fc1                                                      !
                  pcd |  |  |  +----------------+|                0x555555756bc0 <_ZTV2CD+24>:       +----------------------------------------+                                                                     !
  0x55555576a338      |  |  |  | - m_data1:int  ||                                                   |+v  <A::vfunc2()>                       | 0x555555554e72                                                      !
                      |  |  |  +----------------+|                0x555555756bc8 <_ZTV2CD+32>:       +----------------------------------------+                                                                     !
  0x55555576a33c      |  |  |  | - m_data2:int  ||                                                   |+v  <A::vfunc3()>                       | 0x555555554ea9                                                      !
                      |  |  +--+----------------+|                                                   +----------------------------------------+                                                                     !
  0x55555576a340      |  |  |    - m_data1:int   |                                                                                                                                                                  !
                      |  |  |--------------------+                0x555555756bd0 <_ZTV2CD+40>:       +----------------------------------------+                                                                     !
  0x55555576a344      |  |  |    - m_data4:int   |                                                   |       offset   :0xffffffffffffffe8(-24)|                                                                     !
                      |  +--+--+----------------++                0x555555756bd8 <_ZTV2CD+48>:       +----------------------------------------+                                                                     !
  0x55555576a348  pdd |  |D |A |  _vptr.A       ||  - - -                                            |       type_info: <_ZTI2CD>             | 0x555555756cc8  ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
                      |  |  |  +----------------+|        ` - ->  0x555555756be0 <_ZTV2CD+56>:       +----------------------------------------+                                                                     !
  0x55555576a350      |  |  |  | - m_data1:int  ||                                                   |+v  <A::vfunc1()>                       | 0x555555554e3a                                                      !
                      |  |  |  +----------------+|                0x555555756be8 <_ZTV2CD+64>:       +----------------------------------------+                                                                     !
  0x55555576a354      |  |  |  | - m_data2:int  ||                                                   |+v  <D::vfunc2()>                       | 0x555555555032                                                      !
                      |  |  +--+----------------+|                                                   +----------------------------------------+                                                                     !
  0x55555576a358      |  |  |    - m_data5:int   |                                                                                                                                                                  !
			          |  +--+--------------------+                                                                                                                                                                  !
  0x55555576a35c      |          - m_data_cd:int |                                                                                                                                                                  !
			          +--------------------------+                                                                                                                                                                  !
                                                                  0x555555756bf8 <_ZTV2AB>:          +----------------------------------------+                                                                     !
                                                                                                     |       offset   :   0x0                 |                                                                     !
                                                                  0x555555756c00 <_ZTV2AB+8>:        +----------------------------------------+                                                                     !
                                                                                                     |       type_info: <_ZTI2AB>             | 0x555555756d00    & & & & & & & & & & & & & & & & & & & & & &       !
                                                              ->  0x555555756c08 <_ZTV2AB+16>:       +----------------------------------------+                                                             &       !
                                                            /                                        |+v  <A::vfunc1()>                       | 0x555555554e3a                                              &       !
                         +--+--+----------------+         /       0x555555756c10 <_ZTV2AB+24>:       +----------------------------------------+                                                             &       !
  0x55555576a300:  ab    |AB|A |  _vptr.A       |   - - -                                            |+v  <A::vfunc2()>                       | 0x555555554e72                                              &       !
                         |  |  +----------------+                 0x555555756c18 <_ZTV2AB+32>:       +----------------------------------------+                                                             &       !
  0x55555576a308:        |  |  | - m_data1:int  |                                                    |+v  <A::vfunc3()>                       | 0x555555554eaa                                              &       !
                         |  |  +----------------+                                                    +----------------------------------------+                                                             &       !
  0x55555576a30c:        |  |  | - m_data2:int  |                                                                                                                                                           &       !
                         |  +--+----------------+                 0x555555756c20 <_ZTV2AB+40>:       +----------------------------------------+                                                             &       !
  0x55555576a310:        |  |B |  _vptr.B       |   - - -                                            |       offset   :0xfffffffffffffff0(-16)|                                                             &       !
                         |  |  +----------------+         \       0x555555756c28 <_ZTV2AB+48>:       +----------------------------------------+                                                             &       !
  0x55555576a318:        |  |  | - m_data3:int  |           \                                        |       type_info: <_ZTI2AB>             | 0x555555756d00    & & & & & & & & & & & & & & & & & & & & & &       !
                         |  +--+----------------+             ->  0x555555756c30 <_ZTV2AB+56>:       +----------------------------------------+                                                             &       !
  0x55555576a31c:        |  |    - m_data_ab:int|                                                    |+v  <B::vfunc1()>                       | 0x555555554f52                                              &       !
                         +----------------------+                                                    +----------------------------------------+                                                             &       !
                                                                                                                                                                                                            &       !
                                                                  0x555555756c38 <_ZTV1D>:           +----------------------------------------+                                                             &       !
                                                                                                     |       offset   :   0x0                 |                                                             &       !
                                                                  0x555555756c40 <_ZTV1D+8>:         +----------------------------------------+                                                             &       !
                         +--+--+----------------++                                                   |       type_info: <_ZTI1D>              | 0x555555756d38    * * * * * * * * * * * * * * * *           &       !
                   d     |D |A |  _vptr.A       ||  ----------->  0x555555756c48 <_ZTV1D+16>:        +----------------------------------------+                                                 *           &       !
                         |  |  +----------------+|                                                   |+v  <A::vfunc1()>                       | 0x555555554e3a                                  *           &       !
                         |  |  | - m_data1:int  ||                0x555555756c50 <_ZTV1D+24>:        +----------------------------------------+                                                 *           &       !
                         |  |  +----------------+|                                                   |+v  <D::vfunc2()>                       | 0x555555555032                                  *           &       !
                         |  |  | - m_data2:int  ||                0x555555756c58 <_ZTV1D+32>:        +----------------------------------------+                                                 *           &       !
                         |  +--+----------------+|                                                   |+v  <A::vfunc3()>                       | 0x555555554eaa                                  *           &       !
                         |  |    - m_data5:int   |                                                   +----------------------------------------+                                                 *           &       !
                         +--+--------------------+                                                                                                                                              *           &       !
                                                                  0x555555756c60 <_ZTV1C>:           +----------------------------------------+                                                 *           &       !
                                                                                                     |       offset   :   0x0                 |                                                 *           &       !
                                                                  0x555555756c68 <_ZTV1C+8>:         +----------------------------------------+                                                 *           &       !
       ----    --        +--+--+----------------++                                                   |       type_info: <_ZTI1C>              | 0x555555756d50   # # # # # # # # # # # #        *           &       !
     /       /           |C |A |  _vptr.A       || ------------>  0x555555756c70 <_ZTV1C+16>:        +----------------------------------------+                                        #        *           &       !
    |   A * pc = new C();|  |  +----------------+|                                                   |+v  <C::vfunc1()>                       | 0x555555554fc2                         #        *           &       !
    |       |            |  |  | - m_data1:int  ||                0x555555756c78 <_ZTV1C+24>:        +----------------------------------------+                                        #        *           &       !
    |       |            |  |  +----------------+|                                                   |+v  <A::vfunc2()>                       | 0x555555554e72                         #        *           &       !
    |        \           |  |  | - m_data2:int  ||                0x555555756c80 <_ZTV1C+32>:        +----------------------------------------+                                        #        *           &       !
    |          --        |  +--+----------------+|                                                   |+v  <A::vfunc3()>                       | 0x555555554eaa                         #        *           &       !
C  *  c = new C();       |  |    - m_data1:int   |                                                   +----------------------------------------+                                        #        *           &       !
C * pcc = new C();       |  |--------------------+                                                                                                                                     #        *           &       !
     \                   |  |    - m_data4:int   |                                                                                                                                     #        *           &       !
       ----------        +--+--------------------+                                                                                                                                     #        *           &       !
                                                                                                                                                                                       #        *           &       !
                                                                  0x555555756c88 <_ZTV1B>:           +----------------------------------------+                                        #        *           &       !
                                                                                                     |       offset   :   0x0                 |                                        #        *           &       !
                                                                  0x555555756c90 <_ZTV1B+8>:         +----------------------------------------+                                        #        *           &       !
                               +----------------+                                                    |       type_info:  <_ZTI1B>             | 0x555555756d68  :: :: :: :: ::         #        *           &       !
                   b           |  _vptr.B       |  ------------>  0x555555756c98 <_ZTV1B+16>:        +----------------------------------------+                             ::         #        *           &       !
                               +----------------+                                                    |+v  <B::vfunc1()>                       | 0x555555554f52              ::         #        *           &       !
                               | - m_data3:int  |                                                    +----------------------------------------+                             ::         #        *           &       !
                               +----------------+                                                                                                                           ::         #        *           &       !
                                                                  0x555555756ca0 <_ZTV1A>:           +----------------------------------------+                             ::         #        *           &       !
                               +----------------+                                                    |       offset   :   0x0                 |                             ::         #        *           &       !
                   a       --> |  _vptr.A       |                 0x555555756ca8 <_ZTV1A+8>:         +----------------------------------------+                             ::         #        *           &       !
                               +----------------+                                                    |       type_info:  <_ZTI1A>             | 0x555555756d78  @ @ @ @     ::         #        *           &       !
                               | - m_data1:int  |  ------------>  0x555555756cb0 <_ZTV1A+16>:        +----------------------------------------+                       @     ::         #        *           &       !
                               +----------------+                                                    |+v  <A::vfunc1()>                       | 0x555555554e3a        @     ::         #        *           &       !
                               | - m_data2:int  |                 0x555555756cb8 <_ZTV1A+24>:        +----------------------------------------+                       @     ::         #        *           &       !
                               +----------------+                                                    |+v  <A::vfunc2()>                       | 0x555555554e72        @     ::         #        *           &       !
                                                                  0x555555756cc0 <_ZTV1A+32>:        +----------------------------------------+                       @     ::         #        *           &       !
                                                                                                     |+v  <A::vfunc3()>                       | 0x555555554eaa        @     ::         #        *           &       !
                   		                                                                             +----------------------------------------+                       @     ::         #        *           &       !
                   		                                                                                                                                              @     ::         #        *           &       !
                   		                                                                             +_--------------------------------------------+                  @     ::         #        *           &       !
                   		                            	          0x555555756cc8 <_ZTI2CD>:                                                                           @     ::         #        *           &       !
                                                                                                     <_ZTVN10__cxxabiv121__vmi_class_type_infoE+16>               ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
                                                                  0x555555756cd0 <_ZTI2CD+8>:                                                                         @     ::         #        *           &
                                                                                                     <_ZTS2CD>                              "2CD"   0x555555555fd7    @     ::         #        *           &
                                                                                                                                                                      @     ::         #        *           &
                                                                  0x555555756cd8 <_ZTI2CD+16>:                                                                        @     ::         #        *           &
                                                                                                     0x200000001                                                      @     ::         #        *           &
                   		                                          0x555555756ce0 <_ZTI2CD+24>:                                                                        @     ::         #        *           &
                                                                                                     <_ZTI1C>                                       0x555555756d50 # # # # # # # # # # #        *           &
                   		                                          0x555555756ce8 <_ZTI2CD+32>:                                                                        @     ::         #        *           &
                                                                                                     0x2                                                              @     ::         #        *           &
                                                                                                                                                                      @     ::         #        *           &
                                                                                                                                                                      @     ::         #        *           &
                   										          0x555555756cf0 <_ZTI2CD+40>:                                                                        @     ::         #        *           &
                                                                                                     <_ZTI1D>                                       0x555555756d38  * * * * * * * * * * * * * * *           &
                   										          0x555555756cf8 <_ZTI2CD+48>:                                                                        @     ::         #        *           &
                                                                                                     0x1802                                                           @     ::         #        *           &
                                                                                                                                                                      @     ::         #        *           &
                                                                                                     +---------------------------------------------+                  @     ::         #        *           &
                                                                                                                                                                      @     ::         #        *           &
                   										          0x555555756d00 <_ZTI2AB>:                                                                           @     ::         #        *           &
                                                                                                     <_ZTVN10__cxxabiv121__vmi_class_type_infoE+16> 0x7ffff7dc74f8  & & & & & & & & & & & & & & & & & & & & &
                   										          0x555555756d08 <_ZTI2AB+8>:                                                                         @     ::         #        *
                                                                                                     <_ZTS2AB>                              "2AB"   0x555555555fdb    @     ::         #        *
                   										          0x555555756d10 <_ZTI2AB+16>:                                                                        @     ::         #        *
                                                                                                     0x200000000                                                      @     ::         #        *
                                                                                                                                                                      @     ::         #        *
                                                                  0x555555756d18 <_ZTI2AB+24>:                                                                        @     ::         #        *
                                                                                                     <_ZTI1A>                                       0x555555756d78  @ @     ::         #        *
                                                                  0x555555756d20 <_ZTI2AB+32>:                                                                        @     ::         #        *
                                                                                                     0x2                                                              @     ::         #        *
                                                                  0x555555756d28 <_ZTI2AB+40>:                                                                        @     ::         #        *
                                                                                                     <_ZTI1B>                                       0x555555756d68 :: :: :: ::         #        *
                                                                  0x555555756d30 <_ZTI2AB+48>:                                                                        @     ::         #        *
                                                                                                     0x1002                                                           @     ::         #        *
                                                                                                     +---------------------------------------------+                  @     ::         #        *
                                                                  0x555555756d38 <_ZTI1D>:                                                                            @     ::         #        *
                                                                                                     <_ZTVN10__cxxabiv120__si_class_type_infoE+16>  0x7ffff7dc7438  * * * * * * * * * * * * * * *
                                                                  0x555555756d40                                                                                      @     ::         #
                                                                                 <_ZTI1D+8>:         <_ZTS1D>                                "1D"   0x555555555fdf    @     ::         #
                                                                  0x555555756d48                                                                                      @     ::         #
                                                                                 <_ZTI1D+16>:        <_ZTI1A>                                       0x555555756d78  @ @     ::         #
                                                                                                                                                                      @     ::         #
                                                                                                     +---------------------------------------------+                  @     ::         #
                                                                  0x555555756d50                                                                                      @     ::         #
                                                                                 <_ZTI1C>:           <_ZTVN10__cxxabiv120__si_class_type_infoE+16>  0x7ffff7dc7438 # # # # # # # # # # #
                                                                  0x555555756d58                                                                                      @     ::
                                                                                 <_ZTI1C+8>:         <_ZTS1C>                                "1C"   0x555555555fe2    @     ::
                                                                  0x555555756d60                                                                                      @     ::
                                                                                 <_ZTI1C+16>:        <_ZTI1A>                                       0x555555756d78  @ @     ::
                                                                                                     +---------------------------------------------+                  @     ::
                                                                  0x555555756d68                                                                                      @     ::
                                                                                 <_ZTI1B>:           <_ZTVN10__cxxabiv117__class_type_infoE+16>     0x7ffff7dc67f8 :: :: :: ::
                                                                  0x555555756d70                                                                                      @
                                                                                 <_ZTI1B+8>:         <_ZTS1B>                                "1B"   0x555555555fe5    @
                                                                                                     +---------------------------------------------+                  @
                                                                  0x555555756d78                                                                                      @
                                                                                 <_ZTI1A>:           <_ZTVN10__cxxabiv117__class_type_infoE+16>     0x7ffff7dc67f8  @ @
                                                                  0x555555756d80
                                                                                 <_ZTI1A+8>:         <_ZTS1A>                                "1A"   0x555555555fe8
                                                                  0x555555756d88
                                                                                 0x1
                                                                  0x555555756d90

```
### 7. 多继承有虚继承无虚函数
```cpp
                                                    CD
                                                        m_data_cd
                                   C  func1
                                      func2         CVD
                                      m_data_c4        m_data_cvd
                               /      m_data_c5
                                                    VCD
                 A  func1       -  D  func2            m_data_vcd
AB           /      func2             func3
   m_data_ab        func3             m_data_d8     VCVD
             \     func4                              m_data_vcvd
                    m_data_a1   -  VC func1
                    m_data_a2         func2         VVCVVD
                                      m_data_vc6       m_data_vvcvvd
VAB           /                       m_data_vc7
   m_data_vab                  \
              \                   VD func2
                                      func3
                                      m_data_vd9
                 B  func1
                    func2
                    m_data_b3

```

#### - 代码/Codes

```cpp
#include <iostream>

class A
{
public:
    A():m_data_a1(1),m_data_a2(2){}
    void func1();
    void func2();
    void func3();
    void func4();
private:
    int m_data_a1, m_data_a2;
};
void A:: func1(){std::cout << "A::func1" << std::endl;}
void A:: func2(){std::cout << "A::func2" << std::endl;}
void A:: func3(){std::cout << "A::func3" << std::endl;}
void A:: func4(){std::cout << "A::func4" << std::endl;}

class B
{
public:
    B():m_data_b3(3){}
    void func1();
    void func2();
private:
    int m_data_b3;
};
void B:: func1(){std::cout << "B::func1" << std::endl;}
void B:: func2(){std::cout << "B::func2" << std::endl;}

class C: public A
{
public:
    C():A(),m_data_c4(4),m_data_c5(5){}
    void func1();
    void func2();
private:
    int m_data_c4, m_data_c5;
};
void C:: func1(){std::cout << "C::func1" << std::endl;}
void C:: func2(){std::cout << "C::func2" << std::endl;}

class VC: virtual public A
{
public:
    VC():A(),m_data_vc6(6),m_data_vc7(7){}
    void func1();
    void func2();
private:
    int m_data_vc6, m_data_vc7;
};
void VC:: func1(){std::cout << "VC::func1" << std::endl;}
void VC:: func2(){std::cout << "VC::func2" << std::endl;}

class D:public A
{
public:
    D():A(),m_data_d8(8){}
    void func2();
    void func3();
private:
    int m_data_d8;
};
void D:: func2(){std::cout << "D::func2" << std::endl;}
void D:: func3(){std::cout << "D::func3" << std::endl;}

class VD:virtual public A
{
public:
    VD():A(),m_data_vd9(9){}
    void func2();
    void func3();
private:
    int m_data_vd9;
};
void VD:: func2(){std::cout << "VD::func2" << std::endl;}
void VD:: func3(){std::cout << "VD::func3" << std::endl;}

class AB: public A, public B
{
private:
    int m_data_ab;
};
class VAB: virtual public A, virtual public B
{
private:
    int m_data_vab;
};
class CD: public C, public D
{
private:
    int m_data_cd;
};
class VCD: virtual public C, public D
{
private:
    int m_data_vcd;
};
class CVD: public C, virtual public D
{
private:
    int m_data_cvd;
};
class VCVD: public VC, public VD
{
private:
    int m_data_vcvd;
};
class VVCVVD: virtual public VC, virtual public VD
{
private:
    int m_data_vvcvvd;
};
int main()
{
    std::cout <<
    "                                                    CD               \n"
    "                                                        m_data_cd    \n"
    "                                   C  func1                          \n"
    "                                      func2         CVD              \n"
    "                                      m_data_c4        m_data_cvd    \n"
    "                               /      m_data_c5                      \n"
    "                                                    VCD              \n"
    "                 A  func1       -  D  func2            m_data_vcd    \n"
    "AB           /      func2             func3                          \n"
    "   m_data_ab        func3             m_data_d8     VCVD             \n"
    "             \\     func4                              m_data_vcvd   \n"
    "                    m_data_a1   -  VC func1                          \n"
    "                    m_data_a2         func2         VVCVVD           \n"
    "                                      m_data_vc6       m_data_vvcvvd \n"
    "VAB           /                       m_data_vc7                     \n"
    "   m_data_vab                  \\                                    \n"
    "              \\                   VD func2                          \n"
    "                                      func3                          \n"
    "                                      m_data_vd9                     \n"
    "                 B  func1                                            \n"
    "                    func2                                            \n"
    "                    m_data_b3                                        \n"

        <<std::endl;
    A      *  a    = new A();
    B      *  b    = new B();
    C      *  c    = new C();
    D      *  d    = new D();
    AB     * ab    = new AB();
    CD     * cd    = new CD();
    VC     * vc    = new VC();
    VD     * vd    = new VD();
    VAB    *vab    = new VAB();
    VCD    *vcd    = new VCD();
    CVD    *cvd    = new CVD();
    VCVD   *vcvd   = new VCVD();
    VVCVVD *vvcvvd = new VVCVVD();

    std::cout << "sizeof(A)      :" << sizeof(A)      << std::endl; // 8   4 + 4
    std::cout << "sizeof(B)      :" << sizeof(B)      << std::endl; // 4   4
    std::cout << "sizeof(C)      :" << sizeof(C)      << std::endl; // 16  A(8) + m_data_c4(4) + m_data_c5(4)
    std::cout << "sizeof(D)      :" << sizeof(D)      << std::endl; // 12  A(8) + m_data_d8(4)
    std::cout << "sizeof(AB)     :" << sizeof(AB)     << std::endl; // 16  A(8) + B(4) + m_data_ab(4)
    std::cout << "sizeof(CD)     :" << sizeof(CD)     << std::endl; // 32  C(A(8)+4+4)  + D(A(8)+4+4)
    std::cout << "sizeof(VC)     :" << sizeof(VC)     << std::endl; // 24  [_vptr.VC    ](8) + VC(4+4) + A(4+4)
    std::cout << "sizeof(VD)     :" << sizeof(VD)     << std::endl; // 24  [_vptr.VD    ](8) + VD.m_data_vd9(4) + A(4+4)  == 20
    std::cout << "sizeof(VAB)    :" << sizeof(VAB)    << std::endl; // 24  [_vptr.VAB   ](8) + m_data_vab(4) + A(4+4) +B(4)  == 24
    std::cout << "sizeof(VCD)    :" << sizeof(VCD)    << std::endl; // 40  [_vptr.VCD   ](8) + D(A(4+4)+4  ) + m_data_vcd(4) + C(A(4+4)+4+4)
    std::cout << "sizeof(CVD)    :" << sizeof(CVD)    << std::endl; // 40  [_vptr.CVD   ](8) + C(A(4+4)+4+4) + m_data_cvd(4) + D(A(4+4)+4  )
    std::cout << "sizeof(VCVD)   :" << sizeof(VCVD)   << std::endl; // 40  [_vptr.VC    ](8) + VC(4+4)                 + [_vptr.VD](8) + VD(4)                + m_data_vcvd(4) + A(4+4)
    std::cout << "sizeof(VVCVVD) :" << sizeof(VVCVVD) << std::endl; // 56  [_vptr.VVCVVD](8) + m_data_vvcvvd(4) + 0(4) + [_vptr.VC](8) + VC(4 + 4) + A(4 + 4) + [_vptr.VD](8) + VD(4) + 0(4)
    //ab->func1();
    //error: request for member ‘func1’ is ambiguous
    ab->func3();

    //cd->func1();
    //cd->func2();
    //error: request for member ‘func2’ is ambiguous
    //cd->func3();
    return 0;
}
```

#### - 运行/Run Results

```cpp
/* SIZEOF

sizeof(A)      :8
sizeof(B)      :4
sizeof(C)      :16
sizeof(D)      :12
sizeof(AB)     :16
sizeof(CD)     :32
sizeof(VC)     :24
sizeof(VD)     :24
sizeof(VAB)    :24
sizeof(VCD)    :40
sizeof(CVD)    :40
sizeof(VCVD)   :40
sizeof(VVCVVD) :56

*/
```

#### - 打印值/PRINT VALUE

```
/* GDB
(gdb) p *a
$97 = {m_data_a1 = 1, m_data_a2 = 2}
(gdb) p *b
$98 = {m_data_b3 = 3}
(gdb) p *c
$99 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_c4 = 4, m_data_c5 = 5}
(gdb) p *d
$100 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_d8 = 8}
(gdb) p *ab
$101 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, <B> = {m_data_b3 = 3}, m_data_ab = 0}
(gdb) p *cd
$103 = {<C> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_c4 = 4, m_data_c5 = 5}, <D> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_d8 = 8}, m_data_cd = 0}
(gdb) p *vc
$104 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VC = 0x555555757bc0 <VTT for VC>, m_data_vc6 = 6, m_data_vc7 = 7}
(gdb) p *vd
$105 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VD = 0x555555757ba0 <VTT for VD>, m_data_vd9 = 9}
(gdb) p *vab
$102 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, <B> = {m_data_b3 = 3}, _vptr.VAB = 0x555555757b80 <VTT for VAB>, m_data_vab = 0}
(gdb) p *vcd
$106 = {<C> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_c4 = 4, m_data_c5 = 5}, <D> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_d8 = 8}, _vptr.VCD = 0x555555757b58 <VTT for VCD>, m_data_vcd = 0}
(gdb) p *cvd
$107 = {<C> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_c4 = 4, m_data_c5 = 5}, <D> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_d8 = 8}, _vptr.CVD = 0x555555757b38 <VTT for CVD>, m_data_cvd = 0}
(gdb) p *vcvd
$108 = {<VC> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VC = 0x555555757ab8 <vtable for VCVD+24>, m_data_vc6 = 6, m_data_vc7 = 7}, <VD> = {_vptr.VD = 0x555555757ad0 <VTT for VCVD>, m_data_vd9 = 9}, m_data_vcvd = 0}
(gdb) p *vvcvvd
$109 = {<VC> = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VC = 0x555555757a30 <vtable for VVCVVD+64>, m_data_vc6 = 6, m_data_vc7 = 7}, <VD> = {_vptr.VD = 0x555555757a48 <VTT for VVCVVD>, m_data_vd9 = 9},
  _vptr.VVCVVD = 0x555555757a18 <vtable for VVCVVD+40>, m_data_vvcvvd = 0}

*/
```
####  - 打印值/PRINT PRETTY
```
/* set print pretty on
(gdb) p *a
$114 = {
  m_data_a1 = 1,
  m_data_a2 = 2
}

(gdb) p *b
$111 = {
  m_data_b3 = 3
}

(gdb) p *c
$112 = {
  <A> = {
    m_data_a1 = 1,
    m_data_a2 = 2
  },
  members of C:
  m_data_c4 = 4,
  m_data_c5 = 5
}

(gdb) p *d
$113 = {
  <A> = {
    m_data_a1 = 1,
    m_data_a2 = 2
  },
  members of D:
  m_data_d8 = 8
}
(gdb) p *ab
$115 = {
  <A> = {
    m_data_a1 = 1,
    m_data_a2 = 2
  },
  <B> = {
    m_data_b3 = 3
  },
  members of AB:
  m_data_ab = 0
}

(gdb) p *cd
$117 = {
  <C> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of C:
    m_data_c4 = 4,
    m_data_c5 = 5
  },
  <D> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of D:
    m_data_d8 = 8
  },
  members of CD:
  m_data_cd = 0
}

(gdb) p *vc
$118 = {
  <A> = {
    m_data_a1 = 1,
    m_data_a2 = 2
  },
  members of VC:
  _vptr.VC = 0x555555757bc0 <VTT for VC>,
  m_data_vc6 = 6,
  m_data_vc7 = 7
}
(gdb) p *vd
$119 = {
  <A> = {
    m_data_a1 = 1,
    m_data_a2 = 2
  },
  members of VD:
  _vptr.VD = 0x555555757ba0 <VTT for VD>,
  m_data_vd9 = 9
}

(gdb) p *vab
$116 = {
  <A> = {
    m_data_a1 = 1,
    m_data_a2 = 2
  },
  <B> = {
    m_data_b3 = 3
  },
  members of VAB:
  _vptr.VAB = 0x555555757b80 <VTT for VAB>,
  m_data_vab = 0
}

(gdb) p *vcd
$120 = {
  <C> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of C:
    m_data_c4 = 4,
    m_data_c5 = 5
  },
  <D> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of D:
    m_data_d8 = 8
  },
  members of VCD:
  _vptr.VCD = 0x555555757b58 <VTT for VCD>,
  m_data_vcd = 0
}

(gdb) p *cvd
$121 = {
  <C> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of C:
    m_data_c4 = 4,
    m_data_c5 = 5
  },
  <D> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of D:
    m_data_d8 = 8
  },
  members of CVD:
  _vptr.CVD = 0x555555757b38 <VTT for CVD>,
  m_data_cvd = 0
}

(gdb) p *vcvd
$122 = {
  <VC> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of VC:
    _vptr.VC = 0x555555757ab8 <vtable for VCVD+24>,
    m_data_vc6 = 6,
    m_data_vc7 = 7
  },
  <VD> = {
    members of VD:
    _vptr.VD = 0x555555757ad0 <VTT for VCVD>,
    m_data_vd9 = 9
  },
  members of VCVD:
  m_data_vcvd = 0
}

(gdb) p *vvcvvd
$123 = {
  <VC> = {
    <A> = {
      m_data_a1 = 1,
      m_data_a2 = 2
    },
    members of VC:
    _vptr.VC = 0x555555757a30 <vtable for VVCVVD+64>,
    m_data_vc6 = 6,
    m_data_vc7 = 7
  },
  <VD> = {
    members of VD:
    _vptr.VD = 0x555555757a48 <VTT for VVCVVD>,
    m_data_vd9 = 9
  },
  members of VVCVVD:
  _vptr.VVCVVD = 0x555555757a18 <vtable for VVCVVD+40>,
  m_data_vvcvvd = 0
}
*/

```

#### - GDB查看内存分布

```
/*

/////////////////////////////////////////////////////////////////////////////
//A
   a (sizeof 8)

name    |  m_data_a1   |     m_data_a2|
value   |    1         |    2         |
address |0x55555576b280|0x55555576b284|
/////////////////////////////////////////////////////////////////////////////
//B
   b (sizeof b)

name    |  m_data_b3   |
value   |    1         |
address |0x55555576b2a0|
/////////////////////////////////////////////////////////////////////////////
//C
   c (sizeof 16)

class C: public A
        |         base < A >            |              C              |
name    |   m_data_a1    |  m_data_a2   |  m_data_c4   |  m_data_c5   |
value   |   1            |     2        |    4         |    5         |
address |  0x55555576b2c0|0x55555576b2c4|0x55555576b2c8|0x55555576b2cc|

C继承于A类,A排列在最前面，然后是C类自己的成员变量
/////////////////////////////////////////////////////////////////////////////
//D
   d (sizeof 12)

class D:public A

        |         base < A >            |    D         |
name    |   m_data_a1    |  m_data_a2   |  m_data_d8   |
value   |   1            |     2        |    8         |
address |  0x55555576b2e0|0x55555576b2e4|0x55555576b2e8|

D继承于A类,A排列在最前面，然后是D类自己的成员变量
/////////////////////////////////////////////////////////////////////////////
//AB
   ab(sizeof 16)

class AB: public A, public B

        |         base < A >            | base < B >   |    AB        |
name    |   m_data_a1    |  m_data_a2   |  m_data_b3   |  m_data_ab   |
value   |   1            |     2        |    3         |    0         |
address |  0x55555576b300|0x55555576b304|0x55555576b308|0x55555576b30c|

AB公有继承于A类、B类,A排列在最前面，然后是B类，最后是AB类自己的成员变量
/////////////////////////////////////////////////////////////////////////////
//CD
   cd(sizeof 32)

(gdb) p cd
$285 = (CD *) 0x55555576b320

class C: public A
class D: public A
class CD: public C, public D

        |                       base  < C >                           |                       base  < D >            |    CD        |
        |         base < A >            |             <C>             |         base < A >            |              |              |
name    |   m_data_a1    |  m_data_a2   |  m_data_c4   |  m_data_c5   |   m_data_a1    |  m_data_a2   | m_data_d8    |  m_data_cd   |
value   |   1            |     2        |    4         |    5         |   1            |     2        | 8            |     0        |
address |  0x55555576b320|0x55555576b324|0x55555576b328|0x55555576b32c|  0x55555576b330|0x55555576b334|0x55555576b338|0x55555576b33c|

CD类使用公有继承于C类、D类,C和D都继承于A,
CD类最开始 放置C基类,其中包含A基类，
然后放置 D基类,其中也包含A基类,
最后放置 CD 类本身成员变量;

/////////////////////////////////////////////////////////////////////////////
(gdb) p *vc
$131 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VC = 0x555555757bc0 <VTT for VC>, m_data_vc6 = 6, m_data_vc7 = 7}

(gdb) p &*vc
$137 = (VC *) 0x55555576b350

(gdb) x /2xg (intptr_t*)(&*vc)
0x55555576b350: 0x0000555555757bc0      0x0000000700000006

(gdb) x /8dw (intptr_t*)(&*vc)
0x55555576b350: 1433762752      21845   6       7
0x55555576b360: 1       2       33      0


(gdb) p vc.m_data_a1
$132 = 1

(gdb) p &vc.m_data_a1
$133 = (int *) 0x55555576b360
(gdb) p &vc.m_data_a2
$134 = (int *) 0x55555576b364
(gdb) p &vc.m_data_vc6
$135 = (int *) 0x55555576b358
(gdb) p &vc.m_data_vc7
$136 = (int *) 0x55555576b35c

/////////////////////////////////////////////////////////////////////////////
//VC
   vc(sizeof 24)

        |        members of VC:                                    |  < A>                       |
name    | == _vptr.VC <VTT for VC>  |  m_data_vc6   |  m_data_vc7  |  m_data_a1   |     m_data_a2|
value   | == 0x0000555555757bc0     |  6            |7             |    1         |    2         |
address | == 0x    55555576b350     | 0x55555576b358|0x55555576b35c|0x55555576b360|0x55555576b364|
相比于非虚继承的类C：
        |         base < A >            |              C              |
name    |   m_data_a1    |  m_data_a2   |  m_data_c4   |  m_data_c5   |
value   |   1            |     2        |    4         |    5         |
address |  0x55555576b2c0|0x55555576b2c4|0x55555576b2c8|0x55555576b2cc|

相比于 C 多了一个 _vptr.VC, 且  base A 位于最后面；

/////////////////////////////////////////////////////////////////////////////
//VD
   vd(sizeof 24)
(gdb)  x /4xg &*vd
0x55555576b370: 0x0000555555757ba0      0x0000000100000009
0x55555576b380: 0x0000000000000002      0x0000000000000021

VD:
        |        members of VD:                     |  < A>                       |
name    | == _vptr.VD <VTT for VD>  |  m_data_vd9   |  m_data_a1   |     m_data_a2|
value   | == 0x0000555555757ba0     |  9            |    1         |    2         |
address | == 0x    55555576b370     | 0x55555576b378|0x55555576b37c|0x55555576b380|
相比于非虚继承的类D：
D:
        |         base < A >            |    D         |
name    |   m_data_a1    |  m_data_a2   |  m_data_d8   |
value   |   1            |     2        |    8         |
address |  0x55555576b2e0|0x55555576b2e4|0x55555576b2e8|

VD 相比于 D 多了一个 _vptr.VD, 且  base A 位于最后面;

/////////////////////////////////////////////////////////////////////////////
//VAB   8 + 4 + 4 + 4 +4
   vab(sizeof 24)

(gdb) x /4xg  &*vab
0x55555576b390: 0x0000555555757b80      0x0000000100000000
0x55555576b3a0: 0x0000000300000002      0x0000000000000031

VAB:(virtual public A, virtual public B)
        |        members of VAB:                    |  < A>                       |        <B>   |
name    | == _vptr.VAB <VTT for VAB>|  m_data_vab   |  m_data_a1   |     m_data_a2|     m_data_b3|
value   | == 0x0000555555757b80     |  0            |    1         |    2         |    3         |
address | == 0x    55555576b390     | 0x55555576b398|0x55555576b39c|0x55555576b3a0|0x55555576b3a4|

AB:
        |         base < A >            | base < B >   |    AB        |
name    |   m_data_a1    |  m_data_a2   |  m_data_b3   |  m_data_ab   |
value   |   1            |     2        |    3         |    0         |
address |  0x55555576b300|0x55555576b304|0x55555576b308|0x55555576b30c|

VAB 相比于 AB 的继承,
使用了virtual,增加了一个 _vptr.VAB,
然后是VAB自己的成员变量,
且Base A和Base B在VAB的成员变量后面;

/////////////////////////////////////////////////////////////////////////////
//VCD   8 + 4 + 4 + 4 +4 + 4 + 4 + 4 + 4
   vcd(sizeof 40)

(gdb) x /8xg 0x55555576b3b0
0x55555576b3b0: 0x0000555555757b58      0x0000000200000001
0x55555576b3c0: 0x0000000000000008      0x0000000200000001
0x55555576b3d0: 0x0000000500000004      0x0000000000000031

(gdb) p *(C*)0x55555576b3c8
$237 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_c4 = 4, m_data_c5 = 5}
(gdb) p *(D*)0x55555576b3b8
$240 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_d8 = 8}

class VCD: virtual public C, public D
        |        members of VCD:    |  < D >                                          | members of VCD:|        <C>                                                  |
name    | == _vptr.VCD <VTT for VCD>|  m_data_a1     |  m_data_a2    |     m_data_d8  |     m_data_vcd |  m_data_a1     |  m_data_a2   | m_data_c4    |m_data_c5     |
value   | == 0x0000555555757b58     |  1             |    2          |    8           |    0           |   1            |    2         |   4          |  5           |
address | == 0x    55555576b3b0     | 0x55555576b3b8 |0x55555576b3bc | 0x55555576b3c0 | 0x55555576b3c4 |  0x55555576b3c8|0x55555576b3cc|0x55555576b3d0|0x55555576b3d4|

CD:
        |                       base  < C >                           |                       base  < D >            |    CD        |
        |         base < A >            |             <C>             |         base < A >            |              |              |
name    |   m_data_a1    |  m_data_a2   |  m_data_c4   |  m_data_c5   |   m_data_a1    |  m_data_a2   | m_data_d8    |  m_data_cd   |
value   |   1            |     2        |    4         |    5         |   1            |     2        | 8            |     0        |
address |  0x55555576b320|0x55555576b324|0x55555576b328|0x55555576b32c|  0x55555576b330|0x55555576b334|0x55555576b338|0x55555576b33c|

VCD 是virtual虚继承于C和D类,从内存结构上来看,
1. 首先增加了 _vptr.VCD ,
2. 然后先 排列 D (未虚继承的基类),
3. 然后是VCD自己的成员变量，
4. 最后是 virtual虚继承的C类基类；

////////////////////////////////////////////////////////////////////////////
//CVD
   cvd(sizeof 40)

(gdb) x /8xg 0x55555576b3e0
0x55555576b3e0: 0x0000555555757b38      0x0000000200000001
0x55555576b3f0: 0x0000000500000004      0x0000000100000000
0x55555576b400: 0x0000000800000002      0x0000000000000031

(gdb) p *(C*)0x55555576b3e8
$242 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_c4 = 4, m_data_c5 = 5}
(gdb) p *(D*)0x55555576b3fc
$243 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, m_data_d8 = 8}

class CVD: public C, virtual public D

        |        members of CVD:    |  < C >                                                           | members of CVD:|        <D>                                                  |
name    | == _vptr.CVD <VTT for CVD>|  m_data_a1     |  m_data_a2    |     m_data_c4  |     m_data_c5  |  m_data_cvd    |  m_data_a1   | m_data_a2    |m_data_d8     |
value   | == 0x0000555555757b38     |  1             |    2          |    4           |    5           |   0            |    1         |   2          |  8           |
address | == 0x    55555576b3e0     | 0x55555576b3e8 |0x55555576b3ec | 0x55555576b3f0 | 0x55555576b3f4 |  0x55555576b3f8|0x55555576b3fc|0x55555576b400|0x55555576b404|
CVD 是继承于C类 及 virtual虚继承于D类,从内存结构上来看,
1. 首先增加了 _vptr.CVD ,
2. 然后先 排列 C (未虚继承的基类),
3. 然后是 CVD 自己的成员变量 m_data_cv，
4. 最后是 virtual虚继承的 D 类基类；
////////////////////////////////////////////////////////////////////////////
//VCVD
   vcvd(sizeof 40) 8 + 4 + 4 + 8 + 4 + 4 + 4 + 4

(gdb) x /8xg 0x55555576b410
0x55555576b410: 0x0000555555757ab8      0x0000000700000006
0x55555576b420: 0x0000555555757ad0      0x0000000000000009
0x55555576b430: 0x0000000200000001      0x0000000000000041

$246 = {m_data_a1 = 6, m_data_a2 = 7}
(gdb) p *(VC*) 0x55555576b410
$247 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VC = 0x555555757ab8 <vtable for VCVD+24>, m_data_vc6 = 6, m_data_vc7 = 7}
(gdb) p *(VD*) 0x55555576b420
$248 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VD = 0x555555757ad0 <VTT for VCVD>, m_data_vd9 = 9}

class VC: virtual public A
class VD: virtual public A

VC:
        |        members of VC:                                    |  < A>                       |
name    | == _vptr.VC <VTT for VC>  |  m_data_vc6   |  m_data_vc7  |  m_data_a1   |     m_data_a2|
value   | == 0x0000555555757bc0     |  6            |7             |    1         |    2         |
address | == 0x    55555576b350     | 0x55555576b358|0x55555576b35c|0x55555576b360|0x55555576b364|

VD:
        |        members of VD:                     |  < A>                       |
name    | == _vptr.VD <VTT for VD>  |  m_data_vd9   |  m_data_a1   |     m_data_a2|
value   | == 0x0000555555757ba0     |  9            |    1         |    2         |
address | == 0x    55555576b370     | 0x55555576b378|0x55555576b37c|0x55555576b380|

class VCVD: public VC, public VD
        |        < VC >                                                    |                   < VD >                |                |      < VC >  / < VD >       |
        |        members of VC:                                            |             members of VD:              |members of VCVD:|      < A >                  |
name    | == _vptr.VC<vtable for VCVD+24> | m_data_vc6     |  m_data_vc7   |_vptr.VD <VTT for VCVD> |  m_data_vd9    |  m_data_vcvd   |  m_data_a1   | m_data_a2    |
value   | == 0x0000555555757ab8           |  6             |    7          |   0x0000555555757ad0   |    9           |   0            |    1         |   2          |
address | == 0x    55555576b410           | 0x55555576b418 | 0x55555576b41c| 0x55555576b420         | 0x55555576b428 |  0x55555576b42c|0x55555576b430|0x55555576b434|

VCVD 公有继承于 VC 及 VD 类，
首先,排列VC类，包含 _vptr.VC
然后,排列VD类，包含 _vptr.VD
然后，VCVD类自己的类成员变量,
最后，VCVD类共有的A类成员;

////////////////////////////////////////////////////////////////////////////
//VVCVVD
   vvcvvd(sizeof 56) 8 + 4 + (4) + 8 + 4 + 4 + 4 + 4 + 8 + 4 + (4)

(gdb) x /16xg 0x55555576b440
0x55555576b440: 0x0000555555757a18      0x0000000000000000
0x55555576b450: 0x0000555555757a30      0x0000000700000006
0x55555576b460: 0x0000000200000001      0x0000555555757a48
0x55555576b470: 0x0000000000000009      0x000000000000eb91

(gdb) p *(VC*) 0x55555576b450
$251 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VC = 0x555555757a30 <vtable for VVCVVD+64>, m_data_vc6 = 6, m_data_vc7 = 7}
(gdb) p *(VD*) 0x55555576b468
$252 = {<A> = {m_data_a1 = 1, m_data_a2 = 2}, _vptr.VD = 0x555555757a48 <VTT for VVCVVD>, m_data_vd9 = 9}

class VC: virtual public A
class VD: virtual public A
class VVCVVD: virtual public VC, virtual public VD

VC:
        |        members of VC:                                    |  < A>                       |
name    | == _vptr.VC <VTT for VC>  |  m_data_vc6   |  m_data_vc7  |  m_data_a1   |     m_data_a2|
value   | == 0x0000555555757bc0     |  6            |7             |    1         |    2         |
address | == 0x    55555576b350     | 0x55555576b358|0x55555576b35c|0x55555576b360|0x55555576b364|

VD:
        |        members of VD:                     |  < A>                       |
name    | == _vptr.VD <VTT for VD>  |  m_data_vd9   |  m_data_a1   |     m_data_a2|
value   | == 0x0000555555757ba0     |  9            |    1         |    2         |
address | == 0x    55555576b370     | 0x55555576b378|0x55555576b37c|0x55555576b380|


        |                                                        |               |               < VC >                                             |      < VC >  / < VD >       |       < VD >                                |
        |         members of VVCVVD:                             |    NULL       |     members of VC:                                               |            < A >            |     members of VD:                          |
name    | == _vptr.VVCVVD<vtable for VVCVVD+40> | m_data_vvcvvd  |               |_vptr.VC <vtable for VVCVVD+64> |  m_data_vc6    |  m_data_vc7    |  m_data_a1   | m_data_a2    | _vptr.VD <VTT for VVCVVD>  | m_data_vd9     |
value   | == 0x0000555555757a18                 |  0             |       0       |   0x0000555555757a30           |    6           |   7            |    1         |   2          | 0x0000555555757a48         |  9             |
address | == 0x    55555576b440                 | 0x55555576b448 | 0x55555576b44c| 0x55555576b450                 | 0x55555576b458 |  0x55555576b45c|0x55555576b460|0x55555576b464| 0x55555576b468             | 0x55555576b470 |

首先，VVCVVD虚继承于VC类，虚继承于VD类,
先增加 _vptr.VVCVVD 到 开始位置;
然后，增加 VVCVVD自己的成员变量;
然后增加 VC 类的 _vptr.VC 及 VC类成员变量;
以及 增加 A 类的 成员变量;
最后放置 VD 类的 _vptr.VD 及 VD类成员变量;
共用一份A的成员变量;
*/
```
### 8. 多继承有虚继承有虚函数
```cpp
class Base {
public:
    int a;
    virtual void func() {}
};

class Derived1 : virtual public Base {
public:
    double b;
};

class Derived2 : virtual public Base {
public:
    char c;
};

class Final : public Derived1, public Derived2 {
public:
    float d;
    virtual void anotherFunc() {}
};

#include <iostream>

int main() {
    std::cout << "Size of Base: " << sizeof(Base) << std::endl;
    std::cout << "Size of Derived1: " << sizeof(Derived1) << std::endl;
    std::cout << "Size of Derived2: " << sizeof(Derived2) << std::endl;
    std::cout << "Size of Final: " << sizeof(Final) << std::endl;
    return 0;
}
```

```cpp
(gdb) p a
$1 = {_vptr.Base = 0x555555755ce0 <vtable for Base+16>, a = 1}
(gdb) p b
$2 = {<Base> = {_vptr.Base = 0x555555755cb8 <vtable for Derived1+48>, a = 1431654284},
  _vptr.Derived1 = 0x555555755ca0 <vtable for Derived1+24>, b = 4.635570642243394e-310}
(gdb) p c
$3 = {<Base> = {_vptr.Base = 0x555555755c70 <vtable for Derived2+48>, a = 1431654306},
  _vptr.Derived2 = 0x555555755c58 <vtable for Derived2+24>, c = -1 '\377'}
(gdb) p d
$4 = {<Derived1> = {<Base> = <invalid address>, _vptr.Derived1 = 0x2, b = 4.6355705385104085e-310}, <Derived2> = {
    _vptr.Derived2 = 0x7ffff7de3b40 <_dl_fini>, c = 0 '\000'}, d = 0}

(gdb) p &a
$8 = (Base *) 0x7fffffffe210
(gdb) p &b
$9 = (Derived1 *) 0x7fffffffe220
(gdb) p &c
$10 = (Derived2 *) 0x7fffffffe240
(gdb) p &d
$11 = (Final *) 0x7fffffffe260

(gdb) p (void *)&a.a-(void *)&a
$14 = 8
(gdb) p (void *)&b.b-(void *)&b
$15 = 8
(gdb) p (void *)&c.c-(void *)&c
$16 = 8
(gdb) p (void *)&d.d-(void *)&d
$17 = 28

(gdb) p (void *)&b.a-(void *)&b.b
$19 = 16
(gdb) p (void *)&c.a-(void *)&c.c
$20 = 16
```

当你在C++中同时使用虚继承和虚函数时，确实会涉及多个指针。

假设我们有以下类层次结构：

```cpp
class Base {
public:
    virtual void foo() {}
};

class VirtualBase {
public:
    virtual void bar() {}
};

class Derived : public virtual Base, public virtual VirtualBase {
public:
    void foo() override {
        // 实现
    }

    void bar() override {
        // 实现
    }
};

int main() {
    std::cout << "Size of Derived: " << sizeof(Derived) << " bytes" << std::endl;
    return 0;
}
```

在上述例子中，`Derived` 类同时虚继承了 `Base` 和 `VirtualBase` 类。这意味着：

1. **虚基类指针**：由于 `Derived` 虚继承了 `Base` 和 `VirtualBase`，它会包含两个指针，分别指向 `Base` 和 `VirtualBase` 的实例。这是因为虚继承的目的在于确保基类仅被继承一次，即使是从多个派生路径。这些指针确保了即使 `Derived` 类的多个实例通过不同的派生路径到达同一基类，它们仍然指向同一个基类实例。

2. **虚函数表指针**：由于 `Base` 和 `VirtualBase` 都有虚函数，每个类都会有一个虚函数表。`Derived` 类继承了这些虚函数，所以它会有一个虚函数表指针指向自己的虚函数表，这个虚函数表包含了从 `Base` 和 `VirtualBase` 继承的所有虚函数的地址，以及自身定义的虚函数地址。

因此，`Derived` 类的对象会包含：

- 一个指向 `Derived` 类虚函数表的虚函数表指针(vptr)。
- 一个指向 `Base` 类型的虚基类实例的指针。
- 一个指向 `VirtualBase` 类型的虚基类实例的指针。

但是，需要注意的是，这里的“虚基类指针”实际上并不是直接的指针，而是包含了指向虚基类实例的额外信息的结构。在某些实现中，这个信息可能包含在对象的布局中，而不是一个简单的指针。每个虚基类实例在 `Derived` 类的每个对象中可能只有一个拷贝，即使它们通过不同的路径被继承。

此外，虚函数表和虚基类指针的实现细节依赖于编译器，但大多数现代编译器会优化这些结构以最小化内存占用和提高性能。例如，如果 `Base` 和 `VirtualBase` 没有数据成员，它们可能共享相同的虚函数表，从而减少所需的内存空间。但是，这取决于编译器的优化策略和具体的类设计。

如果我们假设`Derived`类除了虚函数表指针和虚基类指针之外没有其他数据成员，我们可以进行如下估计：

1. **虚函数表指针**：每个类包含一个虚函数表指针。`Derived`类从`Base`和`VirtualBase`继承虚函数，但它只需要一个虚函数表指针指向自己的虚函数表。因此，这是8字节。

2. **虚基类指针**：对于虚继承，`Derived`类需要存储指向`Base`和`VirtualBase`的虚基类实例的指针。在某些实现中，这可能是一个额外的结构，称为虚基类子对象描述符(VB pointer或VB table指针)，它不仅包含指针，还包括其他信息，如偏移量。然而，为了简化讨论，我们假设每个虚基类指针占用8字节。因此，这里有16字节。


但是，实际情况可能更复杂。例如，某些编译器可能会使用一个单一的虚基类子对象描述符来同时跟踪`Base`和`VirtualBase`的实例，这可能减少所需的空间。此外，编译器可能还会进行对齐和填充以优化访问速度。

因此，一个粗略的估计是`Derived`类至少有24字节的大小（8字节的虚函数表指针加上16字节的虚基类指针）。但是，实际大小可能更高，因为需要考虑对齐和填充，以及编译器可能添加的额外元数据。
# 4.C++多态

## 4.1 动态绑定和静态绑定 C++多态

### 4.1.0 动态绑定和静态绑定 C++多态
1. 对象的静态类型: 对象在声明时采用的类型. 是在编译期确定的.
2. 对象的动态类型: 目前所指对象的类型. 是在运行期决定的. 对象的动态类型可以更改. 但是静态类型无法更改.
3. 静态绑定: 绑定的是对象的静态类型, 某特性(比如函数)依赖于对象的静态类型, 发生在编译期.
4. 动态绑定: 绑定的是对象的动态类型，某特性(比如函数)依赖于对象的动态类型, 发生在运行期.

**只有涉及虚函数的地方才存在动态绑定, 其他的全部是静态绑定.**

**缺省参数是静态绑定.** 所以缺省参数按照静态绑定方式计算.

> 静态多态是指通过模板技术或者函数重载技术实现的多态，其在编译器确定行为。
> 动态多态是指通过虚函数技术实现在运行期动态绑定的技术
**经过虚表调用虚函数的过程称为动态绑定, 其表现出来的现象称为运行时多态.**

**多态是通过模板具现化和函数重载解析实现的. 以不同的模板参数具现化导致调用不同的函数,这就是所谓的编译期多态.**

- 最常见的用法就是声明基类的指针，利用该指针指向任意一个子类对象，调用相应的虚函数，可以根据指向的子类的不同而实现不同的方法
- 基类指针指向子类对象
  - 固定偏移量，基类普通函数
  - 基类指针，指向虚函数，调用虚函数表找到的地址
- up cast 子类的指针去指向一个强制转换为子类地址的基类对象
  - 普通函数，调用子类对象的偏移量
  - 指向基类对象，虚函数表找到基类func调用基类函数
- 纯虚函数在基类中实现纯虚函数的方法是在函数原型后加“=0”
  - （动物 老虎 狮子）
  - 要求在派生类中必须予以重写以实现多态性
  - 纯虚拟函数的类称为抽象类，它不能生成对象


### 4.1.2 运行期多态优点

1.灵活性和扩展性：运行期多态使得代码更加灵活和可扩展。通过基类指针或引用调用虚函数，可以处理不同的派生类对象，而无需更改调用方式。这样，在后续的开发过程中，可以轻松添加新的派生类，而无需修改现有的代码。
2.高层抽象：运行期多态能够提供高层次的抽象，将对象的特定实现细节与使用对象的代码分离开来。通过基类接口进行编程，可以隐藏对象的具体实现细节，只关注对象能够提供的功能和行为。
3.代码重用：通过运行期多态，可以利用多态性的特性，编写可复用的代码。一个基类指针可以指向不同的派生类对象，从而共享相同的代码逻辑，减少代码的冗余。
4.维护性和可读性：运行期多态使得代码更易于维护和理解。通过使用基类指针或引用来调用方法，可以提高代码的可读性，减少了大量的条件语句和类型判断，使得代码更加清晰和简洁。


1. OO设计中重要的特性, 对客观世界直觉认识
2. 能够处理同一个继承体系下的异质类集合

### 4.1.3 运行期多态缺点

1. 运行期间进行虚函数绑定, 提高了程序运行开销
2. 庞大的类继承层次, 对接口的修改易影响类继承层次
3. 由于虚函数在运行期再确定, 所以编译器无法对虚函数进行优化
4. 虚表指针增大了对象体积, 类也多了一张虚函数表, 当然, 这是理所应当值得付出的资源消耗, 列为缺点有点勉强

### 4.1.4 编译期多态优点
编译期多态（Compile-time Polymorphism），也被称为静态多态，主要通过模板（Templates）和重载（Overloading）实现。相比于运行时多态，编译期多态有其独特的优势，尤其在性能和类型安全性方面。以下是编译期多态的一些主要优点：

1. **类型安全**：
    静态类型安全：由于编译期多态是在编译时就确定具体实例的，因此可以对参数类型进行静态类型检查，确保类型的正确性。这可以减少运行时类型相关的错误，提高代码的稳定性和可靠性。
      编译期多态通过模板和函数重载在编译时确定具体调用哪个函数或模板实例，这意味着类型错误可以在编译阶段就被捕捉到，提高了代码的安全性和可靠性。
    编译时错误检测：编译期多态可以在编译时进行类型检查，能够及早发现潜在的错误。如果某个函数调用无法匹配到适当的函数或模板实例，编译器会在编译期间报告错误，从而帮助开发人员更快地发现和修复问题。

2. **零开销抽象**（Zero-cost Abstraction）：
   编译器可以完全展开模板实例和重载函数的调用，这意味着在运行时没有额外的开销，如虚函数调用表的查找，从而提供了接近于内联函数的性能。

3. **高性能**：
   由于编译器在编译时就能确定具体的类型和函数调用，所以它可以进行优化，如内联、类型特化等，从而生成更高效的机器代码。
    性能高效：编译期多态的特点是在编译时就能够确定调用的具体函数或代码实例，不需要在运行时进行动态绑定。这样可以避免虚函数表查找、函数指针调用等运行时开销，提高程序的执行效率。

4. **代码复用**：
   模板允许你编写泛型代码，同一段代码可以应用于多种类型，这不仅减少了代码量，也提高了代码的可维护性和可读性。
    代码整洁：使用编译期多态可以减少手动编写的重复代码。通过函数重载和模板的特性，可以根据不同的参数类型自动生成对应的函数或代码实例，使代码更加简洁、清晰。

5. **延迟实例化**（Deferred Instantiation）：
   模板实例化可以在需要时才进行，也就是说，只有当模板被实际使用时，编译器才会生成相应的代码，这可以减少编译时间和二进制大小。

6. **早期绑定**（Early Binding）：
   编译期多态实现了早期绑定，这意味着在编译时就知道了函数调用的目标，这有助于提高代码的可预测性和调试性。

7. **避免运行时开销**：
   不像运行时多态需要额外的开销，如虚函数表的维护和查找，编译期多态在运行时没有此类开销，这对于性能敏感的应用非常重要。

8. **支持泛型编程**：
   模板是C++中实现泛型编程的核心机制，它允许编写高度抽象和通用的算法和数据结构，同时保持类型安全和高性能。

9. **易于理解和调试**：
   由于编译期多态的决定是在编译时做出的，因此在阅读和调试代码时，可以更容易地预测和理解程序的行为。

编译期多态非常适合于需要高性能和类型安全的场合，如底层系统编程、游戏开发、高性能计算等领域。然而，它也有一定的局限性，如模板元编程可能会导致编译时间较长，模板实例化可能会增加二进制大小等。因此，在使用时需要权衡其优缺点。

编译期多态具有高效性、简洁性、错误检测和类型安全等优点，适用于需要在编译期间确定函数调用或代码实例的场景.
1. 它带来了泛型编程的概念, 使得C++拥有泛型编程与STL这样的强大武器
2. 在编译器完成多态, 提高运行期效率
3. 具有很强的适配性与松耦合性, 对于特殊类型可由模板偏特化, 全特化来处理

### 4.1.5 编译期多态缺点
1.缺乏灵活性：编译期多态在编译时确定函数调用或代码实例，无法根据运行时的条件或动态变化进行适应。这意味着编译期多态无法处理动态创建对象或在运行时决定调用哪个函数的情况。这导致编译期多态对于某些需要在运行时才能确定的场景不够灵活。

2.代码膨胀：编译期多态使用模板和函数重载来生成不同的代码实例，对于每个不同的参数类型组合都会生成对应的函数或代码，这可能导致代码体积的增加。当参数类型组合非常多时，代码的体积可能会急剧增加，造成额外的内存占用和编译时间增长。

3.难以维护：编译期多态生成的大量重载函数或模板实例可能会增加代码的复杂性，使代码更难理解和维护。当需要对原有函数或模板进行修改时，可能需要同时更新多个重载函数或模板实例，这增加了代码维护的难度。

4.可读性差：由于编译期多态主要通过模板和函数重载来实现，代码中可能会出现大量的模板参数、类型推断和函数重载的情况，这可能导致代码变得复杂和晦涩。这可能增加了其他开发人员理解代码的难度。

5.编译时间增加：由于编译期多态需要对多个函数或模板进行生成和匹配，可能会导致编译时间的增加。特别是当参数类型组合较多时，编译器需要处理更多的代码实例，增加了编译时间。
1. 程序可读性降低, 代码调试带来困难
2. 无法实现模板的分离编译, 当工程很大时, 编译时间不可小觑
3. 无法处理异质对象集合

## 4.2 虚函数表
### 4.2.0 虚函数表
- 虚函数表属于类，类的所有对象共享这个类的虚函数表。
- 虚表是和类对应的, 虚表指针是和对象对应的.
- 不同对象虚函数表是一样的（虚函数表的第一个函数地址相同）；
- 每个对象内部都保存一个指向该类虚函数表的指针vptr，每个对象的vptr的存放地址都不一样，但是都指向同一虚函数表。通过对象内存中的虚函数指针vptr找到虚函数表vtbl，再通过vtbl中的函数指针找到对应虚函数的实现区域并进行调用
- 编译器为每一个类维护一个虚函数表，每个对象的首地址保存着该虚函数表的指针，同一个类的不同对象实际上指向同一张虚函数表。
```cpp
typedef void(*Pfun)();
int main() {

    Base base_test;   //创建对象会输出Base::A
    Base* base_ptr;
    //虚函数指针一般存放在一个类对象的最开始的地方
    long *address =(long*)(&base_test);
    cout << "基类虚函数表地址" << (long*)&base_test<<endl;
    cout << "基类虚函数表地址" << address << endl;
    //首先取到虚函数表的地址，这个地址里存放的是虚函数也就是第一个虚函数的地址，取出这个地址。
    cout << "基类虚函数表第一个函数的地址" << (long*)*(long*)&base_test<<endl;
    cout << "基类虚函数表第一个函数的具体地址" << std::hex << *(long*)*(long*)&base_test << endl;
    cout << "基类虚函数表第一个函数的地址" << (long*)(*address)<< endl;
    //在long*的基础上加1则指向第二个虚函数的地址
    cout << "基类虚函数表第二个函数的地址" << (((long*)(*address))+1) << endl;
    cout << "基类虚函数表第二个函数的具体地址" <<  std::hex << *(long*)(((long*)(*address))+1) << endl;
    cout << "基类虚函数表第三个函数的地址" << ((long*)(*(address)) + 2) << endl;
    cout << "基类虚函数表第三个函数的具体地址" <<  std::hex << *((long*)(*(address)) + 2) << endl;

    //上面得到虚函数的地址，取出这个地址的值然后再用函数指针指向它。
    Pfun p1 = (Pfun)*((long*)(*address));           //函数指针
    Pfun p2 = (Pfun)*(((long*)(*address)) + 1);
    Pfun p3 = (Pfun)*(((long*)(*(address)) + 2));
    p1();  //基类第一个虚函数
    p2();  //基类第二个虚函数
    p3();  //基类第三个虚函数
}
基类虚函数表第二个函数的地址0x5592b35c6d38
基类虚函数表第二个函数的具体地址5592b33c634a
基类虚函数表第三个函数的地址0x5592b35c6d40
基类虚函数表第三个函数的具体地址5592b33c6382
Base::A
Base::C
Base::D
Base::A
Der::A
派生类虚函数表地址0x7ffdcba81530
派生类虚函数表第一个函数的地址0x5592b35c6d08
虚函数表第一个函数的具体地址5592b33c63f0
派生类虚函数表第二个函数的地址0x5592b35c6d10
虚函数表第二个函数的具体地址5592b33c6428
派生类虚函数表第三个函数的地址0x5592b35c6d18
虚函数表第三个函数的具体地址5592b33c6382
派生类虚函数表第4个函数的地址0x5592b35c6d20
Der::A
Der::C
Base::D
```

# 5. C++其他问题

### 5.1 构造函数不能是虚函数
[为什么C++的构造函数不可以是虚函数，而析构函数可以是虚函数](https://blog.csdn.net/zhang2531/article/details/51218149)

* **虚构造函数**不支持, 虚拟函数调用只需要“部分的”信息，即只需要知道函数接口，而不需要对象的具体类型。但是构建一个对象，却必须知道具体的类型信息。如果你调用一个虚拟构造函数，编译器怎么知道你想构建是继承树上的哪种类型呢？所以这在逻辑上是一个悖论
* 虚函数的作用在于通过父类的指针或者引用来调用它的时候能够变成调用子类的那个成员函数。而构造函数是在创建对象时自动调用的，不可能通过父类的指针或者引用去调用，因此也就规定构造函数不能是虚函数。
* 从实现上看，vptr 在构造函数调用后才建立, 指定对应的 vtbl，因而构造函数不可能成为虚函数. 在调用构造函数时还不能确定对象的真实类型（因为子类会调父类的构造函数）；而且构造函数的作用是提供初始化，在对象生命期只执行一次，不是对象的动态行为，也没有太大的必要成为虚函数

### 5.2 构造函数、析构函数调用虚函数
1. 构造函数或者析构函数调用虚函数并不会发挥虚函数动态绑定的特性，跟普通函数没区别。
2. 即使构造函数或者析构函数如果能成功调用虚函数， 程序的运行结果也是不可控的

参见《Effective C++》 条款09：[绝不在构造函数或析构函数中调用虚函数](http://blog.csdn.net/hxz_qlh/article/details/14089895)

1. 从语法上讲，调用完全没有问题。
2. 但是从效果上看，往往不能达到需要的目的。

  Effective 的解释是：派生类对象构造期间进入基类的构造函数时，对象类型变成了基类类型，而不是派生类类型。同样，进入基类析构函数时，对象也是基类类型。 所以，虚函数始终仅仅调用基类的虚函数（如果是基类调用虚函数），不能达到多态的效果，所以放在构造函数中是没有意义的，而且往往不能达到本来想要的效果。

### 5.3 为什么基类的析构函数是虚函数？

**虚析构函数**是为了避免内存泄露, 而且是当子类中会有指针成员变量时才会使用得到的. 也就说**虚析构函数使得在删除指向子类对象的基类指针时可以调用子类的析构函数达到释放子类中堆内存的目的, 而防止内存泄露的**.

- 在实现多态时，当用基类操作派生类，在析构时防止只析构基类而不析构派生类的状况发生。
- 将可能会被继承的父类的析构函数设置为虚函数，可以保证当我们new一个子类，然后使用基类指针指向该子类对象，释放基类指针时可以释放掉子类的空间，防止内存泄漏。
- C++默认的析构函数不是虚函数是因为虚函数需要额外的虚函数表和虚表指针，占用额外的内存。
  - 而对于不会被继承的类来说，其析构函数如果是虚函数，就会浪费内存。因此C++默认的析构函数不是虚函数，而是只有当需要当作父类时，设置为虚函数

### 5.4 C实现多态
[C实现多态](https://light-city.club/sc/basic_content/c_poly/)
```cpp
#include <stdio.h>

// 定义一个形状结构体
typedef struct {
    void (*draw)(void);  // 函数指针，用于绘制形状
} Shape;

// 矩形的绘制函数
void drawRectangle(void) {
    printf("Drawing a rectangle.\n");
}

// 圆形的绘制函数
void drawCircle(void) {
    printf("Drawing a circle.\n");
}

int main() {
    Shape rectangle;
    Shape circle;

    rectangle.draw = drawRectangle;
    circle.draw = drawCircle;

    rectangle.draw();  // 调用矩形的绘制函数
    circle.draw();     // 调用圆形的绘制函数

    return 0;
}
```

### 5.5 变长参数实现
类型`va_list`和三个宏 `va_start`、`va_arg`、`va_end`
```cpp
#include <stdarg.h>
/*
 * getSum：用于计算一组整数的和
 * num：整数的数量
 *
 * */
int getSum(int num,...)
{
    va_list ap;//定义参数列表变量
    int sum = 0;
    int loop = 0;
    va_start(ap,num);
    /*遍历参数值*/
    for(;loop < num ; loop++)
    {
        /*取出并加上下一个参数值*/
        sum += va_arg(ap,int);
    }
    va_end(ap);
    return sum;
}
```
```cpp
#include <iostream>

template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T value, Args... args) {
    return value + sum(args...);
}

int main() {
    int total = sum(1, 2, 3, 4, 5);
    std::cout << "Sum: " << total << std::endl;

    double result = sum(1.5, 2.7, 3.3);
    std::cout << "Sum: " << result << std::endl;

    return 0;
}
```

### 5.6 必须在构造函数初始化式里进行初始化的数据成员有哪些
- 常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面,常量成员在创建对象之后就不能再修改。
- 引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
- 没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化，而是直接调用拷贝构造函数初始化
```cpp
class MyClass {
private:
    const int myConst;

public:
    MyClass(int value) : myConst(value) {
        // 其他构造逻辑
    }
};

class MyClass {
private:
    int& myRef;

public:
    MyClass(int& value) : myRef(value) {
        // 其他构造逻辑
    }
};

class AnotherClass {
public:
    AnotherClass(int value) { /* 构造函数实现 */ }
};


class MyClass {
private:
    AnotherClass myObject;

public:
    MyClass(int value) : myObject(value) {
        // 其他构造逻辑
    }
};
```
### 5.7 模板特化
- 全特化/偏特化
  - 例如，判断相等的模板函数，字符串需要特化出专门供字符串使用的模板参数
  - 全特化就是限定死模板实现的具体类型，
  - 偏特化就是如果这个模板有多个类型，那么只限定其中的一部分
- 部分特化
  - 就是只对函数模板的一部分模板类型进行特化
  - 对于模板类型的进一步限制
  - 对类型的范围的限制，主要的类型基础不变

### 5.8.1 内存泄漏问题出现
C++中的内存泄漏问题通常出现在以下几个方面：

1.动态分配内存未释放：在使用 new、malloc 或类似的分配内存的函数时，需要手动调用对应的释放内存的函数，如 delete、free 等。如果忘记或错误地未释放动态分配的内存，就会导致内存泄漏。

2.重复释放内存：当多次释放同一块内存时，会导致不可预测的行为，包括程序崩溃。确保每个动态分配的内存只被释放一次。

3.循环引用：循环引用指的是对象之间存在相互引用关系，导致无法释放的情况。如果某个对象持有其他对象的指针，而被其它对象也持有引用，这样形成了循环引用，即使没有外部引用，这些对象也无法被释放，从而导致内存泄漏。

4.STL容器的使用：STL容器（如vector、map等）会自动管理其元素的内存，但如果容器中存储了指针，并且没有正确地释放这些指针所指向的内存，就可能导致内存泄漏。

5.异常处理不当：在异常处理过程中，如果没有适当地释放已分配的内存，就会导致内存泄漏。应确保在发生异常时可以正确地释放已分配的资源。

为了避免内存泄漏，可以采取以下措施：

1.使用智能指针（如std::shared_ptr、std::unique_ptr）来管理动态分配的内存，以确保在不再需要时自动释放内存。
2.注意及时释放不再使用的动态分配的内存。
3.确保对象之间的引用关系不会形成循环引用。
4.在异常处理中正确处理内存释放。
5.使用 STL 容器时，注意元素的正确释放。
6.使用内存泄漏检测工具来帮助发现和调试潜在的内存泄漏问题。
### 5.8.2 排查和解决内存泄漏问题的过程
1.确认是否存在内存泄漏：
 在怀疑出现内存泄漏时，首先要确认是否真的存在内存泄漏问题。可以借助内存泄漏检测工具（例如Valgrind、Dr. Memory等）进行检查，或者通过代码审查和日志记录分析来确定是否存在内存泄漏。
2.定位内存泄漏的位置：
一旦确认存在内存泄漏，接下来需要定位泄漏的具体位置。可以通过以下方式进行定位：
 2.1观察代码中可能导致内存泄漏的地方，如动态内存分配、持有资源的对象等。
 2.2使用内存调试工具来追踪内存分配和释放的情况，以及跟踪指针的生命周期。
 2.3借助日志记录或调试器来跟踪程序执行过程中的内存分配和释放情况。
3.分析内存泄漏的原因：一旦找到了泄漏的位置，需要分析泄漏的原因。常见的原因包括：
 3.1动态分配的内存没有被正确释放。
 3.2对象之间存在循环引用，导致无法释放。
 3.3异常处理不当，未正确处理内存释放。
 3.4容器中存储了指针，但没有正确释放指针所指向的内存。
4.解决内存泄漏问题：根据泄漏的原因，采取适当的措施进行解决：
 4.1手动添加缺失的释放语句，确保动态分配的内存得到正确释放。
 4.2检查循环引用的情况，并考虑使用智能指针或改变对象之间的引用关系来解决循环引用。
 4.3在异常处理过程中，确保已分配的资源得到正确释放。
 4.4确保容器中存储的指针在不需要时正确释放。
5.进行测试和验证：
 在修改代码后，进行全面的测试和验证，确保解决了内存泄漏问题，并且程序的功能不受影响。
### 5.8.3 内存泄漏工具
- 释放内存之前，失去对内存的控制，造成浪费
- 后台消耗越来越多；频繁分配；程序能请求未释放的内存（共享内存）；操作系统内部；系统驱动内部；内存有限；不自动释放的系统；
- windows下CRT，
  - crtdbg.h 调试版本跟踪malloc和free，
  - 退出时转储内存泄露信息 _CrtDumpMemoryLeaks();
  - 显示：（_CRTDBG_MAP_ALLOC 可以多显示分配泄漏的内存的文件和行号）
  - 内存分配编号
  - 块类型(普通、客户端或 CRT)
  - “普通块”是由程序分配的普通内存。
  - “客户端块”是由 MFC 程序用于需要析构函数的对象的特殊类型内存块。 MFC new 操作根据正在创建的对象的需要创建普通块或客户端块。
  - “CRT 块”是由 CRT 库为自己使用而分配的内存块。 CRT 库处理这些块的释放，因此您不大可能在内存泄漏报告中看到这些块，除非出现严重错误（例如 CRT 库损坏）。
  - 不会看到的类型：
  - “可用块”是已释放的内存块。
  - “忽略块”是您已特别标记的块，因而不出现在内存泄漏报告中。
  - 十六进制内存位置
  - 以字节为单位的块大小。
  - 前 16 字节的内容（亦为十六进制）。
  - 定位具体内存泄漏的地方
  - 通过向 _CrtMemDumpStatistics 函数传递 _CrtMemState 结构，可以在任意点转储该结构的内容：
  - 再使用_CrtMemDifference 比较两个内存状态（s1 和 s2），生成这两个状态之间差异的结果（s3）。 在程序的开始和结尾放置 _CrtMemCheckpoint 调用，并使用_CrtMemDifference 比较结果，是检查内存泄漏的另一种方法。 如果检测到泄漏，则可以使用 _CrtMemCheckpoint 调用通过二进制搜索技术来划分程序和定位泄漏。
- linux下使用mtrace或valgrind
  - valgrind --leak-check=full ./a.out
### 5.8.4 valgrind 例子
假设我们有以下的 C++ 代码：
```cpp
#include <iostream>
void leakingnew()
{
    int *ptr = new int[10];
}
void leakingFunction()
{
    int* ptr = new int(10);
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        leakingFunction();
    }
    leakingnew();

    return 0;
}
```

这段代码中，leakingFunction() 函数在每次被调用时都会动态分配一个 int 类型的内存块，并没有进行释放，导致内存泄漏。

我们可以使用 Valgrind 来检测该程序的内存泄漏。请确保你已经安装了 Valgrind。

在终端中，使用以下命令编译并运行程序：

```shell
g++ -g -o program program.cpp
valgrind --leak-check=full ./program
```

Valgrind 将输出一系列的信息，其中包含了内存泄漏的相关报告。在报告中，找到类似下面的行：

4 bytes in 1 blocks are definitely lost in loss record 1 of 5
这将告诉你发生了 4 字节内存泄漏。进一步，找到 "lost" 行的上一行，其中包含堆栈跟踪信息：

```shell
valgrind --leak-check=yes ./newleck
==17365== Memcheck, a memory error detector
==17365== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17365== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17365== Command: ./newleck
==17365==
==17365==
==17365== HEAP SUMMARY:
==17365==     in use at exit: 60 bytes in 6 blocks
==17365==   total heap usage: 7 allocs, 1 frees, 72,764 bytes allocated
==17365==
==17365== 20 bytes in 5 blocks are definitely lost in loss record 1 of 2
==17365==    at 0x4C3217F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==17365==    by 0x1087F4: leakingFunction() (newleck.cpp:9)
==17365==    by 0x10881B: main (newleck.cpp:16)
==17365==
==17365== 40 bytes in 1 blocks are definitely lost in loss record 2 of 2
==17365==    at 0x4C3289F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==17365==    by 0x1087DB: leakingnew() (newleck.cpp:5)
==17365==    by 0x108826: main (newleck.cpp:18)
==17365==
==17365== LEAK SUMMARY:
==17365==    definitely lost: 60 bytes in 6 blocks
==17365==    indirectly lost: 0 bytes in 0 blocks
==17365==      possibly lost: 0 bytes in 0 blocks
==17365==    still reachable: 0 bytes in 0 blocks
==17365==         suppressed: 0 bytes in 0 blocks
==17365==
==17365== For counts of detected and suppressed errors, rerun with: -v
==17365== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
这段信息告诉我们，内存泄漏发生在 leakingFunction() 函数中的第 6 行，由 operator new 所触发。而泄漏最终出现在 main() 函数的第 14 行。

通过这些信息，我们可以找到泄漏发生的具体位置，并进行修复。

希望这个例子能够帮助你理解如何使用 Valgrind 查看具体的内存泄漏位置。
### 5.9 i++不是原子操作

**i++分为三个阶段：**
1. 内存到寄存器
2. 寄存器自增
3. 写回内存
这三个阶段中间都可以被中断分离开

### 5.10 获取结构体元素偏移量 offsetof
[获取结构体元素偏移量 offsetof](https://blog.csdn.net/weixin_44536482/article/details/88928990)

``` c
#define OFFSETOF(s,m) ((INT32U)&(((s *)0->m))
```
`(s *)0`：表示将0转化为指向"s"这个结构体类型的指针；可以理解为一个起始地址为0的"s"类型变量；
`((s *)0)->m`：表示这个起始地址为0的"s"类型变量中的成员"m"；
`&(((s *)0)->m)`：表示取这个成员"m"的地址；
`((INT32U)&(((s *）0->m))`：将"m"成员的地址以整型数据类型强制输出。
因为这个"s"类型的结构体变量起始地址为0，则最后一步输出的成员"m"的地址，即为其在结构体里面的偏移量了

### 5.11  memcpy与memmove的区别
```cpp
void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);

//没有重叠：
     <-
dest     src
|||||||||||||||

//有重叠： 会覆盖。
     ->
src     dest
|||||||||||||||
```
一般来说：
```cpp
#include <stddef.h> /* size_t */
void *memcpy(void *dest, const void *src, size_t n)
{
    char *dp = dest;
    const char *sp = src;
    while (n--)
        *dp++ = *sp++;
    return dest;
}
```
memcpy假定两块内存区域没有数据重叠, 如果复制的两个区域存在重叠时使用memcpy，其结果是不可预知的, 程序员自身必须确保两块内存没有重叠部分
memmove 则没有限制
```cpp
#include <stddef.h> /* for size_t */
void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *pd = dest;
    const unsigned char *ps = src;
    if (__np_anyptrlt(ps, pd))
        for (pd += n, ps += n; n--;)
            *--pd = *--ps;
    else
        while(n--)
            *pd++ = *ps++;
    return dest;
}
```
由此可见memcpy的速度比memmove快一点，如果使用者可以确定内存不会重叠，则可以选用memcpy，否则memmove更安全一些。
[考虑重叠时，从后向前拷贝](https://www.jianshu.com/p/9c3784d8d8ad)



### 5.12 手写strcpy

考虑重叠时，从后向前拷贝
memcpy，strcat，strcmp
https://blog.csdn.net/shanghairuoxiao/java/article/details/72876248
```cpp
if (pdest>psrc&&pdest < psrc+size)
{
    pdest = pdest + size -1;
    psrc = psrc + size -1;
    *pdest-- = *psrc--;
}
else
{
    *pdest ++ = *psrc++;
}
```
### 5.13 无锁编程

无锁编程时，我们可以使用原子操作和无锁数据结构来实现并发安全性
#### 5.13.1 `atomic_compare_exchange_weak_explicit`函数
`std::atomic_compare_exchange_weak_explicit`是C++中的原子操作函数，用于进行比较并交换的操作。它的作用是比较一个原子对象的值与期望值是否相等，如果相等，则将该原子对象的值替换为新值。这个操作是原子的，可以在多线程环境下安全地进行。

函数的签名如下：

```cpp
bool atomic_compare_exchange_weak_explicit(
    volatile atomic<T>* obj,
    T* expected,
    T desired,
    memory_order success,
    memory_order failure
);
```
obj：要进行比较和交换操作的原子对象的地址。
expected：一个指向预期值的指针。
desired：要替换的新值。
success：定义了交换操作成功时内存访问的顺序约束。
failure：定义了交换操作失败时内存访问的顺序约束。
该函数的工作方式是，首先检查obj的值是否与*expected相等。如果相等，则将desired的值存储到obj中，并返回true表示操作成功。如果不相等，则将obj的当前值存储到*expected中，并返回false表示操作失败。
函数中的_weak表示函数可能会在比较时失败，即使没有竞争情况存在.这意味着函数可能不会保证成功地进行比较和交换，因此需要在循环中反复尝试。
_explicit表示函数使用了显式的内存顺序参数，以在进行比较和交换操作时指定内存访问的顺序约束。这些顺序约束可以控制原子操作对内存的可见性和顺序性。
`atomic_compare_exchange_weak_explicit`函数允许我们在多线程环境下以原子方式进行条件比较和交换操作，从而实现并发安全性。
#### 5.13.2 实现无锁队列
我们使用了`std::atomic`类模板来实现原子操作。`LockFreeQueue`类是一个线程安全的无锁队列，支持在多个线程之间进行enqueue（入队）和dequeue（出队）操作。

enqueue操作使用原子操作`std::atomic_compare_exchange_weak_explicit`来保证对尾节点（tail）的修改是线程安全的。在循环中，我们首先检查尾节点是否与当前已知的尾节点相同。如果是，就尝试通过原子操作将新节点添加到尾节点的next指针上。如果添加成功了，就退出循环；否则，可能有其他线程修改了尾节点，因此我们需要更新当前已知的尾节点，并再次尝试添加。

dequeue操作也使用原子操作`std::atomic_compare_exchange_weak_explicit`来保证对头节点（head）的修改是线程安全的。类似于enqueue操作，我们在循环中检查头节点是否与当前已知的头节点相同。如果是，就尝试修改头节点并返回对应的值，然后删除之前的头节点。否则，可能有其他线程修改了头节点，因此我们需要更新当前已知的头节点，并再次尝试修改。
```cpp
#include <atomic>

template <typename T>
class LockFreeQueue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:
    LockFreeQueue() : head(nullptr), tail(nullptr) {}

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = nullptr;

        Node* currentTail = tail.load(std::memory_order_relaxed);
        while (true) {
            Node* actualTail = tail.load(std::memory_order_acquire);
            if (actualTail == currentTail) {
                Node* nextTail = actualTail->next;
                if (nextTail == nullptr) {
                    if (std::atomic_compare_exchange_weak_explicit(
                            &actualTail->next, &nextTail, newNode,
                            std::memory_order_release, std::memory_order_relaxed)) {
                        break;
                    }
                } else {
                    std::atomic_compare_exchange_weak_explicit(
                        &tail, &currentTail, nextTail,
                        std::memory_order_release, std::memory_order_relaxed);
                }
            }
        }

        std::atomic_compare_exchange_weak_explicit(
            &tail, &currentTail, newNode,
            std::memory_order_release, std::memory_order_relaxed);
    }

    bool dequeue(T& value) {
        Node* currentHead = head.load(std::memory_order_relaxed);
        while (true) {
            Node* actualHead = head.load(std::memory_order_acquire);
            if (actualHead == currentHead) {
                Node* nextHead = actualHead->next;
                if (nextHead == nullptr) {
                    return false;
                }
                value = nextHead->data;
                if (std::atomic_compare_exchange_weak_explicit(
                        &head, &currentHead, nextHead,
                        std::memory_order_release, std::memory_order_relaxed)) {
                    delete actualHead;
                    break;
                }
            }
        }

        return true;
    }
};
```
1.创建新节点：首先，我们创建一个新节点newNode，并将需要入队的值value存储在该节点的data成员中。

2.添加新节点到队尾：我们需要保证队列的线程安全性，因此我们使用原子操作来添加新节点到队列的尾部。
2.1 我们首先通过tail.load(std::memory_order_relaxed)获取当前尾节点（currentTail）。由于这是个松散的加载操作，不需要对内存进行顺序约束。
2.2 然后，我们进入一个循环，检查已知的尾节点是否与实际的尾节点（actualTail）相同。如果相同，则说明没有其他线程在此期间修改了尾节点。
2.3 在循环中，我们检查实际尾节点的next指针是否为nullptr。如果是，说明队列为空，我们可以安全地将新节点添加到尾节点的next指针上。
2.4 使用std::atomic_compare_exchange_weak_explicit原子操作来尝试将新节点设置为尾节点的next指针，拥有“发布”内存顺序约束（std::memory_order_release）。
2.4.1 如果操作成功（即设置成功），我们退出循环。
2.4.2 如果操作失败（即有其他线程在此期间修改了尾节点），我们需要更新当前已知的尾节点，并重新尝试添加。

3.更新尾节点：最后，我们使用std::atomic_compare_exchange_weak_explicit原子操作尝试更新尾节点。我们将当前已知的尾节点指针（currentTail）与新节点指针（newNode）进行比较，如果相等，则将新节点设置为新的尾节点。
### 5.14 C++类重构设计六大原则
### 5.14.0 C++类重构设计六大原则

一，开闭原则 一个软件实体如类，模块和函数应该对扩展开放，对修改关闭。
二，单一职责原则 指一个类或者模块应该有且只有一个改变的原因。
三，依赖倒置原则 **高层模块不应该依赖低层模块，应该依赖抽象。**  **抽象不应该依赖细节；细节应该依赖抽象。**
四，里氏替换原则 在不影响原功能，而不是不覆盖原方法
五，接口隔离原则 客户端不应该依赖它不需要的接口
六，迪米特原则（最小知识原则） **一个软件实体应当尽可能少的与其他实体发生相互作用**。
合成复用原则（Composite Reuse Principle） 首先使用合成/聚合的方式，而不是使用继承
### 5.14.1 C++类重构设计六大原则
1.单一职责原则（Single Responsibility Principle，SRP）：
一个类应该只有一个引起变化的原因。换句话说，每个类应该只负责完成一个明确定义的职责。这样可以使类的设计更加清晰、简洁，并提高代码的可维护性。

2.开放封闭原则（Open-Closed Principle，OCP）：
软件实体（类、模块、函数等）应该是可扩展的，但对修改关闭。通过使用抽象、接口、继承等方式，可以使得系统在需求变化时能够进行扩展而不需要修改现有的代码。

3.里氏替换原则（Liskov Substitution Principle，LSP）：
子类型必须能够替代其基类型。也就是说，如果一个类是某个抽象类型的子类，那么它应该可以替代该抽象类型在任何使用该抽象类型的地方，而不会导致程序逻辑错误或异常。

4.依赖倒置原则（Dependency Inversion Principle，DIP）：
高层模块不应该依赖于低层模块，两者都应该依赖于抽象。抽象不应该依赖于具体实现细节，而实现细节应该依赖于抽象。通过使用接口和依赖注入等方式，可以降低模块之间的耦合性，提高系统的灵活性和可维护性。

5.接口隔离原则（Interface Segregation Principle，ISP）：
客户端不应该依赖它不需要的接口。一个类不应该强迫自己的客户端依赖它们不需要的方法。通过将大接口拆分成多个小接口，可以避免对无关方法的依赖，提高代码的可重用性和灵活性。

6.迪米特法则（Law of Demeter，LoD）：
一个对象应该对其他对象有尽可能少的了解。一个类应该只与其直接的朋友发生交互，而避免与陌生的类发生直接的交互。通过减少类之间的耦合性，可以提高系统的可维护性和可扩展性。


### 5.15 堆

在C++中，您可以使用标准库中的`std::priority_queue`来定义堆（优先队列），并且可以通过指定比较器来控制堆是最大堆还是最小堆。

1. **最大堆**（Max Heap）：最大的元素位于堆的顶部，可以使用默认的比较器或自定义比较器来实现。


```cpp
#include <queue>
std::priority_queue<int> maxHeap; // 默认为最大堆
// 或者使用自定义比较器
std::priority_queue<int, std::vector<int>, std::less<int>> maxHeapCustomComparator;
bool operator()(int a, int b) { return a < b; }
```


2. **最小堆**（Min Heap）：最小的元素位于堆的顶部，需要使用自定义比较器。

```cpp
#include <queue>
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // 自定义比较器为std::greater<int>
bool operator()(int a, int b) { return a > b; }
```

### 5.16 C++ int / long
在C++中，int的大小通常取决于编译器和操作系统的位数。
通常情况下，int是4字节（32位）大小，因此可以表示的最大整数是2^31 - 1，最小整数是-2^31。

这是因为int是带符号的整数类型，其中一位用于表示符号（正或负），所以可以表示的范围是从-2^31到2^31 - 1，包括0。如果你需要更大的整数范围，可以考虑使用long int或long long int，它们通常是8字节（64位）大小，可以表示更大的整数范围。

`long` 是64位的，因此可以表示的最大整数是 2^63 - 1

2^32 = 4,294,967,296
2^31 -1 = 2,147,483,647
2^64 = 18,446,744,073,709,551,616(1.844674407E19)
2^63 -1 = 9,223,372,036,854,775,807
1. 2^32 表示 32 位二进制数的最大值，也称为 32 位整数。它的值是 4,294,967,296。这是无符号整数的最大值，如果是有符号整数，其范围通常是从 -2,147,483,648 到 2,147,483,647。这在计算机中常用于表示内存地址或存储整数数据。

2. 2^31-1 表示 32 位二进制数的最大有符号整数值，即 2,147,483,647。这是因为最高位通常用于表示数的正负，所以有符号整数的范围是从 -2,147,483,648 到 2,147,483,647。

3. 2^64 表示 64 位二进制数的最大值，也称为 64 位整数。它的值是 18,446,744,073,709,551,616。这提供了更大的数值范围，通常用于表示非常大的整数或用于计算很大的数值。

4. 2^63-1 表示 64 位二进制数的最大有符号整数值，即 9,223,372,036,854,775,807。这是因为最高位通常用于表示数的正负，所以有符号整数的范围是从 -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807。
5. 一个32位整数可以表示的最大值是2^31 - 1，或者约为21亿（2,147,483,647）。这是因为一个32位整数的最高位通常被用来表示正负号（0表示正数，1表示负数），所以实际可用的位数是31位。因此，一个32位整数可以正常表示10^9（10亿），但不能正常表示10^10（100亿），因为10^10大于2,147,483,647，超出了32位整数的表示范围。


2,147,483,647
1,000,000,000

## 5.17 bind
在C++中，`std::bind`是一个实用工具，用于绑定函数参数和函数对象，以便可以稍后以不同的方式调用它们。`std::bind`返回一个可调用对象，通常与`std::function`一起使用，这样可以存储和延迟函数的调用直到需要的时候。

`std::bind`的基本语法如下：

```cpp
std::bind(function, arg1, arg2, ...);
```

这里，`function`是要绑定的函数或函数对象，`arg1`, `arg2`, ...是你要绑定到函数的参数。参数可以是具体的值，也可以是占位符（`std::placeholders::_1`, `std::placeholders::_2`, ...）表示的位置，这些占位符将在调用时由其他参数替换。

下面是一些使用`std::bind`的例子：

### 5.17.1 绑定全局函数

假设有一个全局函数`add`，它接受两个整数参数并返回它们的和：

```cpp
int add(int x, int y) {
    return x + y;
}
```

你可以使用`std::bind`来创建一个新函数，它总是将第一个参数设置为5：

```cpp
#include <functional>
#include <iostream>

int add(int x, int y) {
    return x + y;
}

int main() {
    auto add_five = std::bind(add, 5, std::placeholders::_1);
    std::cout << add_five(10) << std::endl; // 输出 15
    return 0;
}
```

### 5.17.2 绑定成员函数

假设你有一个类`Rectangle`，它有一个成员函数`area`计算矩形的面积：

```cpp
class Rectangle {
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const {
        return width * height;
    }
private:
    int width;
    int height;
};
```

你可以使用`std::bind`来创建一个可调用对象，它将计算特定`Rectangle`实例的面积：

```cpp
#include <functional>
#include <iostream>

class Rectangle {
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const {
        return width * height;
    }
private:
    int width;
    int height;
};

int main() {
    Rectangle rect(4, 5);
    auto calc_area = std::bind(&Rectangle::area, &rect);
    std::cout << calc_area() << std::endl; // 输出 20
    return 0;
}
```

### 5.17.3 改变参数顺序

`std::bind`还可以用来改变函数参数的顺序：

```cpp
int subtract(int x, int y) {
    return x - y;
}

int main() {
    auto reverse_subtract = std::bind(subtract, std::placeholders::_2, std::placeholders::_1);
    std::cout << reverse_subtract(10, 5) << std::endl; // 输出 -5
    return 0;
}
```

### 5.17.4 结合`std::function`

`std::function`可以存储`std::bind`返回的可调用对象：

```cpp
#include <functional>
#include <iostream>

int multiply(int x, int y) {
    return x * y;
}

int main() {
    std::function<int(int)> double_it = std::bind(multiply, 2, std::placeholders::_1);
    std::cout << double_it(5) << std::endl; // 输出 10
    return 0;
}
```

以上是`std::bind`的一些基本用法。在现代C++中，`std::bind`的使用不如以前那么常见，因为在C++14之后引入了lambda表达式，后者通常提供了更简洁的方式来达到类似的效果。不过，了解`std::bind`的用法仍然是很有帮助的，特别是在需要延迟绑定或在一些特定的库接口中。
