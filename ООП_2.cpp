#include <iostream>
#include <string>
using namespace std;

class ModelWindow {
private:
    string title;
    int x, y;
    int width, height;
    string color;
    bool isVisible;
    bool hasBorder;

    bool isWithinScreen(int newX, int newY, int newWidth, int newHeight) {
        return (newX >= 0 && newY >= 0 && newX + newWidth <= 1920 && newY + newHeight <= 1080);
    }

public:
    void Init() {
        title = "Window";
        x = y = 0;
        width = height = 100;
        color = "white";
        isVisible = true;
        hasBorder = true;
    }

    void Read() {
        cout << "Title: "; getline(cin, title);
        cout << "X Y: "; cin >> x >> y;
        cout << "Width Height: "; cin >> width >> height;
        cout << "Color: "; cin >> color;
        cout << "Visible (1/0): "; cin >> isVisible;
        cout << "Border (1/0): "; cin >> hasBorder;
    }

    void Display() {
        cout << title << " at (" << x << "," << y << ") "
            << width << "x" << height << " " << color
            << " Vis:" << isVisible << " Border:" << hasBorder << endl;
    }

    string toString() {
        return title + "(" + to_string(x) + "," + to_string(y) + ") "
            + to_string(width) + "x" + to_string(height) + " " + color;
    }

    void moveHorizontal(int dx) {
        if (isWithinScreen(x + dx, y, width, height)) x += dx;
    }

    void moveVertical(int dy) {
        if (isWithinScreen(x, y + dy, width, height)) y += dy;
    }

    void resize(int w, int h) {
        if (isWithinScreen(x, y, w, h)) { width = w; height = h; }
    }

    void setColor(string c) { color = c; }
    void setVisible(bool v) { isVisible = v; }
    void setBorder(bool b) { hasBorder = b; }
};

int main() {
    ModelWindow w;
    w.Init();
    w.Display();
    w.moveHorizontal(50);
    w.resize(200, 150);
    w.setColor("blue");
    w.Display();
    return 0;
}