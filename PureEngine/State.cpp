#include "stdafx.h"
#include "State.h"

using namespace pure;

State::State(StateManager* manager): 
	m_bTransparent(false),
	m_bTranscendant(false),
	m_bActive(false),
	m_stateManager(manager)
{
}


State::~State()
{
}

bool State::isTransparent() const
{
	return m_bTransparent;
}

bool State::isTranscendant() const
{
	return m_bTranscendant;
}

bool State::isActive() const
{
	return m_bActive;
}
