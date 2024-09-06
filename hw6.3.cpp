#include <iostream>
using namespace std;

int main() {
    double Input; 
    cout << "Enter a number: ";
    cin >> Input;
    double result;

    if (Input == 0) {
        result = 0;
    }

    else {
        double x_n = 1.0;
        double x_n_next = 1.0;

        do {
            x_n = x_n_next;
            x_n_next = 0.5 * (x_n + Input / x_n);
        } while (x_n_next != x_n);

        
 

        result = x_n_next;
    }

    cout << "The square root of " << Input << " is approximately " << result << endl;
    return 0;
}
