#pragma once
#include "state.h"

namespace FSM {
	class PlayerWalkState : public State {
		// Inherited via State
	public:
		PlayerWalkState() = default;
		virtual void OnEnter(Actors::GameObject& in_owner) override;
		virtual void OnExit(Actors::GameObject& in_owner) override;
		virtual void Update(Actors::GameObject& in_owner) override;
	};
}