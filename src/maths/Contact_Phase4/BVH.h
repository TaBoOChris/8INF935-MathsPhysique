#pragma once

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

#include "SphereEnglobante.h"
#include "Primitive.h"
#include "CollisionData.h"

class Node {

public :
	
	Node* node_parent;
	SphereEnglobante_t sphere;
	std::vector<Node*> nodes_enfant;
	Primitive primitive;

	Node();
	Node(SphereEnglobante_t sphere);

	Node(Primitive prim);


	// ----------  Sphere methodes ------

	float getSphereVolume();

	SphereEnglobante_t addSphere(SphereEnglobante_t sphereA, SphereEnglobante_t sphereB);

	// --------- Methodes for node ---------

	bool hasParent(){ return node_parent != nullptr;}

	bool isLeaf() {	return nodes_enfant.size() == 0;}

	Node* getBrother();

	void RemoveFromChild(Node* nodeToRemove);


	// ------------------------

	void insertion(Node* NewNode);

	void suppression();

	//^------ affichage -------------

	void print(int degree);

};

class BVH
{
public :

	BVH();
	BVH(SphereEnglobante_t sphere);
	void checkCollision(Node* parent, CollisionData* cd);
	Node* root;
	void checkCollision();

};

