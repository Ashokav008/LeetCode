class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        // map<int,int>mp;
        int n=costs.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({costs[i][1]-costs[i][0],i});
            
        }
        
        sort(v.begin(),v.end());
     
        int cost=0;
        int k=n/2;
     for(auto it:v){
         cout<<it.second<<" "<<it.first<<endl;
         if(k>0)
            cost+=costs[it.second][1],k--;
         else
                 cost+=costs[it.second][0];
     }
        
      
        return cost;
    }
};