#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPropertyAnimation>
#include <QStringListModel>
#include <QDateTime>
#include "vector.h"
#include <dateformator.h>
#include <algorithm>
#include <bitset>
#include "list.h"
#include <chrono>
#include "itor_vector.h"
#include <iostream>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_3_returnPressed();

    void on_pushButton_10_pressed();

    void on_pushButton_11_pressed();

    void on_pushButton_12_pressed();

    void on_pushButton_13_pressed();

    void on_pushButton_14_pressed();

    void on_pushButton_6_pressed();

private:
    Ui::MainWindow *ui;

    void AddFruit();

    void UpdateListViews();
    void UpdateListDatesView();
    void AddDate();
    void AddBitSet();
    void RunVectorListTest(int n);

    void ShiftLeft();
    void ShiftRight();

    int all12 = 0;
    int never = 0;
    int eightOrMore = 0;
    int bitSetCounter = 0;

    bool ShouldSort = false;
    bool ShoulRemoveA = false;
    bool ShouldRemoveCitrus = false;
    QStringListModel * model1;
    QStringListModel * model2;
    QStringListModel * dateModel;
    vector<std::string> stringList1 = vector<std::string>(0);
    vector<std::string> stringList2 = vector<std::string>(0);
    vector<std::string> Citrus = vector<std::string>(0);
    vector<std::string> dates = vector<std::string>(0);
    vector<char> alphabet = vector<char>(0);
    DateFormator formator;

    std::bitset<67> bitset = std::bitset<67>(228);
    char charForShifting = 'C';
    int intForShifting = 1337;
};
#endif // MAINWINDOW_H
