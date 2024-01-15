//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.
// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &arr, int N, int M)
        {
            // your code here
            int i=0;
            int j=M-1;
            int ans=-1;
            while(i<N and j>=0)
            {
                if(arr[i][j]==1)
                {
                    j--;
                    ans=i;
                }
                else
                i++;
                
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends