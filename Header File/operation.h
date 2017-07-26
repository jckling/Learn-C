#pragma once
#ifndef _OPERATION_H
#define _OPERATION_H

#include <math.h>
#include "player.h"

// 怪物移动
void ArmyMove(AllType *a);
void MoveArmy();

// 怪物攻击
void ArmyAttack();
BOOL Army_yMeet(AllType *a);

// 玩家攻击
BOOL yMeetArmy(AllType *a);
BOOL xMeetArmy(AllType *a);
void AttackArmy();

// 玩家大招
BOOL yMeetBig(AllType *a);
BOOL xMeetBig(AllType *a);
void BigAttack();
void Clearbehit();


#endif // !_OPERATION_H