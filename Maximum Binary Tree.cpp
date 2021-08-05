class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createTree(nums, 0, nums.size()-1);
    }
    
    
    TreeNode* createTree(vector<int> nums, int start, int end) {
        if(start < 0 || end >= nums.size() || start > end) return nullptr;
        int ind = start; int tmpMax = 0;
        for(int i=start; i<=end; i++) {
            if(tmpMax <  nums[i]) {
                tmpMax = nums[i];
                ind = i;
            }
        }
        TreeNode* tn = new TreeNode(tmpMax);
        tn->left = createTree(nums, start,ind-1); 
        tn->right = createTree(nums, ind+1, end);
        return tn;
    }
};
