class MedianFinder {
public:
    multiset<int>st;
    int n=0;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        st.insert(num);
        n++;
    }
    
    double findMedian() {
        multiset<int>:: iterator it=st.begin();
        double med=0;
        if(n%2==0){
            int j=n/2-1;
            while(j--)
                    it++;
            
            med=*it;
            it++;
            med+=(*it);
            return med/2;
            
        }else{
            int j=n/2;
           while(j--)
                it++;
            
            med=*it;
        }
        
        return med;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */