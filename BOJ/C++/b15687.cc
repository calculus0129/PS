#include <bits/stdc++.h>
using namespace std;

class Rectangle {
    int width, height;
    public:
    Rectangle(int width, int height):
        width(width), height{height} {}
    int get_width() const {
        return width;
    }
    int get_height() const {
        return height;
    }
    void set_width(int width) {
        if(width <= 0 || width > 1000) return;
        this->width = width;
    }
    void set_height(int height) {
        if(height <= 0 || height > 2000) return;
        this->height = height;
    }
    int area() const {
        return width * height;
    }
    int perimeter() const {
        return (width + height) << 1;
    }
    bool is_square() const {
        return width == height;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    return 0;
}