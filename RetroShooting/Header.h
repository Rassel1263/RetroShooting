#pragma once
#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Singleton.h"
#include "Input.h"
#include "Texture.h"
#include "Sprite.h"

#include "Collider2D.h"
#include "Object.h"

#include "MainMenu.h"

#include "State.h"
#include "Unit.h"
#include "Player.h"
#include "PlayerState.h"

#include "Enemy.h"
#include "RushEnemy.h"
#include "Turret.h"
#include "DestructEnemy.h"
#include "DefensiveEnemy.h"
#include "FlashEnemy.h"
#include "Barrier.h"

#include "Font.h"
#include "PlayerUI.h"
#include "EnemyUI.h"
#include "ProgressUI.h"
#include "ShopPanel.h"
#include "Fade.h"
#include "EPage.h"
#include "CalcPage.h"

#include "Obstacle.h"
#include "Infirmary.h"
#include "Arsenal.h"

#include "IBullet.h"
#include "Bullet.h"

#include "MapLayer.h"
#include "Effect.h"
#include "DestEffect.h"

#include "ResultPage.h"
#include "RankingPage.h"

#include "Scene.h"
#include "MainScene.h"
#include "GameScene.h"
#include "GameScene2.h"
#include "ResultScene.h"

#include "Game.h"

extern Scene* nowScene;