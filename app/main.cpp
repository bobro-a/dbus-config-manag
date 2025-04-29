#include "Application.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    Application application;
    QDBusConnection conn = QDBusConnection::sessionBus();
    conn.connect(SERVER_NAME,
                 "/com/system/configurationManager/Application/confManagerApplication1",
                 APP_CONFIG,
                 "configurationChanged",
                 &application, SLOT(newData(QVariantMap))
    );

    return app.exec();
}
