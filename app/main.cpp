#include "Application.h"

int main(int argc,char* argv[]) {
    QCoreApplication app(argc,argv);
    Application application;
    QDBusConnection conn=QDBusConnection::sessionBus();
    conn.connect("com.system.configurationManager",
        "/com/system/configurationManager/Application/confManagerApplication1",
        "com.system.configurationManager.Application.Configuration",
        "configurationChanged",
        &application, SLOT(newData(QVariantMap))
        );

    return app.exec();
}