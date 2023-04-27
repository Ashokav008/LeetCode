//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<vector<int>>seg;
    
    
    void build(int idx, int low, int high, string &s){
        
        if(low==high){
            ++seg[idx][s[low]-'a'];;
            return;
        }
        int mid=(low+high)/2;
        build(2*idx+1,low,mid,s);
        build(2*idx+2,mid+1,high,s);
        
        for(int i=0;i<26;i++)
            seg[idx][i]=seg[2*idx+1][i]+ seg[2*idx+2][i];
            
        return;
    }
    
    void update(int idx, int low,int high, int l, int r, char ch){
        
        //completely outlies
        
        if(low>l or high<r)
            return;
        //completely lies
        if(low>=l and high<=r){
            vector<int>f(26,0);
            ++f[ch-'a'];
            seg[idx]=f;
            return;
            
        }
        //partially lies
        int mid=(low+high)/2;
        update(2*idx+1,low,mid,l,r,ch);
        update(2*idx+2, mid+1, high,l,r,ch);
        
        for(int i=0;i<26;i++)
            seg[idx][i]=seg[2*idx+1][i]+ seg[2*idx+2][i];
        
        return;
        
    }
    
    vector<int>query(int idx, int low,int high, int l, int r){
        vector<int>f(26,0);
        if(low>r or high<l)
            return f;
        if(low>=l and high<=r){
            return seg[idx];
        }
        int mid=(low+high)/2;
        vector<int>leftV=query(2*idx+1,low,mid,l,r);
        vector<int>rightV=query(2*idx+2,mid+1,high,l,r);
        
        for(int i=0;i<26;i++)
            f[i]=leftV[i]+rightV[i];
        return f;
    }
    
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        vector<char>ans;
        seg.resize(4*n,vector<int>(26,0));
        build(0,0,n-1,s);
        
        for(auto q:queries){
            
            int choice=stoi(q[0]);
            
            if(choice==1){
                //update the seg tree  
                char ch=q[2][0];
                int idx=stoi(q[1]);
                update(0,0,n-1,idx,idx,ch);
                
                
            }else{
                // query the seg tree
                int l=stoi(q[1]);
                int r=stoi(q[2]);
                int k=stoi(q[3]);
                
                vector<int>freq=query(0,0,n-1,l,r);
                int cnt=0;
                for(int i=25;i>=0;i--){
                    cnt+=freq[i];
                    if(cnt>=k){
                        ans.push_back('a'+(i));
                        break;
                    }
                }
            }
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends