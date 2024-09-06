#include <iostream>
#include <cmath>
using namespace std;


class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) {
        this->length = length;
        this->width = width;
    }
    
    Rectangle() {
        length = 1;
        width = 1;
    }

    double getLength()  {
        return length;
    }

    void setLength(double length) {
            this->length = length;
    }

    double getWidth()  {
        return width;
    }

    void setWidth(double width) {
            this->width = width;
    }

    double getArea()  {
        return length * width;
    }

    double getPerimeter()  {
        return 2 * (length + width);
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    

};

class Point2D {
public:
    int x;
    int y;


    Point2D() {
        x = y = 0;
    }

    Point2D(int x , int y) {
        this->x = x;
        this->y = y;
    }

    int getx()  {
        return x;
    }

    void setx(int x) {
            this->x = x;
    }

    int gety()  {
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

    double DistanceTo(const Point2D& another)  {
        int dx = x - another.x;
        int dy = y - another.y;
        return sqrt(dx * dx + dy * dy);
    }
};


class Point3D : public Point2D {
    int z;
public:
    Point3D() {
        z = 0;
    }

    Point3D(int x, int y, int z) : Point2D(x, y) {
        this->z = z;
    }
    int getz() {
        return z;
    }

    void setz(int z) {
        this->z = z;
    }

    int* getxyz() {
        int coordinates[3];
        coordinates[0] = x;
        coordinates[1] = y;
        coordinates[2] = z;
        return coordinates;
    }

    double DistanceTo( Point3D another)  {
        int dx = x - another.x;
        int dy = y - another.y;
        int dz = z - another.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
    
};

int main() {
    Point2D p1(1, 2);
    Point2D p2(4, 6);

    cout << "Distance between p1 and p2 =  " << p1.DistanceTo(p2) << endl;

    Point3D p3(1, 2, 3);
    Point3D p4(4, 6, 8);

    cout << "Distance between p3 and p4 =  " << p3.DistanceTo(p4) << endl;
    return 0;
}
