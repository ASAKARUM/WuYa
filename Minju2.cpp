#include "Minju2.h"

Minju2::Minju2(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Minju2::~Minju2()
{
}

void Minju2::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	if (Schedule == 8)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\nǰ����֪�����������Ϲ����������䣿С�ü�������ҩ�Ľⶾ��"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�Ϸ����ڶ���ǰն��һֻ����������Ǿ��ˣ��ⱱ������֮�������ȥ�ɡ�"));
			extern bool Drug_02;
			Drug_02 = true;
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n��лǰ���ˡ�"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�Ϸ������˳��������ⶫ������Ҳ��ռ�ض���������������ȥ���ˡ�ֻ�����Ϲ�����...�Ϸ�Ҳ������Ϊ���ˡ�"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n��лǰ��������������Ҳ�������߶���ˣ���ǡ�"));
			t++;
			break;
		}
		case 5:
		{
			Schedule++;
			this->close();
			t++;
			break;
		}
		default:
			break;
		}
	}
	return;
}
