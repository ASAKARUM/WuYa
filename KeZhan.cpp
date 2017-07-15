#include "KeZhan.h"
#include "Tip.h"
#include <QTime>
#include "Bag.h"
#include "State.h"

KeZhan::KeZhan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnBXS, SIGNAL(clicked()), this, SLOT(OpenBXS()));
	connect(ui.btnRest, SIGNAL(clicked()), this, SLOT(OpenRest()));
	connect(ui.btnBag, SIGNAL(clicked()), this, SLOT(OpenBag()));
	connect(ui.btnState, SIGNAL(clicked()), this, SLOT(OpenState()));

	QTime tm;
	tm = QTime::currentTime();
	qsrand(tm.msec() + tm.second() * 1000);

	extern int Schedule;
	if (Schedule == 2)
	{
		ui.btnBXS->hide();
		ui.lblBXS->hide();
		ui.btnRest->hide();
		ui.btnBag->hide();
		ui.btnState->hide();
	}
	if (Schedule >= 7 && Schedule <= 20)
	{
		ui.lblText->hide();
	}
}

KeZhan::~KeZhan()
{
}

void KeZhan::mousePressEvent(QMouseEvent * event)
{
	extern int Schedule;
	if (Schedule == 2)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�ƿͼ�\n�������˰�����£����ⶼ�����ˣ����ǻ�����"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�ƿ���\n�����������ǲ�ɽ��������̫���ˣ�Թ������..."));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n���Ǳߺ����ᵽ�˲�ɽ�ɣ���Ҳ���δ������ʦ�ŵ���Ϣ�ˣ�������ȥ̽��һ�¡���"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n��λ���֣���������λ�ᵽ�˲�ɽ�ɣ��������������ʲô���£�"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�ƿͼ�\n���¶��ֵ������������˾���֪����λС�羹��δ����˵��"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("�ƿ���\n���¶�Ҫ�Ӱ����ǰ˵����...�����ǰ����Ӱɽ�����Ŵ���ɱ�ϲ�ɽ����սһ��һҹ����ɽ��ǰѪ���ɺӣ���ɽ�ɰ����ҵ��һҹ֮�䣬��Ȼ���������ǿ�ϧ������ϧ��"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n���Ȼ������ǰ���ڣ����к���һƬ��ֻ�������ƿ�����֮�����ڻ��㣬���ñ�ʧȥ��֪��..."));
			t++;
			break;
		}
		case 7:
		{
			Schedule++;
			t++;
			this->close();
			break;
		}
		default:
			break;
		}
	}
	if (bxs)
	{
		switch (tb)
		{
		case 0:
		{
			QString str;
			int n = qrand() % 8;
			switch (n)
			{
			case 0:
			{
				str = QString::fromLocal8Bit("������\n�����ϴ������������������װ���ֱ����ڶ����ϱ��ĸ���λ�������������ػ������ܹ��õ���������װ����ɳư����֣��������¡�");
				break;
			}
			case 1:
			{
				str = QString::fromLocal8Bit("������\n������ҽ�ݵĴ����ʵ��ݿ���ҩ���ȵ�ǰ�ι��������Ǵ��������а���");
				break;
			}
			case 2:
			{
				str = QString::fromLocal8Bit("������\nԩԩ�౨��ʱ��...");
				break;
			}
			case 3:
			{
				str = QString::fromLocal8Bit("������\n���˵ĵط������ǽ�����");
				break;
			}
			case 4:
			{
				str = QString::fromLocal8Bit("������\nӰɽ�����������ǵ����������书��һ��ǿ֮�ˣ��������Ƕ�ʮ��ǰ��ɽ�ɽ���ħ��ʱ�Ҵ�������ħ���Ź¡�");
				break;
			}
			case 5:
			{
				str = QString::fromLocal8Bit("������\n������������ߣ��ഫ����һλ���ָ��֣����������������ң���ڡ�");
				if (Schedule == 7)
				{
					Schedule++;
				}
				break;
			}
			case 6:
			{
				str = QString::fromLocal8Bit("������\n�ڿ�ջ��Ϣһ�����ܻظ����е���Ѫ����������һ�ԡ�");
				break;
			}
			case 7:
			{
				str = QString::fromLocal8Bit("������\n��ɽ�ɴ���ӽ��꣬�Ǹ����˲��֮�ˣ���һ��������������������Ӱɽ����ɽ֮ʱ������������������Ŷ��һ�٣����Ҳ��֪��ô���ˡ�");
				break;
			}
			default:
				break;
			}
			ui.lblText->setText(str);
			tb++;
			break;
		}
		case 1:
		{
			ui.lblText->clear();
			ui.lblText->hide();
			ui.btnBXS->show();
			ui.lblBXS->show();
			ui.btnRest->show();
			ui.btnBag->show();
			ui.btnState->show();
			bxs = false;
			tb++;
			break;
		}
		default:
			break;
		}
	}
}

int KeZhan::OpenBXS()
{
	ui.btnBXS->hide();
	ui.lblBXS->hide();
	ui.btnRest->hide();
	ui.btnBag->hide();
	ui.btnState->hide();
	ui.lblText->show();
	tb = 0;
	bxs = true;
	return 0;
}

int KeZhan::OpenRest()
{
	ui.btnBXS->hide();
	ui.btnBag->hide();
	ui.btnState->hide();
	ui.btnRest->hide();
	ui.lblBXS->hide();
	Tip tp(QString::fromLocal8Bit("�Ƿ񻨷�100����Ϣһ��"));
	int ret = tp.exec();
	extern int Money;
	extern int Blood;
	extern int Blood_max;
	extern int Pneuma_max;
	extern int Pneuma;
	if (ret == QDialog::Accepted && Money >= 100)
	{
		Money -= 100;
		Blood = Blood_max;
		Pneuma = Pneuma_max;
	}
	else if (ret == QDialog::Accepted && Money < 100)
	{
		Tip tp(QString::fromLocal8Bit("���㣡"));
		tp.exec();
	}
	ui.btnBXS->show();
	ui.btnBag->show();
	ui.btnState->show();
	ui.btnRest->show();
	ui.lblBXS->show();
	return 0;
}

int KeZhan::OpenBag()
{
	Bag bg;
	bg.exec();
	return 0;
}

int KeZhan::OpenState()
{
	State st;
	st.exec();
	return 0;
}
