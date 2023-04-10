/*
 * 295. Find Median from Data Stream
 * Hard
 * Median is the middle value in an ordered integer list. 
 * If the size of the list is even, there is no middle value. 
 * So the median is the mean of the two middle value.
 * 
 * For example,
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * + void addNum(int num) - 
 *        - Add a integer number from the data stream to the data structure.
 * + double findMedian() -
 *        - Return the median of all elements so far.
 * 
 * 
 * Example:
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3)
 * findMedian() -> 2
 * 
 * 
 * Follow up:
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
 * 
 * 
 */

#include <stack>
#include <vector>
#include <queue>
#include <iostream>

class Solution_1 {
//class MedianFinder 
public:
    template <typename T>
    int printvector(std::vector<T> v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << std::endl;
        return v.size();
    }
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }
    int printqueue()
    {
        std::priority_queue<int> Big_queue = big_queue;
        std::priority_queue<int, std::vector<int>, std::greater<int>> Small_queue=small_queue;
        int bsize = Big_queue.size();
        int ssize = Small_queue.size();
        if (Big_queue.empty())
        {
            std::cout << "The big queue is empty. "<< std::endl;
        }
        if (Small_queue.empty())
        {
            std::cout << "The small queue is empty. "<< std::endl;
        }
        while (ssize--)
        {
            std::cout << Small_queue.top() << ", " ;
            Small_queue.pop();
        }
        std::cout << " | ";
        while (bsize--)
        {
            std::cout << Big_queue.top() << ", " ;
            Big_queue.pop();
        }
        std::cout << std::endl ;
        return bsize;
    }

public:
    /** initialize your data structure here. */
    //MedianFinder() {

    // 默认是大顶堆
    std::priority_queue<int, std::vector<int>, std::less<int>>    big_queue;
    //less表示按照递减(从大到小)的顺序插入元素
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue;
    //greater表示按照递增（从小到大）的顺序插入元素

    void addNum(int num) 
    {
        if (big_queue.empty())
        {
            big_queue.push(num);
            return;
        }
        int bsize = big_queue.size();
        int ssize = small_queue.size();
        int big = 0;
        int small = 0;

        if (!big_queue.empty())
        {
            big   = big_queue.top();
        }
        if (!small_queue.empty())
        {
            small = small_queue.top();
        }

        if (bsize == ssize)
        {
            if (big > num)
            {
                big_queue.push(num);
            }
            else
            {
                small_queue.push(num);
            }
        }
        else if (bsize > ssize) // 大堆已经多一个
        {
            if (big > num) // 大堆顶大于 num
            {
                big_queue.push(num);
                int tmp = big_queue.top();
                small_queue.push(tmp);
                big_queue.pop();
            }
            else // 大堆顶小于 num
            {
                small_queue.push(num);
            }
        }
        else if (bsize < ssize) // 小堆已经多一个
        {
            if (small < num) // 小堆顶小于 num
            {
                small_queue.push(num);
                int tmp = small_queue.top();
                big_queue.push(tmp);
                small_queue.pop();
            }
            else // 小堆顶大于 num
            {
                big_queue.push(num);
            }
        }
    }

    double findMedian() 
    {
        int bsize = big_queue.size();
        int ssize = small_queue.size();
        int big = 0;
        int small = 0;
        if (!big_queue.empty())
        {
            big   = big_queue.top();
        }
        if (!small_queue.empty())
        {
            small = small_queue.top();
        }
        std::cout << "bsize:" << bsize << ", ";
        std::cout << "ssize:" << ssize << ", ";
        std::cout << "big  :" << big   << ", ";
        std::cout << "small:" << small << ", ";

        if (bsize == ssize)
        {
            return (big+small)/2.0;
        } 
        else if (bsize > ssize)
        {
            return big;
        }
        else if (bsize < ssize)
        {
            return small;
        }
        return 0;
    }
};

class Solution {
public:
/*
 *    1
 *
 *    1    2
 *
 *
 *    2    3
 *   1
 *
 *    2    3
 *   1    4
 *
 *    3    4
 *   1 2  6
 *
 *    3    4
 *   1 2  5 6
 */
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;

    // 使左边最大堆总是多一个
    void addNum(int num) 
    {
        if (left.empty())
        {
            left.push(num);
            return;
        }
        int size1 = left.size();
        int size2 = right.size();

        if (size1 == size2)
        {
            int tmp = right.top();
            if (num < tmp) // new value smaller than right
            {
                left.push(num);
            }
            else // new value greater than right
            {
                left.push(tmp);
                right.pop();
                right.push(num);
            }
        }
        else // 不同等
        {
            int tmp = left.top();
            if (tmp <= num)
            {
                right.push(num);
            }
            else
            {
                left.pop();
                left.push(num);
                right.push(tmp);
            }
        }
    }

    double findMedian()
    {
        int size1 = left.size();
        int size2 = right.size();
        if (size1 == 0)
        {
            return 0;
        }
        if (size1 >  size2)
        {
            return left.top();
        }
        else //if (size1 <= size2)
        {
            return (left.top()+right.top())/2.0;
        }
        return 0;
    }
    int printqueue()
    {
        std::priority_queue<int> Big_queue = left;
        std::priority_queue<int, std::vector<int>, std::greater<int>> Small_queue=right;
        int bsize = Big_queue.size();
        int ssize = Small_queue.size();
        if (Big_queue.empty())
        {
            std::cout << "The big queue is empty. "<< std::endl;
        }
        if (Small_queue.empty())
        {
            std::cout << "The small queue is empty. "<< std::endl;
        }
        while (ssize--)
        {
            std::cout << Small_queue.top() << ", " ;
            Small_queue.pop();
        }
        std::cout << " | ";
        while (bsize--)
        {
            std::cout << Big_queue.top() << ", " ;
            Big_queue.pop();
        }
        std::cout << std::endl ;
        return bsize;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
    Solution a;
    a.printqueue();
    double median = a.findMedian();
    std::cout << "median:" << median << std::endl;
    a.addNum(7);
    a.addNum(6);
    a.addNum(4);

    a.printqueue();
    median = a.findMedian();
    std::cout << "median:" << median << std::endl;

    a.addNum(10);
    a.addNum(33);
    a.addNum(99);
    a.printqueue();
    median = a.findMedian();
    std::cout << "median:" << median << std::endl;

    a.addNum(3);
    a.printqueue();
    median = a.findMedian();
    std::cout << "median:" << median << std::endl;
    return 0;
}
