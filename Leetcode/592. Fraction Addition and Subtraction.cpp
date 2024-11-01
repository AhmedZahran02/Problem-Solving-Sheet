typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:
    string fractionAddition(string expression) {
        vector<ll> nems;
        vector<ll> dems;
        ll commonDem = 1;
        // get list of nems and dems and get common dem
        ll start = 0;
        bool dem = 0;
        for (ll i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '/')
            {
                nems.push_back(stoi(expression.substr(start, i - start)));
                start = i + 1;
                dem = 1;
            }
            else if (dem && (expression[i] == '+' || expression[i] == '-'))
            {
                dems.push_back(stoi(expression.substr(start, i - start)));
                commonDem *= stoi(expression.substr(start, i - start));
                start = i;
                dem = 0;
            }
        }
        dems.push_back(stoi(expression.substr(start, expression.length() - start)));
        commonDem *= stoi(expression.substr(start, expression.length() - start));
        // edit the nems list to have common dem
        ll nemSum = 0;
        for (ll i = 0; i < nems.size(); i++)
        {
            nems[i] *= commonDem / dems[i];
            nemSum += nems[i];
        }
        // gcd(sum nems,common dem)
        ll x = gcd(nemSum, commonDem);
        // divide by gcd
        nemSum /= x;
        commonDem /= x;
        return to_string(nemSum)+'/'+to_string(commonDem);
    }
};