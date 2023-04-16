// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long s=1,e=pow(2,31)-1;
        long long ans;
        while(s<=e){
            long long mid=s+ (e-s)/2;
            if(isBadVersion(mid)){
                ans=mid; 
                e=mid-1;   
            }
            else
                s=mid+1;

        }
        return ans;
    }
};