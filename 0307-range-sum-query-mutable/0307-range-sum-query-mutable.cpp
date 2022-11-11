class NumArray {
public:
    vector<int>seg;
    int n;
    void build(int ind,int low, int high, vector<int> &arr){
        
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1, low,mid,arr);
        build(2* ind+2, mid+1, high,arr);
        
        
        seg[ind]=seg[2*ind+1]+ seg[2*ind+2];
        
    }
    
    int query(int ind, int low, int high, int l , int r){
        
        //completey overlap
        if(low>=l and high<=r)
                return seg[ind];
        //no overlap
        if(low>r or high<l)
                return 0;
        
        //partial overlap
        int mid=(low+high)/2;
        int left=query(2*ind+1, low,mid,l,r);
        int right=query(2*ind+2, mid+1,high, l ,r);
        
        return left+right;
        
    }
  
    void updateHelper(int ind, int low , int high, int pos, int val ){
        
        if(low==high){
            seg[ind]=val;
        }
        else{
        int mid=(low+high)/2;
        if(pos<=mid){
            updateHelper(2*ind+1, low,mid, pos,val);
        }
        else{
            updateHelper(2*ind+2, mid+1, high, pos,val);
        }
        
        seg[ind]=seg[2*ind+1] + seg[2*ind+2];
        } 
    }
    
    NumArray(vector<int>& nums) {
         n=nums.size();
        if(n==0)
                return;
        
        seg.resize(5*n);
        build(0,0,n-1,nums);
       
    }
    
    void update(int index, int val) {
        
          // cout<<"Contruector completed"<<endl;
        updateHelper(0,0,n-1, index, val);
    }
    
    int sumRange(int l, int r) {
       
       return query(0, 0 , n-1, l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */