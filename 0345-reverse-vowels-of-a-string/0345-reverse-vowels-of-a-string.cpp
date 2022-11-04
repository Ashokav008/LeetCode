class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        unordered_map<char,int>mp{{'a',1},{'e',1},{'i',1},{'o',1},{'u',1},{'A',1},{'E',1},{'I',1},{'O',1},{'U',1}};
        while(i<j){
            
            while(i<j and mp.find(s[i])==mp.end())
                        i++;
            
            while(i<j and mp.find(s[j])==mp.end())
                        j--;
            
            if(i<j)
            {
                swap(s[i],s[j]);
                i++;j--;
                
            }
            
            
        }
        
        return s;
    }
};