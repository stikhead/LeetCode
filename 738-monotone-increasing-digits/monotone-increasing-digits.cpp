class Solution {
public:

    void bt(long long&ans, int n, long long &input){
        if(input<=n){
            ans = max(ans, input);
        }
        if(input>n){
            return;
        }
        for(long long i=input%10; i<=9; i++){
            if(input == 0 && i == 0) continue;
            if(i>=input%10){
                input = (input*10)+i;
            bt(ans, n, input);
            input = input/10;
            }
        }
    }
    int monotoneIncreasingDigits(int n) {
        long long ans = 0;
        long long op = 0;
        bt(ans, n, op);
        return ans;
    }
};