#include <iostream>

template<class Ttype>
class Node{
public:
    Ttype x;
    Node *next;
    Node *prev;
};

template<class Ttype, int size> 
class Dlist{
    Node *Head;
    Node *Tail;
public:
    DList():Head(NULL),Tail(NULL);
    ~Dlist();
    void show();
    void add(Ttype data);

};

template<class Ttype,int size> 
Dlist<Ttype,size>::~Dlist(){
    while(Head){
        Tail = Head->next;
        delete Head;
        Head = Tail;
    }
}

template<class Ttype,int size>
void Dlist<Ttype,size>::add(Ttype data){
    Node *temp = new Node;
    temp->next = NULL;
    temp->x = data;
    if(Head != NULL){   // mb if(Head)
        
    }
}
