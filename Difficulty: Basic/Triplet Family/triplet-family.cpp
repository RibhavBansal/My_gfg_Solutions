//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // The approach is first insert values to unordered map
        // then create two nested loops that sums two values at a time
        // if the value appears in the map, answer is true
        // else answer is false
        int n = arr.size();
        // map storing the appearance of every value
        unordered_map<int, int> mp;
        // loop filling the map
        for(int val : arr)
        {
            mp[val]++;
        }
        // nested loop for summing two elements at a time
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int val = arr[i] + arr[j];
                // check if element appears in the map
                if(mp.find(val) != mp.end())
                {
                    return true;
                }
            }
        }
        // loops end elements not found
        return false;
    }
};
 


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends