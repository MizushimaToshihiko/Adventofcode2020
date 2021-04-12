#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    string str;
    unordered_set<int> us;
    int ans = 0;

    while(getline(cin, str)) {

        if(!str.empty()) {
            // cout << str << endl;
            for(const char& c:str)
                us.insert(c);
            continue;
        }

        // cout << us.size() << endl;
        ans += us.size();
        us.clear();
    }

    ans += us.size();
    us.clear();

    cout << ans << endl;
    return 0;
}