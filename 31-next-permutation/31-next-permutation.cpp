class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            int index1 = -1, index2 = -1;
    
    for(int i = nums.size()-2;i>=0;i--) //traversing from second last index and finding break point
    {
        if(nums[i]<nums[i+1])
        {
            index1 = i;
            break;
            return;
        }
    }
    // if break point doesn't exist
    if(index1 == -1)
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    else // if break point exist
    {
        for(int i=nums.size()-1;i>=0;i--)  //traversing from last index
        {
            if(nums[i] > nums[index1])
            {
                index2 = i;
                break;
                return;
            }
        }
    }
    
    swap(nums[index1], nums[index2]);
    
    reverse(nums.begin()+index1+1,nums.end());
    
    return ;
}
};