class MedianFinder {
public:
  priority_queue<int>maxHeap;
  priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() 
    {
        
    }
    
    void addNum(int num)
    {    
        if(maxHeap.empty()||maxHeap.top()>num)
        maxHeap.push(num);
        else
        minHeap.push(num);

        if(maxHeap.size()>minHeap.size()+1)
        {
           minHeap.push(maxHeap.top());
           maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()+1)
        {
           maxHeap.push(minHeap.top());
           minHeap.pop();
        }
       
    }
    
    double findMedian()
    {
        if(maxHeap.size()==minHeap.size())
        return (maxHeap.top()+minHeap.top())/2.0;

        else if(maxHeap.size()>minHeap.size())
        return maxHeap.top();
        else
        return minHeap.top();
    }
};
//TC: O(logN) [Insertion: because adding a number to a heap takes logarithmic time.]
//SC: O(N)
//Problem:https://leetcode.com/problems/find-median-from-data-stream/description/
