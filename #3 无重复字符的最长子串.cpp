class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    // int freq[256] = {0};
    //     int l = 0, r = -1; //滑动窗口为s[l...r]
    //     int res = 0;
    //     // 整个循环从 l == 0; r == -1 这个空窗口开始
    //     // 到l == s.size(); r == s.size()-1 这个空窗口截止
    //     // 在每次循环里逐渐改变窗口, 维护freq, 并记录当前窗口中是否找到了一个新的最优值
    //     while(l < s.size()){
    //         if(r + 1 < s.size() && freq[s[r+1]] == 0){
    //             r++;
    //             freq[s[r]]++;
    //         }else {   //r已经到头 || freq[s[r+1]] == 1
    //             freq[s[l]]--;
    //             l++;
    //         }
    //         res = max(res, r-l+1);
    //     }
    //     return res;
    //
//      滑动窗口法，i左边界，j右边界


        int  size,i=0,j,k,max=0;
        size = s.size();
        for(j = 0;j<size;j++){
            for(k = i;k<j;k++)//检查i到j之间有没有重复的
                if(s[k]==s[j]){
                    i = k+1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
};