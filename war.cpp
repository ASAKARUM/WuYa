#include "war.h"
#include <QTime>
#include <QDebug>

extern int Attack;
extern int Defense;
extern int Blood;
extern int Pneuma;
extern int Schedule;
extern bool Drug_03;
extern bool qinglongjian;
extern bool zhuqueguan;
extern bool xuanwuzhongjia;
extern bool baihuxue;
extern int Blood_max;
extern int Pneuma_max;
extern bool Map_xw;
extern bool Map_bh;
extern bool Map_zq;
extern bool Map_ql;
extern bool END;

int bosshuifu;
int bossnowhp;
int m_Attack;
int m_Defense;
int BossHP;
int BossMaxHP;
int BossAttack;
int m_BossAttack;
int BossDefense;
int m_BossDefense;
int atkup = 0;
int Hpup = 0;
int bossdfsup = 0;
int bossatkup = 0;
int dfsdown = 0;
int atkdown = 0;
int Hpdown = 0;
int heroatk;
int bossatk;

war::war(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btnpugong, SIGNAL(clicked()),
		this, SLOT(onbtnPugong()));
	connect(ui.btnzhanyi, SIGNAL(clicked()),
		this, SLOT(onbtnZhanyi()));
	connect(ui.btnmingxiang, SIGNAL(clicked()),
		this, SLOT(onbtnMingxiang()));
	connect(ui.btncangshan, SIGNAL(clicked()),
		this, SLOT(onbtnCangshan()));
	connect(ui.btnzhengyang, SIGNAL(clicked()),
		this, SLOT(onbtnZhengyang()));
	connect(ui.btnqinglong, SIGNAL(clicked()),
		this, SLOT(onbtnQinglong()));

	

	if (Schedule == 10)
	{
		BossAttack = 800;
		BossDefense = 1500;
		BossHP = 30000;
		BossMaxHP = 30000;
		m_BossAttack = 800;
		m_BossDefense = 1500;
		ui.bossname->setText(QString::fromLocal8Bit("  ����"));
		ui.baihu->hide();
		ui.zhuque->hide();
		ui.qinglong->hide();
		ui.boss->hide();
	}
	if (Schedule == 11)
	{
		BossAttack = 1500;
		BossDefense = 1000;
		BossHP = 20000;
		BossMaxHP = 20000;
		m_BossAttack = 1500;
		m_BossDefense = 1000;
		ui.bossname->setText(QString::fromLocal8Bit("  �׻�"));
		ui.xuanwu->hide();
		ui.zhuque->hide();
		ui.qinglong->hide();
		ui.boss->hide();
	}
	if (Schedule == 12)
	{
		BossAttack = 1200;
		BossDefense = 1200;
		BossHP = 10000;
		BossMaxHP = 10000;
		m_BossAttack = 1200;
		m_BossDefense = 1200;
		ui.bossname->setText(QString::fromLocal8Bit("  ��ȸ"));
		ui.baihu->hide();
		ui.xuanwu->hide();
		ui.qinglong->hide();
		ui.boss->hide();
	}
	if (Schedule == 13)
	{
		BossAttack = 1500;
		BossDefense = 800;
		BossHP = 25000;
		BossMaxHP = 25000;
		m_BossAttack = 1500;
		m_BossDefense = 800;
		ui.bossname->setText(QString::fromLocal8Bit("  ����"));
		ui.baihu->hide();
		ui.zhuque->hide();
		ui.xuanwu->hide();
		ui.boss->hide();
	}
	if (Schedule == 15)  //Boss
	{
		BossAttack = 2000;
		BossDefense = 1000;
		BossHP = 30000;
		BossMaxHP = 30000;
		m_BossAttack = 2000;
		m_BossDefense = 1000;
		ui.bossname->setText(QString::fromLocal8Bit("  ����"));
		ui.baihu->hide();
		ui.zhuque->hide();
		ui.qinglong->hide();
		ui.xuanwu->hide();
	}
	if (Schedule <= 13)
	{
		ui.btnqinglong->hide();
	}

	this->state();
}



