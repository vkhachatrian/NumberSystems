#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

#include "NumberSystem.h"
#include "CoreManager.h"

#define LABEL_HEIGHT 30

NumberSystem::NumberSystem(QWidget* parent)
    :QWidget(parent)
{
    setFixedSize(700, 300);
    setWindowTitle("NumberSystems");
    setStyleSheet("background: #c6c9f0;");

    createMembers();
    makeConnections();
    setupLayout();
    installStyleSheets();
}

void NumberSystem::createMembers()
{
    m_decimalLabel = new QLabel("Decimal", this);
    m_hexLabel = new QLabel("Hex", this);
    m_binaryLabel = new QLabel("Binary", this);

    m_decimalLineEdit = new QLineEdit(this);
    m_hexLineEdit = new QLineEdit(this);
    m_binaryLineEdit = new QLineEdit(this);

    m_core = new CoreManager(this);
}

void NumberSystem::makeConnections()
{
    connect(m_decimalLineEdit, &QLineEdit::textChanged, m_core, &CoreManager::onDecimalChangedSlot);
    connect(m_hexLineEdit, &QLineEdit::textChanged, m_core, &CoreManager::onHexChangedSlot);
    connect(m_binaryLineEdit, &QLineEdit::textChanged, m_core, &CoreManager::onBinaryChangedSlot);

    // core
    connect(m_core, &CoreManager::decimalProcessed, this, &NumberSystem::onDecimialProcessedSlot);
    connect(m_core, &CoreManager::hexProcessed, this, &NumberSystem::onHexProcessedSlot);
    connect(m_core, &CoreManager::binaryProcessed, this, &NumberSystem::onBinaryProcessedSlot);
    connect(m_core, &CoreManager::processFailed, this, &NumberSystem::clearData);
}

void NumberSystem::setupLayout()
{
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->addWidget(m_decimalLabel);
    gridLayout->addWidget(m_hexLabel);
    gridLayout->addWidget(m_binaryLabel);

    gridLayout->addWidget(m_decimalLineEdit, 0, 2, 1, 5);
    gridLayout->addWidget(m_hexLineEdit, 1, 2, 1, 5);
    gridLayout->addWidget(m_binaryLineEdit, 2, 2, 1, 5);
    setLayout(gridLayout);
}

void NumberSystem::installStyleSheets()
{
    const QString labelsStyleSheet = "QLabel{font: 18px}";

    m_decimalLabel->setStyleSheet(labelsStyleSheet);
    m_hexLabel->setStyleSheet(labelsStyleSheet);
    m_binaryLabel->setStyleSheet(labelsStyleSheet);

    m_decimalLineEdit->setFixedHeight(LABEL_HEIGHT);
    m_hexLineEdit->setFixedHeight(LABEL_HEIGHT);
    m_binaryLineEdit->setFixedHeight(LABEL_HEIGHT);

    const QString lineEditsStyleSheet = "QLineEdit{background: #ffffff; border: 2px solid black; font-size: 18px;\
                                         border-radius: 2px; padding-left: 5px; }";
    m_decimalLineEdit->setStyleSheet(lineEditsStyleSheet);
    m_hexLineEdit->setStyleSheet(lineEditsStyleSheet);
    m_binaryLineEdit->setStyleSheet(lineEditsStyleSheet);
}

void NumberSystem::onDecimialProcessedSlot(const QString &binary, const QString &hex)
{
    m_binaryLineEdit->blockSignals(true);
    m_hexLineEdit->blockSignals(true);

    m_binaryLineEdit->setText(binary);
    m_hexLineEdit->setText(hex);

    m_binaryLineEdit->blockSignals(false);
    m_hexLineEdit->blockSignals(false);
}

void NumberSystem::onHexProcessedSlot(const QString &decimal, const QString &binary)
{
    m_decimalLineEdit->blockSignals(true);
    m_binaryLineEdit->blockSignals(true);

    m_decimalLineEdit->setText(decimal);
    m_binaryLineEdit->setText(binary);

    m_decimalLineEdit->blockSignals(false);
    m_binaryLineEdit->blockSignals(false);
}

void NumberSystem::onBinaryProcessedSlot(const QString &decimal, const QString &hex)
{
    m_decimalLineEdit->blockSignals(true);
    m_hexLineEdit->blockSignals(true);

    m_decimalLineEdit->setText(decimal);
    m_hexLineEdit->setText(hex);

    m_decimalLineEdit->blockSignals(false);
    m_hexLineEdit->blockSignals(false);
}

void NumberSystem::clearData()
{
    m_decimalLineEdit->clear();
    m_hexLineEdit->clear();
    m_binaryLineEdit->clear();
}
