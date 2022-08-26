class Solution {
public:
    bool flg=false;
    void perem(string &str, int i , int n){
        
        if(i==n){
            // cout<<str<<endl;
            return;
                 
            
        }

        for(int index=i;index<=n;index++){
            swap(str[i],str[index]);
            
            if(str[0]!='0' and  (stoi(str)&(stoi(str)-1)) ==0   ){
                
                flg=true;
                return;
                
            }
            perem(str,i+1,n);
            swap(str[i],str[index]);
            
        }
        return;  
    }
    
    bool reorderedPowerOf2(int num) {
        
        flg=false;
        if(num==1 or (num&(num-1)) ==0 )
                return true;
        
        string str=to_string(num);
        int n=str.size(),i=0;
        
         perem(str,i,n-1);
        
        return flg;
    }
};