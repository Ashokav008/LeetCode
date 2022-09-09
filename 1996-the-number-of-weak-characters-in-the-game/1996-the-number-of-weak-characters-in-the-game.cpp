class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        
        
         if(v1[0]==v2[0] )
               return v1[1]>v2[1];
        
        return v1[0]<v2[0];
        
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        sort(arr.begin(),arr.end(), comp);
        int ans=0;
        int n=arr.size();
        int first=arr[0][0],second=arr[0][1];

        int mtn=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(arr[i][1]<mtn)
                ans++;
            mtn=max(mtn,arr[i][1]);
        
    }
        return ans;
       
    }
};