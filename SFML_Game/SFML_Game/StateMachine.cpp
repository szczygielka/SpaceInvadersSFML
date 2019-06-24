#include "StateMachine.h"
//Maszyna stan�w, dodawanie i usuwanie stan�w nast�pnych nast�puje w nast�pnym kroku generowania widok�w
void StateMachine::AddState(std::shared_ptr < State > newState)
{
	this->isAdding = true;

	this->newState = newState;
}

void StateMachine::RemoveState()
{
	this->isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (!this->states.empty() && this->isRemoving)
	{
		this->states.pop();
		this->isRemoving = false;
	}
	//isAdding - bool 
	if (this->isAdding)
	{
		this->states.push(newState); //na stos
		this->states.top()->Init(); //inicjalizacja 
		this->isAdding = false;
	}
}

std::shared_ptr <State> StateMachine::GetActiveState()
{
	return this->states.top();
}