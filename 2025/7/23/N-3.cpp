/*
//BM23 二叉树的前序遍历
//
//描述
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//
//数据范围：二叉树的节点数量满足 1≤n≤100  ，二叉树节点的值满足 1≤val≤100  ，树的各节点的值各不相同
//示例 1：
//
//https://uploadfiles.nowcoder.com/images/20211111/392807_1636599059575/FE67E09E9BA5661A7AB9DF9638FB1FAC
//
//示例1
//输入：
//{1,#,2,3}
//
//返回值：
//[1,2,3]

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 *
vector<int>a(105);
int k = 0;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     *
    vector<int> preorderTraversal(TreeNode* root) {
        lb(root);
        a.resize(k);
        return a;
    }
    void lb(TreeNode* root)
    {
        if (!root)return;
        a[k++] = root->val;
        lb(root->left);
        lb(root->right);
    }
};
*/

/*
//BM24 二叉树的中序遍历
//
//描述
//给定一个二叉树的根节点root，返回它的中序遍历结果。
//
//数据范围：树上节点数满足 0≤n≤1000，树上每个节点的值满足 −1000≤val≤1000
//进阶：空间复杂度 O(n)，时间复杂度 O(n)
//示例1
//输入：
//{1,2,#,#,3}
//
//返回值：
//[2,3,1]
//
//说明：
//https://uploadfiles.nowcoder.com/images/20210330/1_1617077399487/DB3124E4AB48ACA166EAC6A59F5ADCE9
//
//
//示例2
//输入：
//{}
//
//返回值：
//[]
//
//
//示例3
//输入：
//{1,2}
//
//返回值：
//[2,1]
//
//说明：
//https://uploadfiles.nowcoder.com/images/20210330/1_1617077828797/348BF14EF65EB6D94D5EAD8895712DF1
//
//
//示例4
//输入：
//{1,#,2}
//
//返回值：
//[1,2]
//
//说明：
//https://uploadfiles.nowcoder.com/images/20210330/1_1617077855982/FF7B3016FB0274E8D3CBD7C082DBFFC9
//
//
//备注：
//树中节点数目在范围 [0, 100] 内
//树中的节点的值在[-100,100]以内

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 *
vector<int>a(1005);
int k = 0;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     *
    vector<int> inorderTraversal(TreeNode* root) {
        lb(root);
        a.resize(k);
        return a;
    }
    void lb(TreeNode* root)
    {
        if (!root)return;
        lb(root->left);
        a[k++] = root->val;
        lb(root->right);
    }
};
*/

/*
//BM25 二叉树的后序遍历
//
//广度优先搜索(BFS)
//描述
//给定一个二叉树，返回他的后序遍历的序列。
//
//后序遍历是值按照 左节点->右节点->根节点 的顺序的遍历。
//
//数据范围：二叉树的节点数量满足 1≤n≤100  ，二叉树节点的值满足 1≤val≤100  ，树的各节点的值各不相同
//
//样例图
//
//https://uploadfiles.nowcoder.com/images/20211111/392807_1636596692486/64547759EAC75079FDBF501CAA589890
//
//示例1
//输入：
//{1,#,2,3}
//
//返回值：
//[3,2,1]
//
//说明：
//如题面图
//
//
//示例2
//输入：
//{1}
//
//返回值：
//[1]

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 *
vector<int>a(105);
int k = 0;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     *
    vector<int> postorderTraversal(TreeNode* root) {
        lb(root);
        a.resize(k);
        return a;
    }
    void lb(TreeNode* root)
    {
        if (!root)return;
        lb(root->left);
        lb(root->right);
        a[k++] = root->val;
    }
};
*/
