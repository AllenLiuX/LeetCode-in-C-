class Solution {
public:
    string getPermutation(int n, int k) {
    string res;
    vector<int> str;
    for(int i=1;i<=n;++i){
        str.push_back(i);
    }
    
    dfs(res,str,n,k);
    
    return res;   
}
    
    int fact(int a){
        int b=1;
        while(a>1){
            b *= a;
            a--;
        }
        return b;
    }

    void dfs(string& res, vector<int>& str,int n,int k){
    if(str.empty()) return;
    int step=fact(n-1),count=0,s=step;
    while(k>s){
        s+=step;
        ++count;
    }
 
    res+=to_string(str[count]);
    str.erase(str.begin()+count);   //erase方法important！
    dfs(res,str,n-1,k-count*step);
    
    
}

    
};