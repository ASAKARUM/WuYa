#include "Yingshan.h"
#include "war.h"

Yingshan::Yingshan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnRS, SIGNAL(clicked()), this, SLOT(OnRongshe()));

	ui.btnRS->hide();
	extern int Schedule;
	if (Schedule != 15)
	{
		ui.lblText->hide();
	}
}

Yingshan::~Yingshan()
{
}

int Yingshan::OnRongshe()
{
	extern bool END;
	war wr;
	int ret = wr.exec();
	if (ret == QDialog::Accepted)
	{
		ui.btnRS->hide();
	}
	if (!ret && END)
	{
		this->close();
	}
	return 0;
}

void Yingshan::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	if (Schedule == 15)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n��һ·ɱ��Ӱɽ��ƾ��һ����װ����߱�񣬷�ɱ�����ڱƳ����������档"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n���˲�ɽ�ɴ���ӽ��꣬���ձ���Ϊ�Ҳ�ɽ�ɱ���"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n��֪С���������ȥ�����ǰɡ�"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->hide();
			ui.btnRS->show();
			t++;
			break;
		}
		default:
			break;
		}
	}
	return;
}
