#include <iostream>
#include <string>
#include <cmath>
const double PI = 3.14;
using namespace std;
class Shape3D {
protected:
    double sideLength;

public:
    Shape3D(double length) : sideLength(length) {}

    virtual double getArea() const = 0;
    virtual double getSurfaceArea() const = 0;
    virtual double getVolume() const = 0;
    virtual string IsA() const = 0;
    virtual void print() const = 0;
    virtual void read() = 0;
};

class Cube : public Shape3D {
public:
    Cube(double length) : Shape3D(length) {}

    double getArea() const override {
        return sideLength * sideLength;
    }

    double getSurfaceArea() const override {
        return 6 * sideLength * sideLength;
    }

    double getVolume() const override {
        return sideLength * sideLength * sideLength;
    }

    string IsA() const override {
        return "Cube";
    }

    void print() const override {
        cout << "Cube: Side Length = " << sideLength << endl;
    }

    void read() override {
        cout << "Enter the side length of the Cube: ";
        cin >> sideLength;
    }
};

class Cone : public Shape3D {
public:
    Cone(double length) : Shape3D(length) {}

    double getArea() const override {
        return PI * sideLength * (sideLength + sqrt(sideLength * sideLength + sideLength * sideLength));
    }

    double getSurfaceArea() const override {
        return PI * sideLength * (sideLength + sqrt(sideLength * sideLength + sideLength * sideLength)) + PI * sideLength * sideLength;
    }

    double getVolume() const override {
        return (1.0 / 3.0) * PI * sideLength * sideLength * sideLength;
    }

    string IsA() const override {
        return "Cone";
    }

    void print() const override {
        cout << "Cone: Side Length = " << sideLength << endl;
    }

    void read() override {
        cout << "Enter the side length of the Cone: ";
        cin >> sideLength;
    }
};

class Pyramid : public Shape3D {
public:
    Pyramid(double length) : Shape3D(length) {}

    double getArea() const override {
        return sideLength * sideLength;
    }

    double getSurfaceArea() const override {
        return sideLength * sideLength + 2 * sideLength * sqrt((sideLength / 2.0) * (sideLength / 2.0) + sideLength * sideLength);
    }

    double getVolume() const override {
        return (1.0 / 3.0) * sideLength * sideLength * sideLength;
    }

    string IsA() const override {
        return "Pyramid";
    }

    void print() const override {
        cout << "Pyramid: Side Length = " << sideLength << endl;
    }

    void read() override {
        cout << "Enter the side length of the Pyramid: ";
        cin >> sideLength;
    }
};

class Cuboid : public Shape3D {
public:
    Cuboid(double length) : Shape3D(length) {}

    double getArea() const override {
        return sideLength * sideLength;
    }

    double getSurfaceArea() const override {
        return 6 * sideLength * sideLength;
    }

    double getVolume() const override {
        return sideLength * sideLength * sideLength;
    }

    string IsA() const override {
        return "Cuboid";
    }

    void print() const override {
        std::cout << "Cuboid: Side Length = " << sideLength << std::endl;
    }

    void read() override {
        cout << "Enter the side length of the Cuboid: ";
        cin >> sideLength;
    }
};

class Tetrahedron : public Shape3D {
public:
    Tetrahedron(double length) : Shape3D(length) {}

    double getArea() const override {
        return sqrt(3) * sideLength * sideLength / 4;
    }

    double getSurfaceArea() const override {
        return sqrt(3) * sideLength * sideLength;
    }

    double getVolume() const override {
        return (sideLength * sideLength * sideLength) / (6 * sqrt(2));
    }

    string IsA() const override {
        return "Tetrahedron";
    }

    void print() const override {
        cout << "Tetrahedron: Side Length = " << sideLength << std::endl;
    }

    void read() override {
        cout << "Enter the side length of the Tetrahedron: ";
        cin >> sideLength;
    }
};

class Sphere : public Shape3D {
public:
    Sphere(double length) : Shape3D(length) {}

    double getArea() const override {
        return 4 * PI * sideLength * sideLength;
    }

    double getSurfaceArea() const override {
        return 4 * PI * sideLength * sideLength * sideLength / 3;
    }

    double getVolume() const override {
        return (4.0 / 3.0) * PI * sideLength * sideLength * sideLength;
    }

