#ifndef HASHSET_H
#define HASHSET_H
#include "Collection.h"
#include"Iterator.h"
#include "HashSetItr.h"
#include "Set.h"
#include <set>
using namespace SetNameSpace;
template <class E,template<class...>class T>
class HashSet : public Set<E,T>{
    public:
        virtual Iterator<E>* iterator();
        virtual void add(E e);
        virtual void addAll(Collection<E,T> &c);
        virtual void clear();
        virtual bool contains(E e);
        virtual bool containsAll(Collection<E,T> &c);
        virtual bool isEmpty();
        virtual bool remove(E e);
        virtual bool removeAll(Collection<E,T> &c);
        virtual bool retainAll(Collection<E,T> &c);
        virtual int size();
        T<E> getSet()const { return s; }
    private:
        T<E> s;
};
template <class E,template<typename...>class T>
Iterator<E>* HashSet<E,T>::iterator(){
    HashSetItr<E> a(s.begin(),s.end());
    Iterator<E>* itr = new HashSetItr<E>(a);
    return itr;
}
template <class E,template<class...>class T>
void HashSet<E,T>::add(E e){
    s.insert(e);
}
template <class E,template<typename...>class T>
void HashSet<E,T>::addAll(Collection<E,T>& c){
    Iterator<E> *hsItr2 = dynamic_cast<HashSet<E,T>&>(c).iterator();
    while(hsItr2->hasNext()){
        s.insert(hsItr2->next());
    }
}
template <class E,template<typename...>class T>
void HashSet<E,T>::clear(){
    s.clear();
}
template <class E,template<typename...>class T>
bool HashSet<E,T>::contains(E e){
    Iterator<E> *itr = this->iterator();
    while(itr->hasNext()){
        if(e == itr->next())
            return true;
    }
    return false;    
}
template <class E,template<typename...>class T>
bool HashSet<E,T>::containsAll(Collection<E,T> &c){
    bool temp;
    E temp2;
    Iterator<E> *itr = this->iterator();
    Iterator<E> *itr2 = dynamic_cast<HashSet<E,T>&>(c).iterator();
    while(itr2->hasNext()){
        temp=false;
        temp2=itr2->next();
        while(itr->hasNext()){
            if(temp2 == itr->next()){
                temp=true;
            }         
        }
        if(temp == false)
            return false;
    }
    return temp;
}
template <class E,template<typename...>class T>
bool HashSet<E,T>::isEmpty(){
    if(s.size() == 0)
        return true;
    return false;
}
template <class E,template<typename...>class T>
bool HashSet<E,T>::remove(E e){
    E temp;
    Iterator<E> *itr = this->iterator();
    while(itr->hasNext()){
        temp = itr->next();
        if(e == temp){        
            s.erase(temp);
            return true;
        }
    }
    return false;  
}
template <class E,template<typename...>class T>
bool HashSet<E,T>::removeAll(Collection<E,T> &c){
    Iterator<E> *itr = dynamic_cast<HashSet<E,T>&>(c).iterator();
    Iterator<E> *itr2 = this->iterator();
    E temp;
    while(itr->hasNext()){
        temp = itr->next();
        while(itr2->hasNext()){
            if(temp == itr2->next()){
                s.erase(temp);
            }
        }
    }
    return true;
}
template <class E,template<typename...>class T>
bool HashSet<E,T>::retainAll(Collection<E,T> &c){
    bool temp;
    Iterator<E> *itr2 = this->iterator();
    E temp2,temp3;
    while(itr2->hasNext()){
        temp2 = itr2->next();
        temp=false;
        Iterator<E> *itr = dynamic_cast<HashSet<E,T>&>(c).iterator();
        while(itr->hasNext()){
            temp3 = itr->next();
            if(temp2 == temp3)
                temp = true;          
        }
        if(temp == false)
            s.erase(temp2);    
    }
    return temp;
}
template <class E,template<typename...>class T>
int HashSet<E,T>::size(){
    return s.size();
}
#endif /* HASHSET_H */

