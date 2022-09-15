class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        

        if (arr.size() % 2) return {};
        int n =arr.size();
        multiset<int> s(begin(arr), end(arr));
        vector<int> ans;
        for (int i = 0; i < n; i += 2) {
            int ele = *s.begin();
            ans.push_back(ele);
            s.erase(s.begin());
            if (s.find(2 * ele) == s.end()) return {}; // Don't use `s.count(2 * n) == 0` here since it's an `O(N)` operation for `multiset`.
            s.erase(s.find(2 * ele));
        }
        return ans;
    }
};