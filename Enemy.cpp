#include "Enemy.h"
#include <stdio.h>



Enemy::Enemy()
{
	phaseNum = 0;
}

void Enemy::Initialize()
{
	phaseNum = 0;
}

void Enemy::Update()
{
	(this->*pFunc[phaseNum])();
	phaseNum++;
	if (phaseNum > 2) {
		phaseNum = 0;
	}
}
void Enemy::Approach()
{
	printf("\n近接\n");
}

void Enemy::Attack()
{
	printf("\n射撃\n");
}

void Enemy::Secession()
{
	printf("\n離脱\n");
}

void (Enemy::* Enemy::pFunc[])() = {
		&Enemy::Approach,		// 状態 0
		&Enemy::Attack,			// 状態 1
		&Enemy::Secession		// 状態 2
};