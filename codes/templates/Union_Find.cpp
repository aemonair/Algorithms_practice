/*
 *
 *************************************************************************************
 *  union-Find
 *************************************************************************************
 *************************************************************************************
 *************************************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>


class UF{
private:
    // 记录连通分量
    int _count;
    // 节点 x 的节点是 parent[x]
    //int[] parent;
    std::vector<int> parent;
    std::vector<int> size;
public:
    /* 构造函数，n 为图的节点总数 */
    UF(int n)
    {
        // 一开始互不连通
        this->_count = n;
        // 父节点指针初始指向自己
        //parent = new int[n];
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = i;
        }
    }
    void Union1(int p, int q)
    {
        int rootP = find1(p);
        int rootQ = find1(q);
        if (rootP == rootQ)
            return;
        // 将两棵树合并为一棵
        parent[rootP] = rootQ;
        // parent[rootQ] = rootP 也一样
        _count--; // 两个分量合二为一
    }
    void Union2(int p, int q)
    {
        int rootP = find2(p);
        int rootQ = find2(q);
        if (rootP == rootQ)
            return;

        // 小树接到大树下面，较平衡
        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        _count--;
    }
   
    /* 返回某个节点 x 的根节点 */
    int find1(int x)
    {
        // 根节点的 parent[x] == x
        while (parent[x] != x)
        {
            x = parent[x];
        }
        return x;
    }
   
    int find2(int x)
    {
        while (parent[x] != x)
        {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    /* 返回当前的连通分量个数 */
    int count()
    {
        return _count;
    }
    bool connected(int p, int q)
    {
        int rootP = find2(p);
        int rootQ = find2(q);
        return rootP == rootQ;
    }
};
// ==================== TEST Codes====================
void Test(const std::string& testName,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    UF *uf = new UF(10);

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }


        uf->Union1(0,1);
        uf->Union2(0,2);
        int result = 0;
        //if(solution.isSame(root , expected) == true)
        if(result ==  expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}

void Test1()
{
    Test("Test1", 0);
}

void Test2()
{
}

void Test3()
{
}

void Test4()
{
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
