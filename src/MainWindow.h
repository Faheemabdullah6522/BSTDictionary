#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "Dictionary.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void onInsert();
    void onFind();
    void onRemove();
    void onShowAll();
    void onSave();

private:
    QLineEdit *keyEdit;
    QLineEdit *valueEdit;
    QTextEdit *output;
    QPushButton *insertBtn;
    QPushButton *findBtn;
    QPushButton *removeBtn;
    QPushButton *showBtn;
    QPushButton *saveBtn;

    Dictionary<std::string, std::string> dict;

    std::string captureShowOutput();
};
