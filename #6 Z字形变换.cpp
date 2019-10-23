class Solution {
public:
    int min(int a, int b){
        return a>b ? a : b;
    }
    
    string convert(string s, int numRows) {
        // if(numRows==1)
        //     return s;
        vector<string> rows(min(numRows, s.size()));
        bool down=true;
        int row=0;
        string result="";
        for(char c : s){
            rows[row] += c;
            row += down ? 1 : -1;
            if(row==numRows-1 || row==0)
                down=!down;
        }
        for (string m : rows){
            result+=m;
        }
        return result;
    }
};