#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Modules/ImageDuplicatesFinder/ImageDuplicatesFinderModule.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"
#include "Services/ImageDuplicatesFinderService/Data/OperationProgress.h"
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterSingletonType(QUrl("qrc:///Style.qml"), "Style", 1, 0, "Style");

    qRegisterMetaType<IDFServiceOutputData>("IDFServiceOutputData");
    qRegisterMetaType<OperationProgress>("OperationProgress");

    ImageDuplicatesFinderModule::init(engine.rootContext());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}



//int main(int argc, char *argv[])
//{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

//    return app.exec();
//}
