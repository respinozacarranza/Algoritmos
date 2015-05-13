#pragma once

using namespace System::Drawing;
class Bomba
{
	int x;
	int y;
	int x0;
	int y0;
	int w;
	int h;
	int dx;
	int dy;
	int XPixelColi;
	int YPixelColi;


public:
	Bomba(int px,int py,int pw,int ph,int pdx,int pdy,int px0,int py0);
	~Bomba(void);
	void Pintar(Bitmap^bmp,array<Point>^vec,BufferedGraphics^g);
	void PintarSprite(Bitmap^bmp,array<Point>^vec,BufferedGraphics^g);
	void Mover(int pDX,int pDY,Bitmap^fondoDes);
	bool PixelColision(Bitmap^fondoDes,int mx,int my);
	void setX(int nuevo);
	void setY(int nuevo);
	void setW(int nuevo);
	void setH(int nuevo);
	void setDx(int nuevo);
	void setDy(int nuevo);
	void setXPixelColi(int nuevo);
	void setYPixelColi(int nuevo);
	void setX0(int nuevo);
	void setY0(int nuevo);
	int getX();
	int getY();
	int getW();
	int getH();
	int getDx();
	int getDy();
	int getXPixelColi();
	int getYPixelColi();
	int getX0();
	int getY0();



};

