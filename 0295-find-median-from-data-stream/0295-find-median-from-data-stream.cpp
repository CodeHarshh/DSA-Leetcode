class MedianFinder {
public:

// we divide array into parts
// in first parts we find the max element using max-heap
// in second part we find the min element using min-heap

priority_queue<int> maxHeap;
priority_queue< int ,vector<int>,greater<int>>minHeap;

double median;


    MedianFinder() {
        median=0;
    }
    
    void addNum(int num) {
        if(minHeap.size()== maxHeap.size()){
                if(num>median){
                // insert in right 
                minHeap.push(num);
                median=minHeap.top();

                }
                else{
                    maxHeap.push(num);
                    median=maxHeap.top();
                }

        }

        else if (minHeap.size() == maxHeap.size() + 1) {
    if (num > median) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
        minHeap.push(num);
    } else {
        maxHeap.push(num);
    }
    median = (minHeap.top() + maxHeap.top()) / 2.0;
}

else if (minHeap.size() + 1 == maxHeap.size()) {
    if (num > median) {
        minHeap.push(num);
    } else {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    median = (minHeap.top() + maxHeap.top()) / 2.0;
}


    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */