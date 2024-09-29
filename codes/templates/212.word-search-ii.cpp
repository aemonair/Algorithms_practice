/*
 *************************************************************************************************
 *  212. Word Search II
 *************************************************************************************************
 * Given an m x n board of characters and a list of strings words, return all words on the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 *************************************************************************************************
 * Example 1:
 * Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
 *
 * Output: ["eat","oath"]
 *************************************************************************************************
 * Example 2:
 *
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 *************************************************************************************************
 * Constraints:
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] is a lowercase English letter.
 * 1 <= words.length <= 3 * 104
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 *************************************************************************************************
 *
 */
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define     RESET   "\033[0m"
#define     RED     "\033[31m"             /*      Red     */
#define     CYAN    "\033[36m"             /*      Cyan    */
#define     BLUE    "\033[34m"             /*      Blue    */
#define     GREEN   "\033[32m"             /*      Green   */
#define     WHITE   "\033[37m"             /*      White   */
#define     BLACK   "\033[30m"             /*      Black   */
#define     YELLOW  "\033[33m"             /*      Yellow  */
#define     MAGENTA "\033[35m"             /*      Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow  */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black   */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White   */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green   */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan    */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red     */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
            std::vector<std::string>& words) {
        return {};
    }
     std::vector<std::string> findWords1(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        return {};
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<char>>& board,
        std::vector<std::string> &words,
        std::vector<std::string> expected
        )
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "board:"<< std::endl;
    std::cout << board << std::endl;
    std::cout << "words:"<< words << std::endl;
    sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) solution_result = solution.findWords(board, words);
        std::cout << "solution result:" << solution_result << std::endl;
        sort(solution_result.begin(), solution_result.end());

        if(solution_result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_1)
    {
    }
}

// 75yy
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]"<< std::endl ;
    return out;
}

void Test1()
{
    std::vector<std::vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    std::vector<std::string> words = {"oath","pea","eat","rain"};
    std::vector<std::string> expect = {"eat","oath"};
    Test("Test1", board, words, expect);
}
void Test2()
{
    std::vector<std::vector<char>> board = {{'a','b'},{'c','d'}};
    std::vector<std::string> words = {"abcd"};
    std::vector<std::string> expect = {};
    Test("Test2", board, words, expect);
}

void Test3()
{
    std::vector<std::vector<char>> board = {{'a','b'},{'c','d'}};
    std::vector<std::string> words = {"ab","ba"};
    std::vector<std::string> expect = {"ab","ba"};
    Test("Test3", board, words, expect);
}

void Test4()
{
    std::vector<std::vector<char>> board = {{'a','b'},{'c','d'}};
    std::vector<std::string> words = {"dca"};
    std::vector<std::string> expect = {"dca"};
    Test("Test4", board, words, expect);
}

void Test5()
{
    std::vector<std::vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    std::vector<std::string> words = {"oath","pea","eat","rain","hklf", "hf"};
    std::vector<std::string> expect = {"oath","eat","hklf","hf"};
    Test("Test5", board, words, expect);
}

void Test6()
{
    std::vector<std::vector<char>> board = {{'o'}};
    std::vector<std::string> words = {"o"};
    std::vector<std::string> expect = {"o"};
    Test("Test6", board, words, expect);
}
void Test7()
{
    std::vector<std::vector<char>> board = {{'a','a'}};
    std::vector<std::string> words = {"aaa"};
    std::vector<std::string> expect = {};
    Test("Test7", board, words, expect);
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;

}
