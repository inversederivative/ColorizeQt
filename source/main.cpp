#include <ColorChanger.hpp>



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ColorChanger window;
    window.resize(600, 400);
    window.show();

    return app.exec();
}

