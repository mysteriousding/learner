/*
//BM17 二分查找-I
//
//描述
//请实现无重复数字的升序数组的二分查找
//
//给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1
//
//数据范围：0≤len(nums)≤2×10^5 ， 数组中任意值满足 ∣val∣≤10^9
//
//进阶：时间复杂度 O(logn) ，空间复杂度 O(1)
//
//示例1
//输入：
//[-1,0,3,4,6,10,13,14],13
//
//返回值：
//6
//
//说明：
//13 出现在nums中并且下标为 6
//
//
//示例2
//输入：
//[],3
//
//返回值：
//-1
//
//说明：
//nums为空，返回-1
//
//
//示例3
//输入：
//[-1,0,3,4,6,10,13,14],2
//
//返回值：
//-1
//
//说明：
//2 不存在nums中因此返回 -1
//
//
//备注：
//数组元素长度在[0,10000]之间
//数组每个元素都在 [-9999, 9999]之间。

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     *
int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1, k;
    while (i <= j)
    {
        k = i + (j - i) / 2;
        if (nums[k] == target)
            return k;
        else if (nums[k] > target)
            j = k - 1;
        else
            i = k + 1;
    }
    return -1;
}
};
*/

/*
//BM18 二维数组中的查找
//
//描述
//在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//[
//[1,2,8,9],
//[2,4,9,12],
//[4,7,10,13],
//[6,8,11,15]
//]
//给定 target = 7，返回 true。
//
//给定 target = 3，返回 false。
//
//数据范围：矩阵的长宽满足 0≤n,m≤500 ， 矩阵中的值满足 0≤val≤10^9
//
//进阶：空间复杂度 O(1) ，时间复杂度 O(n+m)
//
//示例1
//输入：
//7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
//
//返回值：
//true
//
//说明：
//存在7，返回true
//
//
//示例2
//输入：
//1,[[2]]
//
//返回值：
//false
//
//
//示例3
//输入：
//3,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
//
//返回值：
//false
//
//说明：
//不存在3，返回false


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param target int整型
     * @param array int整型vector<vector<>>
     * @return bool布尔型
     *
bool Find(int target, vector<vector<int> >& array) {
    if (!array.size() || !array[0].size())return false;
    int n = array.size() - 1, m = array[0].size(), i = 0;
    while (n >= 0 && i < m)
        if (array[n][i] == target)
            return true;
        else if (array[n][i] > target)
            n--;
        else i++;
    return false;
}
};
*/