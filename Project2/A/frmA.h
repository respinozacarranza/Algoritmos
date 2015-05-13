#pragma once
#include "Bomba.h"
#include <math.h>

namespace A {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmA
	/// </summary>
	public ref class frmA : public System::Windows::Forms::Form
	{
	public:
		frmA(void)
		{
			int a,b;
			a=Width;
			b=Height;
			barrIncre=0;			
			rotar=false;
			veca= gcnew array<Point>(3);
			PoFlech= gcnew array<Point>(3);
			anguloDisparar=0.0;
			fondo=gcnew Bitmap("background.png");
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~frmA()
		{
			/*delete bomb;*/
			delete fondo;
			delete fondDestroy;
			delete carro;
			delete flechaA;
			delete PoFlech;
			delete veca;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		Bomba* bomb;
		Bitmap^fondo;
		Bitmap^fondDestroy;
		Bitmap ^carro;
		Bitmap ^flechaA;
		int a,b;
		bool EstaEnAire;
		Rectangle rec;
		int barrIncre;
		 array<Point>^veca;
		 array<Point>^PoFlech;
		 double anguloDisparar;
		 bool rotar;
		 double x0f,y0f;
		 double x0fa,y0fa;
		

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
			
		
		
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &frmA::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(647, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(647, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 478);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 2;
			// 
			// frmA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 513);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmA";
			this->Text = L"frmA";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmA::frmA_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmA::frmA_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &frmA::frmA_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmA::frmA_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmA::frmA_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmA::frmA_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 Graphics^g= CreateGraphics();

				 

                BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
				espacioBuffer->MaximumBuffer = System::Drawing::Size( g->VisibleClipBounds.Width + 1, g->VisibleClipBounds.Height + 1 );
				BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Drawing::Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height));
				
		

			

					buffer->Graphics->DrawImage(fondo,0.0,0.0,g->VisibleClipBounds.Width,g->VisibleClipBounds.Height);
					buffer->Graphics->DrawImage(fondDestroy,0,0);


					if(!bomb->PixelColision(fondDestroy,bomb->getW(),bomb->getH()) && !bomb->PixelColision(fondDestroy,bomb->getW(),0) && !bomb->PixelColision(fondDestroy,0,0) && !bomb->PixelColision(fondDestroy,0,bomb->getH()))
					{
						
						EstaEnAire=true;	
						bomb->Mover(0,7,fondDestroy);
						rotar=true;

						ActualizarVerticesRectangulo(false,0);
						

					

					}
					else
					{
						EstaEnAire=false;

						if(rotar)
						{
							if (bomb->getXPixelColi() > bomb->getX() + bomb->getW() / 2)
							{
								/*double CatetoAd = Pitagoras(bomb->getXPixelColi(), bomb->getYPixelColi(), bomb->getX() + bomb->getW() / 2, bomb->getY() + bomb->getH());
								double CatetoOp = Pitagoras(bomb->getX() + bomb->getW() / 2, bomb->getY() + bomb->getH(), bomb->getX() + bomb->getW() / 2, dameYAdyacentColi(bomb->getX()+bomb->getW()/2,bomb->getY()+bomb->getH()));*/
								double CatetoAd = Pitagoras(bomb->getXPixelColi(), bomb->getYPixelColi(), bomb->getX(), bomb->getY() + bomb->getH());
								double CatetoOp = Pitagoras(bomb->getX() , bomb->getY() + bomb->getH(), bomb->getX(), dameYAdyacentColi(bomb->getX(),bomb->getY()+bomb->getH()));
								
								double angulo= atan2(CatetoOp,CatetoAd);

								ActualizarVerticesRectangulo(true,angulo);
								RotarAngulo(anguloDisparar*3.14159265359/180.0);

								/*RotarImagen(angulo);*/

							}
							else
							{
								/*double CatetoAd = Pitagoras(bomb->getXPixelColi(), bomb->getYPixelColi(), bomb->getX() + bomb->getW() / 2, bomb->getY() + bomb->getH() / 2);
								double CatetoOp = Pitagoras(bomb->getX() + bomb->getW() / 2, bomb->getY() + bomb->getH(), bomb->getX() + bomb->getW() / 2, dameYAdyacentColi(bomb->getX()+bomb->getW()/2,bomb->getY()+bomb->getH()));*/
								double CatetoAd = Pitagoras(bomb->getXPixelColi(), bomb->getYPixelColi(), bomb->getX() + bomb->getW(), bomb->getY() + bomb->getH());
								double CatetoOp = Pitagoras(bomb->getX() + bomb->getW(), bomb->getY() + bomb->getH(), bomb->getX() + bomb->getW(), dameYAdyacentColi(bomb->getX()+bomb->getW(),bomb->getY()+bomb->getH()));
								double angulo= atan2(CatetoOp,CatetoAd)*-1; 

								ActualizarVerticesRectangulo(true,angulo);
								

								

								/*RotarImagen(angulo);*/

							}

							rotar=false;
						}
						

						

					}

					/*Point* poi=  new Point(50,50);*/

					
					

					/*gimg->DrawImage(fondDestroy,Rectangle(0,0,g->VisibleClipBounds.Width,g->VisibleClipBounds.Height),0,0,fondDestroy->Width,fondDestroy->Height,GraphicsUnit::Pixel);*/
				/*	gimg->DrawImage(fondDestroy,0.0,0.0,fondDestroy->Width,fondDestroy->Height);*/
					

					
					

					

					/*gimg->Clear(Color::Black);*/

					
					
					
				/*	bomb->Mover(gimg,fondDestroy);*/


					bomb->Pintar(carro,veca,buffer);
					/*buffer->Graphics->DrawImage(flechaA,bomb->getX()+bomb->getW(),bomb->getY(),flechaA->Width,flechaA->Height);*/

					buffer->Graphics->DrawImage(flechaA,PoFlech);
					


					buffer->Graphics->FillEllipse(Brushes::Red,200,100,100,100);

					

					buffer->Graphics->FillRectangle(Brushes::Red,30,(int)g->VisibleClipBounds.Height-30,barrIncre,30);
					buffer->Graphics->FillEllipse(Brushes::Black,x0f,y0f,5,5);
					buffer->Graphics->FillEllipse(Brushes::Red,x0fa,y0fa,5,5);



					
					
	

					
					 /*g->DrawImage(img,0,0);*/

					/*buffer->Graphics->DrawImage(carro,veca);*/

					//label1->Text="X: "+bomb->getXPixelColi().ToString();
					//label2->Text="Y: "+bomb->getYPixelColi().ToString();

					label1->Text="X: "+bomb->getX0().ToString();
					label2->Text="Y: "+bomb->getY0().ToString();

					if(bomb->getXPixelColi()!=-1 && bomb->getYPixelColi()!=-1)
					{
						buffer->Graphics->FillEllipse(Brushes::Black,bomb->getXPixelColi(),bomb->getYPixelColi(),3,3);
						

					}

					buffer->Render(g);
					delete buffer;
					delete espacioBuffer;
					delete g;

					 

					 
					 /*delete gimg;*/
				  /*}*/

				  
				

				  

			 }
	private: System::Void frmA_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

				 if(!EstaEnAire)
				 {
					 if(e->KeyChar=='h')
					 {
						
						 if(fondDestroy->GetPixel(bomb->getX(),bomb->getY()).A!=0)
							 MessageBox::Show("Exito");
					 }

					 if(!bomb->PixelColision(fondDestroy,0,bomb->getH()/2))
					 {
							 if(e->KeyChar=='a')
						 {
							 bomb->Mover(-7,0,fondDestroy);
							 ActualizarVerticesRectangulo(false,0);
							 rotar=true;
						 }
					 }

					 if(!bomb->PixelColision(fondDestroy,bomb->getW(),bomb->getH()/2))
					 {
						 if(e->KeyChar=='d')
						 {
							 bomb->Mover(7,0,fondDestroy);
							 ActualizarVerticesRectangulo(false,0);
							 rotar=true;
						 }
					 }

					 
				 }

			

				

			 }
	private: System::Void frmA_Load(System::Object^  sender, System::EventArgs^  e) {

				 fondDestroy= gcnew Bitmap(Image::FromFile("miramo_fg.png"),this->Size.Width,this->Size.Height);
				 
				 carro= gcnew Bitmap("armor.png");
				 bomb= new Bomba(this->Size.Width/2.0+100,2,50,50,0,0,0,0);

				 /*bomb= new Bomba(this->Size.Width/2.0+100,2,carro->Width/20.0,carro->Height,0,0,0,0);*/

				 flechaA= gcnew Bitmap("flecha.png");

				 rec=Rectangle(this->Size.Width/2.0,2,50,50);

				 if(!bomb->PixelColision(fondDestroy,bomb->getW(),bomb->getH()))
					 EstaEnAire=true;

				 progressBar1->Location.Y=this->Size.Height-progressBar1->Size.Height-5;
				 progressBar1->Size.Width=this->Size.Width;
				

				 veca[0]=Point(bomb->getX(),bomb->getY());
				 veca[1]=Point(bomb->getX()+bomb->getW(),bomb->getY());
				 veca[2]=Point(bomb->getX(),bomb->getY()+bomb->getH());

				 PoFlech[0]=Point(bomb->getX()+bomb->getW(),bomb->getY());
				 PoFlech[1]=Point(bomb->getX()+bomb->getW()+flechaA->Width,bomb->getY());
				 PoFlech[2]=Point(bomb->getX()+bomb->getW(),bomb->getY()+flechaA->Height);

				 /* PoFlech[0]=Point(500,800);
				  PoFlech[1]=Point(500+flechaA->Width,800);
				  PoFlech[2]=Point(500,800+flechaA->Height);*/

				

				 bomb->setX0(valorAbsoluto( (veca[1].X+veca[2].X)/2));
				 bomb->setY0(valorAbsoluto( (veca[1].Y+veca[2].Y)/2));

				
				 x0f=bomb->getX()+bomb->getW();
				 y0f=bomb->getY()+flechaA->Height/2;








				/* x0f=500;
				 y0f=800+flechaA->Height/2;*/

				 /*  PoFlech[0]=Point(500,800);
				  PoFlech[1]=Point(550,800);
				  PoFlech[2]=Point(500,850);*/

				 /* x0f=valorAbsoluto( (PoFlech[1].X+PoFlech[2].X)/2);
				 y0f=valorAbsoluto( (PoFlech[1].Y+PoFlech[2].Y)/2);*/

				 /*x0f=500;
				 y0f=825;*/
			
				/* bomb->getX0()= valorAbsoluto( (veca[1].X+veca[2].X)/2);
				 bomb->getY0()= valorAbsoluto( (veca[1].Y+veca[2].Y)/2);*/


				
				
			 }



				

