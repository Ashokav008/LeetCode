class Solution {
public:
    int maximum69Number (int num) {
        string nn=to_string(num);
        
        for(int i=0;i<nn.size();i++){
            if(nn[i]=='6'){
                    nn[i]='9';
                break;
            }
        }
        
        num=stoi(nn) ;
        
        return num;
    }
};