#include "stdafx.h"
#include"Queue.h"


//������ ���
bool Queue::DeQueue (Unit *pOut)
{
	

}


//������ �Է�
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


//������ ���� �׸��� ���
bool Queue::Peek (Unit *pOut, int Num)
{
	if ( (Front + Num) % QueMax == Rear )
	{
		return false;
	}

	*pOut = Que[(Front + Num) % QueMax];

	return true;

}


//���� ������� Size
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


//���� ��� ������ Size
int Queue::GetFreeSize (void)
{
	return QueMax - GetUseSize ();
}
