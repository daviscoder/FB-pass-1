// 1. From right to left, find the first number that is larger than its next right number, call it pivot.
// 2. From right to left, find the first number that is smaller than pivot, call it swapNum.
// 3. Swap swapNum and pivot.
// 4. reverse all numbers from the pivot index + 1 to the end.

// O(n), O(1)

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        int pivot = nums.size() - 2, swapIdx = nums.size() - 1;
        for (; pivot >= 0; pivot--) {
            if (nums[pivot] > nums[pivot + 1]) {
                break;
            }
        }
        if (pivot >= 0) {  // a pivot is found.
            for (; swapIdx > pivot; swapIdx--) {
                if (nums[swapIdx] < nums[pivot]) {
                    break;
                }
            }
            swap(nums[swapIdx], nums[pivot]);
        }
        pivot++;
        reverse(nums.begin() + pivot, nums.end());
        return nums;
    }
};
