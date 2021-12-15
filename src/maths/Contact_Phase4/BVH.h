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


	// ----------  Sphere methodes ------

	float getSphereVolume() {
		return  (4 / 3) * 3.1415 * sphere.rayon * sphere.rayon;
	}


	SphereEnglobante_t addSphere(SphereEnglobante_t sphereA, SphereEnglobante_t sphereB) {
		SphereEnglobante_t newSphere;

		float distanceAB = (sphereA.center + sphereB.center).norme();

		newSphere.center = Vector3D(
			(sphereA.center.x + sphereB.center.x) / 2,
			(sphereA.center.y + sphereB.center.y) / 2,
			(sphereA.center.z + sphereB.center.z) / 2);
		
		newSphere.rayon = distanceAB + sphereA.rayon + sphereB.rayon;

	}


	// --------- Methodes for node ---------

	bool hasParent(){
		return node_parent != nullptr;
	}

	bool isLeaf() {

		return nodes_enfant.size() == 0;
	}



	Node* getBrother() {
		Node* returnBrother = nullptr;			// creation du pt à retourner
		if (hasParent) {
			for (Node* brother : this->node_parent->nodes_enfant)		// pour chaque frere
			{
				if (brother != this && returnBrother == nullptr) {		// verification du frere
					returnBrother = brother;
				}
			}
		}
		return returnBrother;			// retourne le frere
	}


	void RemoveFromChild(Node* nodeToRemove) {
		// on cherche l'index du parent pour le supp des enfant du grand parent
		int index = 0;
		int saveIndex = -1;
		for (Node* child : this->nodes_enfant) {
			if (child == nodeToRemove)
			{
				saveIndex = index;
			}
			index++;
		}

		if (saveIndex == -1) {
			std::cout << "Suppression error, parent not found in parrent2Child";
			return;
		}

		// on supprime le parent des enfant du grand parent
		this->nodes_enfant.erase(this->nodes_enfant.begin() + saveIndex);
	}


	// ------------------------

	void insertion(Node* NewNode) {
		if (isLeaf) {
			this->node_parent->RemoveFromChild(this);

			Node* NewParent;
			this->node_parent->nodes_enfant.push_back(NewParent);
			this->node_parent = NewParent;
			NewParent->nodes_enfant.push_back(NewNode);
			NewParent->nodes_enfant.push_back(this);

		}
		else {
			// refaire sur l'enfant ou le BV sera le plus petit apres l'ajout de la node
			float minSearch = std::numeric_limits<float>::max();		// taille max
			Node* childSave = nullptr;
			for (Node* child : this->nodes_enfant)
			{
				SphereEnglobante_t addSphere = this->addSphere(child->sphere, NewNode->sphere);
				
				if (addSphere.rayon < minSearch) {		// si taille plus petite qu'avant, on garde ce child
					minSearch = addSphere.rayon;
					childSave = child;
				}
			}

			childSave->insertion(NewNode);
		}

	}

	void suppression() {
		if (hasParent && this->node_parent->nodes_enfant.size() == 2)
		{
			Node* parrent2 = this->node_parent->node_parent;
			Node* parrent = this->node_parent;
			Node* brother = getBrother();

			parrent2->RemoveFromChild(parrent);

			// on met le frere à la place du parent 
			brother->node_parent = parrent2;
			parrent2->nodes_enfant.push_back(brother);				

			
		}
		delete this;
	}



};

class BVH
{
public :

	Node* root;

	


};

