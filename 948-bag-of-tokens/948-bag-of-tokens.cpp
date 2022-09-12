class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0,j=n-1;
        int ans=0,score=0;
        while(i<=j){
            if(score<1 and arr[i]>power)
                    return score;
            
            else if(arr[i]>power)
            {
               // cout<<"score-- "<<i<<"  "<<j<<endl;
                power+=arr[j];
                ans-=1;
                j--;
                
            }
            else {
                //cout<<"score++ "<<i<<"  "<<j<<endl;
                power-=arr[i];
                ans+=1;
                i++;
            }
            
            score=max(score,ans);
            
        }
        return score;
    }
};