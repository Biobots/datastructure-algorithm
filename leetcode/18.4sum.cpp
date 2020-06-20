class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rst;
        int len = nums.size();
        if(len<4) return rst;
        quicksort(nums,0,len-1);
        int i = 0; int j = 1;
        while(i<len-3)
        {
            j=i+1;
            while(j<len-2)
            {
                int lo = j+1;
                int hi = len-1;
                while(hi>lo)
                {
                    int tmp = nums[i]+nums[j]+nums[lo]+nums[hi];
                    if(tmp==target)
                    {
                        rst.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        while(hi>lo && nums[hi]==nums[hi-1]) hi--;
                        hi--;
                        while(hi>lo && nums[lo]==nums[lo+1]) lo++;
                        lo++;
                    }
                    else if(tmp>target)
                    {
                        hi--;
                    }
                    else if(tmp<target)
                    {
                        lo++;
                    }
                }
                while(j<len-3 && nums[j]==nums[j+1]) j++;
                j++;
            }
            while(i<len-4 && nums[i]==nums[i+1]) i++;
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