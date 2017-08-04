#include "stdafx.h"
#include"Queue.h"


//데이터 출력
bool Queue::DeQueue (Unit *pOut)
{
	

}


//데이터 입력
bool Queue::EnQueue (const Unit *pIn)
{
	if ( (Rear + 1) % QueMax == Front )
	{
		return false;
	}

	Que[Rear] = *pIn;

	Rear = (Rear + 1) % QueMax;

	return true;

}


//데이터 보존 그리고 출력
bool Queue::Peek (Unit *pOut, int Num)
{
	if ( (Front + Num) % QueMax == Rear )
	{
		return false;
	}

	*pOut = Que[(Front + Num) % QueMax];

	return true;

}


//현재 사용중인 Size
int Queue::GetUseSize (void)
{
	if ( Front < Rear )
	{
		return Rear - Front;
	}
	else if ( Front > Rear )
	{
		return (QueMax - Front) + Rear;
	}

	return 0;

}


//현재 사용 가능한 Size
int Queue::GetFreeSize (void)
{
	return QueMax - GetUseSize ();
}
