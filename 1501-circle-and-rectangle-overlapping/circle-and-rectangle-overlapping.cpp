#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the point on/inside the rectangle closest to the circle center
        int nearestX = std::max(x1, std::min(xCenter, x2));
        int nearestY = std::max(y1, std::min(yCenter, y2));

        // Calculate squared distance from closest point to circle center
        int dx = xCenter - nearestX;
        int dy = yCenter - nearestY;

        return (dx * dx + dy * dy) <= (radius * radius);
    }
};