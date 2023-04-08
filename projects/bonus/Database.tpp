#include "Database.hpp"

template <typename T>
Database<T>::Database() {
    // TODO
    amt=0;
}

template <typename T>
bool Database<T>::isEmpty() {
    // TODO
    return (amt==0);
    //return false;
}

template <typename T>
std::size_t Database<T>::getNumberOfEntries() {
    // TODO
    return amt;
}

template <typename T>
bool Database<T>::add(std::string key1, std::string key2, const T& item) {
    // TODO
    //return false;
if(contains(key1) || contains(key2)){
    return false;
}
    bst.insert(key1, amt);
    bst2.insert(key2,amt);
    
    keys1.push_back(key1);
    keys2.push_back(key2);

    lst.insert(amt, item);
    amt++;
    return true;
}

template <typename T>
bool Database<T>::remove(std::string key) {
    // TODO
    //return false;
    if(isEmpty())
    {
        return false;
    }
    else{
    int here=0;
    for (int i =0; i<amt;i++)
    {
        if(keys1.at(i)==key || keys2.at(i)==key)
        {
            here = i;
            break;
        }
    }
    keys1.erase(keys1.begin()+here);
    keys2.erase(keys2.begin()+here);
    lst.remove(here);
    amt--;
    }
    if(contains(key)){
        return false;
    }
    else{
        return true;
    }
}

template <typename T>
void Database<T>::clear() {
    // TODO
    amt=0;
    lst.clear();
    bst.destroy();
    bst2.destroy();
    keys1.clear();
    keys2.clear();
}

template <typename T>
T Database<T>::getValue(std::string key) {
    // TODO
    //return T();
    int here=0;
    for (int i =0; i<amt;i++)
    {
        if(keys1.at(i)==key || keys2.at(i)==key)
        {
            here =i;
            break;
        }
    }
    return lst.getEntry(here);
}

template <typename T>
bool Database<T>::contains(std::string key) {
    // TODO
    //return false;
    for (int i = 0; i<amt;i++)
    {
         if(keys1.at(i)==key || keys2.at(i)==key)
        {
            return true;
        }
    }
    return false;
}

