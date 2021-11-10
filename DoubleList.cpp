#include <iostream>

template<class Ttype>
class Node{
public:
    Ttype x;
    Node *next;
    Node *prev;
};

template<class Ttype> 
class Dlist{
public:
    Node* Head;
    Node* Tail;
    DList()<Ttype>:Head(NULL),Tail(NULL){};
    ~Dlist();
    void show();
    void add(Ttype data);

};

template<class Ttype> 
Dlist<Ttype>::~Dlist(){
    while(Head){
        Tail = Head->next;
        delete Head;
        Head = Tail;
    }
}

template<class Ttype>
void Dlist<Ttype>::add(Ttype data){
    Node *temp = new Node;
    temp->next = NULL;
    temp->x = data;
    if(Head != NULL){   // mb if(Head)
        temp->prev = NULL;
        Tail->next = temp;
        Tail = temp;
    }
    else {
        temp->prev = NULL;
        Head = Tail = temp;
    }
}

template<class Ttype>
void Dlist<Ttype>::show(){
    Node *temp=Tail; 
    while (temp != NULL){
        cout << temp->x << " ";
        temp = temp->Prev;  
    }
    cout << "\n";

    temp = Head;
    while (temp != NULL) {
        cout << temp->x << " ";
        temp = temp->Next;
    }
    cout << "\n";
}

int main ()
{

 Dlist<int> lst; //Объявляем переменную, тип которой есть список
 lst.add(100); //Добавляем в список элементы
 lst.add(200);
 lst.add(900);
 lst.add(888);
 
 lst.show(); //Отображаем список на экране

    return 0;
}
