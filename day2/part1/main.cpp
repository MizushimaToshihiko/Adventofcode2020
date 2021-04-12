#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    string least_most;
    string given_letter;
    string password;
    
    int count = 0;
    int ans = 0;

    for(int i=0;i<1000;i++){
        cin >> least_most;
        vector<string> vec = split(least_most, '-');
        int least = stoi(vec[0]);
        int most = stoi(vec[1]);

        cin >> given_letter;
        char given = given_letter[0];

        cin >> password;
        for(size_t i=0;i<password.size();i++){
            if(password[i] == given)count++;
        }
        // cout << count << endl;
        if(least <= count && count <= most)ans++;
        count = 0;
    }

    cout << ans << endl;
    return 0;
}