//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
// code herev
vector<int> one;
vector<int >two;
int si=max(one.size(),two.size());
vector<int > ans;
 
 
for(int i=0; i<arr.size(); i++) {
if (arr[i]<0) {
two.push_back(arr[i]);
}
else {
one.push_back(arr[i]);
}
}
int i = 0, j = 0;
while (i < one.size() && j < two.size()) {
ans.push_back(one[i++]);
ans.push_back(two[j++]);
}
while(i<one.size()) {
ans.push_back(one[i++]);
}
while(j<two.size()) {
ans.push_back(two[j++]);
}
 
// for(int i=0;i<arr.size();i++){
//     arr[i]=ans[i];
// }
arr=ans;
 
 
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends