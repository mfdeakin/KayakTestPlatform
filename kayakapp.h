#ifndef KAYAKAPP_H
#define KAYAKAPP_H

#include <QCoreApplication>
#include <cmdqueue.h>

class QTimer;

class KayakApp : public QCoreApplication
{
    Q_OBJECT
public:
    explicit KayakApp(int *argc, char **argv);  //See: http://qt-project.org/forums/viewthread/3498/#21990
    virtual ~KayakApp();
    void setup();
signals:
    
public slots:
    void loop();

private:
    struct cmdQueue *commands;
    QTimer *loopTimer;
};

#endif // KAYAKAPP_H
