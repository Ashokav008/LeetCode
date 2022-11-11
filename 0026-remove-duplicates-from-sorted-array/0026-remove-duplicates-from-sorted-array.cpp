class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size(),ans=0;
        if(n==1)
                return 1;
        int i=0,j=0;
        while(j<n){
            j=i+1;
            while(j<n and arr[j]==arr[i]){
                j++;
            }
            arr[ans]=arr[i];
            ans++;
            i=j;
        }
        return ans;
    }
};