/*
 * 376. Wiggle Subsequence
 * Medium
 * A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative.
 * The first difference (if one exists) may be either positive or negative.
 * A sequence with fewer than two elements is trivially a wiggle sequence.
 *
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative.
 * In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences,
 * the first because its first two differences are positive and the second because its last difference is zero.
 *
 * Given a sequence of integers,
 * return the length of the longest subsequence that is a wiggle sequence.
 * A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence,
 * leaving the remaining elements in their original order.
 *
 ***************************************
 * Example 1:
 *
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 ***************************************
 * Example 2:
 *
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
 ***************************************
 * Example 3:
 *
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 ***************************************
 *
 */

#include <stack>
#include <vector>
#include <queue>
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




    // 状态机方式
    int wiggleMaxLength1 (std::vector<int>& nums)
    {
        if (nums.size() < 2)
        {
            //序列个数小于2时直接为摇摆序列
            return nums.size() ;

        }
        //扫描序列时的三种状态
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;

        int max_length = 1; //摇摆序列最大长度至少为1
        //从第二个元素开始扫描
        for (int i = 1; i < nums.size() ; i++)
        {
             switch (STATE)
             {
             case BEGIN:
                 if(nums[i] > nums[i-1])//1.)
                 {
                     STATE = UP ;
                     max_length++ ;
                 }
                 else if (nums[i-1] > nums[i])
                 {
                     //2.
                     STATE = DOWN;
                     max_length++;
                 }
                 break;
             case UP:
                 if (nums[i-1] > nums[i] )//3.)
                 {
                     STATE = DOWN;
                     //4.
                     max_length++;
                 }
                 break;
             case DOWN:
                 if(nums[i-1] < nums[i] )//5.)
                 {
                     STATE = UP;
                     max_length++;
                 }
                 break;
             }
        }
        return max_length;
    }

    // 使用isUp区分上升或下降
    int wiggleMaxLength2 (std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int count = 1;
        int isUp  = 2;
        for (int i = 1; i < nums.size(); ++i)
        {
            std::cout << "nums[i-1] :"<< nums[i-1] << " , ";
            std::cout << "nums[i] :"<< nums[i] << std::endl;
            if (nums[i] > nums[i-1] && isUp !=1)
            {
                count ++;
                isUp = 1;
            }
            else if (nums[i] < nums[i-1] && isUp != 0)
            {
                count ++;
                isUp = 0;
            }
            std::cout << "isUp:"<< isUp << " , ";
            std::cout << "count:"<< count << std::endl;
        }
        return count;
    }

    // 使用up和down区分上升或下降
    int wiggleMaxLength3 (std::vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        int up = 1;
        int down = 1;

        for (int i = 1; i < size ; ++i)
        {
            std::cout << "nums[i-1] :"<< nums[i-1] << " , ";
            std::cout << "nums[i] :"<< nums[i] << std::endl;
            if (nums[i] > nums[i-1])
            {
                up = down + 1;
            }
            else if (nums[i] < nums[i-1])
            {
                down = up + 1;
            }
            std::cout << "up :"<< up<< " , ";
            std::cout << "down :"<< down<< std::endl;
        }
        return std::max (up , down);

    }

    // 使用 prevdiff和diff判断
    int wiggleMaxLength(std::vector<int>& nums)
    {
        int flag = 1;
        int max  = 0;
        if (nums.size() < 2)
        {
            return nums.size();
        }
        int size = nums.size();
        int prevdiff = nums[1] - nums[0];
        int count = prevdiff != 0 ? 2: 1;

        for (int i = 2; i < size; i++)
        {
            int diff = nums[i] - nums[i-1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0))
            {
                count ++;
                prevdiff = diff;
            }
        }
        return count;
    }
};

int main()
{
    Solution a;
    std::vector<int> v = {3, 3, 3, 2, 5};
    //std::vector<int> v = {1, 17,5, 10, 13, 15, 10, 5, 16, 8 };
    int wlength = a.wiggleMaxLength(v);
    std::cout << "find:" << wlength << std::endl;
    return 0;
}
