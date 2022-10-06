#include<bits/stdc++.h>
class TimeMap {
public:
   unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap()
    {
        mp.clear();
    }
    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp)
    {
        if (mp[key].size() == 0)
            return "";
        int low = 0;
        int n = mp[key].size();
        int high = n - 1;
        int mid = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mp[key][mid].first <= timestamp)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (low == 0)
            return "";
        return mp[key][low - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */