#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> stt(wordList.begin(), wordList.end());
        stt.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int num = q.front().second; // Correct type
            q.pop();

            if (word == endWord)
            {
                return num;
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (word[i] == original)
                    {
                        continue;
                    }

                    if (stt.find(word) != stt.end())
                    { // Correct variable name
                        stt.erase(word);
                        q.push({word, num + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};