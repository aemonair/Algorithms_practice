#TwoPointers 
#### [581. 最短无序连续子数组](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/)

难度中等

给你一个整数数组 `nums` ，你需要找出一个 **连续子数组** ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 **最短** 子数组，并输出它的长度。

**示例 1：**

**输入：** nums = [2,6,4,8,10,9,15]
**输出：** 5
**解释：** 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

**示例 2：**

**输入：** nums = [1,2,3,4]
**输出：** 0

**示例 3：**
```
**输入：** nums = [1]
**输出：** 0
```

**提示：**

-   `1 <= nums.length <= 10^4`
-   `-10^5 <= nums[i] <= 10^5`

**Example 1:**

```
Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
```

**Example 2:**

```
Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
```

**Example 3:**

```
Input: [1, 2, 3]
Output: 0
Explanation: The array is already sorted
```

**Example 4:**

```
Input: [3, 2, 1]
Output: 3
Explanation: The whole array needs to be sorted.
```
**进阶：**你可以设计一个时间复杂度为 `O(n)` 的解决方案吗？
1.  From the beginning and end of the array, find the first elements that are out of the sorting order. The two elements will be our candidate subarray.
2.  Find the maximum and minimum of this subarray.
3.  Extend the subarray from beginning to include any number which is bigger than the minimum of the subarray.
4.  Similarly, extend the subarray from the end to include any number which is smaller than the maximum of the subarray.

```cpp
    int findUnsortedSubarray(std::vector<int>& nums)

    {    

        int size = nums.size();

        int low = 0, high = size -1;
        
        // 从前向后找到，是否存在不连续递增的位置，记录low
        while ( low < size -1 && nums[low] <= nums[low+1]){

            low ++;

        }

        if (low == size - 1) {

            return 0;

        }

        while (high > 0 && nums[high] >= nums[high - 1]) {

            high --;

        }
        ／／ 从后向前找到，不连续递增的记录high
        ／／ 获取最大最小
        ／／ 如果存在 左边 比最小值还大的，向左扩展
        ／／ 如果存在 右边 比最大值还小的，向右扩展
        int max = std::numeric_limits<int>::min();

        int min = std::numeric_limits<int>::max();

        for (int i = low ; i <= high ; i++) {

            max = std::max(max, nums[i]);

            min = std::min(min, nums[i]);

        }

        while (low > 0 && nums[low-1] > min) {

            low --;

        }

        while (high < size - 1 && nums[high+1] < max) {

            high ++;

        }

        return high - low + 1;

    }
```