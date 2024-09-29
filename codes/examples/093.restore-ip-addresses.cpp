/*
 *********************************************
 ******************************************
 *
 */

#include <set>
#include <stack>
#include <queue>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
    std::vector<std::string> restoreIpAddresses1(std::string s)
    {
        std::vector<std::string> res;
        int k = 0;
        int size = s.size();

        auto dfs = [&](auto &&dfs, int start, std::string &path) {
            if (k > 3) {
                return;
            }
            if (k == 3 ) {
                std::cout << std::endl;
                std::cout << "3:" << path << " " << start << " " ;
                std::cout << "size:" << size << " ";
                std::cout << std::endl;
            }
            //if (k == 3 && start >= size) {
            //    res.push_back(path);
            //    return;
            //}
            if (start <= 2+size && k == 3) {
                std::string part = path.substr(start);
                if (part.size() == 0){
                    return ;
                }
                int num = std::stoi(part);
                // 检查当前部分是否有效
                if (num > 255) return; // 数字不能大于255
                if (part.size() >1 && part[0] == '0') {
                    //std::cout if (path.size() >1 && part[0] == '0') {
                    return;   // 不能有前导零
                }

                res.push_back(path);
                return;
            }

            for (int i = 1; i <= 3; ++i) {
                if (start + i>= path.size()) {
                    return;
                }
                std::string part = path.substr(start, i);
                if (part.size() == 0){
                    return ;
                }
                int num = std::stoi(part);
                //std::cout << part << " " << num << " ";

                // 检查当前部分是否有效
                if (num > 255) return; // 数字不能大于255
                if (part[0] == '0' && i > 1) return;   // 不能有前导零

                // 插入点
                path.insert(start + i, ".");
                k++;
                std::cout << " " << path << "+k:" << k << " ";

                // 递归调用
                dfs(dfs, start + i + 1, path);

                // 回溯
                path.erase(start + i, 1);
                k--;
                std::cout << " " << path << "-k:" << k << " ";
                std::cout << std::endl;
            }
        };

        std::string path = s;
        dfs(dfs, 0, path);
        return res;
    }
    std::vector<std::string> restoreIpAddresses(std::string s)
    {
        std::string path=s;
        std::vector<std::string> res;
        int k = 0;
        int size =s.size();
        auto dfs = [&](auto &&dfs, int start) {
            int num = 0;
            if (k>3) {
                return;
            }
            if (k == 3 ) {
                std::cout << std::endl;
                std::cout << "3:" << path << " " << start << " " ;
                std::cout << "size:" << size << " ";
                std::cout << std::endl;
            }
            if (start <= 2+size && k == 3) {
                std::string part = path.substr(start);
                if (part.size() == 0){
                    return ;
                }
                if (part.size() > 3) {
                    return;
                }
                int num = std::stoi(part);
                // 检查当前部分是否有效
                if (num > 255) return; // 数字不能大于255
                if (part.size() >1 && part[0] == '0') {
                    return;   // 不能有前导零
                }

                res.push_back(path);
                return;
            }
            num =0;
            for (int i = 0; i < 3; ++i) {
                if (start +i +1 >= path.size()) {
                    return;
                }
                num = num * 10 + path[start+i] - '0';
                if (i> 0 && path[start+0]  == '0') {
                    return;
                }

                if (num > 255) {
                    continue;
                }
                path.insert(start+i+1, ".");
                k++;
                std::cout << path << " (+" << k << ") ";
                dfs(dfs, start+ i+2);
                k--;
                path.erase(start+i+1, 1);
                //std::cout << path << " " << std:: endl;
                std::cout << path << " (-" << k << ") " << std::endl;
            }
        };
        dfs(dfs, 0);
        return res;
        return {};
    }

};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string& s,
        std::vector<std::string> expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "s:" << s << std::endl;
    std::sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if (TEST__)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.restoreIpAddresses(s);
        std::cout << "solution result:" << result << std::endl;

        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_1)
    {
    }
    if (TEST_2)
    {
    }
    if (TEST_3)
    {
    }
}

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
void Test1()
{
    std::string s = "25525511135";
    std::vector<std::string> expect   = {"255.255.11.135","255.255.111.35"};
    Test("Test1", s, expect);
}
void Test2()
{
    std::string s = "0000";
    std::vector<std::string> expect   = {"0.0.0.0"};
    Test("Test2", s, expect);
}

void Test3()
{
    std::string s = "101023";
    std::vector<std::string> expect   = {"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"};
    Test("Test3", s, expect);
}

void Test4()
{
    std::string s = "0279245587303";
    std::vector<std::string> expect   = {"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"};
    Test("Test3", s, expect);
}

void Test5()
{
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
