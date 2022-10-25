class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
     
        int i=0,j=0,i1=0,j1=0;
        int n=word1.size(),m=word2.size();
       while(i<n and j<m){
           
           while(i1<word1[i].size() and j1<word2[j].size() ){
                if(word1[i][i1]!=word2[j][j1])
                        return false;
               cout<<word1[i][i1]<<" = "<<word2[j][j1]<<endl;
               i1++;j1++;
           }
           if(i1==word1[i].size())
           {    cout<<" i++"<<endl;
                i++;i1=0;
           
           }
            if(j1==word2[j].size())
           { 
               cout<<" j++"<<endl;
               j++;j1=0;
           
           }
           
           
       }
        if(i!=n or j!=m)
                return false;
//        if(i<n){
//            if(i1!=word1[i].size()-1)
//                 return false;
//        }
        
//         if(j<n){
//            if(j1!=word2[j].size()-1)
//                 return false;
//        }
        return true;
    }
};