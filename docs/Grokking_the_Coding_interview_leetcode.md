

# Grokking the Coding Interview: Patterns for Coding

[toc]

Questions

## Pattern 2: Sliding Window (11)
### LC 209 ()                                              Maximum Sum Subarray of Size K               (easy)  :

> Given an array of positive numbers and a positive number ‘k’, find the **maximum sum of any contiguous subarray of size ‘k’**.
>
> **Example 1:**
>
> ```
> Input: [2, 1, 5, 1, 3, 2], k=3 
> Output: 9
> Explanation: Subarray with maximum sum is [5, 1, 3].
> ```
>
> **Example 2:**
>
> ```
> Input: [2, 3, 4, 1, 5], k=2 
> Output: 7
> Explanation: Subarray with maximum sum is [3, 4].
> ```



> ```cpp
> K=3
>     2 1 5 1 3 2 Window Sum = 0 Max Sum = 0
>     2_1_5 1 3 2 Window Sum = 8 Max Sum = 8
>     2 1_5_1 3 2 Window Sum = 7 Max Sum = 8
>     2 1 5_1_3 2 Window Sum = 9 Max Sum = 9
>     2 1 5 1_3_2 Window Sum = 6 Max Sum = 9
> ```



```cpp
int findMaxSumSubArray(int k, std::vector<int> &arr)
{
    int start = 0;
    int max = 0;
    int windowsum = 0;
    for(int end =0; end < arr.size(); end++)
    {
        windowsum += arr[end];
        if(end >= k-1)
        {
            max = max(windowsum , max);
            windowsum -= arr[start];
            start++;
        }
    }
    return max;
}
```



### LC 209 (209.Minimum_Size_Subarray_Sum)                 Smallest Subarray with a given sum           (easy)  : @20210107 @20221208

> 209. Minimum Size Subarray Sum - Medium
>
> Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a **contiguous subarray** `[numsl, numsl+1, ..., numsr-1, numsr]` of which the sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.
>
> **Example 1:**
>
> ```
> Input: target = 7, nums = [2,3,1,2,4,3]
> Output: 2
> Explanation: The subarray [4,3] has the minimal length under the problem constraint.
> ```
>
> **Example 2:**
>
> ```
> Input: target = 4, nums = [1,4,4]
> Output: 1
> ```
>
> **Example 3:**
>
> ```
> Input: target = 11, nums = [1,1,1,1,1,1,1,1]
> Output: 0
> ```



```cpp
 7  - [2,3,1,2,4,3]
       2 3 1 2     - 8
         3 1 2 4   - 10
           1 2 4   - 7
             2 4 3 - 9
               4 3 - 7
         
    int minSubArrayLen(int s, std::vector<int> &nums)
    {
        int i =0;
        int j = 0;
        int currentsum = 0;
        int max = -1;
        int min = std::numeric_limits<int>::max();
        int size = nums.size();
        for(i=0; i<size; i++)
        {
            currentsum += nums[i];
            while(currentsum >= s)
            {
                std::cout <<"i:" << i<< ",j:" << j << ",currentsum:" << currentsum ;//<< std::endl;
                //max = std::max((i - j), max);
                min = std::min((i - j+1), min);
                currentsum -= nums[j];
                std::cout << "min:" << min << std::endl;
                j++;
            }
        }
        return min == INT_MAX ? 0: min;
    }
i:3,j:0,currentsum:8min:4
i:4,j:1,currentsum:10min:4
i:4,j:2,currentsum:7min:3
i:5,j:3,currentsum:9min:3
i:5,j:4,currentsum:7min:2
result:2
```



### LC 340 (340.Longest_Substring_with_K_Distinct_Characters)      Substring with K Distinct Characters (medium): @20210108

> 340. Longest Substring with K Distinct Characters
> ******************************************************************************
>  * Given a string, find the length of the longest substring in it with no more than K distinct characters.
> ******************************************************************************
>  * Example 1:
>  * Input: String="araaci", K=2
>  * Output: 4
>  * Explanation: The longest substring with no more than '2' distinct characters is "araa".
> ******************************************************************************
>  * Example 2:
>  * Input: String="araaci", K=1
>  * Output: 2
>  * Explanation: The longest substring with no more than '1' distinct characters is "aa".
> ******************************************************************************
>  * Example 3:
>  * Input: String="cbbebi", K=3
>  * Output: 5
>  * Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
>

```cpp 
K = 2
a r a a c i
     a  r  a  a  c  i
    _a_ r  a  a  c  i max length =1
    _a__r_ a  a  c  i max length =2
    _a__r__a_ a  c  i max length =3
    _a__r__a__a_ c  i max length =4
    _a__r__a__a__c_ i 
                      number of distinct characters > 2(arc),shrink the sliding window
                      max length =4
     a _r__a__a__c_ i
                      number of distinct characters > 2(rac),shrink the sliding window
                      max length =4
     a  r _a__a__c_ i
                      max length =4
     a  r _a__a__c__i
                      number of distinct characters > 2(aci),shrink the sliding window
                      max length =4
     a  r  a  a _c__i
                      max length =4
        
```



> ******************************************************************************

```cpp

int LongestSubstringDistinct0(std::string & s, int k)
    {
        int j = 0;
        int maxlength = std::numeric_limits<int>::min();
        std::unordered_map<int,int> umap;
        for(int i = 0; i < s.size(); i++)
        {
            umap[s[i]]++;
            if(umap.size() <= k)
            {
                maxlength = std::max (i -j+1, maxlength);
            }
            else
            {
                umap[s[j]]--;
                if ( umap[s[j]] ==0 )
                {
                    umap.erase(s[j]);
                }
                j++;
            }
        }
        return maxlength;
    }
```

```cpp
    int LongestSubstringDistinct1(std::string & str, int k)
    {
        int start=0;
        int end = 0;
        int size = str.size();
        int maxlength = 0;
        std::unordered_map<int,int> umap;

        for(end =0; end < size; end++)
        {
            char ch = str[end];
            umap[ch]++;
            while(umap.size() > k)
            {
                umap[str[start]] --;
                if(umap[str[start]] == 0)
                {
                    umap.erase(str[start]);
                }
                start++;
            }
            maxlength = std::max(maxlength, end - start + 1);
        }
        return maxlength;
    }
```



### LC 904 (904.Fruit_Into_Baskets)                        Fruits into Baskets                          (medium): @20210108

