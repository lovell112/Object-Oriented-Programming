#include <bits/stdc++.h>
using namespace std;

// typedef vector<int> int1D;
typedef vector<vector<int>> int2D;


class matrix{
    private:
        int n;
        int m;
        int2D mat;
        static int countMatrix;
    public:
        matrix(int newn, int newm){
            n = newn;
            m = newm;
            mat.resize(n, vector<int>(m));
            if(countMatrix == 0) cout << "Enter the " << ++countMatrix << "st matrix : " << endl;
            else if(countMatrix == 1) cout << "Enter the " << ++countMatrix << "nd matrix : " << endl;
            else if(countMatrix == 2) cout << "Enter the " << ++countMatrix << "rd matrix : " << endl;
            else cout << "Enter the " << ++countMatrix << "th matrix : " << endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    // mat[i][j] = (n+m)/(i+j+1);
                    cin >> mat[i][j];
                }
            }
        }
        const int2D& getMatrix() const{
            return mat;
        }
        int getRow(){
            return n;
        }
        int getCol(){
            return m;
        }
};

int matrix::countMatrix = 0;

class methodMatrix{
    private:
    int n1;
    int m1;
    int n2;
    int m2;
    public:
        int2D mulMatrix(matrix *mat1, matrix *mat2){
            n1 = mat1->getRow(), n2 = mat2->getRow();
            m1 = mat1->getCol(), m2 = mat2->getCol();
            if(m1 == n2){
                int2D result;
                result.resize(n1, vector<int>(m1));
                const int2D& operator1 = mat1->getMatrix(), operator2 = mat2->getMatrix();
                for(int i = 0; i < n1; i++){
                    for(int j = 0; j < m2; j++){
                        result[i][j] = 0;
                        for(int k = 0; k < m1; k++){
                            result[i][j] += operator1[i][k] * operator2[k][j];
                        }
                    }
                }
                return result;
            }
        }
        void outMatrix(int2D mat){
            cout << "Matrix is: " << endl;
            for(int i = 0; i < mat.size(); i++){
                for(int j = 0; j < mat[i].size(); j++){
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    matrix *mat1 = new matrix(2, 2);
    matrix *mat2 = new matrix(2, 2);
    methodMatrix multiply;
    int2D result = multiply.mulMatrix(mat1, mat2);
    multiply.outMatrix(result);

    delete mat1;
    delete mat2;
    return 0;
}