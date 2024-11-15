//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> mid;
        for(int i =0 ; i<n; i++){
            if(arr[i] != 0) mid.push_back(arr[i]);
        }
        int z = n - mid.size();
        int ind = 0;
        while(ind<n-z){
            arr[ind] = mid[ind];
            ind++;
        }
        for(int i = ind; i<n; i++){
            arr[i] = 0;
        }
        
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
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends