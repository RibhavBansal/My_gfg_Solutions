//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int ct = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] <= arr[i-1]){
                ct++;
            }
        }
        if(ct == arr.size()-1){
            sort(arr.begin(),arr.end());
            return;
        }
        int idx = arr.size()-1;
        while(idx > 0 and arr[idx-1] >= arr[idx]){
            idx--;
        }
        int t = arr.size()-1;
        while(t > idx-1){
            if(arr[t] > arr[idx-1]){
                break;
            }
            t--;
        }
        swap(arr[t], arr[idx-1]);
        reverse(arr.begin()+idx,arr.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends