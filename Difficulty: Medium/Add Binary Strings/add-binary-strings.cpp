//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& A, string& B) {
        // your code here
        string ans="";
        int Asize=A.length(),Bsize=B.length();
        int i=Asize-1,j=Bsize-1;
        int carry=0;
        while(i>=0 || j>=0|| carry>0 ){
            int a=0,b=0;
            if(i>=0)
            a=A[i--]-'0';
            if(j>=0)
            b=B[j--]-'0';
            
            int sum=a+b+carry;
            if(sum==0){
                ans.push_back('0');
                carry=0;
            }
            else if(sum==1){
                ans.push_back('1');
                carry=0;
            }
            else if(sum==2){
                ans.push_back('0');
                carry=1;
            }
            else if(sum==3){
                ans.push_back('1');
                carry=1;
            }
        }
        while(ans.back()=='0' && ans.size()>1)
        ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends