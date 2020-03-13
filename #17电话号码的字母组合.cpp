给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

---

class Solution {
public:
    vector<string> helper(string digits, vector<string> ori){
        if(digits=="")
            return ori;
        string base[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res = {};
        string temp = base[digits[0]-'2'];  //corresponding characters for this digit
        if(ori.size()==0)   //include a "" for loop to push back new strings
            ori.push_back("");
        for(string a : ori){
            for(char b : temp){
                res.push_back(a+b);
            }
        }
        return helper(digits.substr(1), res);
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res = {};
        return helper(digits, res);
    }
};