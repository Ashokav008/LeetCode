#include<bits/stdc++.h>
class TimeMap {
public:
   map<string, vector<pair<int, string>>> mp;
    TimeMap()
    {
        mp.clear();
    }
    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
        // Storage is a hasmap storing timestamp and value as vector of pairs
        // against a timestamp
    }
    string get(string key, int timestamp)
    {
        if (mp[key].size() == 0)
            return "";
        // If for that key no such pair is available then we cannot get
        // any value
        int n = mp[key].size();
        // If there is vector of pairs then there will be size also
        int low = 0;
        int high = n - 1;
        int mid = -1;
        // We are using binary search to find the value pair <= timestamp
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