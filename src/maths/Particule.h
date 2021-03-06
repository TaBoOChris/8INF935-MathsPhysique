#pragma once
#include "Vecteur3D.h"

class Particule
{
private :

	//inverse masse et frottement sont des constantes nécessaires au calcul de vitesse et accélération en physique
	float masse;
	float inverseMasse;
	float frottement;
	float rayon;

	//trois vecteurs des nécessaire à décrire l'état d'une particule et prévoir son évolution
	Vector3D position;
	Vector3D vitesse;
	Vector3D acceleration;

public :

	Particule();

	Particule(float invMasse);

	Particule(float invMasse, float frottement);

	Particule(Vector3D initialPosition, Vector3D initialVitesse, Vector3D initialAcceleration);


	//avec position, vitesse et accélération, suffisant à décrire la particule et son évolution
	Vector3D accumForce;

	float getInverseMasse();

	float getMasse();

	Vector3D getPosition();

	Vector3D getVitesse();

	Vector3D getAcceleration();

	float getRayon();

	void setInverseMasse(float invM);

	void setMasse(float masse);

	void setFrottement(float frott);

	void setVitesse(Vector3D vitesse);

	void setPosition(Vector3D position);

	void updateAcceleration();

	//dans les trois fonctions suivantes, le temps est le delta temps avec l'instant précédent, permet une approximation du calcul
	void updateVitesse(float temps);

	void updatePosition(float temps);

	void integrer(float temps);

	void addForce(Vector3D force);
};




