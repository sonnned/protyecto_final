#include "menuscene.h"

MenuScene::MenuScene()
{
    s = new QGraphicsScene;
    menuTitle = new QGraphicsTextItem("Game menu");

    continueBtn = new QPushButton("Continue game");
    continueBtnProxy = new QGraphicsProxyWidget;
    continueBtnProxy->setWidget(continueBtn);
    backBtn = new QPushButton("Go back");
    backBtnProxy = new QGraphicsProxyWidget;
    backBtnProxy->setWidget(backBtn);

    //connect(continueBtn, &QPushButton::clicked, this, &MenuScene::continueBtnClicked);
    //connect(backBtn, &QPushButton::clicked, this, &MenuScene::backBtnClicked);
}

MenuScene::~MenuScene()
{
    delete s;
    delete g;
    delete menuTitle;
    delete continueBtn;
    delete backBtn;
    delete continueBtnProxy;
    delete backBtnProxy;
}

void MenuScene::setGraphicsScene(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);
    setMenuItems();
    s->addItem(menuTitle);
    s->addItem(continueBtnProxy);
    s->addItem(backBtnProxy);
    g->setScene(s);
}

void MenuScene::setMenuItems()
{
    continueBtnProxy->setPos((g->width() - continueBtn->width()) / 2, 200);
    backBtnProxy->setPos((g->width() - backBtn->width()) / 2, 250);

    QFont titleFont = menuTitle->font();
    titleFont.setBold(true);
    titleFont.setPointSize(24);
    menuTitle->setFont(titleFont);
    menuTitle->setPos((g->width() - menuTitle->boundingRect().width()) / 2, 100);
}

/*
void MenuScene::continueBtnClicked() {
    emit continueClicked();
}
void MenuScene::backBtnClicked()
{
    emit backClicked();
}
*/
