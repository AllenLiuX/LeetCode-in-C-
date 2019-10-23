class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int K = 10;
        map<string, int> m;
        vector<string> res;
        if (s.size() < K + 1)
            return res;
        for (int i = 0; i <= s.size() - K; ++i) {
            ++m[s.substr(i, K)];
        }
        for (auto kv : m) {
            if (kv.second > 1) {
                res.push_back(kv.first);
            }
        }
        return res;

    }
};