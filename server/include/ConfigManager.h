#include <QObject>
#include <QtDBus>
#include <QDir>
#include <QFile>
#include <QTextStream>

class ConfigurationManager : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.system.configurationManager");

public:
    explicit ConfigurationManager(QObject *parent = nullptr);


private:
    QStringList configs;

    void loadConfigs(const QString &path);
};
