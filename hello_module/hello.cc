#include "public/hello.h"
#include <iostream>


namespace hello {

using std::cout;
using std::endl;

bool PrintHelloWorld() {
    cout << "Hello World from hello module" << endl;
    return true;
}

} // namespace hello