// minHeap. O(log(k)*n), O(k).

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < nums.size(); i++) {
            if (minHeap.size() < k) {
                minHeap.push(nums[i]);
                continue;
            }
            if (minHeap.top() < nums[i]) {
                minHeap.push(nums[i]);
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

// quick select
// O(n), worst O(n^2)
class Solution {
public:
    int partition (vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap (nums[l], nums[r]);
                l++;
                r--;
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap (nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) {
                return nums[pos];
            }
            else if (pos < k - 1) {
                left = pos + 1;
            }
            else {
                right = pos - 1;
            }
        }
        return 0;
    }
};
