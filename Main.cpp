
#include <iostream>
#include <bitset>
#include <cmath>
#include <string>

using namespace std;

// Convert decimal to binary string (two's complement for negative)
string toBinary(int value, int bit_width) {
    unsigned int mask = (1 << bit_width) - 1;
    unsigned int unsigned_val = value & mask;
    return bitset<32>(unsigned_val).to_string().substr(32 - bit_width);
}

// Convert binary string to signed decimal
int toDecimal(string binary, int bit_width) {
    if (binary[0] == '0') {
        return bitset<32>(binary).to_ulong();
    }
    else {
        // Two's complement to positive
        for (char& c : binary) {
            c = (c == '0') ? '1' : '0';
        }
        int positive = bitset<32>(binary).to_ulong() + 1;
        return -positive;
    }
}

// Detect overflow
bool checkOverflow(int a, int b, int result, int bit_width, string operation) {
    if (operation == "add") {
        if (a > 0 && b > 0 && result < 0) return true;
        if (a < 0 && b < 0 && result > 0) return true;
    }
    else if (operation == "sub") {
        if (a > 0 && b < 0 && result < 0) return true;
        if (a < 0 && b > 0 && result > 0) return true;
    }
    return false;
}

int main() {
    int bit_width, a, b;
    string operation;

    cout << "Enter bit width (4, 8, 16, 32): ";
    cin >> bit_width;
    cout << "Enter integer A: ";
    cin >> a;
    cout << "Enter integer B: ";
    cin >> b;
    cout << "Enter operation (add/sub): ";
    cin >> operation;

    int min_range = -pow(2, bit_width - 1);
    int max_range = pow(2, bit_width - 1) - 1;

    cout << "\nBit width: " << bit_width << endl;
    cout << "Valid range: " << min_range << " to " << max_range << endl;
    cout << "A = " << a << " Binary A = " << toBinary(a, bit_width) << endl;
    cout << "B = " << b << " Binary B = " << toBinary(b, bit_width) << endl;

    int exact_result = (operation == "add") ? a + b : a - b;
    string op_display = (operation == "add") ? "ADD" : "SUBTRACT";

    int mask = (1 << bit_width) - 1;
    int fixed_result = exact_result & mask;
    int signed_result = toDecimal(toBinary(fixed_result, bit_width), bit_width);
    bool overflow = checkOverflow(a, b, signed_result, bit_width, operation);

    cout << "Operation: " << op_display << endl;
    cout << "Binary result = " << toBinary(signed_result, bit_width) << endl;
    cout << "Signed result = " << signed_result << endl;
    cout << "Overflow: " << (overflow ? "Yes" : "No") << endl;

    return 0;
}
