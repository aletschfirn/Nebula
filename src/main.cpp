#include <Geode/Geode.hpp>
#include <Geode/cocos/CCDirector.h>
#include <Geode/cocos/base_nodes/CCNode.h>
#include <Geode/cocos/menu_nodes/CCMenu.h>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		// log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

		CCSize screenSize = CCDirector::sharedDirector()->getWinSize(); // This one gets window size, will be used to correctly place things in menu

		// Here I take nodes into variables, which I will move afterwards
		auto menuLayer = this;
		auto menuBG = this -> getChildByID("main-menu-bg");
		
		auto exitButton = this -> getChildByID("close-menu");

		auto menuCenter = this -> getChildByID("main-menu");
		auto garageButton = menuCenter -> getChildByID("icon-kit-button");
		auto mainLevelsButton = menuCenter -> getChildByID("play-button");
		auto onlineButton = menuCenter -> getChildByID("editor-button");

		auto menuBottom = this -> getChildByID("bottom-menu");
		auto achievementsButton = menuBottom -> getChildByID("achievements-button");
		auto settingsButton = menuBottom -> getChildByID("settings-button");
		auto statsButton = menuBottom -> getChildByID("stats-button");
		auto newgroundsButton = menuBottom -> getChildByID("newgrounds-button");
		auto geodeButton = menuBottom -> getChildByID("geode.loader/geode-button");

		auto profileButton = this -> getChildByID("profile-menu");
		auto socialMediaButtons = this -> getChildByID("social-media-menu");
		
		auto rightSideMenu = this -> getChildByID("right-side-menu");
		auto dailyChestButton = rightSideMenu -> getChildByID("daily-chest-button");
		auto moreGamesMenu = this -> getChildByID("more-games-menu");
		//
		
		// menuBG -> setVisible(false);  So what this does is disabling main menu background

		auto newMenu = CCMenu::create(); // This one creates new CCMenu in main menu
		auto newMenuBG = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("square02_001.png"),
			CCSprite::createWithSpriteFrameName("square02_001.png"),
			CCSprite::createWithSpriteFrameName("square02_001.png")
		);
		menuLayer -> addChild(newMenu);
		newMenu -> setID("new-main-menu"_spr);
		newMenu -> addChild(newMenuBG);
		newMenuBG -> setID("new-main-menu-bg"_spr);
		
		menuLayer -> updateLayout();
		newMenu -> updateLayout();

		/* 
		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);
		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);
		menu->updateLayout();
		*/

		return true;
	}

	void onMyButton(CCObject*) {
		FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show();
	}
};