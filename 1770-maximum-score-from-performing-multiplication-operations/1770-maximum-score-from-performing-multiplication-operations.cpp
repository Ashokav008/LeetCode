class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m_size = multipliers.size();
        dp.resize(m_size, vector<int>(m_size, INT_MIN));
        return getMax(0, nums.size()-1, 0, m_size, nums, multipliers);
    }
    
    int getMax(int i, int j, int m_i, int &m_size, vector<int>& nums, vector<int>& multipliers){
        
        if( m_i >= m_size || j<i ){
            return 0;
        }
        if( dp[i][m_i] == INT_MIN ){
            
            int choose_i = nums[i] * multipliers[m_i];
            int choose_j = nums[j] * multipliers[m_i];

            choose_i += getMax(i+1, j, m_i+1, m_size, nums, multipliers);
            choose_j += getMax(i, j-1, m_i+1, m_size, nums, multipliers);
            dp[i][m_i] = max(choose_i, choose_j);
        } 
        return dp[i][m_i];
    }
};