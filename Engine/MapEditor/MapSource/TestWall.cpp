#include "TestWall.h"
#include "../MapData.h"
#include "../../Model.h"


//�R���X�g���N�^
TestWall::TestWall(GameObject* parent)
    :GameObject(parent, "TestWall"), hModel_(-1),isDelete_(false),isClose_(false)
{
}

//�f�X�g���N�^
TestWall::~TestWall()
{
}

//������
void TestWall::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Map/testWall.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void TestWall::Update()
{
}

//�`��
void TestWall::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void TestWall::Release()
{
}

void TestWall::Imgui_Window()
{

	//ImGui::Begin("DataWindow");
	//Imgui_Data_Edit();

}

void TestWall::Imgui_Data_Edit()
{
	ImGui::Begin("DataWindow");

	//Imgui�̖��O�\����char�ɂ���K�v�����邽�߂��̏���
	int tmp = GetObjectID();
	std::string ID = std::to_string(tmp);
	std::string str = GetObjectName() + ID;
	const char* windowName = str.c_str();

	if (ImGui::CollapsingHeader(windowName))
	{

		Setting_Transform(transform_, -100.0f, 100.0f, 365.0f, 5.0f, GetObjectName() + ID);

		//Delete�{�^���������ꂽ��Delete�̊m�F�E�B���h�E��\�����ĉ����ꂽ�����
		str = "delete" + ID;
		const char* deleteName = str.c_str();
		if (ImGui::Button(deleteName)) {
			isDelete_ = true;
		}

		if (isDelete_) {
			ImGui::SetNextWindowPos(ImVec2(600, 300), ImGuiCond_Once);//ImGuiCond_FirstUseEver�����t����Ə��߂Ď��s�����Ƃ��������̑傫���ɐݒ肳��āB����ȍ~��imgui.ini�ɕۑ������
			ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_Once);
			std::string tmp = str + "OK?";
			const char* deleteConf = tmp.c_str();
			ImGui::Begin(deleteConf, &isDelete_);
			if (ImGui::Button(deleteConf)) {

				KillMe();
			}
			ImGui::End();
		}

		str = "ChangeUp" + ID;
		const char* changeUp = str.c_str();
		if (ImGui::Button(changeUp)) {
			((MapData*)this->GetParent())->ChengeUp(this);
			//KillMe();
		}

		str = "ChangeDown" + ID;
		const char* changeDown = str.c_str();
		if (ImGui::Button(changeDown)) {
			((MapData*)this->GetParent())->ChengeDown(this);
		}

	}
	ImGui::End();
}

bool TestWall::IsKillCheck()
{
	return isDelete_;
}

void TestWall::DeleteMe()
{
	isDelete_ = true;
}

void TestWall::DeleteStop()
{
	isDelete_ = false;
}