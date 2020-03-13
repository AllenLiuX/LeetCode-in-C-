Tags: 二叉树, 递归, 普通
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

示例：



输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) 
            return NULL;
        Node *next = root->next;
        while (next) {
            if (next->left) {
                next = next->left;
                break;
            } else if (next->right) {
                next = next->right;
                break;
            } else next = next->next;
        }   //找到root-->right的next应该指的node
        //看left和right分三种情况讨论
        if (root->left && root->right) {
            root->left->next = root->right;
            root->right->next = next;
        } 
        else if (!root->left && root->right) 
            root->right->next = next;
        else if (root->left && !root->right) 
            root->left->next = next;
        connect(root->right);
        connect(root->left);
        return root;
    }
};


//more readible and faster：
class Solution {
public:
    Node* connect(Node* root) {
        con(root);
        return root;
    }
    void con(Node* r) {
        if (!r) return;
        if (r->left && r->right)
            r->left->next = r->right;
        Node* p = (r->right ? r->right : r->left);
        Node* p2 = r->next;
        while (p && p2) {
            if (p2->left) {
                p->next = p2->left; break;
            }
            else if (p2->right) {
                p->next = p2->right; break;
            }
            else p2 = p2->next;
        }
        con(r->right);
        con(r->left);
    }
};






