class Solution {
public:
    string reorganizeString(string s) {
        
        // cout<<to_char('a'+2)<<endl;
        map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            pq.push({it.second,it.first});
        }
        
      if( pq.top().first>(n/2)+(n%2))
            return "";
     
    
        string ans;
       while(pq.size()>1)
        {
            auto t1=pq.top(); pq.pop();
            auto t2=pq.top(); pq.pop();
            
            ans+=t1.second; ans+=t2.second;
            t1.first-=1; t2.first-=1;
            
            if(t1.first>0){
                pq.push(t1);
            }
            if(t2.first>0){
                pq.push(t2);
            }
            
        }
        if(!pq.empty()){
            
                ans+=pq.top().second;
                
        }
    
        return ans;

        
    }
};