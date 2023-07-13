// Link to the question: https://codeforces.com/problemset/problem/977/AS

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < k; i++){
        int lastDigit = n%10;
        
        if(lastDigit != 0){
            n = n - 1;
        }
        else{
            n = n/10;
        }
    }
    cout << n;
    
    return 0;
}