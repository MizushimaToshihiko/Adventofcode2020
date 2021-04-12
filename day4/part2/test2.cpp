#include <iostream>
#include <regex>

using namespace std;

int main() {
    string str;
    cin >> str; // 60in
    smatch smatch;
    bool reg = regex_match(str,smatch,regex("(amb|blu|brn|gry|grn|hzl|oth)"));
    if(!reg) {
        cout << "false" << endl;
        return 0;
    }
    
    cout << "true" << endl;
    cout << smatch[0] << " " << smatch[1] << " " << smatch[2] << endl; // 60in 60 in
    return 0;
}