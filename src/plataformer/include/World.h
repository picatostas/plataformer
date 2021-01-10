#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Wall.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "PlatformContainer.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"
#include "LevelDoor.h"
class World
{
private:
	bool impacto;
	int nivel;
	bool nivelterminado;

public:
	bool salto;
	World();
	void Inicializa();
	void Rotared();
	void Move();
	void Draw();
	virtual ~World();
	int GetNumEsferas();
	bool estadoNivel();
	int GetVidasHombre();
	bool Impacto();
	float x_ojo;
	float y_ojo;
	float z_ojo;
	ListaEsferas esferas;
	ListaDisparos disparos;
	PlatformContainer platforms;
	Hombre hombre;
	Bonus bonus;
	Caja caja;
	LevelDoor puerta;
	DisparoEspecial dispowa;

	void KeyEspecial(unsigned char key);
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
	void Key(unsigned char key);
	bool SetLevel();
};
