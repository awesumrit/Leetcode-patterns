class Solution {
public:
    vector<vector<int>> ans;
    void makesum(vector<int>& v,int tar,vector<int> &temp,int idx){
        if(tar<0){
            return;
        }
        else if(tar==0){
            ans.emplace_back(temp);
            return;
        }
        
        for(int i=idx;i<v.size();i++){
            if(i>idx && v[i]==v[i-1]) continue;
            temp.emplace_back(v[i]);
            makesum(v,tar-v[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        makesum(candidates,target,temp,0);
        return ans;
    }
};
