#include <bits/stdc++.h> 
class LFUCache
{

unordered_map<int, list<pair<int, int>>> cache;
unordered_map<int, pair<int, list<pair<int, int>> :: iterator>> mp;
int cap, min_freq;

public:
    LFUCache(int capacity)
    {
        // Write your code here.
        cap = capacity;
        min_freq = 0;
    }

    int get(int key)
    {
        // Write your code here.
        if(mp.find(key) == mp.end())
            return -1;
        auto it = mp[key].second;
        int val = (*it).second;
        put(key, val);
        return val;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(mp.find(key) != mp.end())
        {
            int freq = mp[key].first;
            auto it = mp[key].second;
            cache[freq].erase(it);
            if(min_freq == freq && cache[freq].empty())
                cache.erase(freq), min_freq++;
            cache[freq + 1].push_back({key, value});
            mp[key] = {freq + 1, --cache[freq + 1].end()};
            return;
        }
        if(mp.size() == cap)
        {
            auto least = cache[min_freq].begin();
            int k = (*least).first;
            cache[min_freq].erase(least);
            if(cache[min_freq].empty())
                cache.erase(min_freq);
            mp.erase(k);
        }
        min_freq = 1;
        cache[min_freq].push_back({key, value});
        mp[key] = {min_freq, --cache[min_freq].end()};
    }
};
