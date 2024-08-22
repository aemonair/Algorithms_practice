/*
 ******************************************************************************
 * 30. Substring with Concatenation of All Words
 * Hard
 ******************************************************************************
 * You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
 *
 * You can return the answer in any order.
 ******************************************************************************
 *
 * Example 1:
 *
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.
 ******************************************************************************
 * Example 2:
 *
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 ******************************************************************************
 * Example 3:
 *
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 ******************************************************************************
 * Constraints:
 *
 * 1 <= s.length <= 10^4
 * s consists of lower-case English letters.
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] consists of lower-case English letters.
 ******************************************************************************
 */

#include <unordered_map>
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

template<typename T>
int printvector(std::vector<T> v);

template <typename T>
int printstack(std::stack<T> s);

template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v);

class Solution
{
public:
    //
    std::vector<int> findSubstring_old(std::string s, std::vector<std::string>& words)
    {
        std::unordered_map<std::string ,int> umap;
        for (auto x: words) {
            umap[x]++;
        }
        printunordered_map(umap);
        int left =0, right = 0;
        int match = 0;
        std::vector<int> vect;
        int count = words.size();
        int wsize= words[0].size();
        for (left = 0; left < s.size() - count*wsize+1; left++) {
            match = 0;
            std::unordered_map<std::string,int> umap2(umap);
            for (int j = 0; j< count; j++) {
                std::string str = s.substr(left + j *wsize, wsize);
                std::cout << "j:" << j << ",str:"<< str << ",match:" << match << std::endl;
                if (umap.count(str)  == 0) {
                    std::cout << "str:"<< str << ",break:"<< std::endl;
                    break;
                }
                if (umap.count(str) > 0) {
                    if (umap2[str] > 0) {
                        umap2[str]--;
                        if (umap2[str] == 0) {
                            match ++;
                        }
                    }
                }
            }
            printunordered_map(umap2);
            std::cout << "left:"<< left << ",match:"<< match << std::endl;
            if (match == umap.size()) {
                vect.push_back(left);
            }
        }
        return vect;
    }
    std::vector<int> findSubstring0(std::string s, std::vector<std::string>& words)
    {
        std::unordered_map<std::string , int> umap;
        std::unordered_map<std::string , int> backup;
        for (auto word : words) {
            ++umap[word];
            ++backup[word];
        }
        printunordered_map(umap);
        int match = 0;
        int left = 0;
        std::vector<int> result;
        int ssize = words.size();
        int wsize = words[0].size();
        for (int i = 0; i <= s.size() - ssize*wsize; ++i) {
            match = 0;
            umap = backup;
            for (int j = 0; j < ssize; j++) {
                auto str = s.substr(i + j*wsize, wsize);
                std::cout << " " << str << " ";
                if (umap.count(str)>0){
                    if (--umap[str] == 0) {
                        match++;
                    }
                } else {break;}
            }
            if (match == umap.size()) {
                result.emplace_back(i);
            }
            std::cout << std::endl;
        }
        return result;
        return std::vector<int>();
    }
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
    {
        std::vector<int> results;
        if (s.empty() || words.empty()) return results;

        size_t wordLength = words.front().size();
        size_t totalWords = words.size();
        size_t totalLength = wordLength * totalWords;
        std::unordered_map<std::string, int> wordFrequency;

        // Populate the frequency map
        for (const auto& word : words) {
            ++wordFrequency[word];
        }
        int match = 0;

        // Loop through possible starting points in s
        std::cout << s.size() << " "<< totalLength << " " << std::endl;
        for (size_t start = 0; start < wordLength ;
              //  s.size() - totalLength;
                ++start) {
            std::cout << "start:" << start << " " << s.substr(start, s.size() ) << std::endl;
            match = 0;
            std::unordered_map<std::string, int> currentFrequency(wordFrequency);
            for (int i = start, left = start; i < s.size() - wordLength+1; i += wordLength) {
                std::string str = s.substr(i, wordLength);
                std::cout << " " << str << " ";
                if (currentFrequency.count(str) > 0) {
                    if (--currentFrequency[str] == 0) {
                        ++match;
                    }
                }
                if (i - left  >= totalLength - wordLength) {
                    std::cout << "match:" << match << " ";
                    if (match == currentFrequency.size()) {
                        results.emplace_back(left);
                    }
                    auto lstr = s.substr(left, wordLength);
                    std::cout << " -" << lstr << " ";
                    if (currentFrequency.count(lstr) > 0) {
                        if (++currentFrequency[lstr] == 1) {
                            --match;
                        }
                    }
                    left += wordLength;
                }
            }
            std::cout << std::endl;
        }

        return results ;
    }
};

// ==================== TEST Codes====================
//std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
void Test(const std::string& testName,
        std::string s, std::vector<std::string>& words,
        std::vector<int> expected
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

    std::cout << "s:" << s << std::endl;
    std::cout << "words:" << std::endl;
    printvector(words);

const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //decltype(expected)
        std::vector<int> && result = solution.findSubstring0(s, words);
        //std::vector<int> && result = solution.findSubstring_old(s, words);
        std::cout << "result:" << std::endl;
        printvector(result);

        if(result == expected)
        {
            //10yy
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
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //decltype(expected)
        std::vector<int> && result = solution.findSubstring(s, words);
        std::cout << "result:" << std::endl;
        printvector(result);

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}
void Test1()
{
    std::string s                   = "barfoothefoobarman";
    std::vector<std::string> words  = {"foo","bar"};
    std::vector<int>         expect = {0, 9};
    Test("Test1", s, words, expect);
}
void Test2()
{
    //s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
    //Output: []
    std::string s                   = "wordgoodgoodgoodbestword";
    std::vector<std::string> words  = {"word","good","best","word","bar"};
    std::vector<int>         expect = {};
    Test("Test2", s, words, expect);
}

void Test3()
{
    //Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
    //Output: [6,9,12]
    std::string s                   = "barfoofoobarthefoobarman";
    std::vector<std::string> words  = {"bar","foo","the"};
    std::vector<int>         expect = {6, 9, 12};
    Test("Test3", s, words, expect);
}

void Test4()
{
    std::string s                   = "wordgoodgoodgoodbestword";
    std::vector<std::string> words  = {"word","good","best","good"};
    std::vector<int>         expect = {8};
    Test("Test4", s, words, expect);
}

void Test5()
{
    std::string s                   = "wordgoodgoodgoodbestword";
    std::vector<std::string> words  = {"word","good","best","word"};
    std::vector<int>         expect = {};
    Test("Test5", s, words, expect);
}

void Test6()
{
    std::string s                   = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    std::vector<std::string> words  = {"fooo","barr","wing","ding","wing"};
    std::vector<int>         expect = {13};
    Test("Test6", s, words, expect);
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
    out << "\b\b ]" ;
    return out;
}
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "[ ] Empty vector." << std::endl;
        return 0;
    }
    std::cout << "[ " ;
    for(auto i: v)
    {
        std::cout << i << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    return v.size();
}
template<typename T>
int printstack (std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
}
template<typename T>
int printvector(std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
}
template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v)
{
    std::cout << "unordered_map size: " << v.size() << std::endl;
    for (auto iter = v.begin(); iter != v.end(); iter++ )
    {
        std::cout << "(" << iter->first << "," << iter->second<< "), ";//<<std::endl;
    }
    std::cout << std::endl;
    return v.size();
}
int main()
{
    Test1();
#if 1
    Test2();
    Test3();

    Test4();
    Test5();
    Test6();
#endif

    return 0;
}
