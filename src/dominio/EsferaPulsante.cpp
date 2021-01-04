#include "EsferaPulsante.h"


EsferaPulsante::EsferaPulsante(float px=0,float py=0)
{
	pos.x=px;
	pos.y=py;
	pulso=0.5;
	rad_max=2;
	rad_min=0.5;
	pos.x=0;
	pos.y=5;
	acelr.y=0;
	acelr.x=0;
}


EsferaPulsante::~EsferaPulsante(void)
{
}
void EsferaPulsante::Move(float t)
{
	Esfera::Move(t);
	if(rad>rad_max) pulso=-pulso;
	if(rad<rad_min) pulso=-pulso;
	rad+=pulso*t;
	color.r=rad*255; 
	color.g=255-rad*100; 
	color.b=100+rad*50;


}
Esfera* EsferaPulsante::Dividir()
{

	if(rad<1.0f) return 0; //no dividimos 
	rad/=2.0f;//Dividimos el radio por 2 
	//Creamos una esfera nueva, copiando la actual
	pulso*=1.1;
	if(pulso>3) pulso=3;
	Esfera *aux=new EsferaPulsante(*this); //Les damos nuevas velocidades 
	aux->SetPos(pos.x+1,pos.y+1);
	aux->SetVel(5,8);//a la nueva mitad 
	pulso*=1.5;
	SetVel(-5,8);//a la mitad original 
	return aux;


}
void EsferaPulsante::SetPulso(float t)
{
pulso=t;

}