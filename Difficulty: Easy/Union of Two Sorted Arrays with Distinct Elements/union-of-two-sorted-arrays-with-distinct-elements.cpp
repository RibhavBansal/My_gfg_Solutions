//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // c - vector of the answer
        vector<int> c;
        // i, j indexes to iterate through the arrays
        int i=0, j=0;
        // n, m size of given arrays
        int n = a.size(), m = b.size();
        // loop 1: until one of the arrays end
        while(i<n && j<m)
        {
            // case1: elements equals insert only one of them
            if(a[i] == b[j])
            {
                c.push_back(a[i]);
                i++;
                j++;
            }
            // case2: element of a smaller - insert it
            else if(a[i] < b[j])
            {
                c.push_back(a[i]);
                i++;
            }
            // case3: element of b smaller - insert it
            else
            {
                c.push_back(b[j]);
                j++;
            }
        }
        // loop 2: complete elements of array a
        while(i<n)
        {
            c.push_back(a[i]);
            i++;
        }
        // loop 3: complete elements of array b
        while(j<m)
        {
            c.push_back(b[j]);
            j++;
        }
        return c;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends