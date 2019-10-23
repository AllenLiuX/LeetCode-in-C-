/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    map<Node*,Node*> mp;    //原node指着克隆的node
    Node* cloneGraph(Node* node) {
        if(!node)   
            return nullptr;
        if(mp.count(node))  
            return mp[node];
        Node* c = new Node(node -> val);    //新建一个一模一样的
        mp[node] = c;   //指着自己的克隆体
        for(int i = 0; i < node -> neighbors.size(); ++ i){
            if(node -> neighbors[i])
                c->neighbors.push_back(cloneGraph(node->neighbors[i]));
            //转了一圈，到最后一个的时候左和右邻居都在map里了，就可以push and return了
        }
        return c;   //return这个克隆的新node
    }

};