//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int kadanAlgo(vector<int> &a){
        int ans=INT_MIN;
        int temp=0;
        
        for(auto ele:a){
            temp+=ele;
            ans=max(ans,temp);
            temp=(temp<0)?0:temp;
        }
        
        return ans;
        
    }
    
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        return kadanAlgo(arr);
        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends