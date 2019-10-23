class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1=0, l2=0;
        int a=0, b=0;
        int v1 = version1.size(), v2 = version2.size();
    while(l1<v1 || l2<v2){
        // int r1=l1, r2=l2;
        while(l1<v1 && version1[l1]!='.'){  //位置条件一定要放在access之前！！
            a = a*10 + version1[l1]-'0';
            l1++;
        }
        while(l2<v2 && version2[l2]!='.'){
            b = b*10 + version2[l2]-'0';
            l2++;
        }
        if(a<b)
            return -1;
        if(a>b)
            return 1;
        l1++;
        l2++;
        a=0;
        b=0;
    }
    return 0;
    }
};