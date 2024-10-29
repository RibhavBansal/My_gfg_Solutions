//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        m[arr[i]]++;
        
        int count=0;
        if(k==0){
            for(int i=0;i<n;i++){
               int p=m[arr[i]];
                count=count+p-1;
                m[arr[i]]--;
        } 
        }
        else{
            for(int i=0;i<n;i++)
                count=count+m[arr[i]+k];
        
        }
       
        return count;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends