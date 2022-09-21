class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& arr, vector<vector<int>>& q) {
        
        vector<int>ans;
        long long  sum=0;
        for(auto it: arr){
            if(it%2==0)
                    sum+=it;
        }
        
        for(auto it:q){
            
            int val=it[0];
            int idx=it[1];
            if(arr[idx]%2==0){
                sum-=arr[idx];
            }
            
            arr[idx]+=val;
            
            if(arr[idx]%2==0)
                    sum+=arr[idx];
            
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};