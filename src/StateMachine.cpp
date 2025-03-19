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

StateMachine::EState StateMachine::GetCurrentState() const
{
    return m_eCurrentState;
}

const char* StateMachine::GetCurrentStateString() const
{
  const char* sState = "INVALID";
  switch (m_eCurrentState)
  {
    case StateMachine::STANDING:
    {
      sState = "STANDING";
    }
    break;
    case StateMachine::DUCKING:
    {
      sState = "DUKING";
    }
    break;
    case StateMachine::JUMPING:
    {
      sState = "JUMPING";
    }
    break;
    case StateMachine::DIVING:
    {
      sState = "DIVING";
    }
    break;
    default:
    {
      sState = "INVALID";
    }
  }
  return sState;
}

bool StateMachine::CanTransit(const char* _sInput) const
{
  bool bCanTransit = false;
  for (Transition transition : m_vTransitions)
  {
    if ((transition.eOrigin == m_eCurrentState) && (strcmp(transition.sCondition, _sInput) == 0))
    {
      bCanTransit = true;
      break;
    }
  }
  return bCanTransit;
}

void StateMachine::Transit(const char* _sInput)
{
  for (Transition transition : m_vTransitions)
  {
    if ((transition.eOrigin == m_eCurrentState) && (strcmp(transition.sCondition, _sInput) == 0))
    {
      m_eCurrentState = transition.eDestiny;
      break;
    }
  }
}
