/*
 * 146. LRU Cache
 * Medium
 ************************************************************************************ 
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 ************************************************************************************ 
 * Follow up:
 * Could you do get and put in O(1) time complexity?
 ************************************************************************************ 
 * Example 1:
 * 
 * Input
 * ["LRUCache", "> put", "> put", "get", "> put", "get", "> put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * 
 ************************************************************************************ 
 * Constraints:
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 3000
 * 0 <= value <= 104
 * At most 3 * 104 calls will be made to get and put.
 *************************************************************************************
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <list>
#include <map>

class LRUCache0
{
public:
    LRUCache0(int capacity) 
    {
    }

    int get(int key) 
    {
    }

    void put(int key, int value) 
    {
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    int printcache()
    {
        for (auto &x : list) {
            std::cout << x.first << "(" << x.second << ") " ;
        }
            std::cout << std::endl;
        return 0;
    }
};

class LRUCache1
{
public:    
    LRUCache1(size_t capacity)
    {
    }
    int get(int key)
    {
        return 0;
    }
    void put(int key, int value)
    {
    }
    int printcache()
    {
        return 0;
    }
};

class LRUCache2
{
public:
    LRUCache2(int capacity)
    {
    }
    int get(int key)
    {
    }    
    void put(int key, int value)
    {
    }
    int printcache()
    {
        for (auto &x : list) {
            std::cout << x.first << "(" << x.second << ") " ;
        }
            std::cout << std::endl;
        return 0;
        return 0;
    }
};

template<class T>
void Test1(T *cache)
{
    std::cout << "Test1 START:" << std::endl;
    //LRUCache *cache = new LRUCache(2);
    // 你可以把 cache 理解成一个队列
    // 假设左边是队头，右边是队尾
    // 最近使用的排在队头，久未使用的排在队尾
    // 圆括号表示键值对 (key, val)
    
    std::cout << "> put(1, 1)" << std::endl;
    cache->put(1, 1);
    cache->printcache();
    // cache = [(1, 1)]
    
    std::cout << "> put(2, 2)" << std::endl;
    cache->put(2, 2);
    cache->printcache();
    // cache = [(2, 2), (1, 1)]
    
    int get1 = cache->get(1);       // 返回 1
    std::cout << "get1:" << get1 << std::endl;
    cache->printcache();
    // cache = [(1, 1), (2, 2)]
    // 解释：因为最近访问了键 1，所以提前至队头
    // 返回键 1 对应的值 1
    
    std::cout << "> put(3, 3)" << std::endl;
    cache->put(3, 3);
    cache->printcache();
    // cache = [(3, 3), (1, 1)]
    // 解释：缓存容量已满，需要删除内容空出位置
    // 优先删除久未使用的数据，也就是队尾的数据
    // 然后把新的数据插入队头
    
    int get2 = cache->get(2);       // 返回 -1 (未找到)
    std::cout << "get2:" << get2 << std::endl;
    cache->printcache();
    // cache = [(3, 3), (1, 1)]
    // 解释：cache 中不存在键为 2 的数据
    
    std::cout << "> put(1, 4)" << std::endl;
    cache->put(1, 4);
    cache->printcache();
    // cache = [(1, 4), (3, 3)]
    // 解释：键 1 已存在，把原始值 1 覆盖为 4
    // 不要忘了也要将键值对提前到队头
    std::cout << "Test1 END  :" << std::endl;
}

template<class T>
void Test2(T *lRUCache)
{
    std::cout << "Test2 START:" << std::endl;
    //LRUCache *lRUCache = new LRUCache(2);
    std::cout << "> put(1, 1)" << std::endl;
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->printcache();
    std::cout << "> put(2, 2)" << std::endl;
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->printcache();
    auto get1 = lRUCache->get(1);    // return 1
    std::cout << "get1:" << get1 << std::endl;
    lRUCache->printcache();
    std::cout << "> put(3, 3)" << std::endl;
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->printcache();
    auto get2 = lRUCache->get(2);    // returns -1 (not found)
    std::cout << "get2:" << get2 << std::endl;
    lRUCache->printcache();
    std::cout << "> put(4, 4)" << std::endl;
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->printcache();
    lRUCache->get(1);    // return -1 (not found)
    get1 = lRUCache->get(1);    // returns -1 (not found)
    std::cout << "get1:" << get1 << std::endl;
    lRUCache->printcache();
    lRUCache->get(3);    // return 3
    auto get3 = lRUCache->get(3);    // returns -1 (not found)
    std::cout << "get3:" << get3 << std::endl;
    lRUCache->printcache();
    lRUCache->get(4);    // return 4
    auto get4 = lRUCache->get(4);    // returns -1 (not found)
    std::cout << "get4:" << get4 << std::endl;
    lRUCache->printcache();
    std::cout << "Test2 END  :" << std::endl;
}
void Test3()
{
}

void Test4()
{
}

// ==================== TEST Codes====================
void Test()
{
    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
const static int TEST_TIME    = 1;
const static int TEST_LRU0    = 1;
const static int TEST_LRU1    = 0;
const static int TEST_LRU2    = 1;
    if (TEST_LRU0)
    {
        std::cout << "LRUCache0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //std::cout << "LRUCache0:" << std::endl;

        LRUCache0 * cache01 = new LRUCache0(2);
        Test1(cache01);
        delete cache01;
        LRUCache0 * cache02 = new LRUCache0(2);
        Test2(cache02);
        delete cache02;

        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "LRUCache0 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    if (TEST_LRU1)
    {
        std::cout << "LRUCache1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //std::cout << "LRUCache1:" << std::endl;

        LRUCache1 * cache11 = new LRUCache1(2);
        Test1(cache11);
        LRUCache1 * cache12 = new LRUCache1(2);
        Test2(cache12);
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "LRUCache1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    if (TEST_LRU2)
    {
        std::cout << "LRUCache2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "LRUCache2:" << std::endl;

        LRUCache2 * cache21 = new LRUCache2(2);
        Test1(cache21);
        LRUCache2 * cache22 = new LRUCache2(2);
        Test2(cache22);
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "LRUCache2 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
}
int main()
{
    Test();

    return 0;
}
