// time: O(n)
// space: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0; // index for the next written element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        for (; idx < nums.size(); idx++) {
            nums[idx] = 0;
        }
    }
};
