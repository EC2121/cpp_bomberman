#pragma once
#pragma once
#include <memory>
#include "state.h"
#include <map>
#include <string>

namespace FSM {
	class IStateMachinable {
	public:
		IStateMachinable() = default;
		~IStateMachinable();
	public:
		void InsertState(States in_key, std::shared_ptr<State> in_state);
		void ChangeCurrentState(Actors::GameObject& in_owner,States in_key);
	protected:
		void Update(class Actors::GameObject& in_owner);
		std::map<States, std::shared_ptr<FSM::State>> states_map;
		std::shared_ptr<State> curr_state;

	protected:

	};
}