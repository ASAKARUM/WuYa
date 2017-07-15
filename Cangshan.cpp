#include "Cangshan.h"
#include "Dadian_c.h"
#include "MiShi_c.h"

Cangshan::Cangshan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnDadian, SIGNAL(clicked()), this, SLOT(OpenDadian()));
	connect(ui.btnMishi, SIGNAL(clicked()), this, SLOT(OpenMishi()));
	connect(ui.btnOut, SIGNAL(clicked()), this, SLOT(OpenOut()));

	extern int Schedule;
	if (Schedule == 4 || Schedule == 17)
	{
		ui.btnDadian->hide();
		ui.btnMishi->hide();
		ui.btnOut->hide();
	}
}

Cangshan::~Cangshan()
{
}

void Cangshan::mousePressEvent(QMouseEvent * event)
{
	extern int Schedule;
	if (Schedule == 4)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n����ҹ�ϻز�ɽ��ֻ��Ѫˮ����ɽ�ŵĽ������Ѷ��£�ɽ�������������˵�ʬ�御�Ե���Ѫ��֮�С�"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->hide();
			ui.btnDadian->show();
			ui.btnMishi->show();
			t++;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 17)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\nʮ���..."));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�˴���ɽ��������Ҳ����˵ʲô�ˣ�ֻ��Ҫע��С��..."));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n�����ڸ�����������ĺ���׼�������ң�˳���������䡣�����Ŀ�һ������ǰð���˰�߳��Ľ��С�"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n...Ϊʲô��"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�к�\n�Բ����ҵ�ʦ�������档"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\nԭ��...�ֲ��ã��ֲ�����ʮ�������δ�й���һ����ʦ������"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�к�\n...�Բ���"));
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n���˰��ˣ��ຣ���ģ���ͷ�ǰ����úû���ȥ�ɡ�"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\nʦ�ã���Ȼ��ԩԩ�౨��ʱ�˰���ʦ�����������㣬�ɻ��㲻��"));
			t++;
			break;
		}
		case 9:
		{
			extern bool END_b;
			END_b = true;
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

int Cangshan::OpenDadian()
{
	Dadian_c dd;
	dd.exec();
	extern int Schedule;
	if (Schedule == 6)
	{
		ui.btnOut->show();
	}
	return 0;
}

int Cangshan::OpenMishi()
{
	MiShi_c ms;
	ms.exec();
	extern int Schedule;
	if (Schedule == 6)
	{
		ui.btnOut->show();
	}
	extern bool END;
	if (END)
	{
		this->close();
	}
	return 0;
}

int Cangshan::OpenOut()
{
	this->close();
	return 0;
}
