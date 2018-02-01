#pragma once
#include <DxLib.h>
#include "Header.h"
#include "Billboard.h"
#include "TimetableControler.h"
#include "StringControler.h"
class StringEditorFrame
{
private:
	/*��f�[�^*/
			Billboard			billboard;										//LED�}�g���N�X
			StringControler		stringcontroler;								//�������񐧌�N���X
	/*��f�[�^*/
	/*�\���E�ҏW�p�f�[�^*/
			int					str_vecsize;									//�ǂݍ��񂾕�������̐�
			int					current_id;										//���ݕ\�����̕�������ID
//			StringInformation	current_strinfo;								//���ݕ\�����̕�������
//			StringInformation	new_strinfo;									//�V�K�ǉ��p�o�b�t�@
	const	int					font_size = SCREENHEIGHT_STRINGDISPLAY / 12;
	/*�\���E�ҏW�p�f�[�^*/
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
private:
	void MainLoop();
	void EditorMode(StringInformation strinfo, unsigned int register_id);
	void OverWrite(StringInformation rewrite_strinfo, unsigned int current_id);
};

