#include "Database.hpp"

template <typename T>
Database<T>::Database() {
    // TODO
    amount=0;
}

template <typename T>
bool Database<T>::isEmpty() {
    // TODO
    return (amount==0);
    //return false;
}

template <typename T>
std::size_t Database<T>::getNumberOfEntries() {
    // TODO
    return amount;
}

template <typename T>
bool Database<T>::add(std::string key1, std::string key2, const T& item) {
    // TODO
    //return false;

//std::cout << key1 << std::endl << key2 << std::endl;
    

if(contains(key1) || contains(key2)){
    return false;
}
    bt.insert(key1, amount);
    bt2.insert(key2,amount);
    
    k1.push_back(key1);
    k2.push_back(key2);

    list1.insert(amount, item);
    amount++;

    return true;
}

template <typename T>
bool Database<T>::remove(std::string key) {
    // TODO
    //return false;
    //cannot remove from false

    //std::cout << key;

    if(isEmpty()){
        return false;
    }
    
    //
    int index = -1; //init index to -1, this will indicate that a matching
    //entry has not yet been found

    for (int i =0; i<amount;i++){
        if(k1.at(i)==key || k2.at(i)==key)
        {
            index = i;
            break;
        }
    }
    if (index == -1){ // If no matching entry was found, return false
        return false;
    }

    k1.erase(k1.begin()+index);
    k2.erase(k2.begin()+index);
    list1.remove(index);
    amount--;

    /*for(int i = index; i < amount; i++){
        if(k1.at(i) == key || k2.at(i) == key){
            index = i;
            break;
        }
        k1.at(i) = k1.at(i+1);
        k2.at(i) = k2.at(i+1);
        list1.getEntry(i) = list1.getEntry(i+1);
    }*/
    
    if(contains(key)){
        return false;
    }
    
    return true;
    
}

template <typename T>
void Database<T>::clear() {
    // TODO

    //zeroing out amount and clearing everything
    amount=0;

    k1.clear();
    k2.clear();
    list1.clear();

    bt.destroy();
    bt2.destroy();

}

template <typename T>
T Database<T>::getValue(std::string key) {
    // TODO
    //return T();
    //check with for loop if the key value exists in either k1, k2. return the entry
    int j=0;
    for (int i=0; i<amount;i++){
        if(k1.at(i)==key || k2.at(i)==key){
            j = i;
            break;
        }
    }
    return list1.getEntry(j);
}

template <typename T>
bool Database<T>::contains(std::string key) {
    // TODO
    //return false;
    //check with for loop to ensure it exists in k1 or k2
    for (int i = 0; i<amount;i++){
        if(k1.at(i)==key || k2.at(i)==key){
            return true;
        }
    }
    return false;
}

