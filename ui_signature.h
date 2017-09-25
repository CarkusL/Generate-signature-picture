/********************************************************************************
** Form generated from reading UI file 'signature.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNATURE_H
#define UI_SIGNATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signature
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *open_button;
    QPushButton *generate_button;
    QPushButton *save_button;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *blur_size;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *signature)
    {
        if (signature->objectName().isEmpty())
            signature->setObjectName(QStringLiteral("signature"));
        signature->resize(450, 392);
        centralWidget = new QWidget(signature);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        open_button = new QPushButton(centralWidget);
        open_button->setObjectName(QStringLiteral("open_button"));

        horizontalLayout->addWidget(open_button);

        generate_button = new QPushButton(centralWidget);
        generate_button->setObjectName(QStringLiteral("generate_button"));

        horizontalLayout->addWidget(generate_button);

        save_button = new QPushButton(centralWidget);
        save_button->setObjectName(QStringLiteral("save_button"));

        horizontalLayout->addWidget(save_button);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        blur_size = new QSlider(centralWidget);
        blur_size->setObjectName(QStringLiteral("blur_size"));
        blur_size->setMaximum(7);
        blur_size->setPageStep(1);
        blur_size->setValue(0);
        blur_size->setOrientation(Qt::Horizontal);
        blur_size->setInvertedAppearance(false);
        blur_size->setInvertedControls(false);

        horizontalLayout_3->addWidget(blur_size);


        gridLayout_4->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        signature->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(signature);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        signature->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(signature);

        QMetaObject::connectSlotsByName(signature);
    } // setupUi

    void retranslateUi(QMainWindow *signature)
    {
        signature->setWindowTitle(QApplication::translate("signature", "signature", Q_NULLPTR));
        label->setText(QString());
        open_button->setText(QApplication::translate("signature", "\346\211\223\345\274\200", Q_NULLPTR));
        generate_button->setText(QApplication::translate("signature", "\347\224\237\346\210\220\347\255\276\345\220\215", Q_NULLPTR));
        save_button->setText(QApplication::translate("signature", "\344\277\235\345\255\230", Q_NULLPTR));
        label_2->setText(QApplication::translate("signature", "\345\216\273\345\231\252\347\250\213\345\272\246\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signature: public Ui_signature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNATURE_H
