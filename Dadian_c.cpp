#include "Dadian_c.h"

Dadian_c::Dadian_c(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Dadian_c::~Dadian_c()
{
}

void Dadian_c::mousePressEvent(QMouseEvent * event)
{
	extern int Schedule;
	extern bool Key_cs_ms;
	if (Schedule == 4)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\nֻ��һ�����ذ��мӵ�ʦ���˿�������һƬ���ѸɺԵ�Ѫ��֮�У������Ŀ�����в�ʤ���ߡ����߹�ȥ������ʦ�������Ϊ��������˫�ۣ�ȴͻȻ����ʦ�����з·�����ʲô...ԭ����һ��Կ�ס�"));
			Key_cs_ms = true;
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n����...��ɽ���ҵ�Կ�ף�Ī����ʦ�������ҵ���������ȥ���ҿ����ɣ�"));
			t++;
			break;
		}
		case 2:
		{
			Schedule++;
			this->close();
			break;
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
			ui.lblText->setText(QString::fromLocal8Bit("\n���Ǿ���ȥ�����Ұɡ�"));
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
