class Solution {
public:
    int totalFruit(vector<int>& tree) {
        
        int left = 0, right = 0, res = 0, n = tree.size();
        unordered_map<int, int>map;
        
        while(right < n)
        {
            map[tree[right]]++;  // continue to expand right window until map size is 2
            
            while(map.size() > 2){ // now start to close left window to reach size 2
                map[tree[left]]--;
                if(map[tree[left]] == 0) map.erase(tree[left]);
                left++;
            }
            
            res = max(res, right-left+1); 
            right++;
        }
        return res;
    }
};
