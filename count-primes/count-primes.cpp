class Solution {
public:

    int sieve(int s, int e){
        vector<int>prime(e+1,1);
       
        for(int i=2;i*i<e;i++){
            if(prime[i])
            for(int j=i*i;j<e;j+=i){
                prime[j]=0;
            }
        }
        int ans=0;
        for(int i=2;i<e;i++){
            if(prime[i]==1) {
                // cout<<i<<endl;
                ans++;
            }
        }
    return ans;
    }

    int countPrimes(int n) {
        return sieve(2,n);
    }
};