class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string out="";
        // bool match=true;
        // if(strs.size()==0)
        //     return "";
        // for(int i=0; match; i++){
        //     char k=strs[0][i];
        //     for(string a : strs){
        //         if(a[i]!=k){
        //             match=false;
        //             break;
        //         }
        //     }
        //     if(!match)
        //         break;
        //     out+=k; 
        // }
        // return out;
        
        if (strs.size() == 0) 
            return "";
        string prefix = strs[0];    //先取第一个作为标准，之后跟每一个比较，只要末尾字母不相同就直接删掉
        for (int i = 1; i < strs.size(); i++){
            while (strs[i].substr(0,prefix.size()) != prefix) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix=="") 
                    return "";
            }
       }        
    return prefix;

    }
};