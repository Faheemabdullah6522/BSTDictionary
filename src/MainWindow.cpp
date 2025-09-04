#include "MainWindow.h"
#include <QWidget>
#include <QGroupBox>
#include <QMessageBox>
#include <sstream>
#include <iostream>
#include <limits>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), dict()
{

    setWindowTitle("BST Dictionary (Qt GUI)");
    resize(700, 480);

    keyEdit = new QLineEdit(this);
    valueEdit = new QLineEdit(this);
    output = new QTextEdit(this);
    output->setReadOnly(true);

    insertBtn = new QPushButton("Insert / Update", this);
    findBtn = new QPushButton("Find", this);
    removeBtn = new QPushButton("Remove", this);
    showBtn = new QPushButton("Show All", this);
    saveBtn = new QPushButton("Save to file", this);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto *leftLayout = new QVBoxLayout();
    {
        QGroupBox *inBox = new QGroupBox("Entry", central);
        auto *inLayout = new QVBoxLayout();
        inLayout->addWidget(new QLabel("Key (word):"));
        inLayout->addWidget(keyEdit);
        inLayout->addWidget(new QLabel("Value (meaning):"));
        inLayout->addWidget(valueEdit);
        inBox->setLayout(inLayout);
        leftLayout->addWidget(inBox);

        auto *btnLayout = new QHBoxLayout();
        btnLayout->addWidget(insertBtn);
        btnLayout->addWidget(findBtn);
        btnLayout->addWidget(removeBtn);
        leftLayout->addLayout(btnLayout);

        leftLayout->addWidget(showBtn);
        leftLayout->addWidget(saveBtn);
    }

    auto *mainLayout = new QHBoxLayout(central);
    mainLayout->addLayout(leftLayout, 1);
    mainLayout->addWidget(output, 2);

    connect(insertBtn, &QPushButton::clicked, this, &MainWindow::onInsert);
    connect(findBtn, &QPushButton::clicked, this, &MainWindow::onFind);
    connect(removeBtn, &QPushButton::clicked, this, &MainWindow::onRemove);
    connect(showBtn, &QPushButton::clicked, this, &MainWindow::onShowAll);
    connect(saveBtn, &QPushButton::clicked, this, &MainWindow::onSave);

    dict.loadFromFile("dictionary.txt");

    onShowAll();
}

void MainWindow::onInsert()
{
    QString k = keyEdit->text().trimmed();
    QString v = valueEdit->text();
    if (k.isEmpty())
    {
        QMessageBox::warning(this, "Insert", "Please enter a key.");
        return;
    }
    dict.insert(k.toStdString(), v.toStdString());
    output->append(QString("Inserted/updated: \"%1\"").arg(k));
    keyEdit->clear();
    valueEdit->clear();
}

void MainWindow::onFind()
{
    QString k = keyEdit->text().trimmed();
    if (k.isEmpty())
    {
        QMessageBox::warning(this, "Find", "Please enter a key to find.");
        return;
    }
    std::string key = k.toStdString();
    std::string *val = dict.find(key);
    if (val)
    {
        output->append(QString("Found: \"%1\" : %2").arg(k).arg(QString::fromStdString(*val)));
    }
    else
    {
        output->append(QString("Not found: \"%1\"").arg(k));
    }
}

void MainWindow::onRemove()
{
    QString k = keyEdit->text().trimmed();
    if (k.isEmpty())
    {
        QMessageBox::warning(this, "Remove", "Please enter a key to remove.");
        return;
    }
    dict.remove(k.toStdString());
    output->append(QString("Removed (if existed): \"%1\"").arg(k));
    keyEdit->clear();
}

void MainWindow::onShowAll()
{
    std::string s = captureShowOutput();
    if (s.empty())
        s = "<empty dictionary>";
    output->append("=== Dictionary (in-order) ===");
    output->append(QString::fromStdString(s));
    output->append("============================");
}

void MainWindow::onSave()
{
    dict.saveToFile("dictionary.txt");
    output->append("Saved dictionary to dictionary.txt");
}

std::string MainWindow::captureShowOutput()
{
    std::ostringstream oss;
    std::streambuf *oldBuf = std::cout.rdbuf(oss.rdbuf());
    dict.show();
    std::cout.rdbuf(oldBuf);
    return oss.str();
}
