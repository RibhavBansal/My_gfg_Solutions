//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class com{
    public:
    bool operator()(Node* a, Node* b){
        return a->data> b->data;
    }
 };
class Solution {
  public:
     Node* mergeKLists(vector<Node*>& arr) {
     priority_queue<Node*, vector<Node*>, com> pq;
     if(arr.size()==0){
         return nullptr;
         
     }
     for (int i=0; i<arr.size(); i++ ){
         if(arr[i]!=nullptr){
             pq.push(arr[i]);
         }
         
     }
     Node* head= nullptr;
     Node* tail= nullptr;
     while(pq.size()>0){
         Node* temp= pq.top();
         pq.pop();
         if(head==nullptr){
             head= temp;
             tail= temp;
         }
         else{
             tail->next= temp;
             tail= temp;
             
         }
         if(temp->next!=nullptr){
             pq.push(temp->next);
             
         }
     }
     return head;
     
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends