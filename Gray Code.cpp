class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n);
        // const int size = 1 << n;
        // res.reserve(size);
        for(int i = 0; i < 1 << n; i++) {
            // res.emplace_back(binary_to_gray(i));
            res[i] = binary_to_gray(i);
        }
        return res;
    }
    unsigned int binary_to_gray(unsigned int n){
        return n ^ (n >> 1);
    }
};
