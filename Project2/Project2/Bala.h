#include "math.h"

using namespace System::Drawing;

class Bala
{
private:
	int indice;
	double x;
	double y;
	double dx;
	double dy;
	double potencia;
	int w;
	int h;
	double radioexplosion;
	int damage;
	int tipo;
	bool estado;
	double tiempo;
	double angulo;
	int tipoCarro;
	
	


public:
	Bala(int px, int py, int pw, int ph, int pdx, int pdy);
	~Bala();
	void Pintar(BufferedGraphics^g, Bitmap ^gimg);
	void Mover(Bitmap^fondoDes, BufferedGraphics^g,char direccion, Bitmap ^gimg);
	bool PixelColision(Bitmap^fondoDes, int mx, int my);
	void RellenarCirculo(double centrox,double centroy,double radio,int wForm,int hForm,Bitmap^fondDestroy);

	//Metodos Set
	void setX(int nuevo);
	void setY(int nuevo);
	void setW(int nuevo);
	void setH(int nuevo);
	void setDx(int nuevo);
	void setDy(int nuevo);
	void setEstado(bool nuevo);
	void setPotencia(double nuevo);
	void setAngulo(double nuevo);
	void setTipoCarro(int nuevo);

	//Metodos Get
	int getX();
	int getY();
	int getW();
	int getH();
	int getDx();
	int getDy();
	int getTipoCarro();
	bool getEstado();
	double getPotencia();
	double getAngulo();
};

