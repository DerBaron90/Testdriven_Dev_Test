#ifndef SUPPORT_FUNCTIONS_H
#define SUPPORT_FUNCTIONS_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;


void print_test( const bool& successful,
                const string& testType,
                const string& description,
                const string& expected = "",
                const string& actual = "");

bool check_int( const int& exp, const int& act,
               const string& description,
               const bool& silent=false);

bool check_string( const string& exp, const string& act,
                  const string& description,
                  const bool& silent=false);

bool check_double( const double& exp, const double& act,
                  const double& precision,
                  const string& description,
                  const bool& silent=false);

#endif // SUPPORT_FUNCTIONS_H
