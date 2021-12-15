#pragma once

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

#include "SphereEnglobante.h"
#include "Primitive.h"
#include "CollisionData.h"


/// <summary>
/// Deux classes, Node et BHV
/// </summary>


class Node {

public :
	
	Node* node_parent;						// Parent
	std::vector<Node*> nodes_enfant;		// all child
	
	SphereEnglobante_t sphere;				// Sphere
	Primitive primitive;					// Primitive


	// ------ Constructor ----------
	Node();
	Node(SphereEnglobante_t sphere);
	Node(Primitive prim);


	// ----------  Sphere methodes ------
	float getSphereVolume();
	SphereEnglobante_t addSphere(SphereEnglobante_t sphereA, SphereEnglobante_t sphereB);

	// --------- Methodes for node ---------

	bool hasParent(){ return node_parent != nullptr;}		// A t il un parent 
	bool isLeaf() {	return nodes_enfant.size() == 0;}		// A t il des enfants
	Node* getBrother();										// obtenir le premier frere
	void RemoveFromChild(Node* nodeToRemove);				// retirer une node parmis les enfants
		
	// ------------------------

	void insertion(Node* NewNode);				// Inserer une node (methode recursif)
	void suppression();							// Supprimer la current node

	//------ affichage -------------
	void print(int degree);

};

class BVH
{
public :
	Node* root;

	// ------ Constructor ----------
	BVH();
	BVH(SphereEnglobante_t sphere);

	// --------- Methodes ---------
	void checkCollision(Node* parent, CollisionData* cd);
	void checkCollision();

};