> \904. Fruit Into Baskets
>
> Medium
>
> 26713Add to ListShare
>
> You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the **type** of fruit the `ith` tree produces.
>
> You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
>
> - You only have **two** baskets, and each basket can only hold a **single type** of fruit. There is no limit on the amount of fruit each basket can hold.
> - Starting from any tree of your choice, you must pick **exactly one fruit** from **every** tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
> - Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
>
> Given the integer array `fruits`, return *the **maximum** number of fruits you can pick*.
>
>  
>
> **Example 1:**
>
> ```
> Input: fruits = [1,2,1]
> Output: 3
> Explanation: We can pick from all 3 trees.
> ```
>
> **Example 2:**
>
> ```
> Input: fruits = [0,1,2,2]
> Output: 3
> Explanation: We can pick from trees [1,2,2].
> If we had started at the first tree, we would only pick from trees [0,1].
> ```
>
> **Example 3:**
>
> ```
> Input: fruits = [1,2,3,2,2]
> Output: 4
> Explanation: We can pick from trees [2,3,2,2].
> If we had started at the first tree, we would only pick from trees [1,2].
> ```
>
> **Example 4:**
>
> ```
> Input: fruits = [3,3,3,1,2,1,1,2,3,3,4]
> Output: 5
> Explanation: We can pick from trees [1,2,1,1,2].
> ```
>
>  
>
> **Constraints:**
>
> - `1 <= fruits.length <= 105`
> - `0 <= fruits[i] < fruits.length`

```cpp
    template <typename T>
    int totalFruit(std::vector<T> nums)
    {
        int size = nums.size();
        int current = 0;
        int start = 0;
        int end = 0;
        int max = 0;
        std::unordered_map<T, int> umap;
        umap[nums[0]]=1;
        current =1;
        for(end=1; end< size; end++)
        {
            T tmp = nums[end];
            umap[tmp]++;
            current += 1;
            while(umap.size() > 2)
            {
                T s = nums[start];
                current -= 1;//umap[s];
                umap[s]--;
                if(umap[s] == 0)
                {
                    umap.erase(s);
                }
                start++;
            }
            std::cout << "start:" << start << ",end:" << end; //<< ",max:"<<max << std::endl;
            std::cout << "current:" << current << std::endl;
            std::cout << end - start + 1 << std::endl;
            max = std::max(current , max);
            //std::cout << "umap[start]:" << umap[nums[start]]<< "umap[end]:" << umap[nums[end]] <<" " ;//<< std::endl;
            //std::cout << "sum:" <<umap[nums[start]]+umap[nums[end]] << std::endl;
            //max = std::max(max, nums[start]+nums[end]);
        }
        return max;
    }
[ A, B, C, B, B, C ]
Solution0 start..........
start:0,end:1current:2
2
start:1,end:2current:2
2
start:1,end:3current:3
3
start:1,end:4current:4
4
start:1,end:5current:5
5
result:5
```



### LC 003 (003.Longest_Substring_Without_Repeating_Characters)  No-repeat Substring                    (hard)  : @20210108

> \3. Longest Substring Without Repeating Characters
>
> Medium
>
> Given a string `s`, find the length of the **longest substring** without repeating characters.
>
>  
>
> **Example 1:**
>
> ```
> Input: s = "abcabcbb"
> Output: 3
> Explanation: The answer is "abc", with the length of 3.
> ```
>
> **Example 2:**
>
> ```
> Input: s = "bbbbb"
> Output: 1
> Explanation: The answer is "b", with the length of 1.
> ```
>
> **Example 3:**
>
> ```
> Input: s = "pwwkew"
> Output: 3
> Explanation: The answer is "wke", with the length of 3.
> Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
> ```
>
> **Example 4:**
>
> ```
> Input: s = ""
> Output: 0
> ```
>
>  
>
> **Constraints:**
>
> - `0 <= s.length <= 5 * 104`
> - `s` consists of English letters, digits, symbols and spaces.

```cpp
	// 标记并删除umap
    int lengthOfLongestSubstring0(std::string s)
    {
        int start = 0;
        int end = 0;
        std::unordered_map<char, int> umap; // save counter
        int max = std::numeric_limits<int>::min();
        int size = s.size();
        for(end = 0; end < size; end++)
        {
            char c = s[end];
            if(umap.count(c) > 0)
            {
                while(umap.count(c) > 0 && start < end)
                {
                    umap.erase(s[start]);
                    start++;
                }
            }
            else
            {
                max = std::max (max, end - start + 1);
            }
            umap[c]++;
        }
        return max == std::numeric_limits<int>::min()? 0: max;
    }
> s: "pwwkew"
Solution0 start..........
start:0,end:0,c:p, unordered_map size: 1
(p,1),
start:0,end:1,c:w, unordered_map size: 2
(w,1), (p,1),
start:0,end:2,c:w, unordered_map size: 1
(w,1),
start:2,end:3,c:k, unordered_map size: 2
(k,1), (w,1),
start:2,end:4,c:e, unordered_map size: 3
(e,1), (w,1), (k,1),
start:2,end:5,c:w, unordered_map size: 3
(w,1), (e,1), (k,1),
result:3
    // 记录最大start位置
    pwwkew
   _p_ w  w  k  e  w   [{p0}]         start=0,end = 0,maxlength = 1
   _p__w_ w  k  e  w   [{p0}{w1}]     start=0,end = 1,maxlength = 2
   _p__w__w_ k  e  w   [{p0}{w2}]     start=0,end = 2
    p  w _w_ k  e  w                  start=2,end = 2,maxlength = 2 
    p  w _w__k_ e  w   [{p0}{w2}{k3}] start=2,end = 3,maxlength = 3
    p  w _w__k__e_ w   [{p0}{w2}{k3}{e4}] start=2,end = 4,maxlength = 3
    p  w _w__k__e__w   [{p0}{w2}{k3}{e4}] start=2,end = 5
    p  w  w _k__e__w   [{p0}{w5}{k3}{e4}] start=3,end = 5,maxlength = 3    
    int lengthOfLongestSubstring1(std::string s)
    {
        int start = 0;
        int end = 0;
        int size = s.size();
        int maxlength = 0;
        std::unordered_map<char, int> umap;//save greater position
        for(end = 0; end < size; end++)
        {
            char ch = s[end];
            if(umap.count(ch) > 0)
            {
                start = std::max(start, umap[ch]+1);
            }
            umap[ch] = end;
            maxlength = std::max(maxlength, end - start + 1);
        }

        return maxlength;
    }
- - - - - - - - - - - - - - - - - - -
Solution1 start..........
start:0,end:0,ch:p, maxlength:1, unordered_map size: 1
(p,0),
start:0,end:1,ch:w, maxlength:2, unordered_map size: 2
(w,1), (p,0),
start:0,end:2,ch:w, maxlength:2, unordered_map size: 2
(w,2), (p,0),
start:2,end:3,ch:k, maxlength:2, unordered_map size: 3
(k,3), (p,0), (w,2),
start:2,end:4,ch:e, maxlength:3, unordered_map size: 4
(e,4), (k,3), (p,0), (w,2),
start:2,end:5,ch:w, maxlength:3, unordered_map size: 4
(e,4), (k,3), (p,0), (w,5),
result:3
Solution1 passed.
```



### LC 424 (424.Longest_Repeating_Character_Replacemt)     Substring with Same Letters after Replacement(hard)  : @20210109

> \424. Longest Repeating Character Replacement
>
> Medium
>
> You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.
>
> Return *the length of the longest substring containing the same letter you can get after performing the above operations*.
>
> 
>
> **Example 1:**
>
> ```
> Input: s = "ABAB", k = 2
> Output: 4
> Explanation: Replace the two 'A's with two 'B's or vice versa.
> ```
>
> **Example 2:**
>
> ```
> Input: s = "AABABBA", k = 1
> Output: 4
> Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
> The substring "BBBB" has the longest repeating letters, which is 4.
> ```
>
> 
>
> **Constraints:**
>
> - `1 <= s.length <= 105`
> - `s` consists of only uppercase English letters.
> - `0 <= k <= s.length2`，

