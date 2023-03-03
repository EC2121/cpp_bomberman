#include "IStateMachinable.h"
#include "game-object.h"
namespace FSM {
	IStateMachinable::~IStateMachinable()
	{
		states_map.clear();
	}
	void IStateMachinable::InsertState(States in_key, std::shared_ptr<State> in_state)
	{
		states_map[in_key] = in_state;
		curr_state = states_map[in_key];
	}
	void IStateMachinable::ChangeCurrentState(Actors::GameObject& in_owner,States in_new_state_key)
	{
		curr_state->OnExit(in_owner);
		curr_state = states_map[in_new_state_key];
		curr_state->OnEnter(in_owner);
	}
	void IStateMachinable::Update(Actors::GameObject& in_owner)
	{
		if (curr_state.get())
		{
			curr_state->Update(in_owner);
		}
	}
}

