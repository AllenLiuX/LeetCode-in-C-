Tags: set, bits, 简单
---

//set
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        // int res;
        for(int i : nums){
            if(set.count(i))
                set.erase(i);
            else
                set.insert(i);
        }
        unordered_set<int>::iterator it = set.begin();
        return *it;
    }
};


//异或，更快
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            res = res^nums[i];  //自己和自己的异或是0
        }
        return res;
    }
};