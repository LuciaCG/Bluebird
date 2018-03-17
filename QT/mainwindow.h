#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QLCDNumber>
#include <QModelIndex>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tableView_activated(const QModelIndex &index);


    void on_BlackPanther_clicked();

private:
    Ui::MainWindow *ui;
    QModelIndex modelindex;
};

#endif // MAINWINDOW_H
