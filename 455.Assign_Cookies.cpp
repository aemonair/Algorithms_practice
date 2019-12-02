/*
 * 455. Assign Cookies
 * Easy
 * 
 * Assume you are an awesome parent and want to give your children some cookies. 
 * But, you should give each child at most one cookie. 
 * Each child i has a greed factor gi, 
 * which is the minimum size of a cookie that the child will be content with; 
 * and each cookie j has a size sj. If sj >= gi, 
 * we can assign the cookie j to the child i, 
 * and the child i will be content. 
 * Your goal is to maximize the number of your content children and output the maximum number.
 * 
 * Note:
 * You may assume the greed factor is always positive.
 * You cannot assign more than one cookie to one child.
 * 
 ************************************************
 * Example 1:
 * Input: [1,2,3], [1,1]
 * 
 * Output: 1
 * 
 * Explanation: 
 * You have 3 children and 2 cookies. 
 * The greed factors of 3 children are 1, 2, 3.
 *
 * And even though you have 2 cookies, 
 * since their size is both 1, 
 * you could only make the child whose greed factor is 1 content.
 *
 * You need to output 1.
 *
 ************************************************
 * Example 2:
 * Input: [1,2], [1,2,3]
 * 
 * Output: 2
 * 
 * Explanation: 
 * You have 2 children and 3 cookies. 
 * The greed factors of 2 children are 1, 2.
 *
 * You have 3 cookies and their sizes are big enough to gratify all of the children,
 * You need to output 2.
 * 
 ************************************************
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

      int findContentChildren(std::vector<int>& g, std::vector<int>& s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        for (i = 0, j = 0; i < g.size() && j < s.size();)
        {
            if (s[j] >= g[i])
                i++;
            j++;
        }
        return i;
    }

    int findContentChildren1(std::vector<int>& g, std::vector<int>& s) 
    {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        printvector(g);
        printvector(s);
        int find = 0;
        auto si = s.begin();
        auto gi = g.begin();
        for (; si !=s.end() && gi != g.end();)
        {
            if (*si >= *gi)
            {
                find ++;
                si++;
                gi++;
            }
            else
            {
                si++;
            }
        }
        return find;
    }
};

int main()
{
    Solution a;
    std::vector<int> g = {1, 2, 3};
    std::vector<int> s = {1, 1};
    //std::vector<int> g = {5, 10, 2, 9, 15, 9};
    //std::vector<int> s = {6, 1, 20, 3, 8};
    int findcontentchildren = a.findContentChildren(g, s);
    std::cout << "find:" << findcontentchildren << std::endl;
    return 0;
}
