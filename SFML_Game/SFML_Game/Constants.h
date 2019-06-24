#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <sstream>
#include <map>
#include <SFML/Graphics.hpp>
#include "ControlKeysEnum.h"


#define GET_VARIABLE_NAME(x) (#x) //przekazuje zmnienn¹ a zwraca nazwê zmiennej jako string 

static inline std::string Int2Str(int x)
{
	std::stringstream type;
	type << x;
	return type.str();
}

static inline  sf::Vector2f Str2Vector2f(std::string str)
{
	std::stringstream ss(str);
	float x, y;
	char delim;
	ss >> x >> delim >> y;
	return sf::Vector2f(x, y);
}

static inline  sf::Text::Style Str2TextStyle(std::string str)
{
	if (str.find("Bold") != std::string::npos)
	{
		return sf::Text::Style::Bold;
	}
	else if (str.find("Italic") != std::string::npos)
	{
		return sf::Text::Style::Italic;
	}
	else
	{
		return sf::Text::Style::Regular;

	}
}

static inline float Str2Float(std::string str)
{
	std::stringstream ss(str);
	float x;
	ss >> x;
	return x;
}

static inline int Str2Int(std::string str)
{
	std::stringstream ss(str);
	int x;
	ss >> x;
	return x;
}

static inline std::map<CONTROL_KEYS, sf::Keyboard::Key> Str2ControlKeyMap(std::string str)
{
	std::stringstream ss(str);
	int left, right, shoot;
	char delim;
	ss >> left >> delim >> right >> delim >> shoot;

	return std::map<CONTROL_KEYS, sf::Keyboard::Key>({
			{CONTROL_KEYS::LEFT,static_cast<sf::Keyboard::Key>(left)},
			{CONTROL_KEYS::RIGHT,static_cast<sf::Keyboard::Key>(right)},
			{CONTROL_KEYS::SHOOT,static_cast<sf::Keyboard::Key>(shoot)}
		});
}

static inline sf::Color Str2Color(std::string str)
{
	std::stringstream ss(str);
	int r, g, b;
	char delim;
	ss >> r >> delim >> g >> delim >> b;

	return sf::Color(r, g, b);
}



const std::string CONFIG_FILE_NAME = "assets/config.cfg";

#endif // CONSTANTS_H