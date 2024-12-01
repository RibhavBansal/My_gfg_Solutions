//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    
    private:
    
    void findLPS(string &s, vector<int> &LPS){
        
        LPS[0] = 0;
        int i = 1;
        int len = 0;
        while(i < s.size()){
            
            if(s[i] == s[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = LPS[len - 1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
            
        }
        
    }
    
    public:
    
    vector<int> search(string pat, string txt){
        
        int n = txt.size();
        int m = pat.size();
        
        // Step 1: Find the Longest prefix suffix
        vector<int> LPS(m, 0);
        findLPS(pat, LPS);
        
        // Step 2: Store all the occurences of pat
        vector<int> occ;
        int i = 0, j = 0;
        while(i < n){
            
            if(txt[i] == pat[j]){
                i++; j++;
            }
            
            if(j == m){
                occ.push_back(i - j);
                j = LPS[j - 1]; // Move back for next occurences
            }
            else if(txt[i] != pat[j]){
                if(j != 0) j = LPS[j - 1];
                else i++;
            }
            
        }
        
        return occ;
        
    }
     
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends