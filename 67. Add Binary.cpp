// O(max (sizeof(a), sizeof(b)), O(max (sizeof(a), sizeof(b))

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "") {
            return b;
        }
        else if (b == "") {
            return a;
        }
        reverse (a.begin(), a.end());
        reverse (b.begin(), b.end());
        int carry = 0;
        string result = "";
        for (int i = 0; i < a.size() || i < b.size() || carry; i++) {
            carry += i < a.size()? a[i] - '0' : 0;
            carry += i < b.size()? b[i] - '0' : 0;
            result += to_string (carry % 2);
            carry /= 2;
        }
        if (carry) {
            result += to_string (carry);
        }
        reverse (result.begin(), result.end());
        return result;
    }
};
