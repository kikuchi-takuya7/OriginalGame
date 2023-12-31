#include "PlayerIdleState.h"
#include "PlayerStateManager.h"

void PlayerIdleState::Update(Player* player)
{


	HandleInput(player);
}


void PlayerIdleState::HandleInput(Player* player)
{
	
	if (Input::IsKeyDown(DIK_SPACE)) {
		PlayerStateManager::playerState_ = PlayerStateManager::playerJumpState_;
		PlayerStateManager::playerState_->Enter(player);
	}

}

void PlayerIdleState::Enter(Player* player)
{
}
