#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> drawCircle(int xc, int yc, int r) {
    int x = r, y = 0;
    int points = 0;

    vector<pair<int, int>> result;

    // Initial decision parameter of region 1
    int d = 1 - r;

    // Plot the initial points in all octants
    for (points = 0; x > y; ++y) {
        // If the discriminant is negative, choose E
        if (d <= 0)
            d = d + 2 * y + 1;
        // Otherwise, choose SE
        else {
            x--;
            d = d + 2 * (y - x) + 1;
        }
        result.push_back(make_pair(xc + x, yc + y));
        result.push_back(make_pair(xc - x, yc + y));
        result.push_back(make_pair(xc + x, yc - y));
        result.push_back(make_pair(xc - x, yc - y));
        result.push_back(make_pair(xc + y, yc + x));
        result.push_back(make_pair(xc - y, yc + x));
        result.push_back(make_pair(xc + y, yc - x));
        result.push_back(make_pair(xc - y, yc - x));
    }

    return result;
}

int main() {
    int xc = 250, yc = 250; // Center of the circle
    int r = 150; // Radius of the circle

    vector<pair<int, int>> points = drawCircle(xc, yc, r);

    // Print the points
    for (auto& p : points) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
