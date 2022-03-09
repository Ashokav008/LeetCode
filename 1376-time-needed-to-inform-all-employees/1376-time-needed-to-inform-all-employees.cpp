class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        queue<int>q;
        q.push(headID);
        
        
        int time=0;
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto child : adj[node]){
                informTime[child]+=informTime[node];
                q.push(child);
            }
        }
        
        for(auto it:informTime)
            time=max(time,it);
        
        return time;
    }
};