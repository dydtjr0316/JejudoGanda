#include "stdafx.h"

// ���� ���� 
// https://blocked.tistory.com/344
// f11�� �ϳ��ϳ� ���󰡸鼭 ���� ���ܵ�

// ���������� �������� ������������ State������ �̿��ϴ� ���� class�� ������ �þ�� ������ ��������
// ����Ҷ��� ��Ȳ�� ���� ���

class KnockdownState;
class NormalState;

class State
{
public:
	    virtual void Push() = 0;
	    virtual void Reset() = 0;
	};

class PunchDoll : public State
{
private:
	    KnockdownState * knockdownState;
	    NormalState * normalState;

	    State * state;

public:
	    PunchDoll();

		void setState(State* state) {
			this->state = state;
		};
		KnockdownState* getKnockdownState() {
			return knockdownState;
		};
		NormalState* getNormalState() {
			return normalState;
		};

		void Push() { state->Push(); }
		void Reset() { state->Reset(); }
	};

class KnockdownState : public State
{
private:
	    PunchDoll * punchDoll;

public:
	    KnockdownState(PunchDoll * punchDoll) : punchDoll(punchDoll) { };

		    void Push();
	    void Reset();
	};

class NormalState : public State
{
private:
    PunchDoll * punchDoll;

public:
	    NormalState(PunchDoll * punchDoll) : punchDoll(punchDoll) { };

	    void Push();
	    void Reset();
	};

PunchDoll::PunchDoll()
{
	
	knockdownState = new KnockdownState(this);
	
	normalState = new NormalState(this);
	
	state = normalState;
	
}

void KnockdownState::Push()
{
		printf("������ �̹� �ٴڿ� ���������ϴ� -_-; \n");
}

void KnockdownState::Reset()
{
	printf("������ �ٽ� ������ ����ϴ�\n");
	punchDoll->setState(punchDoll->getNormalState());
}
void NormalState::Push()
{
	printf("������ ������ �ļ� ������ ���������ϴ�\n");
	punchDoll->setState(punchDoll->getKnockdownState());
}

void NormalState::Reset()
{
	printf("������ �̹� ���ֽ��ϴ�\n");
}


int main()
{
	PunchDoll punchDoll;

	punchDoll.Push();
	punchDoll.Reset();
	punchDoll.Push();
	punchDoll.Push();

}

