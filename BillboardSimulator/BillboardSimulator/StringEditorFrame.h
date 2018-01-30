#pragma once
#include <DxLib.h>
#include "Header.h"
#include "Billboard.h"
#include "Timetable.h"
#include "StringControler.h"
class StringEditorFrame
{
private:
	Billboard billboard;	//LED�}�g���N�X
	StringControler stringcontroler; //�������񐧌�N���X
	int size;	//�ǂݍ��񂾕�������̐�
	int current_id;	//���ݕ\�����̕�������ID
	StringInformation current_strinfo;	//���ݕ\�����̕�������
	StringInformation new_strinfo;	//�V�K�ǉ��p�o�b�t�@
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
private:
	void WriteOut();
};

