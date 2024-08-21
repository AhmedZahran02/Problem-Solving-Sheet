class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0 ;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5) {
                five++;
            }
            else if (bills[i] == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            }
            else if (bills[i] == 20) {
                if (!((five > 2) || (five > 0 && ten > 0))) {
                    return false;
                }
                if (ten > 0) {
                    ten--;
                    five--;
                }
                else {
                    five-=3;
                }
            }
        }
        return true;
    }
};