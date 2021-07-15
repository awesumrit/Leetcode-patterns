// class Solution {
//     vector<int> fenwick;
//     void add(int i, int val) { for(; i < fenwick.size(); i += i&-i)      fenwick[i] += val; }
//     void sum(int i, int &o)  { for(; i;                  i -= i&-i) o += fenwick[i];        }
// public:
//     int countRangeSum(vector<int>& nums, int lower, int upper) {
//         int n = nums.size();
//         fenwick.resize(n+1);
        
//         vector<long> prefix = {nums[0]};
//         for(int i = 1; i < n; i++) prefix.push_back( prefix[i-1] + nums[i] );
        
//         vector<pair<long,int>> sorted;
//         for(int i=0;i<n;i++)sorted.push_back({prefix[i],i+1});
//         sort(sorted.begin(),sorted.end(),[](auto&x,auto&y){return x.first<y.first;});

//         int L = 0, U = 0, count = 0;
//         for(int i = 0; i < n; i++)
//         {
//             long prefix = sorted[i].first; if(prefix>=lower&&prefix<=upper) count++;
//             long hi = prefix - lower;
//             long lo = prefix - upper;
//             while( U < n && sorted[U].first <= hi ) add( sorted[U++].second,  1 );
//             while( L < n && sorted[L].first <  lo ) add( sorted[L++].second, -1 );
//             sum( sorted[i].second-1, count );
//         }
//         return count;
//     }
// };


class Solution {

    int diviAndCon(vector<long>& nums, int lower, int upper, int l, int r) {
        if (r - l <= 1) return 0;
        int mid = (l+r)/2;
        int count = diviAndCon(nums, lower, upper, l, mid) + diviAndCon(nums, lower, upper, mid, r);
        int n = mid, m = mid;
        for (int i = l; i < mid; i++) {
            while (n < r && nums[n] - nums[i] < lower) n++;
            while (m < r && nums[m] - nums[i] <= upper) m++;
            count += m - n;
        }

        inplace_merge(nums.begin() + l, nums.begin() + mid, nums.begin() + r);
        return count;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size()+1, 0)
        for (int i = 0; i < nums.size(); i++) sums[i+1] = sums[i] + nums[i];

        return diviAndCon(sums, lower, upper, 0, nums.size()+1);
    }
};
