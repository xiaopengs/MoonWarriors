#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    	bool bRet = false;
	do
	{
		CC_BREAK_IF(! CCLayer::init());

		// 用一个图片做画面的背景
		CCSprite *sp = CCSprite::create("bg.png");
		CC_BREAK_IF(! sp);
		sp->setAnchorPoint(CCPointZero);
		// 既然是背景，zOrder值尽量小。
		this->addChild(sp, 0, 1);

		// 设置菜单项字体
		CCMenuItemFont::setFontName("Marker Felt");
		CCMenuItemFont::setFontSize(25);

		// 逐一创建5个菜单项
		CCMenuItemFont *newGame = CCMenuItemFont::itemWithString("New Game", this, menu_selector(HelloWorld::onNewGame));
		CC_BREAK_IF(! newGame);
		CCMenuItemFont *loadGame = CCMenuItemFont::itemWithString("Load");
		CC_BREAK_IF(! loadGame);
		CCMenuItemFont *gameSettings = CCMenuItemFont::itemWithString("Option", this, menu_selector(HelloWorld::onSettings));
		CC_BREAK_IF(! gameSettings);
		CCMenuItemFont *help = CCMenuItemFont::itemWithString("Help");
		CC_BREAK_IF(! help);
		CCMenuItemFont *quit = CCMenuItemFont::itemWithString("Quit", this, menu_selector(HelloWorld::onQuit));
		CC_BREAK_IF(! quit);

		// 将这些菜单项都加入到菜单对象中
		CCMenu *menu = CCMenu::menuWithItems(newGame, loadGame, gameSettings, help, quit, NULL);
		CC_BREAK_IF(! menu);
		// 设置菜单以纵向布局显示
		menu->alignItemsVertically();
		// 最重要的是不要忘记把菜单加入主层对象，否则不会显示
		this->addChild(menu, 1, 2);

		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::onNewGame(CCObject* pSender)
{
	CCScene *scene = CCScene::node();
	// 特别说明，我们将游戏层和控制层在此分开，由scene作为他们统一的父节点。
	//scene->addChild(GameLayer::node());
	//scene->addChild(GameControlMenu::node());
	// 从右至左滚动画面切换到游戏场景。
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(1.2f, scene));
}

void HelloWorld::onSettings(CCObject* pSender)
{
	CCScene *scene = CCScene::node();
//	scene->addChild(SettingsLayer::node());
	// 缩放变换切换到游戏设置画面。
	CCDirector::sharedDirector()->replaceScene(CCTransitionShrinkGrow::transitionWithDuration(1.2f, scene));
}

void HelloWorld::onQuit(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}


