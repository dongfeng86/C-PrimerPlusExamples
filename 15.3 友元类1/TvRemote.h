/*
��������Ҫʹ������Ԫ�ࡣ
��֮ǰ��ѧϰ�У��������������ģ������ʹ������Ԫ��������Ԫ�����ܹ��������е����г�Ա��
���ǣ�������ĳ�������ܹ���������ڲ���Ա�����Բ��㡣�ڱ������У���������Ԫ�࣬����������ĳ�������Ԫ��ʵ�����
Ŀ�꣬������Ҫ�����а���Ԫ������Ϊfriend���ɣ�������Tv�൱��������
friend class Remote;
�����Խ�Remote����ΪTv����Ԫ�ࡣ
*/
#ifndef TVFM_H_
#define TVFM_H_

class Tv;             //ǰ��������forward declaration��

class Remote
{
public:
	enum State{kOff,kOn};
	enum{kMinVal,kMaxVal=20};
	enum{kAntena,kCable};
	enum{kTv,kDvd};
private:
	int iMode;
public:
	Remote(int m=kTv):iMode(m){ }
	bool volup(Tv & t);                     //��Щ��������ֱ�����������ж��壬��ΪTv����ؽӿڻ�û��������
	bool voldown(Tv & t);                   //��ˣ���Щ��Ա����������������Tv�ඨ��֮�����ж���
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void set_chan(Tv & t, int c);
};

class Tv
{
public:
	/*
	�����Tv����������
	friend class Remote;
	��ô����Remote�඼��Tv�����Ԫ����û�б�Ҫ����ΪRemote�������������ʹ��Tv�Ĺ��нӿڣ�
	������set_chan������Ҫ����Tv���˽�б�������ˣ��������ú�������Ϊ��Ԫ��
	*/
	friend void Remote::set_chan(Tv & t, int c);    //��Tv�����Remote�ķ���������Ϊ��Ԫʱ��Ӧ���ȿ���Remote���Ӧ������ԭ��

	enum State{kOff,kOn};
	enum {kMinVal,kMaxVal=20};
	enum {kAntenna,kCable};
	enum {kTv,kDvd};

	Tv(int s=kOff,int mc=125):iState(s),iVolume(5),iMaxchannel(mc),iChannel(2),iMode(kCable),iInput(kTv){ }
	void onoff() { iState = (kOn == iState) ? kOff : kOn; }
	bool ison() const { return kOn==iState; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { iMode = (iMode == kAntenna) ? kCable : kAntenna; }
	void set_input() { iInput = (kTv == iInput) ? kDvd : kTv; }
	void settings() const;
private:
	int iState;
	int iVolume;
	int iMaxchannel;
	int iChannel;
	int iMode;
	int iInput;
};

/*�������������������ڲ��ģ�����ζ�ź������������ʹ�ú������ļ��С����ڱ���������
����λ��ͷ�ļ��У������ʹ�ú������ļ��а���ͷ�ļ���ȷ�������������ȷ�ĵط�*/
inline bool Remote::volup(Tv & t)
{
	return t.volup();
}

inline bool Remote::voldown(Tv & t)
{
	return t.voldown();
}

inline void Remote::onoff(Tv & t)
{
	t.onoff();
}

inline void Remote::chanup(Tv & t)
{
	t.chanup();
}

inline void Remote::chandown(Tv & t)
{
	t.chandown();
}

inline void Remote::set_mode(Tv & t)
{
	t.set_mode();
}

inline void Remote::set_input(Tv & t)
{
	t.set_input();
}

inline void Remote::set_chan(Tv & t, int c)
{
	t.iChannel = c;
}


#endif
