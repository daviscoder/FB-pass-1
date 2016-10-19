class Solution {
public:
    void dfs (string& digits, vector<string>& result, string& current, string keyboard[], int pos) {
        if (pos == digits.length()) {
            result.push_back(current);
            return;
        }
        string str = keyboard[digits[pos] - '0'];
        for (int i = 0; i < str.size(); i++) {
            current.push_back(str[i]);
            dfs (digits, result, current, keyboard, pos + 1);
            current.pop_back ();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string keyboard[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current = "";
        if (digits.size() == 0)
            return result;
        dfs (digits, result, current, keyboard, 0);
        return result;
    }
};
