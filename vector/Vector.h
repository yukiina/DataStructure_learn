#include <iostream>
#include <cassert>
namespace yukiina{

template<class T>
  class Vector{
  public:
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin(){
      return _start;
    }
    iterator end(){
      return _finish;
    }

    const_iterator cbegin() const{
      return _start;
    }
    const_iterator cend() const {
      return _finish;
    }
  public:

    Vector() : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr){}


    ~Vector(){}

    //Vector v1(v2);
    Vector(const Vector<T>& v){}

    // v1 = v2
    Vector<T>& operator=(Vector<T> v){}
    
  public:
    T& operator[](size_t pos){
      assert(pos < Size());
      return _start[pos];
    }

    const T& operator[](size_t pos) const {
      assert(pos < Size());
      return _start[pos];
    }

    size_t Size() const{
      return _finish - _start;
    }

    size_t Capacity() const{
      return _endOfStorage - _start;
    }

    void push_back(const T& x){
      if (_finish == _endOfStorage){
        int newCapacity = Capacity() == 0 ? 4 : 2 * Capacity();
        Reverse(newCapacity);
      }  
      *_finish = x;
      ++_finish;
    }

    void pop_back() {
      assert(_finish > _start);
      --_finish;
    }

    void Reverse(int n){
      if (n > Capacity()){
        T* tmp = new T[n];
        int size = Size();
        if (_start){
          for (int i = 0; i < size; i++){
            tmp[i] = _start[i];
          }
        }

        delete [] _start;
        _start = tmp;
        _finish = _start + size;
        _endOfStorage = _start + n;
      }
    }

    iterator Insert(iterator pos, const T& x){
    }
  private:
    iterator _start;   // 指向数据起始
    iterator _finish;       // 指向数据末尾
    iterator _endOfStorage; // 指向空间末尾
  };
}
