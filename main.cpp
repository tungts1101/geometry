#include <iostream>
#include <list>

using namespace std;

#define X 0
#define Y 1
#define DIM 2

typedef int tPointi[DIM];

typedef struct tVertexStructure tsVertex;

struct tVertexStructure {
    int vnum;
    tPointi v;
    bool ear;
};

list<tsVertex> vertices;

int Area2(tPointi a, tPointi b, tPointi c) {
    return (b[X] - a[X]) * (c[Y] - a[Y]) - (c[X] - a[X])*(b[Y] - a[Y]);
}

int AreaPoly2(void) {
    int sum = 0;

    auto p = vertices.begin();
    auto a = next(p);
    do {
        sum += Area2(p->v, a->v, next(a)->v);
        a = next(a);
    } while(next(a) != p);

    return sum;
}

int main() {
    tsVertex a{0, {0,0}, false};
    tsVertex b{1, {10,0}, false};
    tsVertex c{2, {10,10}, false};
    tsVertex d{3, {0,10}, false};

    vertices.push_back(a);
    vertices.push_back(b);
    vertices.push_back(c);
    vertices.push_back(d);
    cout << AreaPoly2() << '\n';
}