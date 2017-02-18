#ifndef TESTPROCESS_H
#define TESTPROCESS_H

#include <QDebug>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QString>

class TestProcess
{
public:
    TestProcess(QString Tiedostonimi);
    ~TestProcess();
    void F_Tiedostonluku();
    void F_Tulostus();
    void F_Prosessinhallinta();
    void F_AloitaProsessi();
    void F_LopetaProsessi();
private:
    int Var_Ohjelmanumero;
    QString Obj_Ohjelma;
    QString Obj_Tiedostonimi;
    QObject *Obj_Temp;
    QFile Obj_Tiedosto;
    QProcess *Obj_SuoritettavaOhjelma;
};

#endif // TESTPROCESS_H
