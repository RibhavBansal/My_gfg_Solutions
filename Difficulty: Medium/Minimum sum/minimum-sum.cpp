//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort(arr.rbegin(), arr.rend()); // nlogn + 2n
        int n = arr.size();
        string ans="";
        int hate=0;
        for(int i=0;i<n-1;i+=2){
            int x=arr[i]+arr[i+1];
            
            ans+=to_string((x+hate)%10);
            
            hate=(x+hate)/10;
        }
        
        if(n&1){
            hate+=arr[n-1];
        }
            ans+=to_string(hate);
        
        while(ans.back()=='0'){
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        if(ans.empty()){
            return "0";
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
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends