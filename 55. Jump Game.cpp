class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxCanReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxCanReach < i) {
                return false;
            }
            maxCanReach = max (maxCanReach, i + nums[i]);
        }
        return true;
    }
};
