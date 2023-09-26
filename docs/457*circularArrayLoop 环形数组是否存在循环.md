#### [457. 环形数组是否存在循环](https://leetcode.cn/problems/circular-array-loop/)

难度中等

存在一个不含 `0` 的 **环形** 数组 `nums` ，每个 `nums[i]` 都表示位于下标 `i` 的角色应该向前或向后移动的下标个数：

-   如果 `nums[i]` 是正数，**向前**（下标递增方向）移动 `|nums[i]|` 步
-   如果 `nums[i]` 是负数，**向后**（下标递减方向）移动 `|nums[i]|` 步

因为数组是 **环形** 的，所以可以假设从最后一个元素向前移动一步会到达第一个元素，而第一个元素向后移动一步会到达最后一个元素。

数组中的 **循环** 由长度为 `k` 的下标序列 `seq` 标识：

-   遵循上述移动规则将导致一组重复下标序列 `seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...`
-   所有 `nums[seq[j]]` 应当不是 **全正** 就是 **全负**
-   `k > 1`

如果 `nums` 中存在循环，返回 `true` ；否则，返回 `false` 。

**示例 1：**

**输入：** nums = [2,-1,1,2,2]
**输出：** true
**解释：** 存在循环，按下标 0 -> 2 -> 3 -> 0 。循环长度为 3 。

**示例 2：**

**输入：** nums = [-1,2]
**输出：** false
**解释：** 按下标 1 -> 1 -> 1 ... 的运动无法构成循环，因为循环的长度为 1 。根据定义，循环的长度必须大于 1 。

**示例 3:**

**输入：** nums = [-2,1,-1,-2,-2]
**输出：** false
**解释：** 按下标 1 -> 2 -> 1 -> ... 的运动无法构成循环，因为 nums[1] 是正数，而 nums[2] 是负数。
所有 nums[seq[j]] 应当不是全正就是全负。

**提示：**

-   `1 <= nums.length <= 5000`
-   `-1000 <= nums[i] <= 1000`
-   `nums[i] != 0`

**进阶：**你能设计一个时间复杂度为 `O(n)` 且额外空间复杂度为 `O(1)` 的算法吗？
---- ----
1.通过uset记录已获取过的记录，如果已存在记录，判断长度并返回；
2.通过循环数组可以得到，通过快慢指针可以判断是否存在循环；

需要注意，判断方向，
a.`findnext`是通过传入`对应的nums[i] > 0`到函数中作区分判断；
b.`lamdba same`方法通过乘法>0的方式进行判断；
c.为了最终的index>0,注意计算same时，`(i+nums[i])%size+size)%size`;
d.`nums[i] == 0`的判断；
e.`same(i, slow) && same(i, next(fast)) && same(slow, fast) && same(i, fast)`判断条件；

```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums){
        int n=nums.size();
        auto next=[&](int x){return((x+nums[x])%n+n)%n;};
        auto same=[&](int&x,int y){return nums[x]*nums[y]>0;};
        for(int i=0;i<n;i++){
            if(!nums[i])continue;
            int slow=i,fast=next(i);
            while(same(slow,fast)&&same(slow,next(fast))){
                if(slow==fast){
                    if(slow!=next(slow))return true;
                    else break;
                }
                slow=next(slow);
                fast=next(next(fast));
            }
        }
        return false;
    }
};
```

```cpp
    int findnext(std::vector<int> &nums, int index, bool isleft) {
        int size = nums.size();
        int next = (nums[index] + index + size )% size;
        if (nums[next] > 0 && isleft) {
            std::cout << "get next:" << next << std::endl;
            return next;
        }
        if (nums[next] < 0 && !isleft) {
            std::cout << "get next:" << next << std::endl;
            return next;
        }
        return -1;
    }
    bool circularArrayLoop(std::vector<int>& nums)
    {
        int size = nums.size();
        for (int i = 0; i< size; ++i) {

            int slow = i;
            int fast = i;
            bool isforward = nums[i] > 0;

            while (slow != -1 && fast!=-1) {
                slow = findnext(nums, slow, isforward);
                fast = findnext(nums, fast, isforward);
                if (fast != -1) {
                    fast = findnext(nums, fast, isforward);
                }
                if (slow!= -1 && slow==fast) {
                    return true;
                }
            }
        }
        return false;
    }
```

```cpp
    bool circularArrayLoop1(std::vector<int>& nums)
    {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            int curr = nums[i];
            std::unordered_set<int> uset;
            uset.insert(i);
            printunordered_set(uset);
            int next = 0;
            int j = i;
            std::cout << j <<":" << nums[j] << " ";
            while (next != -1) {
                if (curr > 0) {
                    next = findnext(nums, j, true);
                } else {
                    next = findnext(nums, j, false);
                }
                if (next == -1) {
                    std::cout << "can not found" << std::endl;
                    break;
                }
                std::cout << next <<":" << nums[next] << " ";
                if (uset.count(next) > 0) {
                    printunordered_set(uset);
                    if (uset.size() >1){
                        return true;
                    } else {
                        return false;
                    }
                }
                uset.insert(next);
                j = next;
            }
        }
        return false;
    }
```
#FastSlowPointers;