void war::mousePressEvent(QMouseEvent *event)
{
	if (win)
	{
		accept();
	}
	if (lose)
	{
		reject();
	}
	return;
}

void war::winvalue()
{
	if (Blood > 0 && BossHP <= 0)
	{
		win = true;
		if (Schedule == 10)
		{
			xuanwuzhongjia = 1;
			Map_bh = true;
			ui.warBrowser->append(QString::fromLocal8Bit("ս��ʤ���������������ؼ׺Ͱ׻�Ѩ��ͼ��"));
		}
		if (Schedule == 11)
		{
			baihuxue = 1;
			Map_zq = true;
			ui.warBrowser->append(QString::fromLocal8Bit("ս��ʤ���������˰׻�ѥ����ȸ����ͼ��"));
		}
		if (Schedule == 12)
		{
			zhuqueguan = 1;
			Map_ql = true;
			ui.warBrowser->append(QString::fromLocal8Bit("ս��ʤ������������ȸ�ں�����̶��ͼ��"));
		}
		if (Schedule == 13)
		{
			qinglongjian = 1;
			Drug_03 = 1;
			ui.warBrowser->append(QString::fromLocal8Bit("ս��ʤ�����������������������ۣ�"));
		}
		if (Schedule == 15)
		{
			ui.warBrowser->append(QString::fromLocal8Bit("ս��ʤ������ɱ�������档"));
		}
		Schedule++;
		ui.btnpugong->setEnabled(false);
		ui.btnzhanyi->setEnabled(false);
		ui.btnmingxiang->setEnabled(false);
		ui.btncangshan->setEnabled(false);
		ui.btnzhengyang->setEnabled(false);
		ui.btnqinglong->setEnabled(false);
	}
}



void war::buffvalue()
{
	if (atkup==0)
	{
		m_Attack = Attack;
	}
	if (atkdown==0)
	{
		m_Attack = Attack;
	}
	if (dfsdown==0)
	{
		m_Defense = Defense;
	}
	if (bossdfsup==0)
	{
		m_BossDefense = BossDefense;
	}
	if (bossatkup==0)
	{
		m_BossAttack = BossAttack;
	}
	if (Hpup)
	{
		int huifu = Blood_max/10;
		int hpnow = Blood + huifu;
		if (hpnow >= Blood_max)
		{
			Blood = Blood_max;
		}
		else Blood = hpnow;
		ui.warBrowser->append(QString::fromLocal8Bit("���Ѫ�������ظ���... ..."));
	}
	if (Hpdown)
	{
		int diaoxue = Blood_max / 10;
		Blood -= diaoxue;
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
	}
}



void war::disbuff()
{
	if (atkup)
	{
		atkup--;
	}
	if (Hpup)
	{
		Hpup--;
	}
	if (atkdown)
	{
		atkdown--;
	}
	if (dfsdown)
	{
		dfsdown--;
	}
	if (bossdfsup)
	{
		bossdfsup--;
	}
	if (bossatkup)
	{
		bossatkup--;
	}
}



