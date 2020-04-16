#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lqueue = nullptr;
    tqueue = nullptr;
    vqueue = nullptr;
    toggledRadioButton = ui->radioButtonAVLTree;
    queueType = 1;
    connect(ui->radioButtonList,&QRadioButton::toggled,this,&MainWindow::on_radioButton_toggled);
    connect(ui->radioButtonAVLTree,&QRadioButton::toggled,this,&MainWindow::on_radioButton_toggled);
    connect(ui->radioButtonVector,&QRadioButton::toggled,this,&MainWindow::on_radioButton_toggled);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::oneRadioButtonSelected(){
    return toggledRadioButton;
}

void MainWindow::on_pushButtonAdd_clicked(){
    if (oneRadioButtonSelected()){
        if (ui->lineEditData->text() == ""){
            QMessageBox* mbox = new QMessageBox(this);
            mbox->setModal(true);
            mbox->setText("Enter some value, please");
        }
        else{
            switch(queueType){
            case 0:
                lqueue->push(ui->lineEditData->text().toStdString(), std::stoi(ui->comboBoxPriority->currentText().toStdString()));
                break;
            case 1:
                tqueue->push(QString::fromStdString(ui->lineEditData->text()), std::stoi(ui->comboBoxPriority->currentText().toStdString()));
                break;
            case 2:
                vqueue->push(ui->lineEditData->text(), std::stoi(ui->comboBoxPriority->currentText().toStdString()));
                break;
            }

            updateOutput();
        }
    }
    else{//TODO: del this
        QMessageBox* mbox = new QMessageBox(this);
        mbox->setModal(true);
        mbox->setText("Please, choose the type of the queue first");
    }
}

void MainWindow::on_radioButton_toggled(bool){
    toggledRadioButton = static_cast<QRadioButton*>(sender());
    updateQueueType();
}

void MainWindow::updateQueueType(){
    if (toggledRadioButton == ui->radioButtonList)
        queueType = 0;

    if (toggledRadioButton == ui->radioButtonAVLTree)
        queueType = 1;

    if (toggledRadioButton == ui->radioButtonVector)
        queueType = 2;

    updateOutput();
}

void MainWindow::updateOutput(){
    switch (queueType){
    case 0:
        ui->listWidget->addItem(QString::fromStdString(lqueue->to_string()));
        break;
    case 1:
        ui->listWidget->addItem(QString::fromStdString(tqueue->to_string()));
        break;
    case 2:
        ui->listWidget->addItem(QString::fromStdString(vqueue->to_string()));
        break;
    }
}
