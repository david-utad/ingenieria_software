/**
 * @author: David Gonzalez
 */

#include <vector>

class StateMachine
{
public:
  enum EState
  {
    STANDING,
    DUCKING,
    JUMPING,
    DIVING
  };

  StateMachine();
  ~StateMachine();

  StateMachine::EState GetCurrentState();
  bool CanTransit(const char* _sInput);
  void Transit(const char* _sInput);

private:
  struct Transition
  {
    EState eOrigin;
    EState eDestiny;
    const char* sCondition;
  };

  EState m_eCurrentState;
  std::vector<Transition> m_vTransitions;
};