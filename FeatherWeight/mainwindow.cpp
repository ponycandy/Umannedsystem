#include "f_manager.h"
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

QString MainWindow::get_text_between(QString start, QString endtext, QString text)
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
        QString result=text.mid(starts+start.size());
        return  result;
    }
    int starts=text.indexOf(start);
    int ends=text.indexOf(endtext);
    QString result=text.mid(starts+1, ends-1-starts);
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
    this->ui->label_5->setText("done");

}

void MainWindow::on_pushButton_6_clicked()
{
    QString libname=ui->lineEdit_4->text();

    QDir filedir("../template");
    QDir newfilepath("../3rdlib/project_library/src");
    QFile file;


    ///复制pro文件
    file.setFileName(newfilepath.absoluteFilePath("library_gen.pro"));
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream library_gen_pro(&file);

    qDebug()<<"file stream created";

    QString library_gen_pro_str=library_gen_pro.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);

    library_gen_pro<<library_gen_pro_str<<"\n    "<< libname<<"   \\";
    file.close();

    newfilepath.mkpath(newfilepath.absoluteFilePath(libname));

    QString newfilepath_str="../3rdlib/project_library/src/"+libname;
    newfilepath.setPath(newfilepath_str);
    QString sourcepath = filedir.absoluteFilePath("lib_template.pro");
    QString targetpath= newfilepath.absoluteFilePath("lib_template.pro");
    QFile sourcefile(sourcepath);
    sourcefile.copy(targetpath);

    QString newfilname=libname+".pro";
    file.setFileName(targetpath);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream lib_template_pro(&file);
    QString lib_template_str;
    lib_template_str=lib_template_pro.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);
    QString lib_template_str_new=f_Replacestring(lib_template_str,"UNKNOW_LIBRARY_global",libname.toUpper()+"_global");
    QString lib_template_str_new_1=f_Replacestring(lib_template_str_new,"UNKNOW_LIBRARY.cpp",libname+".cpp");
    QString lib_template_str_new_2=f_Replacestring(lib_template_str_new_1,"UNKNOW_LIBRARY.h",libname+".h");
    QString lib_template_str_new_3=f_Replacestring(lib_template_str_new_2,"DEFINES += UNKNOW_LIBRARY","DEFINES += "+libname.toUpper());

    lib_template_pro<<lib_template_str_new_3;
    file.close();
    file.rename(newfilepath.absoluteFilePath(newfilname));



    ///复制pro文件
    ///
    ///复制cpp文件


    newfilepath_str="../3rdlib/project_library/src/"+libname;
    newfilepath.setPath(newfilepath_str);
    sourcepath = filedir.absoluteFilePath("LIBRARY_NAME.cpp");
    targetpath= newfilepath.absoluteFilePath("LIBRARY_NAME.cpp");
    sourcefile.setFileName(sourcepath);
    sourcefile.copy(targetpath);

    newfilname=libname+".cpp";
    file.setFileName(targetpath);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream LIBRARY_NAME_CPP(&file);
    QString LIBRARY_NAME_CPP_str;
    LIBRARY_NAME_CPP_str=LIBRARY_NAME_CPP.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);
    QString LIBRARY_NAME_CPP_str_new=f_Replacestring(LIBRARY_NAME_CPP_str,"LIBRARY_NAME",libname);
    LIBRARY_NAME_CPP<<LIBRARY_NAME_CPP_str_new;
    file.close();
    file.rename(newfilepath.absoluteFilePath(newfilname));
    ///复制cpp文件
    ///复制h文件
    newfilepath_str="../3rdlib/project_library/src/"+libname;
    newfilepath.setPath(newfilepath_str);
    sourcepath = filedir.absoluteFilePath("LIBRARY_NAME.h");
    targetpath= newfilepath.absoluteFilePath("LIBRARY_NAME.h");
    sourcefile.setFileName(sourcepath);
    sourcefile.copy(targetpath);

    newfilname=libname+".h";
    file.setFileName(targetpath);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream LIBRARY_NAME_h(&file);
    QString LIBRARY_NAME_h_str;
    LIBRARY_NAME_h_str=LIBRARY_NAME_h.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);
    QString LIBRARY_NAME_h_str_new=f_Replacestring(LIBRARY_NAME_h_str,"LIBRARY_NAME_H",libname.toUpper()+"_H");
    QString LIBRARY_NAME_h_str_new_1=f_Replacestring(LIBRARY_NAME_h_str_new,"UNKNOW_LIBRARY",libname.toUpper());
    QString LIBRARY_NAME_h_str_new_2=f_Replacestring(LIBRARY_NAME_h_str_new_1,"LIBRARY_NAME",libname);

    LIBRARY_NAME_h<<LIBRARY_NAME_h_str_new_2;
    file.close();
    file.rename(newfilepath.absoluteFilePath(newfilname));
    ///复制global文件
    newfilepath_str="../3rdlib/project_library/src/"+libname;
    newfilepath.setPath(newfilepath_str);
    sourcepath = filedir.absoluteFilePath("UNKNOW_LIBRARY_global.h");
    targetpath= newfilepath.absoluteFilePath("UNKNOW_LIBRARY_global.h");
    sourcefile.setFileName(sourcepath);
    sourcefile.copy(targetpath);

    newfilname=libname.toUpper()+"_global.h";
    file.setFileName(targetpath);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream UNKNOW_LIBRARY_global_h(&file);
    QString UNKNOW_LIBRARY_global_h_str;
    UNKNOW_LIBRARY_global_h_str=LIBRARY_NAME_h.readAll();
    file.close();
    file.open(QFile::WriteOnly | QFile::Text);
    QString UNKNOW_LIBRARY_global_h_str_new=f_Replacestring(UNKNOW_LIBRARY_global_h_str,"UNKNOW_LIBRARY",libname.toUpper());


    UNKNOW_LIBRARY_global_h<<UNKNOW_LIBRARY_global_h_str_new;
    file.close();
    file.rename(newfilepath.absoluteFilePath(newfilname));
    this->ui->label_6->setText("done");
    this->ui->label_5->setText("done");
}

