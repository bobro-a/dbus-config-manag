#include <QtDBus>
#include "ConfigObject.h"

class ConfigurationManager : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.system.configurationManager");

public:
    explicit ConfigurationManager(QObject *parent = nullptr);

private:
    QMap<QString, ConfigObject*> configs;

    void loadConfigs(const QString &path);
};
