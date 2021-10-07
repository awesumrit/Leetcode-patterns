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


int Solution::maximalRectangle(vector<vector<int> > &A) {
    int result = largestRectangleArea(A[0]);
    int R = A.size(), C = A[0].size();
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++){
            if (A[i][j])
                A[i][j] += A[i - 1][j];
        }
        result = max(result, largestRectangleArea(A[i]));
    }
    return result;
}



// int Solution::maximalRectangle(vector<vector<int> > &A) {
    
//     int m=A.size();
//     int n=A[0].size();
    
//     for(int i=1;i<m;i++)
//     {
//         for(int j=1;j<n;j++)
//         {
//             if(A[i][j]!=0)A[i][j]=1+min(A[i-1][j-1],min(A[i-1][j],A[i][j-1]));
//         }
//     }
//     int ans=0;
    
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(A[i][j]!=0)
//             {
//                 int k,count=0;
//                 for(k=i+1;k<m && A[k][j]>=A[i][j];k++)
//                 {
//                     count++;
//                 }
//                 ans=max(ans,max(A[i][j]*A[i][j],A[i][j]*(A[i][j]+count)));

//                 int k1,count1=0;
//                 for(k1=j+1;k1<n && A[i][k1]>=A[i][j];k1++)
//                 {
//                     count1++;
//                 }

//                 ans=max(ans,max(A[i][j]*A[i][j],A[i][j]*(A[i][j]+count1)));
//             }
//         }
//     }
    
//     return ans;
    
// }
