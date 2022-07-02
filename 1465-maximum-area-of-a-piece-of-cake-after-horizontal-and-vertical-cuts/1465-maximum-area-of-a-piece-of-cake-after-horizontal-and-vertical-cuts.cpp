class Solution {
public:
    long  mod=1e9+7;
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        hCuts.push_back(0);
         hCuts.push_back(h);
        vCuts.push_back(0); 
         vCuts.push_back(w);
        sort(hCuts.begin(),hCuts.end());
        sort(vCuts.begin(),vCuts.end());
        long ans=0;
    long  n=hCuts.size(),m=vCuts.size();
        int h1=0,h2=0;
        for(int i=0;i<n-1;i++){
                 h1=max(h1,abs(hCuts[i]-hCuts[i+1]));
        }
        for(int j=0;j<m-1;j++){
                  h2=max(h2,abs(vCuts[j]-vCuts[j+1]));
               
       }
     long lcl = (long long) ((h1%mod *h2 % mod )%1000000007);
        return (int)lcl;
    }
};