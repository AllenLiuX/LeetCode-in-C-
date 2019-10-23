/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //双指针！
        if(head == nullptr || head->next ==nullptr)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        for(int i=0; i<k; i++){ //一次循环搞定！
            p2 = p2->next;
            if(p2==nullptr){
                p2=p1;
                if(k>2*(i+1))   //i+1是第一次到达时的循环周期
                    k=k%(i+1) + i+1;    //只需要剩下的模加上第一次的i+1即可求出旋转点。
            }
        }
        while(p2->next!=nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }   //这个时候p1是new tail，p1->next则是new head，p2为old tail，齐活。
        p2->next = head;
        head = p1->next;
        p1->next = nullptr;
        return head;
        
    }
};