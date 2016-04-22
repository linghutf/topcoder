#ifndef HASHNODE_HH_
#define HASHNODE_HH_

template<typename K,typename V>class HashNode{
    public:
        HashNode(const K& key,const V& value,HashNode<K,V> *next=nullptr):key_(key),value_(value),next_(next){}
        virtual ~HashNode();

        void setNext(HashNode<K,V> *next)
        {
            this->next_ = next;
        }

        HashNode<K,V> *getNext();

        void setKey(const K& key);
        K getKey();
        void setValue(const V& value);
        V getValue();

        K& key(){return this->key_;}
        V& value(){return this->value_;}

    private:
        K key_;
        V value_;
        HashNode<K,V> *next_;
};

template<typename K,typename V>HashNode<K,V>::~HashNode()
{
    this->next_ = nullptr;
}

template<typename K,typename V> HashNode<K,V>* HashNode<K,V>::getNext(){
    return this->next_;
}

template<typename K,typename V> void HashNode<K,V>::setKey(const K& key)
{
    this->key_ = key;
}

template<typename K,typename V>K HashNode<K,V>::getKey()
{
    return this->key_;
}

template<typename K,typename V> void HashNode<K,V>::setValue(const V& value)
{
    this->value_=value;
}

template<typename K,typename V> V HashNode<K,V>::getValue()
{
    return this->value_;
}

#endif
