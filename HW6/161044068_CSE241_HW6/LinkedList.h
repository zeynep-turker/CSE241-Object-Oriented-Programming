#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "List.h"
#include "Queue.h"
template <class E,template<class,class>class T>
class LinkedList : public List<E,T>,public Queue<E,T>{
public:
	void add(E e){};
 	void addAll(Collection<E,T> &c){};
 	void clear(){};
 	bool contains(E e){};
 	bool containsAll(Collection<E,T> &c){};
 	bool isEmpty(){};
 	bool remove(E e){};        
 	bool removeAll(Collection<E,T> &c){};
 	bool retainAll(Collection<E,T> &c){};
 	int size(){};
 	void element(){};
 	void offer(E e){};
 	void poll(){};
   	
private:

};

#endif /* LINKEDLIST_H */

