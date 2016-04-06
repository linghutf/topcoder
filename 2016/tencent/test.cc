#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;

    const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    int x = 0, y = -1, c = 0;

    vector<vector<int>> mat(n, vector<int>(n));//n*n
    int i,j;
    int im,jlen;
    for(i = 0, im = 0; i < n + n - 1; ++i, im = i % 4)
        for(j = 0, jlen = (n + n - i) / 2; j < jlen; ++j)
            mat[x += dx[im]][y += dy[im]] = ++c;

    for (auto & r : mat) {
            for (auto & v : r)
                cout << setw(4)<<v;
            cout << endl;
        }
}
