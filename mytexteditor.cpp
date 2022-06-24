#include "mytexteditor.h"
#include "ui_mytexteditor.h"
#include <QTextEdit>

MyTextEditor::MyTextEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyTextEditor)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MyTextEditor::~MyTextEditor()
{
    delete ui;
}


void MyTextEditor::on_actionBold_triggered(bool checked)
{
    checked ? ui->textEdit->setFontWeight(QFont::Bold) :
              ui->textEdit->setFontWeight(QFont::Normal);
}



void MyTextEditor::on_actionSuper_triggered(bool checked)
{
    QTextCharFormat format1;
    QTextCharFormat format2;
    format1.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    format2.setVerticalAlignment(QTextCharFormat::AlignNormal);
    checked ? ui->textEdit->mergeCurrentCharFormat(format1):
              ui->textEdit->mergeCurrentCharFormat(format2);
}


void MyTextEditor::on_actionSub_triggered(bool checked)
{
    QTextCharFormat format1;
    QTextCharFormat format2;
    format1.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    format2.setVerticalAlignment(QTextCharFormat::AlignNormal);
    checked ? ui->textEdit->mergeCurrentCharFormat(format1):
              ui->textEdit->mergeCurrentCharFormat(format2);
}


void MyTextEditor::on_actionAbout_triggered()
{
    secDialog= new SecDialog(this);
    secDialog->show();
}

