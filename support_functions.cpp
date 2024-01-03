#include "support_functions.h"

void print_test(const bool &successful, const string &testType, const string &description, const string &expected, const string &actual)
{
    if( !successful ) cout << "FAILED test ";
    else cout << " succeeded test ";
    cout << testType << '(' << description << ')';
    cout << ", expected: " << expected;
    cout << ", actual: " << actual << endl;
}

bool check_int(const int &exp, const int &act, const string &description, const bool &silent)
{
    const bool result{ exp == act };
    if( !silent )
        print_test( result,
                   "check_int",
                   description,
                   std::to_string( exp ),
                   std::to_string( act ) );
    return result;
}

bool check_string(const string &exp, const string &act, const string &description, const bool &silent)
{
    const bool result{ exp == act };
    if( !silent )
        print_test( result,
                   "check_string",
                   description,
                   exp,
                   act );
    return result;
}

bool check_double(const double &exp, const double &act, const double &precision, const string &description, const bool &silent)
{
    const double difference { ( act < exp ) ?
                                ( exp-act ) : ( act-exp ) };
    const bool result{ difference <= precision };
    if( !silent )
        print_test( result,
                   "check_double",
                   description,
                   std::to_string( exp ),
                   std::to_string( act ) );
    return result;
}
