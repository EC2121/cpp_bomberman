#include "player-idle-state.h"
#include "game-object.h"
#include "player.h"
namespace FSM {
	void PlayerIdleState::OnEnter(Actors::GameObject& in_owner)
	{
		((Actors::Player&)in_owner).ChangeCurrentAnimation("idle");
	}

	void PlayerIdleState::OnExit(Actors::GameObject& in_owner)
	{
	}

	void PlayerIdleState::Update(Actors::GameObject& in_owner)
	{
		Actors::Player& ref = (Actors::Player&)in_owner;
		if (ref.CheckForMovementInputs())
		{
			ref.ChangeCurrentState(in_owner,WALK);
		}
		if (ref.CheckForAttackInput())
		{
			ref.ChangeCurrentState(in_owner,ATTACK);
		}
	}
}

