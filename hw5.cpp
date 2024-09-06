#include<iostream>
using namespace std;

class Matrix {
    int n, m ;
    int** arr;
public:
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        arr = new int* [n];
        for (int i = 0; i < n; i++) {
            arr[i] = new int[m];

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = 0;
            }
        }
    }



    Matrix(int n, int m, int data) {
        this->n = n;
        this->m = m;
        arr = new int* [n];
        for (int i = 0; i < n; i++) {
            arr[i] = new int[m];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = data;
            }
        }
    }

   

    friend istream& operator >> (istream& in, const Matrix& matrix) {

        for (int i = 0; i < matrix.n; i++) {
            for (int j = 0; j < matrix.m; j++) {
                in >> matrix.arr[i][j];
            }
        }
        return in;

    }

    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (int i = 0; i < matrix.n; i++) {
            for (int j = 0; j < matrix.m; j++) {
                out << matrix.arr[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

   

    Matrix operator+(Matrix &another) {
        Matrix C(n, m);
        if (n != another.n || m != another.m) {
            cout << "Error" << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    C.arr[i][j] = arr[i][j] + another.arr[i][j];
                }
            }
        }
        return C;
    }


    Matrix operator-(Matrix& another) {
        if (n != another.n || m != another.m) {
            cout << "Error" << endl;
        }
        
            Matrix D(n, m,0); 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    D.arr[i][j] = arr[i][j] - another.arr[i][j];
                }
            }
            return D;
       
    }

    Matrix operator*(Matrix& another) {
        if (m != another.n) {
            cout << "Error" << endl;
        }
        else {
            Matrix E(n, another.m ,0); // Create the result matrix with correct dimensions
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < another.m; j++) {
                    E.arr[i][j] = 0;
                    for (int k = 0; k < m; k++) {
                        E.arr[i][j] += arr[i][k] * another.arr[k][j];
                    }
                }
            }
            return E;
        }
    }

   

    bool operator!=( Matrix another) {
        if (n != another.n || m != another.m) {
            return true; 
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != another.arr[i][j]) {
                    return true; 
                }
            }
        }

        return false; 
    }

    bool operator==(const Matrix another)  {
        if (n != another.n || m != another.m) {
            return false; 
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != another.arr[i][j]) {
                    return false; 
                }
            }
        }

        return true; 
    }

   

    int* operator[](int rowIndex) {
        if (rowIndex < 0 || rowIndex >= n) {
            cout << "Error: Index out of bounds" << endl;
            return nullptr;
        }
        return arr[rowIndex];
    }

    int operator()() const {
        if (n != m) {
            cout << "Matrix is not square";
        }

        if (n == 2) {
            return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
        }
        else if (n == 3) {
            return arr[0][0] * arr[1][1] * arr[2][2] +
                arr[0][1] * arr[1][2] * arr[2][0] +
                arr[0][2] * arr[1][0] * arr[2][1] -
                arr[0][2] * arr[1][1] * arr[2][0] -
                arr[0][0] * arr[1][2] * arr[2][1] -
                arr[0][1] * arr[1][0] * arr[2][2];
        }
        else {
            throw "Determinant calculation is not implemented for matrices of this size";
        }
        }
    ~Matrix() {
        for (int i = 0; i < n; i++) {
            delete arr[i];
        }
        delete[] arr;
    }

    
};

int main() {
    Matrix A(3, 3), B(3, 3, 0);

    cout << "Enter values for matrix A :" << endl;
    cin >> A;
    cout << "Enter values for matrix B :" << endl;
    cin >> B;

  

    cout << "Matrix A:" << endl << A << endl;
    cout << "Matrix B:" << endl << B << endl;

    Matrix Result_of_Summ = A + B;
    Matrix Result_of_Minus = A - B;
    Matrix Result_of_Multiplication = A * B;

    cout << "Matrix A + B:" << endl << Result_of_Summ << endl;
    cout << "Matrix A - B:" << endl << Result_of_Minus << endl;
    cout << "Matrix A * B:" << endl << Result_of_Multiplication << endl;

    if (A == B) {
        cout << "Matrix A and B are equal." << endl;
    }
    else {
        cout << "Matrix A and B are not equal." << endl;
    }

    if (A != B) {
        cout << "Matrix A and B are not equal." << endl;
    }
    else {
        cout << "Matrix A and B are equal." << endl;
    }
    
    cout << "Number if Matrix of given n,m is: " << A[0][1] << endl;

    //todo List: operator: >>, <<, +, -, *, ==, !=, [], () - determinant

    int det_A = A();
    cout << "Determinant of Matrix A: " << det_A << endl;
    int det_B = B();
    cout << "Determinant of Matrix A: " << det_B << endl;

    return 0;
}