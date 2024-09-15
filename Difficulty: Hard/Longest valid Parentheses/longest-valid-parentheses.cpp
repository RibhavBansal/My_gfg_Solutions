//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string str) {
        // code here
        int n=str.size();
        int mxl=0;
        stack<int>s,t;
        for(int i=0;i<n;i++){
            if(!s.empty()&&str[s.top()]=='('&&str[i]==')'){
                s.pop(),t.pop();
                t.empty()?mxl=i+1:mxl=max(mxl,i-t.top());
            }
            else t.push(i),s.push(i);
        }
        return mxl;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends