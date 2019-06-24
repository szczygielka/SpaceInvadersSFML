#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "State.h"
#include <stack>
#include <memory>


//maszyna zaimplementowana jako stack
class StateMachine
{
	std::stack< std::shared_ptr<State>> states;
	std::shared_ptr <State> newState;

	bool isRemoving;
	bool isAdding;
public:
	StateMachine() {}
	~StateMachine() {}

	void AddState(std::shared_ptr <State> newState);
	void RemoveState();
	void ProcessStateChanges();

	std::shared_ptr < State > GetActiveState();
};

#endif
