#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pushButton0_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();
    void on_pushButtonPoint_clicked();
    void on_pushButtonAdd_clicked();
    void on_pushButtonMinus_clicked();
    void on_pushButtonTime_clicked();
    void on_pushButtonDivide_clicked();
    void on_pushButtonEqual_clicked();
    void on_pushButtonC_clicked();
    void on_pushButtonDel_clicked();
    void showHide(bool b);

};

#endif // MAINWINDOW_H