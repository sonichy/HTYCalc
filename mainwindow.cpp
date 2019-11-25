#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QShortcut>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->hide();
    ui->statusBar->hide();
    move((QApplication::desktop()->width() - width())/2, (QApplication::desktop()->height() - height())/2);
    //QRegExp regx("[0-9]+$");
    //QValidator *validator = new QRegExpValidator(regx, ui->lineEdit);
    //ui->lineEdit->setValidator(validator);
    qApp->installEventFilter(this);
    connect(ui->pushButtonResult, SIGNAL(toggled(bool)), this, SLOT(showHide(bool)));
    ui->pushButtonResult->toggled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton0_clicked()
{
    ui->lineEdit->insert("0");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton1_clicked()
{
    ui->lineEdit->insert("1");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton2_clicked()
{
    ui->lineEdit->insert("2");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton3_clicked()
{
    ui->lineEdit->insert("3");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton4_clicked()
{
    ui->lineEdit->insert("4");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton5_clicked()
{
    ui->lineEdit->insert("5");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton6_clicked()
{
    ui->lineEdit->insert("6");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton7_clicked()
{
    ui->lineEdit->insert("7");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton8_clicked()
{
    ui->lineEdit->insert("8");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButton9_clicked()
{
    ui->lineEdit->insert("9");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonPoint_clicked()
{
    ui->lineEdit->insert(".");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonAdd_clicked()
{
    ui->lineEdit->insert("＋");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonMinus_clicked()
{
    ui->lineEdit->insert("－");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonTime_clicked()
{
    ui->lineEdit->insert("×");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonDivide_clicked()
{
    ui->lineEdit->insert("÷");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonC_clicked()
{
    ui->lineEdit->setText("");
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonDel_clicked()
{
    ui->lineEdit->backspace();
    ui->pushButtonResult->setText("");
}

void MainWindow::on_pushButtonEqual_clicked()
{
    ui->textBrowser->clear();
    QString s = ui->lineEdit->text();
    QStringList SL = s.split(QRegExp("[＋－×÷]"));
    QStringList SL1 = s.split(QRegExp("[^＋－×÷]"), QString::SkipEmptyParts);
    qDebug() << "-------------------------------";
    qDebug() << SL;
    qDebug() << SL1;
    float result = SL.at(0).toFloat();
    for(int i=1; i<SL.length(); i++){
        QString ss = SL.at(i);
        if (ss == "") ss = "0";
        float n = ss.toFloat();
        if((i-1)<SL1.length()){
            if(SL1.at(i-1) == "＋"){
                qDebug() << ss << result << "＋" << n;
                ui->textBrowser->append("＝" + QString::number(result) + "＋" + ss);
                result += n;
            }else if(SL1.at(i-1) == "－"){
                qDebug() << ss << result << "－" << n;
                ui->textBrowser->append("＝" + QString::number(result) + "－" + ss);
                result -= n;
            }else if(SL1.at(i-1) == "×"){
                qDebug() << ss << result << "×" << n;
                ui->textBrowser->append("＝" + QString::number(result) + "×" + ss);
                result *= n;
            }else if(SL1.at(i-1) == "÷"){
                qDebug() << ss << result << "÷" << n;
                ui->textBrowser->append("＝" + QString::number(result) + "÷" + ss);
                result /= n;
            }
        }
    }
    qDebug() << result;
    ui->pushButtonResult->setText(QString::number(result));
    ui->textBrowser->append("＝" + QString::number(result));
}

void MainWindow::showHide(bool b)
{
    if(b){
        ui->textBrowser->show();
        setFixedSize(600,600);
    }else{
        ui->textBrowser->hide();
        setFixedSize(400,600);
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    QKeyEvent *KE = static_cast<QKeyEvent*>(event);
    if(event->type() == QEvent::KeyPress){
        qDebug() << KE;
        if(KE->key() == Qt::Key_Plus){
            ui->pushButtonAdd->setDown(true);
            on_pushButtonAdd_clicked();
            QTimer::singleShot(100, ui->pushButtonAdd, [=]{ ui->pushButtonAdd->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_Minus){
            ui->pushButtonMinus->setDown(true);
            on_pushButtonMinus_clicked();
            QTimer::singleShot(100, ui->pushButtonMinus, [=]{ ui->pushButtonMinus->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_Asterisk){
            ui->pushButtonTime->setDown(true);
            on_pushButtonTime_clicked();
            QTimer::singleShot(100, ui->pushButtonTime, [=]{ ui->pushButtonTime->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_Slash){
            ui->pushButtonDivide->setDown(true);
            on_pushButtonDivide_clicked();
            QTimer::singleShot(100, ui->pushButtonDivide, [=]{ ui->pushButtonDivide->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_0){
            ui->pushButton0->setDown(true);
            on_pushButton0_clicked();
            QTimer::singleShot(100, ui->pushButton0, [=]{ ui->pushButton0->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_1){
            ui->pushButton1->setDown(true);
            on_pushButton1_clicked();
            QTimer::singleShot(100, ui->pushButton1, [=]{ ui->pushButton1->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_2){
            ui->pushButton2->setDown(true);
            on_pushButton2_clicked();
            QTimer::singleShot(100, ui->pushButton2, [=]{ ui->pushButton2->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_3){
            ui->pushButton3->setDown(true);
            on_pushButton3_clicked();
            QTimer::singleShot(100, ui->pushButton3, [=]{ ui->pushButton3->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_4){
            ui->pushButton4->setDown(true);
            on_pushButton4_clicked();
            QTimer::singleShot(100, ui->pushButton4, [=]{ ui->pushButton4->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_5){
            ui->pushButton5->setDown(true);
            on_pushButton5_clicked();
            QTimer::singleShot(100, ui->pushButton5, [=]{ ui->pushButton5->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_6){
            ui->pushButton6->setDown(true);
            on_pushButton6_clicked();
            QTimer::singleShot(100, ui->pushButton6, [=]{ ui->pushButton6->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_7){
            ui->pushButton7->setDown(true);
            on_pushButton7_clicked();
            QTimer::singleShot(100, ui->pushButton7, [=]{ ui->pushButton7->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_8){
            ui->pushButton8->setDown(true);
            on_pushButton8_clicked();
            QTimer::singleShot(100, ui->pushButton8, [=]{ ui->pushButton8->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_9){
            ui->pushButton9->setDown(true);
            on_pushButton9_clicked();
            QTimer::singleShot(100, ui->pushButton9, [=]{ ui->pushButton9->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_Enter){
            ui->pushButtonEqual->setDown(true);
            on_pushButtonEqual_clicked();
            QTimer::singleShot(100, ui->pushButtonEqual, [=]{ ui->pushButtonEqual->setDown(false); });
            return true;
        }else if(KE->key() == Qt::Key_Backspace){
            ui->pushButtonDel->setDown(true);
            on_pushButtonDel_clicked();
            QTimer::singleShot(100, ui->pushButtonDel, [=]{ ui->pushButtonDel->setDown(false); });
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}
