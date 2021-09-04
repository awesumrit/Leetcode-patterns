class Solution {
public:
    // pick k numbers from vector num
    vector<int> select(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> res(k, INT_MIN);
        for(int i = 0, j = 0;i<nums.size();i++){
            int x = nums[i];
            // monotonic stack
            while(j>0&&x > res[j-1]&&i+k-j<n) j--;
            if(j<k) res[j++] = x;
        }
        return res;
    }
    vector<int> merge(vector<int>& a, vector<int> &b){
        vector<int> c;
        int i=0, j=0;
        while(a.size()&&b.size()){
        // while(i<a.size() && j<b.size()){
            if(a > b)
                c.push_back(a[0]), a.erase(a.begin());
            // if(a[i] > b[j])
            //     c.push_back(a[i++]);
            else
                c.push_back(b[0]), b.erase(b.begin());
                // c.push_back(b[j++]);
        }
        while(a.size())
            c.push_back(a[0]), a.erase(a.begin());
        while(b.size())
            c.push_back(b[0]), b.erase(b.begin());
        return c;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, INT_MIN);
        int n = nums1.size(), m = nums2.size();

        // for(int i = max(0, k-m);i<=min(k, n);i++){
        for(int i = 0;i<=k;i++){
            if(i>n || k-i>m)
                continue;
            vector<int> a = select(nums1, i);
            vector<int> b = select(nums2, k - i);
            res = max(res, merge(a, b));
        }
        return res;
    }
};




// class Solution {
// public:
//     vector<int> getMaxArray(vector<int>& nums, int k){
//         vector<int> ans;
//         int len = nums.size();
//         for(int i = 0, j = 0; i < len; ++i){
//             while(j > 0 && len - i + j > k && ans[j - 1] < nums[i]){
//                 ans.pop_back();
//                 --j;
//             }
//             if(j < k){
//                 ans.push_back(nums[i]);
//                 ++j;
//             }
//         }
//         return ans;
//     }
//     bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j){
//         int len1 = nums1.size();
//         int len2 = nums2.size();
//         while(i < len1 && j < len2 && nums1[i] == nums2[j]){
//             ++i;
//             ++j;
//         }
//         if(j == len2 || (i < len1 && nums1[i] > nums2[j])){
//             return true;
//         }
//         return false;
//     }
//     vector<int> merge(vector<int>& nums1, vector<int>& nums2){
//         int len1 = nums1.size();
//         int len2 = nums2.size();
//         vector<int> ans;
//         for(int i = 0, j = 0, m = 0;i < len1 || j < len2;){
//             ans.push_back((greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++]));
//         }
//         return ans;
//     }
//     vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//         int len1 = nums1.size();
//         int len2 = nums2.size();
//         if(len1 < len2){
//             return maxNumber(nums2, nums1, k);
//         }
//         vector<int> ans;
//         for(int i = max(0, k - len1); i <= min(k, len2); ++i){
//             vector<int> c2 = getMaxArray(nums2, i);
//             vector<int> c1 = getMaxArray(nums1, k - i);
//             vector<int> c = merge(c1, c2);
//             if(ans.empty() || greater(c, 0, ans, 0)){
//                 ans = c;
//             }
//         }
//         return ans;
//     }
// };
