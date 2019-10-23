class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=numbers.size()-1;
        vector<int> res;
        if(r<0)
        	return res; //考虑空numbers的情况
        while(numbers[l] + numbers[r] != target){
        	int sum = numbers[l] + numbers[r];
        	if(sum < target)
        		l++;
        	if(sum > target)
        		r--;
        }
        res.push_back(++l);
        res.push_back(++r); //注意应该是++r而不是r++
        return res;
    }
};