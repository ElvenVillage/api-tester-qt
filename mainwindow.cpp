#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include "curl_events.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList methods = {"GET", "POST", "COOKIE", "JSON",
          "AUTH"};
    ui->methodBox->addItems(methods);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_runButton_clicked(){
    QString URL = ui->URLlineEdit->text();
    std::string answer="Loading... Please, wait";
    ui->textBrowser->setPlainText(answer.c_str());
    answer="";
    int http_code=::curl_query(URL.toStdString(),answer);
    if(http_code!=200){
        answer="HTTP code:"+std::to_string(http_code)+"\n"+answer;
    }
    ui->textBrowser->setPlainText(answer.c_str());
}

void MainWindow::on_curlButton_clicked()
{
    QString URL = ui->URLlineEdit->text();
    std::string answer="";
    ::curl_query_text(URL.toStdString(),answer);
    ui->textBrowser->setPlainText(answer.c_str());
}


void MainWindow::on_addPairButton_clicked()
{

}

