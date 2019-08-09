/*
 * 215. Kth Largest Element in an Array
 * Medium
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 * Example 2:
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

#include <stack>
#include <vector>
#include <queue>
#include <iostream>

class Solution {
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
    int partion(std::vector<int>& nums, int l, int r)
    {
        if (l == r)
        {
            return l;
        }
        int mid = l;
        int randpivot = rand()%(r-l)+l;
        std::cout << "randpivot: num[" << randpivot << "]:" << nums[randpivot] ;
        std::cout << " , nums[" << r << "]:" << nums[r] << std::endl;
        std::swap(nums[randpivot], nums[r]);
        printvector(nums);

        for (int i = l; i < r ;i++)
        {
            if (nums[i] > nums[r])
            {
                std::cout << "swap: num[" << i << "]:" << nums[i]<< " , nums[" << mid << "]:" << nums[mid] << std::endl;
                std::swap(nums[mid], nums[i]);
                mid ++;
            }
        }
        std::swap(nums[mid], nums[r]);
        printvector(nums);
        return mid;
    }
    int partion1(std::vector<int>& nums, int left, int right)
    {
        int pivot = nums[left];
        int l     = left + 1;
        int r     = right ;
        
        std::cout << "num[" << left << "]:" << nums[left] << std::endl;
        std::cout << "num[" << l << "]:" << nums[l]<< " , nums[" << r << "]:" << nums[r] << std::endl;

        while (l <= r)
        {
            if (nums[l] < pivot && nums[r] > pivot)
            {
                std::cout << "swap: num[" << l << "]:" << nums[l]<< " , nums[" << r << "]:" << nums[r] << std::endl;
                std::swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot)
            {
                l ++;
            }
            if (nums[r] <= pivot)
            {
                r --;
            }
        }
        std::swap(nums[left], nums[r]);
        printvector(nums);
        return r;
    }
    int findKthLargest(std::vector<int>& nums, int k) 
    {
        int kth  = 0;
        int left = 0;
        int right = nums.size() -1;

        if (nums.size() < k)
        {
            return -1;
        }
        while (true)
        {
            int mid = partion(nums, left , right);
            if (mid == k - 1)
            {
                kth = nums[mid];
                break;
            }
            if (mid < k - 1)
            {
                left = mid + 1;
            }
            else
            {
                right= mid - 1;
            }
        }
        return kth;
    }
    int findKthLargest1(std::vector<int>& nums, int k) 
    {
        std::priority_queue<int> p_queue;
        if (nums.size() < k)
        {
            return -1;
        }
        for (auto num : nums)
        {
            p_queue.push(num);
        }
        while (k-- > 1)
        {
            p_queue.pop();
        }
        return p_queue.top();
    }
};

int main()
{
    Solution a;
    int x =  0;
    int k =  0;
    std::vector<int> nums0 = {};
    k = 4;
    a.printvector(nums0);
    x = a.findKthLargest(nums0, k);
    std::cout << k << "--------x:" << x << std::endl;

    std::vector<int> nums = {3,2,1,5,6,4};
    k = 2;
    a.printvector(nums);
    x = a.findKthLargest(nums, k);
    std::cout << k << "--------x:" << x << std::endl;

    std::vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    k = 4;
    a.printvector(nums2);
    x = a.findKthLargest(nums2, k);
    std::cout << k << "--------x:" << x << std::endl;

    return 0;
}

