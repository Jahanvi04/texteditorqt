#ifndef MYTEXTEDITOR_H
#define MYTEXTEDITOR_H

#include <QMainWindow>
#include "secdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyTextEditor; }
QT_END_NAMESPACE

class MyTextEditor : public QMainWindow
{
    Q_OBJECT

public:
    MyTextEditor(QWidget *parent = nullptr);
    ~MyTextEditor();

private slots:
    void on_actionBold_triggered(bool checked);






    void on_actionSuper_triggered(bool checked);

    void on_actionSub_triggered(bool checked);

    void on_actionAbout_triggered();

private:
    Ui::MyTextEditor *ui;
    SecDialog *secDialog;

};
#endif // MYTEXTEDITOR_H
