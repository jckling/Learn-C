#include "operation.h"

// 怪物移动
void ArmyMove(AllType *a) {

	// x坐标移动
	if (a->type == NORMAL) {
		if (a->d == LEFT) {
			if (a->x - a->step > 0)
				a->x -= a->step;
			else {
				a->d = RIGHT;
				a->x += a->step;
			}
		}
		else {
			if (a->x + a->step < Width - a->width)
				a->x += a->step;
			else {
				a->d = LEFT;
				a->x -= a->step;
			}
		}
	}
	else if (a->type == FAST) {
		if (a->d == LEFT) {
			if (a->x - a->multi * a->step > 0)
				a->x -= a->multi * a->step;
			else {
				a->d = RIGHT;
				a->x += a->multi*a->step;
			}
		}
		else {
			if (a->x + a->multi * a->step < Width - a->width)
				a->x += a->multi * a->step;
			else {
				a->d = LEFT;
				a->x -= a->multi * a->step;
			}
		}
	}
	else if (a->type == FALL) {
		if ((a->x - player.x) > Player_Width / 3)
			a->x -= a->step / 2;
		else if ((player.x - a->x) > Player_Width / 3)
			a->x += a->step / 2;
		// y坐标移动
		if (a->d == DOWN) {
			if (a->y + a->multi * a->step < Height - a->height)
				a->y += a->multi * a->step;
			else {
				a->y -= a->multi * a->step;
				a->d = UP;
			}
		}
		else {
			if (a->y - a->multi * a->step > Border)
				a->y -= a->multi * a->step;
			else {
				a->y += a->multi * a->step;
				a->d = DOWN;
			}
		}
	}

	// y坐标移动
	if (a->type == NORMAL || a->type == FAST) {
		if (a->y > player.y) {
			if ((a->y - player.y) > Player_Height / 3)
				a->y -= a->step / 2;
		}
		else {
			if ((player.y - a->y) > a->height / 4)
				a->y += a->step / 2;
		}
	}
}
void MoveArmy() {

	int i;
	AllType *a;

	for (i = 0; i < ArmyNum(); i++) {
		a = ListGetAt(Army, i);
		ArmyMove(a);
	}
}

// 怪物攻击
void ArmyAttack() {

	int i;
	AllType *a;

	for (i = 0; i < ArmyNum(); i++) {
		a = ListGetAt(Army, i);
		if (Army_yMeet(a)) {
			if (a->d == LEFT) {
				if (player.x < a->x) {
					if (a->x - player.x < Player_Width - 3)
						player.HP -= a->hurt;
				}
				else {
					if (player.d == LEFT)
						if (player.x - a->x < a->width - 2)
							player.HP -= a->hurt;
				}
			}
			else {
				if (player.x > a->x) {
					if (player.x - a->x < a->width - 2)
						player.HP -= a->hurt;
				}
				else {
					if (player.d == RIGHT)
						if (a->x - player.x < Player_Width - 3)
							player.HP -= a->hurt;
				}
			}
		}
	}
}
BOOL Army_yMeet(AllType *a) {
	if (a->y > player.y) {
		if ((a->y - player.y) < Player_Height - 3)
			return TRUE;
		return FALSE;
	}
	else {
		if ((player.y - a->y) < a->height - 2)
			return TRUE;
		return FALSE;
	}
}

// 玩家攻击
BOOL yMeetArmy(AllType *a) {
	if (a->y > player.y) {
		if ((a->y - player.y) < AttackDistance)
			return TRUE;
		return FALSE;
	}
	else {
		if (player.y - a->y < a->height / 2) {
			if ((a->height - (player.y - a->y)) > AttackDistance)
				return TRUE;
			return FALSE;
		}
	}
}
BOOL xMeetArmy(AllType *a) {
	if (player.d == LEFT) {
		if (((player.x - a->x) < Player_Width + a->width - 5) && (player.x - a->x) >= 0)
			return TRUE;
		return FALSE;
	}
	else {
		if ((a->x - player.x) < (Player_Width + a->width - 5) && (a->x - player.x) >= 0)
			return TRUE;
		return FALSE;
	}
}
void AttackArmy()
{
	// 按照方向寻找最近的敌人
	int enemy = 0;
	int i, dis;
	AllType *a;

	dis = 1111;

	for (i = 0; i < ArmyNum(); i++) {
		a = ListGetAt(Army, i);
		if (RIGHT == player.d && a->x >= player.x) {
			if (a->x - player.x < dis) {
				dis = a->x - player.x;
				enemy = i;
			}
		}
		else if (LEFT == player.d && player.x >= a->x) {
			if (player.x - a->x < dis) {
				dis = player.x - a->x;
				enemy = i;
			}
		}
	}

	if (dis < 1111) {
		a = ListGetAt(Army, enemy);
		// 判断攻击是否成功 
		if (TRUE == xMeetArmy(a) && TRUE == yMeetArmy(a)) {
			a->HP -= player.hurt;
			if (player.fire <= 5)
				player.fire += player.hurt / 2;
			if (a->HP <= 0) {
				if (enemy == 0 && ArmyNum() == 1)
					init();
				else
					a = ListDeleteAt(Army, enemy);
			}
		}
	}
}

// 玩家大招
BOOL yMeetBig(AllType *a) {
	if (bigy > a->y) {
		if ((a->y - bigy) < BigDistance)
			return TRUE;
		return FALSE;
	}
	else {
		if ((a->height - (bigy - a->y)) > BigDistance)
			return TRUE;
		return FALSE;
	}
}
BOOL xMeetBig(AllType *a) {
	if ((bigx - a->x) <  a->width && (bigx - a->x) >= 0)
		return TRUE;
	else if ((a->x - bigx) < Big_Width && (a->x - bigx) >= 0 && a->x < Width - a->width)
		return TRUE;
	return FALSE;
}
void BigAttack() {

	int i;
	AllType *a;

	for (i = 0; i < ArmyNum(); i++) {
		a = ListGetAt(Army, i);
		if (yMeetBig(a) && xMeetBig(a) && FALSE == a->behit) {
			a->behit = TRUE;
			a->HP -= 1.1;
			player.fire += 0.1;
			if (a->HP <= 0) {
				if (ArmyNum() == 1)
					init();
				else
					a = ListDeleteAt(Army, i);
			}
		}
	}
}
void Clearbehit() {

	int i;
	AllType *a;
	
	for (i = 0; i < ArmyNum(); i++) {
		a = ListGetAt(Army, i);
		a->behit = FALSE;
	}
}