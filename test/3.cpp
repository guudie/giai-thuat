#include <bits/stdc++.h>
#define MX (int)1e6
using namespace std;

bool check(int* arr, int n, int x) {
    bool* exists = new bool[MX];
    memset(exists, false, MX);
    for(int i = 0; i < n; i++) {
        exists[arr[i]] = true;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(x < arr[i] + arr[j]) continue;
            if(exists[x - arr[i] - arr[j]])
                return true;
        }
    }
    return false;
}

int main() {
    fstream fin("input.txt", ios::in);
    int n, x;
    fin >> n >> x;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        fin >> arr[i];
        // cout << arr[i];
    }

    cout << check(arr, n, x);
}