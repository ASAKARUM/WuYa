#include "Begining.h"

Begining::Begining(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Begining::~Begining()
{
}


void Begining::mousePressEvent(QMouseEvent *event)
{
	switch (t)
	{
	case 0:
	{
		ui.lblText->setText(QString::fromLocal8Bit("�ⳡ���Ѿ������˰�������"));
		break;
	}
	case 1:
	{
		ui.lblText->setText(QString::fromLocal8Bit("�����һ����ɽִ������Ҳ�а���֮����..."));
		break;
	}
	default:
		this->close();
		break;
	}
	t++;
	return;
}
