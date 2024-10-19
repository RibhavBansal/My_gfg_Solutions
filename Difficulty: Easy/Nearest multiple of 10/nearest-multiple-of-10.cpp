//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int i=str.size()-1;
        while(i>=0){
            if(str[i]>'5'){
                str[i]='0';
                i--;
                while(str[i]=='9'){
                    str[i]='0';
                    i--;
                }
                str[i]+=1;
                break;
            } else{
                str[i]='0';
                break;
            }
        }
        return str;
    }
};





//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends