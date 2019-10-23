class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
    for(auto s : strs){
        string temp = s;
        sort(temp.begin(), temp.end());
        hash[temp].push_back(s);
    }
    int n = hash.size();
    vector<vector<string>> res(n);
    int i=0;
    for(auto v : hash){
        res[i] = v.second;
        i++;
    }
    return res;
    }
};