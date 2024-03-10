#ifndef COREMANAGER_H
#define COREMANAGER_H

#include<QObject>

class CoreManager: public QObject
{
    Q_OBJECT

public:
    explicit CoreManager(QObject* parent = nullptr);

public slots:
    void onDecimalChangedSlot(const QString& text);
    void onHexChangedSlot(const QString& text);
    void onBinaryChangedSlot(const QString& text);

signals:
    void processFailed();
    void decimalProcessed(const QString& binary, const QString& hex);
    void hexProcessed(const QString& decimal, const QString& binary);
    void binaryProcessed(const QString& decimal, const QString& hex);
};

#endif // COREMANAGER_H
