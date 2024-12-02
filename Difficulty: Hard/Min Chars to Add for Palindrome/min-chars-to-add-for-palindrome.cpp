//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        //The approach is simple. We will use prefix suffix to check if the palindrome exist for few or all charcters of the given string using KMP algorithm.
        //For e.g. if 4 chars are palindrome out of 6. Then, we can say that only 2 (6-4=2) elements should be added to the front to make the string a palindrome
        //This would be similar to longest common prefix and suffix approach(KMP Algorithm)
        //We will be creating empty array of char and int of size (2*(s.size()+1)), because
        //we will be having our original string + special character(%) + reverse of original string to find the palindrone of existing elements in the current string
        //we will be placing elements starting from index 1; by doing (i+1)
        //And then using the KMP algorithm
        
        
        int LPS[2*(s.size()+1)];
        char ch[2*(s.size()+1)];
        int n = 2*(s.size()+1); 
        
        for(int i=0 ; i < s.size() ; i++) {
            ch[i+1] = ch[n-i-1] = s[i];
            LPS[i] = LPS[i + s.size()] = 0;
        }
        
        LPS[n-1] = LPS[n-2] = 0; //because while putting zeros in the above for loop, the last two index n-1, n-2 would still need to be assigned zero, as the values won't be coming in the above for loop. 
        ch[s.size()+1] = '%'; //putting the special charater(% or $) at s.size+1 , because all the index after this special character will be the reverse of the input string
        
        int first = 0 ; int second = 2;
        
        //looping until second reaches the last index which will be n - 1
        while(second < n) { 
            if(ch[first+1]==ch[second]) {
                LPS[second] = first+1;
                first++;
                second++;
            } else {
                if(first==0) {
                    second++;
                } else{
                    first = LPS[first];
                }
            }
        }
        
        return s.size() - LPS[n-1]; // returning (n - 1) because we have created LPS of size 8, so the max index will be 7
        //doing minus because we need to the number of elements that we would add to make it a palidrome.
        //so if 4 characters are the same and are palindrome out of the total input Strig size of 6,
        // we can say that we need to add 2 more character to make it a palindrome.(6-4=2)
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
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends