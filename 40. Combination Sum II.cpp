// O(2^n) * k?

class Solution {
public:
    void dfs (vector<int>& candidates, vector<int>& current, vector<vector<int>>& result, int target, int start) {
        if (target < 0) {
            return;
        }
        else if (target == 0) {
            result.push_back(current);
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i != start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            current.push_back(candidates[i]);
            dfs(candidates, current, result, target - candidates[i], i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, current, result, target, 0);
        return result;
    }
};
