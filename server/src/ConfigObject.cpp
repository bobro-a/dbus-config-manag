#include "ConfigObject.h"

ConfigObject::ConfigObject(QObject *parent, const QString &name, const QVariantMap &config) : QObject(parent),
name_(name),config_(config){}

void ConfigObject::ChangeConfiguration(const QString &key, const QDBusVariant &variant) {
    if (config_.find(key)==config_.end()) {
        sendErrorReply(QDBusError::InvalidArgs, "Invalid key specified");
        return;
    }
    config_[key]=variant.variant();
    emit configurationChanged(config_);
}

QVariantMap ConfigObject::GetConfiguration() {
    return config_;
}
