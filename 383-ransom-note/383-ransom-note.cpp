class Solution {
public:
    bool canConstruct(string nn, string oo) {
        
        if(nn.size()>oo.size()){
            return false;
        }
        
        map<char,int>mp1;
        map<char,int>mp2;
        int n=nn.size(),m=oo.size();
        for(int i=0;i<n;i++){
            mp1[nn[i]]++;
        }
        
        for(int i=0;i<m;i++){
            mp2[oo[i]]++;
        }
        
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end()){
               return false;
            }
            if(mp2[it.first]<it.second)
                    return false;
            
            
        }
    
        return true;
        
    }
};