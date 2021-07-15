class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) 
    {
        int n=a.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ptr(n,0); // pointer array
        
        vector<int> ans={INT_MAX,INT_MIN};
        
        for(int i=0;i<n;i++) 
        {
            ans[0] = min(ans[0],a[i][0]); // least first element of every array
            ans[1] = max(ans[1],a[i][0]); // greatest first element of every array
            pq.push({a[i][0],i});
        }
        
        int low,high=ans[1]; 
        
        while(1) // every array in [a] must have a single element in pq
        {
            int ind = pq.top().second; //contains index of array with the least element
			pq.pop(); ptr[ind]++; 
            
            // if we have exhausted any array in [a], then there's no point in continuing
            if(ptr[ind] >= a[ind].size()) break; 
			
			
            pq.push({a[ind][ptr[ind]],ind}); //pushing the next element of that array in [a] which had minimum element
            
            low=pq.top().first;  // min element of all the arrays[ptr[i]]
            high=max(high,a[ind][ptr[ind]]); // max element of all the arrays[ptr[i]]
            
            if(high-low<ans[1]-ans[0]) ans={low,high}; // if the current range is better than previous one
        }
		
        return ans;
    }
};
