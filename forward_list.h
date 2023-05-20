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
    public:
        ForwardList() {
            head = nullptr;
        }

        ~ForwardList(){
            if(head) head->killSelf();
        }

        void push_front(T data){//funcion para insertar al inicio de la lista
            NodeF<T>* nuevo = new NodeF<T>(data);
            nuevo->next = head;
            head = nuevo;
        }

        void display(){//funcion para mostrar la lista
            NodeF<T>* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }

        //creamos un iterador para recorrer la lista
        class iterator{
            private:
                NodeF<T>* ptr;
            public:
                iterator(NodeF<T>* p = nullptr){
                    ptr = p;
                }
                iterator operator++(){
                    ptr = ptr->next;
                    return *this;
                }
                iterator operator++(int){
                    iterator temp = *this;
                    ptr = ptr->next;
                    return temp;
                }
                bool operator==(const iterator& it){
                    return ptr == it.ptr;
                }
                bool operator!=(const iterator& it){
                    return ptr != it.ptr;
                }
                T& operator*(){
                    return ptr->data;
                }
        };

        iterator begin(){
            return iterator(head);
        }

        iterator end(){
            return iterator(nullptr);
        }

};