// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {// Your code here
       //int H = high;
       int mid = 0;
       while(low<high)
       {
           if((high - low) == 1)
           {
               if(arr[high]<arr[low]) return arr[high];
               else return arr[low];
           }
           mid = (low+high)/2;
           if(arr[mid] > arr[high])
           {
               low = mid;
           }
           else if(arr[mid]<arr[high])
           {
               high = mid;
           }
       }
       
   }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends