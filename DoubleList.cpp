#include <iostream>
#include <stdlib.h>

template <typename Ttype>
class Dlist
{
private:
    template <class T>
    class listElem
    {
    public:
        Ttype data;
        listElem *ptrNext;
        listElem *ptrPrev;
        listElem(Ttype data, listElem *ptrNext = nullptr, listElem *ptrPrev = nullptr)
        {
            this->data = data;
            this->ptrNext = ptrNext;
            this->ptrPrev = ptrPrev;
        }
    };

    listElem<Ttype> *HEAD;
    listElem<Ttype> *TAIL;
    int size;

public:
    Dlist();
    //~Dlist();
    void push_back(Ttype a);
    void push_front(Ttype a);
    void show();
    void pop_back();
    void insert(int pos,Ttype obj);
    Ttype& operator[](int pos);
};

template <class Ttype>
void Dlist<Ttype>::push_back(Ttype a)
{
    if (size == 0)
    {
        size++;
        HEAD = new listElem<Ttype>(a);
        TAIL = HEAD;    
    }
    else if (size == 1)
    {   
        size++;
        listElem<Ttype> *current = new listElem<Ttype>(a);
        HEAD->ptrNext = current;
        current->ptrPrev = HEAD;
        TAIL = current;
    }
    else {
        size++;
        listElem<Ttype> *current = new listElem<Ttype>(a);
        current->ptrPrev = TAIL;
        TAIL->ptrNext = current;
        TAIL = current;
    }
}

template <class Ttype>
void Dlist<Ttype>::push_front(Ttype a)
{
     if (size == 0)
    {
        size++;
        HEAD = new listElem<Ttype>(a);
        TAIL = HEAD;    
    }
    else if (size == 1)
    {   
        size++;
        listElem<Ttype> *current = new listElem<Ttype>(a);
        HEAD->ptrPrev = current;
        current->ptrNext = HEAD;
        HEAD = current;
    }
    else {
        size++;
        listElem<Ttype> *current = new listElem<Ttype>(a);
        current->ptrNext = HEAD;
        HEAD->ptrPrev = current;
        HEAD = current;
    }
}

template <class Ttype>
void Dlist<Ttype>::pop_back(){
    if(size>1){
    listElem<Ttype> *tmp = TAIL;
    TAIL = TAIL->ptrPrev;
    TAIL->ptrNext = nullptr;
    size--;
    delete tmp;
    }
    else if(size == 1){
         listElem<Ttype> *tmp = TAIL;
         TAIL = nullptr;
         HEAD = nullptr;
         size--;         
         delete tmp;    
    }
    else std::cout<<"Список пуст\n";
}

template<class Ttype>
void Dlist<Ttype>::insert(int pos,Ttype obj){
    if (pos == size){
        this->push_back(obj);
    }
    else if(pos > 0 && pos < size){
        if(size - 1 - pos < pos)
        {   
            listElem<Ttype> *tmpFirst = TAIL;
            listElem<Ttype> *tmpSec;
            listElem<Ttype> *current = new listElem<Ttype>(obj);
            for (int i=0;i<size - 1 - pos;i++){
                tmpFirst = tmpFirst->ptrPrev;
            }
            tmpSec = tmpFirst->ptrPrev;
            current->ptrNext = tmpFirst;
            current->ptrPrev = tmpSec;  
            tmpSec->ptrNext = current;
            tmpFirst->ptrPrev = current;
            size++;
        }
        else 
        {
            listElem<Ttype> *tmpFirst = HEAD;
            listElem<Ttype> *tmpSec;
            listElem<Ttype> *current = new listElem<Ttype>(obj);
            for (int i=0;i<pos;i++){
                tmpFirst = tmpFirst->ptrNext;
            }
            tmpSec = tmpFirst->ptrPrev;
            current->ptrNext = tmpFirst;
            current->ptrPrev = tmpSec;  
            tmpSec->ptrNext = current;
            tmpFirst->ptrPrev = current;
            size++;
        }
    }
    else if(pos == 0){
        size++;
        listElem<Ttype> *current = new listElem<Ttype>(obj);
        current->ptrPrev = nullptr;
        current->ptrNext = HEAD;
        HEAD->ptrPrev = current;
        HEAD = current;
    }
    //else std::cout<<"out of range\n\n";
}
template <class Ttype>
Dlist<Ttype>::Dlist()
{
    size = 0;
    HEAD = nullptr;
    TAIL = nullptr;
}

template<class Ttype>
Ttype& Dlist<Ttype>::operator[](int pos){
    try{
        if(pos >=size) throw 1;
        else if (pos < 0) throw 2;
    }
    catch(int a) {
        switch (a)
        {
        case 1:
            std::cout<<"Exception: out of range, list pushed back by 0's to index\n\n";
            while(pos>=size) this->push_back(Ttype());
            break;
        case 2:
            std::cout<<"Exception: out of range, list pushed front by 0's to index\n\n";
            while(pos < 0){
                this->push_front(Ttype());
                pos++;
            }
            break;
        }

        //exit(a);

    }
    if(pos > (size-1)/2 ){
        listElem<Ttype> *tmp = TAIL;
        for (int i=0;i<size - 1 - pos;i++){
            tmp = tmp->ptrPrev;
        }
        return tmp->data;
        }
    else {
        listElem<Ttype> *tmp = HEAD;
        for (int i=0;i<pos;i++){
            tmp = tmp->ptrNext;
        }
        return tmp->data;
        }          
}

template <class Ttype>
void Dlist<Ttype>::show(){
    if(size!=0){
        for(listElem<Ttype> *ptr = HEAD; ptr!=TAIL; ptr = ptr->ptrNext){
            std::cout<<ptr<<" "<<ptr->data<<'\n';
        }
        if(TAIL!=nullptr) std::cout<<TAIL<<" "<<TAIL->data<<'\n';
    }
    else std::cout<<"Список пуст\n";
}

int main()
{
    Dlist<int> obj;
    obj.push_back(13);
    obj.push_back(7);
    obj.push_back(3);
    obj.push_back(3);
    obj.push_back(44);

    obj.insert(0,555);
    obj.insert(4,555);
    obj.insert(6,555);
    obj.insert(10,555);
    obj[5] = 111;
    obj[11] = 0;
    obj[-1] = 4;
    obj.push_front(13);
    //std::cout<<obj[20];
    //obj[20] = 111;
    obj.show();
    return 0;
}
