# Leetcode-patterns
The solutions to leetcode patterns problems

### Maximum Product Subarray

Enhanced Kadane's sol - Swap the max and min prod values when you encounter negative values

### Pacific Atlantic Water Flow

Simple dfs solution. Iterate for all left, right, top and bottom sides

### Course Schedule 2

Bfs based solution. Push courses with indegree 0 (no prerequisites) to the queue. Pop from queue and reduce indegree of each course which had that prerequisite until the queue is empty. If num operations of pop on the queue is equal to number of courses then there is no cycle and courses can be done, else not.
