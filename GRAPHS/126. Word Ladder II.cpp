#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(string word, vector<string> &cur,
             vector<vector<string>> &ans, map<string, int> &mp,
             unordered_set<string> &s, string &beginWord)
    {
        cur.push_back(word);
        if (word == beginWord)
        {
            reverse(cur.begin(), cur.end());
            ans.push_back(cur);
            reverse(cur.begin(), cur.end());
            cur.pop_back();
            return;
        }
        int curLevel = mp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (s.find(word) != s.end() && mp[word] == curLevel - 1)
                {
                    dfs(word, cur, ans, mp, s, beginWord);
                }
            }
            word[i] = original;
        }
        cur.pop_back();
    }
    map<string, int> returnWordLevel(string &beginWord, string &endWord,
                                     unordered_set<string> s)
    {
        map<string, int> mp;
        queue<string> q;
        int level = 1;
        q.push({beginWord});
        mp[beginWord] = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.size(); i++)
                {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if (s.find(word) != s.end())
                        {
                            q.push(word);
                            mp[word] = level;
                            if (s.find(word) != s.end())
                                s.erase(word);
                            if (word == endWord)
                                return mp;
                        }
                    }
                    word[i] = original;
                }
            }
            level++;
        }
        return mp;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> s(wordList.begin(), wordList.end());
        if (s.find(beginWord) != s.end())
            s.erase(beginWord);
        map<string, int> mp = returnWordLevel(beginWord, endWord, s);
        vector<string> cur;
        s.insert(beginWord);
        dfs(endWord, cur, ans, mp, s, beginWord);
        return ans;
    }
};