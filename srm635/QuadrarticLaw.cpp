#include <iostream>
#include <math.h>

using namespace std;

class QuadraticLaw {
    public:
        static long long getTime(long long d);
};

long long QuadraticLaw::getTime(long long d)
{
    double t = 0.0;
    t = (int)((sqrt(1 + 4.0*d) - 1.0)/2.0);

    return t;
}

int main(int argc, char** argv)
{
    cout << QuadraticLaw::getTime(1) << endl;
    cout << QuadraticLaw::getTime(2) << endl;
    cout << QuadraticLaw::getTime(5) << endl;
    cout << QuadraticLaw::getTime(6) << endl;
    cout << QuadraticLaw::getTime(7) << endl;
    cout << QuadraticLaw::getTime(1482) << endl;
    cout << QuadraticLaw::getTime(1000000000000000000) << endl;
    cout << QuadraticLaw::getTime(31958809614643170) << endl;

    return 0;
}
