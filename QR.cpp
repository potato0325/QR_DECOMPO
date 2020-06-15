#include <stdio.h>
#include <iostream>
using namespace std;
typedef float T;
class matrix
{
public:
    int m, n;
    T **M;
    matrix(int _m, int _n)
    {
        m = _m;
        n = _n;
        M = new T *[m];
        for (int i = 0; i < m; i++)
            M[i] = new T[n]();
    }

    void print()
    {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
    }

    friend istream &operator>>(istream &is, matrix &A);
    /* res.M = M + A.M */
    matrix operator+(matrix const &A)
    {
        matrix res(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res.M[i][j] = M[i][j] + A.M[i][j];
        return res;
    }

    /* res.M = M - A.M */
    matrix operator-(matrix const &A)
    {
        matrix res(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res.M[i][j] = M[i][j] - A.M[i][j];
        return res;
    }

    /*
     * res.M = M * A.M
     * where M is a m by n matrix while A is a n by k matrix
     */
    matrix operator*(matrix const &A)
    {
        int k = A.n;
        matrix res(m, k);
        for (int c = 0; c < k; c++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    /* FIXME: correct the matrix multiplication */
                    res.M[i][c] += M[i][j] * A.M[j][c];

        return res;
    }
};

istream &operator>>(istream &is, matrix &A)
{
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            is >> A.M[i][j];k
    return is;
}

class vector : public matrix
{
public:
    vector(int _n) : matrix(1, _n) {}

    T operator*(vector const &x)
    {
        T res = 0;
        for (int i = 0; i < n; i++)
            res += M[0][i] * x.M[0][i];
        return res;
    }
    T operator-(vector const &x)
    {
        T res = 0;
        for (int i = 0; i < n; i++)
            res = M[0][i] - x.M[0][i];
        return res;
    }
    void printv()
    {
        for (int i = 0; i < m; i++)
            cout << M[i] << " ";
        cout << endl;
    }
};
int main()
{
    int k;
    cin >> k;
    int M, N;
    for (int i = 0; i < k; i++) {
        cin >> M, N;
        matrix A(M, N);
        cin >> A;
        A.print();
    }
    return 0;
}