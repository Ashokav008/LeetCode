class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
     
        int n=v.size();
        int carry=1;
        reverse(v.begin(),v.end());
        
        for(int i=0;i<n;i++){
            
            int ele=v[i]+carry;
            v[i]=ele%10;
            if(ele>9){
                    carry=1;
                
            }
            else{
                carry=0;
                break;
            }
        }
        if(carry==1){
            v.push_back(carry);
            
        }
        
        reverse(v.begin(),v.end());
        
        
        
        return v;
            
    }
};