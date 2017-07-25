#include "level.h"

BOOL level1 = FALSE;
BOOL level2 = FALSE;
BOOL level3 = FALSE;
BOOL level4 = FALSE;
BOOL level5 = FALSE;
BOOL level6 = FALSE;

BOOL wave1 = TRUE;
BOOL wave2 = FALSE;
BOOL wave3 = FALSE;

BOOL next = FALSE;

int first = 0;
int second = 0;
int third = 0;
int counter = 0;

// 随机间隔距离
void DistanceSuit() {

	if (!level1)
		distance = rand() % 100 + 161;
	else if (!level2)
		distance = rand() % 100 + 142;
	else if (!level3)
		distance = rand() % 100 + 133;
	else if (!level4)
		distance = rand() % 100 + 161;
	else if (!level5)
		distance = rand() % 100 + 142;
	else if (!level6)
		distance = rand() % 100 + 122;
}
// 关卡设置
void CreateArmy_level1() {

	int *num;
	AllType *a, *pre;

	DistanceSuit();

	if (FALSE == level1) {
		if ((wave1 && counter != level1_1) || (wave2 && counter != level1_2 + level1_1)) {
			pre = ListGetAt(Army, ArmyNum() - 1);
			if (NULL == pre || pre->x < Width - distance) {
				a = malloc(sizeof(AllType));
				Z_Create(a);
				num = malloc(sizeof(int));
				*num = 0;
				ListPushBack(Army, a);
				ListPushBack(Army_PicNum, num);

				counter++;
			}
		}
		if (level1_1 == counter && 0 == ArmyNum()) {
			wave1 = FALSE;
			wave2 = TRUE;
		}
		if (level1_1 + level1_2 == counter && 0 == ArmyNum()) {
			counter = 0;
			wave2 = FALSE;
			wave1 = TRUE;
			level1 = TRUE;
			next = TRUE;
		}
	}
}
void CreateArmy_level2() {

	int *num;
	AllType *a, *pre;

	DistanceSuit();

	if (FALSE == level2) {
		if ((wave1 && counter != level2_1) || (wave2 && counter != level2_2 + level2_1)
			|| (wave3 && counter != level2_1 + level2_2 + level2_3)) {
			pre = ListGetAt(Army, ArmyNum() - 1);
			if (NULL == pre || pre->x < Width - distance) {
				a = malloc(sizeof(AllType));
				if (wave3)
					distance % 2 == 0 ? P_Create(a) : Z_Create(a);
				else
					P_Create(a);
				num = malloc(sizeof(int));
				*num = 0;
				ListPushBack(Army, a);
				ListPushBack(Army_PicNum, num);

				counter++;
			}
		}

		if (level2_1 == counter && 0 == ArmyNum()) {
			wave1 = FALSE;
			wave2 = TRUE;
		}

		if (level2_1 + level2_2 == counter && 0 == ArmyNum()) {
			wave2 = FALSE;
			wave3 = TRUE;
		}

		if (level2_1 + level2_2 + level2_3 == counter && 0 == ArmyNum()) {
			counter = 0;
			wave3 = FALSE;
			wave1 = TRUE;
			level2 = TRUE;
			next = TRUE;
		}
	}
}
void CreateArmy_level3() {

	int *num;
	AllType *a, *pre;
	
	DistanceSuit();

	if (FALSE == level3) {
		if (0 == ArmyNum()) {
			a = malloc(sizeof(AllType));
			B1_Create(a);
			num = malloc(sizeof(int));
			*num = 0;
			ListPushBack(Army, a);
			ListPushBack(Army_PicNum, num);
		}

		pre = ListGetAt(Army, ArmyNum() - 1);
		if ((1 == ArmyNum() || pre->x < Width - distance) && 8 >= ArmyNum()) {
			a = malloc(sizeof(AllType));
			if (0 == distance % 2)
				Z_Create(a);
			else
				P_Create(a);
			num = malloc(sizeof(int));
			*num = 0;
			ListPushBack(Army, a);
			ListPushBack(Army_PicNum, num);
		}

		pre = ListGetAt(Army, 0);
		if (BOSS1 != pre->name) {
			level3 = TRUE;
			next = TRUE;
			init();
		}
	}
}

void CreateArmy_level4() {

	int *num;
	AllType *a, *pre;

	DistanceSuit();

	if (FALSE == level4) {
		if ((wave1 && counter != level4_1) || (wave2 && counter != level4_2 + level4_1)) {
			pre = ListGetAt(Army, ArmyNum() - 1);
			if (NULL == pre || pre->x < Width - distance) {
				a = malloc(sizeof(AllType));
				M_Create(a);
				num = malloc(sizeof(int));
				*num = 0;
				ListPushBack(Army, a);
				ListPushBack(Army_PicNum, num);

				counter++;
			}
		}

		if (level4_1 == counter && 0 == ArmyNum()) {
			wave1 = FALSE;
			wave2 = TRUE;
		}

		if (level4_1 + level4_2 == counter && 0 == ArmyNum()) {
			counter = 0;
			wave2 = FALSE;
			wave1 = TRUE;
			level4 = TRUE;
			next = TRUE;
		}
	}
}
void CreateArmy_level5() {

	int *num;
	AllType *a, *pre;

	DistanceSuit();

	if (FALSE == level5) {
		if ((wave1 && counter != level5_1) || (wave2 && counter != level5_2 + level5_1)
			|| (wave3 && counter != level5_1 + level5_2 + level5_3)) {
			pre = ListGetAt(Army, ArmyNum() - 1);
			if (NULL == pre || pre->x < Width - distance) {
				a = malloc(sizeof(AllType));
				if (wave3)
					distance % 2 == 0 ? MR_Create(a) : M_Create(a);
				else
					MR_Create(a);
				num = malloc(sizeof(int));
				*num = 0;
				ListPushBack(Army, a);
				ListPushBack(Army_PicNum, num);

				counter++;
			}
		}

		if (level5_1 == counter && 0 == ArmyNum()) {
			wave1 = FALSE;
			wave2 = TRUE;
		}

		if (level5_1 + level5_2 == counter && 0 == ArmyNum()) {
			wave2 = FALSE;
			wave3 = TRUE;
		}

		if (level5_1 + level5_2 + level5_3 == counter && 0 == ArmyNum()) {
			counter = 0;
			wave3 = FALSE;
			wave1 = TRUE;
			level5 = TRUE;
			next = TRUE;
		}
	}
}
void CreateArmy_level6() {

	int *num;
	AllType *a, *pre;

	DistanceSuit();

	if (FALSE == level6) {
		if (0 == ArmyNum()) {
			a = malloc(sizeof(AllType));
			B_Create(a);
			num = malloc(sizeof(int));
			*num = 0;
			ListPushBack(Army, a);
			ListPushBack(Army_PicNum, num);
		}

		pre = ListGetAt(Army, ArmyNum() - 1);
		if ((1 == ArmyNum() || pre->x < Width - distance) && 11 >= ArmyNum()) {
			a = malloc(sizeof(AllType));
			if (0 == distance % 2)
				M_Create(a);
			else
				MR_Create(a);
			num = malloc(sizeof(int));
			*num = 0;
			ListPushBack(Army, a);
			ListPushBack(Army_PicNum, num);
		}

		pre = ListGetAt(Army, 0);
		if (BOSS != pre->name) {
			level6 = TRUE;
			next = TRUE;
			init();
		}
	}
}