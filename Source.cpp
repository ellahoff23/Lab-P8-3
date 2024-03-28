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

int main() {
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    int decimalValue = 0;
    int prevValue = 0; 

    
    for (int i = romanNumeral.length() - 1; i >= 0; i--) {
        int currentVal = romanCharValue(romanNumeral[i]);

        
        if (currentVal < prevValue) {
            decimalValue -= currentVal;
        }
        else {
            decimalValue += currentVal;
        }

      
        prevValue = currentVal;
    }

    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}