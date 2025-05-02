#include "Shape3D.h"

int main() {
    Shape3D* shapes[10];
    int shapeCount = 0;

    while (true) {
        cout << "Select an operation (1 = Add Shape, 2 = Delete Shape, 3 = Print Shapes, 4 = Sort by Surface Area, 5 = Find Min/Max Volume, 6 = Quit): ";
        int operation;
        cin >> operation;

        switch (operation) {
        case 1:
            addShape(shapes, shapeCount);
            break;
        case 2:
            deleteShape(shapes, shapeCount);
            break;
        case 3:
            printShapes(shapes, shapeCount);
            break;
        case 4:
            sortShapesBySurfaceArea(shapes, shapeCount);
            break;
        case 5:
            findMinMaxVolume(shapes, shapeCount);
            break;
        case 6:
            for (int i = 0; i < shapeCount; i++) {
                delete shapes[i];
            }
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
