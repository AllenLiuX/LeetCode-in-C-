class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0)
        return 0;
        //加入计数器，计算表中互不相同的元素个数
        int k=1;
        int p=nums[0];
        bool rep = false;
        //nums[i]为当前元素的结点
        for (int i=1;i<nums.size();i++){
            if (nums[i]!=p){
                nums[k]=nums[i];
                p=nums[i];
                k++;
                rep = false;    //注意这一步的位置，只有遇到新的才！rep
            }
            else if(!rep){
                nums[k] = nums[i];
                p=nums[i];
                k++;
                rep = true;
            }
        }
        return k;   //返回表长
    }
};