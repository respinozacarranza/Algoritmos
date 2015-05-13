#include "Bala.h"


Bala::Bala(int px, int py, int pw, int ph, int pdx, int pdy)
{
	x = px;
	y = py;
	w = pw;
	h = ph;
	dx = pdx;
	dy = pdy;
	tiempo=0.1;
	estado = false;
	indice = 0;
}


Bala::~Bala()
{
}
void Bala::Pintar(BufferedGraphics^g, Bitmap ^gimg)
{


	
	Rectangle porcion = Rectangle(indice*w,0,w,h);

	Rectangle porcionPantalla = Rectangle(x,y,w,h);


	g->Graphics->DrawImage(gimg,porcionPantalla,(double)indice*w,0,w,h,GraphicsUnit::Pixel);

	
	if(tipoCarro==1)
	{
		indice++;
		if(indice>=5)
			indice=0;
	}
	if(tipoCarro==2)
	{
		indice++;
		if(indice>=10)
			indice=0;
	}
	if(tipoCarro==3)
	{
		indice++;
		if(indice>=6)
			indice=0;
	}
	if(tipoCarro==4)
	{
		indice++;
		if(indice>=15)
			indice=0;
	}
	if(tipoCarro==5)
	{
		indice++;
		if(indice>=15)
			indice=0;
	}
	if(tipoCarro==6)
	{
		indice++;
		if(indice>=5)
			indice=0;
	}
	if(tipoCarro==7)
	{
		indice++;
		if(indice>=20)
			indice=0;
	}
	if(tipoCarro==8)
	{
		indice++;
		if(indice>=8)
			indice=0;
	}
	if(tipoCarro==9)
	{
		indice++;
		if(indice>=20)
			indice=0;
	}
	if(tipoCarro==10)
	{
		indice++;
		if(indice>=10)
			indice=0;
	}






}
bool Bala::PixelColision(Bitmap^fondoDes, int mx, int my)
{
	

	if (fondoDes->GetPixel(x + mx, y + my).A != 0)
	{
		return true;
	}

	return false;



}

void Bala::Mover(Bitmap^fondoDes, BufferedGraphics^g,char direccion, Bitmap ^gimg)
{

		if (x <= 0 || x + w >= g->Graphics->VisibleClipBounds.Width)
		{
			estado = false;
			potencia=0.0;
			tiempo=0.1;
			return;
		}

		if (y <= 0 || y + h >= g->Graphics->VisibleClipBounds.Height)
		{
			estado = false;
			potencia=0.0;
			tiempo=0.1;
			return;
		}

		if(PixelColision(fondoDes,0,0) || PixelColision(fondoDes,w,0) || PixelColision(fondoDes,0,h) || PixelColision(fondoDes,w,h))
		{
			estado=false;
			tiempo=0.1;
			potencia=0.0;
			RellenarCirculo(x+w/2,y+h/2,50.0,g->Graphics->VisibleClipBounds.Width,g->Graphics->VisibleClipBounds.Height,fondoDes);
			return;

			
		}
	
		if(direccion=='i')
		{
			/*x -= 10.0*tiempo*cos(60.0*3.14/180.0);
			y -= 10.0*tiempo*sin(60.0*3.14/180.0)-0.5*9.81*tiempo*tiempo;*/

			/*x -= potencia*tiempo*cos(60.0*3.14/180.0);
			y -= potencia*tiempo*sin(60.0*3.14/180.0)-0.5*9.81*tiempo*tiempo;*/

			x -= potencia*tiempo*cos(angulo);
			y -= potencia*tiempo*sin(angulo)-0.5*9.81*tiempo*tiempo;
		}
		else
		{
			/*x += 10.0*tiempo*cos(60.0*3.14/180.0);
			y -= 10.0*tiempo*sin(60.0*3.14/180.0)-0.5*9.81*tiempo*tiempo;*/

			/*x += potencia*tiempo*cos(60.0*3.14/180.0);
			y -= potencia*tiempo*sin(60.0*3.14/180.0)-0.5*9.81*tiempo*tiempo;*/

			x += potencia*tiempo*cos(angulo);
			y -= potencia*tiempo*sin(angulo)-0.5*9.81*tiempo*tiempo;
		}

		tiempo+=0.1;
		Pintar(g,gimg);

		
	

}
void Bala::RellenarCirculo(double centrox,double centroy,double radio,int wForm,int hForm,Bitmap^fondDestroy)
{

	if(radio<0)
		return;

	double x,y;
				
	for(double angle=0.0 ; angle<=2.0*3.14 ; angle+=0.001)
	{
		 x=centrox+radio*cos(angle);
		 y=centroy+radio*sin(angle);

		if(x<0 || x>=wForm || y<0 || y>=hForm)
			continue;
		
		fondDestroy->SetPixel(x,y,Color::Transparent);
					 
	}

				



	RellenarCirculo(centrox,centroy,radio-1.0,wForm,hForm,fondDestroy);


}

void Bala::setX(int nuevo)
{
	x = nuevo;
}
void Bala::setY(int nuevo)
{
	y = nuevo;
}
void Bala::setW(int nuevo)
{
	w = nuevo;
}
void Bala::setH(int nuevo)
{
	h = nuevo;
}
void Bala::setDx(int nuevo)
{
	dx = nuevo;
}
void Bala::setDy(int nuevo)
{
	dy = nuevo;
}
void Bala::setPotencia(double nuevo)
{
	potencia=nuevo;
}
void Bala::setAngulo(double nuevo)
{
	angulo=nuevo;
}
void Bala::setTipoCarro(int nuevo)
{
	tipoCarro = nuevo;
}


int Bala::getX()
{
	return x;
}
int Bala::getY()
{
	return y;
}
int Bala::getW()
{
	return w;
}
int Bala::getH()
{
	return h;
}
int Bala::getDx()
{
	return dx;
}
int Bala::getDy()
{
	return dy;
}
bool Bala::getEstado()
{
	return estado;
}

void Bala::setEstado(bool nuevo)
{
	estado = nuevo;
}
double Bala::getPotencia()
{
	return potencia;
}
double Bala::getAngulo()
{
	return angulo;
}
int Bala::getTipoCarro()
{
	return tipoCarro;
}

