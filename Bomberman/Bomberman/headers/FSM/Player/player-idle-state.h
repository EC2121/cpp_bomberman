#pragma once
#include "state.h"

namespace FSM {
	class PlayerIdleState : public State {
		// Inherited via State
	public :
		PlayerIdleState() = default;
		virtual void OnEnter(Actors::GameObject& in_owner) override;
		virtual void OnExit(Actors::GameObject& in_owner) override;
		virtual void Update(Actors::GameObject& in_owner) override;
	};
}