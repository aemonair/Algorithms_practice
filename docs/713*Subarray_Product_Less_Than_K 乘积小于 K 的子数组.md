#### [713. 乘积小于 K 的子数组](https://leetcode.cn/problems/subarray-product-less-than-k/)

难度中等

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回子数组内所有元素的乘积严格小于 `k` 的连续子数组的数目。

**示例 1：**

**输入：** nums = [10,5,2,6], k = 100
**输出：** 8
**解释：** 8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。

**示例 2：**

**输入：** nums = [1,2,3], k = 0
**输出：** 0

**提示:**

-   `1 <= nums.length <= 3 * 104`
-   `1 <= nums[i] <= 1000`
-   `0 <= k <= 106`

---- ----
1.针对每一个nums[i],增加窗口大小计算乘积的个数；

```
  10  5  2  6

 _10_ 5  2  6   10
 _10__5_ 2  6   10*5
 _10__5__2_ 6
  10 _5_ 2  6   5
  10 _5__2_ 6   5*2
  10 _5__2__6_  5*2*6
  10  5 _2_ 6   2
  10  5 _2__6_  2*6
  10  5  2 _6_  6
```

```cpp
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        // 遍历nums,通过 right增加进行判断；
        for (int i = 0; i < size; i++) {
            int left = i;
            int right = i+1;
            int prod = nums[i];
            if (prod < k) {
                count++;
                while (right < size && prod * nums[right] < k ) {
                        prod *= nums[right];
                        count++;
                        right++;

                }
            }
        }
        return count;
    }
```
2.右指针从左向右遍历，记录乘积，
同时通过 `right-left+1` 记录乘积组合数；如

```
{right},
{right-1,right},
{right-2,right-1,right},
...
{left+1,left+2,...,right-1,right},
{left,left+1,left+2,...,right-1,right};
```
共 `right-left+1` 个组合；
如果大于k则左指针左移；
```
  10  5  2  6    k = 100

 _10_ 5  2  6    right=0, prod=10 ; count = right-left+1 = 1种
 _10__5_ 2  6    right=1, prod=50 ; count = right-left+1 = 2种
 _10__5__2_ 6    right=2, prod=100; prod >= k ; left ++; left = 1;
                          prod=10 ;
  10 _5__2_ 6    right=2, prod=10 ; count = right-left+1 = 2种
  10 _5__2__6_   right=3, prod=60 ; count = right-left+1 = 3种

                                  1+2+2+3 = 8
```

```
  1  2  3  4    k = 10

 _1_ 2  3  4    right=0, prod=1  ; count = right-left+1 = 1种
 _1__2_ 3  4    right=1, prod=2  ; count = right-left+1 = 2种
 _1__2__3_ 4    right=2, prod=6  ; count = right-left+1 = 3种
 _1__2__3__4_   right=3, prod=24 ; prod >= k ; left ++; left = 1;
  1 _2__3__4_            prod/nums[left] =24
  1 _2__3__4_   right=3, prod=24 ; prod >= k ; left ++; left = 2;
  1  2 _3__4_            prod/nums[left] =12
  1  2 _3__4_   right=3, prod=12 ; prod >= k ; left ++; left = 3;
  1  2  3 _4_            prod/nums[left] = 4
  1  2  3 _4_            prod=4  ; count = right-left+1 = 1种
                                 1+2+3+1 = 7种
```

```cpp
    int numSubarrayProductLessThanK1(std::vector<int>& nums, int k)
    {
        // left~right ; right - left +1; left++;
        int prod = 1;
        int count = 0;
        int left = 0;
        int right = 0;
        if (k <= 1) {
            return 0;
        }
        int size = nums.size();
        while (right < size) {
            prod *= nums[right];
            std::cout << nums[left] << "," << nums[right] << "," << prod << " ";
            while (prod >= k) {
                std::cout << nums[left] << "->" << nums[left+1] << "," << nums[right] << "," << prod <<"->" << prod/nums[left] << " ";
                prod /= nums[left];
                left++;
            }
            std::cout << "count:" << right - left +1 << ";" << std::endl;
            count += right -left+1;
            right++;
        }
        return count;
    }
```

https://leetcode.cn/problems/subarray-product-less-than-k/solution/jian-dan-yi-dong-xiang-xi-zhu-jie-shuang-jvy3/
```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        //同样排除k为1的情况比如  [1,1,1] k=1
        if (k <= 1) {
            return 0;
        }
        int left = 0;
        int right = 0;
        //创建一个变量记录路上的乘积
        int mul = 1;
        //记录连续数组的组合个数
        int ans = 0;

        //用右指针遍历整个数组，每次循环右指针右移一次
        while(right<nums.length) {
            //记录乘积
            mul *= nums[right];
            //当大于等于k，左指针右移并把之前左指针的数除掉
            while (mul >= k) {
                mul /= nums[left];
                left++;
            }

            //每次右指针位移到一个新位置，应该加上 x 种数组组合：
            //  nums[right]
            //  nums[right-1], nums[right]
            //  nums[right-2], nums[right-1], nums[right]
            //  nums[left], ......, nums[right-2], nums[right-1], nums[right]
            //共有 right - left + 1 种
            ans += right - left + 1;

            //右指针右移
            right++;
        }
        return ans;
    }
}

作者：ren-feiye
链接：https://leetcode.cn/problems/subarray-product-less-than-k/solution/jian-dan-yi-dong-xiang-xi-zhu-jie-shuang-jvy3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
#TwoPointers;
