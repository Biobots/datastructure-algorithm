class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        int len = nums.size();
        if(len<3) return rst;
        quicksort(nums,0,len-1);
        if(nums[0]>0) return rst;
        int i = 0;
        while(i<len)
        {
            int lo = i+1; int hi =len-1;
            while(hi>lo)
            {
                int tmp = nums[i]+nums[lo]+nums[hi];
                if(tmp==0)
                {
                    rst.push_back({nums[i], nums[lo], nums[hi]});
                    while(hi>lo+1 && nums[lo+1]==nums[lo]) lo++;
                    while(hi-1>lo && nums[hi-1]==nums[hi]) hi--;
                    hi--;
                    lo++;
                }
                else if(tmp>0)
                {
                    hi--;
                }
                else if(tmp<0)
                {
                    lo++;
                }
            }
            while(i<len-1 && nums[i+1]==nums[i]) i++;
            i++;
        }
        return rst;
    }
    void quicksort(vector<int>& nums, int l, int h)
    {
        if (l >= h) return;
        int lo = l; int hi = h;
        int store = nums[lo];
        while(hi>lo)
        {
            while(nums[hi]>store && hi>lo) hi--;
            if(hi>lo)
            {
                nums[lo] = nums[hi];
                lo++;
            }
            while(nums[lo]<=store && hi>lo) lo++;
            if(hi>lo)
            {
                nums[hi] = nums[lo];
                hi--;
            }
        }
        nums[lo]=store;
        quicksort(nums, l, lo-1);
        quicksort(nums, lo+1, h);
        return;
    }
};