void MainWindow::on_pushButton_8_clicked()
{
    qDebug()<<"open ";
    QString lib_dir("../3rdlib/project_library/src");
    QString directory_name=f_Open_directory(lib_dir);
    qDebug()<<directory_name;
    QString libname=get_text_between("3rdlib/project_library/src/","",directory_name);
    qDebug()<<libname;

    QDir filedir("../3rdlib/project_library/src/"+libname);
    QDir newfilepath("../3rdlib/project_library/include/"+libname);
    QDir newfilepath_1("../include/proj_lib/");

    QString newfilepath_str="../3rdlib/project_library/include/"+libname;
    ui->lineEdit_5->setText(newfilepath_str);
    QFileInfoList fileList = filedir.entryInfoList(QStringList() << "*.h");
    QString sourcepath;
    QString targetpath;
    QString targetpath1;

    QFile sourcefile;
    newfilepath.mkpath(newfilepath.absolutePath());

    ///遍历容器
    for(auto fileInfo:fileList)
    {
        //        ///输出文件名包含后缀
        //        qDebug() << fileInfo.fileName();
        //        ///输出文件的完整路径名
        //        qDebug() << fileInfo.absoluteFilePath();

        sourcepath = filedir.absoluteFilePath(fileInfo.absoluteFilePath());
        targetpath= newfilepath.absoluteFilePath(fileInfo.fileName());
        targetpath1= newfilepath_1.absoluteFilePath(fileInfo.fileName());

        qDebug() << targetpath1;

        sourcefile.setFileName(sourcepath);
        sourcefile.copy(targetpath);
        sourcefile.copy(targetpath1);

    }

}


void MainWindow::on_pushButton_9_clicked()
{
    QString lib_dir("../plugin");
    QString directory_name=f_Open_directory(lib_dir);
    depend_plugin_name=get_text_between("/plugin/","",directory_name);
    qDebug()<<depend_plugin_name;
    QDir filedir("../plugin/"+depend_plugin_name);


    QFile file;
    file.setFileName(filedir.absoluteFilePath(depend_plugin_name+".pro"));
    ui->lineEdit_6->setText(filedir.absoluteFilePath(depend_plugin_name+".pro"));

    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream depend_plugin_name_pro(&file);
    depend_plugin_name_pro_str=depend_plugin_name_pro.readAll();
    file.close();
    //    file.open(QFile::WriteOnly | QFile::Text);

    //    library_gen_pro<<library_gen_pro_str<<"\n    "<< libname<<"   \\";
    //    file.close();

}

void MainWindow::on_pushButton_10_clicked()
{
    QString lib_dir("../3rdlib/project_library/src");
    QString directory_name=f_Open_directory(lib_dir);
    dependency_name=get_text_between("/project_library/src/","",directory_name);
    ui->lineEdit_7->setText(directory_name);
}

void MainWindow::on_pushButton_11_clicked()
{
    QString targetext=f_insert_a_line(depend_plugin_name_pro_str,5,"LIBS += -L../../3rdlib/project_library/bin -l"+dependency_name);
    targetext=f_insert_a_line(targetext,5,"INCLUDEPATH += ../../3rdlib/project_library/src/"+dependency_name);
    QFile file;
    QDir filedir("../plugin/"+depend_plugin_name);
    file.setFileName(filedir.absoluteFilePath(depend_plugin_name+".pro"));
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream depend_plugin_name_pro(&file);
    depend_plugin_name_pro<<targetext;
    depend_plugin_name_pro_str=targetext;
    file.close();
    ui->label_5->setText("done!");
}
