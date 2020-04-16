#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include "../../prioritized-queue-uml/priority_queue_data_structure/ListPriorQueue.h"
#include "../../prioritized-queue-uml/priority_queue_data_structure/TreePriorQueue.h"
#include "../../prioritized-queue-uml/priority_queue_data_structure/VectorPriorQueue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool oneRadioButtonSelected();
    ListPriorQueue<QString>* lqueue;
    TreePriorQueue<QString>* tqueue;
    VectorPriorQueue<QString>* vqueue;
    //0 - lqueue 1 - tqueue 2 - vqueue
    size_t queueType;
    QRadioButton* toggledRadioButton;
    void updateQueueType();
    void updateOutput();
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonChange_clicked();
    void on_radioButton_toggled(bool);
};
#endif // MAINWINDOW_H