			 void RellenarCirculo(double centrox,double centroy,double radio)
			 {

				 if(radio<0)
					 return;

				 double x,y;

				
				 /*Point^poi;*/
				
				 for(double angle=0.0 ; angle<=2.0*3.14 ; angle+=0.001)
				 {
					 /*poi=gcnew Point(,);*/
					  x=centrox+radio*cos(angle);
					  y=centroy+radio*sin(angle);

					  if(x<0 || x>=this->Width || y<0 || y>=this->Height)
						  continue;

					/* veca[3]=Point(200.0+radio*cos(angle),200.0+radio*sin(angle));*/					 
					 fondDestroy->SetPixel(x,y,Color::Transparent);
					 
				 }

				


				 /*delete poi;*/

				 RellenarCirculo(centrox,centroy,radio-1.0);


			 }

			

			 void RotarImagen(double angle)
			 {
				/*double grados=angle*3.14/180.0;*/
				

				 //Carro
				Point aux;


				aux=veca[0];

				aux.X=bomb->getX0()+(veca[0].X-bomb->getX0())*cos(angle)+(veca[0].Y-bomb->getY0())*sin(angle);
				aux.Y=bomb->getY0()-(veca[0].X-bomb->getX0())*sin(angle)+(veca[0].Y-bomb->getY0())*cos(angle);
				veca[0]=aux;

				aux=veca[1];

				aux.X=bomb->getX0()+(veca[1].X-bomb->getX0())*cos(angle)+(veca[1].Y-bomb->getY0())*sin(angle);
				aux.Y=bomb->getY0()-(veca[1].X-bomb->getX0())*sin(angle)+(veca[1].Y-bomb->getY0())*cos(angle);
				veca[1]=aux;

				aux=veca[2];

				aux.X=bomb->getX0()+(veca[2].X-bomb->getX0())*cos(angle)+(veca[2].Y-bomb->getY0())*sin(angle);
				aux.Y=bomb->getY0()-(veca[2].X-bomb->getX0())*sin(angle)+(veca[2].Y-bomb->getY0())*cos(angle);
				veca[2]=aux;

				RotarAngulo(angle);


				//Flecha Angular

				/*aux=PoFlech[0];

				aux.X=bomb->getX0()+(PoFlech[0].X-bomb->getX0())*cos(angle)+(PoFlech[0].Y-bomb->getY0())*sin(angle);
				aux.Y=bomb->getY0()-(PoFlech[0].X-bomb->getX0())*sin(angle)+(PoFlech[0].Y-bomb->getY0())*cos(angle);
				PoFlech[0]=aux;

				aux=PoFlech[1];

				aux.X=bomb->getX0()+(PoFlech[1].X-bomb->getX0())*cos(angle)+(PoFlech[1].Y-bomb->getY0())*sin(angle);
				aux.Y=bomb->getY0()-(PoFlech[1].X-bomb->getX0())*sin(angle)+(PoFlech[1].Y-bomb->getY0())*cos(angle);
				PoFlech[1]=aux;

				aux=PoFlech[2];

				aux.X=bomb->getX0()+(PoFlech[2].X-bomb->getX0())*cos(angle)+(PoFlech[2].Y-bomb->getY0())*sin(angle);
				aux.Y=bomb->getY0()-(PoFlech[2].X-bomb->getX0())*sin(angle)+(PoFlech[2].Y-bomb->getY0())*cos(angle);
				PoFlech[2]=aux;	*/
					
			 }

