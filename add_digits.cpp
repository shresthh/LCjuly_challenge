class Solution {
public:

    int addDigits(int num) {
        //Input: 38 
        //Output: 2 
        while (num > 9){
            int sum = 0;
            while(num > 0){
                int rem = num % 10;
                sum += rem;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
