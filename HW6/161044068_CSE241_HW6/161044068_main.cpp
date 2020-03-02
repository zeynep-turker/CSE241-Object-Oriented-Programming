#include "ArrayList.h"
#include "HashSet.h"
#include "Iterator.h"
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    
    cout<<"Functions Test with HashSet<int,set>"<<endl;
    //HashSet<int,set> and Function Testing
    //add()
    cout<<"add() Function Test :"<<endl;
    HashSet<int,set> hs1,hs2;
    hs1.add(1);hs1.add(2);hs1.add(2);hs1.add(4);hs1.add(5);
    cout<<"hs1's elements: ";
    Iterator<int> *hsItr1 = hs1.iterator();
    while(hsItr1->hasNext()){
        cout<<hsItr1->next()<<" ";
    }
    //addAll()
    cout<<endl<<"addAll() Function Test :"<<endl;
    hs2.addAll(hs1);
    Iterator<int> *hsItr2 = hs2.iterator();
    cout<<"hs2's elements: ";
    while(hsItr2->hasNext()){
        cout<<hsItr2->next()<<" ";
    }
    //clear()
    cout<<endl<<"clear() Function Test :"<<endl;
    hs2.clear();
    Iterator<int> *hsItr3 = hs2.iterator();
    cout<<"hs2's elements: ";
    while(hsItr3->hasNext()){
        cout<<hsItr3->next()<<" ";
    }
    //contains()
    cout<<endl<<"contains() Function Test :"<<endl;   
    hs2.addAll(hs1);
    if(hs2.contains(2)==true)
        cout<<"2 is hs2's element."<<endl;
    else
        cout<<"2 is not hs2's element."<<endl;
    //containAll()
    cout<<"containAll() Function Test :"<<endl;
    HashSet<int,set> hs3;
    hs3.add(1);hs3.add(3);
    if(hs2.containsAll(hs3)==true)
        cout<<"hs2 contains hs3."<<endl;
    else
        cout<<"hs2 doesn't contain hs3."<<endl;
    //isEmpty()
    cout<<"isEmpty() Function Test :"<<endl;
    hs2.clear();
    if(hs2.isEmpty() == true)
        cout<<"hs2 is empty..";
    else
        cout<<"hs2 is not empty..";
    //remove()
    cout<<endl<<"remove() Function Test :"<<endl;
    hs2.remove(2);
    cout<<"hs2's elements :";
    Iterator<int> *hsItr4 = hs2.iterator();
    while(hsItr4->hasNext()){
        cout<<hsItr4->next()<<" ";
    }
    //removeAll()
    cout<<endl<<"removeAll() Function Test :"<<endl;
    hs2.clear();
    hs2.addAll(hs1);
    hs2.removeAll(hs3);
    Iterator<int> *hsItr5 = hs2.iterator();
    cout<<"hs2's elements :";
    while(hsItr5->hasNext()){
        cout<<hsItr5->next()<<" ";
    }
    //retainAll()
    cout<<endl<<"retainAll() Function Test :"<<endl;
    HashSet<int,set> hs4,hs5;
    hs4.add(1);hs4.add(2);
    hs5.add(1);hs5.add(2);hs5.add(3);
    hs5.retainAll(hs4);
    Iterator<int> *hsItr6 = hs5.iterator();
    cout<<"hs5's elements: ";
    while(hsItr6->hasNext())
        cout<<hsItr6->next()<<" ";
    //size()
    cout<<endl<<"size() Function Test :"<<endl;
    cout<<"hs5's size :"<<hs5.size()<<endl;

    cout<<endl<<endl;
    
    cout<<"Functions Test with HashSet<string,set>"<<endl;
    //HashSet<string,set> and Function Testing
    //add()
    cout<<"add() Function Test :"<<endl;
    HashSet<string,set> hss1,hss2;
    hss1.add("ali");hss1.add("ayse");hss1.add("ayse");hss1.add("feyza");hss1.add("zeynep");
    cout<<"hss1's elements: ";
    Iterator<string> *hssItr1 = hss1.iterator();
    while(hssItr1->hasNext()){
        cout<<hssItr1->next()<<" ";
    }
    //addAll()
    cout<<endl<<"addAll() Function Test :"<<endl;
    hss2.addAll(hss1);
    Iterator<string> *hssItr2 = hss2.iterator();
    cout<<"hss2's elements: ";
    while(hssItr2->hasNext()){
        cout<<hssItr2->next()<<" ";
    }
    //clear()
    cout<<endl<<"clear() Function Test :"<<endl;
    hss2.clear();
    Iterator<string> *hssItr3 = hss2.iterator();
    cout<<"hss2's elements: ";
    while(hssItr3->hasNext()){
        cout<<hssItr3->next()<<" ";
    }
    //contains()
    cout<<endl<<"contains() Function Test :"<<endl;   
    hss2.addAll(hss1);
    if(hss2.contains("ayse")==true)
        cout<<"'ayse' is hss2's element."<<endl;
    else
        cout<<"'ayse' is not hss2's element."<<endl;
    //containAll()
    cout<<"containAll() Function Test :"<<endl;
    HashSet<string,set> hss3;
    hss3.add("ali");hss3.add("rabia");
    if(hss2.containsAll(hss3)==true)
        cout<<"hss2 contains hss3."<<endl;
    else
        cout<<"hss2 doesn't contain hss3."<<endl;
    //isEmpty()
    cout<<"isEmpty() Function Test :"<<endl;
    hss2.clear();
    if(hss2.isEmpty() == true)
        cout<<"hss2 is empty..";
    else
        cout<<"hss2 is not empty..";
    //remove()
    cout<<endl<<"remove() Function Test :"<<endl;
    hss2.remove("ayse");
    cout<<"hss2's elements :";
    Iterator<string> *hssItr4 = hss2.iterator();
    while(hssItr4->hasNext()){
        cout<<hssItr4->next()<<" ";
    }
    //removeAll()
    cout<<endl<<"removeAll() Function Test :"<<endl;
    hss2.clear();
    hss2.addAll(hss1);
    hss2.removeAll(hss3);
    Iterator<string> *hssItr5 = hss2.iterator();
    cout<<"hss2's elements :";
    while(hssItr5->hasNext()){
        cout<<hssItr5->next()<<" ";
    }
    //retainAll()
    cout<<endl<<"retainAll() Function Test :"<<endl;
    HashSet<string,set> hss4,hss5;
    hss4.add("ali");hss4.add("ayse");
    hss5.add("ali");hss5.add("ayse");hss5.add("rabia");
    hss5.retainAll(hss4);
    Iterator<string> *hssItr6 = hss5.iterator();
    cout<<"hss5's elements: ";
    while(hssItr6->hasNext())
        cout<<hssItr6->next()<<" ";
    //size()
    cout<<endl<<"size() Function Test :"<<endl;
    cout<<"hss5's size :"<<hss5.size()<<endl;

    cout<<endl<<endl;
    
    cout<<"Functions Test with ArrayList<int,vector>"<<endl;
    //ArrayList<int,vector> and Function Testing
    //add()
    cout<<"add() Function Test :"<<endl;
    ArrayList<int,vector> al1,al2;
    al1.add(1);al1.add(2);al1.add(3);al1.add(4);al1.add(5);
    Iterator<int> *itr = al1.iterator();
    cout<<"al1's elements :";
    while(itr->hasNext()){
    cout<<itr->next()<<" ";
    }
    //addAll()
    cout<<endl<<"addAll() Function Test :"<<endl;
    al2.addAll(al1);
    Iterator<int> *itr2 = al2.iterator();
    cout<<"al2's elements :";
    while(itr2->hasNext()){
        cout<<itr2->next()<<" ";
    }
    //clear()
    cout<<endl<<"clear() Function Test :"<<endl;
    al2.clear();
    cout<<"al2's elements :";
    for(int i=0; i<al2.getVect().size(); i++)
        cout<<al2.getVect()[i]<<" ";
    al2.addAll(al1);
    //contains()
    cout<<endl<<"contains() Function Test :"<<endl;   
    if(al2.contains(7)==true)
        cout<<"7 is al2's element."<<endl;
    else
        cout<<"7 is not al2's element."<<endl;
    //containAll()
    cout<<"containAll() Function Test :"<<endl;
    ArrayList<int,vector> al3;
    al3.add(1);al3.add(2);
    if(al2.containsAll(al3)==true)
        cout<<"al2 contains al3."<<endl;
    else
        cout<<"al2 doesn't contain al3."<<endl;
    //isEmpty()
    cout<<"isEmpty() Function Test :"<<endl;
    al2.clear();
    if(al2.isEmpty() == true)
        cout<<"al2 is empty..";
    else
        cout<<"al2 is not empty..";
    //remove()
    cout<<endl<<"remove() Function Test :"<<endl;
    al2.addAll(al1);
    al2.remove(3);
    cout<<"al2's elements :";
    for(int i=0; i<al2.getVect().size(); i++)
        cout<<al2.getVect()[i]<<" "; 
    //removeAll()
    cout<<endl<<"removeAll() Function Test :"<<endl;
    al2.clear();
    al2.addAll(al1);
    al2.removeAll(al3);
    for(int i=0; i<al2.getVect().size(); i++)
        cout<<al2.getVect()[i]<<" ";
    //retainAll()
    cout<<endl<<"retainAll() Function Test :"<<endl;
    ArrayList<int,vector> al4,al5;
    al4.add(1);al4.add(2);al4.add(3);
    al5.add(1);al5.add(2);
    al4.retainAll(al5);
    Iterator<int> *itr4 = al4.iterator();
    cout<<"al4's elements: ";
    while(itr4->hasNext())
        cout<<itr4->next()<<" ";
    //size()
    cout<<endl<<"size() Function Test :"<<endl;
    cout<<"al4's size: "<<al4.size();

    cout<<endl<<endl;
    
    cout<<"Functions Test with ArrayList<string,vector>"<<endl;
    //ArrayList<int,vector> and Function Testing
    //add()
    cout<<"add() Function Test :"<<endl;
    ArrayList<string,vector> al6,al7;
    al6.add("papatya");al6.add("karanfil");al6.add("lale");al6.add("gül");al6.add("orkide");
    Iterator<string> *itr5 = al6.iterator();
    cout<<"al6's elements :";
    while(itr5->hasNext()){
        cout<<itr5->next()<<" ";
    }
    //addAll()
    cout<<endl<<"addAll() Function Test :"<<endl;
    al7.addAll(al6);
    Iterator<string> *itr6 = al7.iterator();
    cout<<"al7's elements :";
    while(itr6->hasNext()){
        cout<<itr6->next()<<" ";
    }
    //clear()
    cout<<endl<<"clear() Function Test :"<<endl;
    al7.clear();
    cout<<"al7's elements :";
    for(int i=0; i<al7.getVect().size(); i++)
        cout<<al7.getVect()[i]<<" ";
    al7.addAll(al6);
    //contains()
    cout<<endl<<"contains() Function Test :"<<endl;   
    if(al7.contains("menekse")==true)
        cout<<"menekse is al7's element."<<endl;
    else
        cout<<"menekse is not al7's element."<<endl;
    //containAll()
    cout<<"containAll() Function Test :"<<endl;
    ArrayList<string,vector> al8;
    al8.add("papatya");al8.add("karanfil");
    if(al7.containsAll(al8)==true)
        cout<<"al7 contains al8."<<endl;
    else
        cout<<"al7 doesn't contain al8."<<endl;
    //isEmpty()
    cout<<"isEmpty() Function Test :"<<endl;
    al7.clear();
    if(al7.isEmpty() == true)
        cout<<"al7 is empty..";
    else
        cout<<"al7 is not empty..";
    //remove()
    cout<<endl<<"remove() Function Test :"<<endl;
    al7.addAll(al6);
    al7.remove("lale");
    cout<<"al7's elements :";
    for(int i=0; i<al7.getVect().size(); i++)
        cout<<al7.getVect()[i]<<" "; 
    //removeAll()
    cout<<endl<<"removeAll() Function Test :"<<endl;
    al7.clear();
    al7.addAll(al6);
    al7.removeAll(al8);
    for(int i=0; i<al7.getVect().size(); i++)
        cout<<al7.getVect()[i]<<" ";
    //retainAll()
    cout<<endl<<"retainAll() Function Test :"<<endl;
    ArrayList<string,vector> al9,al10;
    al9.add("papatya");al9.add("karanfil");al9.add("lale");
    al10.add("papatya");al10.add("karanfil");
    al9.retainAll(al10);
    Iterator<string> *itr7 = al9.iterator();
    cout<<"al9's elements: ";
    while(itr7->hasNext())
        cout<<itr7->next()<<" ";
    //size()
    cout<<endl<<"size() Function Test :"<<endl;
    cout<<"al9's size: "<<al9.size(); 
    cout<<endl;

    return 0;
}

