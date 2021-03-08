#pragma once
// Used to hold details of a point 
struct tPoint
{
    int x;
    int y;
    tPoint(const int& _x, const int& _y)
    {
        x = _x;
        y = _y;
    }
    tPoint()
    {
        x = 0;
        y = 0;
    }
};

// The objects that we want stored in the quadtree 
struct tNode
{
    tPoint pos;
    int data;
    tNode(const tPoint& _pos, const int& _data)
    {
        pos = _pos;
        data = _data;
    }
    tNode()
    {
        data = 0;
    }
};

