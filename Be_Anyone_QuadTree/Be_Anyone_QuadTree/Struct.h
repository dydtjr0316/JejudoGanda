#pragma once

struct Point2D
{
	float x = 0.f;
	float y = 0.f;

	Point2D(const float& _cx, const float& _cy)
	{
		x = _cx;
		y = _cy;
	}
};

struct BoundaryBox
{
	float cx;			// 노드의 센터좌표
	float cy;			// 노드의 센터좌표
	float dim;			// 노드의 넓이 

	BoundaryBox(const float& _cx,
		const float& _cy, const float& _dim)
	{
		cx = _cx;
		cy = _cy;
		dim = _dim;
	}
};