#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
typedef float
    T;  // declare a typedef name T,定義連續記憶體空間所儲存的函數資料為float

class matrix
{
protected:
    int m, n;  // T** : pointer to pointer to T
    T **M;

public:
    matrix(int _m, int _n)
    {
        m = _m;
        n = _n;
        M = new T *[m];  // T* : pointer to T
        /* allocate a memory space which holds m elements */
        for (int i = 0; i < m; i++)
            M[i] = new T[n]();  //初始化清成0
        /* allocate a memory space which holds n elements */
    }

    void print()
    {  // print out matrix, 沒有要宣告成一特定資料形式但要回傳時必須宣告為void
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
                res.M[i][j] = A.M[i][j];
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
    matrix gram_sch()
    {
        vector u(n);
        matrix sum(m, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (i = 0) {
                    u.M[j][i] = M[j][i];
                }
                else 
                {
                    
                }
        return u;
    }
    matrix norm()
    {
        matrix Q(m, n);
        T inner_pdt;
        T sqrt_inner;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                inner_pdt += M[j][i] * M[j][i];
                sqrt_inner = sqrt(inner_pdt);
                Q.M[i][j] = M[i][j] / sqrt_inner;
            }
        }
        return Q;
    }
    matrix trans_q()
    {
        matrix q(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                q.M[i][j] = M[j][i];
            }
        }
        return q;
    }
};

istream &operator>>(istream &is, matrix &A)
{
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            is >> A.M[i][j];
    return is;
}

class vector : public matrix
{
public:
    vector(int _n) : matrix(1, _n) {}  //??

    /* inner product 內積 */
    T operator*(vector const &x)  // not vector operator, why?
    {
        T res = 0;
        for (int i = 0; i < n; i++)
            res += M[0][i] * x.M[0][i];  // col vector inner product
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
        cin >> M >> N;
        if (1 < M && N < 10) {
            matrix A(M, N);
            cin >> A;
             u(N), Q_trans(M, N), R(N, N), Q(M, N);
            u = A.gram_sch();
            u.print();
        } else {
            cout << " input range is 2 ~ 10" << endl;
        }
    }

    return 0;
}
