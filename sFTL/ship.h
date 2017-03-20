#pragma once
#include "types.h"
#include "system.h"

struct Rectangle : public Rect
{
public:
	set(const uint8_t x,const uint8_t y,const uint8_t width,const uint8_t height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
};

class ShipRoom
{
public:
	int8_t hp = 100;
	uint8_t functional = 1;
	Rectangle shape;
	uint8_t crew;

	void update()
	{
		functional = (hp>=20);
	}
};

class Ship
{
private:
	ShipType type;
	ShipRoom rooms[10];

	int16_t shieldMax = 100;
	int16_t shield = 100;
public:
	System *ab;

	uint8_t roomNum = 0;
	Ship();
	void setType(ShipType type);

	void step();
	void draw(int8_t selected);

	uint8_t roomFromPoint(Point pos);
};

Ship::Ship()
{
};

void Ship::step()
{
	for(uint8_t r=0; r<roomNum; ++r)
	{
		rooms[r].update();
	}
	if(shield < shieldMax)
	{
		shield += rooms[2].functional;
	}
}

void Ship::setType(ShipType type)
{
	this->type = type;
	roomNum = 7;

	rooms[0].shape.set(80,16,16,24);	//Bridge
	rooms[1].shape.set(64,16,16,24);	//Medbay
	rooms[2].shape.set(32,16,32,12);	//Shield
	rooms[3].shape.set(32,28,32,12);	//Weapons
	rooms[4].shape.set(16,16,16,24);	//Engine
	rooms[5].shape.set(0,40,48,16);		//Right Strut
	rooms[6].shape.set(0,0,48,16);		//Left Strut
};

ShipRoom Ship::roomFromPoint(Point pos)
{
	for(uint8_t i=0; i<roomNum; ++i)
	{
		Rectangle shape = rooms[i].shape;
		if(ab->collide(pos,shape))
			return room[i];
	}
}

void Ship::draw(int8_t selected)
{
	for(uint8_t i=0; i<roomNum; ++i)
	{
		Rectangle shape = rooms[i].shape;
		ab->drawRect(shape.x,shape.y,shape.width,shape.height,1);

		if(selected==i)
		{
			ab->drawRect(shape.x+2,shape.y+2,shape.width-4,shape.height-4,1);
		}
	}
};