#include <QCoreApplication>
#include <QDBusConnection>

int main(int argc,char* argv[]) {
    QCoreApplication app(argc,argv);

    QDBusConnection conn=QDBusConnection::sessionBus().connect("com.system.configurationManager",
        "/com/system/configurationManager/Application/confManagerApplication1",
        "com.system.configurationManager.Application.Configuration",
        "configurationChanged",

        );

    return app.exec();
}