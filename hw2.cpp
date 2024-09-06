#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace std::chrono;


double amount;

class Rectangle {

public:
    double length, width;

    Rectangle(double length, double width) {
        this->length = length;
        this->width = width;
   }


    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return (length + width) * 2;
    }

};


class Account {

private:

    string name;
    int id;
    double balance;

public:

    Account(string name, int id) {
        this->name = name;
        this->id = id;
        this->balance = 0.0;
    }
    

    Account(string name, int id, double balance) {
        this->name = name;
        this->id = id;
        this->balance = balance;
    }

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount > balance) {
            cout << endl << "Not enough money";
        }
        else {
            balance -= amount;
        }
    }

    void transfer(Account& another, double amount) {
        debit(amount);
        another.credit(amount);

    }
    void showBalance() {
        cout << balance;
    }
};


class TIME {
    long long  ms;

public:
    TIME() {
        ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
   
    void displayTime() {
        int hh = (ms / 1000 / 3600 + 5) % 24;
        int mm = (ms / 1000 / 60) % 60;
        int ss = (ms / 1000) % 60;
        
        cout << setw(2) << setfill('0') << hh << "."
            << setw(2) << setfill('0') << mm << "."
            << setw(2) << setfill('0') << ss << "." << endl << ms;
    }
};





int main() {

    int length = 5, width = 10;
    double account2 = 0.0;
    Rectangle ABCD(length, width);

    TIME time;
    time.displayTime();

    Account account1("Alice", 1 ,100.0);
    Account account_2("NotAlice", 2, 100.0);
    cout << endl;
    account1.showBalance();
    cout << endl;
    account_2.showBalance();
    cout << endl;

    account1.transfer(account_2, 100);
    account1.showBalance();
    cout << endl;
    account_2.showBalance();
    cout << endl;

    return 0;
  
}

