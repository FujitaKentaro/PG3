#include "Enemy.h"


bool Enemy::isAlive;

void Enemy::Initialize() {

}

void Enemy::Update()
{
	
	if (isAlive == false) {
		printf("\n敵は生きている\n");
	}
	else if (isAlive == true) {
		printf("\n敵は倒された\n");
	}
}

void Enemy::Draw() {

}