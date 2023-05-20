//
// Created by ASUS on 20/05/2023.
//
#include <iostream>
#include "forward_list.h"
#include "SHA256.h"
#include <functional>

using namespace std;

const float maxFillFactor = 0.4;
const int maxColision = 3;

template<typename TK, typename TV>
class ChainHash{
public:
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

private:
    ForwardList<Entry>* array;
    int capacity;//tamanio del array
    int size;//cantidad total de elementos
    hash<TK> hasher;//hash de string

public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
        array = new ForwardList<Entry>[this->capacity]; //sese borra porque se tiene que generar con el fores list de l aclase sha
    }

    void insert(TK key, TV value){
        SHA256 sha;
        sha.update(key);
        uint8_t * digest = sha.digest();
        std::cout<<*digest;
        std::cout << SHA256::toString(digest) << std::endl;

        delete[] digest; 
        

    }

    TV find(TK key){

    }

    void remove(TK key){


    }
/*
    int bucket_count(){

    }

    int bucket_size(int i){

    }
*/
    ~ChainHash(){

    }

private: // ver rehashing
    void rehashing(){

    }
};


