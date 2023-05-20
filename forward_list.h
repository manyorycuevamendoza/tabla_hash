#include <iostream>
using namespace std;

template<typename TK,typename  TV>
struct Entry{
    TK key;
    TV value;

    Entry(){
        key = TK();
        value = TV();
    }

    Entry(TK k, TV v) {
        this->key = k;
        this->value = v;
    }

    bool same_key(Entry a){
        return a.key==this->key;
    }


    friend ostream& operator<<(ostream& salida, Entry<TK,TV> e){
        salida<<e.key<<" "<<e.value;
        return salida;
    }

};

template <typename T>
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
    public:

    T operator [](int e){ //operator como de indez
        NodeF<T>*temp = head;
        for (int i=0;i<e;i++){
            temp = temp->next;
        }
        return temp->data;
    }

    void operator=(T data){
        this->head = data->head;
        this->size = data->size;
    }

    private:
        NodeF<T>* head;//creamos un puntero al inicio de la lista
        int size =0;
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
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            cout<<endl;
        }

        bool find(T data){
            NodeF<T>* temp = head;
            while(temp){
                if (temp->data.same_key(data)) return true;
                temp =temp->next;
            }
            return false;
        }

        int get_size(){
            return size;
        }

        T top(T data){ //siempre retornamos el ttop porque es el ultimo el que insertamos, un forward list imita a un satck
            NodeF<T>* temp = head;
            while(temp) {
                if (temp->data.same_key(data)) return temp->data;
                temp = temp->next;
            }
            return temp->data;
        }

        

};