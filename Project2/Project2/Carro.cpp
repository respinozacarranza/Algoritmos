#include "Carro.h"


Carro::Carro(double x, double y, int tipo, double w, double h,double wFlechaAngulo,double hFlechaAngulo, Bitmap ^gimg)
{
	
	this->x = x;
	this->y = y;
	this ->tipo = tipo;
	this->w = w;
	this->h = h;
	this->wFlechaAngulo=wFlechaAngulo;
	this->hFlechaAngulo=hFlechaAngulo;
	direccion='i';
	indice=0;
	estado=true;
	aire=true;
	vecPosis=vector<pair<int,int>>(3);
	vecPosisFA=vector<pair<int,int>>(3);
	ActualizarVerticesRectangulo();
	bala= new Bala(x,y,gimg->Width/5,gimg->Height,0,0);
	bala->setTipoCarro(tipo);
	XPixelColi=YPixelColi=0;	
	anguloDisparo=0.0;
	/*x0=ValorAbsoluto( (vecPosis[1].first+vecPosis[2].first)/2);

	y0=ValorAbsoluto( (vecPosis[1].second+vecPosis[2].second)/2);*/
	
	

}

Carro::Carro(double x, double y, int tipo, double w, double h,double wFlechaAngulo,double hFlechaAngulo)
{
	
	this->x = x;
	this->y = y;
	this ->tipo = tipo;
	this->w = w;
	this->h = h;
	this->wFlechaAngulo=wFlechaAngulo;
	this->hFlechaAngulo=hFlechaAngulo;
	direccion='i';
	indice=0;
	estado=true;
	aire=true;
	vecPosis=vector<pair<int,int>>(3);
	vecPosisFA=vector<pair<int,int>>(3);
	ActualizarVerticesRectangulo();
	
	XPixelColi=YPixelColi=0;	
	anguloDisparo=0.0;
	/*x0=ValorAbsoluto( (vecPosis[1].first+vecPosis[2].first)/2);
	y0=ValorAbsoluto( (vecPosis[1].second+vecPosis[2].second)/2);*/
	
	

}


Carro::~Carro()
{

}

