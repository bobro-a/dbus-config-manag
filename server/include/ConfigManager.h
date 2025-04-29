#pragma once
#include "ConfigObject.h"
#include "Constants.h"
#include <QObject>

class ConfigurationManager : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.system.configurationManager");

public:
    explicit ConfigurationManager(QObject *parent = nullptr);

private:
    QMap<QString, ConfigObject *> configs;

    void loadConfigs(const QString &path);

    QString pathToApp_ = "/com/system/configurationManager/Application/";
};
