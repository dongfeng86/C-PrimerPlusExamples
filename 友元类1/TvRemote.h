/*
本工程主要使用了友元类。
在之前的学习中，仅仅是在类或者模板类中使用了友元函数，友元函数能够访问类中的所有成员。
但是，仅仅是某个函数能够访问类的内部成员还稍显不足。在本工程中，采用了友元类，即整个类是某个类的友元。实现这个
目标，仅仅需要在类中把友元类声明为friend即可，比如在Tv类当中声明：
friend class Remote;
即可以将Remote声明为Tv的友元类。
*/
#ifndef TVFM_H_
#define TVFM_H_

class Tv;             //前向声明（forward declaration）

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
	bool volup(Tv & t);                     //这些函数不能直接在类声明中定义，因为Tv的相关接口还没有声明，
	bool voldown(Tv & t);                   //因此，这些成员函数的内联方法在Tv类定义之后再行定义
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
	如果在Tv类中声明：
	friend class Remote;
	那么整个Remote类都是Tv类的友元。这没有必要，因为Remote绝大多数函数都使用Tv的公有接口，
	仅仅是set_chan函数需要访问Tv类的私有变量。因此，仅仅将该函数声明为友元。
	*/
	friend void Remote::set_chan(Tv & t, int c);    //当Tv类出现Remote的方法被声明为友元时，应将先看到Remote类对应方法的原型

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

/*内联函数的链接性是内部的，这意味着函数定义必须在使用函数的文件中。由于本内联函数
定义位于头文件中，因此在使用函数的文件中包含头文件可确保将定义放在正确的地方*/
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
