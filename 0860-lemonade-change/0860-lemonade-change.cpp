class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] == 10 || bills[0] == 20) {
            return false;
        }
        int five = 0;
        int ten = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            }

           else if (bills[i] == 10) {
                if (five <= 0) {
                    return false;
                }
                five--;
                ten++;
            }

            else {
                if (five >= 1 && ten >= 1) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};