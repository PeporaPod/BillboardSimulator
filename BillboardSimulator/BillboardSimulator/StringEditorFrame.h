#pragma once
#include <DxLib.h>
#include "Header.h"
#include "Billboard.h"
#include "TimetableControler.h"
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
	int cursor_row;
	int cursor_column;
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
private:
	void MainLoop();
	void OverWrite(StringInformation rewrite_strinfo, unsigned int current_id);
};

