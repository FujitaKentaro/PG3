#include "Enemy.h"


bool Enemy::isAlive;

void Enemy::Initialize() {

}

void Enemy::Update()
{
	
	if (isAlive == false) {
		printf("\n“G‚Í¶‚«‚Ä‚¢‚é\n");
	}
	else if (isAlive == true) {
		printf("\n“G‚Í“|‚³‚ê‚½\n");
	}
}

void Enemy::Draw() {

}