```cpp
currentmax 记录重复字符,
剩余k个可以替换，
直到end-start-current >= k时再收缩滑动窗口；
    A  A  B  A  B  B  A ,k=1
    0  1  2  3  4  5  6
    A_ A  B  A  B  B  A  end=0,start=0,[{A1}]    ,currentmax=1,end-start+1=1,maxlength = 1,
    A__A_ B  A  B  B  A  end=1,start=0,[{A2}]    ,currentmax=2,end-start+1=2,maxlength = 2,
    A__A__B_ A  B  B  A  end=2,start=0,[{A2}{B1}],currentmax=2,end-start+1=3,maxlength = 3,
    A__A__B__A_ B  B  A  end=3,start=0,[{A3}{B1}],currentmax=3,end-start+1=4,maxlength = 4,
    A__A__B__A__B_ B  A  end=4,start=0,[{A3}{B2}],currentmax=3,end-start-currentmax=1,
                                       [{A2}{B2}],
    A  A__B__A__B_ B  A      ++start=1,                        end-start+1=4,maxlength = 4,
    A  A__B__A__B__B_ A  end=5,start=1,[{A2}{B3}],currentmax=3,end-start-currentmax=1,
                                       [{A1}{B3}],
    A  A  B__A__B__B_ A      ++start=2,                        end-start+1=4,maxlength = 4
    A  A  B__A__B__B__A  end=6,start=2,[{A2}{B3}],currentmax=3,end-start-currentmax=1,
                                       [{A2}{B2}],
    A  A  B  A__B__B__A      ++start=3,                        end-start+1=4,maxlength = 4

```



```cpp
    int characterReplacement(std::string s, int k)
    {   
        int start = 0;
        int end = 0;
        int size = s.size();
        int maxlength = 0;
        int currentmax=0;
        std::unordered_map<char, int> umap;
        for(end =0; end <size; end++)
        {
            char ch = s[end];
            umap[ch]++;
            currentmax = std::max(currentmax, umap[ch]);
            std::cout << "umap[ch]:"<< umap[ch] << " , currentmax:" <<currentmax << std::endl;
            if(end - start - currentmax >= k)
            {   
                umap[s[start]]--;
                start++;
            }   
            maxlength = std::max(maxlength, end - start + 1); 
            std::cout << ", maxlength:" <<maxlength << " "; //std::endl;
            printunordered_map(umap);
        }   
        return maxlength;
    }   
```



```cpp
s:AABABBA ,k: 1
Solution0 start..........
umap[A]:1 , currentmax:1
, maxlength:1 unordered_map size: 1
(A,1), 
umap[A]:2 , currentmax:2
, maxlength:2 unordered_map size: 1
(A,2), 
umap[B]:1 , currentmax:2
, maxlength:3 unordered_map size: 2
(B,1), (A,2), 
umap[A]:3 , currentmax:3
, maxlength:4 unordered_map size: 2
(B,1), (A,3), 
umap[B]:2 , currentmax:3
, maxlength:4 unordered_map size: 2
(B,2), (A,2), 
umap[B]:3 , currentmax:3
, maxlength:4 unordered_map size: 2
(B,3), (A,1), 
umap[A]:2 , currentmax:3
, maxlength:4 unordered_map size: 2
(B,2), (A,2), 
result:4
Solution0 passed.
```

### LC 1004(1004.Max_Consecutive_Ones_III)                 Longest Subarray with Ones after Replacement (hard)  : @20210110

> \1004. Max Consecutive Ones III
>
> Medium
>
> Given a binary array `nums` and an integer `k`, return *the maximum number of consecutive* `1`*'s in the array if you can flip at most* `k` `0`'s.
>
> 
>
> **Example 1:**
>
> ```
> Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
> Output: 6
> Explanation: [1,1,1,0,0,1,1,1,1,1,1]
> Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
> ```
>
> **Example 2:**
>
> ```
> Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
> Output: 10
> Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
> Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
> ```
>
> 
>
> **Constraints:**
>
> - `1 <= nums.length <= 105`
> - `nums[i]` is either `0` or `1`.
> - `0 <= k <= nums.length`

```cpp
K: 2;[ 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 ]

[ 1_ 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 ] end:0 , value:1 ,currentmax:1,end-start+1:1,maxlength :1 
end:0 , A[0](value):1 end-start-currentmax:-1 end-start+1:1 maxlength :1
end:1 , A[1](value):1 end-start-currentmax:-1 end-start+1:2 maxlength :2
end:2 , A[2](value):1 end-start-currentmax:-1 end-start+1:3 maxlength :3
end:3 , A[3](value):0 end-start-currentmax:0 end-start+1:4 maxlength :4
end:4 , A[4](value):0 end-start-currentmax:1 end-start+1:5 maxlength :5
end:5 , A[5](value):0 end-start-currentmax:2 start++:1 end-start+1:5 maxlength :5
end:6 , A[6](value):1 end-start-currentmax:2 start++:2 end-start+1:5 maxlength :5
end:7 , A[7](value):1 end-start-currentmax:2 start++:3 end-start+1:5 maxlength :5
end:8 , A[8](value):1 end-start-currentmax:2 start++:4 end-start+1:5 maxlength :5
end:9 , A[9](value):1 end-start-currentmax:1 end-start+1:6 maxlength :6
end:10 , A[10](value):0 end-start-currentmax:2 start++:5 end-start+1:6 maxlength :6

```



```cpp
    int longestOnes(std::vector<int> &A, int K)                            
    {                                                                      
        int start = 0;                                                     
        int end = 0;                                                       
        int currentmax = 0;                                                
        int maxlength = 0;                                                 
        for(end = 0; end < A.size(); end++)                                
        {                                                                  
            int value = A[end];                                            
            std::cout << "start:" << start << " , A[" << start << "]:" << value << " ";
            if(value == 1)                                                 
            {                                                              
                currentmax++;                                              
            }                                                              
            std::cout << "end:" << end << ",start:" << start << ",currentmax:" << currentmax << " ";
            if(end  - start - currentmax >= K)                             
            {                                                              
                if(A[start]==1)                                            
                {                                                          
                    currentmax--;                                          
                }                                                          
                start++;                                                   
            }                                                              
            maxlength = std::max(maxlength, end - start+1);                
            std::cout << "maxlength :" << maxlength  << " "  <<std::endl;                                                                    
        }                                                                  
        return maxlength;                                                  
    }    
```



