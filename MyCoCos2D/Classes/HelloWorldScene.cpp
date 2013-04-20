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

		// ��һ��ͼƬ������ı���
		CCSprite *sp = CCSprite::create("bg.png");
		CC_BREAK_IF(! sp);
		sp->setAnchorPoint(CCPointZero);
		// ��Ȼ�Ǳ�����zOrderֵ����С��
		this->addChild(sp, 0, 1);

		// ���ò˵�������
		CCMenuItemFont::setFontName("Marker Felt");
		CCMenuItemFont::setFontSize(25);

		// ��һ����5���˵���
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

		// ����Щ�˵�����뵽�˵�������
		CCMenu *menu = CCMenu::menuWithItems(newGame, loadGame, gameSettings, help, quit, NULL);
		CC_BREAK_IF(! menu);
		// ���ò˵������򲼾���ʾ
		menu->alignItemsVertically();
		// ����Ҫ���ǲ�Ҫ���ǰѲ˵�����������󣬷��򲻻���ʾ
		this->addChild(menu, 1, 2);

		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::onNewGame(CCObject* pSender)
{
	CCScene *scene = CCScene::node();
	// �ر�˵�������ǽ���Ϸ��Ϳ��Ʋ��ڴ˷ֿ�����scene��Ϊ����ͳһ�ĸ��ڵ㡣
	//scene->addChild(GameLayer::node());
	//scene->addChild(GameControlMenu::node());
	// ����������������л�����Ϸ������
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(1.2f, scene));
}

void HelloWorld::onSettings(CCObject* pSender)
{
	CCScene *scene = CCScene::node();
//	scene->addChild(SettingsLayer::node());
	// ���ű任�л�����Ϸ���û��档
	CCDirector::sharedDirector()->replaceScene(CCTransitionShrinkGrow::transitionWithDuration(1.2f, scene));
}

void HelloWorld::onQuit(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}


