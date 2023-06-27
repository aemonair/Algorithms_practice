#TwoPointers
#### [844. 比较含退格的字符串](https://leetcode.cn/problems/backspace-string-compare/)

难度简单

给定 `s` 和 `t` 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 `true` 。`#` 代表退格字符。

**注意：** 如果对空文本输入退格字符，文本继续为空。

**示例 1：**

**输入：** s = "ab#c", t = "ad#c"
**输出：** true
**解释：** s 和 t 都会变成 "ac"。

**示例 2：**

**输入：** s = "ab##", t = "c#d#"
**输出：** true
**解释：** s 和 t 都会变成 ""。

**示例 3：**

**输入：** s = "a#c", t = "b"
**输出：** false
**解释：** s 会变成 "c"，但 t 仍然是 "b"。

**提示：**

-   `1 <= s.length, t.length <= 200`
-   `s` 和 `t` 只含有小写字母以及字符 `'#'`

**进阶：**

-   你可以用 `O(n)` 的时间复杂度和 `O(1)` 的空间复杂度解决该问题吗？

```cpp //传统方法
    bool backspaceCompare(std::string S, std::string T)
    {   

        int cur = 0;

        int size1 = S.size();

        int size2 = T.size();

        for (int i = 0; i< size1; ++i) {

            if (S[i] != '#') {

                S[cur] =S[i];

                cur += 1;

            } else {

                cur -= 1;

                if (cur < 0) {

                    cur = 0;

                }   

            }   

        }   

        int cur2 = 0;

        for (int i = 0; i< size2; ++i) {

            if (T[i] != '#') {

                T[cur2] =T[i];

                cur2 += 1;

            } else {

                cur2 -= 1;

                if (cur2 < 0) {

                    cur2 = 0;

                }   

            }   

        }   

        std::cout << "cur:" << cur << S.substr(0, cur) << std::endl;

        std::cout << "cur:" << cur << T.substr(0, cur2) << std::endl;

        if (cur == cur2 && S.substr(0, cur) == T.substr(0, cur2)) {

            return true;

        }   

        return false;

    }
```


```cpp
    bool backspaceCompare(std::string S, std::string T)

    {   

        int size1 = S.size();

        int size2 = T.size();

        int end1 = size1 - 1;

        int end2 = size2 - 1;

        int index1 = size1 - 1;

        int index2 = size2 - 1;

        while(end1 >= 0 && end2>= 0) {

            index1 = findnext(S, end1);

            index2 = findnext(T, end2);

            if (index1 < 0 && index2 < 0) {

                return true;

            }   

            if (index1 < 0 || index2 < 0) {

                return false;

            }   

            if (S[index1] != T[index2]) {

                return false;

            }   

            end1 = index1 - 1;

            end2 = index2 - 1;

        }   

        return true;

    }   

    int findnext(std::string str, int end) {

        int count = 0;

        while (end >= 0) { 

            if (str[end] == '#') {

                count ++; 

                end --; 

            } else if (count > 0) {

                count --; 

                end --; 

            } else {

                break;

            }   

        }   

        return end;

    }
```