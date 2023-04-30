#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Environment/ast.hpp"
#include "Environment/environment.hpp"
#include <QMessageBox>
#include "parserctx.hpp"
#include <iostream>

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


void MainWindow::on_pushButton_clicked()
{
    QFont font("Courier New", 10); // Set the font to Courier New, size 10
    ui->textEdit_5->setFont(font); // Set the font for the QTextEdit

    QMessageBox *msg = new QMessageBox();
    QMessageBox *msg3 = new QMessageBox();
    //creando entorno global
    environment *GlobalEnv = new environment(nullptr, "Global");
    //creando ast
    ast *Root = new ast();
    //creando generador c3d
    generator_code *GeneratorC3D = new generator_code();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //ejecutando funcinoes
    if(analizador.Functions != nullptr)
    {
       analizador.Functions->ejecutar(GlobalEnv, Root, GeneratorC3D);
    }
    //ejecutar main
    GeneratorC3D->Main_Code = true;
    analizador.Main->ejecutar(GlobalEnv, Root, GeneratorC3D);
    GeneratorC3D->GenerateFinalCode();
    //valida errores
    if(Root->ErrorTable.empty())
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString(analizador.Salida));
        msg->exec();
        ui->textEdit_3->setText("Compilacion creada correctamente.");
        ui->textEdit_2->setText(QString::fromStdString(GeneratorC3D->OutputCode));
        ui->textEdit_5->clear();
        ui->textEdit_5->append(QString::fromStdString("     ID           SYM          TYPE                 DATA                LINE    COL  "));
        const std::vector<std::string>& SymbolTable = Root->getSymbolTable();
        for (int i = 0; i < SymbolTable.size(); i++) {
            ui->textEdit_5->append(QString::fromStdString(SymbolTable[i]));
        }
    }
    else
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
        msg->exec();
        const std::vector<std::string>& ErrorTable = Root->getErrorTable();
        for (int i = 0; i < ErrorTable.size(); i++) {
            ui->textEdit_4->append(QString::fromStdString(ErrorTable[i]));
        }
    }
}

