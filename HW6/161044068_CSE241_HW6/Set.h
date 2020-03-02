#ifndef SET_H
#define SET_H
#include "Collection.h"
namespace SetNameSpace{
    template <class E,template<class...>class T>
    class Set : public Collection<E,T> {
        public:
        virtual Iterator<E>* iterator()=0;
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

    };
}


#endif /* SET_H */

