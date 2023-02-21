#include <iostream>
using namespace std;

class Wheel {
	int R;
public:
	Wheel(int r) : R(r) {};
	int GetR() { return R; }
	void SetR(int r) { R = r; }
};

class Engine {
	double Volume;
public:
	Engine(double v) : Volume(v) {};
	double GetVolume() { return Volume; }
	void SetVolume(double r) { Volume = r; }
};

class Door {
	int N;
public:
	Door(int n) : N(n) {};
	int GetN() { return N; }
	void SetN(int n) { N = n; }
	void Open() { cout << "Äâåðè îòêðûëèñü" << endl; }
	void Close() { cout << "Äâåðè çàêðûëèñü" << endl; }
};

class Car : public Wheel, public Engine, public Door {
	string make, model;
public:
	Car(string make, string model, int r, double v, int n) : make(make), model(model), Wheel(r), Engine(v), Door(n) {};
	string GetMake() { return make; };
	string GetModel() { return model; };
	void Drive() {
		cout << "красный" << endl;
	}
};


int main() {

	Car car("Toyota", "Corolla", 132, 1.8, 3);

	cout << "Марка и модель машины: " << car.GetMake() << " " << car.GetModel() << endl;
	cout << "Двигатель: " << car.GetVolume() << endl;
	cout << "Цена (млн): " << car.GetN() << endl;
	cout << "Мощность двигателя (л/с): " << car.GetR() << endl;
	cout << "Цвет машины: ";
	car.Drive();

	cout << endl;

	return 0;
}