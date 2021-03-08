#include "stdafx.h"
#include "CQuadTree.h"
// Insert a node into the quadtree 
void CQuadTree::insert(tNode* node)
{
    if (node == NULL)return;
    if (!inBoundary(node->pos))return;
 
    if (abs(m_tTopLeft.x - m_tBotRight.x) <= 1 &&       // 한칸까지 쪼개 졌는지 판단 멀티스레딩할때 abs 문제 안되는지 확인할 것
        abs(m_tTopLeft.y - m_tBotRight.y) <= 1)
    {
        if (m_tNode == NULL)
            m_tNode = node;
        return;
    }

    if ((m_tTopLeft.x + m_tBotRight.x) / 2 >= node->pos.x)  // 센터를 기준으로 어떤 사분면에 존재하는지 판벌 하는 코드
    {
        // Indicates m_tTopLeftTree 
        if ((m_tTopLeft.y + m_tBotRight.y) / 2 >= node->pos.y)
        {
            if (m_tTopLeftTree == NULL)
                m_tTopLeftTree = new CQuadTree(
                    tPoint(m_tTopLeft.x, m_tTopLeft.y),
                    tPoint((m_tTopLeft.x + m_tBotRight.x) / 2,
                        (m_tTopLeft.y + m_tBotRight.y) / 2));
            m_tTopLeftTree->insert(node);
        }

        // Indicates m_tBotLeftTree 
        else
        {
            if (m_tBotLeftTree == NULL)
                m_tBotLeftTree = new CQuadTree(
                    tPoint(m_tTopLeft.x,
                        (m_tTopLeft.y + m_tBotRight.y) / 2),
                    tPoint((m_tTopLeft.x + m_tBotRight.x) / 2,
                        m_tBotRight.y));
            m_tBotLeftTree->insert(node);
        }
    }
    else
    {
        // Indicates m_tTopRightTree 
        if ((m_tTopLeft.y + m_tBotRight.y) / 2 >= node->pos.y)
        {
            if (m_tTopRightTree == NULL)
                m_tTopRightTree = new CQuadTree(
                    tPoint((m_tTopLeft.x + m_tBotRight.x) / 2,
                        m_tTopLeft.y),
                    tPoint(m_tBotRight.x,
                        (m_tTopLeft.y + m_tBotRight.y) / 2));
            m_tTopRightTree->insert(node);
        }

        // Indicates m_tBotRightTree 
        else
        {
            if (m_tBotRightTree == NULL)
                m_tBotRightTree = new CQuadTree(
                    tPoint((m_tTopLeft.x + m_tBotRight.x) / 2,
                        (m_tTopLeft.y + m_tBotRight.y) / 2),
                    tPoint(m_tBotRight.x, m_tBotRight.y));
            m_tBotRightTree->insert(node);
        }
    }
}

// Find a node in a quadtree 
tNode* CQuadTree::search(const tPoint& p)
{
    // Current quad cannot contain it 
    if (!inBoundary(p))
        return NULL;

    // We are at a quad of unit length 
    // We cannot subdivide this quad further 
    if (m_tNode != NULL)
        return m_tNode;

    if ((m_tTopLeft.x + m_tBotRight.x) / 2 >= p.x)
    {
        // Indicates m_tTopLeftTree 
        if ((m_tTopLeft.y + m_tBotRight.y) / 2 >= p.y)
        {
            if (m_tTopLeftTree == NULL)
                return NULL;
            return m_tTopLeftTree->search(p);
        }

        // Indicates m_tBotLeftTree 
        else
        {
            if (m_tBotLeftTree == NULL)
                return NULL;
            return m_tBotLeftTree->search(p);
        }
    }
    else
    {
        // Indicates m_tTopRightTree 
        if ((m_tTopLeft.y + m_tBotRight.y) / 2 >= p.y)
        {
            if (m_tTopRightTree == NULL)
                return NULL;
            return m_tTopRightTree->search(p);
        }

        // Indicates m_tBotRightTree 
        else
        {
            if (m_tBotRightTree == NULL)
                return NULL;
            return m_tBotRightTree->search(p);
        }
    }
};

// Check if current quadtree contains the point 
bool CQuadTree::inBoundary(const tPoint& p)             // 범위 내에 있는가?
{
    return (p.x >= m_tTopLeft.x &&
        p.x <= m_tBotRight.x &&
        p.y >= m_tTopLeft.y &&
        p.y <= m_tBotRight.y);
}