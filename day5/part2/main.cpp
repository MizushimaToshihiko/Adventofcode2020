#include <iostream>
#include <string>
#include <vector>
#include <set>

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
    set<unsigned int> S;
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
        S.insert(binToInt(seat));
    }

    auto itr = S.begin();
    unsigned int i = *itr;
    for(;;) {
        // cout << i << " " << *itr << endl;
        if(i != *itr) {
            ans = i;
            break;
        }
        if(itr == S.end())break;
        i++;
        itr++;
        // if(auto f = S)
    }
    cout << ans << endl;
    return 0;
}