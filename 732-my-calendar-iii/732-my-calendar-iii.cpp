class MyCalendarThree {
public:
    
    map<int,int>mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        
        
        mp[start]++;
        mp[end]--;
        int k=0,ongoing=0;
        for(auto it: mp){
            
            k=max(k, ongoing+=it.second);
            
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */