#include "ConfigManager.h"

int main(int argc,char* argv[]) {
    QCoreApplication app(argc,argv);
    QDBusConnection conn=QDBusConnection::sessionBus();
    if (!conn.registerService("com.system.configurationManager")) {
        qFatal("Could not register D-Bus service");
    }
    ConfigurationManager configManag;
    return app.exec();
}