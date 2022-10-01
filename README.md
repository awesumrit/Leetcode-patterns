# Leetcode-patterns
The solutions to leetcode patterns problems

### Max Rectangle in Binary Matrix

Use largest rectangle in histogram as black box, now add values of prev rows ones to current rows ones and then calculate max area with that vector height of histograms
For hist, use left_min and right_min with the help of stack for each index and calculate area as (right_min - left_min -1)*height[i]
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

### Smallest Range Covering Elements from K Lists

Use priority queue:

	Initialize next array(pointers) with all 0's.

	Find the indices of the lists containing the minimum(min_i) and the maximum(max_i) elements amongst the elements pointed by the nextnext array. Use min-heap to get the min value. Directly compare the updated min value with the last maximum value to determine the current maximum value.

	If the range formed by the maximum and minimum elements found above is larger than the previous maximum range, update the boundary values used for the maximum range.

	Increment the pointer nums[min_i]nums[min_i].

	Repeat steps 2 to 4 till any of the lists gets exhausted.

### Count of Range Sum

Divide and Conquer. The merge sort based solution counts the answer while doing the merge. During the merge stage, we have already sorted the left half [start, mid) and right half [mid, end). We then iterate through the left half with index i. For each i, we need to find two indices k and j in the right half where

	j is the first index satisfy sums[j] - sums[i] > upper and
	k is the first index satisfy sums[k] - sums[i] >= lower
	
Then the number of sums in [lower, upper] is j-k.

### Sliding Window Maximum

Use dequeue.
check if back element of deque is less than current element, if then pop the back element and do it as long as it is true cause we want to store only potential max elements in the deque. Push front in to result vector as soon as current sliding window end is reached. Pop front element from the deque if its position is outside the next sliding window

### Count Unique Characters of All Substrings of a Given String

Use the formula - prev = prev + i + occur[s[i] - 'A'][0] - 2*occur[s[i] - 'A'][1] for i in range(1,n); occur[i] -> last 2 occurences of character i + 'A' 

ans += prev; and initially occur[s[0] - 'A'][1] = 0; all others -1

### Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/solution/
From O(n), O(n) sol to O(n), O(1)

### Prefix and Suffix Search

Trie of Suffix Wrapped Words -  insert '#apple', 'e#apple', 'le#apple', 'ple#apple', 'pple#apple', 'apple#apple' into the trie. Then for a query like prefix = "ap", suffix = "le", we can find it by querying our trie for le#ap


### Maximum Frequency Stack

Make stack of stacks and push each element with the current frequency, while popping, decrease frequency and clear stack if size is 0.

### Substring with Concatenation of All Words

Sliding window approach

### Course Schedule III

Sort by custom comparator with ascending order of completion deadline and then push durations to the priority queue, pop if duration is larger than pq.top()

### Word Search II

Trie and DFS based solution.

### Largest Rectangle in Histogram

Compute left_min and right_min arrays using stack, then find max value of (right_min - left_min - 1)*height

### Minimum Window Substring

Store and reduce the count in map, when remaining values are 0 then find the minimum and increase map[left], if it becomes > 0, then increase remaining

### Reducing Dishes

Sort in the reverse order, then compute prefix sum and prefix sum of prefix sum, which will take into account i*num[i], hence O(n) sol

### Maximum Profit in Job Scheduling

Store start time with positive values and end time with negative, making pair with their index in the array, sort by absolute value, keeping end time first if it is equal to some start time. Iterate and add max value if found start of some before end, else update max value.

### Create Maximum Number

Make Sure to compare the vectors directly while merging and taking max, use Monotonic stack, for all values from 0 to k, find the best max subset of i and k-i from both the arrays, merge them and take max of result

### MEDIUM

### Longest Palindromic Subsequence

// Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 


### Gray code

Use bit manipulation, n ^ (n>>1) produces adjacent nums that differ only in 1 bit

### Sum of Subarray Minimums

Compute index of first left min and right min for each ele using stack approach, this gives the count of no of times that element will be added, which is left[i]*right[i]*arr[i], add all, O(3n) sol

### Redundant Connection

Use union find by rank algo and if parent of src and dest of an edge are equal, then return that edge

### Evaluate Division

Use BFS based apprach and pairs in queue

### Topological Sort (Course Schedule)

Use BFS, push 0 indegree nodes initially and then pop from queue and decrease adj nodes' indegree, push if it becomes 0, cnt number of times elements are popped from the queue, if it is not equal to the number of nodes in the graph, then there exists a cycle, otherwise each pop should be pushed to the ans and return

### Add all greater values to every node in a given BST

Use pointer for storing sum and as argument of helper function and to traverse the BST in descending order we use reverse in-order traversal of BST. This takes a global variable sum which is updated at every node and once the root node is reached it is added to the value of root node and value of the root node is updated.

### Meet in the middle

Partition Array Into Two Arrays to Minimize Sum Differenc. Arbitrarily divide nums into two halves (two arrays). For both halves, pre-calculate a 2D array where the kth index will store all possible sum values if only k elements from this half are added. For each sum of k elements in the first half, find the best sum of n-k elements in the second half such that the two sums add up to a value closest to the target sum from hint 1. These two subsets will form one array of the partition.
Use binary search and compare the closenes of the sum val in right array (lower_bound iterator and the ele just before that) to the sum val in left array 
