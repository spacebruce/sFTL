#pragma once
#include "ardutils/Point2.h"
#include "ardutils/Rectangle.h"

using ByteRectangle = Ardutils::Rectangle<int8_t,int8_t>;
using BytePoint = Ardutils::Point2<uint8_t>;

enum class State : uint8_t
{
	menu,
	game,
	pause,
};

enum class Page : uint8_t
{
	ship,
	peeps,
	target,
	travel,
};

enum class Species : uint8_t
{
	human,
	martian,
};

enum class ShipType : uint8_t
{
	kestrel,
	ship1,
	ship2,
};

enum class RoomType : uint8_t
{
	empty = 0,
	bridge = 1,
	sickbay = 2, 
	weapons = 3,
	shield = 4,
	engine = 5,
};

