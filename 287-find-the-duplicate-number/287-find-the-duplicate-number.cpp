class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i = 0 ; i < nums.size() ; i++){
            int index = abs(nums[i]) - 1;
            cout<<index<<"   "<<"  ";
            if(nums[index] < 0){
                cout<<" returning  nums[index]"<<nums[index]<<endl;
                return abs(nums[i]);
            }
            cout<<-nums[index]<<endl;
            nums[index] = - nums[index];
            
        }
        return -1;
    }
};