#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ZorkUL.h>
#include <QPropertyAnimation> //For animations :)



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void ChangeBackground(string direction);
    void MagicKey(char room);
    void MasterKey();
    int CheatMode();
    int x = 0;
    void FinalRoom();
    void Check(string letter);

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_northButton_clicked();

    void on_southButton_clicked();

    void on_eastButton_clicked();

    void on_wesButton_clicked();

    void on_Key_clicked();

    void on_Key1_clicked();

    void on_Help_clicked();

private:
    Ui::MainWindow *ui;
    ZorkUL tempx;
    QPropertyAnimation *KeyAnimation;


};

#endif // MAINWINDOW_H
