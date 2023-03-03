#pragma once

namespace Actors {
	class GameObject;
}

namespace FSM {
	enum States {
		IDLE,
		WALK,
		ATTACK
	};

	class State {

	public:
		State() = default;
		virtual void OnEnter(Actors::GameObject& in_owner) = 0;
		virtual void OnExit(Actors::GameObject& in_owner) = 0;
		virtual void Update(Actors::GameObject& in_owner) = 0;
	};


}