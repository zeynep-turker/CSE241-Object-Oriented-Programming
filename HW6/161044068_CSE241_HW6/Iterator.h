#ifndef ITERATOR_H
#define ITERATOR_H
template <class E>
class Iterator {
public:
    virtual bool hasNext()=0;
    virtual E next()=0;
    virtual void remove()=0;
protected: 
};

#endif /* ITERATOR_H */

