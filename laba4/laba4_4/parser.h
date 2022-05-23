#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_parser.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <regex>
#include <QDebug>
#include <stack>
#include <QLibrary>
#include <Windows.h>

using std::smatch;
using std::stack;
using std::vector;
using std::string;
using std::regex;

class Parser : public QMainWindow
{
    Q_OBJECT

public:
    Parser(QWidget *parent = Q_NULLPTR);

	
    void getVarsData();
    void showVarsData();

    int* getObjsAndArsData();
    void showObjsAndArsData(int* nums);

    void getFunctionsData();
    void showFunctionsData();

    void coordinatesOfChanges();
    void localsCoordinates();
    void overloadsCoordinates();
    void depthOfBranches();
    void logicalErrors();
	
    
public slots: 

    void on_Code_textChanged();
    void on_comboBox_activated(int index);
    void on_File_clicked();   

private:
    Ui::ParserClass ui;
	
    QString code, result;
    std::string temp;
	
    std::vector<std::string> variables_data, classes_names, arrays_names, functions_names, functions_data;
    std::vector<size_t> functions_positions;
    std::vector<std::pair<std::string, std::string>> objects_names;
	
};
