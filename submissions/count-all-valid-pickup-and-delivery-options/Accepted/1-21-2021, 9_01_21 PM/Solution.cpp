// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

#define MOD 1000000007
class Solution {
public:
    int countOrders(int n) {
        long i, curr_res = 1;
        
        for(i = 2; i <= n; i++) {
            // i*(2i-1)
            curr_res = ((curr_res * i)%MOD * ((2*i)%MOD - 1)%MOD)%MOD;
        }
        
        return curr_res;
    }
};