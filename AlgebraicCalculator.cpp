#include <iostream>
using namespace std;

#include "Term.hpp"

int main(int argc, char *argv[] )
{
    Term T = Term(1, MakeVList( {'x', 'y'} , {2, 5} ));
    Term P = Term(1, MakeVList( {'i'} , {5} ));
    if (P.IsCompatible(T)) {
        cout << "compatible" << endl;
    }
    cout << T.out() << endl;
    
    return 0;
}
