class Solution {
public:
    vector<vector<string>> res;
    string str;
    vector<vector<string>> partition(string s) {
        str = s;
        vector<string> pre;
        dfs(0, pre);
        return res;
    }

    void dfs(int pos, vector<string> pre){
        if(pos>=str.size())
            res.push_back(pre);
        for(int i=1; i<=str.size()-pos; i++){
            if(isp(str.substr(pos, i))){
                pre.push_back(str.substr(pos, i));
                dfs(pos+i, pre);
                pre.pop_back(); //记得pop
            }
        }
    }


    bool isp(string s){
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};