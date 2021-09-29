#pragma once

class CQuadTree
{
private:
	// 자식 노드 
	CQuadTree* northWest;
	CQuadTree* northEast;
	CQuadTree* southWest;
	CQuadTree* southEast;

	shared_ptr<BoundaryBox> boundary2;  // dimesions of the node

	vector<Point2D> children;	// 노드의 구성 요소 내꺼 기준이라면 id로 

	unsigned int maxAmtElements = 1;	//// 노드가 나눠지는 최소 값

	int maxDepth = 6;		// 자식 노드의 최대 깊이

	int nodeDepth;			// 노드의 깊이(0...루트 노드)

	// 그리기
	void colorPick(float elevate, CQuadTree* t, float* depthColor, int depthColorLen);

	CQuadTree* parent;		// 부모노드를 가리키는 포인터

	//  auxiliary function used by delete_element() 다시 공부
	void concatenate_nodes(CQuadTree* concat_this_node_maybe);	
	
	CQuadTree* fetch_node(Point2D seekPt);

	void removeChildren();

	void clearNode();

	// clear the tree
	void clear(CQuadTree* t);

public:
	// constructor
	CQuadTree(std::shared_ptr<BoundaryBox> BB_init, CQuadTree* parent, int _nodeDepth);

	// destructor
	~CQuadTree();

	// insert a point into the tree
	bool insert(Point2D insertPt);

	// create four children that fully divide this quad into four quads of equal area
	void subdivide();

	// draw the tree using OpenGL
	void traverse_and_draw(CQuadTree* t, float widthRootNode);

	// count the nodes of the tree
	int count_nodes(CQuadTree* t);

	// count the elements residing in the tree
	int count_elements(CQuadTree* t);

	// returns all points corresponding to the node in which this point (seekPt) resides
	std::vector<Point2D> fetch_points(Point2D seekPt);

	// remove a single element of the tree
	bool delete_element(Point2D deletePt);

	// relocate a single element of the tree
	bool relocate_element(Point2D ptOrigin, Point2D PtMoveTo);
};


