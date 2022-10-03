class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
       int ans=0;
       int n=colors.size(); 
    priority_queue<int>pq;
      for(int i=0;i<n-1;i++){
             while(i+1<n and colors[i]==colors[i+1]){
                 pq.push(-1* nt[i]);
                 i++;
             }
            pq.push(nt[i]* -1);
          while(pq.size()>1){
              ans+=pq.top();
              pq.pop();
          }
          pq.pop();
      }
       return -ans; 
    }
};