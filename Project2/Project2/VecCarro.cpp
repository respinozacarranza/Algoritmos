#include "VecCarro.h"


VecCarro::VecCarro()
{
	vCarros=vector<Carro*>();
}


VecCarro::~VecCarro(void)
{
	vCarros.clear();
	
}
bool VecCarro::Insertar_final(Carro* objCarro)
{
	if(objCarro==NULL)
		return false;
	vCarros.push_back(objCarro);
	return true;

}
int VecCarro::get_size()
{
	return vCarros.size();
}
Carro* VecCarro::dameDatoEnPos(int pos)
{
	return vCarros[pos];
}
