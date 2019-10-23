class Solution {
public:
    string convertToTitle(int n) {
        string res;   
        while(n != 0){  //比n/26！=0更加smart
            n--;    //处理n为26的情况
        	int temp = n % 26;
        	res.insert(res.begin(), 'A'+temp);
        	n = n/26;
        }
        return res;
    }
};