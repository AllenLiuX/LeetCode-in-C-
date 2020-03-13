nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
---

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=0, n2=0, t;
        double temp1=0, temp2=0;
        bool odd;
        int size = nums1.size()+nums2.size();
        if(size%2==1){
            odd=true;
        }
        else{
            odd=false;
        }
        t=size/2+1;
        while(true){
            if(n1>=nums1.size()){
                temp2=temp1;
                temp1=nums2[n2];
                n2++;
            }
            else if(n2>=nums2.size()){
                temp2=temp1;
                temp1=nums1[n1];
                n1++;
            }
                
            else if(nums2[n2]>=nums1[n1]){
                temp2=temp1;
                temp1=nums1[n1];
                n1++;
            }
            else if(nums2[n2]<nums1[n1]){
                temp2=temp1;
                temp1=nums2[n2];
                n2++;
            }
            if(odd && n1+n2>=t){
                return temp1;
            }
            if(!odd && n1+n2>=t){
                return (temp1+temp2)/2;
            }
        }
        
    }
};