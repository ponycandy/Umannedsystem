#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDir"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir pluginsDir("../build/plugin");
    QFile file(pluginsDir.absoluteFilePath("plugin.xml"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString A=this->ui->lineEdit->text();
    QDir pluginsDir("../plugin");
    QFile file;
     file.setFileName(pluginsDir.absoluteFilePath("UCS.pro"));
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream out3(&file);
    qDebug()<<"file stream created";

    QString str3=out3.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);

    out3<<str3<<"\n    "<< A<<"   \\";
    file.close();

    pluginsDir.mkpath(pluginsDir.absoluteFilePath(A));

    QDir filedir("../template");
    QString newfilepath="../plugin/"+A;
    pluginsDir.setPath(newfilepath);
   // qDebug()<<pluginsDir.absoluteFilePath("hello.cpp");
    QString sourcepath = filedir.absoluteFilePath("Activator.cpp");
    QString targetpath;
     targetpath = pluginsDir.absoluteFilePath("Activator.cpp");
    QFile sourcefile(sourcepath);
    sourcefile.copy(targetpath);
    file.setFileName(targetpath);
    QString newfilname=A+"Activator.cpp";



    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream out(&file);
    QString str;
     str=out.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);
QString str0;
     str0=editcpp(str,A);


    out<<str0;
    file.close();



    file.rename(pluginsDir.absoluteFilePath(newfilname));

     sourcepath = filedir.absoluteFilePath("Activator.h");
     targetpath = pluginsDir.absoluteFilePath("Activator.h");
     sourcefile.setFileName(sourcepath);
     sourcefile.copy(targetpath);
     file.setFileName(targetpath);



         file.open(QFile::ReadOnly | QFile::Text);
         QTextStream out0(&file);
         //qDebug()<<"file stream created";

         str=out0.readAll();
         file.close();
         file.open(QFile::WriteOnly | QFile::Text);

         str0=editall(str,"PLUGINNAME_H",A.toUpper()+"_H");
         str0=editall(str0,"pluginname",A);


         out0<<str0;
         file.close();







     newfilname=A+"Activator.h";
      file.rename(pluginsDir.absoluteFilePath(newfilname));


     sourcepath = filedir.absoluteFilePath("template.pro");
     targetpath = pluginsDir.absoluteFilePath("template.pro");

     sourcefile.setFileName(sourcepath);
     sourcefile.copy(targetpath);
     file.setFileName(targetpath);

     file.open(QFile::ReadOnly | QFile::Text);
     QTextStream out1(&file);
     //qDebug()<<"file stream created";

     str=out1.readAll();
     file.close();
     file.open(QFile::WriteOnly | QFile::Text);

     str0=editall(str,"PLUGINNAME_LIBRARY",A.toUpper()+"_LIBRARY");
     str0=editall(str0,"Activator",A+"Activator");


     out1<<str0;
     file.close();


     newfilname=A+".pro";
     file.rename(pluginsDir.absoluteFilePath(newfilname));
     this->ui->label_4->setText("plugin has been created");





    pluginsDir.setPath("../build/plugin");
     targetpath = pluginsDir.absoluteFilePath("plugin.xml");

     file.setFileName(targetpath);

     file.open(QFile::ReadOnly | QFile::Text);
     QTextStream out4(&file);
     //qDebug()<<"file stream created";

     str=out4.readAll();
     file.close();
     file.open(QFile::WriteOnly | QFile::Text);
     QString klo;
     klo="\""+A+"\"";

     str0=editall(str,"<!--		<endplugin/>-->","                <plugin order=\"1\" name="+klo+" />\nstart_line");
     str0=editall(str0,"start_line","<!--		<endplugin/>-->");


     out4<<str0;
     file.close();









  }
QString MainWindow::editcpp(QString str,QString A)
{
    QString originText = str;
    QString searchText = "pluginname";
    QString replaceText =A;
    QString result = originText.replace(QRegExp(searchText), replaceText);
    return  result;
}
QString MainWindow::editall(QString str,QString origin,QString target)
{
    QString originText = str;
    QString searchText = origin;
    QString replaceText =target;
    QString result = originText.replace(QRegExp(searchText), replaceText);
    return  result;
}

void MainWindow::on_pushButton_4_clicked()
{
    QDir pluginsDir;
        pluginsDir.setPath("../build/plugin");
     QString targetpath = pluginsDir.absoluteFilePath("plugin.xml");
    QFile file;
     file.setFileName(targetpath);

     file.open(QFile::ReadOnly | QFile::Text);
     QTextStream out4(&file);
     //qDebug()<<"file stream created";

     QString str=out4.readAll();
     file.close();
    this->ui->textEdit->setPlainText(str);

}

void MainWindow::on_pushButton_5_clicked()
{
    QDir pluginsDir;
        pluginsDir.setPath("../build/plugin");
     QString targetpath = pluginsDir.absoluteFilePath("plugin.xml");
    QFile file;
     file.setFileName(targetpath);

     file.open(QFile::WriteOnly | QFile::Text);
     QTextStream out4(&file);
     //qDebug()<<"file stream created";

     out4 << this->ui->textEdit->toPlainText();
     this->ui->label_5->setText("conifuration saved");
     file.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString A=this->ui->lineEdit_3->text();
    QDir filedir("../template");
    QString newfilepath="../service";
    QDir pluginsDir;
    QFile file;
    pluginsDir.setPath(newfilepath);
   // qDebug()<<pluginsDir.absoluteFilePath("hello.cpp");
    QString sourcepath = filedir.absoluteFilePath("unkownservice.h");
    QString targetpath;
     targetpath = pluginsDir.absoluteFilePath("unkownservice.h");
    QFile sourcefile(sourcepath);
    sourcefile.copy(targetpath);
    file.setFileName(targetpath);
    QString newfilname=A+"service.h";

    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream out(&file);
    QString str;
     str=out.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);
QString str0;
     str0=editall(str,"unkown",A);

     str0=editall(str0,"UNKOWN",A.toUpper());

    out<<str0;
    file.close();

    file.rename(pluginsDir.absoluteFilePath(newfilname));
    this->ui->label_6->setText("done");
}
