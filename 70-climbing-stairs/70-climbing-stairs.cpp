class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
                return 0;
        
        vector<long long>v(n+1,0);
        v[0]=1;
        v[1]=2;
        
        for(int i=2;i<=n;i++){
            v[i]=v[i-1]+v[i-2];
            // cout<<v[i]<<endl;
        }
        return (int)(v[n-1]);
    }
};