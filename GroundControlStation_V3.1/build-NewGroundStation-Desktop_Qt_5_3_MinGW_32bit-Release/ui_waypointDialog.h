/********************************************************************************
** Form generated from reading UI file 'waypointDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAYPOINTDIALOG_H
#define UI_WAYPOINTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_QWaypointDialog
{
public:

    void setupUi(QDialog *QWaypointDialog)
    {
        if (QWaypointDialog->objectName().isEmpty())
            QWaypointDialog->setObjectName(QStringLiteral("QWaypointDialog"));
        QWaypointDialog->setWindowModality(Qt::NonModal);
        QWaypointDialog->resize(688, 508);

        retranslateUi(QWaypointDialog);

        QMetaObject::connectSlotsByName(QWaypointDialog);
    } // setupUi

    void retranslateUi(QDialog *QWaypointDialog)
    {
        QWaypointDialog->setWindowTitle(QApplication::translate("QWaypointDialog", "\350\210\252\347\272\277\350\256\276\350\256\241\344\270\216\347\256\241\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class QWaypointDialog: public Ui_QWaypointDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAYPOINTDIALOG_H
