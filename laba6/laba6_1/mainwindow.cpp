#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//tree.insert(tree.getRoot(), "sasha");
	//tree.insert(tree.getRoot(), "masha");
	//tree.insert(tree.getRoot(), "kasha");
	//tree.insert(tree.getRoot(), "dasha");
	//tree.insert(tree.getRoot(), "rasha"); 
}

void MainWindow::AddWidget(QTreeWidgetItem* oof, Node<QString>* root) {


    if (oof->childCount() != 3)
    {
        oof->addChild(new QTreeWidgetItem);
        oof->child(0)->setText(0, "data: " + root->key);

        oof->addChild(new QTreeWidgetItem);
        oof->child(1)->setText(0, "Left");

        oof->addChild(new QTreeWidgetItem);
        oof->child(2)->setText(0, "Right");
    }
    if (root->left) {

        AddWidget(oof->child(1), root->left);
    }

    if (root->right) {
        AddWidget(oof->child(2), root->right);
    }
} 

void MainWindow::on_Add_clicked()
{
    ui.Tree->clear();
	
    tree.insert(tree.getRoot(), ui.lineEditAdd->text());
	
    ui.Tree->headerItem()->setText(0, "AWL Tree");
    ui.Tree->insertTopLevelItem(0, new QTreeWidgetItem);
    ui.Tree->topLevelItem(0)->setText(0, "Root");
    AddWidget(ui.Tree->topLevelItem(0), tree.getRoot());
    ui.Tree->expandAll();
	
}

void MainWindow::on_Delete_clicked()
{
	if (tree.getRoot() == nullptr)
	{
		QMessageBox::critical(this, "Error", "Tree is empty");
		return;
	}
	
	ui.Tree->clear();
	
	tree.remove(tree.getRoot(), ui.lineEditDelete->text());
	
	ui.Tree->headerItem()->setText(0, "AWL Tree");
	ui.Tree->insertTopLevelItem(0, new QTreeWidgetItem);
	ui.Tree->topLevelItem(0)->setText(0, "Root");
	if (tree.getRoot() != nullptr)
	    AddWidget(ui.Tree->topLevelItem(0), tree.getRoot());
	ui.Tree->expandAll();
	
}

void MainWindow::on_Find_clicked()
{
	if (tree.getRoot() == nullptr)
	{
		QMessageBox::critical(this, "Error", "Tree is empty");
		return;
	}
	if (tree.find(tree.getRoot(), ui.lineEditFind->text()) != nullptr)
	{
		ui.lineEditFind->setStyleSheet("QLineEdit { background-color: green; }");
	}
	else
	{
		ui.lineEditFind->setStyleSheet("QLineEdit { background-color: red; }");
	}
}

void MainWindow::on_Calculate_clicked()
{
	if (tree.getRoot() == nullptr)
	{
		QMessageBox::critical(this, "Error", "Tree is empty");
		return;
	}
		
	
	QString str = "";
	tree.inContOfDepth(tree.getRoot()->height);
	int* arr = tree.getCountOfEachDepth();
	
    tree.Calculate(tree.getRoot());
	
	for (int i = 0; i < tree.getRoot()->height; i++)
	{
		str += QString::number(arr[i]) + " ";
	}
	
	ui.idTask->setText(str);
}