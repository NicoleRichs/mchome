#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1;
    vector<int> arr2;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr1.push_back(a);
    }
    for(int j = 0; j < m; j++){
        int b; 
        cin >> b;
        arr2.push_back(b);
    }
    int table[m];
    for (int j=0; j<m; j++){
        table[j] = 0; //table stores longest LCS ending with arr2[j]
    }
    for (int i=0; i<n; i++) //iterate through each member of arr1
    {
        int current = 0; //current length of the LCIS
        for (int j=0; j<m; j++)
        {
            if (arr1[i] == arr2[j]) //if we hit a match
                if (current + 1 > table[j]) //if the current length of LCIS is larger than the one stored
                    table[j] = current + 1; //override it
            if (arr1[i] > arr2[j]) //if we've "overshot" the current arr2 member
                if (table[j] > current) 
                    current = table[j]; //set the LCIS to the best one acquired so far
        }
    }
    int result = 0;
    for (int i=0; i<m; i++)
        if (table[i] > result)
           result = table[i];

    cout << result;
    return (0);
}
