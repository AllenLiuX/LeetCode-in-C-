//超时递归：
class Solution {
public:
    string str;
    vector<string> dic;
    bool wordBreak(string s, vector<string>& wordDict) {
        str = s;
        dic = wordDict;
        return helper(0);
    }
    
    bool helper(int p){
        if(p>=str.size())
            return true;
        for(int i=0; i<dic.size(); i++){
            if(dic[i] == str.substr(p, dic[i].size())){
                if(helper(p+dic[i].size()))
                    return true;
            }
        }
        return false;
    }
};

//动态规划
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i){
        for (int j = 0; j < i; ++j){
            if (dp[j] && m.find(s.substr(j, i-j)) != m.end()){  //只要这个i到上一个true的i之间能匹配上，那这个i也为true
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

//改良过的动态规划：
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    dp[0] = true;
    //获取最长字符串长度
    int maxWordLength = 0;
    for (int i = 0; i < wordDict.size(); ++i){
        maxWordLength = std::max(maxWordLength, (int)wordDict[i].size());
    }   //每次并不需要从s[0]开始搜索。因为wordDict中的字符串长度是有限的。只需要从i-maxWordLength开始搜索就可以了。
    for (int i = 1; i <= s.size(); ++i){
        for (int j = std::max(i-maxWordLength, 0); j < i; ++j){
            if (dp[j] && m.find(s.substr(j, i-j)) != m.end()){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

//字典树+记忆化搜索？？？
class Solution {
public:
    struct TrieNode {
        bool flag;
        map<char, TrieNode*> next;
        TrieNode() : flag(false) {}
    };
    
    TrieNode* root;
    vector<int> memo;
    
        bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size(), 0);
        root = new TrieNode();
        auto node = root;
        for (auto w : wordDict) {
            node = root;
            for (auto c : w) {
                if (node->next.count(c) == 0)
                    node->next[c] = new TrieNode();
                node = node->next[c];
            }
            node->flag = true;
        }
        return func(s, 0, s.size());
    }
    
    bool func(string& s, int start, int end) {
        if (start == end)
            return true;
        if (memo[start] != 0)
            return memo[start] > 0;
        auto node = root;
        for (int i = start; i < end; ++i) {
            if (node->next.count(s[i]) == 0)
                break;
            node = node->next[s[i]];
            if (node->flag && func(s, i + 1, end)) {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = -1;
        return false;
    }
};
