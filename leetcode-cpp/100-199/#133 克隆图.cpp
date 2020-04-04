Tags: map, 中等
给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。

示例：



输入：
{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}

解释：
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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