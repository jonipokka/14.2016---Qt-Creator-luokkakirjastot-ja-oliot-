#include <QCoreApplication>
#include <QProcess>
#include <QFile>
#include <QTextSTream>
#include <QString>
#include <QDebug>
#include <iostream>
#include "testprocess.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestProcess *TestProcessOlio;
    TestProcessOlio = new TestProcess("C:/temp/Ohjelmajono.txt");
    delete TestProcessOlio;

    return a.exec();
}
