#include<bits/stdc++.h>
class Solution {
public:
    bool check(string s, unordered_map<char,int> &mp){
        unordered_set<char>st;
        
        for(auto c:s){
            
            if(st.find(c)!=st.end()) //check this string has duplicate inside it or not
                    return false;
            st.insert(c);
            
            if(mp[c]>0) // having  a duplicate character.
                return false;
        }
        return true;
    }
    
    
    int solve(int i , unordered_map<char,int>&mp,vector<string>& arr){
        if(i>=arr.size())
            return 0; 
        
        int x=0;
        x= solve(i+1,mp,arr);
        //cout<<"Not taken "<< arr[i]<<endl;
        if(check(arr[i],mp)){
            
            for(auto c:arr[i])
                    mp[c]++;
            int y=solve(i+1,mp,arr)+arr[i].size();
            x=max(x,y);
            
             for(auto c:arr[i])
                    mp[c]--;
            
        }
             
        return x;
    }
    
    int maxLength(vector<string>& arr) {
        unordered_map<char,int>mp;
        return solve(0,mp,arr);
      
        
    }
};