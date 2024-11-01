#define all(v) v.begin(),v.end()
typedef long long ll;

class Solution {
public:
    bool isPal(string& s) {
        string reversed = s;
        reverse(all(reversed));
        return s == reversed;
    }

    void AddOne(string& s,ll& index) {
        if (index < 0) {
            s = '0' + s;
            index++;
        }
        if (s[index]=='9')
        {
            index--;
            AddOne(s, index);
            s[index] = '0';
        }
        else {
            s[index] = s[index] + 1;
        }
        index++;
    }

    void SubOne(string& s, ll index) {
        if (s[index] == '0')
        {
            SubOne(s, index - 1);
            if (s[index - 1] == '0') {
                for (int i = index+1; i < s.length(); i++)
                {
                    s[i] = '9';
                }
            }
            s[index] = '9';
        }
        else {
            s[index] = s[index] - 1;
        }
    }

    void trimLeadingZeros(string& s) {
        size_t start = s.find_first_not_of('0');
        if (start == std::string::npos) {
            if (s.length() > 1)
            {
                s = "9";
            }
            return;
        }
        s =  s.substr(start);
    }

    ll getDiff(string& s1, string& s2) {
        string num1 = s1;
        string num2 = s2;
        if (num1.length() < num2.length() || (num1.length() == num2.length() && num1 < num2)) {
            std::swap(num1, num2);
        }

        ll len1 = num1.length();
        ll len2 = num2.length();
        ll carry = 0;
        ll result = 0;

        for (ll i = len1 - 1, j = len2 - 1; i >= 0; --i, --j) {
            ll digit1 = num1[i] - '0';
            ll digit2 = (j >= 0) ? (num2[j] - '0') : 0;

            ll sum = digit1 - digit2 + carry;
            if (sum < 0) {
                sum += 10;
                carry = -1;
            }
            else {
                carry = 0;
            }

            result += sum * static_cast<ll>(std::pow(10, len1 - i - 1));
        }

        return result;
    }

    void updatePal(string& s) {
        ll mid = s.length() / 2;
        int i = mid - 1;
        int j = mid + 1;
        if (s.length() % 2 == 0)
        {
            mid = s.length() / 2 - 1;
            i = mid;
            j = mid + 1;
        }

        while (i < s.length())
        {
            s[j] = s[i];
            i--;
            j++;
        }
    }

    void getNearestPal(string& s) {
        ll midIndex = s.length() / 2;
        if (s.length() % 2 == 0)
        {
            midIndex = s.length() / 2 - 1;
        }
        string smallerS = s;
        string normalS = s;
        string largerS = s;

        ll changableIndex = midIndex;
        AddOne(largerS, changableIndex);
        SubOne(smallerS, midIndex);

        string nonTrimmedsmallerS = smallerS;
        trimLeadingZeros(smallerS);
        trimLeadingZeros(normalS);
        trimLeadingZeros(largerS);

        updatePal(smallerS);
        updatePal(nonTrimmedsmallerS);
        updatePal(normalS);
        updatePal(largerS);

        trimLeadingZeros(nonTrimmedsmallerS);

        ll smallerdiff = getDiff(s, smallerS);
        ll nonTrimmedsmallerdiff = getDiff(s, nonTrimmedsmallerS);
        ll normaldiff = INT_MAX;
        if (!isPal(s))
        {
            normaldiff = getDiff(s, normalS);
        }
        ll largerdiff = getDiff(s, largerS);
        if (smallerdiff <= normaldiff && smallerdiff <= largerdiff && smallerdiff <= nonTrimmedsmallerdiff)
        {
            s = smallerS;
        }
        else if (nonTrimmedsmallerdiff <= smallerdiff && nonTrimmedsmallerdiff <= normaldiff && nonTrimmedsmallerdiff <= largerdiff)
        {
            s = nonTrimmedsmallerS;
        }
        else if (normaldiff <= smallerdiff && normaldiff <= nonTrimmedsmallerdiff && normaldiff <= largerdiff)
        {
            s = normalS;
        }
        else if (largerdiff <= normaldiff && largerdiff <= nonTrimmedsmallerdiff && largerdiff <= smallerdiff)
        {
            s = largerS;
        }
    }

    string nearestPalindromic(string n) {
        getNearestPal(n);
        return n;
    }
};