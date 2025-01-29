/*
  Write a menu drivenprogram to calculate the area of the given shapes using classes.
*/

#include <iostream>

using namespace std;


class Square {
    private:
        unsigned int length;
    public:
        Square(unsigned int length): length(length) {}
        Square(): length(1) {}

        unsigned int get_area();
};



class Cube {
    private:
        unsigned int length;
    public:
        Cube(unsigned int length): length(length) {}
        Cube(): length(1) {}

        unsigned int get_area();
};



class Rectangle {
    private:
        unsigned int length, breadth;
    public:
        Rectangle(unsigned int length, unsigned int breadth): length(length), breadth(breadth) {}
        Rectangle(): length(1), breadth(1) {}

        unsigned int get_area();
};



class Cuboid {
    private:
        unsigned int length, breadth, height;
    public:
        Cuboid(unsigned int length, unsigned int breadth, unsigned int height): length(length), breadth(breadth), height(height) {}
        Cuboid(): length(1), breadth(1), height(1) {}

        unsigned int get_area();
};



void menu(void);


int main(void) {

    while (true)
        menu();

    return 0;
}


void menu(void) {
    char choice;

    cout << "a. Square" << endl
    << "b. Cube" << endl
    << "c. Rectangle" << endl
    << "d. Cuboid" << endl
    << "e. Exit" << endl;

    cout << "Enter choice: ";
    cin >> choice;

    int length, breadth, height;
    Square sqr;
    Cube cube;
    Rectangle rect;
    Cuboid cuboid;

    switch (choice) {
    case 'a':
    case 'A':
        cout << "Enter length: ";
        cin >> length;
        sqr = Square(length);

        cout << "Area of given square of side length "
        << length << " is " << sqr.get_area() << " units" << endl;
        break;

    case 'b':
    case 'B':
        cout << "Enter length: ";
        cin >> length;
        cube = Cube(length);

        cout << "Surface area of give cube of side length "
        << length << " is " << cube.get_area() << " units" << endl;
        break;
    
    case 'c':
    case 'C':
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
        rect = Rectangle(length, breadth);

        cout << "Area of given rectangle of side length "
        << length << " and breadth " << breadth << " is " << rect.get_area() << " units" << endl;
        break;

    case 'd':
    case 'D':
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
        cout << "Enter height: ";
        cin >> height;
        cuboid = Cuboid(length, breadth, height);

        cout << "Surface area of given cuboid of side length "
        << length << ", breadth " << breadth << " and height "<< height 
        << " is " << cuboid.get_area() << " units" << endl;
        break;

    case 'e':
    case 'E':
        exit(0);

    default:
        cout << "Invalid choice!" << endl;
    }

    cout << endl << endl;
}


unsigned int Square::get_area() {
    return this->length * this->length;
}


unsigned int Cube::get_area() {
    return 6 * this->length * this->length;
}


unsigned int Rectangle::get_area() {
    return this->length * this->breadth;
}


unsigned int Cuboid::get_area() {
    return 2 * (this->length * this->breadth + this->length * this->height + this->breadth * this->height);
}