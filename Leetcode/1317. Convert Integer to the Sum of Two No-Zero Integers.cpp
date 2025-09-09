class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int firstNumber = 1;
        string firstNumberStr = to_string(firstNumber);
        string secondNumber = to_string(n-firstNumber);
        while (secondNumber.find('0') != string::npos || firstNumberStr.find('0') != string::npos){
            firstNumber++;
            firstNumberStr = to_string(firstNumber);
            secondNumber = to_string(n-firstNumber);
        }
        return {firstNumber,n-firstNumber};
    }
};