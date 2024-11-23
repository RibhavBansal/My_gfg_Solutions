//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &a, int k) {
        sort(a.begin(),a.end());
        int n = a.size();
        long long int ans = a[n-1] - a[0];

        for(int i = 0; i < n-1; i++){
            long long int mn = a[0]+k;
            long long int mx = a[i]+k;
            
            if(a[i+1]-k >= 0){
                mn = min(mn,(a[i+1]-k)*1LL);
            }
            else{
                mx = max(mx,(a[n-1]+k)*1LL);
            }
            
            if(a[n-1]-k >= 0){
                mx = max(mx,(a[n-1]-k)*1LL);
            }
            else{
                mx = max(mx,(a[n-1]-k)*1LL);
            }
            
            ans = min(ans,mx-mn);
        }

        return ans;
    }
};

// 7
// 1 1 4 6 6 8 9 10


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
// } Driver Code Ends