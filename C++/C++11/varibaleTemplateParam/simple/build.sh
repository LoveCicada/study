#! /bin/bash

echo "va_arg"
g++ -o ./bin/va_arg va_arg.cpp 

echo "variadic_template_tuple"
g++ -o ./bin/variadic_template_tuple variadic_template_tuple.cpp -std=c++11

echo "Multiply"
g++ -o ./bin/Multiply Multiply.cpp -std=c++11

echo "VTPrint"
g++ -o ./bin/VTPrint VTPrint.cpp -std=c++11

echo "complex_variable_template"
g++ -o ./bin/complex_variable_template complex_variable_template.cpp -std=c++11

echo "multi_template_params"
g++ -o ./bin/multi_template_params multi_template_params.cpp -std=c++11

echo "variadicType_forward"
g++ -o ./bin/variadicType_forward variadicType_forward.cpp -std=c++11