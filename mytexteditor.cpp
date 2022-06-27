
#include "mytexteditor.h"
#include "ui_mytexteditor.h"
#include <QTextEdit>

MyTextEditor::MyTextEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyTextEditor)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
}

MyTextEditor::~MyTextEditor()
{
    delete ui;
}


void MyTextEditor::on_actionBold_triggered()
{
     QTextCursor cursor = ui->plainTextEdit->textCursor();
    QTextCharFormat format;
    if(!cursor.charFormat().font().bold())
    {
         format.setFontWeight(QFont::Bold);
         cursor.mergeCharFormat(format);
    }
    else
    {
        format.setFontWeight(400);
        cursor.mergeCharFormat(format);
    }
}



void MyTextEditor::on_actionSuper_triggered(bool checked)
{
     QTextCursor cursor=ui->plainTextEdit->textCursor();
    int StartPos=cursor.selectionStart();
    int EndPos=cursor.selectionEnd();
    cursor.setPosition(StartPos, QTextCursor::MoveAnchor);
    cursor.setPosition(EndPos, QTextCursor::KeepAnchor);
    QString word =cursor.selectedText();
    cursor.removeSelectedText();
    QString s="<sup>"+word+"</sup>";
    cursor.insertHtml(s);
}


void MyTextEditor::on_actionSub_triggered(bool checked)
{
     QTextCursor cursor=ui->plainTextEdit->textCursor();
    int StartPos=cursor.selectionStart();
    int EndPos=cursor.selectionEnd();
    cursor.setPosition(StartPos, QTextCursor::MoveAnchor);
    cursor.setPosition(EndPos, QTextCursor::KeepAnchor);
    QString word =cursor.selectedText();
    cursor.removeSelectedText();
    QString s="<sub>"+word+"</sub>";
    cursor.insertHtml(s);
}


void MyTextEditor::on_actionAbout_triggered()
{
    secDialog= new SecDialog(this);
    secDialog->show();
}


