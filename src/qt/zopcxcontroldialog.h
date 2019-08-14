// Copyright (c) 2017-2018 The OPCX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZOPCXCONTROLDIALOG_H
#define ZOPCXCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zopcx/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZOpcxControlDialog;
}

class CZOpcxControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZOpcxControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZOpcxControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZOpcxControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZOpcxControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZOpcxControlDialog(QWidget *parent);
    ~ZOpcxControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZOpcxControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZOpcxControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZOPCXCONTROLDIALOG_H
