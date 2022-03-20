class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int cd1 = tops[0] ;
        int cd2 = bottoms[0] ;
       
        int n=tops.size() ;
        int i=0 , j=0 ;
      
        int ans = 0;
        int p=0 , q=0 ;
        
        int cnt =0; 
        while(i<n and j<n) 
        {
            if(tops[i]==cd1 and bottoms[j]!=cd1)
            
                p++;
            
            if(bottoms[j]==cd1 and tops[i]!=cd1)
                q++ ;
            if(tops[i]==cd1 or bottoms[j]==cd1)
            {
                cnt++;
            }
            i++ ;
            j++;
        }
        if(cnt==n)
        {
            return min(p, q);
        }
            
        
         ans = 0;
       p=0 ; q=0 ;
        
        cnt =0; 
        i=0 ; j=0 ;
        while(i<n and j<n) 
        {
            if(tops[i]==cd2  and bottoms[j]!=cd2)
                p++;
            
            if(bottoms[j]==cd2   and tops[j]!=cd2)
                q++ ;
            if(tops[i]==cd2 or bottoms[j]==cd2)
            {
                cnt++;
            }
            i++ ;
            j++;
        }
                    cout<<cd2<<" "<<p<<" "<<q<<endl ;

        if(cnt==n)
        {
            return min(p, q);
        }
            
        
        return -1 ;
        
    }
};