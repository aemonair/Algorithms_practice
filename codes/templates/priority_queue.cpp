#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

template<typename T>
class MAXPQ
{
public:
    // 父节点的索引
    int parent(int root) 
    {
        return root / 2;
    }
    // 左孩子的索引
    int left(int root) 
    {
        return root * 2;
    }
    // 右孩子的索引
    int right(int root) 
    {
        return root * 2 + 1;
    }
    std::vector<T> pq;
    int N = 0;

    MAXPQ(int cap)
    {
    }

    T max()
    {
    }

    /* 插入元素 e */
    void insert(T e) 
    {
    }

    /* 删除并返回当前队列中最大元素 */
    T delMax() 
    {
    }

    /* 上浮第 k 个元素，以维护最大堆性质 */
    void swim(int k) 
    {
    }

    /* 下沉第 k 个元素，以维护最大堆性质 */
    void sink(int k) 
    {
    }

    /* 交换数组的两个元素 */
    void exch(int i, int j) 
    {
    }

    /* pq[i] 是否比 pq[j] 小？ */
    bool less(int i, int j) 
    {
    }
};

int main()
{
    MAXPQ<int> * maxpq = new MAXPQ<int>(2);
    maxpq->insert(1);
    std::cout << "max:" << maxpq->max() << std::endl;
    maxpq->insert(5);
    maxpq->insert(2);
    maxpq->insert(4);
    std::cout << "max:" << maxpq->max() << std::endl;
    maxpq->insert(3);
    std::cout << "max:" << maxpq->max() << std::endl;
    std::cout << "delMax:" << maxpq->delMax() << std::endl;
    std::cout << "max:" << maxpq->max() << std::endl;
    return 0;
}

