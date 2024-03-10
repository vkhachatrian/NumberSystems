#ifndef NUMBERSYSTEMSH_H
#define NUMBERSYSTEMSH_H

#include <QWidget>

class QLabel;
class QLineEdit;
class CoreManager;

class NumberSystem: public QWidget
{
    Q_OBJECT

public:
    explicit NumberSystem(QWidget* parent = nullptr);

private:
    void createMembers();
    void makeConnections();
    void setupLayout();
    void installStyleSheets();

    QLabel* m_decimalLabel;
    QLabel* m_hexLabel;
    QLabel* m_binaryLabel;

    QLineEdit* m_decimalLineEdit;
    QLineEdit* m_hexLineEdit;
    QLineEdit* m_binaryLineEdit;

    CoreManager* m_core;

private slots:
    void onDecimialProcessedSlot(const QString& binary, const QString& hex);
    void onHexProcessedSlot(const QString& decimal, const QString& binary);
    void onBinaryProcessedSlot(const QString& decimal, const QString& hex);
    void clearData();
};

#endif //NUMBERSYSTEMSH_H
