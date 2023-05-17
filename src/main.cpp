#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //系统自带的QStyle风格
    QStringList listStyle = QStyleFactory::keys();
    //打印当前系统支持的系统风格
    foreach(QString val, listStyle)
        qDebug()<<val<<"  ";
    //设置当前风格为
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ToupCameraDemo_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
