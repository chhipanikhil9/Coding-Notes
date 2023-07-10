//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int arr[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int startRow = 0,startCol = 0;
 		int endRow = n-1,endCol = m-1;
 		
 		while(startRow<=endRow and startCol<=endCol and k>0){
     	    // row left to right
     		for(int col = startCol;col<=endCol;col++){
     		 //   cout<<startRow<<" "<<col<<" "<<arr[startRow][col]<<" "<<endl;
     		    if(k==1){
     		        return arr[startRow][col];
     		    }
     		    k--;
     		}
     		// colm top to botm
     		for(int row = startRow+1;row<=endRow;row++){
     		 //   cout<<row<<" "<<endCol<<" "<<arr[row][endCol]<<" "<<endl;
     		    if(k==1){
     		        return arr[row][endCol];
     		    }
     		    k--;
     		}
     		
     		// row right to left
     		for(int col = endCol-1;col>=startCol;col--){
     		 //   cout<<endRow<<" "<<col<<" "<<arr[endRow][col]<<" "<<endl;
     		    if(k==1){
     		        return arr[endRow][col];
     		    }
     		    k--;
     		}
     		
     		// colm bottom to top
     		for(int row = endRow-1;row>startRow;row--){
     		 //   cout<<row<<" "<<startCol<<" "<<arr[row][startCol]<<" "<<endl;
     		    if(k==1){
     		        return arr[row][startCol];
     		    }
     		    k--;
     		}
     		startRow++,startCol++,endRow--,endCol--;
 		}
 		return INT_MIN;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends