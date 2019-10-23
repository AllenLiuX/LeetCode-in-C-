/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
// 有丝分裂法，原地复制再分裂，时间O(3n)，空间O(1)，36ms，99%
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* ite = head;
        while (ite) { // 用next连接
            Node* n = new Node(ite->val, ite->next, nullptr);
            Node* c = ite->next;
            ite->next = n;  //原node的next改为克隆的node
            ite = c;
        }   //先把整个链表new出来
        ite = head;
        while (ite) { // 连接random
            if (ite->random) ite->next->random = ite->random->next; //ite->next是对应的克隆node，random->next是random对应的克隆node
            ite = ite->next->next;  //ite的克隆node的next就是原本的下一个
        }
        ite = head;
        Node* ret = head->next;
        while (ite->next) { // 有丝分裂
            Node* c = ite->next;    //原来的和克隆的每一个node都要改，把两条链表分裂开来
            ite->next = ite->next->next;
            ite = c;
        }
        return ret;
    }
}; 