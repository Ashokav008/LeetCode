class Solution {
public:
    bool isHappy(int n) {
        int no=n;
        unordered_set<int>st;
        // st.insert(no);
        while(st.find(no)==st.end()){
               st.insert(no);
            int ans=0;
            while(no>0){
                int l=no%10;
                ans+=l*l;
                no/=10;
                // cout<<l<<"  ";
            }
            
            no=ans;
         
            cout<<ans<<endl;
             
            if(no==1)
                    break;
        }
        if(no==1)
                return 1;
        else
                return 0;
    }
};