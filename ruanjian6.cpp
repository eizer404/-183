#include<iostream>
using namespace std;
class Vehicle
{
	public:
		Vehicle(int wl,double wh):wheels(wl),weight(wh){};
		void show()
		{
			cout<<"wheels:"<<wheels<<",weight:"<<weight<<endl;
		}
	protected:
		int wheels;
		double weight;
};
class Car:private Vehicle
{
	public:
		Car(int wl,double wh,int pl):Vehicle(wl,wh),passager_load(pl){};
		void show()
		{
			Vehicle::show();
			cout<<"passager_load:"<<passager_load<<endl;
		}
	private:
		int passager_load;
};
class Truck:private Vehicle
{
	public:
		Truck(int wl,double wh,int pl,double psl):Vehicle(wl,wh),passager_load(pl),payload(psl){};
		void show()
		{
			Vehicle::show();
			cout<<"passager_load:"<<passager_load<<endl;
			cout<<"payload:"<<payload<<endl;
		}
	private:
		int passager_load;
		double payload;
};
int main()
{
	Vehicle v1(4,200);
	v1.show();
	cout<<"===================="<<endl;
	Car c1(4,290,10);
	c1.show();
	cout<<"===================="<<endl;
	Truck t1(4,500,50,200);
	t1.show();
	return 0;
}
