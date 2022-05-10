class Solution {
public:
        
    vector<vector<int>>fAns;
    void backTrack(int i,int k,int sum,int currSum,vector<int>&ans){
        
        if(currSum==sum and ans.size()==k){
            // cout<<"pushing into final"<<endl;
            fAns.push_back(ans);
            return;
        }

        for(int ele=i+1;ele<10;ele++){
           
            if(currSum+ele<=sum){
                ans.push_back(ele);
                 // cout<<"ele  "<<ele<<" currSum ::  "<<currSum+ele<<endl;
                // cout<<" pushing  of ans :  "<<ele<<endl;
                backTrack(ele,k,sum,currSum+ele,ans);
                ans.pop_back();
            }
        
            
        }
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
       int i=0,currSum=0;
        vector<int>ans;
        backTrack(i,k,n,currSum,ans);
        
        
        return fAns;
        
        
    }
};