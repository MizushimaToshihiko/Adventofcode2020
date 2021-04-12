#include <iostream>

using namespace std;

int main(){
    int arr[200];
    for(int i=0;i<200;i++)cin >> arr[i];

    int ans=0;
    for(int i=0;i<200;i++){
        for(int j=i+1;j<200;j++){
            if(arr[i]+arr[j] == 2020){
                ans=arr[i]*arr[j];
                cout <<  arr[i] << " " << arr[j] << endl;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}