```
K: 2;[ 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 ]
Solution0 start..........
start:0 , A[0]:1 end:0,start:0,currentmax:1 maxlength :1 
start:0 , A[0]:1 end:1,start:0,currentmax:2 maxlength :2 
start:0 , A[0]:1 end:2,start:0,currentmax:3 maxlength :3 
start:0 , A[0]:0 end:3,start:0,currentmax:3 maxlength :4 
start:0 , A[0]:0 end:4,start:0,currentmax:3 maxlength :5 
start:0 , A[0]:0 end:5,start:0,currentmax:3 maxlength :5 
start:1 , A[1]:1 end:6,start:1,currentmax:3 maxlength :5 
start:2 , A[2]:1 end:7,start:2,currentmax:3 maxlength :5 
start:3 , A[3]:1 end:8,start:3,currentmax:3 maxlength :5 
start:4 , A[4]:1 end:9,start:4,currentmax:4 maxlength :6 
start:4 , A[4]:0 end:10,start:4,currentmax:4 maxlength :6 
result:6
Solution0 passed.
```



### LC 567 (567.Permutation_in_Sring)                      PC1:                                                 : @20210113


[[567.Permutation_in_Sring  字符串的排列]]
```cpp
   bool checkInclusion(std::string s1, std::string s2) 
    {           
        if(s1.size() > s2.size())
        {
            return false;
        }
        std::unordered_map<char, int> umap1;
        std::unordered_map<char, int> umap2;
        int i = 0;
        for(i = 0; i < s1.size(); i++)
        {       
            umap1[s1[i]]++;
            umap2[s2[i]]++;
        }       
        printunordered_map(umap1);
        int start = 0;
        int end = i;
        do   
        {       
            printunordered_map(umap2);
            if(umap2 == umap1)
            {   
                return true;
            }   
            umap2[s2[end]]++;
            umap2[s2[start]]--;
            if(umap2[s2[start]] == 0)
            {   
                umap2.erase(s2[start]);
            }   
            start++;
            end++;
        }       
        while(end < s2.size());
            if(umap2 == umap1)
            {   
                return true;
            }   
        return false;
        return false;
    }        
s1: "ab"
s2: "eidbaooo"
Solution0 start..........
unordered_map size: 2
(b,1), (a,1), 
unordered_map size: 2
(i,1), (e,1), 
unordered_map size: 2
(d,1), (i,1), 
unordered_map size: 2
(d,1), (b,1), 
unordered_map size: 2
(a,1), (b,1), 
true
Solution0 passed.
```



```cpp
    bool checkInclusion(std::string s1, std::string s2) 
    {   
        std::unordered_map<char ,int> umap1;
        for (int i = 0; i < s1.size(); i++)
        {   
            umap1[s1[i]]++;
        }   
        for (int match=0,end = 0, start =0; end < s2.size(); end++)
        {   
            char ch = s2[end];
            if( umap1.count ( ch ) > 0)
            {   
                umap1[ch]--;
                if(umap1[ch] == 0)
                {
                    match ++; 
                }   
            }   
            if(match == umap1.size())
            {   
                return true;
            }   
            if(end >= s1.size() - 1)
            {   
                char left = s2[start];
                start++;
                if(umap1.count(left) > 0)
                {   
                    if(umap1[left] == 0)
                    {   
                        match--;
                    }   
                    umap1[left]++;
                }   
            }   
        }   
        return false;
    }   
```



### LC 438 (438.Find_All_Anagrams_in_a_String)             PC2:                                                 : @20210113
[[438.Find_All_Anagrams_in_a_String 找到字符串中所有字母异位词]]
> \438. Find All Anagrams in a String
>
> Medium
>
> Given two strings `s` and `p`, return *an array of all the start indices of* `p`*'s anagrams in* `s`. You may return the answer in **any order**.
>
> An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
>
>  
>
> **Example 1:**
>
> ```
> Input: s = "cbaebabacd", p = "abc"
> Output: [0,6]
> Explanation:
> The substring with start index = 0 is "cba", which is an anagram of "abc".
> The substring with start index = 6 is "bac", which is an anagram of "abc".
> ```
>
> **Example 2:**
>
> ```
> Input: s = "abab", p = "ab"
> Output: [0,1,2]
> Explanation:
> The substring with start index = 0 is "ab", which is an anagram of "ab".
> The substring with start index = 1 is "ba", which is an anagram of "ab".
> The substring with start index = 2 is "ab", which is an anagram of "ab".
> ```
>
>  
>
> **Constraints:**
>
> - `1 <= s.length, p.length <= 3 * 104`
> - `s` and `p` consist of lowercase English letters.

```cpp
    std::vector<int> findAnagrams(std::string s, std::string p)
    {            
        std::vector<int> result;
        std::unordered_map<char,int> umap1;
        std::unordered_map<char,int> umap2;
        for(int c=0; c< p.size(); c++)
        {        
            umap2[p[c]]++; 
            umap1[s[c]]++; 
        }        
        printunordered_map(umap1);
        printunordered_map(umap2);
        for(int x=p.size(); x<= s.size(); x++)
        {        
            if(umap1==umap2)
            {    
                result.push_back(x-p.size());
                printvector(result); 
            }    
            umap1[s[x-p.size()]]--;
            umap1[s[x]]++;
            if(umap1[s[x-p.size()]] == 0)
            {    
                umap1.erase(s[x-p.size()]);
            }    
        printunordered_map(umap1);
        }        
        return result;
        return std::vector<int>{};
    } 
s: "abbcabc"
p: "abc"
Solution0 start..........
unordered_map size: 2
(b,2), (a,1), 
unordered_map size: 3
(c,1), (a,1), (b,1), 
unordered_map size: 2
(c,1), (b,2), 
unordered_map size: 3
(a,1), (c,1), (b,1), 
[ 2 ]
unordered_map size: 3
(a,1), (c,1), (b,1), 
[ 2, 3 ]
unordered_map size: 3
(a,1), (c,1), (b,1), 
[ 2, 3, 4 ]
unordered_map size: 3
(c,1), (,1), (b,1), 
[ 2, 3, 4 ]
Solution0 passed.
```



### LC 076 (076.Minimum_Window_Substring)                  PC3:                                                 : @20210121
[[076.Minimum_Window_Substring 最小覆盖子串]]

```cpp
class Solution {
public:
    string minWindow(string s, string t) 
    {
        std::unordered_map<char,int> umap;
        for(auto x:t)
        {
            umap[x]++;
        }
        int left = 0;
        int right = 0;
        int match = 0;
        bool matched = false;
        std::string result;
        int len = std::numeric_limits<int>::max();
        while(right < s.size())
        {
            char c = s[right];
            if(umap.count(c) > 0)
            {
                umap[c]--;
                if(umap[c] == 0)
                {
                    match ++;
                }
            }
            
            while(match == umap.size())
            {
                char a = s[left];
                if ( len > right - left + 1)
                {
                    len = right - left +1;
                    result = s.substr(left, len);
                    std::cout << "left:" << left << ",end:" << right << s.substr(left, right-left+1) << std::endl;

                }
                if(umap.count(a) > 0)
                {
                    umap[a]++;
                    if(umap[a] > 0)
                    {
                        match --;
                    }
                }
                left++;
            }
            right++;
        }
        return (len == std::numeric_limits<int>::max()? "": result);
    }
};
```

