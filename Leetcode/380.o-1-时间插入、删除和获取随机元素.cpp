/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(time(NULL));
    }

    bool insert(int val)
    {
        if (indices.find(val) != indices.end())
        {
            return false;
        }
        else
        {
            indices.emplace(val, data.size());
            data.push_back(val);
            return true;
        }
    }

    bool remove(int val)
    {
        auto res = indices.find(val);
        if (res == indices.end())
        {
            return false;
        }
        else
        {
            int index = indices[val];
            data[index] = data.back();
            indices[data[index]] = index;
            data.pop_back();
            indices.erase(val);
            return true;
        }
    }

    int getRandom()
    {
        int index = rand() % data.size();
        return data[index];
    }

public:
    vector<int> data;
    unordered_map<int, int> indices;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
