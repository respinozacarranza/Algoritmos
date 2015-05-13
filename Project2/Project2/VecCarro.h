#pragma once
#include "Carro.h"
#include <vector>

using namespace std;
using namespace System::Drawing;

class VecCarro
{
	vector<Carro*> vCarros;

	

	
public:
	VecCarro();
	~VecCarro();

	bool Insertar_final(Carro* objCarro);
	Carro* dameDatoEnPos(int pos);
	int get_size();
	
	
};

