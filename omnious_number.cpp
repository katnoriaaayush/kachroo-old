#include <iostream>
using namespace std;

int numberOminous(int a, int b, int k, int *delNos, int n){
    int count = 0;
    for(int i = a; i <= b; i++){
        int temp = i;
        int digitArray[10] = {0};

        while(temp){
            digitArray[temp%10]++;
            temp /= 10;
        }
        
        int rougeK = 0;
        for(int i=0; i<n; i++){
            rougeK += digitArray[delNos[i]];
        }

        if(rougeK < k){
            count++;
        }

    }
    return count;
}


int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    int *delNos = new int[n];
    for(int i=0; i<n; i++){
        cin >> delNos[i];
    }

    cout << numberOminous(a, b, k, delNos, n) << "\n";

    return 0;
}