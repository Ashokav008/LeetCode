class Solution {
public:
    bool rotateString(string s, string goal) {
        
         // s=s+s;
        
        
        string str=s+s; 
        
        if( s.size()==goal.size() and  str.find(goal)!=string::npos)
                return true;
        return false;
        
        
        
    }
};