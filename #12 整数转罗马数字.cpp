class Solution {
public:
    string intToRoman(int num) {
        // int digit[4]=0;
        // while(int i=0; i<4; i++){
        //     digit[i]=num%10;
        //     num /= 10;
        // }
        // string str[4];
        // switch digit[0]{
        //     case 1
        // }
        
        string result = "";
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int i=0;
        while(num!=0){
            if(num>=value[i]){
                result+=symbol[i];
                num-=value[i];
            }
            else
                i++;
        }
              
        // for(int i=0; num!=0; i++){
        //     while(num>=value[i]){
        //         result += symbol[i];
        //         num -= value[i];
        //     }
        // }
        return result;
        
    }
};