#include <QtDBus>
#pragma once

class ConfigObject : public QObject, protected QDBusContext {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.system.configurationManager.Application.Configuration");

public:
    explicit ConfigObject(QObject *parent, const QString &name, const QVariantMap &config);

public slots:
    void ChangeConfiguration(const QString &key, const QVariant &variant);

    QVariantMap GetConfiguration();

signals:
    void configurationChanged(const QVariantMap &dict);

private:
    QVariantMap config_;
    QString name_;
};
