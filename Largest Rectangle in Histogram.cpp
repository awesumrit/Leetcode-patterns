class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int left_min[n], right_min[n];
        
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty())
                left_min[i] = -1;
            else
                left_min[i] = st.top();
            
            st.push(i);
        }
        
        st = stack<int>();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty())
                right_min[i] = n;
            else
                right_min[i] = st.top();
            
            st.push(i);
        }
        
        int max_area = 0;
        for(int i=0; i<n; i++){
            max_area = max(max_area, (right_min[i] - left_min[i] - 1)*heights[i]);
        }
        
        return max_area;
    }
};
