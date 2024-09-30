#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int k =0;
        int n = word.size();
        for(int i = 0;i<n;i++){
            if(word[i]==ch){
                k=i;
                break;
            }
        }
        if(k==0){
            return word;
        }
        int i =0;
        int j =k;
        while(i<=j){
            swap(word[i],word[j]);
            j--;
            i++;
        }
        return word;
    }
};