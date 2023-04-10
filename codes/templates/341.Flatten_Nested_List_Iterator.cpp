/*
 * 341. Flatten Nested List Iterator
 * Medium
 * 
 *************************************************************************************
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *************************************************************************************
 * 
 * Example 1:
 * 
 * Input: [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns false,
 *              the order of elements returned by next should be: [1,1,2,1,1].
 *************************************************************************************
 * Example 2:
 * 
 * Input: [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns false,
 *              the order of elements returned by next should be: [1,4,6].
 *************************************************************************************
 * 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 **/
class NestedInteger 
{
private:
    int val;
    std::vector<NestedInteger> list;    
public:
    NestedInteger(int val)
    {
        this->val = val;
    }
    NestedInteger(std::vector<NestedInteger> list)
    {
        this->list = list;
        this->val = -1;
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return val != -1;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const
    {
        return list;
    }
};

class NestedIterator 
{
private:
public:
    NestedIterator(std::vector<NestedInteger> &nestedList) 
    {
    }

    int next() 
    {
        return 0;
    }

    bool hasNext() 
    {
        return false;
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| "<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<NestedInteger> vnest,
        std::vector<int> expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;


    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        NestedIterator iter(vnest);
        std::vector<int> result;
        while(iter.hasNext())
        {
            int value = iter.next();
            std::cout << value << ",";
            result.push_back(value);
        }
        std::cout <<  std::endl;
        if(result==expected)
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
    std::vector<NestedInteger> v1 = {1, 1};
    NestedInteger value2(2);
    std::vector<NestedInteger> v = {v1, value2, v1};
    ////////////////////////////////////
    Test("Test1",  v, std::vector<int>{1,1,2,1,1});
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    NestedInteger value6(6);
    std::vector<NestedInteger> v6 = {value6};
    std::vector<NestedInteger> v4 = {4, v6};
    std::vector<NestedInteger> v1 = {1, v4};
    Test("Test2",  v1, std::vector<int>{1,4,6});
    std::cout << "----------------" << std::endl;
}

void Test3()
{
    Test("Test3", std::vector<NestedInteger>(), std::vector<int>());
    std::cout << "----------------" << std::endl;
}

void Test4()
{
    Test("Test4", std::vector<NestedInteger>(), std::vector<int>());
    std::cout << "----------------" << std::endl;
}

void Test5()
{
    Test("Test5", std::vector<NestedInteger>(), std::vector<int>());
    std::cout << "----------------" << std::endl;
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
