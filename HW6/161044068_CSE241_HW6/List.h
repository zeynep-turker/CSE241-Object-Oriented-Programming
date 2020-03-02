#ifndef LIST_H
#define LIST_H
#include "Collection.h"
#include <iostream>
template <class E,template<class...>class T>
class List : public Collection<E,T>{
    virtual void add(E e)=0;
    virtual void addAll(Collection<E,T> &c)=0;
    virtual void clear()=0;
    virtual bool contains(E e)=0;
    virtual bool containsAll(Collection<E,T> &c)=0;
    virtual bool isEmpty()=0;
    virtual bool remove(E e)=0;        
    virtual bool removeAll(Collection<E,T> &c)=0;
    virtual bool retainAll(Collection<E,T> &c)=0;
    virtual int size()=0;
	virtual void element()=0;
	virtual void offer(E e)=0;
	virtual void poll()=0;
};


#endif /* LIST_H */

