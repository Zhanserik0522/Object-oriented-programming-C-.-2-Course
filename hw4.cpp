#include <iostream>
#include <string>
#include <array>
#include <cmath>
using namespace std;

class Author {
private:
    string Name;
    int Age;
    string Email;
public:
    Author() {
        Name = "";
        Age = 0;
        Email = "";
    }

    Author(string name, int age, string email) {
        this->Name = name;
        this->Age = age;
        this->Email = email;
    }

    string getName() {
        return Name;
    }

    int getAge() {
        return Age;
    }

    string getEmail() {
        return Email;
    }

    void setAge(int Age) {
        this->Age = Age;
    }

    void setEmail(string Email) {
        this->Email = Email;
    }
};

class Book {
private:
    string Name;
    int Price;
    Author arr[3];
public:
    Book(string Name, int Price, Author arr[3]) {
        this->Name = Name;
        this->Price = Price;
        this->arr[3] = arr[3];
    }

    string getName() {
        return Name;
    }

    int getPrice() {
        return Price;
    }

    Author getarr() {
        return arr[3];
    }

    void setPrice(int Price) {
        this->Price = Price;
    }

    string getAuthorNames() {
        string names = "";
        for (int i = 0; i < 3; i++) {
            names += arr[i].getName();
        }
    }
};

class Point2D {
public:
    int x;
    int y;


    Point2D() {
        x = y = 0;
    }

    Point2D(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getx() {
        return x;
    }

    void setx(int x) {
        this->x = x;
    }

    int gety() {
        return y;
    }

    void sety(int y) {
        this->y = y;

    }

    int* getxy() {
        int coordinates[2];
        coordinates[0] = x;
        coordinates[1] = y;
        return coordinates;
    }

    void setxy(int x, int y) {
        this->x = x;
        this->y = y;
    }

    double DistanceTo(const Point2D& another) {
        int dx = x - another.x;
        int dy = y - another.y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Rectangle {
    Point2D bottomLeft;
    Point2D topRight;
public:
    Rectangle(int x1, int y1, int x2, int y2) {
        bottomLeft = Point2D(x1, y1);
        topRight = Point2D(x2, y2);
    }
    double getArea() {
        int width = topRight.x - bottomLeft.x;
        int height = topRight.y - bottomLeft.y;
        return abs(width) * abs(height);
    }

    double getPerimeter() {
        int width = topRight.x - bottomLeft.x;
        int height = topRight.y - bottomLeft.y;
        return (abs(width) + abs(height)) * 2;
    }
    double Distanceto(Rectangle another) {
        double centerX1 = (bottomLeft.x + topRight.x) / 2.0;
        double centerY1 = (bottomLeft.y + topRight.y) / 2.0;
        double centerX2 = (another.bottomLeft.x + another.topRight.x) / 2.0;
        double centerY2 = (another.bottomLeft.y + another.topRight.y) / 2.0;

        int dx = centerX1 - centerX2;
        int dy = centerY1 - centerY2;

        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    Rectangle ABCD(1, 1, 6, 4);
    cout << "Area of Rectangle ABCD is equal to " << ABCD.getArea() << endl;
    cout << "Perimeter of Rectangle ABCD is equal to " << ABCD.getPerimeter() << endl;
    Rectangle ABCD_2(1, -5, 5, -2);
    cout << "Area of Rectangle ABCD is equal to " << ABCD_2.getArea() << endl;
    cout << "Perimeter of Rectangle ABCD is equal to " << ABCD_2.getPerimeter() << endl;
    cout << "Distance between center of ABCD and center of ABCD_2 is equal to " << ABCD.Distanceto(ABCD_2) << endl;

    return 0;
}