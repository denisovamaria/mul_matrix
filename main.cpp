#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    int num;
    in >> n;
    int *m = new int[n];
    int *s = new int[n];
    long long int **matrix = new long long int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new long long int[n];
    }
    int p = 0;
    while (in >> num) {
        s[p] = num;
        in>>num;
        m[p] = num;
        p++;
    }
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        matrix[i][i + 1] = s[i] * m[i] * m[i + 1];
    }
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i > -1; i--) {
            long long int l = 9223372036854775807;
            if (j > i + 1) {
                for (int k = i; k < j; k++) {
                    if (l > matrix[i][k] + matrix[k + 1][j] + s[i] * m[k] * m[j])
                        l = matrix[i][k] + matrix[k + 1][j] + s[i] * m[k] * m[j];
                }
                matrix[i][j] = l;
            }
        }
    }
    out << matrix[0][n - 1];
}
