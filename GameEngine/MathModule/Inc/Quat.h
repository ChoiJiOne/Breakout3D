#pragma once

#include "Vec4.h"


/**
 * @brief ���ʹϾ��Դϴ�.
 */
struct Quat
{
	/**
	 * @brief ���ʹϾ��� �����Դϴ�.
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