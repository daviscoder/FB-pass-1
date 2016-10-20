class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map <int, int> myMap;
        int sum = 0, result = 0;
        myMap[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int lookfor = sum - k;  // k + myMap[lookfor] == sum.
            if (myMap.count(lookfor)) {
                result = max(result, i - myMap[lookfor] + 1);
            }
            if (myMap.count(sum) == 0) {
                myMap[sum] = i + 1;  // Note: it is i + 1 instead of i.
            }
        }
        return result;
    }
};
