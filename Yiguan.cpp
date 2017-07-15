#include "Yiguan.h"
#include "Tip.h"
#include "Shenyi.h"
#include "Tip.h"

Yiguan::Yiguan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnSY, SIGNAL(clicked()), this, SLOT(OpenSY()));

	extern int Schedule;
	extern bool Drug_02;
	extern bool Drug_03;
	if (Schedule == 3 || Schedule == 6 || (Schedule == 7 && !Drug_02)
		|| (Schedule == 9 && Drug_02) || (Schedule==14 && Drug_03)
		|| Schedule == 16)
	{
		ui.btnSY->hide();
		ui.lblSY->hide();
	}
	if (Schedule >= 10 && Schedule <= 13 || Schedule == 15
		|| Schedule>=17 && Schedule <= 20)
	{
		ui.lblText->hide();
	}
}

Yiguan::~Yiguan()
{
}

void Yiguan::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	extern bool Drug_02;
	extern bool Drug_03;
	if (Schedule == 3)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n����ת��������ǰ���ǻ���һ�������������ڴ��ϣ�һλ�������ڿ����㡣"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n�����ˣ�"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n����ͷ�������ּ��𷽲���������Ϣ��ֻ����̫����ʵ��ֻ�뾡��ز�ɽ������"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n�ҿ�����ɫ�Ұܣ�ӡ�÷��ڣ�������������֮״���������������Ϸ��з�����ҩ�������ȵ����裬����һ��ʱ��֮�ڻ�������׹ǡ��ҿ�������Ե������������㣬������ʧ��ʧ����������"));
			t++;
			break;
		}
		case 4:
		{
			Tip tp(QString::fromLocal8Bit("�Ƿ񻨷�2000�Ĺ���һ�����ȵ����裿"));
			int ret = tp.exec();
			if (ret == QDialog::Accepted)
			{
				extern bool Drug_01;
				extern int Money;
				Drug_01 = true;
				Money -= 2000;
			}
			ui.lblText->setText(QString::fromLocal8Bit("����\n��л���£�������Ҫ����������һ���ˡ�"));
			t++;
			break;
		}
		case 5:
		{
			extern int Schedule;
			Schedule++;
			this->close();
		}
		default:
			break;
		}
	}
	if (Schedule == 6)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n����Ҽ�С�������ˣ������������ҲҪ�κ�����"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n�������£��Ϸ����ơ�"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n�������Ƭ��..."));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n���С���ж���������Ƿ������Ϸ�����ȵ����裬����Ҳ�Ų��������ˡ�"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�ɻ��а취ҽ�Σ�"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n�취�����У�ֻ��Ҫ�õ������ҩ�ģ�����Ҫ��һ������ġ�"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\nʲôҩ�ģ�"));
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n��������֮�Ǻ��Ϲ�����֮�ۡ�"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�����ȥ�ҡ�"));
			t++;
			break;
		}
		case 9:
		{
			extern int Schedule;
			Schedule++;
			this->close();
			break;
		}
		default:
			break;
		}
	}

	if (Schedule == 7 || (Schedule == 8 && !Drug_02))
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\nȥ����һ��ҩ�ĵ�����ɡ�"));
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

	if (Schedule == 9 && Drug_02)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n���˱�������֮�ǣ������Ķ����ǿ�������һ��ʱ�䡣������Ȭ�������Ϲ�����֮�۲��ɰ���"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\nֻ����������Ǻ���ͷ����"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n����������֮����ش���ĳ����ϵ������ȥ��һ�¡�"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n�ã������ȥ��"));
			t++;
			break;
		}
		case 4:
		{
			Drug_02 = false;
			Schedule++;
			this->close();
			t++;
			break;
		}
		default:
			break;
		}
	}

	if (Schedule == 14)
	{
		int ret;
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n�ԶԶԣ�������������ˣ������ȥΪ�ǹ�������"));
			Drug_03 = false;
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n����ʱ��֮��..."));
			extern int Sister_state;
			Sister_state++;
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("ʦ��\nʦ��..."));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\nʦ�ã����˴������Σ��㲻�þͻ�Ȭ���ˣ����������ﰲ�������ɡ�"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("ʦ��\nʦ�֣���Ҫȥ�Ķ���"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n���Ѿ��������ļ���װ�����ڱ����Ӱɽ���������棬Ϊ��ɽ�����������˱���"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("ʦ��\nʦ�֣���������ǰ���һ�仰������Ҫ���Ǻúû���ȥ���㻹�ǲ������Ŀ�����ԩԩ�౨��ʱ�ˣ�ʦ��..."));
			t++;
			break;
		}
		case 7:
		{
			Tip tp(QString::fromLocal8Bit("�Ƿ�ѡ���������"));
			ret = tp.exec();
			if (ret == QDialog::Rejected)
			{
				re = true;
			}
			else if (ret == QDialog::Accepted)
			{
				ac = true;
			}
			Schedule++;
			t++;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 15)
	{
		switch (t2)
		{
		case 0:
		{
			if (re)
			{
				ui.lblText->setText(QString::fromLocal8Bit("����\n�ã�ʦ������ġ�����...�ؼҡ�"));
				extern bool END_h;
				END_h = true;
				this->close();
			}
			else if (ac)
			{
				ui.lblText->setText(QString::fromLocal8Bit("����\nʦ�ã�ԭ��ʦ��ʵ���ǲ����Ŀ��ų�Ϧ�ദ��ͬ�ž������װ�ɥ�����������ﰲ����������ʦ�ֱ��˳𣬾ͻ������㡣"));
				t2++;
				break;
			}
		}
		case 1:
		{
			this->close();
			t2++;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 16)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\nС�ֵ���ɻ����ˣ��ǹ������ǲ������㣬����֮���͵͵�����ˣ�����ȥѰ������ֻ˵..."));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n��·���������һ�����ף�ֻ�Ƽ�������һ��һ�ϣ�ȴ˿����������˵��ʲô�����˰��Σ��Ż�����Щ��"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("����\n������˵ʲô��"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("���\n�ǹ��������Ӱɽ�ɻ�սʱ������ɱ�ˡ�"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n���������·��Ѿ������Լ���һ�㣬�Դ��������������ˡ���������˫���������߳�ҽ�ݡ�"));
			t++;
			break;
		}
		case 5:
		{
			extern int Sister_state;
			Sister_state = 0;
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

int Yiguan::OpenSY()
{
	Shenyi sy;
	sy.exec();
	return 0;
}
