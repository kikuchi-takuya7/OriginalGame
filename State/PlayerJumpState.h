#pragma once
#include "../State/PlayerState.h"

/// <summary>
/// �W�����v���Ă���
/// </summary>
class PlayerJumpState : public PlayerState
{

	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="player">Player�̃|�C���^</param>
	void Update(Player* player) override;


	/// <summary>
	/// ���͂ɂ���ď�Ԃ�ω�����
	/// </summary>
	/// <param name="player">Player�̃|�C���^</param>
	void HandleInput(Player* player) override;

	/// <summary>
	/// ��ԕω������Ƃ��Ɉ�x�����Ă΂��֐�
	/// </summary>
	/// <param name="player">Player�̃|�C���^</param>
	void Enter(Player* player) override;

private:

	float velocity_;

};
