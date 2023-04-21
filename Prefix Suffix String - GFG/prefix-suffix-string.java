//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;

public class code1 
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            String s1[]=in.readLine().trim().split(" ");
            String s2[]=in.readLine().trim().split(" ");

            Solution ob=new Solution();
            int ans=ob.prefixSuffixString(s1,s2);
            out.println(ans);

        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution
{
    public boolean checkPre(String big,String small){
        int n=big.length(),m=small.length();
        if(m>n)
            return false;
        for(int i=0;i<m;i++){
            if(small.charAt(i)!=big.charAt(i))  
                return false;
                
        }
        return true;
    }
     public boolean checkSuf(String big,String small){
        //  System.out.println( "Checkig foe Sufffix");
        int n=big.length(),m=small.length();
        int idx=n-m;
        //  System.out.println( n+"  "+m);
        if(m>n)
            return false;
            //  System.out.println( "Got early returnl");
        for(int i=0;i<m;i++){
            // System.out.println( small.charAt(i)+"   "+ big.charAt(i+idx));
            if(small.charAt(i)!=big.charAt(i+idx))  {
                // System.out.println( small.charAt(i)+"   "+ big.charAt(i+idx));
                return false;
            }
                
        }
        
        return true;
    }
    
    // dogmonkey
    // monkey
    
    public int prefixSuffixString(String s1[],String s2[])
    {
        int n=s2.length,m=s1.length;
        int ans=0;
        for(int i=0;i<n;i++){
            String str=s2[i];
            for(int j=0;j<m;j++){
                // System.out.println(s1[j] +"   "+ str);
                boolean isPre=checkPre(s1[j],str);
                boolean isSuf=checkSuf(s1[j],str);
                
                // System.out.println(isPre +"   "+ isSuf);
                if( isPre||isSuf ){
                    ans++;
                    break;
                }
            }
            
        }
        return ans;
        
    }
}