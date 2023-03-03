#pragma once
#include "state.h"
namespace FSM {
	class PlayerAttackState : public State {
		// Inherited via State
	public:
		PlayerAttackState() = default;
		virtual void OnEnter(Actors::GameObject& in_owner) override;
		virtual void OnExit(Actors::GameObject& in_owner) override;
		virtual void Update(Actors::GameObject& in_owner) override;
	};
}