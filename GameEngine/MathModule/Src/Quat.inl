#include "MathModule.h"

inline Quat Quat::AxisAngle(const Vec3f& axis, float angle)
{
	Vec3f norm = Vec3f::Normalize(axis);
	float scalar = MathModule::Sin(angle * 0.5f);

	return Quat(norm.x * scalar, norm.y * scalar, norm.z * scalar, MathModule::Cos(angle * 0.5f));
}
inline Quat Quat::Zero()
{
	return Quat(0.0f, 0.0f, 0.0f, 0.0f);
}

inline Quat Quat::Identity()
{
	return Quat(0.0f, 0.0f, 0.0f, 1.0f);
}