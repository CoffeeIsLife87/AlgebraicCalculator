#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main()
{
    Parabola P = Parabola(1, -4, 28);

    cout << P.out() << endl;
    return 0;
}
