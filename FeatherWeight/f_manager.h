#pragma once

#include <QFileDialog>
#include <QDir>
#include <QtDebug>
inline QString f_FileOpen();   // 内联声明
inline QString f_Filesavas();   // 内联声明
inline QString f_Read_TXT(QString txtfilename);   // 内联声明
inline void f_Write_TXT(QString txtfilename,QString content);   // 内联声明
inline void f_Write_TXT_LINE(QString txtfilename,QString content,int line) ;   // 内联声明
inline void f_Add_line(QString txtfilename,QString content)   ;   // 内联声明
inline QString f_Replacestring(QString origintexts,QString replacee,QString replacer);   // 内联声明
inline QString f_get_text_between(QString start,QString endtext,QString text);
inline QString f_Open_directory(QString directory_base);
inline QString f_insert_a_line(QString origintext,int linenum,QString insertedtext);


QString f_FileOpen()                 //打开文件
{
    qDebug()<<"open ";
    QString fileName=QFileDialog::getOpenFileName(NULL,"openfile",QDir::currentPath(),NULL,NULL,NULL);
    qDebug()<<fileName;
    return  fileName;
}
QString f_Filesavas()
{
    qDebug()<<"saveas ";
    QString fileName= QFileDialog::getSaveFileName(NULL,"save_as",QDir::currentPath(),NULL,NULL,NULL);
    qDebug()<<fileName;

    return fileName;
}
QString f_Read_TXT(QString txtfilename)                 //打开文件
{
    QFile file(txtfilename);
    file.open(QIODevice::ReadOnly);
    QTextStream out1(&file);
    QString str1=out1.readAll();
    file.close();
    return str1;
}
void f_Write_TXT(QString txtfilename,QString content)                 //打开文件
{
    QFile file(txtfilename);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out3(&file);
    qDebug()<<"file stream created";
    out3<<content;
    file.close();
}
void f_Write_TXT_LINE(QString txtfilename,QString content,int line)                 //打开文件
{
    QFile file(txtfilename);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out3(&file);
    qDebug()<<"file stream created";
    out3<<content;
    file.close();
}
void f_Add_line(QString txtfilename,QString content)                 //打开文件
{
    QFile file(txtfilename);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out3(&file);
    qDebug()<<"file stream created";
    out3<<content;
    file.close();
}
QString f_Replacestring(QString origintexts,QString replacee,QString replacer)
{
    QString originText = origintexts;
    QString searchText = replacee;
    QString replaceText =replacer;
    QString result = originText.replace(QRegExp(searchText), replaceText);
    return  result;
}
QString f_get_text_between(QString start,QString endtext,QString text)
{
    if(start=="")//从头开始截取
    {
        int ends=text.indexOf(endtext);
        QString result=text.mid(0, ends);
        return  result;
    }
    if(endtext=="")//截取到尾部
    {
        int starts=text.indexOf(start);
        QString result=text.mid(starts+1);
        return  result;
    }
    int starts=text.indexOf(start);
    int ends=text.indexOf(endtext);
    QString result=text.mid(starts+1, ends-1-starts);
    return  result;
}
QString f_Open_directory(QString directory_base="NULL")
{
    if(directory_base=="NULL")
    {
        QFileDialog *fileDialog = new QFileDialog;
        fileDialog->setFileMode(QFileDialog::Directory);
        fileDialog->exec();
        auto selectDir = fileDialog->selectedFiles();
        if (selectDir.size()>0)
        {
            return selectDir.at(0);
        }
    }
    else
    {
        QFileDialog *fileDialog = new QFileDialog;
        fileDialog->setDirectory(QDir(directory_base));
        fileDialog->setFileMode(QFileDialog::Directory);
        fileDialog->exec();
        auto selectDir = fileDialog->selectedFiles();
        if (selectDir.size()>0)
        {
            return selectDir.at(0);
        }
    }
}
QString f_insert_a_line(QString origintext,int linenum,QString insertedtext)
{
    QStringList list = origintext.split("\n");//QString字符串分割函数
    list.insert(linenum,insertedtext);
    QString targettext;
    targettext.clear();
    for ( const auto& i : list  )
    {
        targettext.append(i+"\n");
    }
    qDebug()<<targettext;
    return targettext;
}
