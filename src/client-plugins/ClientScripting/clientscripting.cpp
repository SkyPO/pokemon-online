﻿#include <QMessageBox>

#include "clientscripting.h"
#include "../Teambuilder/engineinterface.h"
#include "scriptwindow.h"
#include "scriptengine.h"

ClientPlugin* createClientPlugin(MainEngineInterface*)
{
    return new ClientScripting();
}

ClientScripting::ClientScripting()
{
}

bool ClientScripting::hasConfigurationWidget() const
{
    return true;
}

QString ClientScripting::pluginName() const
{
    return QObject::tr("Script Window");
}

QWidget *ClientScripting::getConfigurationWidget()
{
    ScriptWindow *ret = new ScriptWindow();
    QObject::connect(ret, SIGNAL(scriptChanged(QString)), engine.data(), SLOT(changeScript(QString)));
    QObject::connect(ret, SIGNAL(battleScriptChanged(QString)), engine.data(), SLOT(changeBattleScript(QString)));
    QObject::connect(ret, SIGNAL(safeScriptsChanged(bool)), engine.data(), SLOT(changeSafeScripts(bool)));
    QObject::connect(ret, SIGNAL(warningsChanged(bool)), engine.data(), SLOT(changeWarnings(bool)));
    QObject::connect(ret, SIGNAL(moogleScripts()), engine.data(), SLOT(setMoogleScripts()));
    QObject::connect(engine.data(), SIGNAL(scriptsChanged(QString)), ret, SLOT(setScripts(QString)));

    if (!engine.data()) {
        ret->setOffline();
    }

    return ret;
}

OnlineClientPlugin* ClientScripting::getOnlinePlugin(ClientInterface *c)
{
    return engine = new ScriptEngine(c);
}