### LC 030 (030.Substring_with_Concatenation_of_All_Words) PC4:                                                 : @20210204
> 30. Substring with Concatenation of All Words
> [[030.Substring_with_Concatenation_of_All_Words 串联所有单词的子串]]
> Hard
> You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
> 
> You can return the answer in any order.
> 
> Example 1:
> 
> Input: s = "barfoothefoobarman", words = ["foo","bar"]
> Output: [0,9]
> Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
> The output order does not matter, returning [9,0] is fine too.
> Example 2:
> 
> Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
> Output: []
> Example 3:
> 
> Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
> Output: [6,9,12]
> Constraints:
> 
> 1 <= s.length <= 10^4
> s consists of lower-case English letters.
> 1 <= words.length <= 5000
> 1 <= words[i].length <= 30
> words[i] consists of lower-case English letters.
```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        std::unordered_map<std::string , int> umap;
        for(auto word: words)
        {
            umap[word]++;
        }
        int wordcount = words.size();
        if(wordcount == 0)
        {
            return std::vector<int>();
        }
        std::vector<int> result;
        int wordlength = words[0].size();
        for(int i = 0; i< s.size()- wordcount*wordlength +1; i++)
        {
            std::unordered_map<std::string ,int>  seenword;
            for(int j =0; j < wordcount ; j++)
            {
                int index = i+ j*wordlength;
                std::string word = s.substr(index, wordlength);
                if(umap.count(word) == 0)
                {
                    break;
                }
                seenword[word]++;
                if(seenword[word]>umap[word])
                {
                    break;
                }
                if(j == wordcount-1)
                {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};
```

