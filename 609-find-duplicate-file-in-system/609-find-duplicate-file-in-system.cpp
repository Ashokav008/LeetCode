class Solution {
public:
    unordered_map<string, vector<string>>mp;
    
    string extractPath(string str){
        
        string ans="";
        vector<int>content;
        int i=0, n=str.size();
        
        while(str[i]!=' ')
            ans+=str[i++];
        
        
        return ans;
    }
    unordered_map<string,vector<string>> extractFileName(string path){
        int i=0;
        unordered_map<string, vector<string>>mp;
        int n=path.size();
        while(path[i]!=' ')
                i++;
        i++;
        
        string fName="",fContent="";
        while(i<n){
            
            while(path[i]!='(')
                fName+=path[i++];
            i++;
            
            while(path[i]!=')')
                    fContent+=path[i++];
            
            i++;
            
            mp[fContent].push_back(fName);
            cout<<fContent<<" "<<fName<<endl;
            //break;
            if(i>=n-1)
                    break;
            else{
                fContent="";
                fName="";
                i++;
            }
        }
        return mp;
        
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
     
        
        vector<vector<string>> ans; 
        
        int n=paths.size();
        
        for(int i=0;i<n;i++){
            
            string path=paths[i];
            string ePath=extractPath(path);
            unordered_map<string, vector<string>>contentToName=extractFileName(path);
            // cout<<ePath<<endl;
           for(auto it: contentToName){
               //cout<<it.first<<"  "<<it.second<<endl;
               for(auto it2: it.second)
                    mp[it.first].push_back(ePath+"/"+it2);
           }
             cout<<endl;
            // break;
            
            
        }
        for(auto it: mp){
            if(it.second.size()>1)
            ans.push_back(it.second);
        }
        return ans;
        
    }
};