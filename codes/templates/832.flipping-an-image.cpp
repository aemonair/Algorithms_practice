/*
 *************************************
 * 832. Flipping an Image
 * Easy
 *************************************
 * Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is reversed.
 *
 * For example, flipping [1,1,0] horizontally results in [0,1,1].
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
 *
 * For example, inverting [0,1,1] results in [1,0,0].
 *************************************
 * Example 1:
 *
 * Input: image = [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 *************************************
 * Example 2:
 *
 * Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *************************************
 * Constraints:
 *
 * n == image.length
 * n == image[i].length
 * 1 <= n <= 20
 * images[i][j] is either 0 or 1.
 *************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
template <typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &v);

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image)
    {
        std::vector<std::vector<int>> results;
        return results;
    }
    std::vector<std::vector<int>> flipAndInvertImage1(std::vector<std::vector<int>>& image)
    {
        return {};
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<int>> & image,
        std::vector<std::vector<int>> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "image:\n" << image << std::endl;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if(TEST__)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<std::vector<int>> && result = solution.flipAndInvertImage(image);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:\n" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}
template <typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &v)
{
    out << "[  ";// << std::endl;
    for (auto iter = v.begin(); iter != v.end(); iter++ )
    {
        out << *iter << ", ";//<<std::endl;
    }
    out << "\b\b ]" << std::endl;
    return out;
}
void Test1()
{
    std::vector<std::vector<int>> image ={{1,1,0},{1,0,1},{0,0,0}};
    Test("Test1",image, std::vector<std::vector<int>>{{1,0,0},{0,1,0},{1,1,1}});
}
void Test2()
{
    std::vector<std::vector<int>> image ={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    Test("Test1",image, std::vector<std::vector<int>>{{1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0}});
}

void Test3()
{
    std::vector<std::vector<int>> image ={{}};
    Test("Test2",image, std::vector<std::vector<int>> {{}});
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

