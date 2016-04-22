#ifndef HASHTABLE_HH_
#define HASHTABLE_HH_

#include "hashnode.hh"
#include "keyhash.hh"

//用来保存node地址,使查找更快
/*
template<typename K,typename V>
class Node{
    public:
        Node
    private:
        K key_;
        HashNode<K,V> *data_;
};
*/
template<typename K,typename V,typename F=KeyHash<K>>
class HashTable{
    public:
        HashTable(){
            this->table_ = new HashNode<K,V>*[TABLE_SIZE]();
            for(int i=0;i<TABLE_SIZE;++i){
                this->table_[i] = nullptr;
            }
            this->pv = new V;
        }

        virtual ~HashTable(){
            for(int i=0;i<TABLE_SIZE;++i){
                HashNode<K,V> *entry = this->table_[i];
                HashNode<K,V> *pre;
                while(entry!=nullptr){
                    pre = entry;
                    entry = entry->getNext();
                    delete pre;
                }
                this->table_[i]=nullptr;
            }
            delete[] this->table_;
            delete this->pv;
            this->pv = nullptr;
        }

    public:
        unsigned long hashcode(const K& key)
        {
            return this->hashFunc(key);
        }

        bool get(const K &key,V& value){
            unsigned long hashValue = this->hashcode(key)%TABLE_SIZE;
            HashNode<K,V> *entry = this->table_[hashValue];

            while(entry!=nullptr){
                if(entry->getKey() == key){
                    value = entry->getValue();
                    return true;
                }
                entry = entry->getNext();
            }
            return false;
        }

        void put(const K& key,const V& value){
            unsigned long hashValue = this->hashcode(key)%TABLE_SIZE;

            HashNode<K,V> *pre = nullptr;
            HashNode<K,V> *entry = this->table_[hashValue];
            //find key node
            while(entry!=nullptr && entry->getKey() != key){
                pre = entry;
                entry = entry->getNext();
            }
            //not found,add new node
            if(entry==nullptr){
                entry = new HashNode<K,V>(key,value);
                //the first node
                if(pre==nullptr){
                    this->table_[hashValue] = entry;
                }else{
                    //already hash node
                    pre->setNext(entry);
                }
            }else{
                //found the node.
                entry->setValue(value);
            }
        }

        void remove(const K& key){
            unsigned long hashValue = this->hashcode(key)%TABLE_SIZE;
            HashNode<K,V> *pre = nullptr;
            HashNode<K,V> *entry = this->table_[hashValue];
            while(entry!=nullptr && entry->key()!=key){
                pre = entry;
                entry = entry->getNext();
            }
            if(entry!=nullptr){
                //not first node
                if(pre!=nullptr){
                    pre->setNext(entry->getNext());
                }else{
                    this->table_[hashValue] = entry->getNext();
                }
                delete entry;
                entry = nullptr;
            }
        }

        size_t count(const K& key)
        {
            size_t cnt = 0;
            unsigned long hashValue = this->hashcode(key)%TABLE_SIZE;
            HashNode<K,V> *entry = this->table_[hashValue];
            while(entry!=nullptr){
                if(entry->key() == key) cnt++;
                entry = entry->getNext();
            }
            return cnt;
        }

        V& operator[](const K& key)
        {
            //默认构造函数this->pv

            HashNode<K,V> *pre = nullptr,*entry=nullptr;
            unsigned long hashValue = this->hashcode(key)%TABLE_SIZE;
            entry = this->table_[hashValue];
            while(entry!=nullptr && entry->key()!=key){
                pre = entry;
                entry = entry->getNext();
            }
            //not found,insert new node
            if(entry==nullptr){
                entry = new HashNode<K,V>(key,*pv);
                if(pre==nullptr){
                    this->table_[hashValue]=entry;
                }else{
                    pre->setNext(entry);
                }
            }

            return entry->value();//reference
        }

        HashNode<K,V>* find(const K& key)
        {
            HashNode<K,V> *p=nullptr;
            unsigned long hashValue = this->hashcode(key)%TABLE_SIZE;
            HashNode<K,V> *entry = this->table_[hashValue];

            while(entry!=nullptr){
                if(entry->getKey() == key){
                    p = entry;
                }
                entry = entry->getNext();
            }

            return p;
        }

    private:
        HashNode<K,V> **table_;
        F hashFunc;

    private:
        V *pv;
};
/*
template<typename K,typename V,typename F=KeyHash<K>> V HashTable<K,V,F>::operator[](const K& key)
{
    V value;//call default constructor
    if(!this->get(key,value)){
        this->put(key,value);
    }
    return value;
}
*/
#endif
