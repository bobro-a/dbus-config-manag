#ifndef APPLICATION_H
#define APPLICATION_H
#include <QtDBus>

class Application : public QObject {
    Q_OBJECT
    Application() {
        loadStartData();
    }
public slots:
    void newData();
    void loadStartData();
private:
    QVariantMap data_;
};
#endif //APPLICATION_H
