#pragma once

class CQuadTree
{
private:
	// �ڽ� ��� 
	CQuadTree* northWest;
	CQuadTree* northEast;
	CQuadTree* southWest;
	CQuadTree* southEast;

	shared_ptr<BoundaryBox> boundary2;  // dimesions of the node

	vector<Point2D> children;	// ����� ���� ��� ���� �����̶�� id�� 

	unsigned int maxAmtElements = 1;	//// ��尡 �������� �ּ� ��

	int maxDepth = 6;		// �ڽ� ����� �ִ� ����

	int nodeDepth;			// ����� ����(0...��Ʈ ���)

	// �׸���
	void colorPick(float elevate, CQuadTree* t, float* depthColor, int depthColorLen);

	CQuadTree* parent;		// �θ��带 ����Ű�� ������

	//  auxiliary function used by delete_element() �ٽ� ����
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


