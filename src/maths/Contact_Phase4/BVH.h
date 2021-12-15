#pragma once

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

#include "SphereEnglobante.h"

class Node {

public :
	
	Node* node_parent;
	SphereEnglobante_t sphere;
	std::vector<Node*> nodes_enfant;

	Node();
	Node(SphereEnglobante_t sphere);


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

	Node* root;

};

