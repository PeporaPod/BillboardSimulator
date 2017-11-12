#pragma once
#include "Header.h"
#include "TimeTable.h"
class Billboard
{
private:
	/*LED�{��*/
	LEDTABLE	ledtable;			//LED�̍s��
	TABLESIZE	tablesize;			//LED�̍s��
	/*LED�{��*/

	/*�f�[�^*/
	TimeTable	timetable;			//�����\
	/*�f�[�^*/

	/*�X�V�g���K*/
	DATEDATA	prev_datetime;		//�O��̏������s��������
	int			prev_millisecond;	//�O��̃f�B�X�v���C�o�͎��̃~���b����
	bool		english_trigger;	//�p��\�L�g���K
	int			firsttrain_id;		//�攭��Ԃ̎����\ID
	/*�X�V�g���K*/
public:
	Billboard();							//�R���X�g���N�^�y�я���������

	bool Init();							//����������
	void Start();							//�J�n����
	void Clear();							//LED��S�ď�������
	void Set();								//����ʂ֕`��
	void Update();							//�����X�V����
	void Process(DATEDATA now_datetime);	//�f�B�X�v���C�o�́E�\�����e�X�V
	void Change();

	~Billboard();							//�f�X�g���N�^
};