## Pattern 3: Two Pointers (11)
[[001.Two_Sum 两数之和]]
### LC 1   (001.Two_Sum)                               Pair with Target Sum                         (easy)  : @20210208

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::vector<std::pair<int,int>> records;
        for(int i =0; i< nums.size(); i++)
        {
            records.push_back(std::make_pair(nums[i], i));
        }
        sort(records.begin(), records.end());
        for(int i=0, j = nums.size()-1; i< j ; )
        {
            int result = records[i].first + records[j].first;
            if(result == target)
            {
                return std::vector<int>{records[i].second, records[j].second};
            }
            if(result > target)
            {
                j--;
            }
            if(result < target)
            {
                i++;
            }
        }
        return {};
    }
};
```

### LC 26  (026.Remove_Duplicates_from_Sorted_Array)   Remove Duplicates                            (easy)  : @20210208
### LC 27  (027.Remove_Element)                        Remove Element                               (easy)  : @20210209
### LC 977 (977.Squares_of_a_Sorted_Array)             Squaring a Sorted Array                      (easy)  : @20210209
### LC 15  (15.3Sum)                                   Triplet Sum to Zero                          (medium): @20210209
### LC 16  (016.3Sum_Closest)                          Triplet Sum Close to Target                  (medium): @20210210
### LC 259 (259.3Sum_Smaller)                          Triplets with Smaller Sum                    (medium): @20210210
###         LC 713                                     Subarrays with Product Less than a Target            : @20210212
### LC 75  (075.Sort_Colors)                           Dutch National Flag Problem                  (medium): @20210212
### LC 18  (018.4Sum)                                  PC 1 Quadruple Sum to Target                 (medium): @20210213
### LC 844 (844.Backspace_String_Compare)              PC 2 Comparing Strings containing Backspaces (medium): @20200214
### LC 581 (581.Shortest_Unsorted_Continuous_Subarray) PC 3 Minimum Window Sort                     (medium):

## Pattern 4: Fast & Slow pointers (7)

### LC 141 (141.Linked_List_Cycle)                     LinkedList Cycle                             (easy)  : @20210215
        >                                              length of the LinkedList cycle.
### LC 142 (142.Linked_List_Cycle_II.cpp)              Start of LinkedList Cycle                    (medium): @20210215
### LC 202 (202.Happy_Number)                          Happy Number                                 (medium): @20210219
### LC 876 (876.Middle_of_the_Linked_List)             Middle of the LinkedList                     (easy)  : @20210219
### LC 234                                             Problem Challenge 1                                  :
### LC 143 (234.Palindrome_Linked_List)                Problem Challenge 2                                  : @20210219
### LC 457                                             Problem Challenge 3                                  :

## Pattern 5: Merge Intervals (7)

### LC 056 (056.Merge_Intervals)                       Merge Intervals                              (medium):
        >                                              find out if any two intervals overlap.
### LC 057 (057.Insert_Interval)                       Insert Interval                              (medium): @20210220
### LC 986 (986.Interval_List_Intersections)           Intervals Intersection                       (medium):
### LC 252 (252.Meeting_Rooms)                         Conflicting Appointments                     (easy)  : @20210302
### LC 253 (253.Meeting_Rooms_II)                      Problem Challenge 1:                         (medium):
### LC 124554                                          Problem Challenge 2:Maximum CPU Load                 : @20210302
### LC 759                                             Problem Challenge 3:                         (hard)  :

## Pattern 6: Cyclic Sort (8)
###        (Cyclic Sort)                               Cyclic Sort                                  (easy)  : @20210306
### LC 268 (268.Missing Number)                        Find the Missing Number                      (easy)  : @20210306
### LC 448 (448.Find_All_Numbers_Disappeared_in_Array) Find all Missing Numbers                     (easy)  : @20210307
### LC 287 (287.Find_the_Duplicate_Number)             Find the Duplicate Number                    (easy)  : @20210307
###     >                                              O(1) and without modifying
### LC 442 (442.Find_All_Duplicates_in_an_Array)       Find all Duplicate Numbers                   (medium): @20210307
### LC 645 (645.Set_Mismatch)                          PC 1:Find the Corrupt Pair                   (easy)  : @20210308
### LC 041 (041.First_Missing_Positive)                PC 2:Find Smallest Missing Positive number   (hard)  : @20210309
###         1539. Kth Missing Positive Number                                                       (easy)  : @20210310
###         1539.Kth_Missing_Positive_Number_in_naturalPC 3:Find first k natural numbers missing    (hard)  : @20210311


## Pattern 7: In-place Reversal of a LinkedList (5)
### LC 206 (206.Reverse_Linked_List)                   Reverse a LinkedList                         (easy)  : @20210312
### LC 092 (092.Reverse_Linked_List_II)                Reverse a Sub-list                           (medium): @20210314
           >                                           Reverse the first ‘k’ elements of a given LinkedList.
           >            Given a LinkedList with ‘n’ nodes, reverse it based on its size in the following way:
### LC 025 (025.Reverse_Nodes_in_k-Group)              Reverse every K-element Sub-list             (medium): @20210324
###        (025.Reverse_Alternate_K_Nodes_in_List)     PC 1:Reverse alternating K-element Sub-list  (medium): @20210324
### LC 061 (061.Rotate_List)                           PC 2:Rotate a LinkedList                     (medium): @20210324

## Pattern 8: Tree Breadth First Search (9)
### LC 102 (102.Binary_Tree_Level_Order_Traversal)     Binary Tree Level Order Traversal            (easy)  : @20210325
### LC 107 (107.Binary_Tree_Level_Order_Traversal_II)  Reverse Level Order Traversal                (easy)  : @20210325
### LC 103 (103.Binary_Tree_Zigzag_Level_Order)        Zigzag Traversal                             (medium): @20210325
### LC 637 (637.Average_of_Levels_in_Binary_Tree)      Level Averages in a Binary Tree              (easy)  : @20210325
           >                                           Find the largest value on each level of a binary tree.
### LC 104 (111.Minimum_Depth_of_Binary_Tree)          Minimum Depth of a Binary Tree               (easy)  : @20120325
                                                       Level Order Successor                        (easy)  : @20120326
### LC 117 (117.Populating_Next_Right_Pointers_in_Each)Connect Level Order Siblings                 (medium): @20210326
### LC     (117.Populating_Next_Right_Pointers_in_Each)PC 1: Connect All Level Order Siblings       (medium): @20210326
### LC 199 (199.Binary_Tree_Right_Side_View)           PC 2: Right View of a Binary Tree            (easy)  : @20210326

## Pattern 9: Tree Depth First Search (7)
### LC 112 (112.Path_Sum)                              Binary Tree Path Sum                         (easy)  : @20210327
### LC 113 (113.Path_Sum_II)                           All Paths for a Sum                          (medium): @20210329
    > LC 257 (257.Binary_Tree_Paths)                   All root-to-leaf paths.                      (easy)  : @20210329
### LC 129 (129.Sum_Root_to_Leaf_Numbers)              Sum of Path Numbers                          (medium): @20210329
### LC 1430(1430.Check_If_a_String_Is_a_Valid_Sequence_from_Root_to_Leaves_Path_in_a_Binary_Tree)
                                                       Path With Given Sequence                     (medium): @20210330
### LC 437 (437.Path_Sum_III)                          Count Paths for a Sum                        (medium):
### LC 543 (543.Diameter_of_Binary_Tree)               PC 1: Tree Diameter                          (easy)  : @20210331
### LC 124 (124.Binary_Tree_Maximum_Path_Sum)          PC 2: Path with Maximum Sum                  (hard)  : @20210401

## Pattern 10: Two Heaps (4)
### LC 295 (295.Find_Median_from_Data_Stream)          Find the Median of a Number Stream           (medium): @20210402
### LC 480 (480.Sliding_Window_Median)                 Sliding Window Median                        (hard)  : @20210407
### LC 502 (502.IPO)                                   Maximize Capital                             (hard)  : @20210408
### LC 436 (436.Find_Right_Interval)                   PC 1:                                                : @20210409

## Pattern: Subsets (9)
### LC 078 (078.Subsets)                               Subsets                                      (easy)  : @20210410
```cpp
// []
// [] [] -> [] [1]
// [] [1] -> [] [1] [] -> [] [1] [2] -> [] [1] [2] [1] -> [] [1] [2] [12]
// [] [1] [2] [12] ->
// [] [1] [2] [12] [] -> [] [1] [2] [12] [3] ->
// [] [1] [2] [12] [3] [1] -> [] [1] [2] [12] [3] [13] ->
// [] [1] [2] [12] [3] [13] [2]->  [] [1] [2] [12] [3] [13] [23]->
// [] [1] [2] [12] [3] [13] [23] [12]->[] [1] [2] [12] [3] [13] [23] [123]
    std::vector<std::vector<int>> subsets0(std::vector<int> nums)
    {
        std::vector<std::vector<int>> result;
        result.push_back(std::vector<int>());
        for(int i = 0; i < nums.size() ; i++)
        {
            int size = result.size();
            for(int j = 0; j < size; j++)
            {
                std::vector<int> temp (result[j]);
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
////////////////////////////////////////////////////////////////////////
// subset(n) = subset(nums[:n-1]) x nums[n-1]
    std::vector<std::vector<int>> subsets1(std::vector<int>& nums)
    {
        if(nums.empty())
        {
            return {{}};
        }
        auto back = nums.back();
        nums.pop_back();
        auto res = subsets1(nums);
        int size = res.size();
        for(int i = 0; i < size; i++)
        {
            res.push_back(res[i]);
            res.back().push_back(back);
        }
        return res;
    }
////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> res2;
    std::vector<std::vector<int>> subsets2(std::vector<int>& nums)
    {
        res2.clear();
        std::vector<std::vector<int>> result;
        std::vector<int> track;
        backtrack(nums, 0, track);
        return res2;
    }
    void backtrack(std::vector<int> &nums, int start, std::vector<int> &track)
    {
        res2.push_back(track);
        for(int i =start; i< nums.size() ; i++)
        {
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }
    }
```
### LC 090 (090.Subsets_II)                            Subsets With Duplicates                      (easy)  : @20210412
 Subsets With Duplicates (easy): LC 90
```cpp
// 1 3 5 3
// start [] end
// start [] end []               -> start [] end [1]
// start [] end [1]              -> start [] [1] end []  -> [] [1] [3]  -> [] [1] [3] [1] -> start [] [1] end [3] [13]
// start [] [1] end [3] [13]     ->       [] [1] start [3] [13] end           -> [] [1] start [3] [13] end[3] ->
//       [] [1] start [3] [13] end[33] -> [] [1] start [3] [13] end [33] [13] -> [] [1] start [3] [13] end[33] [133]
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::vector<std::vector<int>> result = {{}};
        if(nums.empty())
        {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        int start = 0;
        int end   = 0;
        for(int i =0; i< nums.size(); i++)
        {
            start = 0;
            if(i>0 && nums[i]==nums[i-1])
            {
                start = end+1;
            }
            end = result.size()-1;
            for(int j = start; j <= end; j++)
            {
                std:vector<int> temp(result[j]);
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
    /*
    [  1, 5, 3, 3]
    start:0,end:0
    {[]}
    {[][  1]}

    start:0,end:1
    {[][  1]}
    {[][  1][  3][  1, 3]}

    start:2,end:3
    {[][  1][  3][  1, 3]}
    {[][  1][  3][  1, 3][  3, 3][  1, 3, 3]}

    start:0,end:5
    {[][  1][  3][  1, 3][  3, 3][  1, 3, 3]}
    {[][  1][  3][  1, 3][  3, 3][  1, 3, 3][  5][  1, 5][  3, 5][  1, 3, 5][  3, 3, 5][  1, 3, 3, 5]}
    */
```
### LC 046 (046.Permutations)                          Permutations                                 (medium): @20210413
Permutations (medium): LC 46

> 回溯
>
> ```
> for 选择 in 选择列表:
>     # 做选择
>     将该选择从选择列表移除
>     路径.add(选择)
>     backtrack(路径, 选择列表)
>     # 撤销选择
>     路径.remove(选择)
>     将该选择再加入选择列表
> ```
>
> 

```cpp
// [ 1 2 5 ]
// { [  1]{    }
// { [  2, 1][  1, 2]{    }
// { [  5, 2, 1][  2, 5, 1][  2, 1, 5][  5, 1, 2][  1, 5, 2][  1, 2, 5]  }
    std::vector<std::vector<int>> permute0(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::queue<std::vector<int>> queue;
        queue.push(std::vector<int>());
        for(auto num: nums)
        {
            auto qsize = queue.size();
            for(int i = 0; i< qsize; i++)
            {
                auto permut = queue.front();
                queue.pop();
                for(int j = 0; j <=permut.size();j++)
                {
                    std::vector<int> temp (permut);
                    temp.insert(temp.begin()+j, num);
                    printvector(temp);
                    if(temp.size() == nums.size())
                    {
                        result.push_back(temp);
                    }
                    else
                    {
                        queue.push(temp);
                    }
                }
            }
        }
        return result;
    }
```
```java
List<List<Integer>> res = new LinkedList<>();

/* 主函数，输入一组不重复的数字，返回它们的全排列 */
List<List<Integer>> permute(int[] nums) {
    // 记录「路径」
    LinkedList<Integer> track = new LinkedList<>();
    backtrack(nums, track);
    return res;
}

// 路径：记录在 track 中
// 选择列表：nums 中不存在于 track 的那些元素
// 结束条件：nums 中的元素全都在 track 中出现
void backtrack(int[] nums, LinkedList<Integer> track) {
    // 触发结束条件
    if (track.size() == nums.length) {
        res.add(new LinkedList(track));
        return;
    }
    
    for (int i = 0; i < nums.length; i++) {
        // 排除不合法的选择
        if (track.contains(nums[i]))
            continue;
        // 做选择
        track.add(nums[i]);
        // 进入下一层决策树
        backtrack(nums, track);
        // 取消选择
        track.removeLast();
    }
}
```



### LC 784 (784.Letter_Case_Permutation)               String Permutations by changing case         (medium): @20210413

 String Permutations by changing case (medium): LC 784
```cpp
// "a1b2"
// [  "a1b2", "A1b2"]
// [  "a1b2", "A1b2"]
// [  "a1b2", "A1b2", "a1B2", "A1B2"]
// [  "a1b2", "A1b2", "a1B2", "A1B2"]
    std::vector<std::string> letterCasePermutation1(std::string S)
    {
        std::vector<std::string> result;
        if(S.empty())
        {
            return result;
        }
        result.push_back(S);
        for(int i =0; i< S.size(); i++)
        {
            if(isalpha(S[i]))
            {
                auto rsize = result.size();
                for(int j =0; j< rsize; j++)
                {
                    auto temp = result[j];
                    if(isupper(temp[i]))
                    {
                        temp[i] = tolower(temp[i]);
                    }
                    else
                    {
                        temp[i] = toupper(temp[i]);
                    }
                    result.push_back(temp);
                }
            }
            printvector(result);
        }
        return result;
    }
```
### LC 022 (022.Generate_Parentheses)                  Balanced Parentheses                         (hard)  : @20210414
### LC 320 (320.Generalized_Abbreviation)              Unique Generalized Abbreviations             (hard)  : LC 320
### LC 241 (241.Different_Ways_to_Add_Parentheses)     PC 1: Evaluate Expression                    (medium): LC 241

### LC 095 (095.Unique_Binary_Search_Trees_II)         PC 2: Structurally Unique Binary Search Trees(medium): LC 95
 Problem Challenge 2: LC 95
```cpp
      1        2
        \    /
         2  1

   1       1          2         3        3
    \       \       /   \      /       /
     2       3     1     3    1       2
      \     /                  \    /
       3   2                    2  1

    std::vector<TreeNode*> generateTrees(int n)
    {
        if(n <= 0)
        {
            return std::vector<TreeNode *>{};
        }
        return findgenerate(1, n);
    }
    std::vector<TreeNode*> findgenerate(int start, int end)
    {
        std::vector<TreeNode*> result;
        if(start > end)
        {
            result.push_back(nullptr);
            return result;
        }
        for(int i = start; i <=end; i++)
        {
            std::vector<TreeNode *> leftSubtrees = findgenerate(start, i-1);
            std::vector<TreeNode *> rigtSubtrees = findgenerate(i+1, end);
            for(auto left: leftSubtrees)
            {
                for(auto right: rigtSubtrees)
                {
                    TreeNode * root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        //printvector(result);
        return result;
    }
```
### LC 096 (096.Unique_Binary_Search_Trees)            PC 3: CountofStructurallyUniqueBSTs          (medium): LC 96
 Problem Challenge 3: LC 96
```cpp
    std::unordered_map<int, int> map;
    int numTrees1(int n)
    {
        if(map.count(n) > 0)
        {
            return map[n];
        }
        if(n <= 1)
        {
            return 1;
        }
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            int leftcount = numTrees1(i-1);
            int rightcount= numTrees1(n-i);
            count += leftcount*rightcount;
        }
        map[n] = count;
        return count;
    }
n:3
i:1,left:1,right:1,sum:1
i:2,left:1,right:1,sum:2
n:2
i:1,left:1,right:2,sum:2
i:2,left:1,right:1,sum:3
i:1,left:1,right:1,sum:1
i:2,left:1,right:1,sum:2
n:2
i:3,left:2,right:1,sum:5
n:3
result:5
```

## Pattern: Modified Binary Search (10)
### LC 704 (704.Binary_Search)                         Order-agnostic Binary Search                 (easy)  : @20210425
 Order-agnostic Binary Search (easy): LC 704
```cpp
    int search(std::vector<int>& nums, int target)
    {
        int left  = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid -1;
            }
            else if (nums[mid] < target)
            {
                left  = mid +1;
            }
        }
        return -1;
    }
```
### LC 000 (704.Ceiling_of_a_number)                   Ceiling of a Number                          (easy)  : @20210426
### LC 000 (704.Floor_of_a_number)                     Floor of a Number                            (easy)  : @20210426
### LC 744 (744.Find_Smallest_Letter_Greater_Than_T)   Next Letter                                  (medium): LC 744
### LC 034 (034.Find_First_and_Last_Position_of_E)     Number Range                                 (medium): LC 34
### LC 702 (702.Search_in_Sorted_Array_of_Unknown_Size)Search in a Sorted Infinite Array            (medium): @20210514
 Search in a Sorted Infinite Array (medium): LC 702
```cpp
class ArrayReader
{
private:
    std::vector<int> v;
public:
    ArrayReader(const std::vector<int> &v)
    {
       this->v = v;
    }
    int get(int i)
    {
        if(i >= v.size())
        {
            return std::numeric_limits<int>::max();
        }
        return v[i];
    }
    friend std::ostream &operator << (std::ostream & in, ArrayReader &a)
    {
        in << "vector size: " << a.v.size() << std::endl;
        for (auto iter = a.v.begin(); iter != a.v.end(); iter++ )
        {
            in << *iter << "| ";//<<std::endl;
        }
        return in ;//v.size();
    }
};

    int search(ArrayReader & reader, int target)
    {
        int left = 0;
        int right = 1;
        while(reader.get(right) < target)
        {
            int newstart = right+1;
            right = right + (right-left+1) *2;
            left = newstart;
        }
        return binarysearch(reader, left, right, target);
    }
    int binarysearch(ArrayReader & reader, int left, int right, int target)
    {
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int midvalue = reader.get(mid);
            if(midvalue > target)
            {
                right = mid-1;
            }
            else if(midvalue < target)
            {
                left = mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
```
### LC 658 (658.Find_K_Closest_Elements)               Minimum Difference Element                   (medium): @20210520
 Minimum Difference Element (medium): LC 658 (k == 1)
```cpp
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int left = 0;
        int right = arr.size() - k ;

        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(x - arr[mid] > arr[mid+k] - x)
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return std::vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
```
### LC 000 (033.Bitonic_Array_Maximum)                 Bitonic Array Maximum                        (easy)  : @20210521
 Bitonic Array Maximum (easy): new (link)
```cpp
         |
1 2 10  8 7 6 5 4
1 4 5  6 7 8 10 2
10  8 7 6 5 4 2 1
1 2 4 5 6 7 8  10
//////\\\\\\\\\\\                mid > right
//////////////\\\  left < mid
\\\\\\\\\\\\\\\\\  left > mid && mid > right
/////////////////  left < mid && mid < right

if(lef < mid)
    if(mid > right)

[mid] [mid+1]

    int searchmax(std::vector<int>& nums)
    {
        int left = 0;
        int right=nums.size()-1;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] <= nums[mid+1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

```
### LC 000 (033.Search_Bitonic_Array)                  PC 1: Search Bitonic Array                   (medium): @20210521
 Problem Challenge 1: Search Bitonic Array (medium)
```cpp
    int search(std::vector<int>& nums, int target)
    {
        int maxindex = searchmax(nums);
        int result = binarysearch(nums, 0, maxindex, target);
        if(result == -1)
        {
            result = binarysearch(nums, maxindex, nums.size() -1, target);
        }
        return result;
    }

    int binarysearch(std::vector<int> &nums, int start , int end, int target)
    {
        bool asc = false;
        if(nums[start] < nums[end])
        {
            asc = true;
        }
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                if(asc)
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }
            else if(nums[mid] < target)
            {
                if(asc)
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
```
### LC 033 (033.Search_in_Rotated_Sorted_Array)        PC 2: Search in Rotated Array                (medium): @20210531
>  081 (081.Search_in_Rotated_Sorted_Array_II)     PC 2: Search in rotated array has duplicates (medium): @20210531
 Problem Challenge 2: LC 33, LC 81
```cpp
   |
1234567
5671234
4567123
```
### LC 153 (153.Find_Minimum_in_Rotated_Sorted_Array)  PC 3: Rotation Count                         (medium): @20210601
>  154 (154.Find_Minimum_in_Rotated_Sorted_Array_II   3: Rotation count rotated has duplicates  (hard)  : @20210601
Problem Challenge 3: LC 153, LC 154

## Pattern: Bitwise XOR (4)
### LC 136 (136.Single_Number)                         Single Number                                (easy)  : @20210601
### LC 260 (260.Single_Number_III)                     Two Single Numbers                           (medium): @20210602
### LC 476 (476.Number_Complement)                     Complement of Base 10 Number                 (medium): @20210602
### LC 832 (832.Flipping_an_Image)                     Problem Challenge 1                          (easy)  : @20210602

## Pattern: Top 'K' Elements (14)
### LC 000 (                                           Top 'K' Numbers                              (easy)  : new
### LC 215 (215.Kth_Largest_Element_in_an_Array)       Kth Smallest Number (smallest/largest)       (easy)  : @20210603
### LC 973 (973.K_Closest_Points_to_Origin)            'K' Closest Points to the Origin             (easy)  : @20210603
### LC 1167(1167.Minimum_Cost_to_Connect_Sticks)       Connect Ropes                                (easy)  : @20210603
### LC 347 (347.Top_K_Frequent_Elements)               Top 'K' Frequent Numbers                     (medium): @20210604
### LC 451 (451.Sort_Characters_By_Frequency)          Frequency Sort                               (medium): @20210604
### LC 703 (703.Kth_Largest_Element_in_a_Stream)       Kth Largest Number in a Stream               (medium): @20210604
### LC 658 (658.Find_K_Closest_Elements)               'K' Closest Numbers                          (medium): @20210604
### LC 000 (658.Maxium_Distinct_Elements)              Maximum Distinct Elements                    (medium):
### LC 000 (                                           Sum of Elements                              (medium):
### LC 767 (767.Reorganize_String)                     Rearrange String                             (hard)  : @20210609
### LC 358 (358.Rearrange_String_k_Distance_Apart)     PC 1:358.Rearrange_String_k_Distance_Apart   (hard)  : @20210616
### LC 621 (621.Task_Scheduler)                        PC 2:621.Task_Scheduler                      (hard)  : LC 621
### LC 895 (895.Maximum_Frequency_Stack)               PC 3:895.Maximum_Frequency_Stack             (hard)  : LC 895

## Pattern: K-way merge (5)
### LC 023 (023.Merge_k_Sorted_Lists)                  Merge K Sorted Lists                         (medium): @20210622
### LC 000 (                                           Kth Smallest Number in M Sorted Lists(array) (Medium): @20210623
     > Given ‘M’ sorted arrays, find the median number among all arrays.
     > Given a list of ‘K’ sorted arrays, merge them into one sorted list.
### LC 378 (378.Kth_Smallest_Element_in_Sorted_Matrix) Kth Smallest Number in a Sorted Matrix       (medium): @20210623
### LC 632 (Smallest_Range_Covering_Elements_from_K_Ls)Smallest Number Range                        (Hard)  : @20210623
### LC 373 (373.Find_K_Pairs_with_Smallest_Sums)       PC 1: largest sum instead of smallest sum    (medium): @20210629

## Pattern : 0/1 Knapsack (Dynamic Programming) (6)
### LC 000 (01.knapsack)                               0/1 Knapsack                                 (medium) : @20210701
### LC 416 (416.Partition_Equal_Subset_Sum)            Equal Subset Sum Partition                   (medium) : @20210701
### LC 000 (416.01.Subset_Sum)                         Subset Sum                                   (medium) : @20210705
### LC 000 (416.02.Minimum_Subset_Sum_Difference)      Minimum Subset Sum Difference                (hard)   : new (link)
### LC 000 (416.03.Count_of_Subset_Sum)                PC 1: Count of Subset Sum                    (medium) : new (link)
### LC 494 (494.Target_Sum)                            PC 2: Target Sum                             (medium) : LC 494

## Pattern: Topological Sort (Graph) (7)
### LC 000 (                                           Topological Sort                             (medium) : new (link)
### LC 207 (                                           Tasks Scheduling                             (medium) : LC 207
### LC 210 (                                           Tasks Scheduling Order                       (medium) : LC 210
### LC 210 (                                           All Tasks Scheduling Orders                  (hard)   : LC 210 (output all possible solutions)
### LC 269 (                                           Alien Dictionary                             (hard)   : LC 269
### LC 444 (                                           PC 1:                                        (medium) : LC 444
### LC 310 (                                           PC 2:                                        (medium) : LC 310

