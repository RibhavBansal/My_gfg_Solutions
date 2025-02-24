//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        vector<int>v1;
        vector<int>v2;
        stack<pair<int, int>> s;
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                v1.push_back(i+1);
            }
            else{
                v1.push_back(i-s.top().second);
            }
            s.push(make_pair(arr[i], i));
        }
        
        while (!s.empty())
        s.pop();
        
     for(int i=arr.size()-1;i>=0;i--){
        while(!s.empty() && s.top().first>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            v2.push_back(arr.size() - i);
        }
        else{
            v2.push_back(s.top().second - i);
        }
        s.push(make_pair(arr[i], i));
    }
    reverse(v2.begin(), v2.end());
    for(int i = 0;i<arr.size();i++){
        v1[i] = v1[i]+v2[i]-1;
        arr[i] = arr[i]*v1[i];
    }
    int maxi = arr[0];
    for(int i = 0;i<arr.size();i++){
        if(arr[i] >= maxi){
            maxi = arr[i];
        }
    }
    return maxi;
    
        
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends