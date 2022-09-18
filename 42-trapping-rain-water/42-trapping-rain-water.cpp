class Solution {
public:
    

    
  
  int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        
        int temp = height[0];
        for(int i = 0; i < n; i++) {
            temp = max(temp,height[i]);
            left[i] = temp;
        }
        
        temp = height[n-1];
        for(int i = n-1; i >= 0; i--) {
            temp = max(temp,height[i]);
            right[i] = temp;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += min(left[i],right[i]) - height[i];
        }
        
        return ans;
    }
};