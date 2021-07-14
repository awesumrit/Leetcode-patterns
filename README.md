# Leetcode-patterns
The solutions to leetcode patterns problems

### Maximum Product Subarray

Enhanced Kadane's sol - Swap the max and min prod values when you encounter negative values

### Pacific Atlantic Water Flow

Simple dfs solution. Iterate for all left, right, top and bottom sides

### Course Schedule 2

Bfs based solution. Push courses with indegree 0 (no prerequisites) to the queue. Pop from queue and reduce indegree of each course which had that prerequisite until the queue is empty. If num operations of pop on the queue is equal to number of courses then there is no cycle and courses can be done, else not.


### Number of Longest Increasing Subsequence (LIS)

NlogN sol - Create a List of List of Pairs, vector<vector< pair<int,int> >> LISbylen(N+1); in which we store the ( count of LIS end at current element, and the current element ). Suppose the current element is 4 and lower_bound gives us 3, that mean LIS of length 3 can be formed by ending at 4. To get count, We know that we can place 4 after any of the LIS of length 2 that end with an element smaller than 4. So to get the count we can add up the counts of LIS of len-1 where the last element is smaller than current element.

### Kth smallest element in a matrix

From left-bottom or right-top, count how many numbers (ele) are less than or equal to mid, if ele < k, then low = mid + 1, else high = mid

### Maximum XOR of Two Numbers in an Array

Use trie. Scan trie and find max xor index... max xor is with number that differs as early as possible because we have stored from MSB to LSB
