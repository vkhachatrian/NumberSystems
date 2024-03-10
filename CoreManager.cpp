#include "CoreManager.h"

CoreManager::CoreManager(QObject *parent)
    :QObject(parent)
{
}

void CoreManager::onDecimalChangedSlot(const QString &text)
{
    bool ok;
    long long valueDec = text.toLongLong(&ok); // Convert text to decimal
    if (!ok) {
        qInfo("Error converting text to decimal");
        emit processFailed();
        return;
    }

    QString valueBin = QString::number(valueDec, 2); // Convert decimal to binary
    QString valueHex = QString::number(valueDec, 16); // Convert decimal to hexadecimal

    emit decimalProcessed(valueBin, valueHex.toUpper());
}

void CoreManager::onHexChangedSlot(const QString &text)
{
    bool ok;
    unsigned long long decimal = text.toULongLong(&ok, 16); // Convert hexadecimal string to decimal
    if (!ok) {
        qInfo("Error converting hexadecimal input");
        emit processFailed();
        return;
    }

    QString binary = QString::number(decimal, 2); // Convert decimal to binary
    emit hexProcessed(QString::number(decimal), binary);
}

void CoreManager::onBinaryChangedSlot(const QString &text)
{
    bool ok;
    unsigned long long num = text.toULongLong(&ok, 16); // Convert from hexadecimal to unsigned integer
    if (!ok) {
        qInfo("Error converting hexadecimal input");
        emit processFailed();
        return;
    }

    long long decimal = text.toLongLong(&ok, 2); // Convert from binary to decimal
    if (!ok) {
        qInfo("Error converting binary input");
        emit processFailed();
        return;
    }

    emit binaryProcessed(QString::number(decimal), QString::number(num, 2));
}
