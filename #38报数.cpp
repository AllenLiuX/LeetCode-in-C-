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

