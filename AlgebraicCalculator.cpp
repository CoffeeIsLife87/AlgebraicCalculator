#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main()
{
    Parabola P = Parabola(8, -59, 21);
    cout << P.out() << endl;

    return 0;
}
