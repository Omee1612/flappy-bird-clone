#pragma once
#include <memory>

#include "state.h"

class statemachine
{
private:
	std::stack<std::unique_ptr<state>> states;
	bool isAdding=false;
	bool isReplacing=false;
	bool isRemoving=false;
	std::unique_ptr<state> newState;
public:
	void addState(std::unique_ptr<state> State,bool isReplacing = true);
	void removeState(std::unique_ptr<state> State);
	void processState();
	std::unique_ptr<state>& getActiveState();
};

