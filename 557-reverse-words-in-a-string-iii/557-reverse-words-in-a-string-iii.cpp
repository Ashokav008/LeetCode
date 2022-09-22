class Solution {
public:
    string reverseWords(string s) {
        int i=0,n=s.size();
       while(i<n){
           int j=i;
           while(j<n and s[j]!=' ')
               j++;
           
           int j1=j;
           j--;
           while(i<j){
               swap(s[i],s[j]);
               i++,j--;
           }
           
           i=j1+1;
       }
        
        return s;
    }
};