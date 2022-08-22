class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)
                return false;
        
        
        int i=0;
        if(n&(n-1)!=0)
                return false;
        int n1=n;
        while(n1){
            n1=n1>>1;
            i++;
        }
        if(i%2==1 and (n&(n-1))==0)
            return true;
        
        return false;
        
    }
};