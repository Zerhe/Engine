#include "CollisionManager.h"

bool CollisionManager::Register(GameObject* entity, int group)
{
	switch (group)
	{
	case 1:
		group01.push_front(entity);
		break;
	case 2:
		group02.push_front(entity);
		break;
	}
	return true;
}
bool CollisionManager::UnRegister(GameObject* entity, int group)
{
	switch (group)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	}
	return true;
	return true;
}
void CollisionManager::CheckCollision()
{
	for (iter01 = group01.begin(); iter01 != group01.end(); iter01++)
	{
		x1 = (*iter01)->transform.position->x;
		y1 = (*iter01)->transform.position->y;

		for (iter02 = group02.begin(); iter02 != group02.end(); iter02++)
		{
			x2 = (*iter02)->transform.position->x;
			y2 = (*iter02)->transform.position->y;

			sr01 = static_cast<SpriteRenderer*>((*iter01)->GetComponent("SpriteRenderer"))->GetSprite();
			sr02 = static_cast<SpriteRenderer*>((*iter02)->GetComponent("SpriteRenderer"))->GetSprite();

			if ( sr01->_collType == Square && sr02->_collType == Square)
			{
				width1 = sr01->_collWidth;
				width2 = sr02->_collWidth;
				height1 = sr01->_collHeight;
				height2 = sr02->_collHeight;

				if (abs(x2 - x1)  < (width2 + width1) / 2.0f && abs(y2 - y1) < (height2 + height1) / 2.0f)
				{
					Penetration();
					(*iter01)->OnCollision((*iter02));
					(*iter02)->OnCollision((*iter01));
				}
			}
			if (sr01->_collType == Circle && sr02->_collType == Circle)
			{
				r1 = sr01->_r;
				r2 = sr02->_r;

				if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r2 + r1) * (r2 + r1))
				{
					Penetration();
					(*iter01)->OnCollision((*iter02));
					(*iter02)->OnCollision((*iter01));
				}
			}

		}
	}
}
void CollisionManager::Penetration()
{
	if ((*iter02)->_inamovible)
	{
		if (x1 < x2)
			(*iter01)->transform.position->x = x2 - width1;
		else if (x1 > x2)
			(*iter01)->transform.position->x = x2 + width1;
	}
	else
	{
		if (x2 < x1)
			(*iter02)->transform.position->x = x1 - width2;
		else if (x2 > x1)
			(*iter02)->transform.position->x = x1 + width2;
	}
	//entidad->_mass
}