/*
 * 78. Subsets
 * Medium
 * Given a set of distinct integers, nums,
 * return all possible subsets (the power set).
 *
 *********************************************
 *********************************************
 * Example:
 * 
 * Input: nums = [1,2,3]
 * Output: 
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 ******************************************
 * Note: 
 * The solution set must not contain duplicate subsets.
 ******************************************
 * 
 */

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

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
    template <typename T>
    int printvectorvector(std::vector<T> v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }

    std::vector<std::vector<int>> subsets1(std::vector<int>& nums) 
    {
        std::vector<int> item;
        std::vector<std::vector<int>> result;

        result.push_back(item);
        generate(0, nums, item, result);

        return result;
    }
    void generate(int i, std::vector<int> &nums,
            std::vector<int> &item,
            std::vector<std::vector<int>> &result)
    {
        if (i >= nums.size())
        {
            return ;
        }
        std::cout << "i:" <<i << ",nums[i]:" << nums[i] << std::endl;
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i + 1, nums, item, result);
        item.pop_back();
        generate(i + 1, nums, item, result);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        int all_set = 1 << nums.size() ;

        for (int i = 0; i < all_set; i++)
        {
            std::vector<int> item;
            for (int j =0; j < nums.size(); j++)
            {
                if ((1<<j) & i)
                {
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};

int main()
{
    int k = 0;
    Solution a;
    std::vector<std::vector<int>> result;

    std::vector<int> nums= {1,2,3};
    a.printvector(nums);
    result = a.subsets(nums);

    a.printvectorvector(result);

    return 0;
}
