class Solution {
public:
    
    struct Node {
        
        Node* left = NULL;
        Node* right = NULL;
        int ind = -1;
    };
    
    Node* root;
    int final_ans;
    
    // method to insert in trie from most significant bit to least
    void insert(int n,int index) {
        
        Node* ptr = root;
        ptr->ind=index;
        
        for(int i=31;i>=0;i--) {
            int bit = (n >> i) & 1;
            if(bit) {
                if(ptr->right) {
                    ptr=ptr->right;
                } else {
                    Node* newN = new Node;
                    ptr->right = newN;
                    ptr = newN;
                    ptr->ind=index;
                }
            } else {
                if(ptr->left) {
                    ptr=ptr->left;
                } else {
                    Node* newN = new Node;
                    ptr->left = newN;
                    ptr = newN;
                    ptr->ind=index;
                }
            }
        }
        ptr->ind=index;
    }
    
    // method to scan trie and find max xor index..max xor is with number that differs as early as possible because we have stored from MSB to LSB
    int maxXorIndex(int n) {
        
        Node* ptr = root;
        
        for(int i=31;i>=0;i--) {
            int bit = (n >> i) & 1;
            if(bit) {
                if(ptr->left) {
                    ptr=ptr->left;
                } else {
                    ptr=ptr->right;
                }
            } else {
                if(ptr->right) {
                    ptr=ptr->right;
                } else {
                    ptr=ptr->left;
                }
            }
        }
        return ptr->ind;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        ios::sync_with_stdio(0);
	    cin.tie(0);
        
        root = new Node;
        final_ans=0;
        insert(nums[0],0); // insert first number
        for(int i=1;i<nums.size();i++) {
            int maxi = maxXorIndex(nums[i]); // get index maxi < i that have max xor with i
            int ans = nums[maxi]^nums[i];
            if(ans>final_ans) final_ans=ans;
            insert(nums[i],i); // insert this number to trie
        }
        return final_ans;
    }
};
