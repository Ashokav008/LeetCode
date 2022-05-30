class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        
        long int d1 = abs(dividend), d2 = abs(divisor);
        
        int res=0;
        while(d2<=d1) {
            long int mul=d2, tmp=1;
            while(mul<=d1-mul) {
                mul+=mul;
                tmp+=tmp;
            }
            res+=tmp;
            d1-=mul;
        }
        
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -res;
        
        return res;
        
    }
};