    string IsA() const override {
        return "Sphere";
    }

    void print() const override {
        cout << "Sphere: Radius = " << sideLength << endl;
    }

    void read() override {
        cout << "Enter the radius of the Sphere: ";
        cin >> sideLength;
    }
};

class Cylinder : public Shape3D {
public:
    Cylinder(double length) : Shape3D(length) {}

    double getArea() const override {
        return PI * sideLength * sideLength;
    }

    double getSurfaceArea() const override {
        return 2 * PI * sideLength * (sideLength + sideLength);
    }

    double getVolume() const override {
        return PI * sideLength * sideLength * sideLength;
    }

    std::string IsA() const override {
        return "Cylinder";
    }

    void print() const override {
        cout << "Cylinder: Radius = " << sideLength << endl;
    }

    void read() override {
        cout << "Enter the radius of the Cylinder: ";
        cin >> sideLength;
    }
};

void addShape(Shape3D* shapes[], int& shapeCount) {
    if (shapeCount < 10) {
        int shapeType;
        cout << "Select a shape type (1 = Cube, 2 = Cone, 3 = Pyramid, 4 = Cuboid, 5 = Tetrahedron, 6 = Sphere, 7 = Cylinder): ";
        cin >> shapeType;

        switch (shapeType) {
        case 1:
            shapes[shapeCount] = new Cube(0.0);
            break;
        case 2:
            shapes[shapeCount] = new Cone(0.0);
            break;
        case 3:
            shapes[shapeCount] = new Pyramid(0.0);
            break;
        case 4:
            shapes[shapeCount] = new Cuboid(0.0);
            break;
        case 5:
            shapes[shapeCount] = new Tetrahedron(0.0);
            break;
        case 6:
            shapes[shapeCount] = new Sphere(0.0);
            break;
        case 7:
            shapes[shapeCount] = new Cylinder(0.0);
            break;
        default:
            cout << "Invalid shape type." << endl;
            return;
        }

        shapes[shapeCount]->read();
        shapeCount++;
    }
    else {
        cout << "Shape list is full." << endl;
    }
}

void deleteShape(Shape3D* shapes[], int& shapeCount) {
    if (shapeCount > 0) {
        cout << "Enter the index of the shape to delete (0 to " << shapeCount - 1 << "): ";
        int index;
        cin >> index;

        if (index >= 0 && index < shapeCount) {
            delete shapes[index];

            for (int i = index; i < shapeCount - 1; i++) {
                shapes[i] = shapes[i + 1];
            }

            shapeCount--;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
    else {
        cout << "No shapes to delete." << endl;
    }
}

void printShapes(Shape3D* shapes[], int shapeCount) {
    for (int i = 0; i < shapeCount; i++) {
        std::cout << "Shape " << i << ": ";
        shapes[i]->print();
        cout << "Area: " << shapes[i]->getArea() << ", Surface Area: " << shapes[i]->getSurfaceArea() << ", Volume: " << shapes[i]->getVolume() << endl;
    }
}

void sortShapesBySurfaceArea(Shape3D* shapes[], int shapeCount) {
    for (int i = 0; i < shapeCount - 1; i++) {
        for (int j = 0; j < shapeCount - i - 1; j++) {
            if (shapes[j]->getSurfaceArea() > shapes[j + 1]->getSurfaceArea()) {

                Shape3D* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;

            }
        }
    }
}

void findMinMaxVolume(Shape3D* shapes[], int shapeCount) {
    if (shapeCount > 0) {
        const Shape3D* minVolumeShape = shapes[0];
        const Shape3D* maxVolumeShape = shapes[0];

        for (int i = 1; i < shapeCount; i++) {
            if (shapes[i]->getVolume() < minVolumeShape->getVolume()) {
                minVolumeShape = shapes[i];
            }

            if (shapes[i]->getVolume() > maxVolumeShape->getVolume()) {
                maxVolumeShape = shapes[i];
            }
        }

        cout << "Shape with minimum volume: " << minVolumeShape->IsA() << ", Volume: " << minVolumeShape->getVolume() << endl;
        cout << "Shape with maximum volume: " << maxVolumeShape->IsA() << ", Volume: " << maxVolumeShape->getVolume() << endl;
    }
    else {
        cout << "No shapes to find minimum and maximum volume." << endl;
    }
}
