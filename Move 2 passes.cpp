#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    void move2pass (vector<int>& nums) {
        // move 1 to the end.
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        int end = idx;
        for (; idx < nums.size(); idx++) {
            nums[idx] = 1;
        }
        
        // move 0 to the front
        idx = end - 1;
        for (int i = end - 1; i >= 0; i--) {
            if (nums[i] != 0) {
                nums[idx] = nums[i];
                idx--;
            }
        }
        for (; idx >= 0; idx--) {
            nums[idx] = 0;
        }
    }
};

int main () {
    int p[] = {0, 0, 0, 1, 1, 2, 1, 0, 3, 4, 1, 1, 0};
    vector<int> v (p, p + sizeof (p) / sizeof(int));
//    cout << v.size();
    Solution s;
    s.move2pass (v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
    return 0;
}
