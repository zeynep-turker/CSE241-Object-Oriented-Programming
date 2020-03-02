#ifndef MYEXCEPTIONCLASS_H
#define MYEXCEPTIONCLASS_H
#include <exception>
using namespace std;
struct IndexOutOfRangeException : public exception {
   const char * what () const throw () {
      return "Index out of range";
   }
};

#endif /* MYEXCEPTIONCLASS_H */

