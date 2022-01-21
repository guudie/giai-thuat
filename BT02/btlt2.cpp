#include <bits/stdc++.h>
using namespace std;

class prob3{
private:
    int n, sum;
    int* a;
    vector<int> list;
    prob3();

public:
    prob3(int _n) : n(_n), sum(0), a(new int[_n]) {}

    ~prob3(){
        if(a)
            delete[] a;
    }

    void get(){
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
    }
    
    void printList(){
        for(auto a : list)
            cout << a << " ";
        cout << "\n";
    }

    void printOtherSubSet(){
        int j = 0;
        for(int i = 0; i < n; i++){
            if(j == list.size() || a[i] != list[j])
                cout << a[i] << " ";
            else 
                j++;
        }
    }

    int lsum(){
        int ans = 0;
        for(auto a : list)
            ans += a;
        return ans;
    }

    bool partition(int cur){
        int sumList = lsum();
        if(cur > n || sumList > sum/2)
            return false;
        if(sumList == sum/2){
            printList();
            printOtherSubSet();
            return true;
        }
        else if(cur < n) {
            list.push_back(a[cur]);
            if(partition(cur + 1))
                return true;
            list.pop_back();
            return partition(cur + 1);
        }
        return false;
    }

    void solve(){
        get();
        if(sum%2 || !partition(0))
            cout << "Failed!";
    }
};

class prob4{
private:
    int** a;
    int n;
    prob4();

public:
    prob4(int _n) : n(_n) {
        a = new int*[n];
        for(int i = 0; i < n; i++){
            a[i] = new int[n];
            for(int j = 0; j < n; j++)
                a[i][j] = n*i + j + 1;
        }
    }

    ~prob4(){
        if(a){
            for(int i = 0; i < n; i++)
                if(a[i])
                    delete[] a[i];
            delete[] a;
        }
    }

    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
    }

    bool check(){
        int t = 0;
        for(int i = 0; i < n; i++)
            t += a[0][i];
  
        int mainDiag = 0;
        int antiDiag = 0;
        for(int i = 0; i < n; i++){
            int row = 0;
            int col = 0;
            mainDiag += a[i][i];
            antiDiag += a[i][n-i-1];
            for(int j = 0; j < n; j++){
                row += a[i][j];
                col += a[j][i];
            }
            if(t != row || t != col)
                return false;
        }
        if(t != mainDiag || t != antiDiag)
            return false;
        return true;
    }
    
    void magicSquare(int pivot){
        if(pivot == n*n-1){
            if(check()){
                print();
                cout << "\n";
            }
        }
        else{
            int pRow = pivot / n;
            int pCol = pivot % n;
            for(int i = pivot; i < n*n; i++){
                int row = i / n;
                int col = i % n;

                swap(a[pRow][pCol], a[row][col]);
                magicSquare(pivot + 1);
                swap(a[pRow][pCol], a[row][col]);
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    prob4 p4(n);
    p4.magicSquare(0);
}