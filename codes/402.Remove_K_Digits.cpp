/*
 * 402. Remove K Digits
 * Medium
 * Given a non-negative integer num represented as a string,
 * remove k digits from the number so that the new number is the smallest possible.
 *
 * Note:
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 ******************************************
 * Example 1:
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 ******************************************
 * Example 2:
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200.
 * Note that the output must not contain leading zeroes.
 ******************************************
 * Example 3:
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 *
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

    std::string removeKdigits1(std::string num, int k)
    {
        std::string result;
        std::vector<int> s;

        std::cout << "num:" << num << std::endl;
        std::cout << "k:" << k << std::endl;
        //首先将字符串转换为整数，存进栈中
        for (int i= 0; i < num.length() ; ++i)
        {
            int size = s.size();
            int number = num[i] - '0';//将字符串转换为整数

            printvector(s);
            //弹栈（注意顺序，先弹栈后压栈）
            while (s.size() != 0 && s[s.size()-1] > number && k > 0)
            {
                s.pop_back();
                k--;
            }
            //压栈的条件，即最高位不可为0
            if (number !=0 || s.size() != 0)
            {
                s.push_back(number);
            }
        }
        //printvector(s);
        //如果还可以删
        while(s.size() != 0 && k>0)
        {
            s.pop_back();
            k--;
        }
        printvector(s);
        //将整数转换为asicc
        for (int i = 0; i < s.size(); ++i)
        {
            result.append(1, '0' + s[i]);//1表示重复一次后面的字符
        }
        //处理特例
        if (result == "")
        {
            result = "0";
        }
        return result;
    }
	
    //https://leetcode.com/problems/remove-k-digits/discuss/441000/C-greedy-deque-80ms-time-O(N)-space-O(N)
    std::string removeKdigits2(std::string num, int k)
    {
        if (num.length() <= k)
        {
            return "0";
        }
        char deque[num.length()+1] ;// Run time error +1
        std::cout << "length:" << num.length() << std::endl;
        memset(deque, 0, sizeof(deque));
        int ic = -1;
        for (int i =0; i < num.length(); i++)
        {
            while (0 < k && -1 <ic && num[i] < deque[ic])
            {
                ic --;
                k --;
            }
            if (ic == -1 && num[i] == '0')
            {
                continue;
            }
            deque[++ic] = num[i];
            std::cout << "deque:" << deque << std::endl;
        }
        std::cout << "deque:" <<deque << std::endl;
        ic -= k;
        if (ic == -1)
            return "0";
        std::string result ;
        result.append( deque, 0 , ic+1);
        return result;
    }

    //https://leetcode.com/problems/remove-k-digits/discuss/88660/A-greedy-method-using-stack-O(n)-time-and-O(n)-space
    std::string removeKdigits3(std::string num, int k)
    {
        int digits = num.length() - k;
        char stk[num.length()];
        memset(stk, 0, sizeof(stk));

        if (0>=digits)
        {
            return "0";
        }
        int top = 0;

        for (int i = 0; i < num.length(); ++i)
        {
            char c = num[i];
            while (top > 0 && stk[top-1] > c && k > 0)
            {
                std::cout <<"in top:" << top << std::endl;
                std::cout << "in stk[top-1]:" << stk[top-1] << std::endl;
                top -= 1;
                k -= 1;
            }
            stk[top++] = c;
            std::cout <<"end top:" << top << std::endl;
            std::cout << "stk[top-1]:" << stk[top-1] << std::endl;
        }

        int idx = 0;
        while (idx < digits && stk[idx] == '0')
            idx ++;
        int start = idx;
        std::cout  << "start:" << start << std::endl;
        int end = digits - idx;
        std::cout  << "end  :" << end   << std::endl;

        // std::string(stk, start, end) Run Time Error
        std::string str;
        str.append(stk+start, end);
        std::cout << "string:" <<str<< std::endl;;
        return idx == digits ? "0": str;
    }

    // https://leetcode.com/problems/remove-k-digits/discuss/88680/My-Easy-Understandable-C%2B%2B-Solution
    std::string removeKdigits4(std::string num, int k)
    {   
        std::string result = "";
        int n = num.size();
        int keep = n - k;
        for (char c : num)
        {
            while (k && result.size() && result.back() > c)
            {
                result.pop_back();
                --k;
            }
            result.push_back(c);
        }
        result.resize(keep);
        while (!result.empty() && result[0] == '0')
        {
            result.erase(result.begin());
        }
        return result.empty()? "0":result;
    }

    std::string removeKdigits5(std::string num, int k)
    {
        int kk = k;
        std::string result;
        if (num.size() <= k)
        {
            return "0";
        }
        for (auto c:num)
        {
            while (!result.empty() && k > 0 && result[result.size() -1] > c)
            {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        std::cout << "for:" << result <<  std::endl;
        while (!result.empty() && '0' == result[0])
        {
            result.erase(result.begin());
        }
        std::string test = std::string(result, 0, num.size() -k);
        std::cout << "size-k:" << num.size()-kk << " ,str:" << test << std::endl;
        return result == ""?"0":std::string(result,0, num.size()-kk);
    }
};

int main()
{
    int k = 0;
    Solution a;
    std::string str;
    std::string result;

    str = "1432219";
    k = 3;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 1432219:" << result << std::endl;

    str = "100200";
    k = 1;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 100200:" << result << std::endl;

    str = "10";
    k = 2;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 10:" << result << std::endl;

    str = "12345";
    k = 3;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 12345:" << result << std::endl;

    str = "1234567890";
    k = 9;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 1234567890:" << result << std::endl;

    str = "1173";
    k = 2;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 1173:" << result << std::endl;


    str = "9";
    k = 1;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 9:" << result << std::endl;

    str = "112";
    k = 1;
    std::cout << "str: " << str << " , k:" << k << std::endl;
    result = a.removeKdigits(str, k);
    std::cout << "result 112:" << result << std::endl;

    return 0;
}
