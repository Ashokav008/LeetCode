class Solution {
public:
    int removePalindromeSub(string s) {
       
        //check if given string is palindrome.. if yess return 1 else return 2;
        int n=s.size();
        
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
                return 2;
        }
    return 1;
        
    }
};