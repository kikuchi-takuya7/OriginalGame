#pragma once
#include "../Engine/GameObject.h"

//���������Ǘ�����N���X
class MapController : public GameObject
{
    int hModel_;
public:
    //�R���X�g���N�^
    MapController(GameObject* parent);

    //�f�X�g���N�^
    ~MapController();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};