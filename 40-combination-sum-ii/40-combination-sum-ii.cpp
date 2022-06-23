class Solution {
    void helper(vector<vector<int>> &res, vector<int> &candidates, vector<int> &cur, int tar, int idx , bool lastTaken){
        if(tar == 0){
            res.push_back(cur);
            return;
        }
        
        if(idx >= candidates.size() || tar<0){
            return;
        }
        
        if(lastTaken || (candidates[idx] != candidates[idx - 1])){
            cur.push_back(candidates[idx]);
            helper(res, candidates, cur, tar - candidates[idx], idx + 1, true);
            cur.pop_back();
        }
        
        helper(res, candidates, cur, tar, idx + 1, false);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        helper(res, candidates, cur, target, 0, 1);
        return res;
    }
};