class Solution {
public:
    void dfs(string src,string destn,unordered_map<string,vector<pair<string,double>>>adj,unordered_map<string,int>vis,double &ans,double temp){
        
        if(vis.count(src))
                return ;
        if(src==destn){
                ans=temp;
                return;
        }
        
        
        vis[src]=1;
        
        for(auto it:adj[src]){
            // if(adj.count(src))
            dfs(it.first,destn,adj,vis,ans,temp*it.second);
        }
        return;
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        unordered_map<string,vector<pair<string,double>>>adj;
        int i=0;
        for(auto it:equations){
        
        adj[it[0]].push_back({it[1],values[i]});
        adj[it[1]].push_back({it[0],1.0/values[i]});
                                                     
            i++;
            }
        
        vector<double>finalAns;
        for(int i=0;i<queries.size();i++){
            
            string src=queries[i][0];
            string destn=queries[i][1];
            
            double ans=-1.0;
            double temp=1.0;
            unordered_map<string,int>vis;
            if(adj.count(src))
             dfs(src,destn,adj,vis,ans,temp);
            
            finalAns.push_back(ans);
        }
        return finalAns;
    }
};