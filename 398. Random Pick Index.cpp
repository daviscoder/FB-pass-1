//  Reservoir Sampling
// O(n), O(1)

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand(time(0));
    }
    
    int pick(int target) {
        int result = 0, count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (rand() % count == 0) {
                    result = i;
                    count++;
                }
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
