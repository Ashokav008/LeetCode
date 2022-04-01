class Solution {
public:
    void reverseString(vector<char>& str) {
        
        int i=0,j=str.size()-1;
        while(i<=j){
            swap(str[i],str[j]);
            i++,j--;
        }
        
        return ;
    }
};