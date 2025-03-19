#include "StateMachine.h"

StateMachine::StateMachine()
{
  Transition transition;

  transition.eOrigin = EState::STANDING;
  transition.eDestiny = EState::DUCKING;
  transition.sCondition = "A";
  m_vTransitions.push_back(transition);

  transition.eOrigin = EState::DUCKING;
  transition.eDestiny = EState::STANDING;
  transition.sCondition = "A";
  m_vTransitions.push_back(transition);

  transition.eOrigin = EState::STANDING;
  transition.eDestiny = EState::JUMPING;
  transition.sCondition = "B";
  m_vTransitions.push_back(transition);

  transition.eOrigin = EState::JUMPING;
  transition.eDestiny = EState::DIVING;
  transition.sCondition = "A";
  m_vTransitions.push_back(transition);

  m_eCurrentState = EState::STANDING;
}

StateMachine::~StateMachine()
{
  m_vTransitions.clear();
}

StateMachine::EState StateMachine::GetCurrentState()
{
    return m_eCurrentState;
}

bool StateMachine::CanTransit(const char* _sInput)
{
  bool bCanTransit = false;
  for (Transition transition : m_vTransitions)
  {
    if ((transition.eOrigin == m_eCurrentState) && (strcmp(transition.sCondition, _sInput) == 0))
    {
      bCanTransit = true;
    }
  }
  return true;
}

void StateMachine::Transit(const char* _sInput)
{
  for (Transition transition : m_vTransitions)
  {
    if ((transition.eOrigin == m_eCurrentState) && (strcmp(transition.sCondition, _sInput) == 0))
    {
      m_eCurrentState = transition.eDestiny;
    }
  }
}
