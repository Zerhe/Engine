#include "CollisionManager.h"

bool CollisionManager::Register(Entity2D* entity, int group)
{
	switch (group)
	{
	case 1:
		group01.push_front(entity);
		break;
	case 2:
		group02.push_front(entity);
	}
	return true;
}
bool CollisionManager::UnRegister(Entity2D* entity, int group)
{
	return true;
}
void CollisionManager::CheckCollision()
{
	for (iter01 = iterBeginGroup01; iter01 != iterEndGroup01; iter01++)
	{
		x1 = (*iter01)->_x;
		y1 = (*iter01)->_y;

		for (iter02 = iterBeginGroup02; iter02 != iterEndGroup02; iter02++)
		{
			x2 = (*iter02)->_x;
			y2 = (*iter02)->_y;

			if ((*iter01)->_collType == 0 && (*iter02)->_collType == 0)
			{
				width1 = (*iter01)->_collWidth;
				width2 = (*iter02)->_collWidth;
				height1 = (*iter01)->_collHeight;
				height2 = (*iter02)->_collHeight;

				if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (width2 - width1) + (height2 - height1))
				{
					(*iter01)->OnCollision((*iter02));
					(*iter02)->OnCollision((*iter01));
				}
			}
			if ((*iter01)->_collType == 1 && (*iter02)->_collType == 1)
			{
				r1 = (*iter01)->_r;
				r2 = (*iter02)->_r;

				if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r2 - r1))
				{
					(*iter01)->OnCollision((*iter02));
					(*iter02)->OnCollision((*iter01));
				}
			}

		}
	}
}