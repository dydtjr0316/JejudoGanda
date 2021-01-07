#include "stdafx.h"

// 상태 패턴 
// https://blocked.tistory.com/344
// f11로 하나하나 따라가면서 보면 개꿀딱

// 유지보수와 가독성에 장점이있지만 State패턴을 이용하다 보면 class의 갯수가 늘어나기 때문에 서버에서
// 사용할때는 상황에 따라 사용

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
		printf("인형이 이미 바닥에 쓰러졌습니다 -_-; \n");
}

void KnockdownState::Reset()
{
	printf("인형을 다시 일으켜 세웁니다\n");
	punchDoll->setState(punchDoll->getNormalState());
}
void NormalState::Push()
{
	printf("인형을 손으로 쳐서 인형이 쓰러졌습니다\n");
	punchDoll->setState(punchDoll->getKnockdownState());
}

void NormalState::Reset()
{
	printf("인형이 이미 서있습니다\n");
}


int main()
{
	PunchDoll punchDoll;

	punchDoll.Push();
	punchDoll.Reset();
	punchDoll.Push();
	punchDoll.Push();

}

