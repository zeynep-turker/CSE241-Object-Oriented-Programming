#ifndef HASHSETITR_H
#define HASHSETITR_H
#include "Iterator.h"
#include <iostream>
#include <set>
using namespace std;
template <class E>
class HashSetItr : public Iterator<E> {
protected:
    typename set<E>::iterator a,d;
public:
    HashSetItr(typename set<E>::iterator b,typename set<E>::iterator c){a=b; d=c;}
    bool hasNext();
    E next();
    void remove();

};
template <class E>
bool HashSetItr<E>::hasNext(){
    if(a != d)
        return true;
    return false;
}
template <class E>
E HashSetItr<E>::next(){   
    if(hasNext() == true)
       return *(a++);
}
template <class E>
void HashSetItr<E>::remove(){
 
}

#endif /* HASHSETITR_H */

