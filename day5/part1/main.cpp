#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned int binToInt(char *c) {
    unsigned int res = 0;
    while(*c != '\0') {
        switch(*c++) {
        case '0':
            res *= 2;
            break;
        case '1':
            res = res * 2 + 1;
            break;
        }
    }
    return res;
}
int main(){
    string str;
    unsigned int ans = 0;

    while(getline(cin, str)) {
        char seat[11];
        for (int i=0;i<7;i++) {
            if(str[i] == 'F')seat[i]='0';
            else seat[i]='1';
        }
        
        for(int i=7;i<10;i++) {
            if(str[i] == 'L')seat[i]='0';
            else seat[i]='1';
        }
        seat[10] = '\0';
        unsigned int seadId = binToInt(seat);
        
        ans = max(ans, seadId);
        cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}