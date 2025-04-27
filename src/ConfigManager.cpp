#include <QObject>
#include <QtDBus>
#include <QDir>
#include <QFile>
#include <QTextStream>

class ConfigurationManager : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.system.configurationManager");
public:
    explicit ConfigurationManager(QObject *parent = nullptr) : QObject(parent) {
        loadFilesFromDirectory("~/");
    }
public slots:
    QString getFileContent(const QString &fileName);
    signals:
    void filesLoaded(int count);
private:
    QMap<QString,QString> fileContents;
    void loadFilesFromDirectory(const QString &path);
};
