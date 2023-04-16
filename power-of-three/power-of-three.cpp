class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        long long curr=1;
        
        while(1){
            curr*=3;
            if(curr==n)
                return 1;
            if(curr>n)
                return false;
        }
        return false;
        
    }
};