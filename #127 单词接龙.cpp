给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
    if (wordDict.find(endWord) == wordDict.end()){
        return 0;//Not FOUND 404
    }
    unordered_set<string> beginSet{beginWord};
    unordered_set<string> endSet{endWord};
    int step = 1;
    while (!beginSet.empty()){
        unordered_set<string> tempSet;
        ++step;
        for (auto s : beginSet) {
            wordDict.erase(s);
        }
        for (auto s : beginSet) {
            for (int i = 0; i < s.size(); ++i){
                string str = s;
                for (char c = 'a'; c <= 'z'; ++c){
                    str[i] = c;
                    if (wordDict.find(str) == wordDict.end()){
                        continue;
                    }
                    if (endSet.find(str) != endSet.end()){
                        return step;
                    }
                    tempSet.insert(str);
                }
            }
        }
        if (tempSet.size() < endSet.size()){
            beginSet = tempSet;
        } else {
            beginSet = endSet;
            endSet = tempSet;
        }
    }
    return 0;
    }
};