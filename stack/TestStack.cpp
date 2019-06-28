#include "Stack.h"

using namespace std;

int main(){
  yukiina::Stack<int> s;
  s.Push(1);
  s.Push(2);
  s.Push(3);
  s.Push(4);
  s.Push(5);
  s.Push(6);

  
  while(!s.Empty()){
    cout << s.Top() << " ";
    s.Pop();
  }
  cout << endl;
  


  return 0;
}
