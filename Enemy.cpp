#include "Enemy.h"


bool Enemy::isAlive;

void Enemy::Initialize() {

}

void Enemy::Update()
{
	
	if (isAlive == false) {
		printf("\n�G�͐����Ă���\n");
	}
	else if (isAlive == true) {
		printf("\n�G�͓|���ꂽ\n");
	}
}

void Enemy::Draw() {

}