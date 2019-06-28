#include "../vector/Vector.h"


namespace yukiina{
  template<class T, class Container = yukiina::Vector<T>>
  class Stack{
  public:
    Stack(){}

    T Top(){
      return _con[Size() - 1];
    }

    void Push(const T& x){
      _con.Push_Back(x);
    }

    void Pop(){
      _con.Pop_Back();
    }

    bool Empty(){
      return _con.Size() == 0;
    }

    int Size(){
      return _con.Size();
    }
  private:
    Container _con;
  };

  
}


