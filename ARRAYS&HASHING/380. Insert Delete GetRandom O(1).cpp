#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
    unordered_map<int,int> mpp;
    vector<int>values;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val)==mpp.end()){
            values.push_back(val);
            mpp[val]=values.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mpp.find(val)==mpp.end()){
            return false;
        }
        int idx = mpp[val];
        int lastval = values[values.size()-1];
        mpp[lastval]=idx;
        values[idx]=lastval;
        values.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */