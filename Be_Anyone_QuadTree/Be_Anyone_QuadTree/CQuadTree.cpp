#include "stdafx.h"
#include "CQuadTree.h"

CQuadTree::CQuadTree(std::shared_ptr<BoundaryBox> BB_init, CQuadTree* parent, int _nodeDepth)
{
	northWest = nullptr;
	northEast = nullptr;
	southWest = nullptr;
	southEast = nullptr;

	this->boundary2 = std::move(BB_init);

	if (parent == nullptr)
	{
		this->parent = this;
	}
	else
	{
		this->parent = parent;
	}

	this->nodeDepth = _nodeDepth;
}


void CQuadTree::clear(CQuadTree* t)
{
	if (t != nullptr)
	{
		clear(t->northEast);
		clear(t->northWest);
		clear(t->southEast);
		clear(t->southWest);

		delete t;	// calls the destructor
	}
}


CQuadTree::~CQuadTree()
{
	delete northWest;
	delete northEast;
	delete southWest;
	delete southEast;

	northWest = nullptr;
	northEast = nullptr;
	southWest = nullptr;
	southEast = nullptr;
}


void CQuadTree::clearNode()
{
	delete northWest;
	delete northEast;
	delete southWest;
	delete southEast;

	northWest = nullptr;
	northEast = nullptr;
	southWest = nullptr;
	southEast = nullptr;
}


// insert one point into the tree. Split the tree and relocate the points ot the node if necessary
bool CQuadTree::insert(Point2D insertPt)
{
	// check if the point resides in this node
	if (insertPt.x > boundary2->cx + boundary2->dim or insertPt.x <= boundary2->cx - boundary2->dim 
		or insertPt.y > boundary2->cy + boundary2->dim or insertPt.y <= boundary2->cy - boundary2->dim)
		return false;

	if ((children.size() < maxAmtElements and northWest == nullptr) or this->nodeDepth == maxDepth)	
	// 노드에 공간이 있거나 and 정렬할 수 있는 하위 노드가 없거나 or 허용된 최대 깊이에 도달한 경우에만 
	// 점을 삽입
	{
		children.push_back(insertPt);
		return true;
	}

	// maximum amount of pts in this node reached -> split into 4 new nodes
	if (northWest == nullptr)	// this node has not been split yet -> nullptr
	{
		subdivide();

		// 상위 노드에서 모든 점을 제거하고 이 점을 하위 노드로 정렬한다. 
		for (int i = 0; i < (int)children.size(); i++)
		{
			// sort this element into the according quadrant(NE, NW, SE, SW)
			Point2D queryPt(children[i].x, children[i].y);	// point to insert into child node

			insert(queryPt);
		}

		for (int i = 0; i < (int)children.size(); i++)
			children.erase(children.begin() + i);
	}

	if (northEast->insert(insertPt))
	{
		return true;
	}

	if (northWest->insert(insertPt))
	{
		return true;
	}

	if (southWest->insert(insertPt))
	{
		return true;
	}

	if (southEast->insert(insertPt))
	{
		return true;
	}

	return false;
}


// 노드를 4개의 하위 노드로 분할
void CQuadTree::subdivide()
{
	if (this->nodeDepth < maxDepth)	// 최대 깊이가 아닐때만
	{
		// subdivide NW
		std::shared_ptr<BoundaryBox> BB_init_NW(new BoundaryBox(boundary2->cx - boundary2->dim * 0.5, boundary2->cy + boundary2->dim * 0.5, boundary2->dim * 0.5));
		northWest = new CQuadTree(std::move(BB_init_NW), this, this->nodeDepth + 1);

		// subdivide NE
		std::shared_ptr<BoundaryBox> BB_init_NE(new BoundaryBox(boundary2->cx + boundary2->dim * 0.5, boundary2->cy + boundary2->dim * 0.5, boundary2->dim * 0.5));
		northEast = new CQuadTree(std::move(BB_init_NE), this, this->nodeDepth + 1);

		// subdivide SE
		std::shared_ptr<BoundaryBox> BB_init_SE(new BoundaryBox(boundary2->cx + boundary2->dim * 0.5, boundary2->cy - boundary2->dim * 0.5, boundary2->dim * 0.5));
		southEast = new CQuadTree(std::move(BB_init_SE), this, this->nodeDepth + 1);

		// subdivide SW
		std::shared_ptr<BoundaryBox> BB_init_SW(new BoundaryBox(boundary2->cx - boundary2->dim * 0.5, boundary2->cy - boundary2->dim * 0.5, boundary2->dim * 0.5));
		southWest = new CQuadTree(std::move(BB_init_SW), this, this->nodeDepth + 1);
	}
}


// drawing routine (used by traverse_and_draw). Used by traverse_and_draw()
void CQuadTree::colorPick(float elevate, CQuadTree* t, float* depthColor, int depthColorLen)
{

}

void CQuadTree::traverse_and_draw(CQuadTree* t, float widthRootNode)
{
	// adjust the height (z-coordinate) of the quadtree
	float elevate = -10.0;

	// pick the colors according to the depth
	float depthColor[] =
	{
		1.0f, 0.0f, 0.0f,		// depth 1 = red
		0.0f, 0.392f, 0.0f,		// depth 2 = darkgreen
		0.0f, 0.0f, 1.0f,		// depth 3 = blue
		1.0f, 0.0f, 1.0f,		// depth 4 = purple
		0.0f, 1.0f, 1.0f, 		// depth 5 = cyan
		0.294f, 0.0f, 0.51f,	// depth 6 = indigo
		0.863f, 0.078f, 0.235f,	// depth 6 = Crimson
	};


	if (t->northEast != nullptr)
	{
		colorPick(elevate, t, depthColor, sizeof(depthColor) / sizeof(*depthColor));
		t->northEast->traverse_and_draw(northEast, widthRootNode);
	}

	if (t->northWest != nullptr)
	{
		colorPick(elevate, t, depthColor, sizeof(depthColor) / sizeof(*depthColor));
		t->northWest->traverse_and_draw(northWest, widthRootNode);
	}

	if (t->southEast != nullptr)
	{
		colorPick(elevate, t, depthColor, sizeof(depthColor) / sizeof(*depthColor));
		t->southEast->traverse_and_draw(southEast, widthRootNode);
	}

	if (t->southWest != nullptr)
	{
		colorPick(elevate, t, depthColor, sizeof(depthColor) / sizeof(*depthColor));
		t->southWest->traverse_and_draw(southWest, widthRootNode);
	}
}


// count the nodes of the tree
int CQuadTree::count_nodes(CQuadTree* t)
{
	// node has been split
	if (t->northEast != nullptr)
	{
		int nodes_NE = northEast->count_nodes(northEast);
		int nodes_SE = southEast->count_nodes(southEast);
		int nodes_SW = southWest->count_nodes(southWest);
		int nodes_NW = northWest->count_nodes(northWest);
		return nodes_NE + nodes_SE + nodes_SW + nodes_NW;
	}

	return 1;
}


// count the elements residing in the tree
int CQuadTree::count_elements(CQuadTree* t)
{
	int fetch_elements = 0;

	// node has been split - continue with the recursion
	if (t->northEast != nullptr)
	{
		fetch_elements += northEast->count_elements(northEast);
		fetch_elements += southEast->count_elements(southEast);
		fetch_elements += southWest->count_elements(southWest);
		fetch_elements += northWest->count_elements(northWest);
	}
	// deepest (child)node possible
	else
	{
		if (t->children.size() > 0)	// there are elements in this node
		{
			fetch_elements += t->children.size();
		}
	}

	return fetch_elements;
}


// 지정된 요소가 있는 노드를 가져온다.
CQuadTree* CQuadTree::fetch_node(Point2D seekPt)
{
	static CQuadTree* ReturnNode;

	// 점이 노드안에 없을 때
	if (seekPt.x > boundary2->cx + boundary2->dim or seekPt.x <= boundary2->cx - boundary2->dim or seekPt.y > boundary2->cy + boundary2->dim or seekPt.y <= boundary2->cy - boundary2->dim)
	{
	}
	// else -> 노드 안에 있을 때
	else
	{
		// deepest node corresponding to this point reached. Return the pointer to this node
		if (northWest == nullptr)
		{
			bool foundNode = false;
			ReturnNode = nullptr;

			for (int i = 0; i < (int)children.size(); i++)
			{
				
				if (seekPt.x == children[i].x and seekPt.y == children[i].y)
				{
					foundNode = true;
				}
			}

			if (foundNode == true)
			{
				ReturnNode = this;
			}

			return ReturnNode;
		}
		else
		{
			ReturnNode = northEast->fetch_node(seekPt);
			ReturnNode = northWest->fetch_node(seekPt);
			ReturnNode = southWest->fetch_node(seekPt);
			ReturnNode = southEast->fetch_node(seekPt);
		}
	}

	return ReturnNode;
}


// searches the node in which seekPt resides and returns all the elements from this node
std::vector<Point2D> CQuadTree::fetch_points(Point2D seekPt)
{
	std::vector <Point2D> return_elements;

	// search the node in which the point seekPt resides
	CQuadTree* search_node = fetch_node(seekPt);

	// retrieve all the pts from the node
	for (int i = 0; i < (int)search_node->children.size(); i++)
	{
		return_elements.push_back(search_node->children[i]);
	}

	return return_elements;
}


// remove a single element from the tree
bool CQuadTree::delete_element(Point2D deletePt)
{
	// try to locate the node where the point lies
	CQuadTree* nodePtReside = fetch_node(deletePt);

	if (nodePtReside == nullptr)   // this element is not in the QT
	{
		return false;
	}
	else
	{
		// retrieve location of deletePt in the children std::vector
		int del_index = -1;
		bool foundItem = false;

		for (del_index = 0; del_index < (int)nodePtReside->children.size(); del_index++)
		{
			if (deletePt.x == nodePtReside->children[del_index].x and deletePt.y == nodePtReside->children[del_index].y)
			{
				foundItem = true;
				nodePtReside->children.erase(nodePtReside->children.begin() + del_index);
				break;
			}
		}

		// element was not found -> deletion failed
		if (foundItem == false)
		{
			return false;
		}

		concatenate_nodes(nodePtReside);
	}

	return true;
}


