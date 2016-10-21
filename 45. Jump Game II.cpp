// O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        int currentMaxJump = 0;
        int previousMaxJump = 0;
        int steps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            currentMaxJump = max (nums[i] + i, currentMaxJump);
            if (i == previousMaxJump) {
                steps++;
                previousMaxJump = currentMaxJump;
            }
        }
        return steps;
    }
};
