#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <unordered_map>

#include "IManager.h"
#include "IResource.h"


/**
 * @brief ���ҽ� ������ �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱����Դϴ�.
 */
class ResourceManager : public IManager
{
public:
	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ResourceManager);


	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ���� �ν��Ͻ��� ����ϴ�.
	 *
	 * @return ���ҽ� ������ �����ϴ� �Ŵ����� �����ڸ� ��ȯ�մϴ�.
	 */
	static ResourceManager& Get();


	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note �� �޼���� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Startup() override;


	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ����� �����մϴ�.
	 *
	 * @note
	 * - ���ø����̼� ���� ���� �� �޼��带 �ݵ�� ȣ���Ͽ� ���� ���ҽ��� �����ؾ� �մϴ�.
	 * - �� �޼���� �ݵ�� �� ���� ȣ��Ǿ�� �մϴ�.
	 */
	virtual void Shutdown() override;


	/**
	 * @brief �� ���ҽ��� �����մϴ�.
	 *
	 * @note
	 * - ���ҽ� �Ŵ����� �ʱ�ȭ�� �������� �����Ƿ�, ��ȯ�ϴ� ������ ������ �̿��ؼ� �ʱ�ȭ�� ���� �����ؾ� �մϴ�.
	 * - ���ҽ��� �ñ״�ó ���� �ߺ��� ������� �ʽ��ϴ�.
	 *
	 * @param signature �Ŵ��� ���ο��� ���ҽ����� ������ �ñ״�ó ���Դϴ�.
	 *
	 * @return ������ ���ҽ��� �����͸� ��ȯ�մϴ�.
	 */
	template <typename TResource>
	TResource* CreateResource(const std::string& signature)
	{
		ASSERT(!IsValidKey(signature), "already exist resource signature %s key", signature.c_str());

		std::unique_ptr<TResource> resource = std::make_unique<TResource>();
		resourceCache_.insert({ signature, std::move(resource) });

		return reinterpret_cast<TResource*>(resourceCache_.at(signature).get());
	}


	/**
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��� ����ϴ�.
	 *
	 * @param signature �Ŵ��� ���ο��� ���ҽ����� ������ �ñ״�ó ���Դϴ�.
	 *
	 * @return �ñ״�ó�� �����ϴ� ���ҽ��� �����͸� ����ϴ�. �ñ״�ó ���� �����ϴ� ���ҽ��� ������ �� �����͸� ��ȯ�մϴ�.
	 */
	template <typename TResource>
	TResource* GetResource(const std::string& signature)
	{
		if (!IsValidKey(signature))
		{
			return nullptr;
		}

		return reinterpret_cast<TResource*>(resourceCache_.at(signature).get());
	}


	/**
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��� �����մϴ�.
	 *
	 * @param signature ������ ���ҽ��� �ñ״�ó ���Դϴ�.
	 */
	void DestroyResource(const std::string& signature);


private:
	/**
	 * @brief ���ҽ� ������ �����ϴ� �Ŵ����� ����Ʈ �����ڿ� �� ���� �Ҹ��ڸ� �����մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ResourceManager);


	/**
	 * @brief Ű ���� ��ȿ���� Ȯ���մϴ�.
	 *
	 * @param key ��ȿ���� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ���ҽ��� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsValidKey(const std::string& key);


private:
	/**
	 * @brief ���ҽ� �Ŵ��� ���� ���ҽ� ĳ���Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<IResource>> resourceCache_;
};