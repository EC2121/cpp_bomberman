#include "player-walk-state.h"
#include "game-object.h"
#include "player.h"
namespace FSM {
	void PlayerWalkState::OnEnter(Actors::GameObject& in_owner)
	{
		((Actors::Player&)in_owner).ChangeCurrentAnimation("walk");
	}
	

	void PlayerWalkState::OnExit(Actors::GameObject& in_owner)
	{
		in_owner.ResetVelocity();
	}

	void PlayerWalkState::Update(Actors::GameObject& in_owner)
	{
		Actors::Player& ref = (Actors::Player&)in_owner;
		if (!ref.CheckForMovementInputs())
		{
			ref.ChangeCurrentState(in_owner,IDLE);
		}
		if (ref.CheckForAttackInput())
		{
			ref.ChangeCurrentState(in_owner,ATTACK);
		}
	}
}

