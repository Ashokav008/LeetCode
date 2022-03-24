class MyCircularQueue {
public:
    int *arr;
    int front=0;
    int rear=-1;
    int count=0;
    int capacity;
    
    
    MyCircularQueue(int k) {
    
        arr = new int[k];
        capacity=k;
    }
    
    bool enQueue(int value) {
        
        if(isFull())
                return false;
         rear=(rear+1)%capacity;
        arr[rear]=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
                return false;
        
        front=(front+1)%capacity;
        count--;
        return true;
        
    }
    
    int Front() {
        if(isEmpty())
                return -1;
        return arr[front];
        
    }
    
    int Rear() {
        
        if(isEmpty())
                return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */