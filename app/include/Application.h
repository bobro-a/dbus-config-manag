#pragma once
#include <QtDBus>
#include "Constants.h"

class Application : public QObject {
    Q_OBJECT

public:
    explicit Application(QObject *parent = nullptr);

public slots:
    void newData(const QVariantMap &newData);

    void printData();

private:
    void loadStartData();

    QVariantMap data_;
    QTimer timer_;
    int currentTimeout;
};
