#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QString>
#include<QDebug>


QSerialPort *serialPort;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{


    ui->setupUi(this);
    // set window title
    this->setWindowTitle("ToolTest");

    // SERIAL PORT
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    ui->comboboxport->addItem(info.portName());

    ui->comboboxbaudrate->addItem("1200");
    ui->comboboxbaudrate->addItem("2400");
    ui->comboboxbaudrate->addItem("4800");
    ui->comboboxbaudrate->addItem("9600");

    ui->comboboxbaudrate->addItem("19200");
    ui->comboboxbaudrate->addItem("38400");
    ui->comboboxbaudrate->addItem("57600");
    ui->comboboxbaudrate->addItem("115200");



    serialPort = new QSerialPort(this);
    QString portName = ui->comboboxport->currentText();

    serialPort->setPortName(portName);

   // qDebug() << portName;


// Select Baud Rate
    QString checkbaud = ui->comboboxbaudrate->currentText();
    if(checkbaud == "1200")
    {
        serialPort->setBaudRate(QSerialPort::Baud1200);
    }
    //qDebug() << checkbaud;
    if(checkbaud == "2400")
    {
        serialPort->setBaudRate(QSerialPort::Baud2400);
    }
    if(checkbaud == "4800")
    {
        serialPort->setBaudRate(QSerialPort::Baud4800);
    }
    if(checkbaud == "9600")
    {
        serialPort->setBaudRate(QSerialPort::Baud9600);
    }
    if(checkbaud == "19200")
    {
        serialPort->setBaudRate(QSerialPort::Baud19200);
    }
    if(checkbaud == "38400")
    {
        serialPort->setBaudRate(QSerialPort::Baud38400);
    }
    if(checkbaud == "57600")
    {
        serialPort->setBaudRate(QSerialPort::Baud57600);
    }
    if(checkbaud == "115200")
    {
        serialPort->setBaudRate(QSerialPort::Baud115200);
    }


    // set bit : 8bit

    serialPort->setDataBits(QSerialPort::Data8);

    // kiểm tra chẵn lẻ
    serialPort->setParity(QSerialPort::NoParity);

    // số bit stop
    serialPort->setStopBits(QSerialPort::OneStop);


    connect(serialPort,SIGNAL(readyRead()),this,SLOT(serialPort_Read()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnconnect_clicked()
{
    QString connecttext = ui->btnconnect->text();

    if(connecttext == "CONNECT")
    {
        ui->btnconnect->setText("DISCONNECT");

        // cho phép mở cổng để bắt đầu truyền
        serialPort->open(QIODevice::ReadWrite);

        ui->textstatus->insertPlainText("Connected\r\n");
        ui->textstatus->insertPlainText("Serial Port:  ");
        ui->textstatus->insertPlainText(ui->comboboxport->currentText());
        ui->textstatus->insertPlainText("\r\n");
        ui->textstatus->insertPlainText("Baud Rate:  ");
        ui->textstatus->insertPlainText(ui->comboboxbaudrate->currentText());
        ui->textstatus->insertPlainText("\r\n");



    }
    else
    {
       ui->btnconnect->setText("CONNECT");
       ui->textstatus->insertPlainText("Disconnect\r\n");

       // đóng cổng com
       serialPort->close();
    }

}

void MainWindow::on_btnsend_clicked()
{
    // VIẾT DỮ LIỆU ĐƯỢC LẤY TỪ CỔNG Ô LINETYPE
    serialPort->write(ui->linetype->text().toStdString().data());
/// hiển thị lên text status

    ui->textstatus->moveCursor(QTextCursor::End);
    ui->textstatus->insertPlainText("send: ");
    ui->textstatus->insertPlainText(ui->linetype->text().toStdString().data());
    ui->textstatus->insertPlainText("\r\n");
}

void MainWindow::serialPort_Read()
{
    ui->textstatus->moveCursor(QTextCursor::End); // DI CHUYỂN CON TRỎ RA CUỐI RỒI CHÈN TEXT

    ui->textstatus->insertPlainText(serialPort->readAll());
}
