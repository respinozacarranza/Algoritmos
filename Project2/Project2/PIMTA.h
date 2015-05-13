#pragma once
#include "Carro.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PIMTA
	/// </summary>
	public ref class PIMTA : public System::Windows::Forms::Form
	{
	public:
		PIMTA(Bitmap^bmp,Carro* pcarro,Bitmap^parrow)
		{
			InitializeComponent();
			FlechaAngulo= gcnew Bitmap("flecha.png");
			FlechaAnguloINV= gcnew Bitmap("flechainv.png");
			Bala1= gcnew Bitmap("bala1armor.png");
			int aux=FlechaAngulo->Width;
			int aux2=FlechaAngulo->Height;

			Player=new Carro(pcarro->get_X(),pcarro->get_Y(),pcarro->get_tipo(),pcarro->get_W(),pcarro->get_H(),(double)FlechaAngulo->Width,(double)FlechaAngulo->Height,Bala1);
			/*Player = new Carro(50.0,50.0,ptipo,50.0,30.0);*/
			Jugador=bmp;
			/*g=this->CreateGraphics();*/
			arrow=parrow;
			fondo=gcnew Bitmap("miramo_bg.jpg");
			
			speed=7;
			tiempo=0.1;
			poder=0.0;
			anguloDisparar=0.0;

			
			

			
			//
			//TODO: agregar código de constructor aquí
			//
		}

		


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~PIMTA()
		{
			delete Player;
			delete Jugador;
			delete arrow;
			delete FlechaAngulo;
			delete FlechaAnguloINV;
			delete fondo;
			delete fondDestroy;
			delete JugadorINV;
			delete Bala1;
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		Carro *Player ;
		Bitmap^Jugador;
		Bitmap^arrow;
		int Xmouse,Ymouse;
		Bitmap^fondo;
		Bitmap^fondDestroy;
		Bitmap^JugadorINV;
		Bitmap^Bala1;
		Bitmap^FlechaAngulo;
		Bitmap^FlechaAnguloINV;
		double tiempo;
		int speed;
		double poder;
		double anguloDisparar;

	

	
			
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &PIMTA::timer1_Tick);
			// 
			// PIMTA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(597, 422);
			this->Name = L"PIMTA";
			this->Text = L"PIMTA";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PIMTA::PIMTA_FormClosed);
			this->Load += gcnew System::EventHandler(this, &PIMTA::PIMTA_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PIMTA::PIMTA_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PIMTA::PIMTA_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &PIMTA::PIMTA_KeyUp);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PIMTA::PIMTA_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PIMTA_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

				  Form ^frm = (Form^)Application::OpenForms["MyForm"];
					frm->Close();

				



				
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

					Graphics^g=CreateGraphics();
					BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
					espacioBuffer->MaximumBuffer = System::Drawing::Size( g->VisibleClipBounds.Width + 1, g->VisibleClipBounds.Height + 1 );
					BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Drawing::Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height));
				

					buffer->Graphics->DrawImage(fondo,0.0,0.0,g->VisibleClipBounds.Width,g->VisibleClipBounds.Height);
					buffer->Graphics->DrawImage(fondDestroy,0,0);

					if(Player->get_direccion()=='i')
						Player->Pintar(fondDestroy,buffer,Jugador,FlechaAnguloINV,Bala1);
					else
						Player->Pintar(fondDestroy,buffer,JugadorINV,FlechaAngulo,Bala1);

					if(Player->getAire())
						Player->Mover(0,speed,g->VisibleClipBounds.Width,g->VisibleClipBounds.Height,Player->get_direccion(),fondDestroy);

					
					
					buffer->Graphics->DrawImage(arrow,Xmouse,Ymouse,arrow->Width,arrow->Height);

					buffer->Graphics->FillRectangle(Brushes::Red,100.0,(float)this->Height-100.0,(float)poder,100.0);



					/*gimg->DrawImage(Jugador,Rectangle(50,50,Jugador->Width,Jugador->Height),0,0,Jugador->Width,Jugador->Height,System::Drawing::GraphicsUnit::Pixel);*/


					buffer->Render(g);

					delete buffer;
				    delete espacioBuffer;
					delete g;
				  

				   

				  
			 }


			
			 
	
	private: System::Void PIMTA_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

				/* if(e->KeyChar=='k')
				 {
					 Player->mirrorLeftRight(Jugador);
					 
					 Jugador->Save("MIRRROR.png");
				 }*/

				 
				 
			 }
private: System::Void PIMTA_Load(System::Object^  sender, System::EventArgs^  e) {

			 int x=this->Size.Width;
			 x=this->Size.Height;
			 fondDestroy= gcnew Bitmap(Image::FromFile("miramo_fg.png"),this->Size.Width,this->Size.Height);

			 CargarImagenInvertido();
			 	

			 
		 }
