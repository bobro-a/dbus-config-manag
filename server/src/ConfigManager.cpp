#include "ConfigManager.h"


ConfigurationManager::ConfigurationManager(QObject *parent) : QObject(parent) {
    loadConfigs(QDir::homePath() + "/" + SERVER_NAME + "/");
}

void ConfigurationManager::loadConfigs(const QString &path) {
    QDir dir(path);
    QStringList files = dir.entryList(QStringList() << "*json", QDir::Files);
    QDBusConnection conn = QDBusConnection::sessionBus();
    for (auto filename: files) {
        QFile file(dir.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            continue;
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (!jsonDoc.isObject())
            continue;
        QVariantMap config = jsonDoc.object().toVariantMap();
        QString appName = filename;
        appName.chop(5);
        QString fullPath = pathToApp_ + appName;
        ConfigObject *object = new ConfigObject(this, appName, config);
        conn.registerObject(fullPath, object,
                            QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals);
        configs.insert(appName, object);
    }
}
