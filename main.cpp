#include <iostream>
#include <string>
#include "support_functions.h"

using std::string;
using std::cout;
using std::endl;


string fbrm( const int& k ) {
    if( k == 1 ) return string{ "1" };
    return string{ "invalid" };
}



int main()
{
    cout << "Hello World!" << endl;

    check_string( "1", fbrm( 1 ), "1.Packung" );
    check_string( "invalid", fbrm( 0 ), "0.Packung" );
    check_string( "invalid", fbrm( -1 ),
                 "-1.Packung, e.c. negative Zahlen" );

    return 0;
}
