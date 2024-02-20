#include "MathModule.h"

inline Quat Quat::AxisAngle(const Vec3f& axis, float radian)
{
	float s = MathModule::Sin(radian * 0.5f);
	float c = MathModule::Cos(radian * 0.5f);
	Vec3f norm = Vec3f::Normalize(axis);

	return Quat(norm.x * s, norm.y * s, norm.z * s, c);
}
inline Quat Quat::Zero()
{
	return Quat(0.0f, 0.0f, 0.0f, 0.0f);
}

inline Quat Quat::Identity()
{
	return Quat(0.0f, 0.0f, 0.0f, 1.0f);
}