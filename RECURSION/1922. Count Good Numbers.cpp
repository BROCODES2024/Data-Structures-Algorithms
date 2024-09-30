#define mod 1000000007
class Solution {
public:
    long long pow(long long x,long long n){
        if(n==0){
            return 1;
        }
        long long nn = n;
        long long ans = 1;
        while(nn){
            if(nn%2==1){
                ans = (ans*x)%mod;
                nn=nn-1;
            }
            else{
                x=(x*x)%mod;
                nn=nn/2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2+n%2;
        long long val = (pow(5,even)*pow(4,odd))%mod;
        return val;
    }
};