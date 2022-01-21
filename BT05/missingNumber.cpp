#include <bits/stdc++.h>
using namespace std;

int find(int* const& arr, int l, int r) {
    if(l==r) {
        if(arr[l]==l)
            return l+1;
        return l;
    }
    int m = (l+r)/2;
    if(arr[m] == m)
        return find(arr, m+1, r);
    else
        return find(arr, l, m);
}

int main() {
    fstream fin("miss.txt", ios::in);
    int n;
    fin >> n;
    int* arr = new int[n+1];
    for(int i = 1; i < n+1; i++)
        fin >> arr[i];
    
    cout << find(arr, 1, n);
}