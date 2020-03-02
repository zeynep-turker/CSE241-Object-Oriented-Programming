#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include "Iterator.h"
template <class E,template<class...>class T>
class Collection{
public:
    virtual Iterator<E>* iterator()=0;
    virtual void add(E e)=0;
    virtual void addAll(Collection &c)=0;
    virtual void clear()=0;
    virtual bool contains(E e)=0;
    virtual bool containsAll(Collection &c)=0;
    virtual bool isEmpty()=0;
    virtual bool remove(E e)=0;        
    virtual bool removeAll(Collection &c)=0;
    virtual bool retainAll(Collection &c)=0;
    virtual int size()=0;
protected :
        
};


#endif /* COLLECTION_H */

