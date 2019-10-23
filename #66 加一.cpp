class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int tag = 0;    //tag记录当前位加1后的结果
        while(i >= 0)   //判断数组是否遍历完成
        {
            tag = digits[i] + 1;
            digits[i--] = tag % 10;
            if(tag < 10)break;  //如果当前位加1后不需要进位，则停止遍历
        }
        //如果原数组首位加1结果大于10，需要进位
        if(i < 0 && tag >= 10)
            digits.insert(digits.begin(),1);  
        return digits;

//这个should work too！        
        // int s = digits.size()-1;
        // while(digits[s]==9)
        //     s--;
        // if(s==-1){
        //     digits.insert(digits.begin(),0);
        //     s=0;
        // }
        // digits[s]++;
        // s++;
        // while(s<digits.size()){
        //     digits[s]=0;
        //     s++;
        // }
        // return digits;
    }
};