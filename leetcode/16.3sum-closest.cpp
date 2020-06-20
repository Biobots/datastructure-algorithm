class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        quicksort(nums,0,len-1);
        int i = 0;
        int offset = nums[0] + nums[1] + nums[2] - target;
        int abs = absf(offset);
        while(i<len)
        {
            int lo = i+1; int hi = len-1;
            while(hi>lo)
            {
                int tmp = nums[i] + nums[lo] + nums[hi];
                if(tmp==target) return target;
                else if(tmp>target)
                {
                    int o = tmp - target;
                    if(absf(o)<abs) {offset = o; abs = absf(o);}
                    hi--;
                }
                else if(tmp<target)
                {
                    int o = tmp - target;
                    if(absf(o)<abs) {offset = o; abs = absf(o);}
                    lo++;
                }
            }
            i++;
        }
        return target+offset;
    }
    int absf(int a)
    {
        return a > 0 ? a : -a;
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