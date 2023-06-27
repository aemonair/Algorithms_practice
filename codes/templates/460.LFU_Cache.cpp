/*
 * 460. LFU Cache
 * Hard
 *
 ************************************************************************************
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 *
 ************************************************************************************
 * Implement the LFUCache class:
 *
 * - LFUCache(int capacity) Initializes the object with the capacity of the data structure.
 * - int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
 * - void put(int key, int value) Sets or inserts the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be evicted.
 *
 * Notice that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.
 *
 ************************************************************************************
 * Example 1:
 *
 * Input
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 *
 * Explanation
 * LFUCache lfu = new LFUCache(2);
 * lfu.put(1, 1);
 * lfu.put(2, 2);
 * lfu.get(1);      // return 1
 * lfu.put(3, 3);   // evicts key 2
 * lfu.get(2);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * lfu.put(4, 4);   // evicts key 1.
 * lfu.get(1);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * lfu.get(4);      // return 4
 *
 ************************************************************************************
 * Constraints:
 *
 * 0 <= capacity, key, value <= 104
 * At most 105 calls will be made to get and put.
 ************************************************************************************
 * Follow up: Could you do both operations in O(1) time complexity?
 ************************************************************************************
 */

#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <list>
#include <map>

class LFUCache0{
private:
public:
    LFUCache0(int capacity)
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
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////
};

class LFUCache1
{
// https://leetcode.com/problems/lfu-cache/discuss/94516/Concise-C++-O(1)-solution-using-3-hash-maps-with-explanation/237210   
private:
    int capacity , size, lfu = 0;
    std::unordered_map <int, std::list<int>> keys; // freq  -> list(key)
    std::unordered_map <int, std::pair<int,int>> values; // key , <value,freq>
    std::unordered_map <int, std::list<int>::iterator> iters; // key -> iter in keys
    void update(int key)
    {
    }
public:
    LFUCache1(int capacity) :capacity(capacity),size(0){}

    int printcache()
    {
        for(auto x = values.begin(); x != values.end(); x++)
        {
            std::cout << "(" << x->first << "," << x->second.first << ")" << ":" << x->second.second<< " ";
        }
        std::cout << std::endl;
        return values.size();

    }
    int get(int key)
    {
    }

    void put(int key, int value)
    {
    }
};

class LFUCache2 {
public:
    LFUCache2(int capacity) {

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
    int printcache()
    {
        return 0;
    }
};
template<class T>
void Test1(T *cache)
{
    std::cout << "Test1 START:" << std::endl;
    //LFUCache *cache = new LFUCache(2);
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
    //LFUCache *lRUCache = new LFUCache(2);
    std::cout << "> put(1, 1)" << std::endl;
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->printcache();
    std::cout << "> put(2, 2)" << std::endl;
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->printcache();
    lRUCache->get(1);    // return 1
    std::cout << "> put(3, 3)" << std::endl;
    lRUCache->put(3, 3); // LFU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->printcache();
    lRUCache->get(2);    // returns -1 (not found)
    std::cout << "> put(4, 4)" << std::endl;
    lRUCache->put(4, 4); // LFU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->printcache();
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache->get(4);    // return 4
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
const static int TEST_LFU0    = 0;
const static int TEST_LFU1    = 1;
const static int TEST_LFU2    = 0;
    if (TEST_LFU0)
    {
        std::cout << "LFUCache0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //std::cout << "LFUCache0:" << std::endl;

        LFUCache0 * cache = new LFUCache0(2);
        Test1(cache);
        Test2(cache);

        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "LFUCache0 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    if (TEST_LFU1)
    {
        std::cout << "LFUCache1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //std::cout << "LFUCache1:" << std::endl;

        LFUCache1 * cache = new LFUCache1(2);
        Test1(cache);
        Test2(cache);
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "LFUCache1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    if (TEST_LFU2)
    {
        std::cout << "LFUCache2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "LFUCache2:" << std::endl;

        LFUCache2 * cache = new LFUCache2(2);
        Test1(cache);
        Test2(cache);
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "LFUCache2 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
}
int main()
{
    Test();

    return 0;
}
