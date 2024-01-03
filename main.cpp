#include <iostream>
#include <string>
#include "support_functions.h"
#include <exception>

using std::string;
using std::cout;
using std::endl;


string fbrm( const int& k ) {
    if( k < 1 ) return string{ "invalid" };
    if( k%15 == 0 ) return string{ "FizzBuzz" };
    if( k%3 == 0 ) return string{ "Fizz" };
    if( k%5 == 0 ) return string{ "Buzz" };
    return std::to_string( k );
}
void fbrm_large_test( int testRangeStart, int testRangeEnd ) {
    for( int i {testRangeStart}; i <= testRangeEnd; ++i ) {
        if( fbrm(i) == std::to_string(i) ) {
            if( i%3 == 0 ) throw ( "fbrm() 3-fault" );
            if( i%5 == 0 ) throw( "fbrm() 5-fault" );
            if( i%15 == 0 ) throw( "fbrm() 15-fault" );
        }
        if( fbrm(i) == "Fizz" ) {
            if( i%3 != 0 ) throw( "fbrm() Fizz-fault" );
        }
        if( fbrm(i) == "Buzz" ) {
            if( i%5 != 0 ) throw( "fbrm() Buzz-fault" );
        }
        if( fbrm(i) == "FizzBuzz" ) {
            if( i%15 != 0 ) throw( "fbrm() FizzBuzz-fault" );
        }
    }
    cout << "fbrm_large_test() ok from " << testRangeStart
         << " to " << testRangeEnd << endl;
}


int main() try
{
    cout << "Hello World!" << endl;

    check_string( "1", fbrm( 1 ), "1.Packung" );
    check_string( "invalid", fbrm( 0 ), "0.Packung" );
    check_string( "invalid", fbrm( -1 ),
                 "-1.Packung, e.c. negative Zahlen" );
    check_string( "Fizz", fbrm( 3 ), "Fizz in 3.Packung" );
    int maxProdSize {20};
    for( int i {3}; i <= maxProdSize; i += 3 ) {
        if( i%5 == 0 ) continue;
        check_string( "Fizz", fbrm( i ),
                     "Fizz in " + std::to_string( i ) + ".Packung");
    }
    check_string( "4", fbrm( 4 ), "4.Packung" );
    check_string( "Buzz", fbrm( 5 ), "Buzz in 5.Packung" );
    for( int i {5}; i <= maxProdSize; i += 5 ) {
        if( i%3 == 0 ) continue;
        check_string( "Buzz", fbrm( i ),
                     "Buzz in " + std::to_string( i ) + ".Packung");
    }
    for( int i {15}; i <= maxProdSize; i += 15 )
        check_string( "FizzBuzz", fbrm( i ),
                     "FizzBuzz in " + std::to_string( i ) + ".Packung");
    return 0;
}
catch (std::exception &e) {
    std::cerr << "exception " << e.what();
    return -2;
} catch (...) {
    std::cerr << "unknown exception";
    return -1;
}

