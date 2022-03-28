class Solution {
public:
bool search(vector<int>& nums, int target) {
	int lo=0;
	int hi=nums.size()-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(nums[mid]==target) return true;
		//for test case like [1,0,1,1,1] i.e. same elements at mid,lo,hi
		if((nums[lo]==nums[mid])&&(nums[hi]==nums[mid]))
			{
				lo++;
				hi--;
			}
		else if(nums[mid]>=nums[lo])
		{
			if(target<=nums[mid] and target>=nums[lo])

				hi=mid-1;

			else

				lo=mid+1;

		}
		else
		{
			if(target>=nums[mid] and target<=nums[hi])

				lo=mid+1;

			else

				hi=mid-1;
		}

	}
		return false;
	}
};