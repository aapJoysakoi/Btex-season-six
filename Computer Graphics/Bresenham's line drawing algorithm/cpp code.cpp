#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    vector<pair<int, int>> points;
    while (true) {
        points.push_back(make_pair(x1, y1));
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    return points;
}

int main() {
    int x1 = 10, y1 = 20;
    int x2 = 400, y2 = 300;
    vector<pair<int, int>> points = drawLine(x1, y1, x2, y2);

    // Print the points
    for (auto& p : points) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
