//���ĵ���Ҫ�Ƕ��ؼ̳л����ͷ�ļ�
#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker
{
private:
	std::string m_fullname;
	long m_lId;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker():m_fullname("no one"),m_lId(0){ }
	Worker(const std::string & s,long n)
		:m_fullname(s),m_lId(n){ }

	/*=0 ָ�����Ǵ��麯���������п��Զ���Ҳ���Բ�����;���ǣ��ڻ����н�
	����������Ϊ��ģ���һ�����������⣬����������������Ǵ���ģ�Ҳ���붨��*/
	virtual ~Worker() = 0;                
	virtual void Set() = 0;               //���麯����ע�⣬���˵����û�и�д���麯��������Ҳ���Ϊ������
	virtual void Show() const = 0;        //���麯��
};

class Waiter :virtual public Worker       //ע�⣬��������������
{
private:
	int m_iPanache;
protected:
	void Data() const;                    //������Ϊ�鷽���������������Զ�Ϊ�鷽��
	void Get();
public:
	Waiter():Worker(),m_iPanache(0){ }
	Waiter(const std::string & s,long n,int p=0)
		:Worker(s,n),m_iPanache(p){ }
	Waiter(const Worker & wk,int p=0)
		:Worker(wk),m_iPanache(p){ }
	void Set();
	void Show() const;
};

class Singer :virtual public Worker
{
protected:
	enum{other,alto,contralto,soprano,bass,baritone,tenor};
	enum {Vtypes=7};
	void Data() const;
	void Get();
private:
	static char * m_pv[Vtypes];
	int m_iVoice;
public:
	Singer():Worker(),m_iVoice(other){ }
	Singer(const std::string & s,long n,int v=other)
		:Worker(s,n),m_iVoice(v){ }
	Singer(const Worker & wk,int v=other)
		:Worker(wk),m_iVoice(v){ }
	void Set();
	void Show() const;
};

//�������Ƕ��ؼ̳�
//ע�⣬�������������public���͵ģ�����������η����ͻ���private����
class SingingWaiter :public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}

	/*ע�⣬���Ƕ��ؼ̳�һ��������÷���������Ϊ��ʱ����ֹ��Ϣͨ���м����Զ����ݸ����ࡣ�������湹�캯���Ķ��壬
	Waiter(s,n,p)��Singer(s,n,v)������û���Worker�����û��Worker(s,n)�������������û����Ĭ�Ϲ��캯�������д��
	��Worker(s,n)�������������Worker�Ĵ��ι��캯��*/
	SingingWaiter(const std::string & s,long n,int p=0,int v=other)
		:Worker(s,n),Waiter(s,n,p),Singer(s,n,v){ }
	SingingWaiter(const Worker & wk,int p=0,int v=other)
		:Worker(wk),Waiter(wk,p),Singer(wk,v){ }          //���㲻���ã�Ҳ��Ҫ��Waiter��SSingingWaiter����дȫ
	SingingWaiter(const Waiter & wt,int v=other)
		:Worker(wt),Waiter(wt),Singer(wt,v){ }            //����һ�������÷��������๹�츸��
	SingingWaiter(const Singer & wt,int p=0)
		:Worker(wt),Waiter(wt,p),Singer(wt) { }           //���̫���ˣ������๹�츸�࣬���������๹��ͬ�����������
	void Set();
	void Show() const;
};

#endif