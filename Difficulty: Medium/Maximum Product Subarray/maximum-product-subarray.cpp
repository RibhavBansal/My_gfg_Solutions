//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  typedef long long ll;
  // Function to find maximum product subarray
    int maxProduct(vector<int> &nums) {
        ll maxProd = 1, minProd = 1, ans = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0)
				swap(minProd, maxProd);
			maxProd = max(maxProd * nums[i], (ll)nums[i]);
			minProd = min(minProd * nums[i], (ll)nums[i]);
			ans = max(ans, maxProd);
		}
		return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends