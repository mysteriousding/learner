/*
//BM1 反转链表
//
//描述
//给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。
//
//数据范围：0≤n≤1000
//要求：空间复杂度 O(1) ，时间复杂度 O(n) 。
//
//如当输入链表{1,2,3}时，
//经反转后，原链表变为{3,2,1}，所以对应的输出为{3,2,1}。
//以上转换过程如下图所示：
//
//https://uploadfiles.nowcoder.com/images/20211014/423483716_1634206291971/4A47A0DB6E60853DEDFCFDF08A5CA249
//
//示例1
//输入：
//{1,2,3}
//
//返回值：
//{3,2,1}
//
//
//示例2
//输入：
//{}
//
//返回值：
//{}
//
//说明：
//空链表则输出空

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 *
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     *
    ListNode* ReverseList(ListNode* head) {
        ListNode* new_head = NULL, * p;
        while (head)
        {
            p = head;
            head = head->next;
            p->next = new_head;
            new_head = p;
        }
        return new_head;
    }
};
*/

/*
BM2 链表内指定区间反转

描述
将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度 (n)，空间复杂度 O(1)。
例如：
给出的链表为
1→2→3→4→5→NULL,m=2,n=4,
返回 1→4→3→2→5→NULL.

数据范围： 链表长度 0<size≤1000，0<m≤n≤size，链表中每个节点的值满足∣val∣≤1000
要求：时间复杂度 O(n) ，空间复杂度 O(n)
进阶：时间复杂度 O(n)，空间复杂度 O(1)
示例1
输入：
{1,2,3,4,5},2,4

返回值：
{1,4,3,2,5}


示例2
输入：
{5},1,1

返回值：
{5}

/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 *
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     *
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n)return head;
        ListNode* list = NULL, * p, * q, * d = head;
        int i;
        if (m == 1)
        {
            q = head;
            i = 0;
        }
        else
        {
            for (i = 2; i < m; i++)
                d = d->next;
            list = d->next;
            q = list->next;
        }
        for (; i < n; i++) {
            p = q;
            q = q->next;
            p->next = list;
            list = p;
        }
        if (m != 1)d->next = list;
        else head = list;
        for (i = m; i < n; i++)
            list = list->next;
        list->next = q;

        return head;
    }
};
*/
