class Solution {
public:
    char toLowerCase (char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && isalnum(s[i]) == false) {
                i++;
            }
            while (i < j && isalnum(s[j]) == false) {
                j--;
            }
            if (toLowerCase(s[i]) != toLowerCase(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