// auxiliary function used by delete_element(). Used to collapse nodes and redistribute elements after collapsing
void CQuadTree::concatenate_nodes(CQuadTree* concat_this_node_maybe)
{
	if (concat_this_node_maybe->parent == concat_this_node_maybe)   // point resides in parent -> do nothing
	{
	}
	else
	{
		// Concatenate because all four nodes (3 sibling nodes and the one where the point lies) are empty
		if (concat_this_node_maybe->parent->northEast->northEast == nullptr && concat_this_node_maybe->parent->northWest->northEast == nullptr && concat_this_node_maybe->parent->southEast->northEast == nullptr && concat_this_node_maybe->parent->southWest->northEast == nullptr)
		{
			int amtElemntsNE = concat_this_node_maybe->parent->northEast->children.size();
			int amtElemntsNW = concat_this_node_maybe->parent->northWest->children.size();
			int amtElemntsSE = concat_this_node_maybe->parent->southEast->children.size();
			int amtElemntsSW = concat_this_node_maybe->parent->southWest->children.size();

			unsigned int sumElements = amtElemntsNE + amtElemntsNW + amtElemntsSE + amtElemntsSW;

			// move all elements from the leaf nodes into their parents node and delete the leaf nodes
			if (sumElements <= maxAmtElements)
			{
				// move elements from the northEast node to the parent node
				for (int i = 0; i < amtElemntsNE; i++)
				{
					float reshufflex = concat_this_node_maybe->parent->northEast->children[i].x;
					float reshuffley = concat_this_node_maybe->parent->northEast->children[i].y;

					Point2D reinsertPt(reshufflex, reshuffley);
					concat_this_node_maybe->parent->children.push_back(reinsertPt);
				}

				// move elements from the northWest node to the parent node
				for (int i = 0; i < amtElemntsNW; i++)
				{
					float reshufflex = concat_this_node_maybe->parent->northWest->children[i].x;
					float reshuffley = concat_this_node_maybe->parent->northWest->children[i].y;

					Point2D reinsertPt(reshufflex, reshuffley);
					concat_this_node_maybe->parent->children.push_back(reinsertPt);
				}

				// move elements from the southEast node to the parent node
				for (int i = 0; i < amtElemntsSE; i++)
				{
					float reshufflex = concat_this_node_maybe->parent->southEast->children[i].x;
					float reshuffley = concat_this_node_maybe->parent->southEast->children[i].y;

					Point2D reinsertPt(reshufflex, reshuffley);
					concat_this_node_maybe->parent->children.push_back(reinsertPt);
				}

				// move elements from the southWest node to the parent node
				for (int i = 0; i < amtElemntsSW; i++)
				{
					float reshufflex = concat_this_node_maybe->parent->southWest->children[i].x;
					float reshuffley = concat_this_node_maybe->parent->southWest->children[i].y;

					Point2D reinsertPt(reshufflex, reshuffley);
					concat_this_node_maybe->parent->children.push_back(reinsertPt);
				}

				// generate a pointer to the next node to concatinate (prevents an invalid read)
				CQuadTree* concat_next = concat_this_node_maybe->parent;

				// delete the sibling nodes (of the removed point)
				concat_this_node_maybe->parent->clearNode();

				// proceed with the recursion
				concatenate_nodes(concat_next);
			}
		}
	}
}


bool CQuadTree::relocate_element(Point2D ptOrigin, Point2D PtMoveTo)
{
	if (ptOrigin.x == PtMoveTo.x and ptOrigin.y == PtMoveTo.y)
	{
		return false;
	}

	CQuadTree* nodePtReside_Origin = fetch_node(ptOrigin);

	// PtMoveTo lies outside of the node -> remove and reinsert this element
	if (PtMoveTo.x > nodePtReside_Origin->boundary2->cx + nodePtReside_Origin->boundary2->dim or PtMoveTo.x <= nodePtReside_Origin->boundary2->cx - nodePtReside_Origin->boundary2->dim or PtMoveTo.y > nodePtReside_Origin->boundary2->cy + nodePtReside_Origin->boundary2->dim or PtMoveTo.y <= nodePtReside_Origin->boundary2->cy - nodePtReside_Origin->boundary2->dim)
	{
		// TODO - remove element, reinsert into the parent node not the root node
		delete_element(ptOrigin);

		bool check_insert = insert(PtMoveTo);

		if (check_insert)
		{
			return true;
		}
		// element could not be fit into the root node, i.e., exited the root tree
		else
		{
			return false;
		}

	}
	//overwrite the point since it did not move out of the node
	else
	{
		// find the position of ptOrigin and overwrite its coordinates with the ones of PtMoveTo
		int foundIndex = -1;

		for (int i = 0; i < (int)nodePtReside_Origin->children.size(); i++)
		{
			if (nodePtReside_Origin->children[i].x == ptOrigin.x and nodePtReside_Origin->children[i].y == ptOrigin.y)
			{
				foundIndex = i;
				break;
			}
		}

		// update the coordinates, i.e., move the element
		nodePtReside_Origin->children[foundIndex].x = PtMoveTo.x;
		nodePtReside_Origin->children[foundIndex].y = PtMoveTo.y;
	}

	return true;
}
