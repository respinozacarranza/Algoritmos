#pragma once
#include "Bala.h"
#include <vector>

using namespace std;
class Carro
{
private:
	double x;
	double y;
	double dx;
	double dy;
	double h;
	double w;
	double wFlechaAngulo;
	double hFlechaAngulo;
	int x0;
	int y0;
	int angulo;
	int gas;
	Bala *bala;
	int hp;
	double delay;
	int tipo;
	int indice;
	bool estado;
	bool aire;
	char direccion;
	int XPixelColi;
	int YPixelColi;
	bool rotar;
	double anguloDisparo;
	vector<pair<int,int>> vecPosis;
	vector<pair<int,int>> vecPosisFA;
	
	int dameYAdyacentColi(int pixelMedioCarroX, int pixelMedioCarroY,int hForm,Bitmap^fondDestroy);
	double Pitagoras(double x1, double y1, double x2, double y2);
	double ValorAbsoluto(double dato);
	double round(double number);
	bool _Mirror(Bitmap ^img,int inicio,double fin,int height,int weight);
public:
	Carro(double x, double y, int tipo, double w, double h,double wFlechaAngulo,double hFlechaAngulo, Bitmap ^gimg);
	Carro(double x, double y, int tipo, double w, double h,double wFlechaAngulo,double hFlechaAngulo);
	~Carro();
	
	void Pintar(Bitmap^fondDestroy,BufferedGraphics ^g, Bitmap ^img,Bitmap ^imgFlechaAngulo, Bitmap ^gimg);
	void Pintar(BufferedGraphics ^g, Bitmap ^img);
	void Mover(int pDx,int pDy,int wFormu,int hFormu,char direc,Bitmap^ fondoDestroy);
	void Disparar(double poder);
	void mirrorLeftRight(Bitmap ^img);
	bool PixelColision(Bitmap^fondoDes,int mx,int my);	
	void ActualizarVerticesRectangulo();
	void Rotar(Bitmap^ fondoDestroy,int hForm);
	void RotarRectangulo(double angle);
	bool EstaDisparando();
	void RotarAngulo(double angle);
	double get_X();
	double get_Y();
	double get_W();
	double get_H();
	int get_tipo();
	int get_direccion();
	bool getAire();
	double get_anguloDisparo();
	void set_X(int nuevo);
	void set_Y(int nuevo);
	void set_W(int nuevo);
	void set_H(int nuevo);
	void set_tipo(int nuevo);
	void set_direccion(char nuevo);
	void set_aire(bool nuevo);
	void set_anguloDisparo(double nuevo);



};

