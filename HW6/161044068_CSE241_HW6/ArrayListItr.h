#ifndef ARRAYLISTITR_H
#define ARRAYLISTITR_H
#include "Iterator.h"
template <class E>
class ArrayListItr : public Iterator<E>{
public:
    ArrayListItr(E *r){p=r;}
    bool hasNext();
    E next();
    void remove();
    void set(int num){size = num;}
protected:
    E *p;
    int size;
    int where =0;
};
template <class E>
bool ArrayListItr<E>::hasNext(){
    if(where < size)
        return true;
    return false;
}
template <class E>
E ArrayListItr<E>::next(){
    if(hasNext() == true)
        return p[where++];
}
template <class E>
void ArrayListItr<E>::remove(){
    delete p;
}

#endif /* ARRAYLISTITR_H */

