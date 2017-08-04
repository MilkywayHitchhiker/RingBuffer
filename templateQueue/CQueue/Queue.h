#pragma once
#include "stdafx.h"
#define QueMax 1000

/*
struct T
{
	int UnitNumber;
	time_t Createtime;
};
*/
namespace hiker
{
	template <T>
	class Queue
	{
	private:

		T *Que;
		int MAX;
		int Front;			//������ ����� ��ġ
		int Rear;			//������ �Է��� ��ġ

	public:
		Queue ()			//Queue �ʱ�ȭ
		{
			MAX = QueMax;
			Que = new T[MAX];
			Front = 0;
			Rear = 0;
		}
		Queue (int MAX)
		{
			Que = new T[MAX];
			Front = 0;
			Rear = 0;
		}
		~Queue ()
		{
			delete[]Que;
		}

		bool DeQueue (T *pOut)		//������ ���
		{
			if ( (Front % MAX) == Rear )
			{
				return false;
			}

			*pOut = Que[Front];

			Front = (Front + 1) % MAX;

			return true;
		}
		bool EnQueue (const T *pIn)		//������ �Է�
		{
			if ( (Rear + 1) % MAX == Front )
			{
				return false;
			}

			Que[Rear] = *pIn;

			Rear = (Rear + 1) % MAX;

			return true;
		}
		bool Peek (T *pOut, int Num)			//������ ���� �׸��� ���
		{
			if ( (Front + Num) % MAX == Rear )
			{
				return false;
			}

			*pOut = Que[(Front + Num) % MAX];

			return true;
		}
		int GetUseSize (void)		//���� ������� Size
		{
			if ( Front < Rear )
			{
				return Rear - Front;
			}
			else if ( Front > Rear )
			{
				return (MAX - Front) + Rear;
			}

			return 0;
		}
		int GetFreeSize (void)		//���� ��� ������ Size
		{
			return MAX - GetUseSize ();
		}
		
	};
}
