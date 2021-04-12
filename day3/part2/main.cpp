#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> grid(323);

int step_num(int right, int down){
    int res = 0;
    int size = grid[0].size();
    int j = 0;

    for(int i=0;i<323;i+=down){
        if(grid[i][(j*right)%size] == '#')res++;
        j++;
    }
    return res;
}

int main(){

    for(int i=0;i<323;i++)
        cin >> grid[i];
    
    long long ans  = step_num(1, 1);
              ans *= step_num(3, 1);
              ans *= step_num(5, 1);
              ans *= step_num(7, 1);
              ans *= step_num(1, 2);
    
    cout << step_num(1, 1) << endl;
    cout << step_num(3, 1) << endl;
    cout << step_num(5, 1) << endl;
    cout << step_num(7, 1) << endl;
    cout << step_num(1, 2) << endl;

    cout << ans << endl;
    return 0;
}