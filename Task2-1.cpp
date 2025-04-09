#include <iostream>
using namespace std;

class Circle
{
    float radius;
public:
    Circle(float r)
    {
        radius = r;
    }
    void compareTwoCircles(Circle c1, Circle c2)
    {
        float area1 = 3.14159 * c1.radius * c1.radius;
        float area2 = 3.14159 * c2.radius * c2.radius;

        if (area1 > area2)
            cout << "First circle has a larger area"<<endl;
        else if (area2 > area1)
            cout << "Second circle has a larger area"<<endl;
        else
            cout << "Both circles have the same area"<<endl;
    }
};
int main() {
    float r1, r2;
    cout << "Enter the radius of first circle: ";
    cin >> r1;
    cout << "Enter the radius of second circle: ";
    cin >> r2;

    Circle c1(r1), c2(r2);
    c1.compareTwoCircles(c1, c2);

    return 0;
}
