#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {
  //TODO
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost
  //we assume that the Q is full
  
  size_t min = queue[0].getFCost();
  int index = 0;

  //iterate thru Q to find the min
  for (int i = 1; i<queue.size(); i++)
  {
    if(queue[i].getFCost() < min)
    {
      index=i;
    }
  }

  //erase min value
  State<T> place = queue.at(index);
  queue.erase(queue.begin()+index);

  //return state value
  return place;

}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {
  //TODO
  //implement this the same way we implemented push in the heap lecture.
  State<T> place(p, cost, heur);
  queue.push_back(place);
}

template <typename T>
bool frontier_queue<T>::empty() {
  //TODO
  //return if size=0 is true
  return (queue.size()==0);
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {
  //TODO
  //traverse thru the Q, if the item is present, return true else return false
  for (int i = 0; i <queue.size(); i++)
  { 
    if (queue[i].getValue()==p)
    {
      return true;
    }
  }
  return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {
  //TODO

  for (int i = 0;i<queue.size();i++)
  {
    //if the item at the ith place in Q, AND the new cost is < old cost
    // update path w new cost
    if(queue[i].getValue() == p && cost < queue[i].getPathCost())
    {
      queue[i].updatePathCost(cost);
    }
  }
  
}


