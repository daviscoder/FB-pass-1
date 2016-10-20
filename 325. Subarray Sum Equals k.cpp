// returns all possible index.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<pair<int, int> > maxSubArray(vector<int>& nums, int k) {
        unordered_map <int, vector<int>> myMap;
        int sum = 0;
        vector<pair<int, int> > result;
        myMap[0] = vector<int> (1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int lookfor = sum - k;  // k + myMap[lookfor] == sum.
            if (myMap.count(lookfor)) {
                for (int j = 0; j < myMap[lookfor].size(); j++) {
                    result.push_back ({myMap[lookfor][j], i});
                }
            }
            if (myMap.count(sum) == 0) {
                myMap[sum] = vector<int> (1, i + 1);
//                myMap[sum] = i + 1;  // Note: it is i + 1 instead of i.
            }
            else {
                myMap[sum].push_back (i + 1);
            }
        }
        return result;
    }
};

int main () {
    vector<int> nums;
    nums.push_back (1);
    nums.push_back (-1);
    nums.push_back (5);
    nums.push_back (-2);
    nums.push_back (3);
    Solution s;
    vector<pair<int, int> > res = s.maxSubArray(nums, 3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << "\t" << res[i].second << endl;
    }
    return 0;
}
