class Solution {
public:
    
    vector<int>nextSmallerEle(vector<int>& heights){
        int n=heights.size();
        stack<int>stk;
        stk.push(-1);
        vector<int>ans(n);
        // ans.push_back(-1);
        for(int i=n-1;i>=0;i--){
           int ele=heights[i];
            while(stk.top()!=-1 and heights[stk.top()]>=ele)
                stk.pop();
           
            ans[i]=stk.top();
            
            stk.push(i);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
     vector<int>preSmallerEle(vector<int>& heights){
        int n=heights.size();
        stack<int>stk;
        vector<int>ans(n);
         stk.push(-1);
        // ans.push_back(-1);
        for(int i=0;i<n;i++){
           int ele=heights[i];
            while(stk.top()!=-1 and heights[stk.top()]>=ele)
                stk.pop();
            ans[i]=stk.top();
            
            stk.push(i);
        }
        return ans;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
            if(n==1)
                return heights[0];
        vector<int>nse;
        nse=nextSmallerEle(heights);
     
        vector<int>pse;
        pse=preSmallerEle(heights);
        
//         for(auto it:nse)
//             cout<<it<<" ";
//         cout<<endl;
        
//         for(auto it:pse)
//             cout<<it<<" ";
//         cout<<endl;
        
        
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l= heights[i];
            if(nse[i]==-1)
                nse[i]=n;
   
     
            
              int b=nse[i]-pse[i]-1;
             
            int newArea=l*b;
            area=max(area,newArea);
            // cout<<l<<"   "<<b<<endl;
        }
        return area;
    }
};