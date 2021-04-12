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
    string position;
    string given_letter;
    string password;
    
    int ans = 0;

    for(int i=0;i<1000;i++){
        cin >> position;
        vector<string> vec = split(position, '-');
        int pos1 = stoi(vec[0])-1;
        int pos2 = stoi(vec[1])-1;

        cin >> given_letter;
        char given = given_letter[0];

        cin >> password;
        // cout << count << endl;
        if((password[pos1] == given && password[pos2] != given) ||
           (password[pos1] != given && password[pos2] ==given))
           ans++;
    }

    cout << ans << endl;
    return 0;
}