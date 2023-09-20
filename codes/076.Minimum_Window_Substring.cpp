/*
 * 76. Minimum Window Substring
 * Hard
 ******************************************************************************
 * Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
 *
 * Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
 ******************************************************************************
 * Example 1:
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 ******************************************************************************
 * Example 2:
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 ******************************************************************************
 * Constraints:
 *
 * 1 <= s.length, t.length <= 10^5
 * s and t consist of English letters.
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
    std::string minWindow0(std::string s, std::string t)
    {
        std::unordered_map<char, int> u1;
        std::unordered_map<char, int> u2;

        for (auto x: t) {
            u1[x] ++;
        }
        int left = 0;
        int right = 0;
        int minleft = 0;
        int minlen = std::numeric_limits<int>::max();
        for (left = 0; right < s.size();right++) {
            char chr = s[right];
            if (u1.count(chr) > 0) {
                u2[chr]++;
                while(u2[chr] > u1[chr]) {
                    char chl = s[left];
                    if (u1.count(chl) > 0){
                        u2[chl]--;
                    }
                    left++;
                }
            }
            
            while (u1 == u2) {
                char chl = s[left];
                if (minlen > right -left+1) {
                    minlen = right-left+1;
                    minleft = left;
                }
                if (u1.count(chl) > 0) {
                    u2[chl]--;
                }
                std::cout << "|:"<< s[left] << "~" << s[right]<< "min:" << minleft << ",len:" << minlen<<std::endl;
                left++;
            }
        }
        std::cout << "left:"<<s[left] << "min:" << minlen << std::endl;
        if (minlen ==std::numeric_limits<int>::max()) {
            return {};
        }
        return s.substr(minleft, minlen);
        return std::string();
    }
    std::string minWindow1(std::string s, std::string t){
        std::unordered_map<char, int> umap;
        for (auto x: t) {
            umap[x] ++;
        }
        printunordered_map(umap);
        int left = 0;
        int right = 0;
        int match = 0;
        int minlen = std::numeric_limits<int>::max();
        int minleft = 0;
        while (right < s.size()) {
            char chr = s[right];
            if (umap.count(chr) > 0) {
                umap[chr] --;
                if (umap[chr] >= 0) {
                    match ++;
                }
            }
            std::cout << left << "~" << right << ":" << s.substr(left, right - left + 1) << ",match:" << match << std::endl;
            printunordered_map(umap);
            while (match == t.size()) {
                if (minlen > right -left+1) {
                    minlen = right - left + 1;
                    minleft = left;
                }
                char chl = s[left];
                if (umap.count(chl) >0) {
                    if (umap[chl] == 0){
                        match --;
                    }
                }
                umap[chl] ++;
                left++;
            printunordered_map(umap);
                std::cout << "match:"<<left << "~" << right << ":" << s.substr(left, right - left + 1) << ",match:" << match << std::endl;
            }
            right++;
        }
        if (minlen == std::numeric_limits<int>::max()) {
            return {};
        } else {
            return s.substr(minleft, minlen);
        }
        return std::string();
    }
    std::string minWindow2(std::string s, std::string t)
    {
        std::unordered_map<char, int> umap;
        for (auto x: t) {
            umap[x] ++;
        }
        int left = 0;
        int right = 0;
        int match = 0;
        int minlen = std::numeric_limits<int>::max();
        int minleft = 0;
        while (right < s.size()) {
            char chr = s[right];
            if (umap.count(chr) > 0) {
                umap[chr] --;
                if (umap[chr] == 0) {
                    match ++;
                }
            }
                printunordered_map(umap);
            std::cout << left << "~" << right << ":" << s.substr(left, right - left + 1) << ",match:" << match << std::endl;
            while (match == umap.size()) {
                char chl = s[left];
                if (minlen > right -left+1) {
                    minlen = right - left + 1;
                    minleft = left;
                }
                if (umap.count(chl) > 0) {
                    umap[chl] ++;
                    if (umap[chl] > 0)  {
                        match --;
                    }
                }
                left++;
                printunordered_map(umap);
                std::cout << "match:"<<left << "~" << right << ":" << s.substr(left, right - left + 1) << ",match:" << match << std::endl;
            }
            right++;
        }
        if (minlen == std::numeric_limits<int>::max()) {
            return {};
        } else {
            return s.substr(minleft, minlen);
        }
        return std::string();
    }
};


// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string s, std::string t,
        std::string expected
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
    std::cout << "t:" << t << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.minWindow0(s, t);
        std::cout << "result:\"" << result << "\"" << std::endl;

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

        decltype(expected) result = solution.minWindow1(s, t);
        std::cout << "result:\"" << result << "\"" << std::endl;

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
    if (TEST_2)
    {
        std::cout << "Solution2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.minWindow2(s, t);
        std::cout << "result:\"" << result << "\"" << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
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
    out << "\b\b ]" ;
    return out;
}
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "Empty vector." << std::endl;
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
    //std::cout << "unordered_map size: " << v.size() << std::endl;
    for (auto iter = v.begin(); iter != v.end(); iter++ )
    {
        std::cout << "(" << iter->first << "," << iter->second<< "), ";//<<std::endl;
    }
    std::cout << std::endl;
    return v.size();
}
void Test1()
{
    std::string s      = "ADOBECODEBANC";
    std::string t      = "ABC";
    std::string expect = "BANC";
    Test("Test1", s, t, expect);
    /*
     * s:ADOBECODEBANC
     * t:ABC
     *
     * unordered_map size: 3
     * (C,1), (A,1), (B,1),
     * right:0 A window[A]++ valid++ == 1
     * window: [0, 1)A
     * right:1 D  valid  == 1
     * window: [0, 2)AD
     * right:2 O  valid  == 1
     * window: [0, 3)ADO
     * right:3 B window[B]++ valid  == 2
     * window: [0, 4)ADOB
     * right:4++ E  valid  == 1
     * window: [0, 5)ADOBE
     * right:5++ C window[C]++ valid  == 3
     * window: [0, 6)ADOBEC
     * right-left : 6 -0,start = 0,len = 6,
     * A left=1,valid -- =2, window[A]-- = 0
     * right:6++ O  valid  == 2
     * window: [1, 7)DOBECO
     * right:7++ D  valid  == 2
     * window: [1, 8)DOBECOD
     * right:8++ E  valid  == 2
     * window: [1, 9)DOBECODE
     * right:9++ B window[B]++ valid  == 2
     * window: [1, 10)DOBECODEB
     * right:10++ A window[A]++ valid  == 3
     * window: [1, 11)DOBECODEBA
     * right-left: 11-1=10 > len 6
     * D left++ =2 need[D]==0
     * right-left :11-2=9 >len 6
     * O left++ =3 need[O]==0
     * right-left :11-3=8 >len 6
     * B left++ =4 need[B]==1, window[B]==2,window[B]--
     * right-left :11-4=7 >len 6
     * E left++ =5 need[E]==0
     * right-left :11-5=6 == len 6
     * C left++ =6 need[C]==1, window[C]==1,valid-- =2,window[C]--
     * while(valid != )
     * N right:11++ N need[N]==0,
     * window: [6, 12)ODEBAN
     * valid == 2
     * C right:12++ window[C]++, valid++ == 3
     * window: [6, 13)ODEBANC
     * 13 - 6
     * right - left:7 > len 6
     * s[left] O, need[O] == 0,left++ 7
     * right - left:6 > len 6
     * s[left] D, need[D] == 0,left++ 8
     * right - left:5 < len 6
     * start = left, 8,len = right - left == 5, left++ 9
     * s[left] E, need[E] == 0,left++ 10
     * right - left: 3 < len 6
     * start = left ,10,s[left] = B,left++ = 11
     * need[B] > 0,window[B]== 2,valid-- =2,window[B]--=1
     * right: 13++
     * result:BANC
     * */
}
void Test2()
{
    std::string s      = "a";
    std::string t      = "a";
    std::string expect = "a";
    Test("Test2", s, t, expect);
}

void Test3()
{
    std::string s      = "a";
    std::string t      = "aa";
    std::string expect = "";
    Test("Test3", s, t, expect);
}

void Test4()
{
    std::string s      = "aabdec";
    std::string t      = "abc";
    std::string expect = "abdec";
    Test("Test4", s, t, expect);
}

void Test5()
{
    std::string s      = "aababdec";
    std::string t      = "abbc";
    std::string expect = "babdec";
    Test("Test5", s, t, expect);
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
