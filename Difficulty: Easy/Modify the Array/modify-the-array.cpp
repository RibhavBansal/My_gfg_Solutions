//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if((i+1)<n && arr[i]!=0 && arr[i]==arr[i+1])
            {
                arr[i]=2*arr[i];
                arr[i+1]=0;
            }
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != 0)
            {
                swap(arr[i],arr[j]);
                j++;
            }
        }
        return arr;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends