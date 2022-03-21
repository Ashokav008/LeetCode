class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int arr[26];
        int n=s.size();
        for(int i=0;i<n;i++){
            arr[s[i]-'a']=i;
        }
        
        int maxi=-1;
        vector<int>ans;
        int last=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[s[i]-'a']);
            if(i==maxi){
                    ans.push_back(i-last+1);
                     last=i+1;
            }
        }
     return ans;   
    }
};