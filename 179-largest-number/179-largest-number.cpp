#include<bits/stdc++.h>

class Solution {
public:
    static bool comp(string &s1,string &s2){
        
        if(s1+s2<s2+s1)
                return true;
        return false;
    } 

    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string>v;
        for(auto it:nums){
            v.push_back(to_string(it));
        }
        
        int n=v.size();
       vector<string>::iterator it = v.begin();
        bool flg=false;
       
        
        
        if(flg)
            v.push_back("0");
         sort(v.begin(),v.end(),comp);
        
        
        
        int cnt=0;
         for(int i=v.size()-1;i>=0;i--){
             if(v[i]=="0")
             {
                 cnt++;
             }
             
             
            ans+=v[i];
        }  
      
      if(cnt==v.size() and cnt>1)
            return "0";

        return ans;
    }
};