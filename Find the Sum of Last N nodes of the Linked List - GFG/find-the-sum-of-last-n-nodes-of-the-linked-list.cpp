//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

int sumOfLastN_Nodes(struct Node* head, int n);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--){
        struct Node* head = NULL;
        int n,m,tmp;
        cin>>m>>n;
        while(m--){
            cin>>tmp;
            append(&head, tmp);
        }
        cout<<sumOfLastN_Nodes(head, n)<<endl;
    }
	return 0;
}

// } Driver Code Ends


/*Structure of the node of the linled list is as

struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};
*/
// your task is to complete this function 
// function should return sum of last n nodes
int size(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int sumOfLastN_Nodes(struct Node* head, int n)
{
      // Code here
    int N = size(head);
    int cnt = N-n;
    // cout<<N<<" "<<cnt<<endl;
    int i = 1;
    int halfSum = 0,totalSum = 0;
    Node* temp = head;
    
    while(temp){
        if(i<=cnt){
            halfSum += temp->data;
            // cout<<halfSum<<" ";
        }        
        totalSum += temp->data;
        temp = temp->next;
        i++;
    }
    return totalSum-halfSum;
}











