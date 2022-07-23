class Solution {
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0 ; // first element 
        int right = ( matrix.size()*matrix[0].size() ) - 1 ; // last element 
        int m=matrix[0].size();
        while (left <= right) 
        {
            int mid = left + (right - left) / 2 ;  
            if ( target == ( matrix[mid/matrix[0].size()][mid%matrix[0].size()] ) )
                return true ;
            else if ( target > ( matrix[mid/matrix[0].size()][mid%matrix[0].size()] ) ) 
                left = mid + 1 ;
            else 
                right = mid - 1 ;
        }
       return false; 
    } 
  
  };