void Carro::Pintar(Bitmap^fondDestroy,BufferedGraphics ^g, Bitmap ^img,Bitmap ^imgFlechaAngulo, Bitmap ^gimg)
{
	Rectangle porcionPantalla = Rectangle(x,y,w,h);
	
	array<Point>^ arrpoi=gcnew array<Point>(3);
	array<Point>^ arrpoiFlechaAngulo=gcnew array<Point>(3);


	for(int i=0 ; i<3 ; i++)
	{
		arrpoi[i].X=vecPosis[i].first;
		arrpoi[i].Y=vecPosis[i].second;
		arrpoiFlechaAngulo[i].X=vecPosisFA[i].first;
		arrpoiFlechaAngulo[i].Y=vecPosisFA[i].second;
	}


	/*g->Graphics->DrawImage(img,porcionPantalla,(double)indice*w,0,w,h,GraphicsUnit::Pixel);*/
	Rectangle porcion = Rectangle(indice*w,0,w,h);
	g->Graphics->DrawImage(img,arrpoi,porcion,GraphicsUnit::Pixel);
	//g->Graphics->DrawString("XColision:"+XPixelColi.ToString(),gcnew Font("Arial",50),Brushes::Black,50,50);
	//g->Graphics->DrawString("YColision:"+YPixelColi.ToString(),gcnew Font("Arial",50),Brushes::Black,50,100);
	//g->Graphics->DrawString("X:"+x.ToString(),gcnew Font("Arial",50),Brushes::Black,50,150);
	//g->Graphics->DrawString("Y:"+y.ToString(),gcnew Font("Arial",50),Brushes::Black,50,200);
	//g->Graphics->FillEllipse(Brushes::Black,XPixelColi,YPixelColi,10,10);
	//g->Graphics->DrawRectangle(gcnew Pen(Color::Black),(int)x,(int)y,(int)w,(int)h);
	g->Graphics->DrawImage(imgFlechaAngulo,arrpoiFlechaAngulo);

	
	

	indice++;
	if(indice>=20)
		indice=0;

	if(bala->getEstado())
	{
		
		bala->Mover(fondDestroy,g,direccion,gimg);
		
	}

	delete arrpoi;
	

}
void Carro::Pintar(BufferedGraphics ^g, Bitmap ^img)
{



	Rectangle porcion = Rectangle(indice*w,0,w,h);

	Rectangle porcionPantalla = Rectangle(x,y,w*2,h*2);


	g->Graphics->DrawImage(img,porcionPantalla,(double)indice*w,0,w,h,GraphicsUnit::Pixel);

	

	indice++;
	if(indice>=20)
		indice=0;

	
}
void Carro::Mover(int pDx,int pDy,int wFormu,int hFormu,char direc,Bitmap^ fondoDestroy)
{
	if(bala->getEstado())
		return;

	if(x+pDx<0 ||  x+w+pDx>=wFormu)
	{
			
		return;
	}
		

	if(y+pDy<0 || y+h+pDy>=hFormu)
	{		
		return;
	}


	if(PixelColision(fondoDestroy,0,h) || PixelColision(fondoDestroy,w,h))
	{
		if(aire)
			aire=false;	
	}
	else
	{
		aire=true;
		rotar=false;
	}

	
	if(PixelColision(fondoDestroy,0,h/2))
	{
		/*if(direccion=='i')
			pDx=0;*/
		pDy=-7;
		

		
	}

	if(PixelColision(fondoDestroy,w,h/2))
	{
		/*if(direccion=='d')
			pDx=0;*/

			pDy=-7;

	}

	
	

	direccion=direc;


	x+=pDx;
	y+=pDy;

	
	if(aire)
		ActualizarVerticesRectangulo();
	else
	{
		ActualizarVerticesRectangulo();
		Rotar(fondoDestroy,hFormu);
	}

	/*x0=ValorAbsoluto( (vecPosis[1].first+vecPosis[2].first)/2);
	y0=ValorAbsoluto( (vecPosis[1].second+vecPosis[2].second)/2);*/
	
	
}
void Carro::Disparar(double poder)
{
	/*if(EstaDisparando())
		return;*/

	if(direccion=='i')
	{
		bala->setX(x);
		bala->setY(y);
	}
	else
	{
		/*bala->setX((x+w)-bala->getW());*/
		bala->setX((x+w));
		bala->setY(y);
	}

	bala->setPotencia(poder/60.0);
	bala->setEstado(true);
	bala->setAngulo(anguloDisparo);
}
bool Carro::PixelColision(Bitmap^fondoDes,int mx,int my)
{
	
	if(fondoDes->GetPixel(x+mx,y+my).A!=0)
	{
		XPixelColi=x+mx;
		YPixelColi=y+my;
		return true;
	}

	return false;

}
void Carro::ActualizarVerticesRectangulo()
{

		vecPosis[0].first=x;
		vecPosis[0].second=y;
		vecPosis[1].first=x+w;
		vecPosis[1].second=y;
		vecPosis[2].first=x;
		vecPosis[2].second=y+h;

		if(direccion=='d')
		{

			vecPosisFA[0].first=x+w;
			vecPosisFA[0].second=y;
			vecPosisFA[1].first=x+w+wFlechaAngulo;
			vecPosisFA[1].second=y;
			vecPosisFA[2].first=x+w;
			vecPosisFA[2].second=y+hFlechaAngulo;
		}
		else
		{
			vecPosisFA[0].first=x-wFlechaAngulo;
			vecPosisFA[0].second=y;
			vecPosisFA[1].first=x;
			vecPosisFA[1].second=y;
			vecPosisFA[2].first=x-wFlechaAngulo;
			vecPosisFA[2].second=y+hFlechaAngulo;
		}
				
		

		/* x0=ValorAbsoluto( (vecPosis[1].first+vecPosis[2].first)/2);
		 y0=ValorAbsoluto( (vecPosis[1].second+vecPosis[2].second)/2);*/
	

	
				 
}
void Carro::Rotar(Bitmap^ fondoDestroy,int hForm)
{
	
	if(XPixelColi > x + w / 2)
		{
			
			double CatetoAd = Pitagoras(XPixelColi, YPixelColi, x, y + h);
			double CatetoOp = Pitagoras(x , y + h, x, dameYAdyacentColi(x,y+h,hForm,fondoDestroy));
								
			double angulo= atan2(CatetoOp,CatetoAd);

			
			RotarRectangulo(angulo);
			RotarAngulo(angulo);	
			if(direccion=='d')
			RotarAngulo(anguloDisparo);
			else
			RotarAngulo(anguloDisparo*-1);

			



			

		}
		else
			if(XPixelColi<x+w/2)
		{
			
			double CatetoAd = Pitagoras(XPixelColi, YPixelColi, x + w, y + h);
			double CatetoOp = Pitagoras(x + w, y + h, x + w, dameYAdyacentColi(x+w,y+h,hForm,fondoDestroy));
			double angulo= atan2(CatetoOp,CatetoAd)*-1; 
			


			RotarRectangulo(angulo);			
			RotarAngulo(angulo);
			if(direccion=='i')
			RotarAngulo(anguloDisparo*-1);
			else
				RotarAngulo(anguloDisparo);


			

		}

	

}
void Carro::RotarRectangulo(double angle)
{
				pair<int,int> aux;

				/*int x0,y0;*/

				x0=ValorAbsoluto( (vecPosis[1].first+vecPosis[2].first)/2);
				y0=ValorAbsoluto( (vecPosis[1].second+vecPosis[2].second)/2);

				aux=vecPosis[0];

				aux.first=x0+(vecPosis[0].first-x0)*cos(angle)+(vecPosis[0].second-y0)*sin(angle);
				aux.second=y0-(vecPosis[0].first-x0)*sin(angle)+(vecPosis[0].second- y0)*cos(angle);
				vecPosis[0]=aux;

				/*x=aux.first;
				y=aux.second;*/

				aux=vecPosis[1];

				aux.first=x0+(vecPosis[1].first-x0)*cos(angle)+(vecPosis[1].second-y0)*sin(angle);
				aux.second=y0-(vecPosis[1].first-x0)*sin(angle)+(vecPosis[1].second-y0)*cos(angle);
				vecPosis[1]=aux;

				aux=vecPosis[2];

				aux.first=x0+(vecPosis[2].first-x0)*cos(angle)+(vecPosis[2].second-y0)*sin(angle);
				aux.second=y0-(vecPosis[2].first-x0)*sin(angle)+(vecPosis[2].second-y0)*cos(angle);
				vecPosis[2]=aux;

				

}
double Carro::ValorAbsoluto(double dato)
{
	if(dato<0)
		return dato*-1;
	else
		return dato;
}
 double Carro::Pitagoras(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
 int Carro::dameYAdyacentColi(int pixelMedioCarroX, int pixelMedioCarroY,int hForm,Bitmap^fondDestroy)
{
	while (true)
	{
		if (pixelMedioCarroY >= hForm)
			return -1;
		/*if (bomb->PixelColision(fondDestroy, bomb->getX + bomb->getW / 2, bomb->getY() + bomb->getH)*/

		/*if (bomb->PixelColision(fondDestroy, pixelMedioCarroX, pixelMedioCarroY))*/
			if(fondDestroy->GetPixel(pixelMedioCarroX,pixelMedioCarroY).A!=0)
			return pixelMedioCarroY;

		pixelMedioCarroY++;
	}
}
bool Carro::EstaDisparando()
{
	return bala->getEstado();
}
double Carro::round(double number)
{
	return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}
void Carro::RotarAngulo(double angle)
{
		double x0f;
		double y0f;

	if(direccion=='d')
	{
		x0f=x+w;
		y0f=y+hFlechaAngulo/2;

	}
	else
	{
		x0f=x;
		y0f=y+hFlechaAngulo/2;
		/*angle*=-1.0;*/
	}

		pair<int,int> aux;
			  
				 
		aux=vecPosisFA[0];

		double aux1=x0f+((double)vecPosisFA[0].first-x0f)*cos(angle)+((double)vecPosisFA[0].second-y0f)*sin(angle);
		double aux2=y0f-((double)vecPosisFA[0].first-x0f)*sin(angle)+((double)vecPosisFA[0].second-y0f)*cos(angle);

		aux.first=round(x0f+((double)vecPosisFA[0].first-x0f)*cos(angle)+((double)vecPosisFA[0].second-y0f)*sin(angle));
		aux.second=round(y0f-((double)vecPosisFA[0].first-x0f)*sin(angle)+((double)vecPosisFA[0].second-y0f)*cos(angle));
		vecPosisFA[0]=aux;

		aux=vecPosisFA[1];

		aux.first=round(x0f+((double)vecPosisFA[1].first-x0f)*cos(angle)+((double)vecPosisFA[1].second-y0f)*sin(angle));
		aux.second=round(y0f-((double)vecPosisFA[1].first-x0f)*sin(angle)+((double)vecPosisFA[1].second-y0f)*cos(angle));
		vecPosisFA[1]=aux;

		aux=vecPosisFA[2];

		aux.first=round(x0f+((double)vecPosisFA[2].first-x0f)*cos(angle)+((double)vecPosisFA[2].second-y0f)*sin(angle));
		aux.second=round(y0f-((double)vecPosisFA[2].first-x0f)*sin(angle)+((double)vecPosisFA[2].second-y0f)*cos(angle));
		vecPosisFA[2]=aux;

		/*x0fa=valorAbsoluto( (PoFlech[1].X+PoFlech[2].X)/2);
		y0fa=valorAbsoluto( (PoFlech[1].Y+PoFlech[2].Y)/2);*/
}
bool Carro::_Mirror(Bitmap ^img,int inicio,double fin,int height,int weight)
{
	

	for (int y = 0; y < height; y++) 
		for (int x = inicio; x < weight; x++) {
			img->SetPixel(x,y,img->GetPixel(img->Size.Width-((x-inicio)+1),y));
				
            }

		if(fin<=0.0)
			return true;

		_Mirror(img,inicio + fin,fin/2.0,height,weight);
			
	

}
void Carro::mirrorLeftRight(Bitmap ^img)
{

	Bitmap^bmp=gcnew Bitmap(img);

	for (int y = 0; y < img->Size.Height; y++) 
		for (int x = 0; x < img->Size.Width; x++) 
			img->SetPixel(x,y,bmp->GetPixel(bmp->Size.Width-(x+1),y));

			delete bmp;


	
	/*_Mirror(img,0,(double)img->Width/2.0,img->Height,img->Width);*/

	/*int a=img->Size.Height;

    for (int y = 0; y < img->Size.Height; y++) 
		for (int x = 0; x < img->Size.Width; x++) {
			img->SetPixel(x,y,img->GetPixel(img->Size.Width-(x+1),y));

			
            }

		for (int y = 0; y < img->Size.Height; y++) 
			for (int x = img->Size.Width/2; x < img->Size.Width; x++) {
				
				img->SetPixel(x,y,img->GetPixel(img->Size.Width-((x-img->Size.Width/2)+1),y));

			
            }*/
    

	
}

double Carro::get_X()
{
	return x;
}
double Carro::get_Y()
{
	return y;
}
double Carro::get_W()
{
	return w;
}
double Carro::get_H()
{
	return h;
}
int Carro::get_tipo()
{
	return tipo;
}
int Carro::get_direccion()
{
	return direccion;
}
bool Carro::getAire()
{
	return aire;
}
double Carro::get_anguloDisparo()
{
	return anguloDisparo;
}
void Carro::set_X(int nuevo)
{
	x=nuevo;
}
void Carro::set_Y(int nuevo)
{
	y=nuevo;
}
void Carro::set_W(int nuevo)
{
	w=nuevo;
}
void Carro::set_H(int nuevo)
{
	h=nuevo;
}
void Carro::set_tipo(int nuevo)
{
	tipo=nuevo;
}
void Carro::set_direccion(char nuevo)
{
	direccion=nuevo;
}
void Carro::set_aire(bool nuevo)
{
	aire=nuevo;
}
void Carro::set_anguloDisparo(double nuevo)
{
	anguloDisparo=nuevo;
}