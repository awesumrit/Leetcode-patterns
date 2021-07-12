namespace { 
static auto _speedupMagic = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
}

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int s = nums.size();
        for (int i = 0; i < s; ++i){
            int n = nums[i];
            while (n > 0 && n <= s && nums[n - 1] != n){
                    swap(n, nums[n - 1]);
            }
        }
        for (int i = 0; i < s; ++i)
        if (nums[i] != i + 1) return i + 1;
        return s + 1;
    }
};