private: System::Void PIMTA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 Xmouse=e->X;
			 Ymouse=e->Y;
		 }
private: System::Void PIMTA_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		 

			 if(Player->getAire())
				 return;

			 
					if(e->KeyCode==Keys::A)
					{
						/*Player->set_direccion('i');*/
						
						Player->Mover(-speed,0,this->Width,this->Height,'i',fondDestroy);
					}
				

			
					 if(e->KeyCode==Keys::D)
					 {
						 /*Player->set_direccion('d');*/
						 Player->Mover(speed,0,this->Width,this->Height,'d',fondDestroy);
					 }
				

					 if(!Player->EstaDisparando())
					 {
						 if(e->KeyCode==Keys::Space)
						 {
							 if(poder<=this->Size.Width-200)
								poder=poder+20;			 
						 }


						 if(e->KeyCode==Keys::Up)
						 {
							/*anguloDisparar+=1.0;*/




							anguloDisparar+=10.0;
							/*if(anguloDisparar>=60.0)
							{
								anguloDisparar=60.0;

							}*/

							if(anguloDisparar<=60.0 && anguloDisparar>=0)
							{
							 Player->set_anguloDisparo(anguloDisparar*3.14159265359/180.0);

							 if(Player->get_direccion()=='d')
									Player->RotarAngulo(10.0*3.14159265359/180.0);
							 else
								 Player->RotarAngulo(10.0*3.14159265359/180.0*-1.0);
							}
							else
								anguloDisparar-=10.0;

				 
						 }
						 if(e->KeyCode==Keys::Down)
						 {
							 /*anguloDisparar-=1.0;*/



							 anguloDisparar-=10.0;
							 /*if(anguloDisparar<=0.0)
							{
								anguloDisparar=0.0;
							}*/

							 if(anguloDisparar<=60.0 && anguloDisparar>=0)
							{

							 Player->set_anguloDisparo(anguloDisparar*3.14159265359/180.0);
							 if(Player->get_direccion()=='d')
								Player->RotarAngulo(10.0*3.14159265359/180.0*-1.0);
							 else
								Player->RotarAngulo(10.0*3.14159265359/180.0);


							}
							 else
								anguloDisparar+=10.0;


						 }
					 }

		 }

		 void CargarImagenInvertido()
		 {			
			 if(Player->get_tipo()==1)
			 {
				 JugadorINV= gcnew Bitmap("armorinv.png");
				 Bala1 = gcnew Bitmap("bala1armor.png");
			 }
			 if(Player->get_tipo()==2)
			 {
				  JugadorINV= gcnew Bitmap("lightninginv.png");
				  Bala1 = gcnew Bitmap("bala1lighting.png");
			 }
			 if(Player->get_tipo()==3)
			 {
				 JugadorINV= gcnew Bitmap("foxinv.png");
				 Bala1 = gcnew Bitmap("bala1fox.png");
			 }
			 if(Player->get_tipo()==4)
			 {
				 JugadorINV= gcnew Bitmap("mageinv.png");
				 Bala1 = gcnew Bitmap("bala1mage.png");
			 }
			 if(Player->get_tipo()==5)
			 {
				 JugadorINV= gcnew Bitmap("turtleinv.png");
				 Bala1 = gcnew Bitmap("bala1turtle.png");
			 }
			 if(Player->get_tipo()==6)
			 {
				 JugadorINV= gcnew Bitmap("bigfootinv.png");
				 Bala1 = gcnew Bitmap("bala1bigfoot.png");
			 }
			 if(Player->get_tipo()==7)
			 {
				 JugadorINV= gcnew Bitmap("unicorninv.png");
				 Bala1 = gcnew Bitmap("bala1unicorn.png");
			 }
			 if(Player->get_tipo()==8)
			 {
				 JugadorINV= gcnew Bitmap("jdinv.png");
				 Bala1 = gcnew Bitmap("bala1jd.png");
			 }
			 if(Player->get_tipo()==9)
			 {
				 JugadorINV= gcnew Bitmap("iceinv.png");
				 Bala1 = gcnew Bitmap("bala1ice.png");
			 }
			 if(Player->get_tipo()==10)
			 {
				 JugadorINV= gcnew Bitmap("adukainv.png");
				 Bala1 = gcnew Bitmap("bala1aduka.png");
			 }

		 }


private: System::Void PIMTA_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			if(!Player->EstaDisparando())
			 if(e->KeyCode==Keys::Space)
			 {				 
				 Player->Disparar(poder);
				 poder=0.0;
				 
			 }
		 }
};
}
