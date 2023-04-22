//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;

public class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            int n=Integer.parseInt(in.readLine());
            String s[]=in.readLine().trim().split(" ");
            int a[]=new int[n];
            for(int i=0;i<n;i++){
                a[i]=Integer.parseInt(s[i]);
            }
            Solution ob=new Solution();
            long ans[]=ob.smallerSum(n,a);
            for(long i:ans){
                out.print(i+" ");
            }out.println();
        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution
{
    
    private int getIdx(int ele, int arr[],int s, int e){
     //1 3 5 8 9
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]<ele){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
    
    public long[] smallerSum(int n,int arr[])
    {
        int []myArr=new int[n];
        for(int i=0;i<n;i++)
            myArr[i]=arr[i];
            
        Arrays.sort(arr);
        long []ans=new long[n];
        long []pre=new long[n];
        
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1]+arr[i];
        }
        
        //3 5 1 8 9
        //1 3 5 8 9
        //1 4 9 17 26
        
        for(int i=0 ;i<n;i++){
            int curr=myArr[i];
            // int idx=-1;
            int idx=getIdx(curr, arr,0,n-1);
            // System.out.println(curr+"  "+idx);
            if(idx==-1)
                {
                    ans[i]=0;
                    continue;
                }
            ans[i]=pre[idx];
        }
        return ans;
    }
}