#pragma once

#include "Vec4.h"


/**
 * @brief 쿼터니언입니다.
 */
struct Quat
{
	/**
	 * @brief 쿼터니언의 원소입니다.
	 */
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		struct
		{
			Vec4f v; // (x, y, z)
			float w;
		};
		float data[4];
	};
};