#include "statemachine.h"



std::unique_ptr<state>& statemachine::getActiveState()
{
	if (states.empty())
	{
		throw std::runtime_error("No active state!"); // Debug message for empty stack
	}
	return states.top();
}

void statemachine::addState(std::unique_ptr<state> State, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = std::move(State);
}

void statemachine::removeState(std::unique_ptr<state> State)
{
	this->isRemoving = true;
}

void statemachine::processState()
{
	if(isAdding)
	{
		if(isReplacing && !this->states.empty())
		{
			this->states.pop();
		}
		this->states.push(std::move(this->newState));
		this->states.top()->init();
		isAdding = false;
	}
	if(isRemoving)
	{
		if(!states.empty())
		{
			states.pop();
			this->states.top()->resume();
		}
		this->isRemoving = false;
	}
}


