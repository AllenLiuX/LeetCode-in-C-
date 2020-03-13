Tags: 运算, 中等, 数据类型
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(denominator==0)
            return res;
        long long a = numerator, b = denominator;
        if((a>0 && b<0) || (a<0 && b>0))
            res += '-';
        a = abs(a);
        b = abs(b);
        res += to_string(a/b); //这时的a和b都还是整数。如果用int的话INT_MIN/-1不能被表示。
        a = a % b;  //a是余数
        if(a)
            res += '.';
        unordered_map<long long, int> map;
        int index = 0;
        while(a && map.find(a) == map.end()){
            map[a] = index++;
            a *= 10;
            res+=to_string(a/b);
            a %= b;
        }

        if(map.find(a) != map.end()){
            res += "()";
            int cur = res.size()-2;
            while(index > map[a]){
                swap(res[cur], res[cur-1]);
                cur--;
                index--;
            }
        }
        return res;
    }
};