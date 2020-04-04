Tags: 链表, 构造, map, 有丝分裂
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。 

 

示例：



输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 

提示：

你必须返回给定头的拷贝作为对克隆列表的引用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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