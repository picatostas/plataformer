#include "dominio\Bonus.h"
#include "dominio\Caja.h"
#include "dominio\Disparo.h"
#include "dominio\Esfera.h"
#include "dominio\Hombre.h"
#include "dominio\Pared.h"
#include "dominio\ListaEsferas.h"
#include "dominio\ListaDisparos.h"
#include "dominio\ListaPlataformas.h"
#include "dominio\EsferaPulsante.h"
#include "dominio\DisparoEspecial.h"
#include "dominio\puertaNivel.h"
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
	//	EsferaPulsante esf_puls;
	DisparoEspecial dispowa;

	void TeclaEspecial(unsigned char key);
	void TeclaDown(unsigned char key);
	void TeclaUp(unsigned char key);
	void Tecla(unsigned char key);
	bool SetLevel();
};
