#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "it.h"
#include "list.h"
#include "sort.h"
#include "sort_algorithms.h"
#include <set>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

Sort<int> my_sort;
List<int> _data;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    qsrand(time(0));
    for (int i = 0; i < 1000; i++)  //random number generation (unsigned short int)
        _data.add(qrand());
    ui->output->clear();
    for(auto tmp_data : _data.Show())
        ui->output->append(QString::number(tmp_data));
}
MainWindow::~MainWindow(){ delete ui; }

void MainWindow::on_Insertion_sort_clicked(){
    my_sort.set_sort_type(Sort_type::Insertion);
    ui->output->clear();
    auto tmp = _data.Show();
    unsigned start_time =  clock();
    my_sort(tmp);
    _data.clear();
    for(auto a:tmp)
        _data.add(a);
    for(auto tmp_data : _data.Show())
        ui->output->append(QString::number(tmp_data));
    unsigned end_time = clock();
    ui->time->setText("time = " + QString::number(end_time - start_time) + "ms");
}

void MainWindow::on_Quicksort_clicked(){
    my_sort.set_sort_type(Sort_type::Quick);
    ui->output->clear();
    auto tmp = _data.Show();
    unsigned start_time =  clock();
    my_sort(tmp);
    _data.clear();
    for(auto a:tmp)
        _data.add(a);
    for(auto tmp_data : _data.Show())
        ui->output->append(QString::number(tmp_data));
    unsigned end_time = clock();
    ui->time->setText("time = " + QString::number(end_time - start_time) + "ms");
}

void MainWindow::on_Heap_sort_clicked(){
    my_sort.set_sort_type(Sort_type::Heap);
    ui->output->clear();
    auto tmp = _data.Show();
    unsigned start_time =  clock();
    my_sort(tmp);
    _data.clear();
    for(auto a:tmp)
        _data.add(a);
    for(auto tmp_data : _data.Show())
        ui->output->append(QString::number(tmp_data));
    unsigned end_time = clock();
    ui->time->setText("time = " + QString::number(end_time - start_time) + "ms");
}

void MainWindow::on_Save_clicked(){
    QString res = ui->output->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save numbers"), "",
           tr("All Files (*)"));
    if (fileName.isEmpty())
         return;
     else {
         QFile file(fileName);
         if (!file.open(QIODevice::WriteOnly)) {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }
         file.write(res.toStdString().c_str());

     }
}

void MainWindow::on_Read_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open numbers"), "",
            tr("All Files (*)"));
    if (fileName.isEmpty())
            return;
        else {

            QFile file(fileName);

            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
            char* tmp = new char[12];

            _data.clear();
            for (int i = 0; i < 500 ; i++){
                file.readLine(tmp, 12);
                _data.add(atoi(tmp));
            }

    }
    ui->output->clear();
    for(auto tmp_data : _data.Show())
        ui->output->append(QString::number(tmp_data));
}