void war::bossjineng()
{
	QTime t = QTime::currentTime();
    qsrand(t.msec() + t.second() * 1000);
	int i = qrand() % 5;
	if (Schedule==10)    //����
	{ 
		switch (i)
		{
		case 0:
			bossatk=BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("����ҧ�����㣬���ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		case 1:
			m_BossDefense = BossDefense * 2;
			bossdfsup = 2;
			ui.warBrowser->append(QString::fromLocal8Bit("�������ع������ķ�����ʱ����ˡ�"));
			break;
		case 2:
			ui.warBrowser->append(QString::fromLocal8Bit("����ʲô��û�����ƺ��ڹ۲��㡣"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("�������βɨ�����㡣���ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		}
	}

	if (Schedule == 11)   //�׻�
	{
		switch (i)
		{
		case 0:
			m_Defense -= 250;
			dfsdown = 3;
			ui.warBrowser->append(QString::fromLocal8Bit("�׻�����һ������ķ�����ʱ�½��ˡ�"));
			break;
		case 1:
			bossatk = BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("�׻������������������ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		case 2:
			bossatk = m_BossAttack*1.5-m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("�׻������ݻ��������Ƥ�������ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("�׻�����צ�������㡣���ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		}
	}

	if (Schedule == 12)   //��ȸ
	{
		switch (i)
		{
		case 0:
			m_Defense = Defense*1.5;
			bossdfsup = 2;
			ui.warBrowser->append(QString::fromLocal8Bit("��ȸ�ɵ����У����ܵ����˺���ʱ�½��ˡ�"));
			break;
		case 1:
			bossatk = BossAttack * 2;
			ui.warBrowser->append(QString::fromLocal8Bit("��ȸ����Ļ����������㣬���ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		case 2:
			bosshuifu = BossMaxHP / 10;
			bossnowhp = BossHP + bosshuifu;
			if (bossnowhp>=BossMaxHP)
			{
				BossHP = BossMaxHP;
			}
			else BossHP = bossnowhp;
			ui.warBrowser->append(QString::fromLocal8Bit("��ȸ�ڿ������������ظ��˲���Ѫ����"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("��ȸ�ļ���������㡣���ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		}
	}

	if (Schedule == 13)   //����
	{
		switch (i)
		{
		case 0:
			bossatk = m_BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("��β��ɨ�������㡣���ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		case 1:
			m_BossAttack = BossAttack*1.5;
			bossatkup = 3;
			ui.warBrowser->append(QString::fromLocal8Bit("������ŭ����������������������˺���ʱ����ˣ�"));
			break;
		case 2:
			m_BossDefense = BossDefense * 3;
			bossdfsup = 2;
			ui.warBrowser->append(QString::fromLocal8Bit("���������������ƺ��ڿ��ţ����ķ�����ʱ����ˡ�"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("�������㸩����������ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		}
	}

	if (Schedule == 15)   //����
	{
		switch (i)
		{
		case 0:
			bossatk = m_BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("�����ͷ���ڤ�񹦡����ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		case 1:
			Blood -= 2000;
			Hpdown = 3;
			ui.warBrowser->append(QString::fromLocal8Bit("����ʹ��һ��������צ�����ж��ˡ�"));
			break;
		case 2:
			if (Pneuma>=Pneuma_max/5)
			{
				Pneuma -= Pneuma_max / 5;
				BossHP += BossMaxHP / 10;
				if (BossHP>=BossMaxHP)
				{
					BossHP = BossMaxHP;
				}
				this->state();
			}
			else
			{
				int absorb = Pneuma;
				Pneuma = 0;
				BossHP += (BossMaxHP / 10) * (absorb / Pneuma_max * 5);
				if (BossHP >= BossMaxHP)
				{
					BossHP = BossMaxHP;
				}
				this->state();
			}
			ui.warBrowser->append(QString::fromLocal8Bit("���淢���˶�ת���ơ�"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("�����˹����㷢�����������ܵ���") + QString::number(bossatk) + QString::fromLocal8Bit("���˺���"));
			break;
		}
	}
}



void war::losevalue()
{
	if (Blood <= 0)
	{
		lose = true;
		ui.warBrowser->append(QString::fromLocal8Bit("�㵹���ˡ�"));
		END = true;
		ui.btnpugong->setEnabled(false);
		ui.btnzhanyi->setEnabled(false);
		ui.btnmingxiang->setEnabled(false);
		ui.btncangshan->setEnabled(false);
		ui.btnzhengyang->setEnabled(false);
		ui.btnqinglong->setEnabled(false);
	}
}



void war::state()
{
	ui.hp->setText(QString::number(Blood));
	ui.maxhp->setText(QString::number(Blood_max));
	ui.sp->setText(QString::number(Pneuma));
	ui.maxsp->setText(QString::number(Pneuma_max));
	ui.bossstate->setText(QString::number(BossHP));
}



void war::onbtnPugong()
{
	buffvalue();
	QTime T = QTime::currentTime();
	qsrand(T.msec() + T.second() * 1000);
	int j = qrand() % 10;
	heroatk = m_Attack - m_BossDefense;
	if (j == 0)
	{
		heroatk = 2*m_Attack-m_BossDefense;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("����һ������Ե��������") + QString::number(heroatk) + QString::fromLocal8Bit("���˺���"));
	}
	else
	{
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("���ὣ��ȥ����Ե��������") + QString::number(heroatk) + QString::fromLocal8Bit("���˺���"));
	}
	int sphuifu = Pneuma_max / 10;
	int spnow = Pneuma + sphuifu;
	if (spnow>Pneuma_max)
	{
		Pneuma = Pneuma_max;
	}
	else Pneuma = spnow;
	this->state();
	this->winvalue();
	if (win)
	{
		this->state();
		return;
	}
	this->bossjineng();
	this->state();
	this->losevalue();
	if (lose)
	{
		this->state();
		return;
	}
	this->disbuff();
}



void war::onbtnZhanyi()
{
	if (Pneuma>=200)
	{
		Pneuma -= 200;
	    this->buffvalue();
	    m_Attack = Attack*1.2;
	    atkup = 3;
	    ui.warBrowser->append(QString::fromLocal8Bit("�����ƴ�������������ʱ�����ˡ�"));
		this->state();
		this->bossjineng();
	    this->state();
	    this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
	    this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("����������㣬����ʩ��ʧ�ܡ�"));
	}
}



void war::onbtnMingxiang()
{
	if (Pneuma>=400)
	{
		Pneuma -= 400;
        this->buffvalue();
		int hphuifu = Blood_max / 5;
		int hpnow = Blood + hphuifu;
		if (hpnow>=Blood_max)
		{
			Blood = Blood_max;
		}
		else Blood = hpnow;
		Hpup = 3;
	    ui.warBrowser->append(QString::fromLocal8Bit("�����ڤ��״̬�����Ѫ���ظ��ˡ�"));
		this->state();
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("����������㣬����ʩ��ʧ�ܡ�"));
	}
}



void war::onbtnCangshan()
{
	if (Pneuma >= 400)
	{
		Pneuma -= 400;
		this->buffvalue();
		heroatk = m_Attack * 2-m_BossDefense;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("��ʹ��һ�ײ�ɽ�������Ե��������") + QString::number(heroatk) + QString::fromLocal8Bit("���˺���"));
		this->state();
		this->winvalue();
		if (win)
		{
			this->state();
			return;
		}
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("����������㣬����ʩ��ʧ�ܡ�"));
	}
}



void war::onbtnZhengyang()
{
	if (Pneuma >= 800)
	{
		Pneuma -= 800;
		this->buffvalue();
		heroatk = m_Attack * 3;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("��ʹ��һ�������������Ե��������") + QString::number(heroatk) + QString::fromLocal8Bit("���˺���"));
		this->state();
		this->winvalue();
		if (win)
		{
			this->state();
			return;
		}
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("����������㣬����ʩ��ʧ�ܡ�"));
	}
}



void war::onbtnQinglong()
{
	if (Pneuma >= Pneuma_max/2&&Blood<=Blood_max/4)
	{
		Pneuma =0;
		this->buffvalue();
		heroatk = m_Attack * 5;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("��ƴ��ȫ��ʹ�������������Ե��������") + QString::number(heroatk) + QString::fromLocal8Bit("���˺���"));
		this->state();
		this->winvalue();
		if (win)
		{
			this->state();
			return;
		}
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("��δ���ʩ����������������50%��Ѫ������25%��������ʩ��ʧ�ܡ�"));
	}
}

war::~war()
{
}
