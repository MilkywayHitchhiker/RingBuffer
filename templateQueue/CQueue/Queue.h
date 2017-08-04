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
		int Front;			//데이터 출력할 위치
		int Rear;			//데이터 입력할 위치

	public:
		Queue ()			//Queue 초기화
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

		bool DeQueue (T *pOut)		//데이터 출력
		{
			if ( (Front % MAX) == Rear )
			{
				return false;
			}

			*pOut = Que[Front];

			Front = (Front + 1) % MAX;

			return true;
		}
		bool EnQueue (const T *pIn)		//데이터 입력
		{
			if ( (Rear + 1) % MAX == Front )
			{
				return false;
			}

			Que[Rear] = *pIn;

			Rear = (Rear + 1) % MAX;

			return true;
		}
		bool Peek (T *pOut, int Num)			//데이터 보존 그리고 출력
		{
			if ( (Front + Num) % MAX == Rear )
			{
				return false;
			}

			*pOut = Que[(Front + Num) % MAX];

			return true;
		}
		int GetUseSize (void)		//현재 사용중인 Size
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
		int GetFreeSize (void)		//현재 사용 가능한 Size
		{
			return MAX - GetUseSize ();
		}
		
	};
}
