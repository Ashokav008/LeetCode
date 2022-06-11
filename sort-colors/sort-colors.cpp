class Solution {
public:
    void sortColors(vector<int>& v) {
        int a=0, b=0, c=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
                a++;
            else if(v[i]==1)
                b++;
            else
                c++;
        }
        
        int i=0;
            while(a--){
                v[i++]=0;
            }
            while(b--)
                    v[i++]=1;
            while(c--)
                    v[i++]=2;
        
        return;
    }
};