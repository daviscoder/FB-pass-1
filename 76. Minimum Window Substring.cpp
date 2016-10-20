// O(n), O(128)

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map (128, 0);
        for (int i = 0; i < t.size(); i++) {
            map[t[i]]++;
        }
        int start = 0, length = INT_MAX, head = 0, count = t.size();
        for (int end = 0; end < s.size(); end++) {
            if (map[s[end]] > 0) {
                count--;
            }
            map[s[end]]--;
            while (count == 0) {
                if (end - start + 1 < length) {
                    head = start;
                    length = end - start + 1;
                }
                if (map[s[start]] == 0) {
                    count++;
                }
                map[s[start]]++;
                start++;
            }
        }
        return length == INT_MAX? "" : s.substr(head, length);
    }
};
