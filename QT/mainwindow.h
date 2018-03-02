#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QLCDNumber>
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


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
