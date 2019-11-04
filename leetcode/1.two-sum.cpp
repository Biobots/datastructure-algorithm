class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> nummap;
        for (int i = 0; i < size; i++)
        {
            nummap.insert(pair<int, int>(nums[i], i));
        }
        map<int, int>::iterator iter;
        for (int i = 0; i < size; i++)
        {
            int tmp = target - nums[i];
            iter = nummap.find(tmp);
            if (iter != nummap.end() && iter->second != i)
            {
                vector<int> ret;
                ret.push_back(i);
                ret.push_back(iter->second);
                return ret;
            }
        }
        vector<int> ret;
        return ret;
    }
};