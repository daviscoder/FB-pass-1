// 需要一个哈希表来建立字符和其出现次数之间的映射，然后需要一个堆来保存这每一堆映射，按照出现次数来排序。然后如果堆不为空我们就开始循环，我们找出k和str长度之间的较小值，然后从0遍历到这个较小值，对于每个遍历到的值，如果此时堆为空了，说明此位置没法填入字符了，返回空字符串，否则我们从堆顶取出一对映射，然后把字母加入结果res中，此时映射的个数减1，如果减1后的个数仍大于0，则我们将此映射加入临时集合v中，同时str的个数len减1，遍历完一次，我们把临时集合中的映射对由加入堆中

// O(n * log (size of distinct alphabets)

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) {
            return str;
        }
        string result;
        map<char, int> frequency;
        int length = str.size();
        for (int i = 0; i < str.size(); i++) {
            frequency[str[i]]++;
        }
        priority_queue<pair<int, char> > maxHeap;
        for (auto it = frequency.begin(); it != frequency.end(); it++) {
            maxHeap.push({it->second, it->first});
        }
        while (maxHeap.empty() == false) {
            vector<pair<int, char> > v;
            int cnt = min (length, k);
            for (int i = 0; i < cnt; i++) {
                if (maxHeap.empty()) {
                    return "";
                }
                auto tmp = maxHeap.top();
                maxHeap.pop();
                result += tmp.second;
                if (tmp.first > 1) {
                    tmp.first--;
                    v.push_back(tmp);
                }
                length--;
            }
            for (int i = 0; i < v.size(); i++) {
                maxHeap.push(v[i]);
            }
        }
        return result;
    }
};
