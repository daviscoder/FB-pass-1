// O(2^n)

class Solution {
public:
    void dfs (vector<int>& candidates, vector<int>& current, vector<vector<int>>& result, int start, int target) {
        if (target < 0) {
            return;
        }
        else if (target == 0) {
            result.push_back(current);
        }
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            dfs(candidates, current, result, i, target - candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, current, result, 0, target);
        return result;
    }
};
