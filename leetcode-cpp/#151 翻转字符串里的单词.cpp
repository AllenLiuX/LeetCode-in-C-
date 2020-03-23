Tags: 字符串, 双指针, 中等
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

进阶：

请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());                        //整体反转
    int start = 0, end = s.size() - 1;
    while (start < s.size() && s[start] == ' ') start++;//首空格
    while (end >= 0 && s[end] == ' ') end--;            //尾空格
    if (start > end) return "";                         //特殊情况

    for (int r = start; r <= end;) {                    //逐单词反转
        while (s[r] == ' '&& r <= end) 
            r++;
        int l = r;
        while (s[l] != ' '&&l <= end) 
            l++;
        reverse(s.begin() + r, s.begin() + l);
        r = l;
    }

    int tail = start;                                   //处理中间冗余空格
    for (int i = start; i <= end; i++) {
        if (s[i] == ' '&&s[i - 1] == ' ') //一直找到当前不是空格的i
            continue;
        s[tail++] = s[i];
    }
    return s.substr(start, tail - start);

    }
};