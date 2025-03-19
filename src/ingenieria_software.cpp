// ingenieria_software.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StateMachine.h"
#include <windows.h>
#define GetKey(X) (!!(GetAsyncKeyState(0[#X]) & 0x8000))

int main()
{
    std::cout << "Hello World!\n";
    StateMachine oStateMachine;

    while (true)
    {
      if (GetKey(A))
      {
        if (oStateMachine.CanTransit("A"))
        {
          std::cout << "Can transit from : " << oStateMachine.GetCurrentStateString() << " with 'A' button\n";
          oStateMachine.Transit("A");
          std::cout << "New state : " << oStateMachine.GetCurrentStateString() << "\n";
        }
      }

      if (GetKey(B))
      {
        if (oStateMachine.CanTransit("B"))
        {
          std::cout << "Can transit from : " << oStateMachine.GetCurrentStateString() << " with 'B' button\n";
          oStateMachine.Transit("B");
          std::cout << "New state : " << oStateMachine.GetCurrentStateString() << "\n";
        }
      }
    }
}
