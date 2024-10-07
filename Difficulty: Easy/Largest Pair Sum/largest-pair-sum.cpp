//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int me=0;
        int me2=0;
        int diff=INT_MAX;
        for(int i:arr){
            if(me<i){
                me2=me;
                me=i;
                diff=INT_MAX;
            }
             else if((me-me2)>(me-i)){
                diff=me-i;
                me2=i;
            }
        }
        return me+me2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends