class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // if n==1 or k==1 we return the nums array
        if(n==1 || k==1)return nums;
        
        // result vector containing max of sliding windows 
        vector<int>res;
        
        // stores the max element indexes in previous K step
        deque<int>dq;
        for(int i=0;i<n;i++)
        {
            // check if back element of deque is less than current element
            // if then pop the back element and do it as long as it is true
            // cause we want to store only potential max elements in the deque
            while(!dq.empty() && nums[dq.back()]<nums[i])dq.pop_back();
            
            // push current element in the back of deque
            dq.push_back(i);
            
            // push front in to result vector as soon as current sliding window end is reached
            if(i>=k-1)res.push_back(nums[dq.front()]);
            
            // pop front element from the deque if its position is outside the next sliding window
            if(i-k+1==dq.front())dq.pop_front();
        }
        
        return res;
    }
};
