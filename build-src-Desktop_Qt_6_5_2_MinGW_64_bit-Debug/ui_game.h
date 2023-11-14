/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *menu_page;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_level_1;
    QPushButton *btn_level_2;
    QPushButton *btn_exit_game;
    QWidget *level_1;
    QVBoxLayout *verticalLayout_4;
    QGraphicsView *graphics_level_1;
    QWidget *level_2;
    QVBoxLayout *verticalLayout_5;
    QGraphicsView *graphics_level_2;
    QWidget *game_menu;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn_go_back;
    QPushButton *btn_continue;
    QLabel *label_3;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName("Game");
        Game->resize(800, 600);
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        menu_page = new QWidget();
        menu_page->setObjectName("menu_page");
        label = new QLabel(menu_page);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 60, 635, 71));
        label->setMinimumSize(QSize(635, 71));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(menu_page);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(310, 230, 160, 163));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_level_1 = new QPushButton(verticalLayoutWidget);
        btn_level_1->setObjectName("btn_level_1");
        btn_level_1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(btn_level_1);

        btn_level_2 = new QPushButton(verticalLayoutWidget);
        btn_level_2->setObjectName("btn_level_2");

        verticalLayout_3->addWidget(btn_level_2);

        btn_exit_game = new QPushButton(verticalLayoutWidget);
        btn_exit_game->setObjectName("btn_exit_game");

        verticalLayout_3->addWidget(btn_exit_game);

        stackedWidget->addWidget(menu_page);
        level_1 = new QWidget();
        level_1->setObjectName("level_1");
        verticalLayout_4 = new QVBoxLayout(level_1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        graphics_level_1 = new QGraphicsView(level_1);
        graphics_level_1->setObjectName("graphics_level_1");
        graphics_level_1->setEnabled(true);

        verticalLayout_4->addWidget(graphics_level_1);

        stackedWidget->addWidget(level_1);
        level_2 = new QWidget();
        level_2->setObjectName("level_2");
        verticalLayout_5 = new QVBoxLayout(level_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        graphics_level_2 = new QGraphicsView(level_2);
        graphics_level_2->setObjectName("graphics_level_2");

        verticalLayout_5->addWidget(graphics_level_2);

        stackedWidget->addWidget(level_2);
        game_menu = new QWidget();
        game_menu->setObjectName("game_menu");
        verticalLayoutWidget_2 = new QWidget(game_menu);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(300, 220, 160, 163));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        btn_go_back = new QPushButton(verticalLayoutWidget_2);
        btn_go_back->setObjectName("btn_go_back");
        btn_go_back->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(btn_go_back);

        btn_continue = new QPushButton(verticalLayoutWidget_2);
        btn_continue->setObjectName("btn_continue");

        verticalLayout_6->addWidget(btn_continue);

        label_3 = new QLabel(game_menu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 60, 635, 71));
        label_3->setMinimumSize(QSize(635, 71));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(game_menu);

        verticalLayout->addWidget(stackedWidget);

        Game->setCentralWidget(centralwidget);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Game", nullptr));
        label->setText(QCoreApplication::translate("Game", "Rick And Morty Final Game", nullptr));
        btn_level_1->setText(QCoreApplication::translate("Game", "Level 1", nullptr));
        btn_level_2->setText(QCoreApplication::translate("Game", "Level 2", nullptr));
        btn_exit_game->setText(QCoreApplication::translate("Game", "Exit Game", nullptr));
        btn_go_back->setText(QCoreApplication::translate("Game", "Go back", nullptr));
        btn_continue->setText(QCoreApplication::translate("Game", "Continue", nullptr));
        label_3->setText(QCoreApplication::translate("Game", "Pause Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
