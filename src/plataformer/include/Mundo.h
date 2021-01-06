#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Pared.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "ListaPlataformas.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"
#include "puertaNivel.h"
class Mundo
{
private:
	bool impacto;
	int nivel;
	bool nivelterminado;
	//bool salto;
public:
	bool salto;
	Mundo();
	void Inicializa();
	void Rotared();
	void Move();
	void Draw();
	virtual ~Mundo();
	int GetNumEsferas();
	bool estadoNivel();
	int GetVidasHombre();
	bool Impacto();
	float x_ojo;
	float y_ojo;
	float z_ojo;
	ListaEsferas esferas;
	ListaDisparos disparos;
	ListaPlataformas plataformas;
	Hombre hombre;
	Bonus bonus;
	Caja caja;
	puertaNivel puerta;
	DisparoEspecial dispowa;

	void TeclaEspecial(unsigned char key);
	void TeclaDown(unsigned char key);
	void TeclaUp(unsigned char key);
	void Tecla(unsigned char key);
	bool SetLevel();
};
