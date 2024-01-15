//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//     Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.
class Solution
{
public:
    string colName(long long int n)
    {
        string ans = "";
        // your code here
        while (n > 0)
        {
            int r = (n - 1) % 26;
            char t = 'A' + r;
            ans += t;
            n = (n - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.colName(n) << '\n';
    }
}

// } Driver Code Ends