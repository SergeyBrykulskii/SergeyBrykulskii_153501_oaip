#include "canva.h"

Canva::Canva(QMainWindow* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	scn = new Paint();
	ui.graphicsView->setScene(scn);
}
