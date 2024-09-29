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
        std::unordered_set<std::string> s, t;
        std::vector<std::string> res;
        std::vector<std::vector<char>> ch;
        int m = 0;
        int n = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        size_t maxlen = 0;
        // 四个方向
        //           上 左 下 右
        for (auto word: words) {
            s.insert(word);
            maxlen = std::max(maxlen, word.size());
        }
        n = board.size();
        m = board[0].size();
        std::string path;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        auto dfs = [&](auto&&dfs, int i, int j) {
            if (path.size() > 10) {
                return;
            }
            if (path.size() > maxlen) {
                return ;
            }
            std::cout << path << " ";
            if (s.count(path)) {
                t.insert(path);
            }
            for (int k = 0; k < 4; ++k) {
                 int xx = i + dx[k], yy = j + dy[k];
                 if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy]) {
                     path.push_back(board[xx][yy]);
                     vis[xx][yy] = true;
                     dfs(dfs, xx, yy);
                     vis[xx][yy] = false;
                     path.pop_back();
                 }
            }
        };
        for(int i= 0; i < n; ++i) {
            for(int j= 0; j < m; ++j) {
                vis[i][j] = true;
                path = std::string(1, board[i][j]);
                dfs(dfs, i, j);
                vis[i][j] = false;
            }
        }
        for(std::string tt : t) res.push_back(tt);

        return res;
    }
     std::vector<std::string> findWords1(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        std::vector<std::string> res;
        std::string path;

        int row = board.size();
        int col = board[0].size();
        // std::vector<int> xdir = {0, 0, 1, -1};
        // std::vector<int> ydir = {1, -1, 0, 0};
        int xdir[4] = {-1, 0, 1, 0};
        int ydir[4] = {0, -1, 0, 1};
        // std::unordered_map<std::string, std::string> umap;
        // std::unordered_map<std::string, int> uset;
        std::unordered_set<std::string> ures;
        std::unordered_set<std::string> s;
        size_t maxlen = 0;
        for (auto &word: words) {
            // auto word = words[i];
            // uset[word]++;
            s.insert(word);
            maxlen = std::max(maxlen, word.size());
        }

        std::vector<std::vector<bool>> used =
            std::vector<std::vector<bool>>(row, std::vector<bool>(col, false));
        auto dfs = [&](auto&& dfs, int i, int j) {
            // if (i >= row || j >= col || i < 0 || j < 0 || used[i][j]) {
            //     return;
            // }
            if (path.size() > maxlen) {
                return;
            }
            // std::cout <<path  << " ";
            if(path==words[0]) {
                // std::cout << "found:"<< s.count(path) << std::endl;
            }
            if (s.count(path)) {
                ures.insert(path);
            }
            for (int k = 0; k < 4; ++k) {
                int xx = i + xdir[k];
                int yy = j + ydir[k];
                if (xx >= 0 && xx < row && yy >= 0 && yy < col && !used[xx][yy]) {
                    path.push_back(board[xx][yy]);
                    used[xx][yy] = true;
                    dfs(dfs, xx, yy);
                    used[xx][yy] = false;
                    path.pop_back();
                }
            }
        };
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                used[i][j] = true;
                path = std::string(1, board[i][j]);
                dfs(dfs, i, j);
                used[i][j] = false;
            }
        }
        // dfs(dfs, 0, 0);
        // std::cout << "res:" << ures.size() << std::endl;
        for (std::string s : ures) {
            // std::cout << "s:" << s << std::endl;
            res.push_back(s);
        }
        return res;
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
