//
// Created by ASUS on 20/05/2023.
//
#include <iostream>
#include <functional>
#include "forward_list.h"
using namespace std;

const float maxFillFactor = 0.4;
const int maxColision = 3;


template<typename TK, typename TV>
class ChainHash{
private:
    ForwardList<Entry<TK,TV>>* array;//array de listas
    int capacity;//tamanio del array
    int size;//cantidad total de elementos
    hash<TK> hasher;//hash de string

public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
        array = new ForwardList<Entry<TK,TV>>[capacity]; //sese borra porque se tiene que generar con el fores list de l aclase sha
    }

    void insert(TK key, TV value){
        int index = hasher(key)%capacity;
        if (size*1.0/(maxColision*capacity)>=maxFillFactor) {cout<<"rehashing\n"; rehashing();}
        array[index].push_front(Entry<TK,TV>(key,value));
        //array[index].display();
        size++;
    }

    bool find(TK key){ // busca si existe uno o mas elementos con ese key
        int index = hasher(key)%capacity;
        return array[index].find(Entry<TK,TV>(key,TV()));
    }


    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i){
        return array[i].get_size();
    }

    ~ChainHash(){

    }

private: // ver rehashing
    void rehashing(){

    }
};


