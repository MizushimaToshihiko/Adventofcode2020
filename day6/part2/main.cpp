#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <class T>
void print_set(set<T> s) {
    for(auto itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "\n";
}

set<char> intersection(set<char> s1, set<char> s2) {
    set<char> res;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                        inserter(res,res.end()));
    return res;
}
int main(){
    string str;
    vector<set<char> > vus;
    set<char> result;

    int ans = 0;

    while(getline(cin, str)) {
        // cout << str << endl;
        if(!str.empty()) {
            // cout << str << endl;
            set<char> us;
            for(const char& c:str)
                us.insert(c);
            vus.push_back(us);
            continue;
        }

        if(vus.size() > 1) {
            result = intersection(vus[0],vus[1]);
            for(int i=2;i<vus.size();i++) {
                // print_set(vus[i]);
                // print_set(vus[i+1]);
                result = intersection(vus[i],result);
            }
            ans += result.size();
            // print_set(result);
            result.clear();
        } else if(vus.size() == 1) {
            ans += vus[0].size();
            // print_set(vus[0]);
        }
        
        // cout << ans << endl;
        vus.clear();
    }

    if(vus.size() > 1) {
        result = intersection(vus[0],vus[1]);
        for(int i=0;i<vus.size();i++) {
            // print_set(vus[i]);
            // print_set(vus[i+1]);
            result = intersection(vus[i],result);
        }
        ans += result.size();
        // cout << result.size() << "\n";
        // print_set(result);
        result.clear();
    } else if(vus.size() == 1) {
        ans += vus[0].size();
        // print_set(vus[0]);
    }

    vus.clear();

    cout << ans << endl;
    return 0;
}