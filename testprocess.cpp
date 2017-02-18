#include "testprocess.h"
#include <QDebug>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QString>
#include "windows.h"

TestProcess::TestProcess(QString Obj_Tiedostonimi)
{
    // Aloittaa funktiosarjan muuntaa tiedostonimen qfile muotoon
    qDebug() << Obj_Tiedostonimi;
    Obj_Tiedosto.setFileName(Obj_Tiedostonimi);
    F_Tiedostonluku();
}

TestProcess::~TestProcess() {
}

// Tämä funktio tulostaa seuraavaksi suoritettavan prosessin
void TestProcess::F_Tulostus() {
    qDebug() << Obj_Ohjelma;
}

// Tämä funktio lukee tekstitiedostosta prosessin ja kutsuu prosessinhallintafunktion
void TestProcess::F_Tiedostonluku() {
    QFile Obj_Tiedosto("C:/temp/Ohjelmajono.txt");
    if (!Obj_Tiedosto.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Virhe avatessa tiedostoa!" << endl;
    } else {
    QTextStream in(&Obj_Tiedosto);
    while (!in.atEnd()) {
        Obj_Ohjelma = in.readLine();
        F_Tulostus();
        F_Prosessinhallinta();
    }}
    Obj_Tiedosto.close();
    qDebug() << "Ohjelmien suoritus valmis" << endl;
}

// Tämä funktio avaa ja sulkee prosessin
void TestProcess::F_Prosessinhallinta() {
    F_AloitaProsessi();
    Sleep(4000);
    F_LopetaProsessi();
}

void TestProcess::F_AloitaProsessi() {
    Obj_SuoritettavaOhjelma = new QProcess();
    Obj_SuoritettavaOhjelma->start(Obj_Ohjelma);
}

void TestProcess::F_LopetaProsessi() {
    Obj_SuoritettavaOhjelma->kill();
}
