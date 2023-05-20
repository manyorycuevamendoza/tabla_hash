#include <iostream>
using namespace std;


template <class T>
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