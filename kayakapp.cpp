#include "kayakapp.h"
#include <stdio.h>
#include <QTimer>

KayakApp::KayakApp(int *argc, char **argv) :
    QCoreApplication(*argc, argv),
    loopTimer(new QTimer(this))
{
    loopTimer->setInterval(0);
    connect(loopTimer, SIGNAL(timeout()), this, SLOT(loop()));
    loopTimer->start();
}

KayakApp::~KayakApp()
{
    delete loopTimer;
}

void KayakApp::loop()
{
    if(commands->hasCommand(commands)) {
        commands->executeCommand(commands);
        commands->removeCommand(commands);
    }
}

void KayakApp::setup()
{

}
