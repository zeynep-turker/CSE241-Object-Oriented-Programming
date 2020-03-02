#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "Collection.h"
#include "Iterator.h"
#include "List.h"
#include "ArrayListItr.h"
#include <vector>
template <class E,template<class...>class T>
class ArrayList : public Collection<E,T>{
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
    T<E> getVect()const { return v; }
private:
    T<E> v;
    E *p; 
};
template <class E,template<typename...>class T>
Iterator<E>* ArrayList<E,T>::iterator(){
    p=&(v[0]);
    ArrayListItr<E> itr(p);
    itr.set(v.size());
    Iterator<E>* itr2 = new ArrayListItr<E>(itr);
    return itr2; 
}
template <class E,template<typename...>class T>
void ArrayList<E,T>::add(E e){
      v.push_back(e);
}
template <class E,template<typename...>class T>
void ArrayList<E,T>::addAll(Collection<E,T>& c){
    int size = dynamic_cast<ArrayList<E,T>&>(c).getVect().size();
    for(int i=0; i<size; i++)
        v.push_back(dynamic_cast<ArrayList<E,T>&>(c).getVect()[i]);
       
}
template <class E,template<typename...>class T>
void ArrayList<E,T>::clear(){
    v.clear();
}
template <class E,template<typename...>class T>
bool ArrayList<E,T>::contains(E e){
    for(int i=0; i<v.size(); ++i){
        if(e == v[i])
            return true;
    }
    return false;    
}
template <class E,template<typename...>class T>
bool ArrayList<E,T>::containsAll(Collection<E,T> &c){
    bool temp;
    int size = dynamic_cast<ArrayList<E,T>&>(c).getVect().size();
    for(int i=0; i<size; ++i){
        temp=false;
        for(int j=0; j<v.size(); ++j){
            if(dynamic_cast<ArrayList<E,T>&>(c).getVect()[i] == v[j]){
                temp=true;
            }           
        }
        if(temp == false)
            return false;
    }
    return temp;
}
template <class E,template<typename...>class T>
bool ArrayList<E,T>::isEmpty(){
    if(v.size() == 0)
        return true;
    return false;
}
template <class E,template<typename...>class T>
bool ArrayList<E,T>::remove(E e){
    int index;
    for(int i=0; i<v.size(); ++i){
        if(e == v[i]){
            index=i;
            v.erase(v.begin()+index);
            return true;
        }
    }
    return false;  
}
template <class E,template<typename...>class T>
bool ArrayList<E,T>::removeAll(Collection<E,T> &c){
    int size=dynamic_cast<ArrayList<E,T>&>(c).getVect().size();
    for(int i=0; i<size; ++i){
        for(int j=0; j<v.size(); ++j){
            if(dynamic_cast<ArrayList<E,T>&>(c).getVect()[i] == v[j]){
                v.erase(v.begin() + j);
            }
        }
    }
    return true;
}
template <class E,template<typename...>class T>
bool ArrayList<E,T>::retainAll(Collection<E,T> &c){
    bool temp;
    int size = dynamic_cast<ArrayList<E,T>&>(c).getVect().size();
    for(int i=0; i<v.size(); ++i){
        temp=false;
        for(int j=0; j<size; ++j){
            if(v[i] == dynamic_cast<ArrayList<E,T>&>(c).getVect()[j])
                temp = true;          
        }
        if(temp == false)
            v.erase(v.begin() + i);             
    }
    return temp;
}
template <class E,template<typename...>class T>
int ArrayList<E,T>::size(){
    return v.size();
}
#endif /* ARRAYLIST_H */

