#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() :
	InterfaceMainWindow(),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("МОРСКОЙ БОЙ"));
	aiLvlList = QSharedPointer<InterfaceAiLvlList> (new AiLvlList);
	connectWidget = QSharedPointer<InterfaceConnectWidget> (new ConnectWidget);
	startMenu = QSharedPointer<InterfaceStartMenu> (new StartMenu);
	battleWidget = QSharedPointer<InterfaceBattleWidget> (new BattleWidget);
	setStyleSheet(":/pictures/sea/jpg");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::showWidget(Widgets widget)
{
	switch (widget) {
	case BATTLE:
		ui->LayoutForWidget->addWidget(battleWidget.data());
		battleWidget->show();
	break;
	case START_MENU:
		ui->LayoutForWidget->addWidget(startMenu.data());
		startMenu->show();
	break;
	case CONNECT:
		ui->LayoutForWidget->addWidget(connectWidget.data());
		connectWidget->show();
	break;
	case AI_MENU:
		ui->LayoutForWidget->addWidget(aiLvlList.data());
		aiLvlList->show();
	break;
	}
}

void MainWindow::hideWidget(Widgets widget)
{
	switch (widget) {
	case BATTLE:
		battleWidget->hide();
	break;
	case START_MENU:
		startMenu->hide();
	break;
	case CONNECT:
		connectWidget->hide();
	break;
	case AI_MENU:
		aiLvlList->hide();
	break;
	}
}

QSharedPointer<InterfaceAiLvlList> MainWindow::getInterfaceAiLvlList()
{
	return aiLvlList;
}

QSharedPointer<InterfaceBattleWidget> MainWindow::getInterfaceBattleWidget()
{
	return battleWidget;
}

QSharedPointer<InterfaceConnectWidget> MainWindow::getInterfaceConnectWidget()
{
	return connectWidget;
}

QSharedPointer<InterfaceStartMenu> MainWindow::getInterfaceStartMenu()
{
	return startMenu;
}
