#include "ConfigObject.h"

ConfigObject::ConfigObject(QObject *parent, const QString &name, const QVariantMap &config) : QObject(parent),
name_(name),config_(config){}

void ConfigObject::ChangeConfiguration(const QString &key, const QVariant &variant) {
    config_[key]=variant;
    emit configurationChanged(config_);
}

QVariantMap ConfigObject::GetConfiguration() {
    return config_;
}
