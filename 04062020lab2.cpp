/*
Реализуйте класс “Точка”. Необходимо хранить координаты x, y, z в переменных-членах класса.
Реализуйте функции-члены класса для ввода данных, вывода данных,
реализуйте аксессоры для доступа к переменным-членам,
реализуйте сохранение в файл и загрузку данных из файла.
*/
#include <iostream>
using namespace std;
class Point {
private:
	int m_x;
	int m_y;
	int m_z;
public:
	Point();
	~Point();
	inline void SetX(int d);
	inline void SetY(int d);
	inline void SetZ(int d);
	inline int GetX();
	inline inline int GetY();
	inline int GetZ();
	void SaveToFile();
	void ReadFromFile();
};
Point::Point() { m_x = 0; m_y = 0; m_z = 0; }
Point::~Point() {}
inline void Point::SetX(int d) { m_x = d; }
inline void Point::SetY(int d) { m_y = d; }
inline void Point::SetZ(int d) { m_z = d; }
inline int Point::GetX() { return m_x; }
inline int Point::GetY() { return m_y; }
inline int Point::GetZ() { return m_z; }
void Point::SaveToFile() {
	FILE* fs = NULL;
	auto error = fopen_s(&fs, "1.bin", "wb");
	if (fs == 0) { cout << "I cannot create the file"; return; exit(error); }
	fwrite(&m_x, sizeof(int), 1, fs);
	fwrite(&m_y, sizeof(int), 1, fs);
	fwrite(&m_z, sizeof(int), 1, fs);
	fclose(fs);
}
void Point::ReadFromFile() {
	FILE* fs = NULL;
	auto error = fopen_s(&fs, "1.bin", "rb");
	if (fs == 0) { cout << "I cannot create the file"; return; exit(error); }
	fread(this, sizeof(Point), 1, fs);
	fclose(fs);
}
int main() {
	Point a;
	a.SetX(1);
	a.SetY(2);
	a.SetZ(3);
	a.SaveToFile();
	a.ReadFromFile();
	cout << "x = " << a.GetX() << ", y = " << a.GetY() << ", z = " << a.GetZ() << endl;
}