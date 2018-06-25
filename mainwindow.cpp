#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QString>
#include<QDebug>
#include<QTimer>

QSerialPort *serialPort;
QTimer *timer; // kiểu tham chiếu, con trỏ // khai báo kiểu này phải xóa đi để giải phóng ram

int number_port_old = 0,number_port_current = 0;
QString name_port[20];


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{


    ui->setupUi(this);

    // set window title
    this->setWindowTitle("ToolTest");

    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(check_port()));
    timer->start();


    // SERIAL PORT
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {

        ui->comboboxport->addItem(info.portName());//+ "(" + info.description() + info.manufacturer() + ")");

    }



    ui->comboboxbaudrate->addItem("9600");
    ui->comboboxbaudrate->addItem("1200");
    ui->comboboxbaudrate->addItem("2400");
    ui->comboboxbaudrate->addItem("4800");
    ui->comboboxbaudrate->addItem("19200");
    ui->comboboxbaudrate->addItem("38400");
    ui->comboboxbaudrate->addItem("57600");
    ui->comboboxbaudrate->addItem("115200");



    serialPort = new QSerialPort(this);

    QString portName = ui->comboboxport->currentText();
    serialPort->setPortName(portName);

   // qDebug() << portName;


 // Select Baud Rate
 //   serialPort->setBaudRate(ui->comboboxbaudrate->currentText().toInt());
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



    // set ẩn mặc định
    ui->btnsend->setEnabled(false);
    ui->linetype->setEnabled(false);


    // nhấn enter để gửi

   connect(ui->linetype,SIGNAL(returnPressed()),ui->btnsend,SIGNAL(clicked()));

   // nhận dữ liệu qua uart
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

       // QString portName = ui->comboboxport->currentText();
       // serialPort->setPortName(portName);

       // cho phép mở cổng để bắt đầu truyền

        qDebug() << "before open comport" << endl;
        serialPort->open(QIODevice::ReadWrite);
        qDebug() << "after open comport" << endl;

        ui -> comboboxbaudrate -> setEnabled(false);
        ui -> comboboxport -> setEnabled(false);


        ui->btnsend->setEnabled(true);
        ui->linetype->setEnabled(true);

        ui->btnconnect->setText("DISCONNECT");

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

      // timer->start();

       ui->textstatus->insertPlainText("\r\nDisconnect\r\n");
       ui->comboboxbaudrate->setEnabled(true);
       ui->comboboxport->setEnabled(true);
       ui->btnsend->setEnabled(false);
       ui->linetype->setEnabled(false);

      // đóng cổng com
       serialPort->close();
    }

}

void MainWindow::on_btnsend_clicked()
{
    // VIẾT DỮ LIỆU ĐƯỢC LẤY TỪ CỔNG Ô LINETYPE QUA UART
   // if(ui->linetype->text())

    serialPort->write(ui->linetype->text().toStdString().data());

   // hiển thị lên text status
    ui->textstatus->moveCursor(QTextCursor::End);
    ui->textstatus->insertPlainText("\r\nsend: ");
    ui->textstatus->insertPlainText(ui->linetype->text().toStdString().data());    
    ui->textstatus->insertPlainText("\r\n");

    ui->linetype->clear();
}

void MainWindow::serialPort_Read()
{
    ui->textstatus->insertPlainText(serialPort->readAll());

}
void MainWindow::check_port()
{

    //ui->comboboxport->clear();
    // SERIAL PORT
    // lấy từng phần tử ra khi nào hết thì thôi
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {

        name_port[number_port_current] = info.portName() + "(" + info.description() + info.manufacturer() + ")";
        number_port_current++;

     }

     if(number_port_old != number_port_current)
     {
         ui->comboboxport->clear();

         for(int k = 0; k < number_port_current; k++)
         {
             ui->comboboxport->addItem(name_port[k]);
         }
         number_port_old = number_port_current;
         number_port_current = 0;
     }
     else
        number_port_current = 0;

       // QString oldname = info.portName();
       // ui->comboboxport->addItem(info.portName());
       // if(oldname == info.portName() )
}


