#include "Vector.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
  yukiina::Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);

  // cout << v.Size() << endl;
  // cout << v.Capacity() << endl;
  
  // auto begin = v.begin();
  // while(begin != v.end()){
    // cout << *begin << endl;
    // ++begin;
  // }
  
  for(auto e : v){
    cout << e << endl;
  }

}
