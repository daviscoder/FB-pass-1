// 1. From right to left, find the first digit (partition number) which violate the increase trend.
// 2. From right to left, find the first digit that is larger than the partition number, call it swap index.
// 3. swap the partition number and swap number.
// 4. reverse all digit on the right of the partition index.

// O(n), O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int pivot = nums.size() - 2, swapIdx = nums.size() - 1;
        for (; pivot >= 0; pivot--) {
            if (nums[pivot] < nums[pivot + 1]) {
                break;
            }
        }
        if (pivot >= 0) {
            for (; swapIdx > pivot; swapIdx--) {
                if (nums[swapIdx] > nums[pivot])
                    break;
            }
            swap (nums[swapIdx], nums[pivot]);
        }
        pivot++;
        reverse (nums.begin() + pivot, nums.end());
    }
};
