给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int m = a.size()-1;
        int n = b.size()-1;
        string res = "";
        if(m>n){
            for(int i=0; i<m-n; i++){
                b = '0' + b;
            }
        }
        if(m<n){
            for(int i=0; i<n-m; i++){
                a = '0' + a;
            }
        }//补位
        
        int s = m>n ? m:n;
        while(s>=0){
            int temp = (a[s]-'0')+(b[s]-'0')+carry;
            carry = temp/2;
            temp %= 2;
            char dig = temp+'0';
            res = dig + res;
            s--;
        } //从后往前加和进位
        if(carry>0) //处理最前一位
            res = '1'+res;
        
        return res;
    }
};