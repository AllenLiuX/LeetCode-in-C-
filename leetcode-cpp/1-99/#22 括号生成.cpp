给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

---

class Solution {
public:
    void helper(int left, int right, string temp, vector<string>& res){
        if(left==0 && right==0){
            res.push_back(temp);
            return;
        }
        
        else if(left>right || left<0 || right <0)
            return;
        
        helper(left-1, right, temp+'(', res);
        helper(left, right-1, temp+')', res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res = {};
        if(n==0)
            return res;
        helper(n, n, "", res);
        return res;
            
    }
};