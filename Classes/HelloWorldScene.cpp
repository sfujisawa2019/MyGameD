﻿/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AudioEngine.h"

USING_NS_CC;
//using namespace experimental;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// イベントリスナーの作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// イベントリスナーにそれぞれ関数を登録
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
	// システムにイベントリスナーを登録（有効化）
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	//counter--;
	//if (counter == 60)
	//{
	//	experimental::AudioEngine::pause(audioID);
	//	//experimental::AudioEngine::stop(audioID);
	//	//experimental::AudioEngine::stopAll();
	//	//experimental::AudioEngine::play2d("test.mp3");
	//}
	//if (counter == 0)
	//{
	//	experimental::AudioEngine::resume(audioID);
	//}
}

// 自作関数
void HelloWorld::myFunction()
{
	Sprite* spr = Sprite::create("HelloWorld.png");
	this->addChild(spr);
	spr->setPosition(Vec2(500, 500));

	audioID = experimental::AudioEngine::play2d("test.mp3");
}

// 自作関数
void HelloWorld::myFunction2(std::string filename)
{
	Sprite* spr = Sprite::create(filename);
	this->addChild(spr);
	spr->setPosition(Vec2(500, 500));

	audioID = experimental::AudioEngine::play2d("test.mp3");
}

// 自作関数
void HelloWorld::myFunction3()
{
	/// 本当にさせたいこと
	audioID = experimental::AudioEngine::play2d("test.mp3");

	/// 次回予約
	DelayTime* delay = DelayTime::create(1.0f);
	CallFunc* callFunc = CallFunc::create(
		CC_CALLBACK_0(HelloWorld::myFunction3, this));
	// 連続実行アクション
	Sequence* seq = Sequence::create(delay, callFunc, nullptr);

	this->runAction(seq);
}

// タッチ開始時に呼ばれる関数
bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	// タッチ座標の取得
	Vec2 touch_pos = touch->getLocation();

	// スプライトの生成
	spr = Sprite::create("CloseNormal.png");
	this->addChild(spr);
	spr->setPosition(touch_pos);

	//                                ファイル名
	experimental::AudioEngine::play2d("test.mp3");

	return true;
}

// タッチを動かした時に呼ばれる関数
void HelloWorld::onTouchMoved(Touch* touch, Event* unused_event)
{
	// タッチ座標の取得
	Vec2 touch_pos = touch->getLocation();

	spr->setPosition(touch_pos);

	//// スプライトを削除
	//spr->removeFromParent();
}

// タッチを離した時に呼ばれる関数
void HelloWorld::onTouchEnded(Touch* touch, Event* unused_event)
{
	
}

// タッチがキャンセルされた時に呼ばれる関数
void HelloWorld::onTouchCancelled(Touch* touch, Event* unused_event)
{

}