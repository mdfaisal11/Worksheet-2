#include <iostream>
using namespace std;
class FindMax
{
    int int1,int2,maxIntTwo;
    float float1, float2, maxFloatTwo;
    int int3, int4, int5, maxIntThree;
    float int6,float3,maxIntFloat;

public:
    void getData()
    {
        cout << "Enter two integers: "<<endl;
        cin >> int1 >> int2;

        cout << "Enter two float numbers: "<<endl;
        cin >> float1 >> float2;

        cout << "Enter three integers: "<<endl;
        cin >> int3 >> int4 >> int5;

        cout << "Enter one integer and one float: "<<endl;
        cin >> int6 >> float3;
    }

    int findMax(int a, int b)
    {
        return (a > b) ? a : b;
    }

    float findMax(float a, float b)
    {
        return (a > b) ? a : b;
    }

    int findMax(int a, int b, int c)
    {
        return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    }

    float findMax(int a, float b)
    {
        return (a > b) ? a : b;
    }

    void calculate()
    {
        maxIntTwo = findMax(int1, int2);
        maxFloatTwo = findMax(float1, float2);
        maxIntThree = findMax(int3, int4, int5);
        maxIntFloat = findMax(int6, float3);
    }

    void display()
    {
        cout << "Max of two integers: " << maxIntTwo << endl;
        cout << "Max of two floats: " << maxFloatTwo << endl;
        cout << "Max of three integers: " << maxIntThree << endl;
        cout << "Max of an integer and a float: " << maxIntFloat << endl;
    }
};
int main()
{
    FindMax m1;
    m1.getData();
    m1.calculate();
    m1.display();

    return 0;
}
