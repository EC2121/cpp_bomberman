#include "player-attack-state.h"
#include "game-object.h"
#include "player.h"
namespace FSM {
	void PlayerAttackState::OnEnter(Actors::GameObject& in_owner)
	{
		((Actors::Player&)in_owner).ChangeCurrentAnimation("attack");
		((Actors::Player&)in_owner).Attack();
	}

	void PlayerAttackState::OnExit(Actors::GameObject& in_owner)
	{
	}

	void PlayerAttackState::Update(Actors::GameObject& in_owner)
	{
	}
}

