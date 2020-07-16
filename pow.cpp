class Solution {
    double rec(double x, long n){
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n < 0)
            return rec(1/x, -n);
        double answer = rec(x*x , n/2);
        if(n&1)
            answer *= x;
        return answer;
    }
public:
    double myPow(double x, int n) {
        return rec(x, n);
        
    }
};
