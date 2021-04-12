#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
using namespace std;

vector<string> fields = {"byr","iyr","eyr","hgt","hcl","ecl","pid"}; //"cid"

bool key_exists(unordered_map<string, string> s) {
    for (const string& f:fields) {
        if(!s.count(f))
            return false;
    }
    return true;
}

bool key_exists_and_valid(unordered_map<string, string> um) {
    for (int i=0;i<fields.size();i++) {
        if(!um.count(fields[i]))
            return false;
        string str = um[fields[i]];
        smatch smatch;
        if(fields[i] == "byr" && !(1920 <= stoi(str) && stoi(str) <= 2002)) {
            return false;
        }else if(fields[i] == "iyr" && !(2010 <= stoi(str) && stoi(str) <= 2020)) {
            return false;
        }else if(fields[i] == "eyr" && !(2020 <= stoi(str) && stoi(str) <= 2030)) {
            return false;
        }else if(fields[i] == "hgt") {
            bool reg = regex_match(str,smatch,regex("(\\d+)(cm|in)"));
            if(!reg)
                return false;
            if(smatch[2] == "cm" && !(150 <= stoi(smatch[1]) && stoi(smatch[1]) <= 193))
                return false;
            else if(smatch[2] == "in" && !(59 <= stoi(smatch[1]) && stoi(smatch[1]) <= 76))
                return false;
        }else if(fields[i] == "hcl") {
            if(!regex_match(str,smatch,regex("^#[0-9a-z]{6}")))
                return false;
        }else if(fields[i] == "ecl") {
            if(!regex_match(str,smatch,regex("(amb|blu|brn|gry|grn|hzl|oth)")))
                return false;
        }else if(fields[i] == "pid") {
            if(!regex_match(str,smatch,regex("[0-9]{9}")))
                return false;
        }
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
    unordered_map<string, string> us;

    int ans = 0;
    int i = 1;
    while(getline(cin, line)){

        if(!line.empty()) {
            vector<string> vec = split(line, ' ');
            for (const string& v:vec){
                vector<string> elem = split(v,':');
                us[elem[0]] = elem[1];
            }
            continue;
        }

        cout << "#" << i++;
        if(key_exists_and_valid(us)) {
            ans++;
            cout << ":valid" << endl;
        }else
            cout << ":invalid" << endl;
        us.clear();
    }

    cout << "#" << i++;
    if(key_exists_and_valid(us)) {
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