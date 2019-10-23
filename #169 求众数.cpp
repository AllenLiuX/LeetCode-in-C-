class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i : nums){
            if(map.find(i)!=map.end())
                map[i]++;
            else map[i] = 1;
        }
        unordered_map<int,int>::iterator iter = map.begin();    //遍历map
        for(;iter!=map.end(); iter++)
        {
            if(iter->second > n/2)
                return iter->first;
        }
        return 0;
    }
};