/* 
we will be iterating from the last if we found spaces intially we continue and then if we found spaces in middle we return count
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]==' '&&cnt == 0){
                continue;
            }
            if(s[i]==' '&&cnt!=0){
                return cnt;
            }
            if(s[i]!=' '){
                cnt++;
            }
        }
        return cnt;
    }
};