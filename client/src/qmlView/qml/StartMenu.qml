import QtQuick 2.0


Rectangle {
	id: main

	width: 240
	height: 320

	// сигналы для внешнего мира :)
	signal vsAiClicked()
	signal vsPlayerClicked()
	signal settingsClicked()
	signal quitClicked()

	Menu {
		id: menu

		width: parent.width
		height: parent.height

		topShipButtonType: 0
		bottomShipButtonType: 1
		leftBombButtonType: 1
		rightBombButtonType: 0

		Component.onCompleted: {
			menu.topShipButton.clicked.connect(vsAiClicked)
			menu.bottomShipButton.clicked.connect(vsPlayerClicked)
			menu.leftBombButton.clicked.connect(settingsClicked)
			menu.rightBombButton.clicked.connect(quitClicked)
		}
	}
}