#include "mainwindow.hpp"
#include "Environment/ast.hpp"
#include "ui_mainwindow.h"
#include <QDir>
#include <QScrollArea>
#include <QMessageBox>
#include "parserctx.hpp"
#include <iostream>
#include <vector>
#include <QMutex>
#include <QLabel>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QMutex mutex;
    QFont font("Courier New", 10); // Set the font to Courier New, size 10
    ui->textEdit_4->setFont(font); // Set the font for the QTextEdit

    QMessageBox *msg = new QMessageBox();
    QMessageBox *msg3 = new QMessageBox();
    //creando entorno global
    environment *GlobalEnv = new environment(nullptr, "Global");
    //creando ast
    ast *Root = new ast();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //ejecutando funcinoes
    if(analizador.Functions != nullptr)
    {
       mutex.lock();
       analizador.Functions->ejecutar(GlobalEnv, Root);
       mutex.unlock();
    }
    //ejecutar main
    mutex.lock();
    analizador.Main->ejecutar(GlobalEnv, Root);
    mutex.unlock();
    //valio errores
    mutex.lock();
    if(Root->ErrorTable.empty())
    {
    //despliega el mensaje
    Root->writeToFile();
    msg->setText(QString::fromStdString(analizador.Salida));
    msg->exec();
    ui->textEdit_2->setText(QString::fromStdString(Root->ConsoleOut));
    ui->textEdit_4->clear();
    ui->textEdit_4->append(QString::fromStdString("     ID           SYM          TYPE                 DATA                LINE    COL  "));
    const std::vector<std::string>& SymbolTable = Root->getSymbolTable();
    for (int i = 0; i < SymbolTable.size(); i++) {
        ui->textEdit_4->append(QString::fromStdString(SymbolTable[i]));
    }
    }
    else
    {
    //despliega el mensaje
    msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
    msg->exec();
    const std::vector<std::string>& ErrorTable = Root->getErrorTable();
    for (int i = 0; i < ErrorTable.size(); i++) {
        ui->textEdit_3->append(QString::fromStdString(ErrorTable[i]));
    }
    }
    mutex.unlock();
    delete GlobalEnv;
}

void MainWindow::on_pushButton_3_clicked()
{
    QDir::setCurrent(".\\Environment");

    system("dot -Tpng ast.dot -o ast.dot.png");

    QPixmap originalPixmap(".\\Environment\\ast.dot.png");

    // Calculate the scaled size of the pixmap

    QLabel *label = new QLabel();
    label->setPixmap(originalPixmap);

    // Create a scroll area to hold the label
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(label);

    // Create a main window to hold the scroll area
    QMainWindow *mainWindow = new QMainWindow();
    mainWindow->setCentralWidget(scrollArea);
    mainWindow->resize(800, 600);
    mainWindow->show();


}
