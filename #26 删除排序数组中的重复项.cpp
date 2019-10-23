class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if (nums.size()==0)
        return 0;
    //加入计数器，计算表中互不相同的元素个数
    int k=1;
    int p=nums[0];
    //nums[i]为当前元素的结点
    for (int i=1;i<nums.size();i++){
        if (nums[i]!=p){
            nums[k]=nums[i];
            p=nums[i];
            k++;
        }
    }
    return k;   //返回表长


        
//         if(nums.size()<=1)
//             return nums.size();
//         int res = nums.size();
//         for(int i=0; i<res-1; i++){
//             if(nums[i+1]==nums[i]){
//                 int p=i+2;
//                 while(nums[p]==nums[i]){
//                     p++;
//                     res--;
//                 }
                
//                 int j=i+1;
//                 while(p<res){
//                     nums[j]=nums[p];
//                     j++;
//                     p++;
//                 }
//                 res--;
//             }
//         }
//         return res;
        
    }
};