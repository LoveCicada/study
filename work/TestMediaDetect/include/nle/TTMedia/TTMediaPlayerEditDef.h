///////////////////////////////////////////////////////////
//  TTMediaPlayerEditDef.h
//  Created on:      21-����-2010 15:52:03
//  Original author: yangxiaodong
///////////////////////////////////////////////////////////

#if !defined(EA_2A7585A9_05DC_6d66_81D7_9170BC5E86E7__INCLUDED_)
#define EA_2A7585A9_05DC_6d66_81D7_9170BC5E86E7__INCLUDED_


enum ADDTYPE
{
	ADD_UNKNOW			= 0,					// δ֪���� 
	ADD_TITLEWORD,								// ������
	ADD_POLYGON,								// �����
	ADD_CIRCLE,									// Բ
	ADD_ANIMAL,									// ����
	ADD_MATERIALPAN,							// ����
	ADD_IMAGE,									// ͼ��
	ADD_ARTWORD,								// ������
	ADD_SONG,									// ����
	ADD_SCROLLSCREEN,							// ����
	ADD_CURVER,									// ����
	ADD_CLOCK,									// ʱ��
};


enum MODIFYTYPE
{ 
	MODIFY_UNKNOW		= 0x00000000,			// δ֪����
	MODIFY_INDEX		= 0x00000001,			// ����
	MODIFY_ALLINDEX		= 0x00000002,			// ����
	MODIFY_CHANGETEXT	= 0x00000004,			// �޸��ı�
	MODIFY_ADDTEXT		= 0x00000008,			// ����ı�
	MODIFY_DELTEXT		= 0x00000010,			// ɾ���ı�
	MODIFY_TIME			= 0x00000020,			// ʱ��
	MODIFY_COLOR		= 0x00000040,			// ��ɫ
	MODIFY_FONT			= 0x00000080,			// ����
	MODIFY_POS			= 0x00000100,			// �޸�λ��
	MODIFY_GETINFO		= 0x80000000,			// ��ȡ��Ϣ

};

enum MODIFYPOSTYPE
{
	MODIFY_POS_SET		= 0x00000001,			//����λ��
	MODIFY_POS_LEFT		= 0x00000002,			//�ƶ�������
	MODIFY_POS_TOP		= 0x00000004,			//�ƶ�������
	MODIFY_POS_BOTTOM	= 0x00000008,			//�ƶ�������
	MODIFY_POS_RIGHT	= 0x00000010,			//�ƶ�������
	MODIFY_POS_CENTER	= 0x00000020,			//�ƶ������м�
};


enum CLAPTYPE
{
	CLAP_UNKUNOW		= 0,					// δ֪����
	CLAP_BEGIN,									// ��ʼ��
	CLAP_STOP,									// ֹͣ��
	CLAP_ONE,									// һ����
	CLAP_NO_ONE,								// �Ǽ���
};

#endif // !defined(EA_2A7585A9_05DC_6d66_81D7_9170BC5E86E7__INCLUDED_)
