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






