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


    ~Vector(){
      if (_start){
        delete[] _start;
        _start = _finish = _endOfStorage = nullptr;
      }
    }


    //Vector v1(v2);
    Vector(const Vector<T>& v) : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr){
      Reverse(v.Size());
      for (size_t i = 0; i < v.Size(); i++){
        this->push_back(v[i]);
      }
    }

    // v1 = v2
    Vector<T>& operator=(Vector<T> v){
      Swap(v);    
      return *this;
    }

    void Swap(Vector<T>& v){
      std::swap(_start, v._start);
      std::swap(_finish, v._finish);
      std::swap(_endOfStorage, v._endOfStorage);
    }
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

    void Push_Back(const T& x){
      if (_finish == _endOfStorage){
        int newCapacity = Capacity() == 0 ? 4 : 2 * Capacity();
        Reverse(newCapacity);
      }  
      *_finish = x;
      ++_finish;
    }

    void Pop_Back() {
      assert(_finish > _start);
      --_finish;
    }

    void Resize(int n, const T& x = T()){
      if (n <= Size()){
        _finish = _start + n;
      }else {
        Reverse(n);
        while(_finish != _start + n){
          *_finish = x;
          _finish++;
        }
      }
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

    void Insert(iterator pos, const T& x){
      assert(pos <= _finish);
      if (_finish == _endOfStorage){
        size_t n = pos - _start;
        size_t newCapacity = Capacity() == 0 ? 4 : 2 * Capacity();
        Reverse(newCapacity);
        pos = _start + n;
      }

      iterator begin = _finish;
      while(begin != pos){
        *begin = *(begin - 1);
        begin--;
      }

      *pos = x;
      ++_finish;
    }

    iterator earse(iterator pos){
      assert(pos < _finish);
      iterator begin = pos;
      while(begin != _finish - 1){
        *begin = *(begin + 1);
        ++begin;
      }
      --_finish;
      return pos;
    }
  private:
    iterator _start;   // 指向数据起始
    iterator _finish;       // 指向数据末尾
    iterator _endOfStorage; // 指向空间末尾
  };
}
