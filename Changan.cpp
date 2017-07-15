#include "Changan.h"
#include "KeZhan.h"
#include "Yiguan.h"
#include <QDebug>

Changan::Changan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnKezhan, SIGNAL(clicked()), this, SLOT(OpenKezhan()));
	connect(ui.btnMinju1, SIGNAL(clicked()), this, SLOT(OpenMinju1()));
	connect(ui.btnMinju2, SIGNAL(clicked()), this, SLOT(OpenMinju2()));
	connect(ui.btnYiguan, SIGNAL(clicked()), this, SLOT(OpenYiguan()));
	connect(ui.btnOut, SIGNAL(clicked()), this, SLOT(OpenOut()));

	extern int Schedule;
	if (Schedule == 1)
	{
		ui.btnKezhan->hide();
		ui.btnMinju1->hide();
		ui.btnMinju2->hide();
		ui.btnYiguan->hide();
		ui.btnOut->hide();
	}
	if (Schedule == 6)
	{
		ui.btnKezhan->setEnabled(false);
		ui.btnMinju1->setEnabled(false);
		ui.btnMinju2->setEnabled(false);
		ui.btnOut->setEnabled(false);
	}
}

Changan::~Changan()
{
}

void Changan::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	if (Schedule == 1)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n������������ϡ��"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�������������������Ҹ���ջ�������١���"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n������������в�����\n�رյ�ǰ���淵����һ�����档"));
			t++;
			break;
		}
		case 3:
		{
			ui.btnKezhan->show();
			ui.btnMinju1->show();
			ui.btnMinju2->show();
			ui.btnYiguan->show();
			ui.btnOut->show();
			ui.btnMinju1->setEnabled(false);
			ui.btnMinju2->setEnabled(false);
			ui.btnYiguan->setEnabled(false);
			ui.btnOut->setEnabled(false);
			ui.lblText->hide();
			t++;
			Schedule++;
			qDebug() << Schedule;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 4 && t == 4)
	{
		ui.lblText->hide();
		ui.btnKezhan->show();
		ui.btnMinju1->show();
		ui.btnMinju2->show();
		ui.btnYiguan->show();
		ui.btnOut->show();
		ui.btnMinju1->setEnabled(false);
		ui.btnMinju2->setEnabled(false);
		ui.btnYiguan->setEnabled(false);
		ui.btnKezhan->setEnabled(false);
		ui.btnOut->setEnabled(true);
	}
	if (Schedule == 17)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n�����������������ꡣ"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n������Ŀ�ĵ��ڿտ��Ľֵ������ţ�ֱ����һ��С���ӿڿ�����һ��������ǽ�ߵ��к��ӡ�"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n���ӣ�����һʱ��ͣ���˵ģ���ؼҰɡ�"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�к�\n�ؼң�...���Ѿ�û�м��ˡ�"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�԰�...û�м��ˡ�"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n�����ڻ�Ӧ���к����ֺ������ڶ��Լ�˵�š�"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n������Ļ����͸����߰ɣ��ҿ��Խ����书�����...Ҳֻ���书�˰ɡ�"));
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�к�\n...����ʦ����"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n����ʦ���أ�"));
			t++;
			break;
		}
		case 9:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�к�\n...���ˡ�"));
			t++;
			break;
		}
		case 10:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n���ģ��Ҳ���������Ϊʦ��"));
			t++;
			break;
		}
		case 11:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�к�\n...�á�"));
			t++;
			break;
		}
		case 12:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n���������к��ӣ��ҵ�ʦ�õ��Źǣ��ص���ɽ��"));
			t++;
			break;
		}
		case 13:
		{
			this->accept();
			t++;
			break;
		}
		default:
			break;
		}
	}
	return;
}

int Changan::OpenKezhan()
{
	KeZhan kz;
	kz.exec();
	extern int Schedule;
	if (Schedule == 3)
	{
		Yiguan yg;
		yg.exec();
		ui.btnKezhan->hide();
		ui.btnMinju1->hide();
		ui.btnMinju2->hide();
		ui.btnYiguan->hide();
		ui.btnOut->hide();
		ui.lblText->show();
		ui.lblText->setText(QString::fromLocal8Bit("��ز�ɽ�����ɡ�"));
	}
	if (Schedule == 8)
	{
		ui.btnMinju1->setEnabled(true);
		ui.btnMinju2->setEnabled(true);
	}
	return 0;
}

int Changan::OpenMinju1()
{
	Minju1 mj1;
	mj1.exec();
	return 0;
}

int Changan::OpenMinju2()
{
	Minju2 mj2;
	mj2.exec();
	extern int Schedule;
	if (Schedule == 9)
	{
		ui.btnMinju1->setEnabled(false);
		ui.btnMinju2->setEnabled(false);
	}
	return 0;
}

int Changan::OpenYiguan()
{
	Yiguan yg;
	yg. exec();
	extern int Schedule;
	if (Schedule == 7)
	{
		ui.btnKezhan->setEnabled(true);
	}
	if (Schedule == 10)
	{
		ui.btnOut->setEnabled(true);
	}
	if (Schedule == 17)
	{
		ui.btnKezhan->hide();
		ui.btnMinju1->hide();
		ui.btnMinju2->hide();
		ui.btnYiguan->hide();
		ui.btnOut->hide();
	}
	extern bool END_h;
	if (END_h)
	{
		this->close();
	}
	return 0;
}

int Changan::OpenOut()
{
	accept();
	return 0;
}
