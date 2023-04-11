#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //TODO
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost
  // needs return statement

  int i =0;
  size_t minimum=queue[0].getFCost();
  int index=0;
  for (i=1;i<queue.size();i++)
  {
    if(queue[i].getFCost()<minimum)
    {
      index=i;
    }
  }
  State<T> temp =queue.at(index);
  queue.erase(queue.begin()+index);

  // needs return statement
  return temp;

}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO
  //implement this the same way we implemented push in the heap lecture.
  State<T> temp(p, cost, heur);
  queue.push_back(temp);
}

template <typename T>
bool frontier_queue<T>::empty() {

  //TODO

  return (queue.size()==0);
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  //TODO
  for (int i = 0;i <queue.size();i++)
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
  int i=0;
  for (i = 0;i<queue.size();i++)
  {
    if(queue[i].getValue()==p && queue[i].getPathCost()>cost)
    {
      queue[i].updatePathCost(cost);
    }
  }
  
}


