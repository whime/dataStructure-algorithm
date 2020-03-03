// 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //递归归并排序，
//class Solution {
//public:
//    ListNode* sortList(ListNode* head) {
//        return mergeSort(head);
//    }
//
//    ListNode* mergeSort(ListNode* head)
//    {
//        if(head==NULL||head->next==NULL)    return head;
//        //快慢指针找中点
//        ListNode *slowp=head,*fastp=head,*pre=head;
//        while(fastp&&fastp->next)
//        {
//            pre=slowp;
//            slowp=slowp->next;
//            fastp=fastp->next->next;
//        }
//        //左右分别归并排序
//        ListNode *r,*l;
//        r=mergeSort(slowp);
//        pre->next=NULL;
//        l=mergeSort(head);
//        return merge(l,r);
//    }
//
//    ListNode* merge(ListNode* l,ListNode* r)
//    {
//        ListNode* tmpHead=new ListNode(0);
//        ListNode* p=tmpHead;
//        while(l&&r)
//        {
//            if(l->val<=r->val)
//            {
//                p->next=l;
//                l=l->next;
//            }
//            else
//            {
//                p->next=r;
//                r=r->next;
//            }
//            p=p->next;
//        }
//        p->next=(l==NULL)?r:l;
//        return tmpHead->next;
//
//    }
//};


//迭代方法,bottom-to-up
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)    return head;
        ListNode *left,*cur,*right;
        cur=head;
        // 计算链表长度
        int len=1;
        while(cur->next)
        {
            cur=cur->next;
            len++;
        }
        // 自底向上，迭代归并
        ListNode *dummyHead=new ListNode(-1);//傀儡结点
        dummyHead->next=head;
        ListNode *joinp=dummyHead;//用于连接各个分割后的链表
        for(int size=1;size<len;size<<=1)
        {
            cur=dummyHead->next;
            joinp=dummyHead;
            while(cur)
            {
                left=cur;
                right=splitByStep(left,size);
                //将当前指针cur移动到未切割的链表头
                cur=splitByStep(right,size);
                joinp->next=merge(left,right);

                //joinp移动到链表尾部
                while(joinp->next!=NULL)
                {
                    joinp=joinp->next;
                }
            }
        }
        return dummyHead->next;
    }

    ListNode* splitByStep(ListNode* head,int step)
    {
        if(head==NULL)  return NULL;
        // 从head开始截取两段step长度的链表
        for(int i=1;i<step&&head->next!=NULL;i++)
        {
            head=head->next;
        }
        ListNode* right=head->next;
        head->next=NULL;
        return right;// 返回第二段的段头
    }

    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode* dummyHead=new ListNode(0);
        ListNode* p=dummyHead;
        while(left&&right)
        {
            if(left->val<right->val)
            {
                p->next=left;
                left=left->next;
            }
            else
            {
                p->next=right;
                right=right->next;
            }
            p=p->next;
        }
        p->next=(left==NULL)?right:left;
        return dummyHead->next;
    }
};