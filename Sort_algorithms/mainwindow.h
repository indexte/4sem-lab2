#pragma once

#include <QMainWindow>

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

    void on_Insertion_sort_clicked();

    void on_Quicksort_clicked();

    void on_Heap_sort_clicked();

    void on_Save_clicked();

    void on_Read_clicked();

private:
    Ui::MainWindow *ui;
};
