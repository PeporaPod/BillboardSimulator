#pragma once
#include "Header.h"
#include "TimeTable.h"
class Billboard
{
private:
	/*LED�}�g���N�X*/
				int			led_row;								//LED��
				int			led_column;								//LED��
				LED_MATRIX	led_matrix;								//LED�̍s��
	unsigned	int			led_color_off = GetColor(32, 32, 32);	//LED�����F
	/*LED�}�g���N�X*/

	/*�X�V�g���K*/
	DATEDATA	prev_datetime;		//�O��̏������s��������
	int			prev_millisecond;	//�O��̃f�B�X�v���C�o�͎��̃~���b����
	bool		english_trigger;	//�p��\�L�g���K
	int			firsttrain_id;		//�攭��Ԃ̎����\ID
	/*�X�V�g���K*/
public:
	Billboard();							//�R���X�g���N�^�y�я���������
	void Init();							//����������
	void Start();							//�J�n����
	void Clear();							//LED��S�ď�������
	void Set();								//����ʂ֕`��
	void Update();							//�����X�V����
	void Process(DATEDATA now_datetime);	//�f�B�X�v���C�o�́E�\�����e�X�V
	void Change();

	~Billboard();							//�f�X�g���N�^
};


