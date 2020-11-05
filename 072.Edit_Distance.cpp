/*
 * 72. Edit Distance
 * Hard
 *
 * Given two words word1 and word2, 
 * find the minimum number of operations required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 ****************************************************** 
 Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

 ****************************************************** 
 Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 ****************************************************** 
 ****************************************************** 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 
class Solution {
public:
    // 
    int dp(std::string word1, std::string word2, int i , int j)
    {
        if (i == -1)
        {
            return j + 1; //删除剩余 word2
        }
        if (j == -1)
        {
            return i + 1; //增加剩余 word1
        }
        if (word1[i] == word2[j])
        {
            return dp(word1, word2, i-1, j-1);
        }
        else
        {
            return std::min( 
                    std::min(
                        dp(word1, word2, i - 1 , j    ) +1 , // delete
                        dp(word1, word2, i     , j - 1) +1 // add
                        ),
                        dp(word1, word2, i - 1 , j - 1) +1  // replace 
                    );
        }
    }
    int minDistance(std::string word1, std::string word2)
    {
        int m = word1.size();
        int n = word2.size();

        return dp(word1, word2, m-1 , n-1);

        std::vector<std::vector<int>> dp(m +1, std::vector<int>(n+1,0));
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int j =1; j <= n; j++)
        {
            dp[0][j] = j;
        }
        for (int i =1; i <= m; i++)
        {
            for (int j =1; j <= n; j++)
            {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = std::min(
                                    std::min(
                            dp[i-1][j] + 1,
                            dp[i][j-1] + 1  ),
                            dp[i-1][j-1] + 1
                            );
            }
        }
        return dp[m][n];
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::string word1, std::string word2,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        std::cout << "word1:" << word1 << std::endl;
        std::cout << "word2:" << word2 << std::endl;

        decltype(expected) result = solution.minDistance(word1, word2);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    std::string word1 = "horse";
    std::string word2 = "ros";
    Test("Test1", word1, word2, 3);
}
void Test2()
{
    std::string word1 = "intention";
    std::string word2 = "execution";
    Test("Test2", word1, word2, 5);
}

void Test3()
{
}

void Test4()
{
}

void Test5()
{
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
