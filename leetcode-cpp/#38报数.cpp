报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"

---

class Solution {
public:
    string helper(string ori, int& count, int tar){
        int p = 0;
        string res;
        count++;
        if(count == tar)
            return ori;
        for(int i=0; i<ori.size(); i++){
            if(ori[i]==ori[p])
                continue;
            res += '0'+i-p;
            res += ori[p];
            p = i;
        }
        res += '0'+ori.size()-p;
        res += ori[p];
        return helper(res, count, tar);
        
    }
    
    string countAndSay(int n) {
        int count = 0;
        return helper("1", count, n);
    }
};

/***
1. 1
2. 11
3. 21
4. 1211
5. 111221
6. 312211
7. 13112221
8. 1113213211
9. 31131211131221

***/

