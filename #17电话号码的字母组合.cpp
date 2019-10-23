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