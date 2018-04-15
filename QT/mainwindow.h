#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
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
    explicit MainWindow(QWidget *parent = 0, QString _user = "");
    ~MainWindow();

private slots:
    //void on_tableView_activated(const QModelIndex &index);
    void on_select_clicked();
    void on_logout_clicked();

private:
    Ui::MainWindow *ui;
    QModelIndex modelindex;
    QString user;
protected:
    void keyPressEvent(QKeyEvent* pe);
};

#endif // MAINWINDOW_H
