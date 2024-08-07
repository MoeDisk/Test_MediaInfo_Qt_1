#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->plainTextEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    QString filePath = ui->lineEdit->text();
    if (filePath.isEmpty()) {
        ui->plainTextEdit->setPlainText("File path empty.");
            return;
    }

    HMediaInfoHelper helper;
    auto info = helper.GetMediaInfo(filePath,1);

    QString result;
    result += "Complete Info: " + info.completeInfo + "\n";
    result += "Width: " + QString::number(info.width) + "\n";
    result += "Height: " + QString::number(info.height) + "\n";
    result += "Duration: " + QString::number(info.duration) + "\n";
    result += "Frame Rate: " + QString::number(info.frameRate) + "\n";
    result += "Bit Rate: " + QString::number(info.bitRate) + "\n";

    ui->plainTextEdit->setPlainText(result);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event){
    QList<QUrl> urls = event->mimeData()->urls();
    if (!urls.isEmpty()) {
        QString filePath = urls.first().toLocalFile();
        ui->lineEdit->setText(filePath);
    }
}
