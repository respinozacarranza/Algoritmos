#pragma once
#include "VecCarro.h"
#include "PIMTA.h"


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			indiceCarro = 0;
			indice=0;
			g = this->CreateGraphics();
			posVecPersonaje=-1;
			Pcarro=new Carro(50,50,1,50,50,0,0);
			carros=new VecCarro();
			nose= gcnew ArrayList();
			arrow=gcnew Bitmap("arrow.png");
			fondo=gcnew Bitmap("room_bg.png");
			start= gcnew Bitmap("Start.png");
			

		
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			
			delete g;
			/*delete carros;*/
			delete arrow;
			delete nose;
			delete fondo;
			delete start;

			/*delete Pcarro;*/
			if (components)
			{
				delete components;
				
			}
		}

	private:
		
		 int indiceCarro;
		 int indice;		
		 Graphics ^g;
		 int posVecPersonaje;
		 Rectangle selec;
		 int Xmouse,Ymouse;
		 Carro* Pcarro;
		 VecCarro* carros;
		 ArrayList^nose;		 
		 Bitmap ^arrow;
		 Bitmap^fondo;
		 Bitmap^start;
		 Rectangle RecStart;
	

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;


	private: System::ComponentModel::IContainer^  components;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(327, 550);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 70;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(13, 105);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(739, 40);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(13, 151);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(859, 37);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(12, 194);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(1880, 54);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			this->pictureBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox3_MouseClick);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(12, 58);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(949, 41);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"label2";
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(12, 4);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(1012, 48);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Visible = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(12, 254);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(1001, 46);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox6->TabIndex = 8;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Visible = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(12, 306);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(1229, 51);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox7->TabIndex = 9;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Visible = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(12, 363);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(717, 45);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox8->TabIndex = 10;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Visible = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(12, 414);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(1093, 55);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox9->TabIndex = 11;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Visible = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(23, 491);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(1135, 40);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox10->TabIndex = 12;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 585);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDoubleClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//void Inicializar_Datos()
		//{
		//	

		//		

		//		 
		//		for (int i=Controls->Count-1 ; i>=0; i--)
		//			 {
		//				 if(Controls[i]->GetType()->Name=="PictureBox")
		//					 nose->Add(Controls[i]);

		//			 }
		//		 			

		//



		//		 double aux=(double)g->VisibleClipBounds.Width/5.0;
		//		 double w;
		//		 PictureBox^auxPic;


		//		 for(int i=0 ; i< 4; i++)
		//		 {
		//			 auxPic=(PictureBox^)nose[i];
		//			 w=(double)auxPic->Width/20.0;
		//			 carros->Insertar_final(new Carro((double)i*aux+(((double)g->VisibleClipBounds.Width/5.0-w)/2.0),(double)g->VisibleClipBounds.Height/5.0,i+1,auxPic->Width,auxPic->Height));
		//			 /*aux=aux+(double)g->VisibleClipBounds.Width/3.0;*/
		//		 }
		//		

		//		 delete auxPic;
		//		 inicializar=true;
		//}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 /*imgtrans = gcnew Bitmap(pictureBox1->Image);*/
				 //imgtrans->MakeTransparent(imgtrans->GetPixel(1,1));

				 	/*	  for (int i=Controls->Count-1 ; i>=0; i--)
					 {
						 if(Controls[i]->GetType()->Name=="PictureBox")
							 nose->Add(Controls[i]);

					 }
*/

				 /*if(inicializar)
					 return;

				 for(int i=0 ; i<Controls->Count ;i++)
				 {
					 if(Controls[i]->GetType()->Name=="PictureBox")
						 nose->Add(Controls[i]);
				 }

				 nose->Sort();

		



				 double aux=(double)g->VisibleClipBounds.Width/3.0;
				 double w;
				 PictureBox^auxPic;


				 for(int i=0 ; i<3 ; i++)
				 {
					 auxPic=(PictureBox^)nose[i];
					 w=(double)auxPic->Width/20.0;
					 carros->Insertar_final(new Carro((double)i*aux+(((double)g->VisibleClipBounds.Width/3.0-w)/2.0),(double)g->VisibleClipBounds.Height/5.0,i+1,auxPic->Width,auxPic->Height));
					 aux=aux+(double)g->VisibleClipBounds.Width/3.0;
				 }
				

				 delete auxPic;
				 inicializar=true;*/
					
				 button1->Visible=false;


				 RecStart.X=g->VisibleClipBounds.Width/3.0;
				 RecStart.Y=g->VisibleClipBounds.Height-200;
				 RecStart.Width=start->Width*2;
				 RecStart.Height=start->Height*2;
				 

				 	for (int i=Controls->Count-1 ; i>=0; i--)
					 {
						 if(Controls[i]->GetType()->Name=="PictureBox")
							 nose->Add(Controls[i]);

					 }
				 			

		



				 double aux=(double)g->VisibleClipBounds.Width/5.0;
				 double w;
				 PictureBox^auxPic;


				 for(int i=0 ; i<= 9; i++)
				 {
					 auxPic=(PictureBox^)nose[i];
					 w=(double)auxPic->Width/20.0;
					 //carros->Insertar_final(new Carro((double)i*aux+(((double)g->VisibleClipBounds.Width/5.0-w)/2.0),(double)g->VisibleClipBounds.Height/5.0,i+1,(double)auxPic->Width/20.0,(double)auxPic->Height,0,0));
					 carros->Insertar_final(new Carro(90,160,i+1,(double)auxPic->Width/20.0,(double)auxPic->Height,0,0));

					 /*aux=aux+(double)g->VisibleClipBounds.Width/3.0;*/
				 }
				

				 delete auxPic;

				  Cursor->Hide();


				


			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


				/* MyForm_Load(sender,e);*/

				/* if(!inicializar)
					 Inicializar_Datos();*/
				 

				 BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
				espacioBuffer->MaximumBuffer = System::Drawing::Size( g->VisibleClipBounds.Width + 1, g->VisibleClipBounds.Height + 1 );
				BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Drawing::Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height));

				  

				  PictureBox^piCaux;
				 

				/* if(g->VisibleClipBounds.Height>0 && g->VisibleClipBounds.Width>0)
				 {
					Bitmap ^img = gcnew Bitmap(g->VisibleClipBounds.Width,g->VisibleClipBounds.Height);
					Graphics ^gimg = Graphics ::FromImage(img);

					

					

					 gimg->Clear(Color::Black);
					
					*/

					
					 
					/* for(int x=0,i<Controls->Find("PictureBox",true))
					 {
						label1->Text=x.Name;
						 

					 }*/
					/*int aux=(g->VisibleClipBounds.Width/3-37)/2;*/



					/* gimg->DrawImage(pictureBox1->Image,Rectangle((g->VisibleClipBounds.Width/3-37)/2,g->VisibleClipBounds.Height/5,37,pictureBox1->Height),Rectangle(indice*37,0,37,pictureBox1->Height),GraphicsUnit::Pixel);
					 gimg->DrawImage(pictureBox2->Image,Rectangle(g->VisibleClipBounds.Width/3+(g->VisibleClipBounds.Width/3-43)/2,g->VisibleClipBounds.Height/4,43,pictureBox2->Height),Rectangle(indice*43,0,43,pictureBox2->Height),GraphicsUnit::Pixel);
					 gimg->DrawImage(pictureBox3->Image,Rectangle(g->VisibleClipBounds.Width/3+g->VisibleClipBounds.Width/3+(g->VisibleClipBounds.Width/3-43)/2,g->VisibleClipBounds.Height/2,94,pictureBox3->Height),Rectangle(indice*94,0,94,pictureBox3->Height),GraphicsUnit::Pixel);
					 Pcarro->Pintar(gimg,(Bitmap^)pictureBox1->Image);*/

					 buffer->Graphics->DrawImage(fondo,0.0,0.0,g->VisibleClipBounds.Width,g->VisibleClipBounds.Height);
					
					///PINTAR CARRO DE ACUERDO AL INDICE
						 piCaux=(PictureBox^)nose[indiceCarro];
						 carros->dameDatoEnPos(indiceCarro)->Pintar(buffer,(Bitmap^)piCaux->Image);
					 

					   buffer->Graphics->DrawRectangle(gcnew Pen(Color::GreenYellow),selec.X,selec.Y,selec.Width,selec.Height);

					   buffer->Graphics->DrawImage(start,RecStart);
					   buffer->Graphics->DrawImage(arrow,Xmouse,Ymouse,arrow->Width,arrow->Height);



					 /*if(indice>=19)
						 indice=0;

					 indice++;
					 */
					 
					
					/* Player->Pintar(gimg,imgtrans);*/
					 
					
					 
					
					


					

					
					 //obj->Pintar(gimg,imgtrans);
					// obj->Mover(gimg,imgtrans);
					 // obj->MoverBalas(gimg);
					// g->DrawImage(img,0,0);

					   buffer->Render(g);

					
					 delete buffer;
					 delete espacioBuffer;
					 delete piCaux;
					 
					
				
				 
				 
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				

				 

				 

			 }
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

				 if(e->KeyCode == Keys::Right)
				 {
					 if(indiceCarro < 9)
					 indiceCarro++;
					 
				 }

				 if(e->KeyCode == Keys::Left)
				 {
					 if(indiceCarro>0)
					 indiceCarro--;
				 }
			 }
