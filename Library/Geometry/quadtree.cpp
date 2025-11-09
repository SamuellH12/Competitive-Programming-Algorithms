#include <bits/stdc++.h> //LATEX_IGNORED_LINE
using namespace std;

const int MXN = 1e5+100;

struct Point {
    int x, y;

    bool const operator<(const Point& o) const {
        return make_tuple(x, y) < make_tuple(o.x, o.y);
    }
};

struct AABB {
    int x1, y1, x2, y2;

    AABB() : x1(0), y1(0), x2(MXN), y2(MXN) {} 
    AABB(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    bool intersects(const AABB& other) const {
        bool overlap_x = (x1 <= other.x2) && (x2 >= other.x1);
        bool overlap_y = (y1 <= other.y2) && (y2 >= other.y1);
        return overlap_x && overlap_y;
    }

    bool contains(int x, int y) const {
        return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
    }

    array<AABB, 4> subdivide() const {
        int x_center = x1 + (x2 - x1) / 2;
        int y_center = y1 + (y2 - y1) / 2;
        return {
            AABB{x1, y1, x_center, y_center},     // NW
            AABB{x_center, y1, x2, y_center},     // NE
            AABB{x1, y_center, x_center, y2},     // SW
            AABB{x_center, y_center, x2, y2}      // SE
        };
    }
};


struct Circle {
    Point c;
    int r, w;
    AABB box;

    Circle(Point c, int r, int w) 
        : c(c), r(r), w(w), box(c.x - r, c.y - r, c.x + r, c.y + r) {}

    bool const operator<(const Circle& o) const {
        return make_tuple(c.x, c.y, r) < make_tuple(o.c.x, o.c.y, o.r);
    }
};

struct Square {
    Point p1, p2;
    int w;
    AABB box;

    Square(Point p1, Point p2)
        : p1(p1), p2(p2), box(min(p1.x, p2.x), min(p1.y, p2.y), 
                              max(p1.x, p2.x), max(p1.y, p2.y)) {}

    bool const operator<(const Square& o) const {
        return make_tuple(p1, p2) < make_tuple(o.p1, o.p2);
    }
};

struct Triangle {
    Point p1, p2, p3;
    int w;
    AABB box;

    Triangle(Point p1, Point p2, Point p3)
        : p1(p1), p2(p2), p3(p3),
          box(min({p1.x, p2.x, p3.x}), min({p1.y, p2.y, p3.y}), max({p1.x, p2.x, p3.x}), max({p1.y, p2.y, p3.y})) {}

    bool const operator<(const Triangle& o) const {
        return make_tuple(p1, p2, p3) < make_tuple(o.p1, o.p2, o.p3);
    }
};

template <typename T>
class Quadtree {
  public:
    static const int MIN_OBJECTS = 8;
    static const int MAX_DEPTH = 16;

    Quadtree(const AABB& root_bounds, const vector<T>& all_objects) 
        : bounds(root_bounds), depth(0) {
        
        vector<const T*> object_ptrs;
        object_ptrs.reserve(all_objects.size());
        for (const auto& obj : all_objects) {
            object_ptrs.push_back(&obj);
        }
        
        build(object_ptrs);
    }

    const vector<const T*>& query(int x, int y) const {
        const Quadtree* node = this;

        while (node->is_branch) {
            int child_index = node->get_child_index(x, y);
            if (child_index == -1) break;
            node = node->children[child_index].get();
        }
        
        return node->objects;
    }

  private:
    AABB bounds;
    int depth;
    bool is_branch = false;
    int x_center, y_center;

    array<unique_ptr<Quadtree<T>>, 4> children;

    vector<const T*> objects;

    Quadtree(const AABB& box, int d) : bounds(box), depth(d) {}

    void build(const vector<const T*>& parent_objects) {
        x_center = bounds.x1 + (bounds.x2 - bounds.x1) / 2;
        y_center = bounds.y1 + (bounds.y2 - bounds.y1) / 2;

        for (const T* obj : parent_objects) {
            if (bounds.intersects(obj->box)) {
                objects.push_back(obj);
            }
        }

        if (objects.size() > MIN_OBJECTS && depth < MAX_DEPTH) {
            is_branch = true;
            auto child_bounds = bounds.subdivide();
            
            for (int i = 0; i < 4; ++i) {
                children[i] = unique_ptr<Quadtree<T>>(new Quadtree<T>(child_bounds[i], depth + 1));
                children[i]->build(objects);
            }
            
            objects.clear();
        }
    }

    int get_child_index(int x, int y) const {
        if (y <= y_center) return (x <= x_center) ? 0 : 1; // 0 (NW) ou 1 (NE)
        else return (x <= x_center) ? 2 : 3; // 2 (SW) ou 3 (SE)   
    }
};
