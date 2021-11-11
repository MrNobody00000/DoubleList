#include <iostream>

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
    void push_back(int a);
    void show();
    void pop_back();
};

template <class Ttype>
void Dlist<Ttype>::push_back(int a)
{
    if (size == 0)
    {
        size++;
        HEAD = new listElem<Ttype>(a);
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
template <class Ttype>
Dlist<Ttype>::Dlist()
{
    size = 0;
    HEAD = nullptr;
    TAIL = nullptr;
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
    obj.pop_back();
    obj.pop_back();
    obj.pop_back();
    obj.pop_back();
    obj.pop_back();
    obj.pop_back();
    obj.show();

    //Dlist<int> lst; //Объявляем переменную, тип которой есть список
    //lst.add(100); //Добавляем в список элементы
    //lst.add(200);
    //lst.add(900);
    //lst.add(888);

    //lst.show(); //Отображаем список на экране

    return 0;
}