private: System::Void MyForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			
			 
				
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

			 

		 }
private: System::Void MyForm_Click(System::Object^  sender, System::EventArgs^  e) {

			 
		 }
private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 Xmouse=e->X;
			 Ymouse=e->Y;
		 }
private: System::Void MyForm_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			
		 }
private: System::Void pictureBox3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 
		 }
private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				for(int i=0  ;i<carros->get_size() ; i++)
					 {
						 
						 if(SeleccionPersonaje( carros->dameDatoEnPos(i)->get_X(),carros->dameDatoEnPos(i)->get_Y(),carros->dameDatoEnPos(i)->get_W()*2,carros->dameDatoEnPos(i)->get_H()*2,e))
							 posVecPersonaje=i;

					}

				if(SeleccionPersonaje(RecStart.X,RecStart.Y,RecStart.Width,RecStart.Height,e))
				{
					InicializarJuego();
				}

			/* if(SeleccionPersonaje(50,50,37,pictureBox1->Height,e))
			 {
				 tipo=1;
			 }
			 if(SeleccionPersonaje(g->VisibleClipBounds.Width/2,g->VisibleClipBounds.Height/4,43,pictureBox2->Height,e))
			 {
				 tipo=2;
			 }
			 if(SeleccionPersonaje(g->VisibleClipBounds.Width/2,g->VisibleClipBounds.Height/2,94,pictureBox3->Height,e))
			 {
				 tipo=3;
			 }
*/
			 
			 
			 
			  
		 }

		 bool SeleccionPersonaje(double x,double y,double w,double h, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 if(e->X>=x && e->X<=x+w && e->Y>=y && e->Y<=y+h)
			 {
				 
				 selec.X=x;
				 selec.Y=y;
				 selec.Width=w;
				 selec.Height=h;
				 return true;
			 }

			 return false;

		 }

		 void InicializarJuego()
		 {
			  if(indiceCarro==-1)
					 return;

				 timer1->Enabled=false;
				 this->Visible=false;
				 PictureBox^auxPic=(PictureBox^)nose[indiceCarro];
				 

				 
				 PIMTA ^frm= gcnew PIMTA((System::Drawing::Bitmap^)auxPic->Image,carros->dameDatoEnPos(indiceCarro),arrow);
				 /*case 2:  frm= gcnew PIMTA((System::Drawing::Bitmap^)pictureBox2->Image,2); break;
				 case 3:  frm= gcnew PIMTA((System::Drawing::Bitmap^)pictureBox3->Image,3); break;*/

				 delete carros;

				 delete auxPic;
				 nose->Clear();
				 
				
				
				 
				 
				 frm->Show();
		 }

	
};

}
