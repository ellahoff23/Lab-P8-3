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
    string userInput;
    while (true) {
        cout << "Enter Roman number or Q to quit: ";
        getline(cin, userInput);

        if (userInput == "Q") {
            break;
        }

        int decimalValue = convertRomanToInt(userInput);
        cout << userInput << " = " << decimalValue << '\n' << endl;
    }

    return 0;
}