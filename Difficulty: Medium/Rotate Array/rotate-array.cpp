//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // Approach using queue.
        // define the queue, n as array size
        queue<int> q;
        int n = arr.size();
        // in case d bigger than length of the array, use d1 modulo
        int d1 = d%n;
        // loop 1: fill queue with elements 0 - d1
        for(int i=0; i<d1; i++)
        {
            q.push(arr[i]);
        }
        // loop 2: move elements to the left by d1 positions
        for(int i=d1; i<n; i++)
        {
            arr[i-d1] = arr[i];
        }
        // loop 3: store elements from the quqe to right of the array
        for(int i=n-d1; i<n; i++)
        {
            arr[i] = q.front();
            q.pop();
        }
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d);

        // printing the elements of the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends