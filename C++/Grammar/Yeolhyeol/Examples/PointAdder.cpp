#include <iostream>
using namespace std;

struct Point {
  int xpos;
  int ypos;

  void MovePos(int x, int y) {
    xpos += x;
    ypos += y;
  }
  void AddPoint(const Point& pos) {
    xpos += pos.xpos;
    ypos += pos.ypos;
  }
  void ShowPosition(void) {
    cout << '[' << xpos << ", " << ypos << ']' << endl;
  }
};

Point& PointAdder(const Point& p1, const Point& p2) {
  Point* tmpP = new Point;
  Point& tmpR = *tmpP;
  tmpR.xpos = p1.xpos + p2.xpos;
  tmpR.ypos = p1.ypos + p2.ypos;
  return tmpR;
}

int main(void) {
  Point pos1 = {12, 4};
  Point pos2 = {30, 40};

  pos1.MovePos(-7, 10);
  pos1.ShowPosition();

  pos1.AddPoint(pos2);
  pos1.ShowPosition();

  Point& pos3 = PointAdder(pos1, pos2);
  pos3.ShowPosition();
  return 0;
}