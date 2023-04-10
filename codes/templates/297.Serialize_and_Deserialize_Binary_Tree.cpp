/*
 * 297. Serialize and Deserialize Binary Tree
 * Hard
 *************************************************************************************
 * Serialization is the process of converting a data structure or object into a sequence of bits so that 
 *  it can be stored in a file or memory buffer, 
 * or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree.
 * There is no restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and 
 *  this string can be deserialized to the original tree structure.
 * 
 *************************************************************************************
 * Example:
 * 
 * You may serialize the following tree:
 * 
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * Clarification: 
 *  The above format is the same as how LeetCode serializes a binary tree.
 *  You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 * 
 *************************************************************************************
 * Example 1:
 * 
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * 
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *************************************************************************************
 * Example 2:
 * 
 * Input: root = []
 * Output: []
 *************************************************************************************
 * Example 3:
 * 
 * Input: root = [1]
 * Output: [1]
 *************************************************************************************
 * Example 4:
 * 
 * Input: root = [1,2]
 * Output: [1,2]
 *************************************************************************************
 * Note: 
 * Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 *************************************************************************************
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *************************************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize0(TreeNode* root)
    {
        std::string str = "";
        if (root ==nullptr)
        {
            return str;
        }
        int lastone = serial0(root, str);
        std::cout <<  "lastone:" << lastone << std::endl;
        int expand  = str.find(std::to_string(lastone));
        std::cout <<  "expand:" << expand << std::endl;
        str[expand+1]='\0';
        return str.substr(0, expand+1);
        //return str;
    }
    std::string serialize01(TreeNode* root)
    {
        std::string str = "";
        if (root ==nullptr)
        {
            return str;
        }
        serialordinary(root, str);
        //std::cout <<  "lastone:" << lastone << std::endl;
        //int expand  = str.find(std::to_string(lastone));
        //std::cout <<  "expand:" << expand << std::endl;
        //str[expand+1]='\0';
        //return str.substr(0, expand+1);
        return str;
    }

    int serial0(TreeNode *root, std::string &str)
    {
        std::queue<TreeNode *> q;
        std::string curstr = "";
        int number = 0;
        int last   = 0;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            if (cur->val == -1)
            {
                q.pop();
                curstr = "null,";
                str += curstr;
                continue;
            }
            else
            {
                number++;
                curstr = std::to_string(cur->val)+",";
                str += curstr;
                last = cur->val;
                std::cout << "str:" << str << std::endl;
            }
            q.pop();
            if (cur ->left != nullptr)
            {
                q.push(cur->left);
            }
            else if (cur->left ==nullptr)
            {
                q.push(new TreeNode(-1));
            }
            if (cur ->right)
            {
                q.push(cur->right);
            }
            else if (cur->right==nullptr)
            {
                q.push(new TreeNode(-1));
            }
        }
        std::cout << "number:" << number << std::endl;
        std::cout << "last:" << last << std::endl;
        return last;
    }

    void serialordinary(TreeNode *root, std::string &str)
    {
        std::string cur = "";
        if (root)
        {
            cur = std::to_string(root->val) + ",";
            str += cur;
            serialordinary(root->left , str);
            serialordinary(root->right, str);
        }
        else
        {
            cur += "null,";
            str += cur;
        }
    }
//    str:1,2,null,null,3,4,null,null,5,null,null,

    // Decodes your encoded data to tree.
    TreeNode* deserialize0(std::string data)
    {
        std::cout << data << std::endl;
        int size = data.size();
        int left = 0;
        int right = 0;

//        std::vector<std::string> v;
        std::vector<TreeNode *> v;
        TreeNode *proot = nullptr;

        if(size==0)
        {
            return proot;
        }
        int index = 0;
        int end = 0;
        for (int i =0; i < size; ++i)
        {
            if (data[i] == ','|| i == size-1)
            {
                std::cout << "index:" << index << ":" << data[index] << std::endl;
                std::cout << "i:" << i << ":" << data[i] << std::endl;
                std::string s = "";
                if (i== size-1)
                {
                    s = data.substr(index,size-index);
                }
                else
                {
                    s = data.substr(index,i-index);
                }
                index = i+1;
                if (s== "null")
                {
                    v.push_back(nullptr);
                }
                else
                {
                    v.push_back(new TreeNode(std::stoi(s)));
                }
            }
        }
        printvector(v);
        // 1 2 3 N N 4
        // 1 N 2 N 3 4 N
         int value = 0; //
        //std::cout << "root value :" << value << std::endl;

        proot = v[0];
        for (left = 0,right = 1; right < v.size() ; left++)
        {
            //std::cout << "left:" << left << ",right:" << right << std::endl;

            if(v[left] == nullptr)
            {
                continue;
            }
            v[left]->left  = v[right];
            right++;
            if (right >= v.size())
            {
                break;
            }
            v[left]->right = v[right];
            right++;
        }


        return proot  ;
    }
        //for (left = 0,right = 1; right < v.size() ; )
        //{
        //    std::cout << "left:" << left << ",right:" << right << std::endl;
        //    std::cout << "v[left]:" << v[left] << ",v[right]:" << v[right] << std::endl;
        //    if (v[left] == "null")
        //    {
        //        left ++;
        //        continue;
        //    }
        //    int value = std::stoi ( v[left] , nullptr ,0);
        //    std::cout << "root value :" << value << std::endl;
        //    TreeNode * root = new TreeNode(value);
        //    if (proot==nullptr)
        //    {
        //        proot = root;
        //    }
        //    left++;
        //    
        //    if (v[right] != "null")
        //    {
        //        int value2 = std::stoi ( v[right], nullptr, 0 );
        //        std::cout << value << "root left value :" << value2 << std::endl;
        //        TreeNode * root2 = new TreeNode(value2);
        //        root->left = new TreeNode(value2);
        //    }
        //    right++;

        //    if (v[right] != "null")
        //    {
        //        int value3 = std::stoi ( v[right] , nullptr, 0);
        //        std::cout << value << "root right value :" << value3 << std::endl;
        //        TreeNode * root2 = new TreeNode(value3);
        //        root->right = new TreeNode(value3);
        //    }
        //    right++;
        //}
 
///////////////////////////////////////////////////////////////////////////////////////////////////////    
    std::string serialize1(TreeNode* root)
    {
        return "";
    }
    TreeNode* deserialize1(std::string preorder)
    {
        return nullptr;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////    
    std::string serialize2(TreeNode* root)
    {
        return "";
    }
    TreeNode* deserialize2(std::string postorder)
    {
        return nullptr;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////    
    template <typename T>
    int printvector(std::vector<T> v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";
        }
        std::cout << std::endl;
        return v.size();
    }
    int printvector(std::vector<TreeNode *> v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (int i = 0; i < v.size(); i++ )
        {
            if(v[i]==nullptr)
            {
                std::cout << "null" << "| ";
            }
            else
            {
                std::cout << v[i]->val << "| ";
            }
        }
        std::cout << std::endl;
        return v.size();
    }
    int printtree  (const TreeNode * head)
    {
        if (head==nullptr)
        {
            std::cout << "null tree. " << std::endl;
            return 0;
        }
        std::cout << "head->val: " << head->val << std::endl;
        std::cout << "[ preorder]  : " ; 
        printtreenodepre(head);
        std::cout << std::endl;
        std::cout << "[  inorder]  : " ; 
        printtreenodein(head);
        std::cout << std::endl;
        std::cout << "[postorder]  : " ; 
        printtreenodepost(head);
        std::cout << std::endl;
        return 0;
    }
    int printtreenodepre (const TreeNode * head)
    {
        if(head==nullptr)
        {
            std::cout << "N" << ",";
        }
        else
        {
            std::cout << head->val << ",";
            printtreenodepre(head->left);
            printtreenodepre(head->right);
        }
        return 0;
    }
    int printtreenodein (const TreeNode * head)
    {
        if(head==nullptr)
        {
            std::cout << "N" << ",";
        }
        else
        {
            printtreenodein(head->left);
            std::cout << head->val << ",";
            printtreenodein(head->right);
        }
        return 0;
    }
    int printtreenodepost (const TreeNode * head)
    {
        if(head==nullptr)
        {
            std::cout << "N" << ",";
        }
        else
        {
            printtreenodepost(head->left);
            printtreenodepost(head->right);
            std::cout << head->val << ",";
        }
        return 0;
    }
    bool isSame(TreeNode *T1, TreeNode *T2)
    {
        if(T1 == nullptr ^ T2 == nullptr)
        {
            // T1 ==nullptr && T2 != nullptr
            // T1 !=nullptr && T2 == nullptr
            return false;
        }
        else
        {
            if (T1 == nullptr && T2==nullptr)
            {
                return true;
            }
        }
        if(T1->val==T2->val)
        {
            return isSame(T1->left,T2->left) && isSame(T1->right,T2->right);
        }
        else
        {
            return false;
        }
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        TreeNode *root,
        std::string preorder , std::string inorder, std::string postorder, std::string levorder)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Codec ser;
    Codec deser;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "root:" << std::endl;
    ser.printtree(root);
    // getpermutataion
const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
    if (TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::string seri = ser.serialize0(root);
        std::cout << "root serial0:" << seri << std::endl;

        std::string seri01 = ser.serialize01(root);
        std::cout << "root serial01:" << seri01 << std::endl;
        TreeNode * result = deser.deserialize0(levorder);

        std::cout << "levorder to Tree result:" << std::endl;
        ser.printtree(result);

        if( seri == levorder && deser.isSame(result , root) == true)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_1)
    {
        std::cout << ">>>> TEST1 preorder serial:"  << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "root pre serial1:" << preorder << std::endl;

        std::string seri = ser.serialize1(root);
        std::cout << "root get serial1:" << seri << std::endl;

        TreeNode * result = deser.deserialize1(preorder );

        std::cout << "preorder  to Tree result:" << std::endl;
        ser.printtree(result);

        if( seri == preorder  && deser.isSame(result , root) == true)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_2)
    {
        std::cout << ">>>> TEST2 postorder serial:"  << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "root post serial2:" << postorder << std::endl;

        std::string seri = ser.serialize2(root);
        std::cout << "root  get serial2:" << seri << std::endl;

        TreeNode * result = deser.deserialize2(postorder );

        std::cout << "postorder  to Tree result:" << std::endl;
        ser.printtree(result);

        if( seri == postorder  && deser.isSame(result , root) == true)
            std::cout << "Solution2 passed." << std::endl;
        else
            std::cout << "Solution2 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}

void Test1()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);

    node3->left = node4;
    node3->right = node5;

    node1->left = node2;
    node1->right = node3;
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "        4   5   " << std::endl;
    ////////////////////////////////////
    //preorder: 1,2,N,N,3,4,N,N,5,N,N,
    //inorder : N,2,N,1,N,4,N,3,N,5,N,

    std::string preorder = "1,2,null,null,3,4,null,null,5,null,null";
    std::string inorder  = "null,2,null,1,null,4,null,3,null,5,null";
    std::string postorder= "null,null,2,null,null,4,null,null,5,3,1";
    std::string levorder = "1,2,3,null,null,4,5";
    Test("Test1", node1, preorder, inorder, postorder, levorder);
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    std::string preorder  = "null";
    std::string inorder   = "null";
    std::string levorder  = "null";
    std::string postorder = "null";
    Test("Test2", nullptr, preorder , inorder, postorder, levorder);
    std::cout << "----------------" << std::endl;
}
void Test3()
{
    TreeNode *p_node1 = new TreeNode(1);
    // preorder: 1,N,N,
    //inorder : N,1,N,

    std::string seridata = "1,null,null";
    std::string preorder = "1,null,null";
    std::string inorder  = "null,1,null";
    std::string postorder= "null,null,1";
    std::string levorder = "1";
    Test("Test3", p_node1, preorder  , inorder, postorder, levorder);
    std::cout << "----------------" << std::endl;
}
void Test4()
{
    TreeNode *p_node2 = new TreeNode(2);
    TreeNode *p_node1 = new TreeNode(1, p_node2, nullptr);
    std::string seridata = "1,2";
    std::string preorder = "1,2,null,null,null";
    std::string inorder  = "2,1";
    std::string levorder = "1,2";
    std::string postorder= "null,null,2,null,1";
    Test("Test4", p_node1, preorder , inorder, postorder, levorder);
    std::cout << "----------------" << std::endl;
}
void Test5()
{
    TreeNode * p_node0 = new TreeNode(0);
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node1);
    TreeNode * p_node3 = new TreeNode(3, nullptr, p_node2);
    TreeNode * p_node5 = new TreeNode(5, p_node0, nullptr);
    TreeNode * p_node6 = new TreeNode(6, p_node3, p_node5);
    
    std::cout << "      6         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   3     5      " << std::endl;
    std::cout << "    \\   /      " << std::endl;
    std::cout << "     2  0       " << std::endl;
    std::cout << "      \\        " << std::endl;
    std::cout << "        1       " << std::endl;
    ////////////////////////////////////
    //preorder: 6,3,N,2,N,1,N,N,5,0,N,N,N,
    // inorder : N,3,N,2,N,1,N,6,N,0,N,5,N,

    std::string preorder = "6,3,null,2,null,1,null,null,5,0,null,null,null";
    std::string inorder  = "null,3,null,2,null,1,null,6,null,0,null,5,null";
    std::string levorder = "6,3,5,null,2,0,null,null,1";
    std::string postorder= "null,null,null,null,1,2,3,null,null,0,null,5,6";
    Test("Test5", p_node6, preorder, inorder, postorder, levorder);
    std::cout << "----------------" << std::endl;
}
// @20200426
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//
// @20201201
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
