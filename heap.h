// Coded By Ankur KUMAR
//  NIT JAMSHEDPUR

#include<iostream>
#include<vector>

#pragma once

template<typename T>
class Heap{

     std::vector<T> v;
     bool minheap;


      /* 
                    This portion was just an old implementation

    //  bool comp(T a,T b)
    //  {
    //      if(minheap)
    //      return a<b;

    //      return a>b;
    //  }


      */


   //return true if obj1 compares less than obj2

    bool (*comp)(T obj1, T obj2);



    // put the last elenemt inserted to it's correct position
    // called when push method invoked

     void heapify_end(int idx)
     {
            int par=(idx-1)/2;

        // keep swapping till you reach top or become greater than parent
         while(idx>0 && comp(v[idx],v[par]))
         {
             std::swap(v[idx],v[par]);
             idx=par;
             par/=2;
         }
     }

    
     // called when pop method invoked

     void heapify_top(int idx)
     {
          int left=2*idx+1;
          int right=2*idx+2;

          int min_idx=idx;

          if(left<v.size() && comp(v[left] , v[idx]))
          {
              min_idx=left;
          }

          if(right<v.size() && comp(v[right] , v[min_idx]))
          {
              min_idx=right;
          }

          if(min_idx!=idx)
          {
              std::swap(v[min_idx], v[idx]);
              heapify_top(min_idx);
          }


     }


    public:

     // constructor


     /* 
     
         constructs an empty Max heap
         this max heap will hold objects of type T
         the priority of the objects will be decided
         by a user defined function.
    
    */

      Heap<T> (bool (*comp)(T obj1, T obj2))
     {
        this -> comp = comp;
     }


     /* 
                    This portion was just an old implementation

    //  Heap()
    //  {
    //      this->minheap=true;
    //  }

    //  Heap(bool type)
    //  {
    //       this->minheap=type;
    //  }

    //  Heap(int size,bool type)
    //  {
    //      v.reserve(size);
    //      this->minheap=type;
    //  }



     */




     //      ------------      methods   -------------  // 

      // insert 

      void push(T data)
      {
         v.push_back(data);

         int idx=v.size()-1;

         heapify_end(idx);
      
      }

      // return top element

      T top()
      {
          if(v.size()>0)
          return v[0];


          else return T(NULL);
      }


      // delete

      void pop()
      {
          std::swap(v[0],v[v.size()-1]);
          v.pop_back();

           heapify_top(0);
     
      }


      // getsize

      int size()
      {
          return v.size();
      }


      // empty

      bool empty()
      {
          return v.size()==0;
      }
      
  

};




//  How to use

/* 

 To implement just simply declare or use

  Heap<type> h(comparator)  

  Decleare like

  bool compare(T x,T y){ return x<y; }
  Heap<int> priority_q(compare);


  All popular Heap Functions suppoerted

  1) top();
  2) pop();
  3) push();
  4) empty();
  5) size();




 */