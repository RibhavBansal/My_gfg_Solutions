//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
         if (n < 2) return -1; 

        int max_sum = arr[0] + arr[1]; 
        for (int i = 1; i < n - 1; i++) {
            int current_sum = arr[i] + arr[i + 1];
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends