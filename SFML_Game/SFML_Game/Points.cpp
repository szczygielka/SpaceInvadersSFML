#include "Points.h"


Points::Points() : Text(GameData::getInstance()->fontsManager.Get(GET_VARIABLE_NAME(pointsFont)), Int2Str(0),
	GameData::getInstance()->config.gamePointsSize, 
	GameData::getInstance()->config.gamePointsColor,
	GameData::getInstance()->config.gamePointsStyle,
	GameData::getInstance()->config.pointsPosition)
{
}

Points::~Points()
{
}

void Points::Set(int points)
{
	this->points = points;
	this->text.setString(Int2Str(this->points));
	this->Reposition();
}

void Points::Add(int points)
{
	this->points += points;
	this->text.setString(Int2Str(this->points));
	this->Reposition();
}

int Points::Get()
{
	return this->points;
}