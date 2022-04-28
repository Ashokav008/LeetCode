class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        
        int d1[] = {0, 1, 0, -1};
        int d2[] = {1, 0, -1, 0};
        
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        // {Minimized Maximum Effort so far, {X coordinate of curr, Y coordinate of curr}}
        
        vector<vector<int>> vis(r, vector<int>(c, false));

        pq.push({0, {0,0}});
        
        while(pq.size()){
            pair<int, pair<int,int>> temp = pq.top();
            pq.pop();
            int currX = temp.second.first;
            int currY = temp.second.second;
            int currMinEffort = temp.first;
            // We have reached the end node at heights[r-1][c-1]
            if(currX == r-1 && currY == c-1){
                return currMinEffort;
            }
            // If we have marked curr node done, then don't add its neighbours again
            if(vis[currX][currY]){
                continue;
            }
            vis[currX][currY] = true;
            for(int i=0; i<4; i++){
                // Neighbours of a node in matrix are up, down, left and right, calculated with predefined d1 and d2 arrays
                int neighX = currX + d1[i];
                int neighY = currY + d2[i];
                
                // Check if a neighbour doesnt go out of bound
                if(neighX >= 0 && neighY >= 0 && neighX < r && neighY < c){
                    // Calculate the height difference between current node and neighbour node
                    int heightDiff = abs(heights[currX][currY] - heights[neighX][neighY]);
                    
                    // We will take max of height difference calcuated so far and above
                    int Effort = max(currMinEffort, heightDiff);
                    
                    // Push the Effort and new node's coordinate in priority queue
                    pq.push({Effort, {neighX, neighY}});
                }
            }
        }
        return 0;
    }
        
    
};