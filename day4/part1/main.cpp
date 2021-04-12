#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> fields = {"byr","iyr","eyr","hgt","hcl","ecl","pid"}; //"cid"

bool key_exists(unordered_set<string> s) {
    for (const string& f:fields) {
        if(!s.count(f))
            return false;
    }
    return true;
}

vector<string> split(string str, char del){
    int first = 0;
    int last = str.find_first_of(del);

    vector<string> result;

    while(first<str.size()){
        string subStr(str, first, last - first);

        result.push_back(subStr);

        first = last + 1;
        last = str.find_first_of(del, first);

        if(last == string::npos)
            last = str.size();
    }

    return result;
}

int main(){
    vector<string> lines;
    string line;
    unordered_set<string> us;

    int ans = 0;
    int i = 1;
    while(getline(cin, line)){

        if(!line.empty()) {
            vector<string> vec = split(line, ' ');
            for (const string& v:vec){
                vector<string> elem = split(v,':');
                us.insert(elem[0]);
            }
            continue;
        }

        cout << "#" << i++;
        if(key_exists(us)) {
            ans++;
            cout << ":valid" << endl;
        }else
            cout << ":invalid" << endl;
        us.clear();
    }

    cout << "#" << i++;
    if(key_exists(us)) {
        ans++;
        cout << ":valid" << endl;
    }else
        cout << ":invalid" << endl;
    us.clear();

    // for(const string& l:lines) {
    //     cout << l << " ";
    //     if(l.empty())
    //         cout << "true";
    //     cout << endl;
    // }
        
    cout << ans << endl;
    return 0;
}