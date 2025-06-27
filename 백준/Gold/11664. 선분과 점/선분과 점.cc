#include <iostream>
#include <cmath>
using namespace std;

struct Vec3 {
    double x, y, z;

    Vec3 operator-(const Vec3& other) const {
        return { x - other.x, y - other.y, z - other.z };
    }

    Vec3 operator+(const Vec3& other) const {
        return { x + other.x, y + other.y, z + other.z };
    }

    Vec3 operator*(double scalar) const {
        return { x * scalar, y * scalar, z * scalar };
    }

    double dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    double norm() const {
        return sqrt(x * x + y * y + z * z);
    }
};

double DistancePointToSegment(Vec3 A, Vec3 B, Vec3 P) {
    Vec3 AB = B - A;
    Vec3 AP = P - A;

    double ab2 = AB.dot(AB);
    double t = AP.dot(AB) / ab2;

    if (t < 0.0) return (P - A).norm();
    if (t > 1.0) return (P - B).norm();

    Vec3 projection = A + AB * t;
    return (P - projection).norm();
}


int main() {
	double ax, ay, az, bx, by, bz, cx, cy, cz;
	cin >> ax >> ay >> az;
	cin >> bx >> by >> bz;
	cin >> cx >> cy >> cz;
    Vec3 A = { ax,ay,az };
    Vec3 B = { bx,by,bz };
    Vec3 P = { cx,cy,cz };

    cout.fixed;
    cout.precision(10);
    cout << DistancePointToSegment(A, B, P);

	return 0;
}