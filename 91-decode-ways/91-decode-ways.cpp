class Solution {
public:
    int solve(int i, string s, vector<int>&dp){
        
        if( i==s.size())
                return 1;
        if(s[i]=='0')
                return 0;
        
         if(i==s.size()-1)
                return 1;
        if(dp[i]!=-1)
                return dp[i];
        string b=s.substr(i,2);
        
        int way1=solve(i+1,s,dp);
        
        int way2=0;
        
        if(stoi(b)<=26 and stoi(b)>0)
                way2=solve(i+2,s,dp);
        
        
        return dp[i]= way1+way2;
        
    }
    
    
    int numDecodings(string s) {
        int pos=0;
        vector<int>v(s.size(),-1);
        int ans=solve(pos,s,v);
        
        return ans;
                
        
    }
};