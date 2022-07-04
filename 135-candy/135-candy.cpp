class Solution {
public:
    int candy(vector<int>& ratings) {
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>  pq;
        vector<int> v(ratings.size(), 1);
        int ans = 0;
        
        for ( int i = 0; i < ratings.size(); i++ ) pq.push( { ratings[i], i } );
        
        while ( !pq.empty() ) {
            
            int rate = pq.top().first, ind = pq.top().second;
            pq.pop();
            
            
            if ( ind < ratings.size() - 1 && ind > 0 && rate > ratings[ind - 1] && rate > ratings[ind + 1] ) {
                v[ind] = max(v[ind - 1], v[ind + 1]) + 1;
            } else if ( ind < ratings.size() - 1 && rate > ratings[ind + 1] ) {
                v[ind] = v[ind + 1] + 1;
            } else if ( ind > 0 && rate > ratings[ind - 1] ) {
                v[ind] = v[ind - 1] + 1;
            }
            
        }
        
        
        ans = accumulate(v.begin(), v.end(), 0);
        
        return ans;
        
    }
};