// Артамонов Кирилл

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace namespaceA {
   class Engine {
   public:
      void run() {
         cout << "EngineA run" << endl;
      }
   };
}

namespace namespaceB {
   class Engine {
   public:
      void run() {
         cout << "EngineB run" << endl;
      }
   };
}

namespace namespaceC {
   class Engine {
   public:
      void run() {
         cout << "EngineC run" << endl;
      }
   };
}

class MyEngine {
public:
// Если передан параметр 1 - должен быть вызван метод run и Engine-а из библиотеки A.
// Если передан параметр 2 - должен быть вызван метод run и Engine-а из библиотеки B.
// Если передан параметр 3 - должен быть вызван метод run и Engine-а из библиотеки C.
// Если передано что-то иное - должно ничего не произойти.
   void run(unsigned int number) {
      switch (number)
      {
         case 1:
            namespaceA::Engine A_Engine;
            A_Engine.run();
            break;
         case 2:
            namespaceB::Engine B_Engine;
            B_Engine.run();
            break;
         case 3:
            namespaceC::Engine C_Engine;
            C_Engine.run();
            break;
         default:
            break;
      }
   }
};

int main() {
   MyEngine e;
   e.run(1); // вызов run из Engine-а из библиотеки A
   e.run(2); // вызов run из Engine-а из библиотеки B
   e.run(3); // вызов run из Engine-а из библиотеки C
   e.run(10); // ничего не происходит
}
