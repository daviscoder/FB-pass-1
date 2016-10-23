// O(n), O(number of distinct tasks)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    int taskFinishTime (string tasks, int interval) {
        int result = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < tasks.size(); i++) {
            char current = tasks[i];
            if (m.count(current)) {
                result = max(result, m[current]) + 1;
            }
            else {
                result++;
            }
            m[current] = result + interval;
        }
        return result;
    }
};

int main () {
    string str = "aabbccabc";
    Solution s;
    cout << s.taskFinishTime (str, 2);
    return 0;
}
