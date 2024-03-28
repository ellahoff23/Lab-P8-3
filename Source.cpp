#include <iostream>
#include <string>

using namespace std;


int romanCharValue(char r) {
    switch (r) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0; 
    }
}


int convertRomanToInt(string s) {
    int total = 0;
    int n = s.length();

    while (n > 0) {
        int firstVal = romanCharValue(s[0]);
        int secondVal = (n > 1) ? romanCharValue(s[1]) : 0;

        if (firstVal >= secondVal || n == 1) {
            total += firstVal;
            s.erase(0, 1);
        }
        else {
            total += (secondVal - firstVal);
            s.erase(0, 2); 
        }

        n = s.length();
    }

    return total;
}

int main() {

    cout << "Testing romanCharValue function:\n";
    cout << "Value of M: " << romanCharValue('M') << endl;
    cout << "Value of C: " << romanCharValue('C') << endl;
    cout << "Value of X: " << romanCharValue('X') << endl;
    cout << "Value of V: " << romanCharValue('V') << endl;
    cout << "Value of I: " << romanCharValue('I') << endl;

  
    string testRoman1 = "MCMLXXVIII";
    string testRoman2 = "MMXIX";
    string testRoman3 = "MCMXCIV";

    cout << "\nTesting convertRomanToInt function:\n";
    cout << "Roman numeral: " << testRoman1 << ", Decimal value: " << convertRomanToInt(testRoman1) << endl;
    cout << "Roman numeral: " << testRoman2 << ", Decimal value: " << convertRomanToInt(testRoman2) << endl;
    cout << "Roman numeral: " << testRoman3 << ", Decimal value: " << convertRomanToInt(testRoman3) << endl;

    return 0;
}