class Solution {
public:
    static bool comp(int a,int b){
        
        if(b>a)
                return true;
        
        return false;
    }
    
    int numRescueBoats(vector<int>& people, int limit) {
     
        int ans=0,n=people.size();
        sort(people.begin(),people.end(),greater<int>());
        
    
    int i=0,j=n-1;
        while(i<=j){
    
            if(people[i]+people[j]<=limit){
                ans++;
                i++;
                j--;
                
            }
            else
            {
                ans++;
                i++;
            }    
                
            
        }
        
        
        return ans;
        
    }
};