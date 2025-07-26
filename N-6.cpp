/*
//BM55 没有重复项数字的全排列
//
//描述
//给出一组数字，返回该组数字的所有排列
//例如：
//[1,2,3]的所有排列如下
//[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], [3,2,1].
//（以数字在数组中的位置靠前为优先级，按字典序排列输出。）
//
//数据范围：数字个数 0<n≤6
//要求：空间复杂度 O(n!) ，时间复杂度 O(n!）
//示例1
//输入：
//[1,2,3]
//
//返回值：
//[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
//示例2
//输入：
//[1]
//
//返回值：
//[[1]]

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型vector
     * @return int整型vector<vector<>>
     *
void dg(vector<int>& a, int k)
{
    int h;
    if (k == a.size())
        t.push_back(a);
    else for (int i = k; i < a.size(); i++)
    {
        h = a[i], a[i] = a[k], a[k] = h;
        dg(a, k + 1);
        h = a[i], a[i] = a[k], a[k] = h;
    }

}
vector<vector<int> > permute(vector<int>& num) {
    if (num.size())
        dg(num, 0);
    return t;
}

private:
    vector<vector<int>>t;
};
*/

/*
//BM56 有重复项数字的全排列
//
//描述
//给出一组可能包含重复项的数字，返回该组数字的所有排列。结果以字典序升序排列。
//
//数据范围：0<n≤8 ，数组中的值满足 −1≤val≤5
//要求：空间复杂度 O(n!)，时间复杂度 O(n!)
//示例1
//输入：
//[1,1,2]
//
//返回值：
//[[1,1,2],[1,2,1],[2,1,1]]
//
//
//示例2
//输入：
//[0,1]
//
//返回值：
//[[0,1],[1,0]]

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型vector
     * @return int整型vector<vector<>>
     *
void dg(vector<int>& a, int k) {
    int h;
    if (k == a.size())
        st.insert(a);
    else for (int i = k; i < a.size(); i++) {
        h = a[i], a[i] = a[k], a[k] = h;
        dg(a, k + 1);
        h = a[i], a[i] = a[k], a[k] = h;
    }

}
vector<vector<int> > permuteUnique(vector<int>& num) {
    if (num.size())
        dg(num, 0);
    set<vector<int>>::iterator it;
    vector<vector<int>>t;
    for (it = st.begin(); it != st.end(); it++)
        t.push_back(*it);
    return t;
}
  private:
      set<vector<int>> st;
};
*/