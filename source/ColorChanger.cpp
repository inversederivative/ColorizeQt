//
// Created by John on 2/19/2024.
//
#include <ColorChanger.hpp>



ColorChanger::ColorChanger(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Change Color");

    QIcon appIcon("./color.png");
    setWindowIcon(appIcon);

    redLabel = new QLabel("Red:");
    greenLabel = new QLabel("Green:");
    blueLabel = new QLabel("Blue:");
    alphaLabel = new QLabel("Alpha:");

    redLineEdit = createLineEdit();
    greenLineEdit = createLineEdit();
    blueLineEdit = createLineEdit();
    alphaLineEdit = createLineEdit();

    sampleButton = new QPushButton("Sample");
    connect(sampleButton, &QPushButton::clicked, this, &ColorChanger::openColorPicker);

    submitButton = new QPushButton("Submit");
    connect(submitButton, &QPushButton::clicked, this, &ColorChanger::changeColor);



    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(redLabel);
    layout->addWidget(redLineEdit);
    layout->addWidget(greenLabel);
    layout->addWidget(greenLineEdit);
    layout->addWidget(blueLabel);
    layout->addWidget(blueLineEdit);
    layout->addWidget(alphaLabel);
    layout->addWidget(alphaLineEdit);
    layout->addWidget(sampleButton);
    layout->addWidget(submitButton);

    setLayout(layout);
}

QLineEdit *ColorChanger::createLineEdit() {
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setValidator(new QIntValidator(0, 255, this));
    return lineEdit;
}

void ColorChanger::changeColor() {
    bool ok;
    int red = redLineEdit->text().toInt(&ok);
    if (!ok) {
        showError("Invalid Red value");
        return;
    }

    int green = greenLineEdit->text().toInt(&ok);
    if (!ok) {
        showError("Invalid Green value");
        return;
    }

    int blue = blueLineEdit->text().toInt(&ok);
    if (!ok) {
        showError("Invalid Blue value");
        return;
    }

    int alpha = alphaLineEdit->text().toInt(&ok);
    if (!ok) {
        showError("Invalid Alpha value");
        return;
    }

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(red, green, blue, alpha));
    this->setPalette(palette);
}

void ColorChanger::showError(const QString &message) {
    QMessageBox::critical(this, "Error", message);
}

void ColorChanger::openColorPicker() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid()) {
        redLineEdit->setText(QString::number(color.red()));
        greenLineEdit->setText(QString::number(color.green()));
        blueLineEdit->setText(QString::number(color.blue()));
        alphaLineEdit->setText(QString::number(color.alpha()));
    }
    changeColor();
}