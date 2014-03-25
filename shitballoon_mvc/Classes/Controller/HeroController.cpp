//
//  HeroController.cpp
//  shitballoon_mvc
//
//  Created by Khanh Hoang Nguyen on 3/25/14.
//
//

#include "HeroController.h"

HeroController::HeroController()
{
    
}

HeroController::~HeroController()
{
    
}

HeroController* HeroController::createHeroWithPos(CCPoint aPos)
{
    HeroController* heroController = new HeroController();
    //Model
    Hero* aHero = Hero::initWithPos(ccp(aPos.x/PTM_RATIO,aPos.y/PTM_RATIO));
    heroController->setModel(aHero);
    //View
    HeroView* aView = new HeroView();
    aView->initWithModel(aHero);
    heroController->setView(aView);
    return heroController;
}

void HeroController::touch(b2Body *aBody){
    b2Vec2 force = b2Vec2(0,150/PTM_RATIO);
    aBody->ApplyLinearImpulse(force,aBody->GetLocalCenter());
}

void HeroController::tap(b2Body *aBody){
    b2Vec2 force = b2Vec2(0,250/PTM_RATIO);
    aBody->ApplyLinearImpulse(force,aBody->GetWorldCenter());
}

void HeroController::swipeUp(b2Body *aBody){
    b2Vec2 force = b2Vec2(0,300/PTM_RATIO);
    aBody->ApplyLinearImpulse(force,aBody->GetWorldCenter());
}

void HeroController::swipeDown(b2Body *aBody){
    b2Vec2 force = b2Vec2(0,-450/PTM_RATIO);
    aBody->ApplyLinearImpulse(force,aBody->GetWorldCenter());
}

void HeroController::swipeLeft(b2Body *aBody){
    b2Vec2 force = b2Vec2(-300/PTM_RATIO,0);
    aBody->ApplyLinearImpulse(force,aBody->GetWorldCenter());
}

void HeroController::swipeRight(b2Body *aBody){
    b2Vec2 force = b2Vec2(300/PTM_RATIO,0);
    aBody->ApplyLinearImpulse(force,aBody->GetWorldCenter());
    
}
