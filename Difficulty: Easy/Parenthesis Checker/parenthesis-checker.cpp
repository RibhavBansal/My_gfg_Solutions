//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        int n = s.size();
        stack<char> ss;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                ss.push(s[i]);
                continue;
            } 
            else if (ss.empty() || (ch == ')' && ss.top() != '(') || (ch == ']' && ss.top() != '[') || (ch == '}' && ss.top() != '{')) {
                return false;
            } 
            else {
                ss.pop();
            }
        }
        return ss.empty();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends