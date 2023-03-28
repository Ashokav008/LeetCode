//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    public:
    vector<int> chocolates;
    int countOfCalls;
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    
    int getSEEle(Shop shop,long  ele){
        int s=0,e=1e5+1;
        int ans=-1;
        while(s<=e){
            shop.countOfCalls=0;
           int mid=(e+s)/2;
           if(shop.get(mid)==-1)
            {
                e=mid-1;
                continue;
            }
            if(shop.get(mid)==ele)
                return shop.get(mid);
            else if(shop.get(mid)<ele){
                ans=shop.get(mid);
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
    
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        long long int ans=0;
        while(k){
            shop.countOfCalls=0;
            int cho=getSEEle(shop, k);
            if(cho==-1)
                break;
            ans+=(k/cho);
            // cout<<"Gettting choc   "<< cho<<"  added  "<<k/cho<<endl;
            k=k%cho;
        }
        return ans;
        
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends