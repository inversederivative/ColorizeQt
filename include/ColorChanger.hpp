//
// Created by John on 2/19/2024.
//
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QIntValidator>
#include <QLabel>
#include <QColorDialog>

#ifndef COLORIZEQT_COLORCHANGER_HPP
#define COLORIZEQT_COLORCHANGER_HPP

class ColorChanger : public QWidget {
public:
    explicit ColorChanger(QWidget *parent = nullptr);

private:
    QLineEdit *createLineEdit();

    void changeColor();

    void showError(const QString &message);

    void openColorPicker();

    QLabel *redLabel;
    QLabel *greenLabel;
    QLabel *blueLabel;
    QLabel *alphaLabel;
    QLineEdit *redLineEdit;
    QLineEdit *greenLineEdit;
    QLineEdit *blueLineEdit;
    QLineEdit *alphaLineEdit;
    QPushButton *sampleButton;
    QPushButton *submitButton;
};

#endif //COLORIZEQT_COLORCHANGER_HPP
