#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string s) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s1.insert(s[i] - 'a');
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s2.insert(s[i] - 'A');
            }
        }
        int c = 0;
        for(int i = 0; i < 26; i++){
            if(s1.find(i) != s1.end() && s2.find(i) != s2.end()){
                c++;
            }
        }
        return c;
    }
};
