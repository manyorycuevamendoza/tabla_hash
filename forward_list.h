#include <iostream>
using namespace std;

<<<<<<< HEAD
template<typename TK,typename  TV>
struct Entry{
    TK key;
    TV value;

    Entry(){
    }

    Entry(TK k, TV v) {
        this->key = k;
        this->value = v;
    }
};

template <typename T>
=======

template <class T>
>>>>>>> 6a8c442b6ec03290f2c876e9c8e8840d0fdb9345
//creamos una clase para el nodo
struct NodeF
{
    T data;
    NodeF* next;

    NodeF(){//constructor por defecto
        next = nullptr;
    }

    NodeF(T value){//constructor con parametro
        data = value;
        next = nullptr;
    }

    void killSelf(){//funcion para eliminar el nodo
        if(next != nullptr) next->killSelf();
        delete this;
    }
};

//creamos una clase para la lista
template <typename T>
class ForwardList {
    private:
        NodeF<T>* head;//creamos un puntero al inicio de la lista
        int size;
    public:
        ForwardList() {
            head = nullptr;
            size=0;
        }

        ~ForwardList(){
            if(head) head->killSelf();
        }

        void push_front(T data){//funcion para insertar al inicio de la lista
            NodeF<T>* nuevo = new NodeF<T>(data);
            nuevo->next = head;
            head = nuevo;
            size++;
        }

        void display(){//funcion para mostrar la lista
            NodeF<T>* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
        int get_size(){
            return size;
        }

};