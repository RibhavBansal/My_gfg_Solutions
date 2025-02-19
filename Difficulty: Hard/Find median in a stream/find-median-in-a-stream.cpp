//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    //Function to insert heap.
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>>g;
    void insertHeap(int &x)
    {
        if(s.size()==0){
            s.push(x);
            return ;
        }
        if(s.size()>g.size()){
            if(x<s.top()){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else{
                g.push(x);
            }
        }
        else{
            if(x<s.top()){
                s.push(x);
            }
            else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(s.size()==g.size()){
            return (double)(s.top()+g.top())/2.0;
        }else{
            return s.top();
        }
    }
    vector<double> getMedian(vector<int> &arr) {
        vector<double>v;
        for(auto it : arr){
            insertHeap(it);
            v.push_back(getMedian());
        }
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends