class Solution {
public:
    static bool compare(int n1, int n2){
        if(!n1)
            return false;
        if(!n2)
            return true;    //防止overbufferflow！but why？？？
        string a = to_string(n1);
        string b = to_string(n2);
        // int size = a.size()>b.size() ? a.size() : b.size();
        // for(int i=0; i<size; i++){
        //     if(a[i%a.size()]>b[i%b.size()])
        //         return true;
        //     else if(a[i%a.size()]<b[i%b.size()])
        //         return false;
        // }
        return a+b > b+a ? true : false;    //简单的规则！直意表达！
        // return true;
    }

    string largestNumber(vector<int>& nums) {
        if(nums.size()<2)
            return to_string(nums[0]);  //只有1位时无法compare
        sort(nums.begin(), nums.end(), &compare);
        string res;
        bool allZero = true;
        for(int i : nums){
            res += to_string(i);
            if(i>0)
                allZero = false;
        }
        return allZero ? "0" : res; //注意是“0”，不是0！
    }
};