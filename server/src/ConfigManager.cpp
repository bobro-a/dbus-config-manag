#include "ConfigManager.h"


ConfigurationManager::ConfigurationManager(QObject *parent) : QObject(parent) {
    loadConfigs(QDir::homePath() + "/" + dirPath_);
}

void ConfigurationManager::loadConfigs(const QString &path) {
    QDir dir(path);
    QStringList files = dir.entryList(QStringList() << "*json", QDir::Files);
    QDBusConnection conn = QDBusConnection::sessionBus();
    for (auto filename: files) {
        QFile file(dir.filePath(filename));
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QByteArray data = file.readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
            if (jsonDoc.isObject()) {
                QVariantMap config = jsonDoc.object().toVariantMap();
                QString appName = filename;
                appName.chop(5);
                QString fullPath = "/com/system/configurationManager/Application/" + appName;
                ConfigObject *object = new ConfigObject(this, appName, config);
                conn.registerObject(fullPath, object,
                                    QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals);
                configs.insert(appName, object);
            }
        }
    }
}
