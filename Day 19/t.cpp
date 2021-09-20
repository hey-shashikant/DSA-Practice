#include <bits/stdc++.h>
using namespace std;
bool Linear_Search(vector<int>&vec, int key)
{
    for(auto i : vec)
    {
        if(i == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "\n Enter No of elements : ";
    cin >> n;
    vector<int>arr(n);
    cout << "\n Enter elemnets : ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int key;
    cout << "\n Enter key : ";
    cin >> key;
    if(Linear_Search(arr,key))
        cout << "Element present.";
    else
        cout << "Not present.";
    return 0;
}