class Solution {
public:
    int mySqrt(int n) {
        if(n==0 || n==1) return n;
        double x = n;
        int itrations=50;
        for (int i = 0; i < itrations; i++) {
            x = (x + n / x) / 2.0;
        }
        
        return int(x);
    }
};