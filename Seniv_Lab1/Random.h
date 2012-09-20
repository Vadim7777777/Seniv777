#pragma once

#include <time.h>
#include <vector>

class Random
{
protected:
	int _x, _a, _c, _m;

public:

	Random(int x = 0, int a = 0, int c = 0, int m = 0):
	  _x(x), _a(a), _c(c), _m(m) {}

	  void Randomize()
	  {
		  _x = time(0);
	  }

	  int Next()
	  {
		  return (_x = (_a * _x + _c) % _m);
	  }

	  int GetM()
	  {
		  return _m;
	  }

};

class RandomPeriodCalculator: Random
{
private:
	Random *_random;
	int *_sameElems;

public:

	RandomPeriodCalculator(Random *random)
	{
		_sameElems = new int[random->GetM() * 4];
		SetRandom(random);
	}

	__forceinline void SetRandom(Random *random)
	{
		_random = random;
	}

	int GetPeriod(int *periodVals)
	{
		_sameElems[0] = _random->Next();

		int len;
		int i = 0;
		int foundPeriod = 0;
		int total = 0;

		while (!foundPeriod)
		{
			do 
			{
				_sameElems[++total] = _random->Next();
			} while (_sameElems[0] != _sameElems[total]);

			len = total;
			i = 0;
			while (i < len)
			{
				if (_sameElems[i] != _sameElems[total])
				{
					break;
				}

				_sameElems[++total] = _random->Next();
				i++;
			}
			if (i == len)
			{
				foundPeriod = 1;
				for (int i = 0; i < len; i++)
					periodVals[i] = _sameElems[i];
			}
		}

		return len;
	}

};

