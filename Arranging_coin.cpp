class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(2*(long long)n + .25) - .50);
    }
};
