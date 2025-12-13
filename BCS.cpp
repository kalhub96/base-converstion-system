#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include<algorithm>
using namespace std;

/* Convert character to numeric value */
int valueOf(char c) {
    if (isdigit(c)) return c - '0';
    return toupper(c) - 'A' + 10;
}

/* Convert numeric value to character */
char digitOf(int v) {
    if (v < 10) return char(v + '0');
    return char(v - 10 + 'A');
}

/* Validate base */
bool validBase(int base) {
    return base >= 2 && base <= 36;
}

/* Validate number format */
bool validNumber(const string& num, int base) {
    int dotCount = 0;
    for (char c : num) {
        if (c == '.') {
             dotCount++;
            if (dotCount > 1) return false;
        } else {
            if (valueOf(c) >= base) return false;
        }
    }
    return true;
}

/* Convert integer part to decimal */
double integerToDecimal(const string& intPart, int base) {
    double result = 0;
    for (char c : intPart) {
        result = result * base + valueOf(c);
    }
    return result;
}

/* Convert fractional part to decimal */
double fractionToDecimal(const string& fracPart, int base) {
    double result = 0;
    double power = base;
    for (char c : fracPart) {
        result += valueOf(c) / power;
        power *= base;
    }
    return result;
}

/* Convert decimal integer part to target base */
string decimalIntegerToBase(double decimal, int base) {
    long long integer = (long long)decimal;
    if (integer == 0) return "0";

    string result = "";
    while (integer > 0) {
        int rem = integer % base;
        result = digitOf(rem) + result;
        integer /= base;
    }
    return result;
}

/* Convert decimal fraction part to target base */
string decimalFractionToBase(double decimal, int base, int precision) {
    double fraction = decimal - floor(decimal);
    string result = "";

    while (fraction > 0 && precision-- > 0) {
        fraction *= base;
        int digit = (int)fraction;
        result += digitOf(digit);
        fraction -= digit;
    }
    return result;
}

/* Main */
int main() {
    string number;
    int baseFrom, baseTo, precision;

    cout << "Enter number: ";
    cin >> number;

    cout << "Enter source base: ";
    cin >> baseFrom;

    cout << "Enter target base: ";
    cin >> baseTo;

    cout << "Enter fraction precision: ";
    cin >> precision;

    if (!validBase(baseFrom) || !validBase(baseTo)) {
        cout << "Error: Invalid base\n";
        return 0;
    }

    if (!validNumber(number, baseFrom)) {
        cout << "Error: Invalid number for given base\n";
        return 0;
    }

    // Split number
    string intPart, fracPart;
    size_t dotPos = number.find('.');

    bool hasFraction = (dotPos != string::npos);

    if (hasFraction) {
        intPart = number.substr(0, dotPos);
        fracPart = number.substr(dotPos + 1);
        if (intPart.empty() || fracPart.empty()) {
            cout << "Error: Invalid fractional format\n";
            return 0;
        }
    } else {
        intPart = number;
    }

    // Convert to decimal
    double decimalValue = integerToDecimal(intPart, baseFrom);
    if (hasFraction) {
        decimalValue += fractionToDecimal(fracPart, baseFrom);
    }

    // Convert to target base
    string resultInt = decimalIntegerToBase(decimalValue, baseTo);

    cout << "Result: ";
    if (hasFraction) {
        string resultFrac = decimalFractionToBase(decimalValue, baseTo, precision);
        cout << resultInt << "." << resultFrac << endl;
    } else {
        cout << resultInt << endl;
    }

    return 0;
}
