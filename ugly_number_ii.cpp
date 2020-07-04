class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        int i=0;
        int j=0;
        int k=0;
        ugly.push_back(1);
        for(;ugly.size()<n;){
            int temp1 = ugly[i]*2;
            int temp2 = ugly[j]*3;
            int temp3 = ugly[k]*5;
            int mn = min(temp1, min(temp2,temp3));
            ugly.push_back(mn);
            if(mn==temp1)
                i++;
            if(mn==temp2)
                j++;
            if(mn==temp3)
                k++;
        }
        return ugly.back();
        
    }
};
