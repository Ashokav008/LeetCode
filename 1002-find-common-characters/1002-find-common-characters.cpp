class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        vector<int>track(26,0),ff(26,INT_MAX); 
        
        // for(auto it:words[0])
        //         ff[it-'a']++;
        
        for(int i=0;i<n;i++){
            
            for(auto it: words[i]){
                track[it-'a']++;
            }            
            
            for(int i=0;i<26;i++){
                ff[i]=min(ff[i], track[i]);
                track[i]=0;
            }
        }
        
        for(int i=0;i<26;i++){
            
            int cnt=ff[i];
            
            while(cnt--){
                char ch=i+'a';
                string str;
                str+=ch;
                ans.push_back(str);
            }
        }
        
        return ans;
    }
};