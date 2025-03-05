//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the length of the longest common subsequence in two strings.
    int lcs(string& s1, string& s2) {
           int n = s1.size();
           int m = s2.size();
           
           vector<int>prev(m+1,0),cur(m+1,0);
           for(int i = 1;i<=n;i++){
               for(int j=1;j<=m;j++){
                   if(s1[i-1] == s2[j-1])
                       cur[j] = 1+prev[j-1];
                    else
                        cur[j] = max(prev[j],cur[j-1]);
               }
               prev = cur;
           }
           return prev[m];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends