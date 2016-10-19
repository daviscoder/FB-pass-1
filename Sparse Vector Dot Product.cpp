// O(min (m, n)), O(1)

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int sparseVectorProduct (vector<pair<int, int> >& A, vector<pair<int, int> >& B) {
        int i = 0, j = 0, result = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i].first == B[j].first) {
                result += A[i].second * B[j].second;
                i++;
                j++;
            }
            else if (A[i].first < B[j].first) {
                i++;
            }
            else {
                j++;
            }
        }
        return result;
    }
};

int main () {
    vector<pair<int, int> > A;
    vector<pair<int, int> > B;
    A.push_back ({3, 1});
    A.push_back ({4, 2});
    A.push_back ({7, 3});
    A.push_back ({8, 4});

    B.push_back ({2, 1});
    B.push_back ({4, 2});
    B.push_back ({6, 3});
    B.push_back ({7, 4});
    B.push_back ({8, 5});

    Solution s;
    cout << s.sparseVectorProduct (A, B) << endl;
    return 0;
}
