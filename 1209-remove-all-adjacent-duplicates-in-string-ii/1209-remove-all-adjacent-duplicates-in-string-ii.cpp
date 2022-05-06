class Solution {
public:
    string removeDuplicates(string s, int k) {
                  //char    index,freq;
        stack<pair<char,int>>stk;
        
        int n=s.size();
        for(int i=0;i<n;i++){
            
            if(!stk.empty() and  stk.size()>=k-1 and stk.top().second==k-1 and stk.top().first==s[i]){
                
               int ele=k-1;
                while(ele){
                    // cout<<"poping "<<stk.top().first<<endl;
                    stk.pop();
                    ele--;
                    
                }
            }
            else {
                // cout<<"pushing  "<<s[i]<<endl;
                
                if(!stk.empty() and stk.top().first==s[i]){
                    
                    
                stk.push({s[i],stk.top().second+1});
                    
                }
                
                else{
                    stk.push({s[i],1});
                    
                }
            }
            
            
        }
        // n=stk.size();
        string ans;
      
        while(!stk.empty())
        {
            // cout<<stk.top().first<<" "<<stk.top().second.second<<endl;
            ans+=stk.top().first;
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};