			 void RotarAngulo(double angle)
			 {
				  
				 /* int x0,y0;*/

				 /*x0=bomb->getX()+bomb->getW();
				 y0=bomb->getY();*/

				 /* x0=500;
				  y0=800;*/
			
				 x0f=bomb->getX()+bomb->getW();
				 y0f=bomb->getY()+flechaA->Height/2;

				 Point aux;
				  
				 

				 aux=PoFlech[0];

				 double aux1=x0f+((double)PoFlech[0].X-x0f)*cos(angle)+((double)PoFlech[0].Y-y0f)*sin(angle);
				 double aux2=y0f-((double)PoFlech[0].X-x0f)*sin(angle)+((double)PoFlech[0].Y-y0f)*cos(angle);

				aux.X=round(x0f+((double)PoFlech[0].X-x0f)*cos(angle)+((double)PoFlech[0].Y-y0f)*sin(angle));
				aux.Y=round(y0f-((double)PoFlech[0].X-x0f)*sin(angle)+((double)PoFlech[0].Y-y0f)*cos(angle));
				PoFlech[0]=aux;

				aux=PoFlech[1];

				aux.X=round(x0f+((double)PoFlech[1].X-x0f)*cos(angle)+((double)PoFlech[1].Y-y0f)*sin(angle));
				aux.Y=round(y0f-((double)PoFlech[1].X-x0f)*sin(angle)+((double)PoFlech[1].Y-y0f)*cos(angle));
				PoFlech[1]=aux;

				aux=PoFlech[2];

				aux.X=round(x0f+((double)PoFlech[2].X-x0f)*cos(angle)+((double)PoFlech[2].Y-y0f)*sin(angle));
				aux.Y=round(y0f-((double)PoFlech[2].X-x0f)*sin(angle)+((double)PoFlech[2].Y-y0f)*cos(angle));
				PoFlech[2]=aux;

				 x0fa=valorAbsoluto( (PoFlech[1].X+PoFlech[2].X)/2);
				 y0fa=valorAbsoluto( (PoFlech[1].Y+PoFlech[2].Y)/2);


			 }
			 int valorAbsoluto(int dato)
			 {
				 if(dato<0)
					 return dato*-1;
				 else
					 return dato;
			 }
			  double Pitagoras(double x1, double y1, double x2, double y2)
			 {
				 return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			 }
			 int dameYAdyacentColi(int pixelMedioCarroX, int pixelMedioCarroY)
			 {
				 while (true)
				 {
					 if (pixelMedioCarroY >= this->Size.Height)
						 return -1;
					 /*if (bomb->PixelColision(fondDestroy, bomb->getX + bomb->getW / 2, bomb->getY() + bomb->getH)*/

					 /*if (bomb->PixelColision(fondDestroy, pixelMedioCarroX, pixelMedioCarroY))*/
						 if(fondDestroy->GetPixel(pixelMedioCarroX,pixelMedioCarroY).A!=0)
						 return pixelMedioCarroY;

					 pixelMedioCarroY++;
				 }
			 }
			 void ActualizarVerticesRectangulo(bool conAngulo,double angulo)
			 {
				 

				 if(!conAngulo)
				 {
					 veca[0].X=bomb->getX();
					 veca[0].Y=bomb->getY();
					 veca[1].X=bomb->getX()+bomb->getW();
					 veca[1].Y=bomb->getY();
					 veca[2].X=bomb->getX();
					 veca[2].Y=bomb->getY()+bomb->getH();

					/* if(EstaEnAire)
					 {*/

						 PoFlech[0].X=bomb->getX()+bomb->getW();
						 PoFlech[0].Y=bomb->getY();
						 PoFlech[1].X=bomb->getX()+bomb->getW()+flechaA->Width;
						 PoFlech[1].Y=bomb->getY();
						 PoFlech[2].X=bomb->getX()+bomb->getW();
						 PoFlech[2].Y=bomb->getY()+flechaA->Height;
					 /*}*/
					  

					 
				 }
				 else				 
					 RotarImagen(angulo);

				 bomb->setX0(valorAbsoluto( (veca[1].X+veca[2].X)/2));
				 bomb->setY0(valorAbsoluto( (veca[1].Y+veca[2].Y)/2));
				 x0f=bomb->getX()+bomb->getW();
				 y0f=bomb->getY()+flechaA->Height/2;
				


				 
			 }
			 double round(double number)
			 {
				return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
			 }
			 
private: System::Void frmA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			/* label1->Text=e->X.ToString();
			 label2->Text=e->Y.ToString();

			 progressBar1->Show();*/

			



		 }
private: System::Void frmA_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 if(fondDestroy->GetPixel(e->X,e->Y).A==0)
				 return;



			 RellenarCirculo(e->X,e->Y,50.0);





		 }
private: System::Void frmA_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 if(e->KeyCode==Keys::Space)
			 if(barrIncre<=this->Size.Width-100)
				barrIncre+=30;

			 if(e->KeyCode==Keys::H)
				 RotarImagen(45);
			 if(e->KeyCode==Keys::J)
				 RotarImagen(-45);
			 if(e->KeyCode==Keys::Up)
			 {
				/*anguloDisparar+=1.0;*/
				anguloDisparar+=10.0;
				RotarAngulo(10.0*3.14159265359/180.0);
				 
			 }
			 if(e->KeyCode==Keys::Down)
			 {
				 /*anguloDisparar-=1.0;*/
				 anguloDisparar-=10.0;
				 RotarAngulo(10.0*3.14159265359/180.0*-1.0);

				 

			 }

		 }
private: System::Void frmA_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			
		 }
};
}
