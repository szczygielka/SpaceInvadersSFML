#ifndef POINTS_H
#define POINTS_H

#include "Text.h"
class Points :
	public Text
{
	int points;
public:
	Points();
	~Points();
	void Set(int points);
	void Add(int points);
	int Get();
};

#endif