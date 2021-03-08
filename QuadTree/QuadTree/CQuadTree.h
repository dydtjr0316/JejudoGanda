#pragma once
// The main quadtree class 
class CQuadTree
{
    // Hold details of the boundary of this node 
    tPoint m_tTopLeft;
    tPoint m_tBotRight;

    // Contains details of node 
    tNode* m_tNode;

    // Children of this tree 
    CQuadTree* m_tTopLeftTree;
    CQuadTree* m_tTopRightTree;
    CQuadTree* m_tBotLeftTree;
    CQuadTree* m_tBotRightTree;

public:
    CQuadTree()
    {
        m_tTopLeft = tPoint(0, 0);
        m_tBotRight = tPoint(0, 0);
        m_tNode = NULL;
        m_tTopLeftTree = NULL;
        m_tTopRightTree = NULL;
        m_tBotLeftTree = NULL;
        m_tBotRightTree = NULL;
    }
    CQuadTree(const tPoint& topL, const tPoint& botR)
    {
        m_tNode = NULL;
        m_tTopLeftTree = NULL;
        m_tTopRightTree = NULL;
        m_tBotLeftTree = NULL;
        m_tBotRightTree = NULL;
        m_tTopLeft = topL;
        m_tBotRight = botR;
    }
    void insert(tNode*);
    tNode* search(const tPoint&);
    bool inBoundary(const tPoint&);
};