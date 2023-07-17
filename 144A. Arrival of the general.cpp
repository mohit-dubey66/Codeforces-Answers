// Link to the questions: https://codeforces.com/problemset/problem/144/A

// ------> Brute Force Approach Code <------\\


#include<bits/stdc++.h>
using namespace std;
 
void swap(vector<int> &arr, int i, int j){
    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}
 
int main(){
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int maxi, mini;
    maxi = mini = arr[0];
    
    for(int i = 0; i < n; i++){
        maxi = max(arr[i], maxi);
        mini = min(arr[i], mini);
    }
    
    // finding index of frst maximum
    int count = 0;
    int maxi_index;
    for(int i = 0; i < n; i++){
        if(arr[i] == maxi){
            maxi_index = i;
            break;
        }
    }
    
    // swapping the first maximum to it's right place
    for(int i = maxi_index; i >= 1; i--){
        swap(arr, i, i-1);
        count++;
    }
    
    // finding index of frst minimum from right
    int mini_index;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] == mini){
            mini_index = i;
            break;
        }
    }
    
    // swapping the first minimum to it's right place
    for(int i = mini_index; i < n-1; i++){
        swap(arr, i, i+1);
        count++;
    }
    
    cout << count << endl;
    
    return 0;
}




// ------> Optimized Code <------\\

#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int maxi, mini;
    maxi = mini = arr[0];
    
    for(int i = 0; i < n; i++){
        maxi = max(arr[i], maxi);
        mini = min(arr[i], mini);
    }
    
    // finding index of frst maximum
    int count = 0;
    int maxi_index;
    for(int i = 0; i < n; i++){
        if(arr[i] == maxi){
            maxi_index = i;
            break;
        }
    }
    
    count += maxi_index;
    
    // finding index of frst minimum from right
    int mini_index;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] == mini){
            mini_index = i;
            break;
        }
    }
    
    if(maxi_index > mini_index)
        mini_index++;
    
    count += (n - 1 - mini_index);
    
    cout << count << endl;
    
    return 0;
}
