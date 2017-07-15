#include "MiShi_c.h"

MiShi_c::MiShi_c(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

MiShi_c::~MiShi_c()
{
}

void MiShi_c::mousePressEvent(QMouseEvent *event)
{
	extern bool Key_cs_ms;
	extern int Schedule;
	if (!Key_cs_ms)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n���������ˣ�ȥ�Ĵ�תת����һ��Կ�װɡ�"));
			t++;
			break;
		}
		case 1:
		{
			this->close();
		}
		default:
			break;
		}
	}
	if (Key_cs_ms && Schedule == 5)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n����ʦ�ã��������ţ�ֻ����Ϣ΢���������������ˡ���"));
			t++;
			break;
		}
		case 1:
		{
			extern bool Drug_01;
			if (Drug_01)
			{
				ui.lblText->setText(QString::fromLocal8Bit("����\n���ҿ��ز�ɽ֮ǰ����׼�������ʦ�÷�ҩ�ɡ���"));
				Drug_01 = false;
				extern int Sister_state;
				Sister_state = 2;
				t++;
				break;
			}
			if (!Drug_01)
			{
				ui.lblText->setText(QString::fromLocal8Bit("������û���κο��Ծ�ʦ�õ�ҩ���������ؿ���ʦ�ö�����������֮�£������Ӱɽ��Ϊ��ɽ�������������˱��𣬽��ȴ����Ӱɽ���������¡�"));
				extern bool END;
				extern int Sister_state;
				Sister_state = 0;
				END = true;
				this->close();
			}
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\nʦ����������������ʦ�֣������㡰�ۡ��ؿ��˳�����"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("ʦ��\nʦ�֣������ڻ����ˣ�������ʦ���Ƕ�..."));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n�㰲ο��ʦ�á�Ƭ�̺�ʦ�õ������ȶ��������ó�һ�����ӡ�"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("ʦ��\nʦ�֣����ǵ�������ǰ���ҽ�����ġ�����˵�����㲻Ҫ�嶯��Ҫ�úû���ȥ..."));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n��򿪺��ӣ�����������һ�ŵ�ͼ��"));
			extern bool Map_xw;
			Map_xw = true;
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n�õ�����ߵ�ͼ������߿�����"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\nʦ���ƺ��˵ú��أ��㴦����ɽ�����µ�ʬ�壬�����ȴ�ʦ�ûس����ˡ�"));
			t++;
			break;
		}
		case 9:
		{
			extern int Schedule;
			Schedule++;
			this->close();
		}
		default:
			break;
		}
	}
	if (Key_cs_ms && Schedule == 6)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n���Ǿ����ʦ��ȥ���˰ɡ�"));
			t++;
			break;
		}
		case 1:
		{
			this->close();
			t++;
		}
		default:
			break;
		}
	}
	return;
}
