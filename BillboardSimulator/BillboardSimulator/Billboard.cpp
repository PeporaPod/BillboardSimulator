#include "Billboard.h"



//
//	�R���X�g���N�^
//
//		�d���f���̐���
//			���@�̑���(��ʃT�C�Y)
//			�z�u����LED�̐����v�Z
//			LED��z�u
//		���̑��ׂ��ȏ�����
//			�A�N�Z�X�ᔽ������邽�߂̎���������
//			�ŏ��̃��[�v�ŕ\���������s�����߂ɏ����^�C�~���O��ݒ�
//			�\�L����{�ꂩ��J�n�ɐݒ�
//
//
Billboard::Billboard()
{
/*�d���f���̐���*/
	/*��Ղ̐��@�𑪂�*/
	int screenwidth, screenheight, colorbitdepth;				//��ʕ�, ��ʍ�, �F�r�b�g�[�x
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);	//�擾
	/*��Ղ̐��@�𑪂�*/


	/*�z�u�ł���LED�̐����v�Z����*/
	Billboard::tablesize.row	= (screenheight	/ DISTANCE) - 1;	//�s��
	Billboard::tablesize.column	= (screenwidth	/ DISTANCE) - 1;	//��
	/*�z�u�ł���LED�̐����v�Z����*/


	/*LED��z�u����*/
	for (int row = 1; row <= Billboard::tablesize.row; row++) {
		LEDROW led_row;												//��LED�s

		/*LED�z�u�v�Z*/
		for (int column = 1; column <= Billboard::tablesize.column; column++) {
			LED led = { column * DISTANCE, row * DISTANCE, LED_OFF };	//LED�̈ʒu�v�Z
			led_row.push_back(led);										//LED����LED�s�֒ǉ�
		}
		/*LED�z�u�v�Z*/

		ledtable.push_back(led_row);								//LED�s��LED�֒ǉ�
	}
	/*LED��z�u����*/
/*�d���f���̐���*/


/*���̑�������*/
	prev_datetime.Sec	= 63;					//�O��̏������s���������̏�����(63�b�ŏ�����)
	prev_millisecond	= GetNowCount() - 2048;	//�O��̃f�B�X�v���C�o�͎��̃~���b����(2048�~���b�O�ŏ�����)
	english_trigger		= false;				//���{��E�p��\�L�̃g���K(���{��ŏ�����)
	firsttrain_id		= -1;					//�攭��Ԃ̎����\ID�𑶍ݔ͈͊O�ŏ�����
/*���̑�������*/
}



//
//	�����\�̓ǂݍ���
//
//
bool Billboard::Init()
{
	if (timetable.Init() == -1)	//�����\�̐���
		return false;								//�G���[��
	return true;
}



//
//	�d���f���̉ғ��J�n
//
//
void Billboard::Start()
{
	DATEDATA now_datetime;
	GetDateTime(&now_datetime);
	Billboard::Process(now_datetime);
}



//
//	LED��S�ď�������
//
//
void Billboard::Clear()
{
	for (int row = 0; row < Billboard::tablesize.row; row++)
		for (int column = 0; column < Billboard::tablesize.column; column++)
			ledtable[row][column].color = LED_OFF;	//�����w��
}



//
//	����ʂ�LED��`�悵�A�f�B�X�v���C�ɕ\�������̑ҋ@������
//
//
void Billboard::Set()
{
	for (int row = 0; row < Billboard::tablesize.row; row++)
		for (int column = 0; column < Billboard::tablesize.column; column++)
			DrawCircle(ledtable[row][column].x, ledtable[row][column].y, RADIUS, ledtable[row][column].color);	//�`��
}



//
//	�����X�V
//
//		����00�b / DISPLAYTIME[�~���b]�o�ߖ��ɓ��{��E�p��\�L��ؑ� ("Header.h"�Q��)
//
//
void Billboard::Update()
{
	/*���ݎ����̎擾*/
	DATEDATA now_datetime;			//���݂̓��t�E����
	GetDateTime(&now_datetime);		//���݂̓��t�E�����̎擾
	int now_milsec = GetNowCount();	//���݂̃~���b�����̎擾
	/*���ݎ����̎擾*/

	/*���ݎ����E�o�ߎ��Ԃɂ��\���̍X�V����*/
	if (!now_datetime.Sec && prev_datetime.Sec != now_datetime.Sec) //����00�b�ł̍X�V����
		Billboard::Process(now_datetime);							//�������f
	else if (now_milsec - prev_millisecond >= DISPLAYTIME/* * (english_trigger + 1)*/)			//�O��̕\���X�V��������2000�~���b�o�߂����ۂ̕\���X�V
		Billboard::Change();
	/*���ݎ����E�o�ߎ��Ԃɂ��\���̍X�V����*/

	Billboard::prev_datetime = now_datetime;	//�������s�����������X�V
}



//
//	�f�B�X�v���C��LED�̏o�͂����s �y�� ���ɕ`�悷����e�����肷��
//
//
void Billboard::Process(DATEDATA now_datetime)
{
	/*��ԏ����X�V����K�v�����邩�m�F*/
	int firsttrain_id_next = timetable.GetID(now_datetime.Hour * 100 + now_datetime.Min);
	if (firsttrain_id == firsttrain_id_next) return;	//�K�v�Ȃ��ꍇ�͏I��
	firsttrain_id = firsttrain_id_next;					//������Ԃ�攭��ԂɕύX
	/*��ԏ����X�V����K�v�����邩�m�F*/

	english_trigger = false;	//�\�L����{��ɐݒ�

	Billboard::Clear();			//LED��S�ď���
	
								//LED�̓_����Ԃ𔽉f
	timetable.Set(ledtable, tablesize, firsttrain_id, DISPLAYROW, 0, 0, english_trigger);

	Billboard::Set();			//����ʂ֕`��

	Billboard::Change();		//�f�B�X�v���C�֏o�͋y�ю��̕`����e������
}



//
//	�f�B�X�v���C�ւ̏o�� �y�� ���{��E�p��\�L��؂�ւ��ďo�͂̃X�^���o�C
//
//
void Billboard::Change()
{
	ScreenFlip();						//�f�B�X�v���C�֏o��
	prev_millisecond = GetNowCount();	//�f�B�X�v���C�X�V�^�C�~���O���X�V

	Billboard::Clear();					//LED��S�ď���

	//LED�̓_����Ԃ𔽉f
	timetable.Set(ledtable, tablesize, firsttrain_id, DISPLAYROW, 0, 0, english_trigger);

	english_trigger = !english_trigger;	//���{��E�p��̕\�L�ؑ�

	Billboard::Set();					//����ʂ֕`��
}



Billboard::~Billboard()
{
}
