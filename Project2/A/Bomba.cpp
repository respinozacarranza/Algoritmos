#include "Bomba.h"


Bomba::Bomba(int px,int py,int pw,int ph,int pdx,int pdy,int px0,int py0)
{
	x=px;
	y=py;
	w=pw;
	h=ph;
	/*dx=pdx;
	dy=pdy;*/
	XPixelColi=-1;
	YPixelColi=-1;
	x0=px0;
	y0=py0;
}

Bomba::~Bomba(void)
{
}
void Bomba::Pintar(Bitmap^bmp,array<Point>^vec,BufferedGraphics^g)
{
	
	/*g->Graphics->DrawRectangle(gcnew Pen(Brushes::Magenta),x,y,w,h);*/

	g->Graphics->DrawImage(bmp,vec);
}
bool Bomba::PixelColision(Bitmap^fondoDes,int mx,int my)
{
	/*if(fondoDes->GetPixel(x,y+my).A!=0)
	return true;

	if(fondoDes->GetPixel(x+mx,y).A!=0)
	return true;

	if(fondoDes->GetPixel(x,y).A!=0)
	return true;

	if(fondoDes->GetPixel(x+mx,y+my).A!=0)
	return true;*/

	if(fondoDes->GetPixel(x+mx,y+my).A!=0)
	{
		XPixelColi=x+mx;
		YPixelColi=y+my;
		return true;
	}

	return false;



}
void Bomba::PintarSprite(Bitmap^bmp,array<Point>^vec,BufferedGraphics^g)
{
	/*g->Graphics->DrawImage(bmp,Rectangle(0,0,w,h),indice*w,0,w,h*/
}

void Bomba::Mover(int pDX,int pDY,Bitmap^fondoDes)
{

	//dx=pDX;
	//dy=pDY;

	if(x+pDX<=0 ||  x+w+pDX>=fondoDes->Width)
	{
		
		
		return;
	}
		

	if(y+pDY<=0 || y+h+pDY>=fondoDes->Height)
	{
		
		return;
	}

	
	/*if(fondoDes->GetPixel(x,y+h+dy).A!=0)
		dy=0;
		
	if( fondoDes->GetPixel(x+w+dx,y).A!=0)
		dx=-0;*/
	
		

	x+=pDX;
	y+=pDY;
	
}
void Bomba::setX(int nuevo)
{
	x=nuevo;
}
void Bomba::setY(int nuevo)
{
	y=nuevo;
}
void Bomba::setW(int nuevo)
{
	w=nuevo;
}
void Bomba::setH(int nuevo)
{
	h=nuevo;
}
void Bomba::setDx(int nuevo)
{
	dx=nuevo;
}
void Bomba::setDy(int nuevo)
{
	dy=nuevo;
}
void Bomba::setXPixelColi(int nuevo)
{
	XPixelColi=nuevo;
}
void Bomba::setYPixelColi(int nuevo)
{
	YPixelColi=nuevo;
}
void Bomba::setX0(int nuevo)
{
	x0=nuevo;
}
void Bomba::setY0(int nuevo)
{
	y0=nuevo;
}
int Bomba::getX()
{
	return x;
}
int Bomba::getY()
{
	return y;
}
int Bomba::getW()
{
	return w;
}
int Bomba::getH()
{
	return h;
}
int Bomba::getDx()
{
	return dx;
}
int Bomba::getDy()
{
	return dy;
}
int Bomba::getXPixelColi()
{
	return XPixelColi;
}
int Bomba::getYPixelColi()
{
	return YPixelColi;
}
int Bomba::getX0()
{
	return x0;
}
int Bomba::getY0()
{
	return y0;
}
